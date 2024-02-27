#include <iostream>

int dp[31][31];

int binomial(int n, int k){
    if (n == k || k == 0) {
        return 1;
    } else if (dp[n][k] != 0) {
        return dp[n][k];
    } else {
        int sum = binomial(n-1,k-1) + binomial(n-1,k);
        dp[n][k] = sum;
        return sum;
    }
}

int main(){
    int n,k;
    std::cin >> n >> k;
    std::cout << binomial(n,k) << "\n";
}