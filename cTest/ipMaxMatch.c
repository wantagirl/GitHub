#include <stdio.h>

int matchCount(unsigned int a, unsigned int b)	//从左向右找到最多1的个数
{
	int c = 0;
	unsigned int n = ~(a^b);
	while(n>0)
	{
		if(0 == (n & 0x80000000))
		{
			break;
		}
		c+=1;
		n<<=1;
	}
	return c;
}
void ip2int(const char* s, unsigned int* n)
{
	unsigned int i, j, t;
	t = 0;
	for(i=0,j=0;;i++)
	{
		if(s[i]=='.')
		{
			//printf("%d ",t);
			j = (j<<8) + t;
			t = 0;
		}
		else if(s[i]=='\0')
		{
			//printf("%d ",t);
			j = (j<<8) + t;
			t = 0;
			break;	//终止条件
		}
		else
		{
			t = t*10 + (s[i]-'0');
		}
	}
	*n = j;
	//printf("J: %d ",j);
	return;
}
void ipMaskSeparate(const char* s, char* ip, char *mask)
{
	int i,j;
	
	for(i=0, j=0;s[i]!='\0';i++)
	{
		if(s[i]=='/')
		{
			ip[i] = '\0';
			j = i+1;	//记录mask开始的下标
		}
		else if(j == 0) //前半部是ip
		{
			ip[i] = s[i];
		}
		else if(j != 0) //后面是mask
		{
			mask[i-j] = s[i];
		}
	}
	mask[i-j] = '\0';
	return;
}

void max_prefix_match(const char *ip_addr, const char *net_addr_array[], int *n)
{
	int i,j;	//j:匹配了几位
	char ip[16];
	char mask[16];
	unsigned int addrn;
	unsigned int ipn;
	unsigned int maskn;

	ip2int(ip_addr,&addrn);
	*n = -1;
	for(i=0,j=0; ;i++)
	{
		if(net_addr_array[i][0] == '\0')
		{
			//printf("EOLst");
			break;
		}
		ipMaskSeparate(net_addr_array[i],ip,mask);
		
		ip2int(ip,&ipn);
		//printf("IP:%s ",ip);
		ip2int(mask,&maskn);
		//printf("MASK:%s ",mask);
		//printf("\n");
		if((addrn & maskn) != ipn)
		{
			continue;
		}
		//同或
		if(matchCount(addrn,ipn)>j)
		{
			j = matchCount(addrn,ipn);
			*n = i;
		}	
	}
	//printf("%d ", j);
	return;
}

int main()
{
	int i;
	char ip[16];
	char mask[16];
	const char *net_addr_array[] = {"192.168.1.128/255.255.255.192","192.168.1.96/255.255.255.96","192.168.1.64/255.255.255.192","192.168.1.0/255.255.255.0",""};
	

	//str2int("255",&i);

	//ip2int("128.20.107.156", &i);
	//printf("%u",i);
	
	//ipMaskSeparate("121.122.123.124/0.0.0.0",ip,mask);
	//ipMaskSeparate(net_addr_array[0],ip,mask);
	//printf("IP:%s\nMASK:%s", ip, mask);

	//printf("\nMC:%d",matchCount(0x00000002,0x00000005));
	max_prefix_match("192.168.1.100", net_addr_array,&i);
	printf("%d",i);	
}

