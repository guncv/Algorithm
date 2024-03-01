#include <iostream>
#include <vector>

int dp[10001];

int divide_chocolate(std::vector<int> &set, int left){
    if (left < 0) {
        return 0;
    } else if (left == 0) {
        return 1;
    } else if (dp[left] != -1){
        return dp[left];
    } else {
        int sum = 0;
        for (int i = 0 ; i < set.size() ; i++){
            sum += divide_chocolate(set,left-set[i]) % 1000003;
        } sum %= 1000003;
        dp[left] = sum;
        return sum;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,k,tmp;
    std::vector<int> set;
    for (int i = 0 ; i <= 1000; i++){
        dp[i] = -1;
    }

    std::cin >> n >> k;
    while(k--){
        std::cin >> tmp;
        set.push_back(tmp);
    } std::cout << divide_chocolate(set,n) << "\n";
}