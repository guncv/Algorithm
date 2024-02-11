#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

bool check_virus(std::vector<int > &check, int k,  bool b) {
    std::vector<int > check1,check2,check3;
    for (int i = 0 ; i < check.size()/2 ; i++){
        check1.push_back(check[i]);
        check2.push_back(check[i+check.size()/2]);
    }   check3 = check1;
    std::reverse(check3.begin(),check3.end());
    if (k > 1){
        return  (check_virus(check3,k-1,false) || check_virus(check1,k-1,false)) && check_virus(check2,k-1,true);
    } else {
        if (b) {
            if (check[0] == 0 && check[1] == 1) return true;
            return false;
        } else if ((check[0] == 0 && check[1] == 1) || (check[0] == 1 && check[1] == 0)) {
            return true;
        } return false;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,k,tmp;
    std::vector<int > check;

    std::cin >> n >> k;
    while(n--){
        for (int i = 0 ; i < pow(2,k) ; i++) {
            std::cin >> tmp;
            check.push_back(tmp);
        }
        if (check_virus(check,k,true)) {
            std::cout << "yes" << "\n";
        } else {std::cout << "no" << "\n";}
        check.clear();
    }
}