#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp,tmp1;
    std::vector<int> seq,time;

    std::cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        std::cin >> tmp;
        seq.push_back(tmp);
    } for (int i = 0 ; i < m ; i++){
        std::cin >> tmp;
        time.push_back(tmp);
    }

    while(n--){
        std::cin >> tmp >> tmp1;
        for (int i = 0 ; i < seq.size() ; i++) {
            if (seq[i] == tmp) {
                
            }
        }
    }
}