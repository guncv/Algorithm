#include <iostream>
#include <vector>
#include <queue>

int main () {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp;

    std::cin >> n;
    std::vector<int> ans;
    std::vector<bool> used(n,false);
    std::vector<std::vector<int> > adj(n);
    std::vector<int> in_degree(n,0);
    std::queue<int> q;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> m;
        while(m--) {
            std::cin >> tmp;
            in_degree[i]++;
            adj[tmp].push_back(i);
        }
    }  

    for (int i = 0 ; i < n ; i++) {
        if (in_degree[i] == 0){
            q.push(i);
            used[i] = true;
        }
    } 

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        ans.push_back(current);
        for (int x : adj[current]) {
            if (!used[x]) {
                in_degree[x]--;
                if (in_degree[x] == 0) {
                    q.push(x);
                    used[x] = true;
                } 
            }
        }
    }
    
    for (int x : ans) {
        std::cout << x << " ";
    } std::cout << "\n";
}