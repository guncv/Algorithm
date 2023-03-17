#include <iostream>
#include <vector>
#include <math.h>

void recur(std::vector<std::vector<int> > &v,int a,int b,int top,int bottom,int left,int right){
    if (a == 0) {
        v[top][left] = b;
        return;
    } int row = (top + bottom) / 2;
    int col = (left + right) / 2;
    recur(v,a-1,b,top,row,left,col);
    recur(v,a-1,b-1,top,row,col,right);
    recur(v,a-1,b+1,row,bottom,left,col);
    recur(v,a-1,b,row,bottom,col,right);
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int a,b;
    std::cin >> a >> b;
    std::vector<std::vector<int> > v;
    int x = pow(2,a);
    std::vector<int> tmp(x);

    while(x--) v.push_back(tmp);
    recur(v,a,b,0,v.size(),0,v.size());

    for (int i = 0 ; i < v.size() ; i++){
        for (int &x : v[i]) std::cout << x << " ";
        std::cout << "\n";
    }
}