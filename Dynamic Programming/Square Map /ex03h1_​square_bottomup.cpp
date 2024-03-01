#include <iostream> 
#include <math.h>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int r,c,max = 0;
    std::string tmp;
    
    std::cin >> r >> c; 
    int table[r][c];

    for (int i = 0 ; i < r ; i++){
        std::cin >> tmp;
        for (int j = 0 ; j < tmp.length() ; j++){
            table[i][j] = static_cast<int>(tmp[j])-48;
            max = std::max(max,table[i][j]);
        }
    }

    for (int i = 1 ; i < r ; i++){
        for (int j = 1 ; j < c ; j++){
            if (table[i][j] == 1) {
                int x = std::min(table[i-1][j],table[i-1][j-1]);
                table[i][j] = 1 + std::min(x,table[i][j-1]);
                max = std::max(max,table[i][j]);
            } 
        }
    } 
    std::cout << max << "\n";
}