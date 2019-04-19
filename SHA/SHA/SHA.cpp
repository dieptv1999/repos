// SHA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "sha256.h"
#include <string>
using namespace std;
int main()
{
	string s = "input";
	string output = sha256(s);
	//cout << output;
	return 0;
}