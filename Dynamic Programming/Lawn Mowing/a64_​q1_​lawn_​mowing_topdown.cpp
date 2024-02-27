#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,k,tmp;
    std::vector<int> count_grass;
    std::cin >> n >> m >> k;

    std::cin >> tmp;
    count_grass.push_back(tmp);
    for (int i = 1 ; i < n ; i++){
        std::cin >> tmp;
        count_grass.push_back(count_grass[i-1] + tmp);
    }
}