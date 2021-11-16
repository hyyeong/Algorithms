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
	vector<pair<int, int>> prime; // �Ҽ�, ����

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
	for (int i = 0; i < n; i++) { //���μ� ���� �� �Է�
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
	for (int x=0;x<prime.size();x++) { // n���� ū �Ҽ��� �й����� �׷��� n������
		if (prime[x].second >= n) {
			gcd *= prime[x].first;
			prime[x].second -= n;
			for (int i = 0; i < n; i++) {
				if (numbers[i] % gcd != 0) { // �й�Ƚ�� üũ �й��������� ���������
					count++;
					numbers[i] *= prime[x].first;
				}
			}
			x--;
		}
	}
	cout << gcd << " " << count;
}