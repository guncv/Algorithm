#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int dp[1001][1001];

int longest_sub(std::vector<int> &v1, std::vector<int> &v2, int size1, int size2){
    if (size1 == 0 || size2 == 0) {
        return 0;
    } else if (dp[size1][size2] != 0){
        return dp[size1][size2];
    }
    else if (v1[size1 - 1] == v2[size2 - 1]) {
        return longest_sub(v1,v2,size1-1,size2-1) + 1;
    } else {
        int m = longest_sub(v1,v2,size1-1,size2);
        int n = longest_sub(v1,v2,size1,size2-1);
        if (m < n){
            dp[size1][size2] = n;
            return n;
        } dp[size1][size2] = m;
        return m;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n,tmp;
    std::vector<int> v,v_sort;

    std::cin >> n;
    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
        v_sort.push_back(tmp);
    } sort(v_sort.begin(),v_sort.end());
    std::cout << longest_sub(v,v_sort,v.size(),v_sort.size()) << "\n";
}