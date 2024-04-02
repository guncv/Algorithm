#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

int main () {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,k,tmp,tmp2,tmp3,target,ans;
    
    std::cin >> n >> m >> k;
    std::cin >> target;
    std::vector<std::vector<int> > shortest(n,std::vector<int>(n,INT_MAX));
    std::vector<int> start;
    
    while(k--) {
        std::cin >> tmp;
        start.push_back(tmp);
    }

    while(m--) {
        std::cin >> tmp >> tmp2 >> tmp3;
        shortest[tmp][tmp2] = tmp3; 
    } 

    for (int i = 0 ; i < n ; i++) {
        shortest[i][i] = 0;
    }

    for (int k = 0 ; k < n ; k++) {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (shortest[i][k] == INT_MAX || shortest[k][j] == INT_MAX) continue;
                shortest[i][j] = std::min(shortest[i][j],shortest[i][k]+shortest[k][j]);
            }
        }
    }

    for (int i = 0 ; i < shortest.size() ; i++){
        for (int x : shortest[i]) {
            std::cout << x << " ";
        } std::cout << "\n";
    }

    ans = shortest[start[0]][target];
    for (int i = 1 ; i < shortest.size() ; i++) {
        ans = std::min(ans,shortest[i][target]);
    } std::cout << ans << "\n";
}   