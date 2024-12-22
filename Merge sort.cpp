//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//// 假设这是图节点结构体，这里简单用个int值代表节点，实际可能更复杂
//struct Node {
//    int val;
//    vector<Node*> neighbors;
//};
//
//// 广度优先搜索函数
//void bfs(Node* start) {
//    if (start == nullptr) return;
//    vector<bool> visited;  // 标记节点是否已访问
//    queue<Node*> q;
//
//    visited.push_back(false);
//    q.push(start);
//    visited[start->val] = true;
//
//    while (!q.empty()) {
//        Node* cur = q.front();
//        q.pop();
//        cout << cur->val << " ";  // 这里简单输出节点值，实际可按需操作
//
//        for (Node* neighbor : cur->neighbors) {
//            if (!visited[neighbor->val]) {
//                visited[neighbor->val] = true;
//                q.push(neighbor);
//            }
//        }
//    }
//}
//
//int main() {
//    Node nodes[5];  // 简单假设5个节点
//    for (int i = 0; i < 5; ++i) {
//        nodes[i].val = i;
//    }
//    // 手动构建简单邻接关系，这里简单示意
//    nodes[0].neighbors.push_back(&nodes[1]);
//    nodes[0].neighbors.push_back(&nodes[2]);
//    nodes[1].neighbors.push_back(&nodes[3]);
//    nodes[2].neighbors.push_back(&nodes[4]);
//
//    bfs(&nodes[0]);
//
//    return 0;
//}



//#include <iostream>
//using namespace std;
//int main() 
//{
//    int n, m, k;
//    cin >> n >> m;
//    k = n * m;
//    cout << k << endl;
//
//    return 0;
//}



#include<iostream>
#include<vector>
using namespace std;
void px(vector<int>& m, int x, int z, int y)
{
	int* p = new int[y - x + 1];
	int k = 0, f = x, g = z+1;
	while (f <= z && g <= y)
	{
		if (m[f] <= m[g])
			p[k++] = m[f++];
		else p[k++] = m[g++];
	}
	while (f <= z)
		p[k++] = m[f++];
	while (g <= y)
		p[k++] = m[g++];
	for (int i = x; i <= y; i++)
		m[i] = p[i - x];
	delete[]p;
}
void sort(vector<int>& m, int x, int y)
{
	if (x >= y)return;
	int k = (x + y) / 2;
	sort(m, x, k);
	sort(m, k + 1, y);
	px(m, x, k, y);
}
int main()
{
	int n;
	cin >> n;
	vector<int>m(n);
	for (int i = 0; i < n; i++)
		cin >> m[i];
	sort(m, 0, n - 1);
	for (int j = 0; j < n; j++)
		cout << m[j] << " ";

	return 0;
}