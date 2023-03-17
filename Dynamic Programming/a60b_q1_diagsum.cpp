#include <iostream>
#include <limits.h>


int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp,sum;
    std::cin >> n;
    int array[n][n];

    int m = INT_MIN;

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            std::cin >> tmp;
            array[i][j] = tmp;
        }
    } for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            sum = 0;
            m = std::max(array[i][j],m);
            sum += array[i][j];
            for (int k = 1 ; k < n ; k++){
                if (i+k >= n || j+k >= n) break;
                sum += array[i+k][j+k];
                m = std::max(sum,m);
                } 
        }
    } std::cout << m << "\n";
}