// Huffman_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//creat huffman code
#include "lib.h"
int main()
{
	Huffman *h = new Huffman("Dai hoc Bach Khoa Hanoi");
	cout << h->getRoot()->index;
	h->showRoot(h->getRoot());
	h->generate(h->getRoot());
	vector<Bit*> r = h->getTreeBit();
	for (Bit* b : r) {
		cout << b->c << " " << b->bit << endl;
	}
	h->write_File(h->getoutput());
	cout<<h->getoutput();
	return 0;
}