#include <iostream>
#include <vector>

void consecutive(int n,int len,int k,int count,bool b,std::vector<int> &sol){
    if (count == k){
        b = true;
    } if (len < n){
        sol[len] = 0;
        consecutive(n,len+1,k,0,b,sol);
        sol[len] = 1;
        consecutive(n,len+1,k,count+1,b,sol);
    } else {
        if (b){
            for (int i = 0 ; i < n ; i++){
                std::cout << sol[i];
            } std::cout << "\n";
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,k;
    std::cin >> n >> k;
    std::vector<int> sol(n);
    consecutive(n,0,k,0,false,sol);
}