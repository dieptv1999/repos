#pragma once
#include <iostream>
using namespace std;
typedef struct Node
{
	int type;
	int start;
	int len;
	Node *next;
	Node(int type,int start,int len,Node *next) {
		this->type = type;
		this->start = start;
		this->len = len;
		this->next = next;
	}
	Node() {};
} Node;
typedef struct
{
	Node *head;
} DList;
void  init(DList &l);
Node *initNode(char type, int start, int len);
Node *nextNode(Node *l, char type, int start, int len);
bool isEmpty(DList &l);
void Inserthead(DList &l, char type, int start, int len);
void Inserttail(DList &l, char type, int start, int len);
int length(DList &l);
void Insertk(DList &l, int k, char type, int start, int len);
void Deletehead(DList &l);
void Deletetail(DList &l);
void Deletek(DList &l, int k);
void printfList(DList &lhead);