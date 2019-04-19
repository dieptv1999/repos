// Ford-Fulkerson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "data.h"
int f[100][100],cf[100][100],*p;
void find_path(graph g, int s,int t,int *e,int *p)//tìm luồng tăng p
{
	int *visit;
	visit = new int[g.getnV()];
	memset(p, -1, g.getnV()*sizeof(int));
	memset(e, -1, g.getnV()*sizeof(int));
	memset(visit, -1, g.getnV()*sizeof(int));
	//p[v],e[v] là nhãn của đỉnh v
	p[t] = t;//path
	e[s] = s;//path đảo ngược
	visit[s] = 1;
	list<int> None;
	None.push_back(s);
	while (!None.empty())//duyet bfs
	{
		int u = None.front();
		None.pop_front();
		for (pair<int,int> v : g.getadj(u))
		{
			if (visit[v.first] == -1)
			{
				e[v.first] = u;
				visit[v.first] = 1;
				None.push_back(v.first);
			}
		}
	}
	int dest = t;
	while (e[dest] != dest && e[dest] != -1)
	{
		p[e[dest]] = dest;
		dest = e[dest];
	}
	if (dest != s) p[s] = -1;
}
void BuildResidualGraph(graph g) {
	int i = 0;
	for (i = 0; i < g.getnV(); i++) {
		memset(cf[i], 0, g.getnV() * sizeof(int)); // clear CF
	}
	int u = 0;
	for (u = 0; u < g.getnV(); u++) {
		for (pair<int,int> v:g.getadj(u)) 
		    if (cf[u][v.first]>0)
		    {
				cf[u][v.first] = v.second - f[u][v.first];
				if (f[u][v.first] > 0) cf[v.first][u] = f[u][v.first];
		    }
	}
}
void Inc_Flow(int *e,int *p,int s,int t)//Tăng luồng theo p
{
	int v = p[t];
	int u = t;
	int tang = e[t];
	while (u != s)
	{
		if (v > 0) f[v][u] += tang;
		else
		{
			v = -v;
			f[u][v] -= tang;
		}
		u = v; v = p[u];
	}
}
void Augment(graph g, int delta, int *p, int s, int t) {
	int i = 0;
	// augment
	int v = s;
	while (p[v] != v) {
		/*if (C[v][P[v]] > 0) F[v][P[v]] += delta;
		else F[P[v]][v] -= delta;*/
		bool isFalse = true;
		for (pair<int, int> u : g.getadj(v))
		{
			if (u.first == p[v])
			{
				f[v][p[v]] += delta;
				isFalse = false;
				break;
			}
		}
		if (isFalse) f[p[v]][v] -= delta;
		v = p[v];
	}
}
void Ford_fulkerson(graph g,int s,int t)
{
	int *e;
	e = new int[g.getnV()];
	memset(f, 0, 100 * 100 * sizeof(int));
	while (1) {
		BuildResidualGraph(g);
		find_path(g, s, t, e, p);
		if (p[s] == -1) break;
		int delta = INT_MAX;
		int v = s;
		while (p[v] != v) { // note that P[t] = t
			delta = (cf[v][p[v]] < delta ? cf[v][p[v]] : delta);
			v = p[v];
		}
		Augment(g, delta, p, s, t);
	}
}
int main()
{
	ifstream in;
	in.open("data.txt");
	graph g(in);
	p = new int[g.getnV()];
	Ford_fulkerson(g, 0, 6);
	for (int i = 0; i < 7; ++i) cout << p[i];
	return 0;
}