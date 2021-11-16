#include <iostream>
#include <memory.h>
#include <queue>
#define SIZE 100

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	using namespace std;

	queue<pair<int, int>> bfs;
	bool visited[SIZE][SIZE];
	char map[SIZE][SIZE];
	int n;
	int standard=0, notstandard = 0;
	cin >> n;
	//input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	// 일반인
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j])
				continue;
			standard++;
			bfs.push(make_pair(i, j));
			visited[i][j] = true;
			while (!bfs.empty()) {
				int y = bfs.front().first;
				int x = bfs.front().second;
				bfs.pop();
				for (int k = 0; k < 4; k++) {
					int ky = y + dy[k];
					int kx = x + dx[k];
					if (ky < 0 || kx < 0 || ky == n || kx == n)
						continue;
					if (!visited[ky][kx] && map[y][x] == map[ky][kx]) {
						bfs.push(make_pair(ky, kx));
						visited[ky][kx] = true;
					}
				}
			}
		}
	}
	//색약

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j])
				continue;
			notstandard++;
			bfs.push(make_pair(i, j));
			visited[i][j] = true;
			while (!bfs.empty()) {
				int y = bfs.front().first;
				int x = bfs.front().second;
				bfs.pop();
				for (int k = 0; k < 4; k++) {
					int ky = y + dy[k];
					int kx = x + dx[k];
					int sum = map[y][x] + map[ky][kx];
					if (ky < 0 || kx < 0 || ky == n || kx == n)
						continue;
					if (!visited[ky][kx] &&( sum != 137 && sum !=148) ) {
						bfs.push(make_pair(ky, kx));
						visited[ky][kx] = true;
					}
				}
			}
		}
	}
	cout << standard << " " << notstandard;
}