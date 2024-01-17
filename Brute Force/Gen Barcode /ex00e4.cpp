#include <iostream>
#include <vector>

void combination(int n, int len ,int used,std::vector<int> &sol){
    if (len < n && used > 0) {
        sol[len] = 1;
        combination(n,len+1,used-1,sol);
        sol[len] = 0;
        combination(n,len+1,used,sol);
    } else {
        if (used == 0){
            for (int x : sol){
                std::cout << x;
            } std::cout << "\n";
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int a,b;
    std::cin >> a >> b;
    std::vector<int> sol(b); 
    combination(b,0,a,sol);
}