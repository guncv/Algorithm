#include <iostream>
#include <vector>

int ans = 0;

void dfs(int a, std::vector<std::vector<int> > &adj,std::vector<int> &used,int parent) {
    if (ans != 0) return;
    for (int j : adj[a]) {
        if (used[j] == -1) {
            used[j] = used[a] + 1;
            dfs(j,adj,used,a);
        } else if (j != parent) {
            ans = used[a] - used[j] + 1;
            if (ans < 0) return;
            std::cout << ans << "\n";
            return;
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,x,y;
    std::cin >> n;
    std::vector<std::vector<int> > adj(n);
    std::vector<int> used(n,-1); 

    for (int i = 0 ; i < n ; i++) {
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 

    for (int i = 0 ; i < n && ans == 0 ; i++) {
        if (used[i] == -1) {
            used[i] = 0;
            dfs(i,adj,used,-1);
        }
    }
}