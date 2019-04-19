#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
typedef struct Node {
	char c;
	int index;
	Node *left;
	Node *right;
	Node() {
		c = '\0';
		index = 0;
		left = NULL;
		right = NULL;
	}
	Node(char c, int key, Node *left, Node *right) {
		this->c = c;
		this->index = key;
		this->left = left;
		this->right = right;
	}
} Node;
struct Bit {
	char c;
	string bit;
	Bit(char c, string bit) {
		this->c = c;
		this->bit = bit;
	}
};
class Huffman {
private:
	string input;
	Node *root;
	vector<Bit*> tree_bit;
	string output;
public:
	Node *getRoot() {
		return root;
	}
	void convert(string s);
	void decoder();
	void showRoot(Node *root);
	void generate(Node *root);
	void write_File(string out);
	vector<Bit*> getTreeBit() {
		return tree_bit;
	}
	string getoutput();
	Huffman(string input);
};