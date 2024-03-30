#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,e,tmp1,tmp2,sum = 0;
    bool check;

    std::cin >> n >> e;
    std::vector<std::vector<int> > adj(n);
    std::vector<int> used(n,false),parent(n,-1);

    while(e--) {
        std::cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    for (int i = 0 ; i < n ; i++){
        if (!used[i]) {
            std::stack<int> s;
            check = true;
            used[i] = true;
            s.push(i);

            while(!s.empty()) {
                int tmp = s.top();
                s.pop();
                if (adj[tmp].size() > 2) check = false;
                for (int j : adj[tmp]) {
                    if (!used[j]) {
                        s.push(j);
                        used[j] = true;
                        parent[j] = tmp;
                    } else if (j != parent[tmp]) {
                        check = false;
                    }
                }
            }   
            if (check) sum++;
        }
    } std::cout << sum << "\n";
}