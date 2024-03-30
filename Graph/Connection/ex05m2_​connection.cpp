#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,e,k,tmp1,tmp2,count,max = 0;

    std::cin >> n >> e >> k;
    std::vector<std::vector<int> > adj(n);
    

    while(e--) {
        std::cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    } 
    
    for (int i = 0 ; i < n ; i++) {
        std::vector<int> used(n,-1);
        count = 0;
        used[i] = 0;
        std::queue<int> q;
        q.push(i);

        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            if (used[tmp] > k) continue;
            count++;
            for (int x : adj[tmp]) {
                if (used[x] == -1) {
                    q.push(x);
                    used[x] = used[tmp]+1; 
                }
            }
        }
        max = std::max(count,max);
    } std::cout << max << "\n";
}