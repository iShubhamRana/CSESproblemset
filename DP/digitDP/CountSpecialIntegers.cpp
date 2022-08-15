https://leetcode.com/problems/count-special-integers/

class Solution {
public:
long long dp[10][2][(1 << 11)];

long long helper(string s , int index , bool tight, int mask = 0) {
    if (index == s.size()) {
        return 1;
    }

    if (dp[index][tight][mask] != -1) return dp[index][tight][mask];

    int ub = (tight) ? s[index] - '0' : 9;
    long long ans = 0;

    for (int dig = 0; dig <= ub; dig++) {
        if ((mask >> dig) & 1) continue;
        if (dig == 0) {
            if (mask) ans += helper(s, index + 1 , tight & (dig == ub) ,  mask | 1);
            else ans += helper(s, index + 1, tight & (dig == ub) , mask);
        } else {
            ans += helper(s, index + 1 , tight & (dig == ub) , mask | (1 << dig));
        }
    }

    return dp[index][tight][mask] = ans ;
}

int countSpecialNumbers(int n) {
    string s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return helper(s, 0, 1) - 1;
}
};
