#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        if(i < 3){
            for(int k = 0; k<= i; k++){
                cout << arr[k];
                if(k == i) break;
                cout << " ";
            } cout << "\n";
        }
        
    }
}


int main(){
    int n, x;
  	vector<int> arr;
  	cin >> n;
  	while(n--){
    	cin >> x;
      	arr.push_back(x);
    }
    insertionsort(arr);
    for(int i : arr){
        cout << i << " ";
    }
}