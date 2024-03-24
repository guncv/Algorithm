#include <iostream>
#include <vector>

int dp[200001][200001][1];

int two_side(std::vector<int> &left,std::vector<int> &right,int count,int side, int len,int w,int k) {
    if (len == 0 || k == 0){
        return 0;
    } else if (dp[len][count][side] != 0) {
        return dp[len][count][side];
    } else {
        if (count == 0) {
            if (side == 0) {
                dp[len][count][side] = std::max(two_side(left,right,count-1,side,len-1,w,k),two_side(left,right,w,!side,len-1,w,k-1) + left[len-1]);
                return dp[len][count][side];
            }
            else {
                dp[len][count][side] = std::max(two_side(left,right,count-1,side,len-1,w,k),two_side(left,right,w,!side,len-1,w,k-1) + right[len-1]);
                return dp[len][count][side];
            }  
        } else {
            dp[len][count][side] = two_side(left,right,count-1,side,len-1,w,k);
            return dp[len][count][side];
        }         
    }
}

int main () {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,w,k,tmp;
    std::vector<int> left_side,right_side;

    std::cin >> n >> w >> k;
    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        left_side.push_back(tmp);
    } for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        right_side.push_back(tmp);
    } 
    std::cout << std::max(two_side(left_side,right_side,0,0,n,w,k),two_side(left_side,right_side,0,1,n,w,k)) << "\n";
}