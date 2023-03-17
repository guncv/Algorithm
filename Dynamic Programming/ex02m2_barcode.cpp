#include <iostream>
#include <vector>

int array[31][31][31];

int combi(int len,int same,int change,int n,int m,int k,std::vector<int> &v){
    if (same > m || change > k) return 0;
    if (len == n){
        if (change == k) return 1;
        return 0;
    } int sum = 0;
    if (array[len][same][change] != 0) return array[len][same][change];
    if (v[len-1] == 0){
        v[len] = 0;
        sum += combi(len+1,same+1,change,n,m,k,v);
        v[len] = 1;
        sum += combi(len+1,1,change+1,n,m,k,v);
        array[len][same][change] = sum;
        return sum;
    } v[len] = 0;
    sum += combi(len+1,1,change+1,n,m,k,v);
    v[len] = 1;
    sum += combi(len+1,same+1,change,n,m,k,v);
    array[len][same][change] = sum;
    return sum;
}

int main(){
    int n,m,k;
    std::cin >> n >> m >> k;
    std::vector<int> v(n);
    std::cout << combi(1,1,0,n,m,k,v) << "\n";
}