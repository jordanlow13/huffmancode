#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#define n 27

void huffmanCode(huffmantree tree[],huffmancode code[])
{
	int i,c,p;
	FILE *fp;
    for(i=0;i<=n-1;i++)
	{
	   code[i].s=n/2;
	   code[i].ch=tree[i].ch;
	   c=i;
	   p=tree[i].parent;
	   while(c!=2*n-2)
	   {
		   code[i].s--;
		   if(tree[p].lchild==c)
		   {
			   code[i].co[code[i].s]='0'; 
		   }
		   else
		   {
			   code[i].co[code[i].s]='1';
		   }
		   c=p;
		   p=tree[p].parent;
	   }
    }
	if((fp=fopen("output.txt","w"))==NULL)  
	{
		printf("can not open the file！\n");
		exit(0);
	}
	fprintf(fp,"huffman code for each character:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%c:",code[i].ch);
		for(int j=code[i].s;j<n/2;j++)
		{	
			fprintf(fp,"%c",code[i].co[j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	printf("code successfully！\nhuffman code is written in output.txt！\n");
}
