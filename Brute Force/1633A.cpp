#include <iostream>
#include <vector>
#include <map>

bool check_digit(int &tmp , std::map<int,std::vector<int> > &m , std::vector<char> &v, bool b){
    std::string s = std::to_string(tmp);
    if (s.length() != v.size()) return true;
    int count = 0;
    for (int i = 0 ; i < s.length() ; i++){
        if (s[i] != v[i]) count++;
    } m[count].push_back(tmp);
    if (b) tmp+= 7;
    else {tmp -= 7;}
    return false;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int line,tmp;
    std::cin >> line;

    while(line--){
        std::cin >> tmp;
        if (tmp%7 == 0) {
            std::cout << tmp << "\n";
            continue;
        } std::vector<char> v;
        std::map<int,std::vector<int> > m;
        std::string s = std::to_string(tmp);
        for (auto &x : s) v.push_back(x);
        int tmp1 = tmp - tmp%7 + 7;
        int tmp2 = tmp - tmp%7;
        while(true){
            if (check_digit(tmp1,m,v,true) && check_digit(tmp2,m,v,false)) break;
        } std::cout << m.begin()->second[0] << "\n"; 
    }
}