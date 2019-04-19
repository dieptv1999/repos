// merge_sort_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
int *merge(int *a, int mid, int l, int r)
{
	int *a1=new int[r-l+1],k=0;
	int i = l, j = mid + 1;
	for (; i <= mid && j <= r;)
	{
		if (a[i] > a[j]){
			a1[k++] = a[j++];
		}
		else{
			a1[k++] = a[i++];
		}
	}
	for (; i <= mid;) a1[k++] = a[i++];
	for (; j <= r;) a1[k++] = a[j++];
	for (i = 0; i < k; ++i) a[l + i] = a1[i];
	return a;
}
void merge_sort(int *a, int l,int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		a=merge(a, mid, l, r);
	}
}
int main()
{
	int a[] = { 1,8,954,765,8456,254,7854,465};
	merge_sort(a, 0, 7 ); 
	return 0;
}