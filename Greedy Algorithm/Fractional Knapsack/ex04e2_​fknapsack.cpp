#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::vector<double> weight,price;
    std::vector<std::pair<double,std::pair<double,double> > > ratio;
    double w,n,tmp,ans = 0;

    std::cin >> w >> n;
    for (double i = 0 ; i < n ; i++){
        std::cin >> tmp;
        price.push_back(tmp);
    } for (double i = 0 ; i < n ; i++){
        std::cin >> tmp;
        weight.push_back(tmp);
    }

    for (double i = 0 ; i < weight.size() ; i++){
        ratio.push_back(std::make_pair(price[i]/weight[i],std::make_pair(price[i],weight[i])));
    } std::sort(ratio.begin(),ratio.end());

    for (int i = ratio.size() - 1 ; i >= 0 ; i--) {
        if (w <= 0) break;
        else {
            if (ratio[i].second.second <= w) {
                ans += ratio[i].second.first;
                w -= ratio[i].second.second;
            } else {
                ans += ratio[i].second.first*(w/ratio[i].second.second);
                w = 0;
            } 
        } 
    } std::cout << std::fixed << std::setprecision(4) << ans << "\n"; 
}