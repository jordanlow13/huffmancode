#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#define n 27
#define max 1000

void huffmanTree(huffmantree tree[])
{
	int i,j,p1,p2;
	int smallest1,smallest2;
	for(i=n;i<=2*n-2;i++)
	{
		p1=0;p2=0;
		smallest1=max;
		smallest2=max;
		for(j=0;j<=i-1;j++)
		{
			if(tree[j].parent==-1)
		    {
				if(tree[j].weight<smallest1)
		        {
			       smallest2=smallest1;  
			       smallest1=tree[j].weight;
			       p2=p1;
		           p1=j;
		        }
		        else if(tree[j].weight<smallest2)
		        {
			       smallest2=tree[j].weight;
			       p2=j;
		        }
		    }
		}
		tree[p1].parent=i;
		tree[p2].parent=i;
		tree[i].lchild=p1;  
		tree[i].rchild=p2;  
		tree[i].weight=tree[p1].weight+tree[p2].weight;
	}
	
}

