/*************************************************************************
    > File Name: Bin2Dec.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年09月01日 星期二 19时51分28秒
	> 二进制转十进制
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#define STACKSIZE 20
using namespace std;

typedef struct
{
	char *base;
	char *top;
	int stackSize;
}Stack;

void InitStack(Stack *s)
{
	s->base = new char[STACKSIZE];
	if(!s->base)  //内存分配失败
		exit(0);

	s->top = s->base;
	s->stackSize = STACKSIZE;
}

//往栈s中压入字符c
void Push(Stack *s, char c)
{
	if(s->top - s->base >= STACKSIZE)  //栈满
		cout << "栈满，不能继续压入." << endl;
	*(s->top) = c;
	s->top++;
}

//出栈,出来的元素保存在c中
void Pop(Stack *s, char c)
{
	if(s->top == s->base)  //空栈
	{
		cout << "栈空，没有元素弹出来" << endl;
		return ;
	}

	c = *--(s->top);
}

int StackLen(Stack *s)
{
	return s->top - s->base;
}

int main()
{
	Stack s;
	char c, d;
	int len;
	int sum = 0;
	InitStack(&s);

	cout << "请输入一串二进制数,以#结尾: ";
	cin >> c;
	while(c != '#')
	{
		Push(&s, c);
		cin >> c;
	}
	getchar();

	len = StackLen(&s);
	cout << "栈的当前容量: " << len << endl;

	for(int i = 0; i < len; i++)
	{
		Pop(&s, d);
		sum += (d - 48) * pow(2, i);
	}
	cout << "转换成的十进制为:" << sum << endl;
}

