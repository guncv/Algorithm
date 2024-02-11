#include <iostream>
#include <vector>
#include <math.h>

void recursive_matrix(std::vector<std::vector<int> > &matrix,int a,int b,int start_x,int stop_x,int start_y,int stop_y) {
    if (a > 1){
        int mx = (start_x + stop_x)/2;
        int my = (start_y + stop_y)/2;
        recursive_matrix(matrix,a-1,b,start_x,mx,start_y,my);
        recursive_matrix(matrix,a-1,b+1,mx+1,stop_x,start_y,my);
        recursive_matrix(matrix,a-1,b-1,start_x,mx,my+1,stop_y);
        recursive_matrix(matrix,a-1,b,mx+1,stop_x,my+1,stop_y);
        return;
    } matrix[start_x][start_y] = b;
    matrix[start_x][start_y+1] = b-1;
    matrix[start_x+1][start_y] = b+1;
    matrix[start_x+1][start_y+1] = b;
}

int main() {
    int a,b;
    std::cin >> a >> b;

    if (a == 0) std::cout << b << "\n";
    else {
        std::vector<std::vector<int> > matrix(pow(2,a));
        for (int i = 0 ; i < pow(2,a) ; i++){
            matrix[i].push_back(0);
        } recursive_matrix(matrix,a,b,0,pow(2,a),0,pow(2,a));
        
        for (int i = 0 ; i < matrix.size() ; i++){
            for (int j = 0 ; j < matrix.size() ; j++){
                std::cout << matrix[i][j] << " ";
            } std::cout << "\n";
        }
    } 
}