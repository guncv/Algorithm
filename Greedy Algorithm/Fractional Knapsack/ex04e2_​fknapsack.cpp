#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    double w,n,tmp,sum = 0;
    std::vector<double> weight,price;
    std::vector<std::pair<double,std::pair<double,double> > > ratio;

    std::cin >> w >> n;
    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        price.push_back(tmp);
    } for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        weight.push_back(tmp);
    }

    for (int i = 0 ; i < n ; i++){
        ratio.push_back(std::make_pair(price[i]/weight[i],std::make_pair(price[i],weight[i])));
    } sort(ratio.begin(),ratio.end(), greater<std::pair<double,std::pair<double,double> > >());

    for (int i = 0 ; i < n ; i++){
        if (w > ratio[i].second.second) {
            sum += ratio[i].second.first;
            w -= ratio[i].second.second;
        } else {
            sum += ratio[i].second.first*(w/ratio[i].second.second); 
            w = 0;
            break;
        }
    } std::cout << std::fixed << std::setprecision(4) << sum << "\n"; 
}