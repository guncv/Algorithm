#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::vector<int> v;
    int n,tmp;
    std::cin >> n;

    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
    } sort(v.begin(),v.end());
    
    if (v.size()%2 != 0) std::cout << v[v.size()/2] << "\n";
    else {std::cout << v[v.size()/2-1] << "\n";}
}