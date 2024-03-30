#include <iostream>
#include <vector>

void dfs(int a,std::vector<std::vector<int> > &adj,std::vector<int> &used) {
    for (int x : adj[a]) {
        if (!used[x]) {
            used[x] = true;
            dfs(x,adj,used);
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int v,e,tmp1,tmp2,count = 0;
    std::cin >> v >> e;
    std::vector<std::vector<int> > adj(v+1); 
    std::vector<int> used(v+1,false);

    while(e--){
        std::cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    for (int i = 1 ; i <= v ; i++){
        if (!used[i]) {
            count++;
            dfs(i,adj,used);
        }
    } std::cout << count << "\n";
}