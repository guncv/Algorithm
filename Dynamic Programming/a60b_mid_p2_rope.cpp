#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

int array[4000];

int divide(std::vector<int> &v,int n){
    if (array[n] != 0) return array[n];
    int sum = INT_MIN;
    for (int i = 0 ; i < v.size() ; i++){
        if (v[i] > n) break;
        if (v[i] == n) {
            sum = std::max(sum,1);
            continue;
        } sum = std::max(sum,divide(v,n-v[i])+1);
    } array[n] = sum;
    return sum;
}

int main(){
    int n,a,b,c;
    std::vector<int> v;
    std::cin >> n >> a >> b >> c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
    std::cout << divide(v,n) << "\n";
}