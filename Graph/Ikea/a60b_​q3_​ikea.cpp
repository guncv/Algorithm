#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,e,tmp1,tmp2;
    bool check = true;

    std::cin >> n >> e;
    std::vector<std::vector<int> > adj(n+1);
    std::vector<int> in_degree(n+1,0);

    while(e--){
        std::cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        in_degree[tmp2]++;
    }

    for (int i = 0 ; i < 5 ; i++){
        check = true;
        std::vector<int> tmp_degree = in_degree;
        for (int i = 0 ; i < n ; i++){
            std::cin >> tmp1;
            if (tmp_degree[tmp1] > 0) {
                check = false;
            } else {
                for (int x : adj[tmp1]) {
                    tmp_degree[x]--;
                }
            }
        }
        if (check) {
            std::cout << "SUCCESS" << "\n";
        } else {
            std::cout << "FAIL" << "\n";
        }
    }
}