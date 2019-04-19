// Min_heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
typedef int data;
void swap(data *a, data *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void Min_heapify(data *a,int n,int parent)
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
void Build_min_heap(data *a, int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
		Min_heapify(a, n, i);
}
void heap_sort(data *a,int n)
{
	Build_min_heap(a, n);
	for (int i = n - 1; i > 0; --i)
	{
		swap(a, a + i);
		Min_heapify(a, i, 0);
	}
}
int main()
{
	data a[] = { 4, 1 ,3, 2, 16, 9, 10, 14, 8, 7 };
	heap_sort(a, 10);
	for (int i : a) std::cout << i << " ";
	return 0;
}