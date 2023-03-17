#include <iostream>

int main(){
    int n,k;
    std::cin >> n >> k;
    int array[n+1][n+1];
    if (n == k || n == 0) std::cout << 1 << "\n";
    else{
        for (int i = 0 ; i < n+1 ; i++){
        array[i][i] = 1;
        array[i][0] = 1;
        } for(int i = 2 ; i < n+1 ; i++){
            for (int j = 1 ; j < i ; j++){
                array[i][j] = array[i-1][j-1] + array[i-1][j];
            } 
        } std::cout << array[n][k] << "\n";
    }
}