#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000
#define MAX_VERTEX 20001
#define MAX_EDGE 300001
using namespace std;

int V,E,K;
vector<pair<int, int>> edge[MAX_EDGE];
int d[MAX_VERTEX];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue < pair<int, int>>pq; //pair<비용, 도착 노드> 형식의 우선 순위 큐,첫 번째 값을 기준으로 큰 값이 top 에 오도록 정렬되어있다.(내림차순)
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int current = pq.top().second;
		int start_to_current_distance = -pq.top().first;
		pq.pop();
		if (d[current] < start_to_current_distance) {
			continue;
		}
		for (int i = 0; i < edge[current].size(); i++) {
			int next = edge[current][i].second;
			int start_to_next_distance = start_to_current_distance + edge[current][i].first;
			if (d[next] > start_to_next_distance) {
				d[next] = start_to_next_distance;
				pq.push(make_pair(-start_to_next_distance, next)); //작은값이 맨 앞으로 오게 만들기 위해 음수화 시켜 push
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	cin >> K;
	for (int i = 1; i < V + 1; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(w, v));
	}

	dijkstra(K);
	for (int i = 1; i < V+1; i++) {
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}
	return 0;
}