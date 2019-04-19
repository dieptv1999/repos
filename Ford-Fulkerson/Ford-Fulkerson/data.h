#pragma once
#define _data_h
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <map>

using namespace std;
class graph
{
	int nV;
	int nE;
	vector<pair<int,int>> *ladj;
public:
	graph(ifstream &in);
	int getnV();
	void setnV(int nV);
	int getnE();
	void setnE(int nE);
	vector<pair<int,int>> getadj(int i);
};