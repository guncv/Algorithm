#include <iostream>
#include <math.h>

int main() {
    std::string x,y;
    std::cin >> x;
    std::cin >> y;

    int lcs[x.length()+1][y.length()+1];
    for (int i = 0 ; i <= x.length() ; i++){
        lcs[i][0] = 0;
    } for (int j = 0 ; j <= y.length() ; j++){
        lcs[0][j] = 0;
    }

    for (int i  = 1 ; i <= x.length() ; i++){
        for (int j = 1 ; j <= y.length() ; j++){
            if (x[i-1] == y[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else {
                lcs[i][j] = std::max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    } 
    std::cout << lcs[x.length()][y.length()] << "\n";
}