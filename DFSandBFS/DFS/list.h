#pragma once
#ifndef __LLIST_H__
#define __LLIST_H__

#ifdef __cplusplus
extern "C" {
#endif

	typedef int data;

	typedef struct Node //cau truc 1 Node
	{
		data Data; //du lieu cua Node
		Node *Left; //Con tro trai
		Node *Right; //con tro phai
	} Node;

	typedef struct DList //cau truc Cua List
	{
		Node *Head; //con tro dau
		Node *Tail; //con tro cuoi
	} DList;
    typedef DList *LLIST;

	

	typedef void(*LLCALLBACK)(int, void*);


	void llInit(DList &l);//tao danh sach

	void llInsertHead(DList &l, int x);//them vao dau
	void llInsertTail(DList &l, int x);//them vao cuoi
	void llInsertAfter(DList &l, int a, data x);//them vao sau vi tri a gia tri x

	void llDeleteHead(DList &l);//xoa vi tri dau
	void llDeleteTail(DList &l);//xoa vi tri cuoi
	void llDeleteAfter(DList &l, int a);//xoa vi tri sau a
	void llDeleteAll(DList &l);//xoa all
	int Search(DList l, data x);//tim phan tu gia tri x
	int llLength(DList l);
	int Isempty(DList L);//kiem tra su ton tai cua danh sach


#ifdef __cplusplus
}
#endif


#endif