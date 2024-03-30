#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

int main () {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,tmp,ans;
    std::cin >> n;

    std::vector<std::vector<int> > adj(n, std::vector<int>(n,-1));
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int,int> > > minHeap;
    std::vector<int> cost(n,INT_MAX),used(n,-1);

    for (int i = 0 ; i < n-1 ; i++){
        for (int j = i+1 ; j < n ; j++){
            std::cin >> tmp;
            adj[i][j] = tmp;
            adj[j][i] = tmp;
        }
    }

    minHeap.push(std::make_pair(0,0));
    cost[0] = 0;
    while(!minHeap.empty()){
        std::pair<int,int> current = minHeap.top();
        minHeap.pop();
        if (used[current.second] != -1) continue;
        ans += current.first;
        used[current.second] = 0;
        for (int i = 0 ; i < adj[current.second].size() ; i++){
            if (adj[current.second][i] != -1 && adj[current.second][i] < cost[i]) {
                cost[i] = adj[current.second][i];
                minHeap.push(std::make_pair(cost[i],i));
            }
        }
    } std::cout << ans << "\n";
} 