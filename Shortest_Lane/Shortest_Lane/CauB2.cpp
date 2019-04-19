#include "graphB.h"
int index = 1;
list<int> stack1;
int visited[6000], lowlink[6000], a[6000];
int chu_trinh = 0;
int min(int a, int b)
{
	if (a > b) return b; else return a;
}
void dijk(graph &g, int u, bool kt) 
{
	lowlink[u] = visited[u] = index++;
	stack1.push_back(u);
	a[u] = 1;
	for (int v : g.adj(u))
	{
		if (visited[v] == -1) dijk(g, v, kt);
		if (a[v]) lowlink[u] = min(lowlink[u], lowlink[v]);
	}

	if (visited[u] == lowlink[u])
	{
		chu_trinh++;
		for (;;)
		{
			int v = stack1.back();
			if (kt && stack1.size()!=1) g.printTop(v);
			stack1.pop_back();
			a[v] = 0;
			if (u == v) break;
		}
	}
}
int main()
{
	ifstream fileinput("dothi.txt");
	graph g(fileinput);
	memset(visited, -1, 6000 * sizeof(int));
	memset(lowlink, 0, 6000 * sizeof(int));
	memset(a, 0, 6000 * sizeof(int));
	cout << "Cau b:" << endl;
	//cin.ignore();
	cout << "Nhap dinh u :";
	char su[6];
	cin >> su;
	int k = g.isTop(su);
	index = 0;
	if (k == -1)
		cout << "Khong ton tai dinh u!";
	else
	{
		cout << "So dinh lien thong voi u la:" << endl;
		dijk(g, k, true);
	}
	getchar();
	return 0;
}
