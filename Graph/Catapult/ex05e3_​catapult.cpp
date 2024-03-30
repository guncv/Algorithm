#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void tranpose_dfs(int a,std::vector<std::vector<int> > &adj,std::vector<bool> &used,std::vector<int> &ans) {
    for (int x : adj[a]) {
        if (!used[x]) {
            used[x] = true;
            ans[ans.size()-1]++;
            tranpose_dfs(x,adj,used,ans);
        }
    } 
}

void dfs(int a,std::stack<int> &s,std::vector<std::vector<int> > &adj,std::vector<bool> &used) {
    for (int x : adj[a]) {
        if (!used[x]) {
            used[x] = true;
            dfs(x,s,adj,used);
        }
    } s.push(a);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp;
    std::stack<int> s;
    
    std::cin >> n;
    std::vector<int> ans;
    std::vector<std::vector<int> > adj(n),tranpose_adj(n);
    std::vector<bool> used(n,false);
    for (int i = 0 ; i < n ; i++){
        std::cin >> m;
        while(m--){ 
            std::cin >> tmp;
            adj[i].push_back(tmp);
            tranpose_adj[tmp].push_back(i);
        }   
    } 

    for (int i = 0 ; i < n ; i++) {
        if (!used[i]) {
            used[i] = true;
            dfs(i,s,adj,used);
        }
    }

    std::vector<bool> ans_used(n,false);
    while(!s.empty()){
        int current = s.top();
        s.pop();
        if (!ans_used[current]) {
            ans_used[current] = true;
            ans.push_back(1);
            tranpose_dfs(current,tranpose_adj,ans_used,ans);
        }
    } std::sort(ans.begin(),ans.end());

    for (int x : ans) {
        std::cout << x << " ";
    } std::cout << "\n";
}