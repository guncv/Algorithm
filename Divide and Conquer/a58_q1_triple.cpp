#include <iostream>
#include <vector>
#include <unordered_map>

bool triple(std::vector<long long> &v,std::unordered_map<long long,int> &m,long long tmp){
    long long x;
    for (int i = 0 ; i < v.size() ; i++){
        for (int j = i+1 ; j < v.size() ; j++){
            x = tmp - (v[i] + v[j]);
            if (m.find(x) != m.end() && x != v[i] && x != v[j]) return true;
        }
    } return false;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    long long N,M,tmp;
    std::vector<long long> v;
    std::unordered_map<long long,int> m;
    std::cin >> N >> M;

    while(N--){
        std::cin >> tmp;
        v.push_back(tmp);
        m[tmp] = 0;
    } while(M--){
        std::cin >> tmp;
        if (triple(v,m,tmp)) std::cout << "YES\n";
        else {std::cout << "NO\n";}
    }
}