#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> x, int target, int low, int right){
    int mid = (low+right)/2;
    if(x[mid] == target){
        return mid;
    }
    else if(x[mid] > target){
        right = mid - 1;
        return binarysearch(x, target, low, right);
    }
    else low = mid + 1; return binarysearch(x, target, low, right);
    return -1;
}

int main()
{
    int target, n, x;
    cin >> target >> n;
    vector<int> myvector;
    while(n--){
        cin >> x;
        myvector.push_back(x);
    }
    int y = myvector.size();
    cout << binarysearch(myvector, target, 0, y);
}