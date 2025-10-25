#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

void Sort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        Sort(vec, low, pi - 1);
        Sort(vec, pi + 1, high);
    }
}

int main()
{
    int n, x;
    vector<int>placeholder;
    cin >> n;
    while(n--){
        cin >> x;
        placeholder.push_back(x);
    }
    int y = placeholder.size();
    Sort(placeholder, 0, y - 1);
    
    for(auto i : placeholder){
        cout << i << " ";
    }
    
}