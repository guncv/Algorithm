#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,k,m,tmp,index;
    std::vector<int> delicious,sum;
    
    std::cin >> n >> k >> m;
    sum.push_back(0);
    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        delicious.push_back(tmp-m);
        sum.push_back(sum[i]+tmp-m);
    } 

    while(k--){
        std::cin >> index >> tmp;
        std::cout << lower_bound(sum.begin()+index,sum.end(),tmp+sum[index-1]) - sum.begin() << "\n";
    }
}