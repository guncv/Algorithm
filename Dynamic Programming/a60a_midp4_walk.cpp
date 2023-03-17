#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int row,col,tmp;
    std::cin >> row >> col;
    int array[row][col];
    int sum[row][col];

    for (int i = 0 ; i < row ; i++){
        for (int j = 0 ; j < col ; j++){
            std::cin >> tmp;
            array[i][j] = tmp;
        }
    } for (int i = 0 ; i < row ; i++){
        for (int j = 0 ; j < col ; j++){
            if (i == 0 && j == 0) sum[i][j] = array[i][j];
            else if (i == 0) sum[i][j] = array[i][j]+sum[i][j-1];
            else if (j == 0) sum[i][j] = array[i][j]+sum[i-1][j];
            else {
                sum[i][j] = std::max(std::max(array[i][j]+sum[i-1][j],array[i][j]+sum[i][j-1]),2*array[i][j]+sum[i-1][j-1]);
            }
        }
    } std::cout << sum[row-1][col-1] << "\n";
}