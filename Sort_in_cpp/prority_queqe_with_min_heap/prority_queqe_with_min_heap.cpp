// prority_queqe_with_min_heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void Min_heapify(int *a, int n, int parent)
{
	int min = 0;
	int left = 2 * (parent + 1) - 1;
	int right = 2 * (parent + 1);
	if (left < n && a[left] < a[parent]) min = left;
	else min = parent;
	if (right < n && a[right] < a[min]) min = right;
	if (min != parent)
	{
		swap(a + parent, a + min);
		Min_heapify(a, n, min);
	}
}
int Min(int *a)
{
	return *a;
}
int heap_extract_min(int *a,int *n)
{
	if (*n < 1) return -1;
	int min = *a;
	*a = *(a + *n - 1);
	Min_heapify(a, --*n, 0);
	return min;
}
int Increase_heap_min(int *a, int i, int key)
{
	if (key > a[i]) return a[i];
	a[i] = key;
	while (i > 1 && a[(i + 1) / 2] > a[i])
	{
		swap(a + (i + 1) / 2, a + i);
		i = (i + 1) / 2;
	}
	return a[i];
}
void Insert_key(int *a,int *n,int key)
{
	a = (int*)realloc(a, (++*n) * sizeof(int));
	a[*n - 1] = INT_MAX;
	int l=Increase_heap_min(a, *n, key);
}
int main()
{
	int *a=new int[1],*n=new int[1];
	*n = 1;
	*a = 1;
	Insert_key(a, n, 2);
	for (int i = 0; i < *n;++i) cout << a[i] << " ";
	return 0;
}