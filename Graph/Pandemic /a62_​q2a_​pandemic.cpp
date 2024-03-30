#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int r,c,T,tmp,count = 0,day = 1;

    std::cin >> r >> c >> T;
    std::vector<std::vector<int> > pandemic(r);
    std::queue<std::pair<int,int> > bfs;
    int dr[] = {0,1,0,-1};
    int dc[] = {1,0,-1,0};

    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            std::cin >> tmp;
            pandemic[i].push_back(tmp);
            if (tmp == 1) {
                count++;
                bfs.push(std::make_pair(i,j));
            } 
        }
    } std::cout << "\n";

    for (int i = day ; i <= T ; i++) {
        int size = bfs.size();
        for (int j = 0 ; j < size ; j++){
            std::pair<int,int> current = bfs.front();
            bfs.pop();
            for (int k = 0 ; k < 4 ; k++){
                int row = current.first + dr[k];
                int col = current.second + dc[k];
                if (row < 0 || row >= r || col < 0 || col >= c || pandemic[row][col] == 2 || pandemic[row][col] == 1) continue;
                pandemic[row][col] = 1;
                bfs.push(std::make_pair(row, col));
                count++;
            }
        }
    } std::cout << count << "\n";
}   