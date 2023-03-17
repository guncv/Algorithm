#include <iostream>

int mod_exponent(int a,int n,int k){
    if (n == 1) return a%k;
    if (n%2 == 0){
        int tmp = mod_exponent(a,n/2,k);
        return (tmp*tmp)%k;
    } int tmp = mod_exponent(a,n/2,k);
    int x = a%k;
    return ((tmp*tmp)%k * x)%k;
}

int main(){
    int X,N,K;
    std::cin >> X >> N >> K;
    std::cout << mod_exponent(X,N,K) << "\n";
}