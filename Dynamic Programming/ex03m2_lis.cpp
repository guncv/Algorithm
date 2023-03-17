#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp,idx;
    std::vector<int> v,seq;
    std::cin >> n;

    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        v.push_back(tmp);
    } seq.push_back(v[0]);
    for(int i = 1 ; i < n ; i++){
        if (v[i] > seq.back()) seq.push_back(v[i]);
        else {
            idx = lower_bound(seq.begin(),seq.end(),v[i])-seq.begin();
            seq[idx] = v[i];
        } 
    } std::cout << seq.size() << "\n";
}