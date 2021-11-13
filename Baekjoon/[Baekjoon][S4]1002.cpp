#include <iostream>
#include <math.h>
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	using namespace std;

	int test_case,x1,x2,y1,y2,r1,r2,result;
	cin >> test_case;
	/* 원의 접선을 이용한 풀이.*/
	for (int i = 0; i < test_case; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double between_circle = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if (r2 > r1) {
			int temp = r1; r1 = r2; r2 = temp;
		}
		double plus = r1 +r2;
		double minus = r1 - r2;

		if (between_circle == 0) {
			if (r1 == r2)
				result = -1;
			else
				result = 0;
		}

		else if (between_circle < plus && between_circle>minus)//2
			result = 2;
		else if (between_circle == plus || between_circle == minus)//1
			result = 1;
		else
			result = 0;
		cout << result << '\n';
	}
}