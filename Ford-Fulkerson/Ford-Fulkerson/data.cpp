#include "data.h"
graph::graph(ifstream &in)
{
	in >> nV;
	in >> nE;
	ladj = new vector<pair<int,int>>[nV + 1];
	for (int i = 0; i < nV; ++i)
	{
		int x=0, y=0, z = 0;
		in >>x >> y >> z;
		ladj[x].push_back(pair<int, int>(y, x));
	}
}

int graph::getnV()
{
	return nV;
}
int graph::getnE()
{
	return nE;
}
void graph::setnV(int nV)
{
	this->nV = nV;
}
void graph::setnE(int nE)
{
	this->nE = nE;
}
vector<pair<int,int>> graph::getadj(int i)
{
	return ladj[i];
}