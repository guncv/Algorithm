#include <iostream>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,price,quality;
    std::priority_queue<std::pair<int,int> > p;
    bool b = false;
    std::cin >> n;

    while(n--){
        std::cin >> price >> quality;
        p.push(std::make_pair(price,quality));
    } int x = p.top().second;
    p.pop();

    while(!p.empty()){
        if (p.top().second > x){
            b = true;
            break;
        } x = p.top().second;
        p.pop();
    } if (b) std::cout << "Happy Alex" << "\n";
    else {std::cout << "Poor Alex" << "\n";}
}