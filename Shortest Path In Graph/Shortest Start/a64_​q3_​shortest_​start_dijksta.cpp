#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <set>

int main () {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,k,tmp,tmp2,tmp3,target,ans;
    
    std::cin >> n >> m >> k;
    std::cin >> target;
    std::vector<std::vector<std::pair<int,int> > > adj(n);
    std::vector<int> cost(n,INT_MAX);
    std::set<std::pair<int,int> > s;
    
    while(k--) {
        std::cin >> tmp;
        s.insert(std::make_pair(0,tmp));
        cost[tmp] = 0;
    }

    while(m--) {
        std::cin >> tmp >> tmp2 >> tmp3;
        adj[tmp].push_back(std::make_pair(tmp2,tmp3));
    } 

    while(!s.empty()) { 
        std::pair<int,int> current = *s.begin();
        s.erase(s.begin());
        for (std::pair<int,int> x : adj[current.second]) {
            if (cost[x.first] > cost[current.second] + x.second) {
                if (s.find(std::make_pair(cost[x.first],x.first)) != s.end()) {
                    s.erase(std::make_pair(cost[x.first],x.first));
                }
                cost[x.first] = cost[current.second] + x.second;
                s.insert(std::make_pair(cost[x.first],x.first));
            }
        }
    } std::cout << cost[target] << "\n";
}   