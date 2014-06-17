#include "includes.h"


#include "sort.h"
#include "compress.h"

#include "list.h"
#include "cbuf.h"

int main(void)
{
	
	int i = 0;
	char c = 0;

	time_t t1;
	time_t t2;

	LIST l = NULL;
	CBUF b = NULL;
	cbuf_t bf = {0};

	b = &bf;
	//showCbuff(b);
	testCBuf(b);
	//printf("123123");

	#if 0
	l = makeList();
	//delList(l);
	//countList(l,&i);
	//showList(l);
	//printf("\nisEmpty:%d,2=FALSE,3=TRUE",isEmptyList(l));
	//printf("\nsNode:%d",sizeofNode(l));
	//printf("\nsList:%d",sizeofList(l));
	testList(l);
	#endif

	#if 0
	testSort();
	testSortElem();
	#endif
	
	#if 0
	t1 = time(NULL);
	printf("current time is %s\n", ctime(&t1));

	t2 = time(NULL);
	printf("current time is %s\n", ctime(&t2));
	
	printf("difftime is %f\n", difftime(t2,t1));
	#endif

	#if 0
	printf("testMath:%f",sqrt(9));
	#endif
}
