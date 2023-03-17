#include <iostream>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp,count = 0;
    std::priority_queue<int> p;
    std::cin >> n;
    
    while(n--){
        std::cin >> tmp;
        p.push(tmp);
    }

    while(!p.empty()){
        int x = p.top();
        p.pop();
        count += x-p.top();
        p.pop();
    } std::cout << count << "\n";
}