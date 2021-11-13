#include <iostream>
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	using namespace std;
	int x1, y1, p1, q1, x2, y2, p2, q2;
	char result;

	for (int i = 0; i < 4; i++) {
		/*input square*/
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

		x1 = max(x1, x2);
		p1 = min(p1, p2);
		y1 = max(y1, y2);
		q1 = min(q1, q2);

		x2 =  p1-x1;
		y2 = q1-y1;

		if (x2 > 0 && y2 > 0)
			result = 'a';
		else if (x2 < 0 || y2 < 0)
			result = 'd';
		else if (x2 == 0 && y2 == 0)
			result = 'c';
		else
			result = 'b';
		cout << result << endl;
	}
}