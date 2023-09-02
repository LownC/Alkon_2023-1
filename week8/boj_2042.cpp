#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000
#define MAX_VERTEX 801
#define MAX_EDGE 200001
using namespace std;

int N, E, v1, v2;
vector<pair<int, int>> edge[MAX_EDGE];
vector<int> d;

int dijkstra(int start, int end) {
	d = vector<int>(N+1,INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, start));
	d[start] = 0;
	while (!pq.empty()) {
		int current = pq.top().second;
		int start_to_current_distance = pq.top().first;
		pq.pop();

		if (d[current] < start_to_current_distance) {
			continue;
		}
		for (int i = 0; i < edge[current].size(); i++) {
			int next = edge[current][i].second;
			int start_to_next_distance = start_to_current_distance + edge[current][i].first;
			if (d[next] > start_to_next_distance) {
				d[next] = start_to_next_distance;
				pq.push(make_pair(start_to_next_distance, next));
			}
		}
	}
	return d[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(c,b));
		edge[b].push_back(make_pair(c,a));
	}
	cin >> v1 >> v2;

	int res1, res2;
	int a1 = dijkstra(1, v1);
	int a2 = dijkstra(v1, v2);
	int a3 = dijkstra(v2, N);
	if (a1 == INF || a2 == INF || a3 == INF)
		res1 = INF;
	else
		res1 = a1 + a2 + a3;
	
	int b1 = dijkstra(1, v2);
	int b2 = dijkstra(v2, v1);
	int b3 = dijkstra(v1, N);
	if (b1 == INF || b2 == INF || b3 == INF) 
		res2 = INF;
	else 
		res2 = b1 + b2 + b3;

	if (res1 == INF && res2 == INF)
		cout << -1;
	else
		cout << min(res1, res2);
	return 0;
}