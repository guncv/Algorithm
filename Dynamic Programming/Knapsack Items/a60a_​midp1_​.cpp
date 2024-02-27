#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp;
    std::vector<int> price,weight,v;

    std::cin >> n >> m;
    int knapsack[n+1][m+1];
    for (int i = 0 ; i < n; i++){
        std::cin >> tmp;
        price.push_back(tmp);
    } for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        weight.push_back(tmp);
    }

    for (int i = 0 ;i <= n ; i++){
        for (int j = 0 ; j <= m ; j++){
            std::cin >> tmp;
            knapsack[i][j] = tmp;
        }
    }

    while (n != 0 && m != 0){
        if (m >= weight[n-1]){
            if (knapsack[n-1][m-weight[n-1]]+price[n-1] == knapsack[n][m]){
                v.push_back(n);
                m -= weight[n-1];
                n--;
            } else {
                n--;
            }
        } else {
            n--;
        }
    } 

    std::cout << v.size() << "\n";
    for (int i = v.size()-1 ; i >= 0 ; i--){
        std::cout << v[i] << " ";
    } std::cout << "\n";
}
