#pragma once
#ifndef graphB_h
#define graphB_h

#include <vector>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;
class graph {
	int nV;
	int nE;
	char *s = new char[100000];
	vector<int> *ladj;
public:
	graph(int);//contructor

	graph(ifstream &in);//cntructor
	int getnV();
	int getnE();
	vector<int> adj(int v);
	void addEdge(int v, int w);
	void  printTop(int k);
	bool isEdge(char *s, int x, int y);
	int isTop(char *s1);
};
#endif 
