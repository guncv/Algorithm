#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int r,c;
    char tmp;

    std::cin >> r >> c;
    std::vector<std::vector<int> > adj(r),value(r);
    std::queue<std::pair<int,int> > bfs;
    int dr[] = {1,0,-1,0};
    int dc[] = {0,1,0,-1};

    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            std::cin >> tmp;
            adj[i].push_back(tmp);
            value[i].push_back(-1);
        }
    }

    bfs.push(std::make_pair(0,0));
    value[0][0] = 0;
    while(!bfs.empty()){
        std::pair<int,int> current = bfs.front();
        bfs.pop();
        for (int i = 0 ; i < 4 ; i++){
            int row = current.first + dr[i];
            int col = current.second + dc[i];
            if (row >= r || row < 0 || col >= c || col < 0 || adj[row][col] == '#') continue;
            if (value[row][col] == -1) {
                value[row][col] = value[current.first][current.second] + 1;
                bfs.push(std::make_pair(row,col));
            } else if (value[current.first][current.second]+1 < value[row][col]) {
                value[row][col] = value[current.first][current.second] + 1;
                bfs.push(std::make_pair(row,col));
            }
        }
    } std::cout << value[r-1][c-1] << '\n';
}