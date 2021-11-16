#include <iostream>
#include <cmath>
#include <vector>
#define SIZE 2000002
bool prime[SIZE]; //False 가 소수임
std::vector<int> vec;

bool is_prime(long long number) {
	for (int i = 0; (long long)vec[i]* vec[i] <= number && i<vec.size(); i++) {
		if (number % vec[i] == 0)
			return false;
	}
	return true;
}
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	using namespace std;

	long long t, a, b;

	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i])
			continue;
		for (int j = i * i; j < SIZE; j += i) {
			prime[j] = true;
		}
	}
	for (int i = 1; i <= SIZE; i++) {
		if (!prime[i])
			vec.push_back(i);
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		bool flag = true;
		long long sum = a + b;

		if (sum < 4)
			cout << "NO\n";
		else if (sum % 2 == 0) // 골드바흐 추측 10^18 이하 에서는 참
			cout << "YES\n";
		else if (is_prime(sum - 2)) // 2+홀수 만이 유일답
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
