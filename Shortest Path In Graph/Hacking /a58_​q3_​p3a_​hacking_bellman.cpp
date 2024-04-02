#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    int n,m,k,tmp1,tmp2,ans = 0;

    std::cin >> n >> m >> k;
    std::vector<int> initial,distance(n,INT_MAX),cost;
    std::vector<std::pair<int,std::pair<int,int> > > adj;

    while(k--){
        std::cin >> tmp1;
        initial.push_back(tmp1);
    }

    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp1;
        cost.push_back(tmp1);
    }

    while(m--){
        std::cin >> tmp1 >> tmp2;
        adj.push_back(std::make_pair(cost[tmp2],std::make_pair(tmp1,tmp2)));
        adj.push_back(std::make_pair(cost[tmp1],std::make_pair(tmp2,tmp1)));
    }

    for (int x : initial){
        distance[x] = cost[x];
    }

    for (int i = 0 ; i < n ; i++){
        for (auto current : adj) {
            if (distance[current.second.first] == INT_MAX) continue;
            else {
                if (distance[current.second.first]+current.first < distance[current.second.second]) {
                    distance[current.second.second] = distance[current.second.first] + current.first;
                }
            }
        }
    }

    for (int x : distance) {
        ans = std::max(ans,x);
    } std::cout << ans << "\n";
}