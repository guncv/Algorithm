#include <iostream>
#include <vector>
#include <math.h>

int dp[5000][5000];

int func(std::vector<int> &maki,int left,int right,int n) {
    if (n == 0){
        return 0;
    } else if (dp[left][right] != 0){
        return dp[left][right];
    } else {
        int tmp1 = std::max(maki[left],maki[right]);
        int tmp2 = std::max(maki[left],maki[left+1]);
        int tmp3 = std::max(maki[right-1],maki[right]);
        int sum;
        sum = std::max(func(maki,left+1,right-1,n-2)+tmp1,func(maki,left+2,right,n-2)+tmp2);
        sum = std::max(sum,func(maki,left,right-2,n-2)+tmp3);
        dp[left][right] = sum;
        return sum;
    }
}

int main() {
    int n,tmp;
    std::vector<int> maki;

    std::cin >> n;

    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        maki.push_back(tmp);
    } std::cout << func(maki,0,n-1,n) << "\n";
}