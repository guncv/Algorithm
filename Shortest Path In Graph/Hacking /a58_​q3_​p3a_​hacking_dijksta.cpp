#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,k,tmp1,tmp2,ans = 0;

    std::cin >> n >> m >> k;
    std::vector<std::vector<std::pair<int,int> > > adj(n);
    std::vector<int> cost(n,INT_MAX),weight,initial;
    std::set<std::pair<int,int> > s;

    while(k--) {
        std::cin >> tmp1;
        initial.push_back(tmp1);
    } 

    for (int i = 0 ; i < n ; i++) {
        std::cin >> tmp1;
        weight.push_back(tmp1);
    } 

    while(m--){
        std::cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(std::make_pair(tmp2,weight[tmp2]));
        adj[tmp2].push_back(std::make_pair(tmp1,weight[tmp1]));
    }

    for (int x : initial) {
        cost[x] = weight[x];
        s.insert(std::make_pair(cost[x],x));
    }

    while(!s.empty()) {
        std::pair<int,int> current = *s.begin();
        s.erase(s.begin());
        for (std::pair<int,int> x : adj[current.second]) {
            if (current.first + x.second < cost[x.first]) {
                cost[x.first] = current.first + x.second;
                s.insert(std::make_pair(cost[x.first],x.first));
            } 
        }
    } 

    for (int x : cost) {
        ans = std::max(ans,x);
    } std::cout << ans << "\n";
}