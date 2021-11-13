#include <queue>
#include <iostream>
#include <map>
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	using namespace std;
	long long  a, b,result=-1;
	queue<pair<long long, long long >> que; // first : a , second : level
	map<long long, bool> check;
	cin >> a >> b;
	que.push(make_pair(a,1));
	while (!que.empty()) {
		long long  number = que.front().first;
		long long  cost = que.front().second;
		que.pop();
		if (number == b) {
			if (result > cost && result != -1)
				result = cost ;
			else if (result == -1)
				result = cost ;
		}
		else if (number > b)
			continue;
		if (check[number * 2]!=true) {
			que.push(make_pair(number * 2, cost + 1));
			check[number * 2] = true;
		}
		if (check[number * 10 + 1]!=true) {
			que.push(make_pair(number * 10 + 1, cost + 1));
			check[number * 10 + 1] = true;
		}
	}
	cout << result;
}