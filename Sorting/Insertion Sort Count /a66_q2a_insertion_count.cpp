#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp,count;
    std::vector<int> v;

    std::cin >> n >> m;
    for (int i = 0 ; i < n ;i++){
        std::cin >> tmp;
        v.push_back(tmp);
    } 

    while(m--){
        std::cin >> tmp;
        count = 0;
        for (int i = 0 ; i < n ; i++) {
            if (v[i] > tmp) count++;
            if (v[i] == tmp) break;
        } std::cout << count << "\n";
    }
}