#include "includes.h"
#include "defs.h"

#include "list.h"


int main(void)
{
	LIST l = NULL;
	int i = 0;
	char c = 0;

	l = makeList();
	//delList(l);
	//countList(l,&i);
	//showList(l);
	
	testList(l);
}
