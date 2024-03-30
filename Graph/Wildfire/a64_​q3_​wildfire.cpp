#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,k,tmp1,tmp2,sum = 0;

    std::cin >> n >> m >> k;
    std::vector<std::vector<int> > adj(n);
    std::vector<int> fire,beauti;
    while(n--){
        std::cin >> tmp1;
        beauti.push_back(tmp1);
        sum += tmp1;
    }

    while(k--){
        std::cin >> tmp1;
        fire.push_back(tmp1);
    }

    while(m--){
        std::cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
    }

    for (int x : fire) {
        if (beauti[x] != 0) {
            std::stack<int> s;
            sum -= beauti[x];
            beauti[x] = 0;
            s.push(x);

            while (!s.empty()) {
                int tmp = s.top();
                s.pop();
                for (int j : adj[tmp]) {
                    if (beauti[j] != 0) {
                        sum -= beauti[j];
                        beauti[j] = 0;
                        s.push(j);
                    }
                }
            }
        } std::cout << sum << " ";
    } std::cout << "\n";
}