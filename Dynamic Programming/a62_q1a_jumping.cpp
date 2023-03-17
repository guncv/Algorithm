#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    long long n,tmp;
    std::vector<long long> v,ma;
    std::cin >> n;

    for (long long i = 0 ; i < n ; i++){
        std::cin >> tmp;
        v.push_back(tmp);
    } ma.push_back(v[0]);
    ma.push_back(ma[0]+v[1]);
    for (long long i = 2 ; i < n ; i++){
        if (i == 2) ma.push_back(std::max(v[i]+ma[i-2],v[i]+ma[i-1]));
        else{
            ma.push_back(std::max(std::max(v[i]+ma[i-1],ma[i-2]+v[i]),v[i]+ma[i-3]));
        }
    } std::cout << ma[ma.size()-1] << "\n";
}