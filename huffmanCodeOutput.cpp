#include<graphics.h>
#include"struct.h"
#define n 27

void huffmanCodeOutput(huffmancode code[])
{
	setcolor(WHITE); 
	setbkcolor(WHITE);
	setfillcolor(RED);
	cleardevice();
	setcolor(BLACK);
	outtextxy(10,10,"Huffman code for each character:");
	for(int i=0;i<n;i++)
	{
		outtextxy(250,40+23*i,code[i].ch);
		for(int j=code[i].s;j<n/2;j++)
		{	
			outtextxy(400+10*j,40+23*i,code[i].co[j]);
		}
	}
	outtextxy(150,700,"Please enter shift to exit");
}
