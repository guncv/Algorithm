#include <iostream>
#include <vector>

typedef long long ll;

void matrix(std::vector<std::pair<ll,ll> > &x,std::vector<std::pair<ll,ll> > &y,ll start_row,ll stop_row,ll start_col,ll stop_col,ll n,bool b){
    ll row = (start_row + stop_row)/2;
    ll col = (start_col + stop_col)/2;
    if (n != 1){
    } if (b) {
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie();
    ll n,sum; int tmp;
    std::cin >> n;
    std::vector<int> vec;
    std::vector<std::pair<ll,ll> > x,y;

    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        vec.push_back(tmp);
    } matrix(x,y,0,n,0,n,false);
    
    for (int i = 0 ; i < n ; i++){
        sum = 0;
        for (int j = 0 ; j < n ; j++){
            if (mat[i][j]) sum -= v[j];
            else {sum += v[j];}
        } std::cout << sum << " ";
    } std::cout << "\n";
}