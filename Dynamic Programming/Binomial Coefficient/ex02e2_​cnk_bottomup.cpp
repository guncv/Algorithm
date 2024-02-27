#include <iostream>

int main(){
    int n,k;
    std::cin >> n >> k;

    if (k == 1 || n == k){
        std::cout << 1 << "\n";
    } else {    
        int binomial[n+1][n+1];

        for (int i = 1 ; i <= n ; i++){
            binomial[i][i] = 1;
            binomial[i][0] = 1;
        }

        for (int i = 2 ; i <= n ; i++){
            for (int j = 1 ; j < i && j <= k ; j++){
                binomial[i][j] = binomial[i-1][j-1] + binomial[i-1][j];
            }
        } 
        std::cout << binomial[n][k] << "\n";
    }
  
}