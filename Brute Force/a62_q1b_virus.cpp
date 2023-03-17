#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

bool check(std::vector<int> &v ,int k,bool b){
    if (k == 1) {
        if (!b){
            if (v[0] == 0 && v[1] == 1) return true;
            return false;
        } if ((v[0] == 0 && v[1] == 1) || (v[0] == 1 && v[1] == 0)) return true;
        return false;
    }
    std::vector<int> v1;
    std::vector<int> v2;
    for (int i = 0 ; i < v.size()/2 ; i++){
        v1.push_back(v[i]);
        v2.push_back(v[i+v.size()/2]);
    } std::vector<int> v3 = v1;
    reverse(v1.begin(),v1.end());
    return (check(v1,k-1,true) || check(v3,k-1,true)) && check(v2,k-1,false);
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,k,tmp;
    std::cin >> n >> k;

    while(n--){
        std::vector<int> v;
        size_t count = pow(2,k);
        while(count--){
            std::cin >> tmp;
            v.push_back(tmp);
        } if (check(v,k,false)) {
            std::cout << "yes" << "\n";
            continue;
        } std::cout << "no" << "\n";
    }
}