#include <iostream>

void combi(int len , int n , std::string s , int count , int a){
    if (count == a) {
        std::cout << s << "\n";
    } else if (len < n){
        s[len] = '0';
        combi(len+1,n,s,count,a);
        s[len] = '1';
        combi(len+1,n,s,count+1,a);
    }
}

int main(){
    int A,B;
    std::cin >> A >> B;
    std::string s;

    for (int i = 0 ; i < B ; i++){
        s += '0';
    }
    combi(0,B,s,0,A);
}