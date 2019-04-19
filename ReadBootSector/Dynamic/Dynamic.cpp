// Dynamic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "list.h"
#include <iostream>
#include <stdio.h>
void first_fit(DList &lhead,int program_size) {
	Node *p = lhead.head;
	while (p != NULL) {
		if (p->type == 'H' && program_size <= p->len) {
			if (program_size == p->len) {
				p->type = 'P';
				break;
			}
			else {
				Node *next = p->next;
				int k = p->len - program_size;
				p->len = program_size;
				p->type = 'P';
				Node *p1 = initNode('H',p->start+program_size,k);
				p->next = p1;
				p1->next = next;
				break;
			}
		}
		p = p->next;
	}
}
void remove(DList &lhead,int start_process) {
	Node *p = lhead.head;
	while (true) {
		if (p->next == NULL) break;
		if (p->next->start == start_process) {
			Node *pnext = p->next->next;
			if (p->type == 'H') {
				p->len = p->len + p->next->len;
				delete(p->next);
				p->next = pnext;
			}
			if (pnext != NULL && pnext->type = 'H') {

			}
		}
	}
}
int main()
{
	int n = 0;//memory size
	printf("Memory size:");
	scanf_s("%d", &n);
	int segment_size = 0;
	printf("Segment size:");
	scanf_s("%d", &segment_size);
	int program_size = 0;
	printf("Program size:");
	scanf_s("%d", &program_size);
	int number_of_Node = 0;
	printf("Nhap so Node:");
	scanf_s("%d", &number_of_Node);
	DList lhead;
	init(lhead);
	for (int i = 0; i < number_of_Node; ++i) {
		char x;
		int y, z;
		cin.ignore();
		printf("Type of Node:");
		scanf_s("%c",&x);
		printf("Start segment of Node:");
		scanf_s("%d", &y);
		printf("Length of Node:");
		scanf_s("%d", &z);
		Inserttail(lhead, x, y, z);
	}
	first_fit(lhead, ceil(program_size/float(n)*segment_size));
	printfList(lhead);
	return 0;
}