#include "graphB.h"
int index = 1;
list<int> stack1;
int visited[6000], lowlink[6000], a[6000];
int chu_trinh = 0;
bool dfs(graph &g, int head, int tail, int *disk, int *pred)
{
	list<int> queqe;//danh sach lien ket don tao ra danh sach luu tru cuc bo
	bool *visited;
	visited = new bool[g.getnV()];
	for (int i = 0; i < g.getnV(); ++i)
	{
		visited[i] = false;//tat ca cac dinh chua duoc duyet
		disk[i] = INT_MAX;
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
	bool isTrue = dfs(g, head, tail, disk, pred);
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
		g.printTop(path[j]);
	}
}
int main()
{
	ifstream fileinput("dothi.txt");
	graph g(fileinput);
	index = 0;
	memset(visited, -1, 6000 * sizeof(int));
	char su1[6], sv1[6];
	cout << "Nhap dinh bat dau (u):";
	cin >> su1;
	cin.ignore();
	cout << "Nhap dinh ket thuc (v):";
	cin >> sv1;
	int u = g.isTop(su1);
	int v = g.isTop(sv1);
	shortest_lane(g, u, v);
	getchar();
	return 0;
}
