#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int fibo[n+1];
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2 ; i <= n ; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    std::cout << fibo[n] << "\n";
}