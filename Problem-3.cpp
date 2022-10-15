#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000;
int from[maxn], to[maxn], weight[maxn], index[maxn], type[maxn];
int pe[maxn], visit[maxn] , depth[maxn],h[maxn];
vector<pair<int, int>> edges[maxn];


int cmp(int x , int y) {
	return weight[x] < weight[y];
}

void addEdge(int from, int to, int index) {

	if (from == to)return;
	type[index] = 1;
	edges[from].push_back({to, index});
	edges[to].push_back({ from, index });
}

void dfs(int n , int ind , int dpth) {

	visit[n] = 1;
	depth[n] = dpth;

	for (auto i : edges[n]) {
		if (!visit[i.first]) {
			dfs(i.first, i.second, dpth + 1);
			depth[n] = min(depth[n], depth[i.first]);
		}
		else if (i.second!=ind) {
			depth[n] = min(depth[n], depth[i.first]);

		}
	}
	if (depth[n] == dpth) type[ind] = 2;


}

int getNode(int x) {
	if (pe[x])
		x = pe[x];
	
	return x;
}

void unite(int from, int to) {
	edges[from].clear();
	edges[to].clear();
	visit[from] = 0;
	visit[to] = 0;
	
	if (from == to)return;

	if (h[from] > h[to]) {
		pe[to] = from;
	}
	else {
		pe[from] = to;
		if (h[from] == h[to])
			h[to]++;
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> from[i] >> to[i] >> weight[i];
		index[i] = i;
	}

	sort(index, index + m +1, cmp);

	for (int i = 1; i <= m; ) {
		int j;

		for ( j = i; weight[index[j]] == weight[index[i]]; j++)
		{
			addEdge(getNode(from[index[j]]), getNode(to[index[j]]) , index[j]);
		}
		for (j = i; weight[index[j]] == weight[index[i]]; j++) {
			int n = getNode(from[index[j]]);
			if (!visit[n])dfs(n, 0, 0);

		}
		for (j = i; weight[index[j]] == weight[index[i]]; j++) {
			unite(getNode(from[index[j]]), getNode(to[index[j]]));
		}

		i = j;
	}


	for (int i = 1; i <= m; i++) {
		if (type[i] == 1) cout << ("at least one") << endl;
		else if (type[i] == 2) cout << ("any") << endl;
		else cout << ("none") << endl;
	}


	return 0;
}

