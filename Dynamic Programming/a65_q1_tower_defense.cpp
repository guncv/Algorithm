#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,k,w,tmp,sum = 0;
    std::vector<int> tower;
    std::unordered_map<int,int> health;
    std::vector<std::pair<int,int> > monster;
    std::cin >> n >> m >> k >> w; 
    
    for (int i = 1 ; i <= m ; i++){
        std::cin >> tmp;
        monster.push_back(std::make_pair(tmp,i));
    } sort(monster.begin(),monster.end());

    for (int i = 1 ; i <= m ; i++){
        std::cin >> tmp;
        health[i] = tmp; 
    } 
    
    while(k--){
        std::cin >> tmp;
        for (int i = 0 ; i < monster.size() ; i++){
            if (monster[i].first >= tmp-w && monster[i].first <= tmp+w){
                if (health[monster[i].second] != 0) {
                    health[monster[i].second] -= 1;
                    break;
                }
            }
        }
    } for (auto it = health.begin() ; it != health.end() ; it++){
        sum += it->second;
    } std::cout << sum << "\n";
}