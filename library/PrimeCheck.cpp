//素数判定
bool IsPrime(int num){
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2){
		if (num % i == 0){
			return false;
		}
	}
	return true;
}

//素因数分解をリストで返す
vector<int> prime_factorization(int N) {
    vector<int> factors;
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }
    for (int i = 3; i * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    if (N > 1) {
        factors.push_back(N);
    }
    return factors;
}

//指数形式で返す素因数分解
vector<pair<int, int>> prime_factorization_exp(int N) {
    vector<pair<int, int>> factors;
    int count = 0;
    while (N % 2 == 0) {
        N /= 2;
        count++;
    }
    if (count > 0) factors.push_back({2, count});

    for (int i = 3; i * i <= N; i += 2) {
        count = 0;
        while (N % i == 0) {
            N /= i;
            count++;
        }
        if (count > 0) factors.push_back({i, count});
    }

    if (N > 1) {
        factors.push_back({N, 1});
    }
    return factors;
}

// エラトステネスの篩を使用してN以下の素数を求める関数
vector<int> sieve(int N) {
    vector<bool> is_prime(N + 1, true); // 素数判定用の配列
    vector<int> primes; // 素数を格納する配列

    is_prime[0] = is_prime[1] = false; // 0と1は素数ではない

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false; // iの倍数は素数ではない
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}