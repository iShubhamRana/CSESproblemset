vector<int> fac;
vector<int> ifac;

int binExp(int base, int exp) {
    base %= MOD;
    int res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (int) ((long long) res * base % MOD);
        }
        base = (int) ((long long) base * base % MOD);
        exp >>= 1;
    }
    return res;
}

void precompute(int n) {
    fac.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = (int) ((long long) i * fac[i - 1] % MOD);
    }

    ifac.resize(n + 1);
    for (int i = 0; i < fac.size(); i++) {
        ifac[i] = binExp(fac[i], MOD - 2);
    }
    return;
}

int nCr(int n, int r) {
    if ((n < 0) || (r < 0) || (r > n)) {
        return 0;
    }
    return (int) ((long long) fac[n] * ifac[r] % MOD * ifac[n - r] % MOD);
}
