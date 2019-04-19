
#include "pch.h"
#include <iostream>
using namespace std;
bool in_prufer(bool *arr,int *a,int *b,int n)
{
	int i = 0;
 	for (int j=0;j<n;++j)
		while(1)
	    {
		     i++;
			 if (i > n+1) return false;
			 int t = n+2;
			 bool kt = true;
			 if (j > 0 && *(a + j - 1) < i && *(a + j - 1) != 0) t = *(a + j - 1); else t = i;
			 for (int k = j; k < n; ++k)
			 {
				 if (*(a + k) == i)
				 {
					 kt = false;
				 }
				 if (*(a + k) == t)
				 {
					 t = i;
					 break;
				 }
			 }
			 if (kt)
			 {
				 if (*(arr + t))
					 *(b + j) = t;
					 *(arr + t) = false;
					 break;
			 }
	    }
	return true;
}
int main()
{
	int *a,*b;
	bool *arr;
	int n;
	cout << "Nhap so phan tu cua ma prufer:";
	cin >> n;
	a = new int[n + 1];
	b = new int[n + 1];
	arr = new bool[n + 2];
	memset(b, 0, n + 1);
	memset(arr, true, n + 2);
	for (int i = 0; i < n; ++i)
	{
		cout << "Nhap phan tu thu " << i + 1 << ":=";
		cin >> *(a + i);
	}
	n++;
	*(a + n - 1) = 0;
	bool kt=in_prufer(arr, a, b, n);
	if (kt)
	{
		for (int i = 0; i < n; ++i) cout << *(b + i) << " ";
		cout << endl;
		for (int i = 0; i < n; ++i) cout << *(a + i) << " ";
	}
	else cout << "day prufer k thao man";
	return 0;
}