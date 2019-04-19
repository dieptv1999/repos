#include "list.h"
#include <iostream>
void llInit(DList &L)
{
	L.Head = NULL; // Con tro dau tro den NULL
	L.Tail = NULL; // Con tro cuoi tro den NULL
}//Ham khoi tao
//--------------------------------------------------------------------------------
int Isempty(DList L) //kiem tra DS rong
{
	return (L.Head == NULL);
}//Ham kiem tra su ton tai
//-------------------------------------------------------------------------------
int llLength(DList l)
{
	Node *ph, *pt;
	ph = l.Head;
	pt = l.Tail;
	int i = 0;
	if (ph == NULL) return 1;
	while (ph != NULL)
	{
		if (ph == pt) break;
		ph = ph->Right;
		i++;
		if (ph == pt) break;
		pt = pt->Left;
		i++;
	}
	return i;
}//Ham tinh do dai
//-----------------------------------------------------------------------------
Node *Make_Node(data x) 
{
	Node *P = (Node *)malloc(sizeof(Node)); //Cap phat vung nho cho P
	P->Data = x; //Ghi du lieu vao Data
	P->Left = NULL;
	P->Right = NULL;
	return P;
}//Tao node chua thong tin
//-----------------------------------------------------------------------------
void llInsertHead(DList &l, data x)
{
	Node *P;
	P = Make_Node(x); //tao 1 Node P
	if (Isempty(l)) //Neu danh sach rong
	{
		l.Head = P;
		l.Tail = P;
	}
	else
	{
		P->Right = l.Head;
		l.Head->Left = P;
		l.Head = P;
	}
}//Chen phan tu vao vi tri dau tien
//------------------------------------------------------------------------------------
void llInsertTail(DList &l,data x)
{
	Node *P;
	P = Make_Node(x); //tao 1 Node P
	if (Isempty(l)) //Neu danh sach rong
	{
		l.Head = P;
		l.Tail = P;
	}
	else
	{
		l.Tail->Right = P; //ket noi voi danh sach
		P->Left = l.Tail; //P tro ve Node truoc
		l.Tail = P; //luu lai vi tri cuoi
	}
}//Chen phan tu vao vi tri cuoi
//----------------------------------------------------------------------------
void llInsertAfter(DList &l, int a, data x)
{
	Node *PH = l.Head, *PT, *R;
	int i = 1, length = llLength(l);
		R = Make_Node(x); //tao 1 Node P
		if (a == 1) llInsertHead(l, x); //chen vao vi tri dau tien
		else
			if (a == length + 1) llInsertTail(l, x); //chen vao vi tri cuoi
			else //chen vao vi tri 1<a<length+1
			{
				while (PH != NULL && i != a - 1) //duyet den vi tri k-1
				{
					i++;
					PH = PH->Right;
				}
				PT = PH->Right; //xac dinh vi tri k
				R->Right = PT;   //(1)
				R->Left = PH;    //(2)
				PH->Right = R;   //(3)
				PT->Left = R;    //(4)
			}
}//Chen phan tu vao vi tri a
//-----------------------------------------------------------------------
void llDeleteHead(DList &l)
{
	Node *ph = l.Head;
	ph = ph->Right;
	ph->Left = NULL;
	l.Head = ph;
}//Xoa vi tri dau
void llDeleteTail(DList &l)
{
	Node *pt = l.Tail;
	pt = pt->Left;
	pt->Right = NULL;
	l.Tail = pt;
}//Xoa vi tri cuoi
//--------------------------------------------------------------------------
void llDeleteAfter(DList &l, int a)
{
	Node *PH = l.Head, *PT;
	int i = 1, length = llLength(l);
		if (a == 1) llDeleteHead(l); //xoa vi tri dau tien
		else
			if (a == length) llDeleteTail(l); //xoa vi tri cuoi
			else //xoa vi tri 1<a<l+1
			{
				while (PH != NULL && i != a - 1) //duyet den vi tri a-1
				{
					i++;
					PH = PH->Right;
				}
				PT = PH->Right->Right; //xac dinh vi tri a+1
				PH->Right = PT;
				PT->Left = PH;
			}
}//Xoa vi tri thu a
//---------------------------------------------------------------------------------
void DeleteAll(DList &l)
{
	l.Tail = NULL;
	Node *ph = l.Head;
	ph = ph->Right;
	ph->Left = NULL;
	l.Head = ph;
	if (ph == NULL) return;
	DeleteAll(l);
}
int Search(DList L, data x) //tim x trong danh sach
{
	Node *P = L.Head;
	int i = 1;
	while (P != NULL && P->Data != x) //duyet danh sach den khi tim thay hoac ket thuc danh sach
	{
		P = P->Right;
		i++;
	}
	if (P != NULL) return i; //tra ve vi tri tim thay
	else return 0; //khong tim thay
}