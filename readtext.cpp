#include<stdio.h>
#include<graphics.h>
#include "struct.h"

void readtext(huffmantree tree[]) 
{
   char globalPath[30];
   int f,i=0,sum=0;
   char a;
   FILE *fp;
   inputbox_getline("welcome to Huffman Code System","Fuction:\nCreate the Huffman Tree\nCreate the Huffman Code\nDraw the Huffman Tree\nPlease enter the path:",globalPath,30);
   while(sum!=1000){
   while((fp=fopen(globalPath,"r"))==NULL)
   {
	   inputbox_getline("welcome to Huffman Code System","can not open the file,please enter again:",globalPath,50);
   }
   for(i=0;i<=2*n-2;i++)
   {
	   tree[i].parent=-1;
	   tree[i].lchild=-1;
	   tree[i].rchild=-1;
	   tree[i].weight=0;
   }
   for(i=0;i<=n-1;i++)  
   {
	   fscanf(fp,"%c %d\n",&a,&f);
	   tree[i].ch=a;
	   tree[i].weight=f;
	   sum+=tree[i].weight;
   }
   if(sum!=1000)
   {
	   inputbox_getline("welcome to Huffman Code System","The text data is error,Please enter the path of the right text",globalPath,30);
   }
   fclose(fp);
   }
}
