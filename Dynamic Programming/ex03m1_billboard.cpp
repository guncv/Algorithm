#include <iostream>
#include <vector>
#include <limits.h>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp,sum;
    std::vector<int> v;
    std::cin >> n;
    int array[n];

    for(int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        v.push_back(tmp);
    } for (int i = v.size()-1 ; i >= 0 ; i--){
        if (i+2 >= n) array[i] = v[i];
        else {
            sum = INT_MIN;
            for (int j = i+2 ; j < v.size() ; j++){
                sum = std::max(array[j],sum);
            } array[i] = v[i]+sum;
        }
    } sum = INT_MIN;
    for (int i = 0 ; i < n ; i++){
        sum = std::max(array[i],sum);
    } std::cout << sum << "\n";
}