#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
using namespace std;

#define MAX 10000
int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int n2 = n - 2; //n-2 phan tu
	int prufer[MAX] = { 0 };
	int prufer0[MAX] = { 0 };
	bool elements[MAX] = { 0 };


	srand(time(NULL));

	prufer[n2] = 0;

	for (int i = 0; i < n2; i++)
	{

		prufer[i] = rand() % (n2 + 2);

	}


	for (int i = 0; i < n2 + 1; i++) elements[prufer[i]] = true;


	for (int i = 0; i < n2 + 1; i++)
	{

		int j = 0; while (elements[j]) j++;  //tim phan tu nho nhat
		elements[j] = true;
		prufer0[i] = j;

		elements[prufer[i]] = false;        // Prufer[i] co the dung cho phan tu tiep theo
		for (int k = i + 1; k < n2 + 1; k++)   // tru khi prufer[i] co khong mat o phia sau 
			if (prufer[i] == prufer[k])
			{
				elements[prufer[i]] = true;
				break;
			}
	}
	ofstream file("C:/Users/Phoenix/source/repos/Color/color3/dothi.txt");
	file << n << " " << n - 1;
	for (int i = 0; i < n2 + 1; i++)
	{
			file << endl<<prufer0[i]+1 << " " << prufer[i]+1;
			cout << prufer0[i] << " " << prufer[i] << endl;
	}
	return 0;
}
