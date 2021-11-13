#include <iostream>
#include <queue>
#include <string>
#include<memory.h>
#define SIZE 10000
bool visited[SIZE] = { 0, };
void bfs() {
	std::queue<std::pair<int, std::string>> que;
	int a, b;
	std::cin >> a >> b;
	que.push(std::make_pair(a, ""));
	visited[a] = 1;
	while (!que.empty()) {
		int s = que.front().first;
		std::string k = que.front().second;
		que.pop();
		if (s == b) {
			std::cout << k << "\n";
			break;
		}
		if (2 * s < SIZE) { // D
			if (!visited[2 * s]) {
				que.push(std::make_pair(2 * s, k + "D"));
			}
		}
		else {
			if (!visited[2 * s % 10000]) {
				que.push(std::make_pair(2 * s % 10000, k + "D"));
			}
		}
		if (s - 1 > 0) {// S
			if (!visited[s - 1]) {
				que.push(std::make_pair(s - 1, k + "S"));
			}
		}
		else if (s == 0) {
			if (!visited[9999]) {
				que.push(std::make_pair(9999, k + "S"));
			}
		}
		int y = (s % 1000) * 10 + (s / 1000);
		if (!visited[y]) {
			que.push(std::make_pair(y, k + "L"));
		}
		y = (s % 10) * 1000 + (s / 10);
		if (!visited[y]) {
			que.push(std::make_pair(y, k + "R"));
		}
	}
}
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T, a, b;
	std::cin >> T;

	for (int z = 0; z < T; z++) {
		memset(visited, 0, sizeof(visited));
// USE DFS
		bfs();
	}
}