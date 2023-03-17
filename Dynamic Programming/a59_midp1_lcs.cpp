#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp;
    std::string s1,s2,s;
    char c;
    std::cin >> n >> m;
    int array[n+1][m+1];

    for (int i = 0 ; i < n ; i++){
        std::cin >> c;
        s1 += c;
    } for (int i = 0 ; i < m ; i++){
        std::cin >> c;
        s2 += c;
    } for (int i = 0 ; i <= n ; i++){
        for (int j = 0 ; j <= m ; j++){
            std::cin >> tmp;
            array[i][j] = tmp;
        }
    }  

    while(n > 0 && m > 0){
        if (s1[n-1] == s2[m-1]){
            s = s1[n-1]+s;
            n--; 
            m--;
            continue;
        } if (array[n][m-1] >= array[n-1][m]){
            m--;
        } else {n--;}
    } std::cout << s << "\n";
}