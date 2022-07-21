#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqstack.h"
int main(int argc, const char *argv[])
{
	seqStack *S = create();
	if(NULL == S)
	{
		return -1;
	}
	JZZH(S);
	//销毁栈
	destroy(S);
	S=NULL;
	return 0;
}
