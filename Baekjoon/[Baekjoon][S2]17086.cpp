#include <iostream>
#include <queue>
#define SIZE 50
/* fail */
void copy_map(int n, int m, int a[][SIZE], int b[][SIZE]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
	int dy[8] = { -1,1,0,0,-1,1,1,-1 };
	std::queue<std::pair<int,int>> sharks;
	int map[SIZE][SIZE];
	int copy[SIZE][SIZE];
	int n, m;
	/*input data*/
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { // map[y][x]
			std::cin >> map[i][j];
			copy[i][j] = map[i][j];
			if (map[i][j] == 0)
				sharks.push(std::make_pair(i,j));// y, x
		}
	}
	int max = 0;
	while (!sharks.empty()) {
		int y = sharks.front().first;
		int x = sharks.front().second;
		sharks.pop();
		std::queue<std::pair<int, int>> coor;
		coor.push(std::make_pair(y, x));
		int level = 1;
		int clevel = 1;
		bool flag = true;
		copy_map(n, m, map, copy);
		while (!coor.empty() && flag) {
			int px = coor.front().second;
			int py = coor.front().first;
			coor.pop();
			map[py][px] = 2;
			for (int i = 0; i < 8; i++) {
				int cx = px + dx[i];
				int cy = py + dy[i];
				if (cx < 0 || cy < 0 || cx >= m || cy >= n)
					continue;
				if (map[cy][cx] == 0) {
					map[cy][cx] = 2;
					coor.push(std::make_pair(cy, cx));
				}
				else if (map[cy][cx] == 1) {
					clevel = level;
					flag = false;
				}
			}
			level++;
		}
		if (max < clevel)
			max = clevel;
	}
	std::cout << max;
}