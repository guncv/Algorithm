#include <iostream>
#include <vector>
#include <math.h>

int dp[10001][3];

int bigger_billboard(std::vector<int> &billboard, int len, int count) {
    if (len == 0){
        return 0;
    } else if (dp[len][count] != 0) {
        return dp[len][count];
    } else if (count == 0) {
        dp[len][count] = std::max(bigger_billboard(billboard,len-1,count),bigger_billboard(billboard,len-1,2) + billboard[len-1]);
        return dp[len][count];
    } else {
        dp[len][count] = bigger_billboard(billboard,len-1,count-1);
        return dp[len][count];
    }
}

int main() {
    int n,tmp;
    std::vector<int> billboard;

    std::cin >> n;
    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        billboard.push_back(tmp);
    } std::cout << bigger_billboard(billboard,n,0) << "\n";  
}