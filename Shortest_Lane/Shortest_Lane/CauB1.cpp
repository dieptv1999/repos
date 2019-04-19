// Interconected.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "graphB.h"
int index = 1;
list<int> stack1;
int visited[6000], lowlink[6000],a[6000];
int chu_trinh=0;
int min(int a, int b)
{
	if (a > b) return b; else return a;
}
void dijk(graph &g,int u,bool kt) {
	lowlink[u] = visited[u] = index++;
	stack1.push_back(u);
	a[u] = 1;
	for (int v : g.adj(u)) 
	{
		if (visited[v] == -1) dijk(g,v,kt);
		if (a[v]) lowlink[u] = min(lowlink[u], lowlink[v]);
	}

	if (visited[u] == lowlink[u]) 
	{
		chu_trinh++;
		for (;;)
	    {
			int v = stack1.back(); 
			if (kt) g.printTop(v);
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
	//cout << g.getnE() << " " << g.getnV() << endl;
	memset(visited, -1, 6000*sizeof(int));
	memset(lowlink, 0, 6000*sizeof(int));
	memset(a, 0, 6000 * sizeof(int));
	for (int i = 0; i < g.getnV(); ++i)	if (visited[i] == -1) dijk(g, i, false);
	cout << "So thanh phan lien thong la: " << chu_trinh << endl;
	cout << "------------------------------------------------------------------" << endl;
	getchar();
	return 0;
} 
