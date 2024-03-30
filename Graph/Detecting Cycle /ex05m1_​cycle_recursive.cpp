#include <iostream>
#include <vector>

bool dfs_cycle_detect(int a,std::vector<std::vector<int> > &adj,std::vector<bool> &used,int parent) {
    used[a] = true;
    for (int j : adj[a]) {
        if (!used[j]) {
            if (dfs_cycle_detect(j,adj,used,a)) return true;
        } else if (j != parent) {
            return true;
        }
    } return false;
}

int main () {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int T,N,E,tmp1,tmp2;
    std::cin >> T;

    while(T--){
        std::cin >> N >> E;
        std::vector<bool> used(N,false);
        std::vector<int> parent(N,-1);
        std::vector<std::vector<int> > adj(N);
        bool check = false;

        while (E--) {
            std::cin >> tmp1 >> tmp2;
            adj[tmp1].push_back(tmp2);
            adj[tmp2].push_back(tmp1);
        }

        for (int i = 0 ; i < N && !check ; i++){
            if (!used[i]) {
                if (dfs_cycle_detect(i,adj,used,-1)) {
                    check = true;
                }
            } 
        }

        if (check) {
            std::cout << "YES" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
    }  
}