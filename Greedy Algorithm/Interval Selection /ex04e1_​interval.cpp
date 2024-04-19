#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::vector<int> start,stop;
    std::vector<std::pair<int,int> > time;
    int n,tmp,last = -1,ans = 0;

    std::cin >> n;
    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        start.push_back(tmp);
    } for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        stop.push_back(tmp);
    }

    for (int i = 0 ; i < n ; i++){
        time.push_back(std::make_pair(stop[i],start[i]));
    } std::sort(time.begin(),time.end());

    for (std::pair<int,int> x : time) {
        if (x.second >= last) {
            last = x.first;
            ans++;
        } 
    } std::cout << ans << "\n";
}