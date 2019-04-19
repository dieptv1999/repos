#include "graph.h"
#include <string>
bool dijk(graph &g, int head, int tail, int *disk, int *pred)
{
	list<int> queqe;//danh sach lien ket don tao ra danh sach luu tru cuc bo
	bool *visited;
	visited = new bool[g.getnV()];
	for (int i = 0; i < g.getnV(); ++i)
	{
		visited[i] = false;//tat ca cac dinh chua duoc duyet
		disk[i] = -100000;
		pred[i] = -1;
	}
	visited[head] = true;
	disk[head] = 0;
	queqe.push_back(head);
	while (!queqe.empty())
	{
		int u = queqe.front();//gan u= gia tri node dau tien trong danh sach
		queqe.pop_front();//xoa node dau tien trong danh sach
		for (int j = 0; j < g.adj(u).size(); j++)
		{
			if (!visited[g.adj(u)[j]])
			{
				visited[g.adj(u)[j]] = true;
				disk[g.adj(u)[j]] = disk[u] + 1;//danh nhan cho dinh ke tiep bang dinh hien tai +1
				pred[g.adj(u)[j]] = u;
				queqe.push_back(g.adj(u)[j]);//them node vao danh sach lien ket don
				if (g.adj(u)[j] == tail) return true;
			}
		}
	}
	delete(visited);
	return false;
}
void shortest_lane(graph &g, int head, int tail)
{
	vector<int> path;
	int *disk, *pred;
	disk = new int[g.getnV()];
	pred = new int[g.getnV()];
	bool isTrue = dijk(g, head, tail, disk, pred);
	if (!isTrue)
	{
		cout << "Khong lien thong";
		return;
	}
	path.push_back(tail); //them vao danh sach dinh cuoi cung
	int c = tail;
	while (pred[c] != -1)
	{
		path.push_back(pred[c]);
		c = pred[c];
	}
	for (int j = path.size() - 1; j >= 0; --j)
	{
		string s2 = g.getEdge(path[j]);
		cout << s2 << " ";
	}
}
int main()
{
	ifstream fileinput;
	fileinput.open("dothi.txt");
	if (fileinput.fail()) cout << "fail!";
	graph g(fileinput, true);
	int head = g.gethead();
	int tail = g.gettail();
	if (head == -1 || tail == -1) cout << "Khong ton tai 1 trong 2 dinh!";
	else
		shortest_lane(g, head, tail);
	getchar();
	return 0;
}

