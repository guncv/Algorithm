#include <iostream>

int array[101][101];
int dp[101][101];

int func(int level,int idx,int n,int sum){
    if (level == n) return 0;
    if (dp[level][idx] != 0) return dp[level][idx];
    sum += array[level][idx];
    int r1 = func(level+1,idx,n,0);
    int r2 = func(level+1,idx+1,n,0);
    sum += std::max(r1,r2);
    dp[level][idx] = sum;
    return sum;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp;
    std::cin >> n;

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j <= i ; j++){
            std::cin >> tmp;
            array[i][j] = tmp;
        } 
    } std::cout << func(0,0,n,0) << "\n";
}