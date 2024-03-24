#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n,tmp;
    std::vector<int> billboard;
  
    std::cin >> n;
    int bigger_billboard[n];
    for (int i = 0 ; i < n ; i++){
        std::cin >> tmp;
        billboard.push_back(tmp);
    } 

    if (n == 1) {
        std::cout << billboard[0] << "\n";
    } else if (n == 2){
        std::cout << std::max(billboard[0],billboard[1]) << "\n";
    } else if (n == 3) {
        std::cout << std::max({billboard[0], billboard[1], billboard[2]});
    }
    else {
        bigger_billboard[0] = billboard[0];
        bigger_billboard[1] = billboard[1];
        bigger_billboard[2] = std::max({billboard[0], billboard[1], billboard[2]});
        
        for (int i = 3 ; i < n ; i++){
            if (i == 3) {
                bigger_billboard[i] = billboard[i] + bigger_billboard[i-3];
            } if (i > 3) {
                bigger_billboard[i] = billboard[i] + std::max(bigger_billboard[i-3],bigger_billboard[i-4]);
            } bigger_billboard[i] = std::max({bigger_billboard[i],bigger_billboard[i-1],bigger_billboard[i-2]});
        }
    } std::cout << bigger_billboard[n-1] << "\n";
}