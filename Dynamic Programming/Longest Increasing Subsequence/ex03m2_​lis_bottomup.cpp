#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp;
    std::vector<int> v,v_sort;

    std::cin >> n;
    int lis[n+1][n+1];
    for (int i = 0 ; i <= n ; i++) {
        lis[0][i] = 0;
        lis[i][0] = 0;
        if (i > 0) {
            std::cin >> tmp;
            v.push_back(tmp);
            v_sort.push_back(tmp);
        }
    } sort(v_sort.begin(),v_sort.end());

    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            if (v[i-1] == v_sort[j-1]) {
                lis[i][j] = lis[i-1][j-1] + 1;
            } else {
                lis[i][j] = std::max(lis[i-1][j],lis[i][j-1]);
            }
        }
    } std::cout << lis[n][n] << "\n";
}