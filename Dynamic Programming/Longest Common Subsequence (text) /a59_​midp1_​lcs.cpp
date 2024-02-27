#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp1;
    std::vector<char> x,y,sub_lcs;
    std::vector<std::vector<int> > table;
    std::vector<int> v_tmp;
    char tmp;

    std::cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        x.push_back(tmp);
    } for (int j = 0 ; j < m ; j++){
        std::cin >> tmp;
        y.push_back(tmp);
    } 

    for (int i = 0 ; i <= n ; i++){
        for (int j = 0 ; j <= m ; j++){
            std::cin >> tmp1;
            v_tmp.push_back(tmp1);
        } table.push_back(v_tmp);
        v_tmp.clear();
    } 

    while(n != 0 && m != 0){
        if (x[n-1] == y[m-1]) {
            sub_lcs.push_back(x[n-1]);
            n-- ;
            m-- ;
        } else if (table[n][m] == 0) {
            break;
        } 
        else {
            if (table[n][m-1] < table[n-1][m]){
                n--;
            } else {
                m--;
            }
        }
    }   
    
    for (int i = sub_lcs.size()-1 ; i >= 0 ; i--){
        std::cout << sub_lcs[i];
    } std::cout << "\n";
}