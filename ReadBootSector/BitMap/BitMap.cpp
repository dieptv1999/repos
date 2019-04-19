// BitMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
bool cap_phat(int n,char *a,int size_program) {
	for (int i = 0; i < n; ++i) {
		if (!a[i]) {
			for (int j = i; a[j] = 0 && j < n; ++j)
				if (j - i == size_program)
				{
					replace(i, j, 0, 1);
					
					return true;
				}
		}
	}
	return false;
}
void delete_(char *a, int start, int size) {
	replace(start, size + start, 1, 0);
}
int main()
{
	int size_memory = 0;
	cin.ignore();
	cout << "Nhap kich thuoc bo nho can quan li:";
	cin >> size_memory;
	int n = 0;
	cout << "Nhap kich thuoc o nho:";
	cin >> n;
	char *a = new char[size_memory/n];
	cout << "Nhap ban do bitmap:";
	cin >> *a;
	int size_program = 0;
	cout << "Nhap kich thuoc chuong trinh:";
	cin >> size_program;
	if (cap_phat(size_memory / n, a, ceil(size_program / float(n)))) cout <<"successful";
	else cout << "Fail";
	return 0;
}