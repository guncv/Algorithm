#include <iostream>
#include <vector>
#include <unordered_map>

void permu(int len,int n,std::vector<int> &v,std::vector<bool> &used,std::unordered_map<int,int> &m){
    if (len < n){
        for (int i = 0 ; i < n ; i++){
            if (!used[i] && m.find(i) != m.end() && used[m[i]]) break;
            if (!used[i]){
                used[i] = true;
                v[len] = i;
                permu(len+1,n,v,used,m);
                used[i] = false;
            }
        } 
    } else {
        for (int &x : v) std::cout << x << " ";
        std::cout << "\n"; }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::unordered_map<int,int> check;
    int n,m,a,b;
    std::cin >> n >> m;
    std::vector<int> v(n);
    std::vector<bool> used(n);

    while(m--){
        std::cin >> a >> b;
        check[a] = b;
    } permu(0,n,v,used,check);
}

