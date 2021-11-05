#include <iostream>
#include <algorithm>
#define SIZE 100

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,sum=0;
	int scale[SIZE];
	/* input data */
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> scale[i];
	}
	std::sort(scale, scale + n);
	for (int i = 0; i < n; i++) {
		if (sum + 1 >= scale[i])
			sum += scale[i];
		else
			break;
	}
	std::cout << sum;
}