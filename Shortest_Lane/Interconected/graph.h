#pragma once
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
	int head=0;
	int tail=0;
	vector<int> *ladj;
public:
	graph(int);//contructor

	graph(ifstream &in);//cntructor
	int getnV();
	int getnE();
	int gethead();
	int gettail();
	vector<int> adj(int v);
	void addEdge(int v, int w);
	void print();
	void  printGraviz();
	bool isEdge(char *s, int x, int y);
};
#endif // !graph_h