#include <iostream>

int array[1000][1000];
int sum[1000][1000];

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int row,col,ma = -1;
    std::string tmp;
    std::cin >> row >> col;

    for (int i = 0 ; i < row ; i++){
        std::cin >> tmp;
        for (int j = 0 ; j < col ; j++){
            array[i][j] = tmp[j] - '0';
            if (i == 0 || j == 0) sum[i][j] = array[i][j];
            ma = std::max(ma,sum[i][j]);
        }
    } for (int i = 1 ; i < row ; i++){
        for (int j = 1 ; j < col ; j++){
            if (array[i][j] == 0) sum[i][j] = 0;
            else{
                int x = std::min(std::min(sum[i][j-1],sum[i-1][j]),sum[i-1][j-1]) + 1;
                sum[i][j] = x;
                ma = std::max(ma,x);
            }
        }
    } std::cout << ma << "\n";
}