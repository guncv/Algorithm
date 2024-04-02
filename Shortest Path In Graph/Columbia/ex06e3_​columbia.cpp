#include <iostream>
#include <vector>
#include <limits.h>
#include <set>  

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int r,c,tmp;
    
    std::cin >> r >> c;
    std::vector<std::vector<int> > weight(r),cost(r);
    std::vector<std::vector<std::pair<int,int> > > prev(r);
    std::set<std::pair<int,std::pair<int,int> > > s;
    int rr[] = {0,1,0,-1};
    int cc[] = {1,0,-1,0};

    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            std::cin >> tmp;
            weight[i].push_back(tmp);
            cost[i].push_back(INT_MAX);
            prev[i].push_back(std::make_pair(-1,-1));
        }
    }

    cost[0][0] = 0;
    s.insert(std::make_pair(0,std::make_pair(0,0)));

    while(!s.empty()){
        auto current = *s.begin();
        s.erase(s.begin());

        for (int i = 0 ; i < 4 ; i++){
            int row = current.second.first+rr[i];
            int col = current.second.second+cc[i];
            if (row < 0 || row >= r || col < 0 || col >= c) continue;
            else if (current.first+weight[row][col] < cost[row][col]) {
                auto it = s.find(std::make_pair(cost[row][col],std::make_pair(row,col)));
                if (it != s.end()) {
                    s.erase(std::make_pair(cost[row][col],std::make_pair(row,col)));
                }
                s.insert(std::make_pair(current.first+weight[row][col],std::make_pair(row,col)));
                cost[row][col] = current.first+weight[row][col];
                prev[row][col] = std::make_pair(current.second.first,current.second.second);
            }
        }
    } 

    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            std::cout << cost[i][j] << " ";
        } std::cout << "\n";
    }
}