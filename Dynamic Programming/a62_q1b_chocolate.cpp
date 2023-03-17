#include <iostream>
#include <vector>

int array[10000] = {0};

int combi(std::vector<int> &v,int n){
    if (array[n-1] != 0) return array[n-1];
    int x = 0;
    for (int i = 0 ; i < v.size() ; i++){
        if (n - v[i] < 0) break;
        if (n - v[i] == 0) {
            x += 1;
            continue;
        } int t = n - v[i];
        x = (x + combi(v,t) % 1000003) % 1000003;
    } array[n-1] = x;
    return x;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::vector<int> v;
    int n,k,tmp;
    std::cin >> n >> k;

    while(k--){
        std::cin >> tmp;
        v.push_back(tmp);
    } std::cout << combi(v,n) << "\n";
}