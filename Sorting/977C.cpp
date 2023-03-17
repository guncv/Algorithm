#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,k,tmp,m;
    std::cin >> n >> k;
    std::vector<int> v;

    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
    } sort(v.begin(),v.end());
    m = v[k-1];
    if (k == 0) {
        if (v[k] == 1) std::cout << -1 << "\n";
        else {std::cout << 1 << "\n";}
    }    
    else if (v.size() >= k+1 && v[k] == m) std::cout << -1 << "\n";
    else if (m < 1) {
        if (v.size() >= k+1 && (v[k] == 1 || v[k] == m)) std::cout << -1 << "\n";
            else {std::cout << 1 << "\n";}
    }
    else if (m > pow(10,9)) std::cout << -1 << "\n";
    else {std::cout << m << "\n";}
    
}