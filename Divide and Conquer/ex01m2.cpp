#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp;
    std::vector<int> v;
    std::cin >> n;

    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
    } int count = 0;
    for (int i = 0 ; i < v.size() ; i++){
        for (int j = i+1 ; j < v.size() ; j++){
            if (v[i] > v[j]) count++;
        }
    } std::cout << count << "\n";
}