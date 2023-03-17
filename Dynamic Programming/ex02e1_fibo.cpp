#include <iostream>
#include <unordered_map>

int fibo(int n,std::unordered_map<int,int> &m){
    if (n == 1 || n == 0){
        return n;
    } if (m.find(n) != m.end()) return m[n]; 
    int x = fibo(n-1,m) + fibo(n-2,m);
    m[n] = x;
    return x; 
}

int main(){
    int n;
    std::unordered_map<int,int> m;
    std::cin >> n;
    std::cout << fibo(n,m) << "\n";
}