#include <iostream>
#define SIZE 1000001
int gcd(int a, int  b);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,del=-1,maxgcd=0;
	int number[SIZE] = { 0 };
	int left_gcd[SIZE] = { 0 };
	int right_gcd[SIZE] = { 0 };
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> number[i];
	}

	for (int i = 1; i <= n; i++) {
		left_gcd[i] = gcd(number[i], left_gcd[i - 1]);
	}
	for (int i = n; i > 0 ; i--) {
		right_gcd[i] = gcd(number[i], right_gcd[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		int x = gcd(left_gcd[i - 1], right_gcd[i + 1]);
		if ((x > maxgcd) &&( number[i]%x)) {
			maxgcd = x;
			del = number[i];
		}
	}
	if (del == -1) std::cout << -1;
	else std::cout << maxgcd << " " << del;
	return 0;
}
int gcd(int a, int  b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}