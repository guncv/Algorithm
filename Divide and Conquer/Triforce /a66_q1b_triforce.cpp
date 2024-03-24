#include <iostream>
#include <vector>

int check(int x1,int x2,int x3,int x4) {
    if (x4 != 0 || x1 == 0 || x2 == 0 || x3 == 0) {
        return 0;
    } else {
        if (x1 == x2 || x1 == x3) {
            return x1;
        } else if (x1 == x2 || x2 == x3) {
            return x2;
        } else {
            return 0;
        }
    }
}

int S(std::vector<std::vector<int> > &matrix,int start_row,int stop_row,int start_col,int stop_col) {
    for (int i = start_row ; i < stop_row ; i++){
        for (int j = start_col ; j < stop_col ; j++){
            if (matrix[i][j] != 0) return 1;
        }
    } return 0;
}

int triforce(std::vector<std::vector<int> > &matrix,int start_row,int stop_row,int start_col,int stop_col,int n) {
    if (n == 2) {
        return check(matrix[start_row][start_col],matrix[start_row][start_col+1],matrix[start_row+1][start_col],matrix[start_row+1][start_col+1]);
    } else {
        int m_row = (start_row + stop_row)/2;
        int m_col = (start_col + stop_col)/2;
        return check(triforce(matrix,start_row,m_row,start_col,m_col,n/2),
            triforce(matrix,start_row,m_row,m_col,stop_col,n/2),
            triforce(matrix,m_row,stop_row,start_col,m_col,n/2),
            S(matrix,m_row,stop_row,m_col,stop_col));
    }
}   

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp;
    std::vector<std::vector<int> > matrix;
    std::vector<int> v,ans;

    std::cin >> n;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            std::cin >> tmp;
            v.push_back(tmp);
        } matrix.push_back(v);
        v.clear();
    } ans.push_back(triforce(matrix,0,n,0,n,n));
    matrix.clear();

    std::cin >> n;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            std::cin >> tmp;
            v.push_back(tmp);
        } matrix.push_back(v);
        v.clear();
    } ans.push_back(triforce(matrix,0,n,0,n,n));
    matrix.clear();

    std::cin >> n;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            std::cin >> tmp;
            v.push_back(tmp);
        } matrix.push_back(v);
        v.clear();
    } ans.push_back(triforce(matrix,0,n,0,n,n));

    for (int i = 0 ; i < ans.size() ; i++){
        std::cout << ans[i] << "\n";
    }
}