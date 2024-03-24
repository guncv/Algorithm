#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

int dp[100][100];

int matrix_chain_multi(std::vector<int> &matrix_v, int left, int right) {
    if (left < right) {
        if (dp[left][right] != 0) {
            return dp[left][right];
        }
        int sum = INT_MAX;
        for (int i = left ; i < right ; i++){
            sum = std::min(sum , matrix_chain_multi(matrix_v,left,i) + matrix_chain_multi(matrix_v,i+1,right) + matrix_v[left]*matrix_v[i+1]*matrix_v[right+1]);
        } dp[left][right] = sum;
        return sum;
    } else {
        return 0;
    }
}

int main(){
    int n,tmp;
    std::vector<int> matrix_v;    
    std::cin >> n;

    for (int i = 0 ; i <= n ; i++){
        std::cin >> tmp;
        matrix_v.push_back(tmp);
    } std::cout << matrix_chain_multi(matrix_v,0,n-1) << "\n";
}