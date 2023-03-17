#include <iostream>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int line,count = 0,tmp1,tmp2;
    std::map<int,int> m_home,m_guest;
    std::cin >> line;

    while(line--){
        std::cin >> tmp1 >> tmp2;;
        if (m_guest.find(tmp1) != m_guest.end()) count += m_guest[tmp1];
        if (m_home.find(tmp2) != m_home.end()) count += m_home[tmp2];

        if (m_home.find(tmp1) != m_home.end()) m_home[tmp1]++;
        else {m_home[tmp1] = 1;}

        if (m_guest.find(tmp2) != m_guest.end()) m_guest[tmp2]++;
        else {m_guest[tmp2] = 1;}
    } std::cout << count << "\n";
}