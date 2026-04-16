// mod. m での a の逆元 a^{-1} を計算する（拡張Euclid)
//ただし、modとaが互いに素であることが必要
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}