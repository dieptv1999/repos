#include "list.h"
void  init(DList &l)//khoi tao list
{
	l.head = NULL;
}
Node *initNode(char type,int start,int len)//tao mot node
{
	Node *l;
	l = new Node;
	l->next = NULL;
	l->type = type;
	l->start = start;
	l->len = len;
	return l;
}
Node *nextNode(Node *l, char type,int start,int len)//them mot node
{
	Node *next1 = initNode(type,start,len);
	l->next = next1;
	return next1;
}
bool isEmpty(DList &l)
{
	return !l.head;
}
void Inserthead(DList &l, char type, int start, int len)
{
	Node *new1 = initNode(type, start, len);
	new1->next = l.head;
	l.head = new1;
}
void Inserttail(DList &l, char type, int start, int len)
{
	Node *new1 = initNode(type, start, len);
	Node *n = l.head;
	if (n == NULL) l.head = new1;
	else {
		while (!(n->next == NULL)) n = n->next;
		n->next = new1;
	}
}
int length(DList &l)
{
	int len = 0;
	Node *n = l.head;
	while (!(n->next == NULL))
	{
		n = n->next;
		len++;
	}
	return len + 1;
}
void Insertk(DList &l, int k, char type, int start, int len)
{
	if (k == 1) Inserthead(l, type, start, len);
	else
	{
		Node *new1 = initNode(type, start, len);
		Node *h = l.head;
		for (int i = 0; i < k - 2; ++i)
		{
			h = h->next;
		}
		Node *h1 = h->next;
		h->next = new1;
		new1->next = h1;
	}
}
void Deletehead(DList &l)
{
	Node *n = l.head;
	l.head = n->next;
	free(n);
}
void Deletetail(DList &l)
{
	Node *n = l.head;
	while (!(n->next == NULL)) n = n->next;
}
void Deletek(DList &l, int k)
{
	Node *n = l.head;
	if (k == 0)
	{
		Deletehead(l);
		return;
	}
	for (int i = 0; i < k - 1; ++i) n = n->next;
	Node *new1 = n->next;
	n->next = (n->next)->next;
	free(new1);
}
void printfList(DList &lhead) {
	Node *p = lhead.head;
	while (p != NULL) {
		printf("%c %d %d \n", p->type, p->start, p->len);
		p = p->next;
	}
}