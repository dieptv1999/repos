#include <iostream>
using namespace std;
int main()
{
	int a[100000];
	for (int i = 0; i < 100000; ++i)
	{
		a[i] = rand() % 100000;
	}
	for (int i = 0; i< 100000; ++i)
		cout << a[i] << endl;
	return 0;
}