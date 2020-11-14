#include <iostream>
#include <vector>
#include <algorithm>
void bucket_sort(float a[], int size) {
    std::vector<float> b[size];
    int i, j, pos=0;
    for(i=0; i<size; i++) b[int(size*a[i])].push_back(a[i]);
    for(i=0; i<size; i++) sort(b[i].begin(), b[i].end());
    for(i=0; i<size; i++) {
        for(j=0; j<b[i].size(); j++) a[pos++]=b[i][j];
    }
}
int main() {
    float arr[] = {0.9, 0.1, 0.22, 0.99, 0.0, 0.4, 0.22};
    int size = sizeof(arr)/sizeof(float);
    bucket_sort(arr, size);
    for(int i=0; i<size; i++) std::cout << arr[i] << " ";
    // 0 0.1 0.22 0.22 0.4 0.9 0.99 
}