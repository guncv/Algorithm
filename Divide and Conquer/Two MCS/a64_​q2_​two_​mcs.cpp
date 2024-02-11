#include <iostream>
#include <vector>
#include <math.h>

int get_sum(std::vector<int> &sum,int a,int b){
    return sum[b+1] - sum[a];
}

int cal_between(std::vector<int> &v,std::vector<int> &sum,int start,int m,int stop){
    std::pair<int,int> left,right;
    int left_maximum = get_sum(sum,m,m);
    left = std::make_pair(m,m);

    for (int i = 0 ; i < m ; i++){
        if (left_maximum < get_sum(sum,i,m)){
            left_maximum = get_sum(sum,i,m);
            left = std::make_pair(i,m);
        }
    } 
    int right_maximum = get_sum(sum,m+1,m+1);
    right = std::make_pair(m+1,m+1);
    for (int i = m+2 ; i <= stop ; i++){
       if (right_maximum < get_sum(sum,m+1,i)){
            right_maximum = get_sum(sum,m+1,i);
            right = std::make_pair(m+1,i);
        }
    } 
    
    int r3 = left_maximum+right_maximum;
    if (m+2 <= right.second) r3 = std::max(r3,left_maximum+right_maximum-v[m+1]-v[m+2]);
    if (m-1 >= left.first) {
        r3 = std::max(r3,left_maximum+right_maximum-v[m]);
        r3 = std::max(r3,left_maximum+right_maximum-v[m]-v[m+1]);
    }
    if (m-2 >= left.first) r3 = std::max(r3,left_maximum+right_maximum-v[m-1]-v[m-2]);
    return std::max(r3,left_maximum+right_maximum-v[m+1]);
}

int two_maximum_subarray(std::vector<int> &v,std::vector<int> &sum,int start,int stop){
    if (start < stop){
        int m = (start+stop)/2;
        
        int r1 = two_maximum_subarray(v,sum,start,m);
        int r2 = two_maximum_subarray(v,sum,m+1,stop);
        int r3 = cal_between(v,sum,start,m,stop);
        int max = std::max(r1,r2);
        return std::max(max,r3);
    } return v[start];
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp;
    std::vector<int> v,sum;
    sum.push_back(0);

    std::cin >> n;
    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
        sum.push_back(tmp+sum[v.size()-1]);
    } std::cout << two_maximum_subarray(v,sum,0,v.size()-1) << "\n";
}