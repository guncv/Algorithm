#include <iostream>
#include <vector>

void combi(int len , int n , std::vector<int> &v , int count , int k , bool b){
    if (count == k) b = true;
    if (len < n){
        v[len] = 0;
        combi(len+1,n,v,0,k,b);
        v[len] = 1;
        combi(len+1,n,v,count+1,k,b);
    } else {
        if (b) {
            for (int &x : v) std::cout << x;
            std::cout << "\n";
        }
    }
}

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    combi(0,n,v,0,k,false);
}