#include <iostream>
#include <map>

bool change_digit(int x){
    std::map<char,int> m;
    std::string s = std::to_string(x);
    for (auto &x : s){
        if (m.find(x) != m.end()) return false;
        m[x] = 0;
    } return true;
}

int main(){
    int year;
    std::cin >> year;

    while(true){
        year++;
        if (change_digit(year)){
            std::cout << year << "\n";
            break;
        }
    }

}


