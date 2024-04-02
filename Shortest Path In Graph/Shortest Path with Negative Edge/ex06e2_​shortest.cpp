#include <iostream>
#include <limits.h>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,e,s,tmp1,tmp2,tmp3;
    bool negative_cycle = false;
    
    std::cin >> n >> e >> s;
    std::vector<std::pair<std::pair<int,int>,int> > adj;
    std::vector<int> distance(n,INT_MAX);
    distance[s] = 0;

    while(e--){
        std::cin >> tmp1 >> tmp2 >> tmp3;
        adj.push_back(std::make_pair(std::make_pair(tmp1,tmp2),tmp3));
    }

    for (int i = 0 ; i < n ; i++){
        for (auto x : adj) {
            if (distance[x.first.first] == INT_MAX) continue;
            if (distance[x.first.first] + x.second < distance[x.first.second]){
                distance[x.first.second] = distance[x.first.first] + x.second;
            }
        }
    }   

    for (auto x : adj) {
        if (distance[x.first.first] + x.second < distance[x.first.second]){
            negative_cycle = true;
        }
    }

    if (negative_cycle) {
        std::cout << "-1" << "\n";
    } else {
        for (int x : distance) {
            std::cout << x << " ";
        } std::cout << "\n";
    }
}