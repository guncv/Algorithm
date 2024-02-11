#include <iostream>
#include <vector>
#include <math.h>

bool check_virus(std::vector<int> &check, int k) {
    if (k > 1){
        int count1 = 0,count2 = 0;
        std::vector<int> check1,check2;
        for (int i = 0 ; i < check.size()/2 ; i++){
            if (check[i] == 1) count1++;
            if (check[i+check.size()/2] == 1) count2++;
            check1.push_back(check[i]);
            check2.push_back(check[i+check.size()/2]);
        } if (count1-count2 > 1 || count1-count2 < -1) return false;
        return check_virus(check1,k-1) && check_virus(check2,k-1);
    } return true;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,k,tmp;
    std::vector<int> check;

    std::cin >> n >> k;
    while(n--) {
        for (int i = 0 ; i < pow(2,k) ; i++){
            std::cin >> tmp;
            check.push_back(tmp);
        } 
        if (check_virus(check,k)) {
            std::cout << "yes" << "\n";
        } else {
            std::cout << "no" << "\n";
        }
        check.clear();
    }
}