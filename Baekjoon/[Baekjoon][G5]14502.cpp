#include <iostream>
#include <algorithm>
#include <queue>
#define SIZE 8
void make_wall(int count);
void copy_map(int copy[][SIZE], int map[][SIZE]);
void bfs();
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int map[SIZE][SIZE];//original
int copy[SIZE][SIZE];//size

int maximum = 0;
int one_sum = 0, two_sum = 0;
std::queue<std::pair<int, int>> original_que;
int b14502(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	
	/* input data */
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 2) {
				original_que.push(std::make_pair(i, j));
				two_sum++;
			}
			else if (map[i][j] == 1)
				one_sum++;
		}
	}
	/*search all number of cases */
	make_wall(0);
	std::cout << maximum;

	return 0;
}
void bfs() {
	std::queue<std::pair<int, int>> copy_que;
	copy_que = original_que;
	int total_two_sum = two_sum; //total_two_sum;
	copy_map(copy,map);
	while (!copy_que.empty()) {
		int x = copy_que.front().first;
		int y = copy_que.front().second;
		copy_que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && copy[nx][ny] == 0) {
					copy_que.push(std::make_pair(nx, ny));
					copy[nx][ny] = 2;
					total_two_sum++;
			}
		}
	}
	maximum = std::max(n * m - (total_two_sum + 3 + one_sum), maximum);
}
void copy_map(int copy[][SIZE],int map[][SIZE]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy[i][j]=map[i][j];
		}
	}
}
void make_wall(int count) {
	if (count == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0)
				continue;
			map[i][j] = 1;
			make_wall(count + 1);
			map[i][j] = 0;
		}
	}
}