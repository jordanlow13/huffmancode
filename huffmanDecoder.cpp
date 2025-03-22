#include<graphics.h>
#include<string.h>
#include<stdio.h>
#include"huffmanDecode.h"
#include"huffmanCodeOutput.h"
#include"struct.h"

void huffmanDecoder(huffmantree tree[],huffmancode code[])
{  
   char a[10];
   inputbox_getline("Huffman Decoder(Please enter '#' to exit)","Please enter the code:",a,10);
   while(1){
	  if(strcmp(a,"#")==0)break;
	  char* b=huffmanDecode(tree,a);
	  if(b==NULL)
	  {
		  inputbox_getline("Huffman Decoder(Please enter '#' to exit)","The code is error,Please enter again:",a,10);
		  b=huffmanDecode(tree,a);
	  }
	  char bu[25];
	  snprintf(bu,sizeof(bu),"%s%s%s",a,":",b);
	  inputbox_getline("Huffman Decoder(Please enter '#' to exit)",bu,a,10);
	  free(b);
	  delay_ms(100);
   }
   huffmanCodeOutput(code);
}
