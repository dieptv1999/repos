#include <iostream>
#define MAX 100000
using namespace std;

int main()
{
	int *prufer0, *prufer,*n;
	int *step;
	int *code_prufer;
	int dem = 0;
	n = new int[1];
	cin >> *n;
	(*n)++;
	prufer0 = new int[*n];
	prufer = new int[*n];
	step = new int[MAX];
	memset(step, 0, MAX);
	for (int i = 0; i < *n-1; ++i)
	{
		cin >> *(prufer0 + i) >> *(prufer + i);
		(*(step+*(prufer0+i)))++;
		(*(step+*(prufer+i)))++;
	}
	code_prufer = new int[*n];
	bool isStart = true;
	while (isStart)
	{
		for (int i = 1; i < *n; ++i)
		{
			if (step[i] == 1)
			{
				for (int j = 0; j < *n; ++j)
				{
					if ((prufer0[j] == i) && step[prufer[j]] != 0)
					{
						step[prufer[j]]--;
						code_prufer[dem] = prufer[j];
						dem++;
						break;
					}
					if (prufer[j] == i && step[prufer0[j]] != 0)
					{
						step[prufer0[j]]--;
						code_prufer[dem] = prufer0[j];
						dem++;
						break;
					}
				}
				step[i]--;
				break;
			}
			if (i == *n - 1) isStart = false;
		}
	}
	dem--;
	for (int i = 0; i < dem; ++i) cout <<code_prufer[i]<<" ";
	delete(prufer0);
	delete(prufer);
	delete(n);
	delete(step);
	delete(code_prufer);
	getchar();
	return 0;
}