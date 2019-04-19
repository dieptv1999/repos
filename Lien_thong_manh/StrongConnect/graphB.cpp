#include "graphB.h"
graph::graph(int n)
{
	nV = n;
	ladj = new vector<int>[nV];
}
graph::graph(ifstream &in)
{
	char u[5], v[5];
	int n = 0;
	while (!in.eof())
	{
		in >> s[n];
		n++;
	}
	nV = n / 5;
	ladj = new vector<int>[nV + 1];
	int i = 0, edge = 0;
	while (i < nV)//kiem tra canh co huong thi them vao danh sach canh
	{
		for (int j = i + 1; j < nV + 1; ++j)
		{
			if (isEdge(s, i, j))
			{
				addEdge(i, j);
				edge++;
			}
			if (isEdge(s, j, i))
			{
				addEdge(j, i);
				edge++;
			}
		}
		i++;
	}
	nE = edge;
}
bool graph::isEdge(char *s, int x, int y)//xem co phai do thi co huong k
{
	int k = 0;
	bool kt[5];
	memset(kt, false, 5*sizeof(bool));
	for (int i = 1; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
			if (*(s + x * 5 + i) == *(s + y * 5 + j) && !kt[j])
			{
				kt[j] = true;
				k++;
				break;
			}
	}
	if (k == 4) return true;
	else return false;
}
int graph::getnV()//ham tra ve so dinh
{
	return nV;
}
int graph::getnE()//ham tra ve so canh
{
	return nE;
}
vector<int> graph::adj(int v)//tra ve danh sach canh cua mot dinh
{
	return ladj[v];
}
void graph::addEdge(int v, int w)
{
	ladj[v].push_back(w);
}
void graph::printTop(int k)
{
	for (int j=0;j<5;++j)
		cout << s[k * 5 + j];
	cout << endl;
}
int graph::isTop(char *s1)
{
	for (int i = 0; i < nV; ++i)
	{
		int k = 0;
		for (int j = 0; j < 5; ++j)
			if (*(s + i * 5 + j) == s1[j])
			{
				k++;
			}
		if (k == 5) return i;
	}
	return -1;
}