#include <iostream>
#define SIZE 100

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int test,n;
	int chapter[SIZE];
	int dp[SIZE][SIZE] = { 0 };
	int sums[SIZE] = { 0 };
	std::cin >> test;
	for (int i = 0; i < test; i++) {
		/*input*/
		std::cin >> n;
		for (int j = 1; j <= n; j++) {
			std::cin >> chapter[j];
			sums[j] = sums[j-1] + chapter[j];
		}

		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n-x; y++) {
				dp[y][y + x] = 100000000;
				for (int z = y; z < x+y; z++) {
					dp[y][y + x] = std::min(dp[y][y + x],  dp[y][z] + dp[z + 1][x + y] + sums[x + y] - sums[y - 1]);
				}
			}
		}
		std::cout << dp[1][n] << '\n';
	}
	return 0;
}