#include <iostream>
#include <vector>

int dp[10000][2];

int advertise_billboard(std::vector<int> &billboard,int len,int n,bool adjen) {
    if (len == n) {
        return 0;
    } else {
        if (dp[len][adjen] != 0) {
            return dp[len][adjen];
        } else if (adjen) {
            dp[len][adjen] = advertise_billboard(billboard,len+1,n,!adjen);
            return dp[len][adjen];
        } else {
            dp[len][adjen] = std::max(advertise_billboard(billboard,len+1,n,!adjen)+billboard[len],advertise_billboard(billboard,len+1,n,adjen));
            return dp[len][adjen];        
        }
    }
}

int main() {
    int n,tmp;
    std::vector<int> billboard;
    std::cin >> n;

    while(n--){
        std::cin >> tmp;
        billboard.push_back(tmp);
    } std::cout << advertise_billboard(billboard,0,billboard.size(),false) << "\n";
}