#include <iostream>

int dp[31][31][31];

int barcode(int n, int len, int m, int k, int max_repeat,int repeat, int change, int number){
    if (repeat > max_repeat){
        max_repeat = repeat;
    } if (n > len){
        if (max_repeat > m || change > k) {
            return 0;
        } if (dp[len][repeat][change] != -1) {
            return dp[len][repeat][change];
        } else {
            dp[len][repeat][change] = barcode(n,len+1,m,k,max_repeat,repeat+1,change,number) + barcode(n,len+1,m,k,max_repeat,1,change+1,!number);
            return dp[len][repeat][change];      
        }
    } else {
        if (k != change || max_repeat > m) {
            return 0;
        } return 1;
    }
}

int main() {
    int n,m,k;
    std::cin >> n >> m >> k;

    for (int i = 0 ; i <= 30 ; i++){
        for (int j = 0 ; j <= 30 ; j++){
            for (int k = 0 ; k <= 30 ; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    std::cout << barcode(n,1,m,k,1,1,0,0) << "\n";
}