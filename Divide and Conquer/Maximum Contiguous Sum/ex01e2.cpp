#include <iostream>
#include <math.h>
#include <vector>

int get_sum(std::vector<int> &sum,int a,int b){
    return sum[b+1] - sum[a];
}

int maximum_subarray(std::vector<int> &v,std::vector<int> &sum,int start,int stop){
    if (start < stop){
        int m = (start+stop)/2;
        int r1 = maximum_subarray(v,sum,start,m);
        int r2 = maximum_subarray(v,sum,m+1,stop);

        int max_sum_left = get_sum(sum,m,m);
        for (int i = 0 ; i < m ; i++){
            max_sum_left = std::max(max_sum_left,get_sum(sum,i,m));
        } 

        int max_sum_right = get_sum(sum,m+1,m+1);
        for (int i = m+2 ; i <= stop ; i++){
            max_sum_right = std::max(max_sum_right,get_sum(sum,m+1,i));
        } int max = std::max(r1,r2);
        return std::max(max,max_sum_left+max_sum_right);
    } return v[start];
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp;
    std::vector<int> v,sum;
    sum.push_back(0);

    std::cin >> n;
    while(n--) {
        std::cin >> tmp;
        v.push_back(tmp);
        sum.push_back(tmp+sum[sum.size()-1]);
    } std::cout << maximum_subarray(v,sum,0,v.size()-1) << "\n";
}