#include <iostream>

int dp[46];

int fibonacci(int n){
    if (n == 0) {
        return 0;
    } if (n == 1){
        return 1;
    } else if (dp[n] != 0) {
        return dp[n];
    } else {
        int fibo = fibonacci(n-1) + fibonacci(n-2);
        dp[n] = fibo;
        return fibo;
    }
}

int main(){
    int n;
    std::cin >> n;
    std::cout << fibonacci(n) << "\n";
}