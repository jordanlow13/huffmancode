#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include"struct.h"
#include"huffmanTree.h"
#include"huffmanCode.h"
#include"huffmanTreeDraw.h"
#include"huffmanCodeOutput.h"
#include"readtext.h"
#include"huffmanDecoder.h"
#define n 27

int main()
{   
	char m[n];
	huffmantree tree[2*n-1];
	huffmancode code[n];
	initgraph(1000,800);
	setcolor(WHITE); 
	setbkcolor(WHITE); 
	PIMAGE img=newimage();
	if(getimage(img,"background.jpg")!=grOk)
	{
		exit(-1);
	}
	putimage(0,0,img);
	delimage(img);
	readtext(tree);
	printf("There are %d characters in total！\n",n);
	huffmanTree(tree);
	huffmanCode(tree,code);
	printf("huffman tree is created！\nplease press enter to view！\n");
	do{
		PIMAGE img=newimage();
		if(getimage(img,"background.jpg")!=grOk)
		{
			exit(-1);
		}
		putimage(0,0,img);
		delimage(img);
		inputbox_getline("welcome to Huffman Code System","Fuction:\n1、Create the Huffman Code\n2、Draw the Huffman Tree\n3、Decode the code\nPlease choose the function:",m,n);
		if(strcmp(m,"1")==0){
		huffmanCodeOutput(code);
		delay_ms(100);
		}
		if(strcmp(m,"2")==0){
		huffmanTreeDraw(tree);
		delay_ms(100);
		}
		if(strcmp(m,"3")==0){
		huffmanDecoder(tree,code);
		delay_ms(100);
		}
		while(1){
		if(keystate(0x10))break;
		}
		}while(1);
	getch();
	closegraph();
	return 0;
}
