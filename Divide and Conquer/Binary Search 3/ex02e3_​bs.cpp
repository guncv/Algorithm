#include <iostream>
#include <vector>

int binary_search(std::vector<int> &v, int start, int stop, int max_num){
    if (start < stop) {
        int m = (start + stop)/ 2;
        if (v[m+1] > max_num){
            if (v[m] <= max_num) {
                return m;
            } return binary_search(v,start,m,max_num);
        } return binary_search(v,m+1,stop,max_num);
    } else {
        if (v[start] > max_num) return -1;
        return start;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, m, tmp;
    std::vector<int> v;

    std::cin >> n >> m;

    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
    }

    while(m--){
        std::cin >> tmp;
        std::cout << binary_search(v,0,v.size()-1,tmp) << "\n";
    }
}