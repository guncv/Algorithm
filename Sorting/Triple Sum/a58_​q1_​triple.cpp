#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m,tmp,left,right,tmp1;
    bool check;
    std::cin >> n >> m;
    std::vector<int> v;

    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
    }

    while(m--){
        std::cin >> tmp;
        check = false;

        for (int i = 0; i < v.size()-1; i++) {
            tmp1 = v[i];
            left = i+1;
            right = v.size()-1;
            while(left < right) {
                if (tmp1 + v[left] + v[right] > tmp) {
                    right--;
                    continue;
                } else if (tmp1 + v[left] + v[right] < tmp){
                    left++;
                    continue;
                } check = true;
                break;
            }
        } 

        if (check) {
            std::cout << "YES" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }

    }
}