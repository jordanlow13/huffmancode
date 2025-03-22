#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#define n 27

char* huffmanDecode(huffmantree tree[],char code[])
{
    char *ab=(char*)malloc(10*sizeof(char));
	int root=2*n-2;
	int a=-1,b=0;
	for(int i=0;code[i]!='\0';i++)
	{
		b=0;
		if(code[i]=='0')
		{
			root=tree[root].lchild;
		}
		if(code[i]=='1')
		{
			root=tree[root].rchild;
		}
		if(tree[root].lchild==-1&&tree[root].rchild==-1)
		{
			a=a+1;
			b=1;
			ab[a]=tree[root].ch;
			root=2*n-2;
		}
	}
	ab[a+1]='\0';
	if(b==0)
	{
		return NULL;
	}
	else 
	{
		return ab;
	}	
}
