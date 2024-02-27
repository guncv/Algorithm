#include <iostream>

int dp[501][501];

int longest_common_sub(std::string x , std::string y, int size1 , int size2){
    if (size1 == 0 || size2 == 0) {
        return 0;
    } if (dp[size1][size2] != -1){
        return dp[size1][size2];
    } if (x[size1-1] == y[size2-1]) {
        dp[size1][size2] = longest_common_sub(x,y,size1-1,size2-1) + 1;
        return dp[size1][size2];
    } int m = longest_common_sub(x,y,size1-1,size2);
    int n = longest_common_sub(x,y,size1,size2-1);
    if (m < n){
        dp[size1][size2] = n;
        return n;
    } dp[size1][size2] = m;
    return m;
}

int main() {
    std::string x,y;
    std::cin >> x;
    std::cin >> y;

    for (int i = 0 ; i <= 500 ; i++){
        for (int j = 0 ; j <= 500 ; j++){
            dp[i][j] = -1;
        }
    } 
    std::cout << longest_common_sub(x,y,x.length(),y.length()) << "\n";
}