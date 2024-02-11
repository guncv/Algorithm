#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,tmp;
    std::vector<int> v;
    std::cin >> n;

    while(n--){
        std::cin >> tmp;
        v.push_back(tmp);
    } int count = 0;
    for (int i = 0 ; i < v.size() ; i++){
        for (int j = i+1 ; j < v.size() ; j++){
            if (v[i] > v[j]) count++;
        }
    } std::cout << count << "\n";
}

//Merge Sort
// int count = 0;

// void merge(std::vector<int> &v, int start,int m, int stop, std::vector<int> &tmp){
//     int j = start;
//     int k = m+1;
//     for (int i = start ; i <= stop ; i++){
//         if (j > m) tmp[i] = v[k++];
//         else if (k > stop) tmp[i] = v[j++];
//         else {
//             if (v[k] < v[j]) {
//                 tmp[i] = v[k++];
//                 count++;
//             } else {tmp[i] = v[j++];}
//         }
//     }

//     for (int i = start ; i <= stop ; i++){
//         v[i] = tmp[i];
//     }
// }

// void merge_sort(std::vector<int> &v, int start, int stop, std::vector<int> &tmp){
//     if (start < stop) {
//         int m = (start + stop) / 2;
//         merge_sort(v,start,m,tmp);
//         merge_sort(v,m+1,stop,tmp);
//         merge(v,start,m,stop,tmp);
//     }
// }

// int main() {
//     std::ios_base::sync_with_stdio(false); std::cin.tie(0);
//     int n,tmp;
//     std::vector<int> v;

//     std::cin >> n;
//     while(n--){
//         std::cin >> tmp;
//         v.push_back(tmp);
//     } std::vector<int> tmp1(v.size()); 
//     merge_sort(v,0,v.size()-1,tmp1);
//     for (int i = 0 ; i < v.size() ; i++) {
//         std::cout << v[i] << " ";
//     } std::cout << "\n";
//     std::cout << count;
// }

/* Quick Sort
int count = 0;

int partition(std::vector<int> &v, int start, int stop){
    int pivot = v[start];
    int left = start;
    int right = stop;
    while (left < right) {
        while(v[left] < pivot) {
            left++;
        } 
        while(v[right] > pivot) {
            right--;
        } 
        if (left < right){
            std::swap(v[left],v[right]);
            count++;
        }
    } return right;
}


void quick_sort(std::vector<int> &v, int start, int stop){
    if (start < stop) {
        int m = partition(v,start,stop);
        quick_sort(v,0,m);
        quick_sort(v,m+1,stop);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, tmp;
    std::vector<int> v;
    
    std::cin >> n;
    while(n--) {
        std::cin >> tmp;
        v.push_back(tmp);
    } quick_sort(v,0,v.size()-1);
    std::cout << count;
}
*/