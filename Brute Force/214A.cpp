#include <iostream>
#include <math.h>

int main(){
    int n,m;
    std::cin >> n >> m;
    int count = 0;
    int mx = m>=n ? m : n;
    int mn = m>=n ? n : m;

    for (int i = 0 ; i <= mn ; i++){
        int t =  mn-i;
        float x = sqrt(t);
        if (floor(x) != ceil(x)) continue;
        if (x + i*i == mx) count++;
    } std::cout << count;
}


