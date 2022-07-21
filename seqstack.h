#ifndef ___SEQSTACK_H___
#define ___SEQSTACK_H___

#define MAX 10
typedef int datatype;

typedef struct
{
	datatype data[MAX]; 		//存放栈的数组
	int top; 		//记录栈顶元素的下标

}seqStack;

//创建
seqStack* create();
//入栈、进栈、压栈
int push(seqStack* S,datatype e);
//遍历栈
void show(seqStack* S);
//销毁栈
void destroy(seqStack* S);
//进制转换
void JZZH(seqStack* S);
#endif
