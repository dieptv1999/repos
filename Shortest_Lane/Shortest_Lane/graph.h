#ifndef graph_h
#define graph_h

#include <vector>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;
class graph {
	int nV;
	int nE;
	int head;
	int tail;
	char *s = new char[100000];
	vector<int> *ladj;
public:
	graph(int);//contructor

	graph(ifstream &in, bool kt);//cntructor
	int getnV();
	int getnE();
	vector<int> adj(int v);
	void addEdge(int v, int w);
	string getEdge(int n);
	int gethead();
	int gettail();
	bool isEdge(char *s, int x, int y);
};
#endif // !graph_h