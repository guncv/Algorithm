#include <iostream>
#include <vector>
#include <math.h>

int dp[501][501];

int walk_in_forest(std::vector<std::vector<int> > &forest, int row, int n, int column, int m) {
    if (row == 0 && column == 0){
        return walk_in_forest(forest,row+1,n,column+1,m) + forest[row+1][column+1];
    } else if (row == n && column == m) {
        return 0;
    } else if (dp[row][column] != 0){
        return dp[row][column];
    } else {
        int sum = 0; 
        if (row < n && column < n) {
            sum = std::max(sum,walk_in_forest(forest,row+1,n,column+1,m) + forest[row+1][column+1]*2);
            sum = std::max(sum,walk_in_forest(forest,row+1,n,column,m) + forest[row+1][column]);
            sum = std::max(sum,walk_in_forest(forest,row,n,column+1,m) + forest[row][column+1]);
        } else {
            if (row == n){
                sum = walk_in_forest(forest,row,n,column+1,m) + forest[row][column+1];
            } else {
                sum = walk_in_forest(forest,row+1,n,column,m) + forest[row+1][column];
            }
        } dp[row][column] = sum;
        return sum;
    }  
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp;
    std::cin >> n >> m;

    std::vector<std::vector<int> > forest;
    std::vector<int> tmp_v;

    for (int j  = 0 ; j <= m ; j++){
        tmp_v.push_back(0);
    } forest.push_back(tmp_v);
    tmp_v.clear();

    for (int i = 0 ; i < n ; i++) {
        tmp_v.push_back(0);
        for (int j = 0 ; j < m ; j++){
            std::cin >> tmp;
            tmp_v.push_back(tmp);
        } forest.push_back(tmp_v);
        tmp_v.clear();
    } 
    
    for (int i = 0 ; i <= n ; i++){
        for (int j = 0 ; j <= m ; j++){
            std::cout << forest[i][j] << " ";
        } std::cout << "\n";
    }
    // std::cout << walk_in_forest(forest,0,n,0,m) << "\n";
}