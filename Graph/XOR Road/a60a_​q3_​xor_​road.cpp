#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

long long find_set(long long x,std::vector<long long> &p){
    while (p[x] != -1) {
        x = p[x];
    } return x;
}

void union_set(long long x,long long y,std::vector<long long> &p){
    long long s1 = find_set(x,p);
    long long s2 = find_set(y,p);
    p[s1] = s2;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    long long n,tmp,ans = 0;

    std::cin >> n;
    std::vector<long long> value,p(n,-1);
    std::priority_queue<std::pair<long long,std::pair<long long,long long> > > road;
    for (long long i = 0 ; i < n ; i++){
        std::cin >> tmp;
        value.push_back(tmp);
    }

    for (long long i = 0 ; i < value.size() ; i++) {
        for (long long j = i+1 ; j < value.size() ; j++){
            road.push(std::make_pair(value[i]^value[j],std::make_pair(i,j)));
        }
    }
    
    while (!road.empty()) {
        auto current = road.top();
        road.pop();
        if (find_set(current.second.first,p) != find_set(current.second.second,p)) {
            ans += current.first;
            union_set(current.second.first,current.second.second,p);
        }
    } std::cout << ans << "\n";
}