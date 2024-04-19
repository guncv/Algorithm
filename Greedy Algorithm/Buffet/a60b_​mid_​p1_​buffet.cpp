#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int f,n,w,tmp,ans = 0;
    std::vector<int> food;
    std::vector<std::pair<int,int> > v;

    std::cin >> f >> w >> n;
    for (int i = 0 ; i < f ; i++){
        std::cin >> tmp;
        food.push_back(tmp);
    } std::sort(food.begin(),food.end());

    for (int i = 0 ; i < food.size() ; i++){
        
    }
    
    int pos = 0;
    for (int i = 0 ; i < food.size() ; i++){
        if (pos < food[i]) {
            ans++;
            pos = food[i] + 2*w;
        }
    } std::cout << ans << "\n";
}