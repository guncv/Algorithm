#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp,sum = 0;
    std::cin >> n >> m;
    std::vector<int> weight,price,product;
    int array[n+1][m+1];

    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        price.push_back(tmp);
    } for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        weight.push_back(tmp);
    } for (int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            std::cin >> tmp;
            array[i][j] = tmp;
        }
    } int col = m,row = n;

    for (int i = n-1 ; i >= 0 ; i--){
        if (weight[i] > col){
            row--;
            continue;
        } if (array[row-1][col-weight[i]]+price[i] >= array[row-1][col]){
            sum++;
            product.push_back(i+1);
            row--;
            col -= weight[i];
            continue;
        } row--;
    } std::cout << sum << "\n";
    for (int i = product.size()-1 ; i >= 0 ; i--) std::cout << product[i] << " ";
    std::cout << "\n";
}