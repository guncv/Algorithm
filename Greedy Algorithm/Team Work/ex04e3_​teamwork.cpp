#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    std::vector<double> task,time;
    double n,m,tmp,ans = 0,j = 0; 
    std::priority_queue<int,std::vector<int>, std::greater<int> > pq;

    std::cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> tmp;
        task.push_back(tmp);
    } std::sort(task.begin(),task.end());

    for (int i = 0 ; i < n ; i++){
        pq.push(task[i]);
        time.push_back(task[i]);
        j++;
    }

    for (int i = j ; i < m ; i++){
        int tmp1 = pq.top();
        pq.pop();
        pq.push(tmp1+task[i]);
        time.push_back(tmp1+task[i]);
    }  
    
    for (int x : time) {
        ans += x;
    }
    
    std::cout << std::fixed << std::setprecision(3) << ans/m << "\n"; 
}