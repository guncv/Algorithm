#include <iostream>

int dp[501][501];

int divide_rock(int n, int k, int item, int divide){
    if (item == divide || divide == 1) {
        return 1;
    } else if (dp[item][divide] != 0) {
        return dp[item][divide];
    } else {
        dp[item][divide] = (divide_rock(n,k,item-1,divide)*divide + 
            divide_rock(n,k,item-1,divide-1)) % 1997;
        return dp[item][divide];
    }
}

int main(){
    int n,k;

    std::cin >> n >> k;
    std::cout << divide_rock(n,k,n,k) << "\n";
}