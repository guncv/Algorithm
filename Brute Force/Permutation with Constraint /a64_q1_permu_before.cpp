#include <iostream>
#include <vector>
#include <unordered_map>

void permutation(int n,std::vector<bool> &used,std::vector<int> &v,int len,std::unordered_map<int,int> &ref){
    if (len < n){
        for (int i = 0 ; i < n ; i++){
            if (!used[i]){
                if (ref.find(i) != ref.end() && !used[ref[i]]) {
                    continue;
                }
                used[i] = true;
                v[len] = i;
                permutation(n,used,v,len+1,ref);
                used[i] = false;
            }
        }
    } else {
        for (int i = 0 ; i < n ; i++){
            std::cout << v[i] << " ";
        } std::cout << "\n";
    }
}

int main (){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp,tmp1;
    std::cin >> n >> m;
    std::vector<bool> used(n);
    std::vector<int> v(n); 
    std::unordered_map<int,int> ref;

    while(m--){
        std::cin >> tmp >> tmp1;
        ref[tmp1] = tmp;
    }
    permutation(n,used,v,0,ref);
}