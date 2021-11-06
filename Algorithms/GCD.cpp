int gcd(int a, int  b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}