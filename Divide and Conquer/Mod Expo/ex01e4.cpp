#include <iostream>

int mod_expo(int x, int n, int k) {
    if (n == 1){
        return x%k;
    } else {
        if (n%2 == 0){
            int r1 = mod_expo(x,n/2,k)%k;
            int r2 = mod_expo(x,n/2,k)%k;
            return (r1*r2)%k;
        } else {
            int r1 = mod_expo(x,n/2,k)%k;
            int r2 = mod_expo(x,n/2,k)%k;
            return (((r1*r2)%k)*(x%k))%k;
        }
    }
}

int main() {
    int x,n,k;
    std::cin >> x >> n >> k;
    std::cout << mod_expo(x,n,k) << "\n";
}