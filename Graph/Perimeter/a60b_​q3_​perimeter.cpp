#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,e,k,tmp1,tmp2,count = 0;

    std::cin >> n >> e >> k;
    std::vector<std::vector<int> > adj(n+1);
    std::vector<int> used(n+1,-1);
    std::queue<int> bfs;

    while(e--) {
        std::cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    bfs.push(0);
    used[0] = 0;
    while(!bfs.empty()) {
        int current = bfs.front();
        bfs.pop();
        for (int x : adj[current]){
            if (used[x] == -1) {
                used[x] = used[current] + 1;
                if (used[x] == k) {
                    count++;
                } else {
                    bfs.push(x);
                }
            } 
        }
    } std::cout << count << "\n";
}