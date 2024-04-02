#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp,ans = 0;

    std::cin >> n;
    std::vector<std::vector<std::pair<int,int> > > adj(n+1);
    std::vector<int> cost(n+1,INT_MAX);
    std::priority_queue<std::pair<int,int> ,std::vector<std::pair<int,int> >, std::greater<std::pair<int,int> > > pq;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            std::cin >> tmp;
            if (tmp != -1 && i != j) {
                adj[i].push_back(std::make_pair(j,tmp));
            }
        }
    }

    pq.push(std::make_pair(0,1));
    cost[1] = 0;
    while (!pq.empty()) {
        std::pair<int,int> current = pq.top();
        pq.pop();
        for (std::pair<int,int> x : adj[current.second]) {
            if (cost[x.first] > cost[current.second] + x.second) {
                cost[x.first] = cost[current.second] + x.second;
                pq.push(std::make_pair(cost[x.first],x.first));
            }
        }
    } 

    for (auto &x : cost) {
        if (x == INT_MAX) {
            std::cout << "-1\n"; return 0;
        }
    }

    for (int i = 1 ; i < cost.size() ; i++) {
        if (cost[i] != INT_MAX) {
            ans = std::max(ans,cost[i]);
        }
    } std::cout << ans << "\n";
}