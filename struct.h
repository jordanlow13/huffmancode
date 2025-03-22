#ifndef STRUCT_H
#define STRUCT_H
#define n 27

struct  Point
{
	int x;
	int y;
};

struct huffmantree
{
	char ch;
	float weight;
	int lchild,rchild,parent;
	int d;
	float D;
	Point p;
};

struct huffmancode
{
	char co[n/2];
	int s;
	char ch;
};
#endif
