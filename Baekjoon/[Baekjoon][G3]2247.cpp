#include <iostream>
#include <algorithm>
#define SIZE 10
#define DIV 1000000
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	long long n, sum = 0;
	/* input data */
	std::cin >> n;

	/* ����� �� : i*c���� n�� ���尡��� ����c-1*/
	long long i = 2;
	for (i = 2; (n / i >= 2) && (i <= n); i++) {
		sum += (n / i * (n / i + 1) / 2) % DIV - 1;
		sum %= DIV;
	}

	std::cout << sum;
	return 0;
}