#include <iostream>

int main() {
    int n,k;

    std::cin >> n >> k;
    int divide_rock[n+1][k+1];

    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= k ; j++){
            divide_rock[i][j] = 0;
        }
    }

    for (int i = 1 ; i <= n ; i++){
        divide_rock[i][1] = 1;
    } for (int j = 1 ; j <= k ; j++){
        divide_rock[j][j] = 1;
    } 

    for (int i = 2 ; i <= n ; i++){
        for (int j = 2 ; j <= k ; j++){
            divide_rock[i][j] = (divide_rock[i-1][j]*j + divide_rock[i-1][j-1]) % 1997;
        }
    } 
    
    std::cout << divide_rock[n][k] << "\n";
}