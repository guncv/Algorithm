#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp,t1,t2,t3,min = INT_MAX;
    
    std::cin >> n;
    std::vector<std::vector<int> > adj(n+1);
    std::vector<int> used_t1(n+1,-1),used_t2(n+1,-1),used_t3(n+1,-1);
    std::queue<int> bfs;
    std::cin >> t1 >> t2 >> t3;

    for (int i = 1 ; i <= n ; i++) {
        std::cin >> m;
        while(m--){
            std::cin >> tmp;
            adj[i].push_back(tmp);
        }
    }
    
    bfs.push(t1);
    used_t1[t1] = 0;
    while(!bfs.empty()){
        int current = bfs.front();
        bfs.pop();
        for (int x : adj[current]) {
            if (used_t1[x] == -1){
                used_t1[x] = used_t1[current] + 1;
                bfs.push(x);
            } else if (used_t1[current] + 1 < used_t1[x]) {
                used_t1[x] = used_t1[current] + 1;
                bfs.push(x);
            }
        }
    }

    bfs.push(t3);
    used_t3[t3] = 0;
    while(!bfs.empty()){
        int current = bfs.front();
        bfs.pop();
        for (int x : adj[current]) {
            if (used_t3[x] == -1){
                used_t3[x] = used_t3[current] + 1;
                bfs.push(x);
            } else if (used_t3[current] + 1 < used_t3[x]) {
                used_t3[x] = used_t3[current] + 1;
                bfs.push(x);
            }
        }
    }

    bfs.push(t2);
    used_t2[t2] = 0;
    while(!bfs.empty()){
        int current = bfs.front();
        bfs.pop();
        for (int x : adj[current]) {
            if (used_t2[x] == -1){
                used_t2[x] = used_t2[current] + 1;
                bfs.push(x);
            } else if (used_t2[current] + 1 < used_t2[x]) {
                used_t2[x] = used_t2[current] + 1;
                bfs.push(x);
            }
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        if (used_t1[i] == -1 || used_t2[i] == -1 || used_t3[i] == -1) continue;
        else {
            int max = std::max(used_t1[i],used_t2[i]);
            max = std::max(max,used_t3[i]);
            min = std::min(min,max);
        }
    } std::cout << min << "\n";
}