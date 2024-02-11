#include <iostream>
#include <vector>
#include <math.h>

void recursive_matrix(std::vector<std::vector<int> > &matrix,int a,int b,int top,int bottom,int left,int right) {
    if (a == 0){
        matrix[top][left] = b;
        return;
    }
    int my = (top + bottom)/2;
    int mx = (left + right)/2;
    recursive_matrix(matrix,a-1,b,top,my,left,mx);
    recursive_matrix(matrix,a-1,b+1,my+1,bottom,left,mx);
    recursive_matrix(matrix,a-1,b-1,top,my,mx+1,right);
    recursive_matrix(matrix,a-1,b,my+1,bottom,mx+1,right);
}

int main() {
    int a,b;
    std::cin >> a >> b;
    std::vector<std::vector<int> > v;
    int x = pow(2,a);
    std::vector<int> tmp(x);

    while(x--) v.push_back(tmp);
    recursive_matrix(v,a,b,0,v.size()-1,0,v.size()-1);

    for (int i = 0 ; i < v.size() ; i++){
        for (int &x : v[i]) std::cout << x << " ";
        std::cout << "\n";
    }
}