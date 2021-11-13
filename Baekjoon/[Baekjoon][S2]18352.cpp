#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX 1000 // 1000000
void dijkstra(int start, int end, std::vector<int> line[MAX], int k) { // 시작 끝 저장공간
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

	int  p[MAX];
	memset(p, 10000001, sizeof(p));
	//DIkj
	p[start] = 0;
	pq.push(std::make_pair(0, start));
	while (!pq.empty()) {
		start = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (auto i = line[start].begin(); i != line[start].end(); i++) {
			int en = *i; // 도착지
			int yn = cost +1;//가중치
			if (p[en] > yn) {
				p[en] = yn;
				pq.push(std::make_pair(yn, en));
			}
		}
	}
	bool flag = true;
	for (int i = 1; i <= end; i++) {
		if (p[i] == k) {
			std::cout << i << "\n";
			flag = false;
		}
	}
	if (flag)
		std::cout << -1;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	using namespace std;

	int m, n, k, x, a,b;
	cin >> n >> m >> k >> x;
	vector< int> line[MAX];

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		line[a].push_back(b);
	}
	dijkstra(x, n, line, k);
}