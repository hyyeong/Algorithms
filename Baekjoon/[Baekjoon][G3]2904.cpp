#include <iostream>
#include <vector>
#include <cmath>

#define SIZE 100005
bool primes[SIZE];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	using namespace std;
	
	int n, numbers[100], gcd = 1, count = 0;
	vector<pair<int, int>> prime; // 소수, 개수

	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (primes[i])
			continue;
		for (int j = i * i; j < SIZE; j += i) {
			primes[j] = true;
		}
	}
	for (int i = 2; i <SIZE; i++) {
		if (!primes[i]) {
			prime.push_back(make_pair(i, 0));
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) { //소인수 분해 및 입력
		cin >> numbers[i];
		int temp = numbers[i];
		int x = 0;
		while (temp != 1) {
			for (int j = x; j < prime.size(); j++) {
				if (temp % prime[j].first==0) {
					prime[j].second = prime[j].second + 1;
					temp/=prime[j].first;
					x = j;
					break;
				}
			}
		}
	}
	for (int x=0;x<prime.size();x++) { // n보다 큰 소수는 분배해줌 그래서 n을뺴줌
		if (prime[x].second >= n) {
			gcd *= prime[x].first;
			prime[x].second -= n;
			for (int i = 0; i < n; i++) {
				if (numbers[i] % gcd != 0) { // 분배횟수 체크 분배해줬으면 곱해줘야함
					count++;
					numbers[i] *= prime[x].first;
				}
			}
			x--;
		}
	}
	cout << gcd << " " << count;
}