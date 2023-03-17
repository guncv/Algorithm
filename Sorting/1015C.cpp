#include <iostream>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    long long n,m,a,b,count = 0,size = 0;;
    std::priority_queue<int> p;
    std::cin >> n >> m;

    while(n--){
        std::cin >> a >> b;
        p.push(a-b);
        size += a;
    } if (size <= m) std::cout << 0 << "\n";
    else {
        while(!p.empty()){
            count++;
            size -= p.top();
            p.pop();
            if (size <= m){
                std::cout << count << "\n";
                break;
            }
        } if (size > m) std::cout << -1 << "\n";
    }
}