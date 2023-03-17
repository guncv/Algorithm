#include <iostream>
#include <vector>
#include <limits.h>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp,sum = INT_MIN;
    std::vector<int> v;
    std::cin >> n;
    int array[n];

    for(int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        v.push_back(tmp);
    } for (int i = v.size()-1 ; i >= 0 ; i--){
        if (i+3 >= n) {
            array[i] = v[i];
            sum = std::max(sum,array[i]);
            continue;
        } int x = INT_MIN;
        x = std::max(x,array[i+3]);
        if (i+4 < n) x = std::max(x,array[i+4]);
        if (i+5 < n) x = std::max(x,array[i+5]);
        array[i] = x+v[i];
        sum = std::max(sum,array[i]);
    } std::cout << sum << "\n";
}