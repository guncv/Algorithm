#include <iostream>
#include <vector>

int main(){
    int n,m,tmp;
    std::vector<std::vector<int> > forest;
    std::vector<int> tmp_v;

    std::cin >> n >> m;
    int dp[n][m];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            std::cin >> tmp;
            tmp_v.push_back(tmp);
        } forest.push_back(tmp_v);
        tmp_v.clear();
    }

    dp[0][0] = forest[0][0];
    for (int i = 1 ; i < n  ; i++){
        dp[i][0] = dp[i-1][0] + forest[i][0];
    } for (int i = 1 ; i < m ; i++){
        dp[0][i] = dp[0][i-1] + forest[0][i];
    }

    for (int i = 1 ; i < n ; i++){
        for (int j = 1 ; j < m ; j++){
            dp[i][j] = std::max(dp[i-1][j] + forest[i][j],dp[i][j-1] + forest[i][j]);
            dp[i][j] = std::max(dp[i][j],dp[i-1][j-1] + 2*forest[i][j]);
        }
    } std::cout << dp[n-1][m-1] << "\n";
}