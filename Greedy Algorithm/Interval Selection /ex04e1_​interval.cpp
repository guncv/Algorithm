#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n,tmp,last = -1,count = 0;
    std::vector<int> start,stop;
    std::vector<std::pair<int,int> > time;

    std::cin >> n;
    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        start.push_back(tmp);
    } for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        stop.push_back(tmp);
    } for (int i = 0 ; i < n ; i++){
        time.push_back(std::make_pair(stop[i],start[i]));
    } std::sort(time.begin(),time.end());

    for (int i = 0 ; i < n ; i++) {
        if (time[i].second >= last) {
            last = time[i].first;
            count++;
        } 
    } std::cout << count << "\n";
}