#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,k,w,tmp,tmp1,tmp2,sum;
    std::cin >> n >> m >> k >> w;
    std::vector<int> mon_ind;
    std::unordered_map<int,int> mon_hp;

    for (int i = 0 ; i < m ; i++){
        std::cin >> tmp;
        mon_ind.push_back(tmp);
    } 

    for (int j = 0 ; j < m ; j++){
        std::cin >> tmp;
        tmp1 = mon_ind[j];
        if (mon_hp.find(tmp1) != mon_hp.end()){
            mon_hp[tmp1] += tmp;
        }else {
            mon_hp[tmp1] = tmp;
        }
    } std::sort(mon_ind.begin(),mon_ind.end());

    while(k--){
        std::cin >> tmp;
        tmp1 = std::lower_bound(mon_ind.begin(),mon_ind.end(),tmp - w) - mon_ind.begin();
        tmp2 = std::upper_bound(mon_ind.begin(),mon_ind.end(),tmp + w) - mon_ind.begin();
        for (int i = tmp1 ; i < tmp2 ; i++){
            if (mon_hp[mon_ind[i]] != 0){
                mon_hp[mon_ind[i]] -= 1;
                break;
            }
        }
    }

    for (auto it = mon_hp.begin() ; it != mon_hp.end() ; it++){
        sum += it->second;
    } std::cout << sum << "\n";
}