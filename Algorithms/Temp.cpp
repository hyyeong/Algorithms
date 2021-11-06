/*
void extended_euclid(long long a, long long b, long long& x, long long& y) { //x,y는 배주계수
	long long temp_a = a, temp_b = b, gcd, xd = 0, yd = 0;
	long long arr[1000]; // 0 = a, 1 = b;
	for (int i = 0; true; i++) {
		gcd = temp_a % temp_b;
		if (gcd != 0) {
			arr[i] = -(temp_a / temp_b);
			temp_a = temp_b;
			temp_b = gcd;
		}
		else {
			xd = 1;
			yd = arr[i - 1];
			for (int j = i - 2; j >= 0; j--) {
				long long temp = xd;
				xd = yd;
				yd = yd * arr[j] + temp;
			}
			break;
		}
	}
	x = xd;
	y = yd;
}
/*
void extended_euclid(long long a, long long b, long long& x, long long& y) { //x,y는 배주계수
	long long temp_a = a, temp_b = b, gcd, xd = 0, yd = 0;
	long long arr[1000]; // 0 = a, 1 = b;
	for (int i = 0; true; i++) {
		gcd = temp_a % temp_b;
		if (gcd != 0) {
			arr[i] = -(temp_a / temp_b);
			temp_a = temp_b;
			temp_b = gcd;
		}
		else {
			xd = 1;
			yd = arr[i - 1];
			for (int j = i - 2; j >= 0; j--) {
				long long temp = xd;
				xd = yd;
				yd = yd * arr[j] + temp;
			}
			break;
		}
	}
	x = xd;
	y = yd;
}

void Eristo(int b) {//b까지
	bool che[MAX] = { 0, };
	che[1] = true;
	for (int i = 2; i <= b; i++) {
		if (che[i])
			continue;
		for (int j = i + i; j <= b; j += i) {
			if (che[i])
				continue;
			che[j] = true;
		}
		primes.insert(std::make_pair(i, 0));
	}
}
//밀러 라빈
template<class T>
T power(T a, T k, T n) {
	T res = 1;
	a %= n;
	while (k) {
		if (k % 2) res = (res * a) % n;
		k /= 2;
		a= (a * a) % n;
	}
	return res;
}
template<class T>
bool miller_rabin(T n, T a) {
	if (a % n == 0) return false;
	T k = n - 1;
	while (1) {
		Ttemp = power(a, k, n);
		if (temp == n - 1)
			return true;
		if (k % 2)
			return (temp == 1 || temp == n - 1);
		k /= 2;
	}
}
template<class T>
bool is_prime(T n) {
	for (int i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == i)
			return true;
		if (!miller_rabin(n, i))
			return false;
	}
	return true;
}


 long lucas( long k,  long n,  long m) {
	 long nAr;
	 long kAr;
	 long temp1 = k, temp2 = n, sum = 1;
	while (temp1 + temp2 != 0) {
		nAr = temp2 % m;
		temp2 /= m;
		kAr = temp1 % m;
		temp1 /= m;
		sum *= combination(kAr, nAr, m);
	}
	return sum;
}

 //뤼카의 정리

void dijkstra(int start, int end, int points[MAX], std::vector<std::pair<int, int>> line[MAX], int k) { // 시작 끝 저장공간
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

	std::priority_queue<int, std::vector<int>> p[MAX]; //경로 저장
	p[1].push(0);
	//DIkj
	pq.push(std::pair(0, start));
	while (!pq.empty()) {
		start = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (auto i = line[start].begin(); i != line[start].end(); i++) {
			int en = i->first; // 도착지
			int yn = cost + i->second;//가중치
			if (p[en].size() < k) {
				p[en].push(yn);
				pq.push(std::pair(yn, en));
			}
			else if (p[en].top() > yn) {
				p[en].pop();
				p[en].push(yn);
				pq.push(std::pair(yn, en));
			}
		}
	}
	for (int i = 1; i <= end; i++) {
		if (p[i].size() < k)
			printf("-1\n");
		else {
			printf("%d\n", p[i].top());
		}
	}
}

void floyd(int n, int graph[MAX][MAX]) {
	int pre[MAX][MAX];
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			pre[y][x] = graph[y][x];
	for (int i = 1; i <= n; i++) {
		int d[MAX][MAX] = { 0 };
		for (int y = 1; y <= n; y++)
			for (int x = 1; x <= n; x++) {
				int a = pre[y][x];
				d[y][x] = pre[y][i] + pre[i][x];
				if (d[y][x] > a)
					d[y][x] = a;
			}
		for (int y = 1; y <= n; y++)
			for (int x = 1; x <= n; x++)
				pre[y][x] = d[y][x];
	}
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			if (y == x)
				graph[y][x] = 1;
			else
				graph[y][x] = pre[y][x];
		}
}

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}
bool sort_compare(const int& a, const int& b) {
	if (a + 1 == b)
		return false;
	else if (a < b)
		return true;
	else
		return false;
};
bool st_sort(int a, int b) {
	return a < b;

};
void swap(std::vector<int>& data, int a, int b) {//a를 b로 교체
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}
void Sort(std::vector<int>& data) {
	int n = data.size();
	for (int i = 0; i < n - 1; i++) {
		if (data[i] + 1 == data[i + 1]) {
			int index = i + 1;
			int dindex = i;
			for (int j = i + 2; j < n; j++) {
				if (data[i + 1] < data[j]) {
					index = j;
					dindex = i + 1;
					break;
				}
			}
			swap(data, dindex, index);
			if (i > 0)i -= 2;
		}

	}
}
inline void swap(int& a, int& b) {
	int temp = a; a = b; b = temp;
}
long long triangle(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c) { //내적으로 삼각형 구하기 
	long long  S = (long long)a.first * b.second + b.first * c.second + c.first * a.second;
	S -= ((long long)b.first * a.second + c.first * b.second + a.first * c.second);
	return S;
}
//합집합 그래프
int gparent(int set[], int x) {
	if (set[x] == x)return x;
	return set[x] = gparent(set, set[x]);
}
void uparent(int set[], int a, int b) {
	a = gparent(set, a);
	b = gparent(set, b);
	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}
int fparent(int set[], int a, int b) {
	a = gparent(set, a);
	b = gparent(set, b);
	if (a == b)
		return 1;
	else
		return 0;
}

void topology(int N, int check[], std::list<int> line[MAX], std::list<int>& G) {//N은 정점수
	std::queue<int> Q;
	for (int i = 1; i <= N; i++)
		if (check[i] == 0) Q.push(i);

	while (!Q.empty())
	{
		int tp = Q.front();
		Q.pop();
		G.push_back(tp);
		auto x = line[tp].begin();
		for (int i = 0; i < line[tp].size(); i++)
		{
			int Next = *(x++);
			check[Next]--;
			if (check[Next] == 0) Q.push(Next);
		}
	}
}

double sandel(std::pair<double, double> a, std::pair<double, double> b) {
	return a.first * b.second + b.first * a.second;
}

int bsch(int arr[MAX], int len, int key) {
	int start = 1;
	int end = len;
	int mid;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start;
}
long long power(long long a, long long k, long long n) {
	long long res = 1;
	a %= n;
	while (k) {
		if (k % 2) res = (res * a) % n;
		k /= 2;
		a = (a * a) % n;
	}
	return res;
}
bool miller_rabin(long long n, long long a) {
	if (a % n == 0) return false;
	long long k = n - 1;
	while (1) {
		long long temp = power(a, k, n);
		if (temp == n - 1)
			return true;
		if (k % 2)
			return (temp == 1 || temp == n - 1);
		k /= 2;
	}
}
bool is_prime(long long n) {
	for (int i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}) {
		if (n == i)
			return true;
		if (!miller_rabin(n, i))
			return false;
	}
	return true;
}

*/