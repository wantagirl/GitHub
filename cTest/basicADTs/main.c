#include "includes.h"
#include "defs.h"

#include "list.h"


int main(void)
{
	LIST l = NULL;
	int i = 0;
	char c = 0;

	l = makeList(7);
	//delList(l);
	countList(l,&i);
	
	
	testDelInsert(l);
}
