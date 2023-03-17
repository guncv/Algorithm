#include <iostream>
#include <math.h>
#include <vector>

bool check(std::vector<int> &v ,int k){
    int count = 0;
    if (k == 1) return true;
    std::vector<int> v1;
    std::vector<int> v2;
    for (int i = 0 ; i < v.size()/2 ; i++){
        if (v[i] == 1) count++;
        if (v[i+v.size()/2] == 1) count--;
        v1.push_back(v[i]);
        v2.push_back(v[i+v.size()/2]);
    } if (count > 1 || count < -1) return false;
    return check(v1,k-1) && check(v2,k-1);
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,k,tmp;
    bool b = false;
    std::cin >> n >> k;

    while(n--){
        std::vector<int> v;
        size_t count = pow(2,k);
        while(count--){
            std::cin >> tmp;
            v.push_back(tmp);
        } if (check(v,k)){
            std::cout << "yes" << "\n";
            continue;
        } std::cout << "no" << "\n";
    }
}