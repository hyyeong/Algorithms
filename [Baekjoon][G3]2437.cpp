#include <iostream>
#define SIZE 100

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	int scale[SIZE];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> scale[i];
	}
}