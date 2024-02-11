#include <iostream>
#include <vector>
#include <math.h>

//Not Finished Yet
void tiling(std::vector<std::vector<int> > &v, int len,int start_x,int stop_x,int start_y,int stop_y,int x,int y,int idx){
    if (len > 4){
        int mx = (start_x + stop_x)/2;
        int my = (start_y + stop_y)/2;
        tiling(v,len/2,start_x,mx,start_y,my,x,y,idx);
        tiling(v,len/2,mx+1,stop_x,start_y,my,x,y,idx);
        tiling(v,len/2,start_x,mx,my+1,stop_y,x,y,idx);
        tiling(v,len/2,mx+1,stop_x,my+1,stop_y,x,y,idx);
    } else {
        if (len == 4) {
        }
    }
}

int main() {
    int l,x,y;
    std::vector<std::vector<int> > tile;

    std::cin >> l >> x >> y;
    tiling(tile,l,0,l,0,l,x,y,4);
    for (int i = 0 ; i < tile.size() ; i++){
        for (int j = 0 ; j < tile[i].size() ; j++){
            std::cout << tile[i][j] << " ";
        } std::cout << "\n";
    }
}