#include <iostream>
#include <vector>
#include <algorithm>

int sum_all(std::vector<int> &S , int a , int b){
    return S[b+1] - S[a];
}

int find_max(std::vector<int> &v , int start , int stop , std::vector<int> &S){
    if (start == stop){
        return v[start];
    } int m = (start + stop)/2;
    int r1 = find_max(v,start,m,S);
    int r2 = find_max(v,m+1,stop,S);

    int max_left = sum_all(S,start,m);
    for (int i = start+1 ; i <= m ; i++){
        max_left = std::max(max_left,sum_all(S,i,m));
    }

    int max_right = sum_all(S,m+1,stop);
    for (int i = stop ; i >= m+1 ; i--){
        max_right = std::max(max_right,sum_all(S,m+1,i));
    } int x1 = std::max(r1,r2);
    return std::max(x1,max_left+max_right);
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp,sum = 0;
    std::vector<int> v,S;
    std::cin >> n;
    S.push_back(sum);

    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
        sum += tmp;
        S.push_back(sum);
    } std::cout << find_max(v,0,v.size()-1,S) << "\n";
}