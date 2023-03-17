#include <iostream>
#include <vector>

int binary_search(std::vector<int> &v,int start,int stop,int k){
    if (start == stop){
        if (v[start] <= k) return start;
        return -1;
    } else {
        int p = (start+stop)/2;
        if (v[p] <= k && v[p+1] > k) return p;
        if (v[p] > k) return binary_search(v,start,p,k);
        return binary_search(v,p+1,v.size()-1,k);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int N,M,tmp;
    std::vector<int> v;
    std::cin >> N >> M;

    while(N--){
        std::cin >> tmp;
        v.push_back(tmp);
    } while(M--){
        std::cin >> tmp;
        std::cout << binary_search(v,0,v.size()-1,tmp) << "\n";
    }
}