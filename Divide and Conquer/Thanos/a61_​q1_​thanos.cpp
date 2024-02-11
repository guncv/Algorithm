#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

typedef long long ll;

ll func(std::vector<ll> &v,ll start,ll stop,ll A,ll B,ll n){
    ll x = lower_bound(v.begin(),v.end(),stop) - lower_bound(v.begin(),v.end(),start);
    if (x == 0) return A;
    if (n != 0){
        ll mid = (start+stop)/2;
        return std::min(B*x*(stop-start),func(v,start,mid,A,B,n-1)+func(v,mid,stop,A,B,n-1));
    } return B*x;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    ll n,k,A,B,tmp;
    std::vector<ll> v;
    std::cin >> n >> k >> A >> B;
    ll p = pow(2,n);

    while(k--){
        std::cin >> tmp;
        v.push_back(tmp-1);
    } sort(v.begin(),v.end());
    std::cout << func(v,0,p,A,B,n) << "\n";
}
