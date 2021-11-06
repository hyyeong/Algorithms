#include <iostream>
#include <vector>
#include <map>
#define SIZE 1001
bool eristo[SIZE] = { 0 };
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<int> prime;
	std::vector<long long> factor;
	long long test_case,a,b,n;
	/* input data */
	std::cin >> test_case;
	for (int i = 2; i < SIZE; i++) {
		if (eristo[i]) continue;
		for (int j = 2 * i; j < SIZE; j += i) {
			eristo[j] = 1;
		}
	}
	for (int i = 2; i < SIZE; i++) {
		if (!eristo[i]) prime.push_back(i);
	}
	for (int i = 0; i < test_case; i++) {
		std::cin >> a >> b >> n;
		std::map<long long, int> mapping;
		factor.clear();
		//Factorization
		while (n > 1) {
			bool flag = false;
			for (auto p : prime) {
				if (n % p == 0) {
					n /= p;
					flag = true;
					mapping[p] = 1;
					break;
				}
			}
			if (!flag) break;
		}
		if (n != 1) mapping[n]=1;
		for (auto it = mapping.begin(); it != mapping.end(); it++) {
			factor.push_back((*it).first);
		}
		int size = factor.size();
		long long result=0;

		for (int d= 0; d < 1 << size; d++) {
			if (!d) continue;
			int cnt = 0;
			long long div = 1;
			for (int j = 0; j < size; j++) {
				if (d & (1 << j)) div *= factor[j], cnt++;
			}
			long long x = (a + div - 1) / div * div;
			long long c = b / div * div;
			if (x > c) continue;
			long long ga = (c - x) / div + 1;
			result += cnt % 2 ? ga : -ga;
		}

		std::cout << "Case #" << i + 1 << ": " << b - a + 1 - result << "\n";
	}

	return 0;
}
