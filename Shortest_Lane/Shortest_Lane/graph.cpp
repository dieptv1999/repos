#include "graph.h"
graph::graph(int n)
{
	nV = n;
	ladj = new vector<int>[nV];
}
graph::graph(ifstream &in,bool kt)
{
	char u[5], v[5];
	int n = 0;
	if (kt)
	{
		cout << "Nhap dinh u:";
		cin >> u[0] >> u[1] >> u[2] >> u[3] >> u[4];
		cout << "Nhap dinh v:";
		cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
	}
	while (!in.eof())
	{
		in >> s[n];
		n++;
		if (kt && n > 4  && (head==0 || tail==0))
		{
			if (s[n - 1] == u[4] && s[n - 2] == u[3] && s[n - 3] == u[2] && s[n - 4] == u[1] && s[n - 5] == u[0]) head = n - 4;
			if (s[n - 1] == v[4] && s[n - 2] == v[3] && s[n - 3] == v[2] && s[n - 4] == v[1] && s[n - 5] == v[0]) tail = n - 4;
		}
	}
	nV = n / 5 + 1;
	head /= 5;
	tail /= 5;
	ladj = new vector<int>[nV + 1];
	int i = 0,edge=0;
	while (i < nV)
	{
		for (int j = i + 1; j < nV + 1; ++j)
		{
			if (isEdge(s, i, j))
			{
				addEdge(i, j);
				edge++;
			}
		}
		i++;
	}
	nE = edge;
}
bool graph::isEdge(char *s,int x,int y)
{
	int k = 0;
	for (int i = 0; i < 5; ++i)
		if (s[x*5 + i] != s[y*5 + i]) k++;
	if (k == 1) return true; else return false;
}
int graph::getnV()
{
	return nV;
}
int graph::getnE()
{
	return nE;
}
vector<int> graph::adj(int v)
{
	return ladj[v];
}
void graph::addEdge(int v, int w)
{
	ladj[v].push_back(w);
	ladj[w].push_back(v);
}
string graph::getEdge(int n)
{
	string s1="";
	for (int i = 0; i < 5; ++i) s1 += s[n * 5 + i];
	return s1;
}
int graph::gethead()
{
	return head;
}
int graph::gettail()
{
	return tail;
}