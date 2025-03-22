#include<graphics.h>
#include<math.h>
#include"struct.h"
#define n 27

void huffmanTreeDraw(huffmantree tree[])
{
	tree[2*n-2].d=1;
	for(int i=2*n-2;i>=n;i--)
	{
		tree[tree[i].lchild].d=2*tree[i].d;
		tree[tree[i].rchild].d=2*tree[i].d+1;
	}
	for(int i=2*n-2;i>=0;i--)
	{
		tree[i].D=tree[i].d/pow(2,(int)((log(tree[i].d)/log(2))));
	}
	for(int i=0;i<=n-1;i++)
	{
		int t=1;
		for(int j=0;j<=n-1;j++)
		{
			if(tree[j].D<tree[i].D)
			{	
				t++;
			}
		}
		tree[i].p.x=(int)((1000/(n+1))*t);
	}
	for(int i=n;i<2*n-1;i++)
	{
		tree[i].p.x=(int)((tree[tree[i].lchild].p.x+tree[tree[i].rchild].p.x)/2);
	}
	for(int i=0;i<2*n-1;i++)
	{
		tree[i].p.y=(int)((800*2/n)*((int)(log(tree[i].d)/log(2))+1));
	}
	setcolor(WHITE); 
	setbkcolor(WHITE);
	setfillcolor(GREEN);
	cleardevice();
	setcolor(BLACK);
	for(int i=0;i<2*n-1;i++)            
	{
		fillellipse(tree[i].p.x,tree[i].p.y,5,5);
		if(tree[i].lchild==-1)
		{	
			outtextxy(tree[i].p.x,5+tree[i].p.y,tree[i].ch);
		}
		if(tree[i].lchild!=-1)           
		{
			outtextxy((int)(tree[i].p.x+tree[tree[i].lchild].p.x)/2,(int)(tree[i].p.y+tree[tree[i].lchild].p.y)/2,"0");
			outtextxy((int)(tree[i].p.x+tree[tree[i].rchild].p.x)/2-5,(int)(tree[i].p.y+tree[tree[i].rchild].p.y)/2,"1");
			line(tree[i].p.x,tree[i].p.y,tree[tree[i].lchild].p.x,tree[tree[i].lchild].p.y);
			line(tree[i].p.x,tree[i].p.y,tree[tree[i].rchild].p.x,tree[tree[i].rchild].p.y);
		}
	}
	outtextxy(150,750,"Please enter shift to exit");
}
