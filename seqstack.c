#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqstack.h"

//创建
seqStack* create()
{
	seqStack* S = (seqStack*)malloc(sizeof(seqStack));
	if(NULL == S)
	{
		printf("申请失败!\n");
		return NULL;
	}
	//初始化
	memset(S->data,0,sizeof(S->data));
	S->top=-1; //将栈顶设为-1
	//printf("创建成功!\n");
	return S;
}
//判空
int empty(seqStack* S)
{
	if(NULL == S)
	{
		printf("栈不合法!\n");
		return -1;
	}
	return S->top==-1?1:0; 	//1表示空 0非空
}
//判满
int full(seqStack* S)
{
	if(NULL == S)
	{
		printf("栈不合法!\n");
		return -1;
	}
	return S->top==MAX-1?1:0; 	//1表示满 0不满
}
//入栈、进栈、压栈
int push(seqStack* S,datatype e)
{
	if(NULL == S||full(S))
	{
		printf("入栈失败!\n");
		return -1;
	}
	S->data[++S->top] = e;

	//printf("入栈成功!\n");
	return 0;
}
//出栈、弹栈
int pop(seqStack* S)
{
	//判断逻辑
	if(NULL == S||empty(S))
	{
		printf("出栈失败!\n");
		return -1;
	}
	//出栈逻辑
	printf("%d出栈成功\n",S->data[S->top]);
	S->top--;
	return 0;
}
//遍历栈
void show(seqStack* S)
{
	if(NULL == S||empty(S))
	{
		printf("遍历失败!\n");
		return;
	}
	printf("转换后为:");
	for(int i=S->top;i>=0;i--)
	{
		if(S->data[i]==10)
			printf("A");
		else if(S->data[i]==11)
			printf("B");
		else if(S->data[i]==12)
			printf("C");
		else if(S->data[i]==13)
			printf("D");
		else if(S->data[i]==14)
			printf("E");
		else if(S->data[i]==15)
			printf("F");
		else
			printf("%d",S->data[i]);
	}
	printf("\n");
}
//销毁栈
void destroy(seqStack* S)
{
	if(NULL!=S)
	{
		free(S);
	}
	S = NULL; 		//防止悬空指针、野指针
	//printf("释放成功\n");
}

//进制转换
void JZZH(seqStack* S)
{
	int n,m;
	printf("请输入待转换的十进制数>>>");
	scanf("%d",&n);
	printf("请输入进制>>>");
	scanf("%d",&m);

	while(n/m!=0)
	{
		push(S,n%m);
		n/=m;
	}
	push(S,n%m);
	show(S);
}
