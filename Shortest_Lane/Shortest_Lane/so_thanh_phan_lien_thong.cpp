//Dem so thanh phan lien thong

#include "graph.h"
void dijk(graph &g, int *chu_trinh)
{
	list<int> queqe;
	int head = 0;
	//danh sach lien ket don tao ra danh sach luu tru cuc bo
	bool *visited;
	visited = new bool[g.getnV()];
	for (int i = 0; i < g.getnV(); ++i)
	{
		visited[i] = false;//tat ca cac dinh chua duoc duyet
		//disk[i] = INT_MAX;
		//pred[i] = -1;
	}
	while (head<g.getnV())
	{
		if (!visited[head])
		{
			visited[head] = true;
			//disk[head] = 0;
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
						//disk[g.adj(u)[j]] = disk[u] + 1;//danh nhan cho dinh ke tiep bang dinh hien tai +1
						//pred[g.adj(u)[j]] = u;
						queqe.push_back(g.adj(u)[j]);//them node vao danh sach lien ket don
					}
				}
			}
			(*chu_trinh)++;
		}
		head++;
	}
}
int main()
{
	ifstream fileinput("dothi.txt");
	graph g(fileinput,false);
	int *chu_trinh;
	chu_trinh = new int[1];
	*chu_trinh = 0;
	dijk(g, chu_trinh);
	cout << *chu_trinh;
	return 0;
}
