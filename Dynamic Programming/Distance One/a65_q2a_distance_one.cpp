#include <iostream>

int dp[5000][5000];

int distance_one(int len, int n, int count, int k) {
    if (len == n) {
        return 1;
    } else if (dp[len][count] != -1){
        return dp[len][count];
    } else {
        if (count == 1) {
            dp[len][count] = ((distance_one(len+1,n,k,k)%100000007) + (distance_one(len+1,n,count,k)%100000007)) %100000007;
            return dp[len][count];
        } else {
            dp[len][count] = distance_one(len+1,n,count-1,k);
            return dp[len][count];
        }
    }
}

int main() {
    int n,k;
    std::cin >> n >> k;
    for (int i = 0 ; i < 5000 ; i++){
        for (int j = 0 ; j < 5000 ; j++){
            dp[i][j] = -1;
        }
    } std::cout << distance_one(0,n,1,k) << "\n";
}