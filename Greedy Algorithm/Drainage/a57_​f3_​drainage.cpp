#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    std::vector<int> drainage;
    int n,l,tmp,ans = 0;

    std::cin >> n >> l;
    while(n--){
        std::cin >> tmp;
        drainage.push_back(tmp);
    } std::sort(drainage.begin(),drainage.end());

    int pos = 0;
    for (int i = 0 ; i < drainage.size() ; i++){
        if (pos < drainage[i]) {
            ans++;
            pos = drainage[i]+l-1;
        }
    } std::cout << ans << "\n";
}