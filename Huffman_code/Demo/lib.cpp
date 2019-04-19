#include "lib.h"
void Huffman::convert(string s) {
	vector<Node*> tree_Node;
	//tạo bảng lưu lại số lần xuất hiện
	for (int i : s) {
		bool check = false;
		for (Node* j : tree_Node) 
			if (j->c == i) {
				j->index++;
				check = true;
				break;
			}
		if (!check) {
			tree_Node.push_back(new Node(i, 1, NULL, NULL));
		}
	}
	//sắp xếp tăng dần
	for (int i=0;i<tree_Node.size()-1;++i)
		for (int j=i+1;j<tree_Node.size();++j)
			if (tree_Node[i]->index > tree_Node[j]->index) {
				Node *t = tree_Node[i];
				tree_Node[i] = tree_Node[j];
				tree_Node[j] = t;
			}
	for (Node* j : tree_Node) cout << j->c<<" "<<j->index << "!";
	while (1) {
		Node *t = new Node();
		t->left = tree_Node[0];
		t->right = tree_Node[1];
		t->index = tree_Node[0]->index + tree_Node[1]->index;
		tree_Node.erase(tree_Node.begin(), tree_Node.begin() + 2);
		tree_Node.resize(tree_Node.size() + 1);
		if (tree_Node.size() == 1) {
			tree_Node[0] = t;
			break;
		}
		else {
			for (int j = 0; j < tree_Node.size() - 1; j++)
			{
				bool isMax = true;
				if (tree_Node[j]->index > t->index)
				{
					for (int k = tree_Node.size() - 1; k > j; k--)
					{
						tree_Node[k] = tree_Node[k - 1];
					}
					tree_Node[j] = t;
					isMax = false;
					break;
				}
				if (isMax) tree_Node[tree_Node.size() - 1] = t;
			}
		}
	}
	root = tree_Node[0];
}
void Huffman::showRoot(Node *root) {
	cout <<root->c<<" "<< root->index << endl;
	if (root->left!=NULL) showRoot(root->left);
	if (root->right!=NULL) showRoot(root->right);
}
Huffman::Huffman(string input) {
	this->input = input;
	convert(input);
	output = "";
}
string x = "";
void Huffman::generate(Node *root) {
	if (!root->left && !root->right) {
		tree_bit.push_back(new Bit(root->c, x));
		x.erase(x.end()-1,x.end());
		return;
	}
	if (root->left) {
		x += "0";
		generate(root->left);
	}
	if (root->right) {
		x += "1";
		generate(root->right);
	}
	if (x!="")
	x.erase(x.end() - 1, x.end());
}
void Huffman::decoder() {
	for (char c : input) {
		for (Bit* b : tree_bit) {
			if (c == b->c) {
				output += b->bit;
				break;
			}
		}
	}
}
string Huffman::getoutput() {
	decoder();
	return output;
}
void Huffman::write_File(string out) {
	uint32_t l = out.length();
	while (out.length() % 8 != 0) out.append("0");
	ofstream f;
	f.open("data.txt");
	f << l;
	f << std::hex << out;
	f.close();
}