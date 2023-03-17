#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int line,tmp,count = 0;
    std::cin >> line >> tmp;
    int worst = tmp,best = tmp;
    line--;

    while(line--){
        std::cin >> tmp;
        if (tmp > best) {
            count++;
            best = tmp;
        } else if (tmp < worst){
            count++;
            worst = tmp;
        }
    } std::cout << count << "\n";
}