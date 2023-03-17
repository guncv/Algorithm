#include <iostream>
#include <vector>

int array[100][100] = {0};

int mcm(int l,int r,std::vector<int> &v){
    if (l == r){
        return 0;
    } if (array[l][r] != 0) return array[l][r];
    int mi = 2147483647;
    for (int i = l ; i < r ; i++){
        int x = mcm(l,i,v) + mcm(i+1,r,v) + v[l]*v[i+1]*v[r+1];
        mi = std::min(mi,x);
    } array[l][r] = mi; 
    return mi;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp;
    std::vector<int> v;
    std::cin >> n;

    for(int i = 0 ; i <= n ; i++){
        std::cin >> tmp;
        v.push_back(tmp);
    } std::cout << mcm(0,n-1,v) << "\n";
}