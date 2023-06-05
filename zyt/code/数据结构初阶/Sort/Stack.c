#include"Stack"
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//初始化时如果top是0，即top指向栈顶上的后一位
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;

}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* temp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;

}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
bool StackEmpty(ST* ps)
{
	return ps->top == 0;
}
