#include <iostream>
#include <vector>
#include <stack>

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

        for (int i = 0 ; i < N && !check ; i++) {
            if (!(used[i])) {
                std::stack<int> s;
                s.push(i);
                used[i] = true;

                while (!s.empty() && !check) {
                    int tmp = s.top();
                    s.pop();
                    for (int j : adj[tmp]) {
                        if (!used[j]) {
                            s.push(j);
                            used[j] = true;
                            parent[j] = tmp;
                        } else if (j != parent[tmp]) {
                            check = true;
                            break;
                        }
                    } 
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