#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q,tmp1,tmp2,i;
    std::cin >> n >> q;
    std::vector<std::pair<int,int> >  v;
    std::vector<int> idx;

    while(n--){
        std::cin >> tmp1 >> tmp2;
        v.push_back(std::make_pair(tmp1,tmp2));
    } std::sort(v.begin(),v.end());

    idx.push_back(v[0].second);
    for (int i = 1 ; i < v.size() ; i++){
        idx.push_back(v[i].second+idx[i-1]);
    }

    while(q--){
        std::cin >> tmp1;
        auto it = std::lower_bound(idx.begin(),idx.end(),tmp1);
        std::cout << v[it-idx.begin()].first << "\n";
    }

}