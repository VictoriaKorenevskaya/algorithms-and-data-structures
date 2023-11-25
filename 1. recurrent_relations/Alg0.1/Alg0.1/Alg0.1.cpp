

#include <iostream>
#include <vector>
using namespace std;

int UpperBound(const vector<int>& arr, const int& value) {
    int leftBound = 0;
    int rightBound = arr.size();

    while (leftBound < rightBound) {
        int middle = (leftBound + rightBound) / 2;
        if (arr[middle] > value)
            rightBound = middle;
        else leftBound = middle + 1;
    }
    return leftBound;
}

int LowerBound(const vector<int>& arr, const int& value) {
    int leftBound = 0;
    int rightBound = arr.size();

    while (leftBound < rightBound) {
        int middle = (leftBound + rightBound) / 2;
        if (arr[middle] >= value)
            rightBound = middle;
        else leftBound = middle + 1;
    }
    return leftBound;
}

bool Binary(const vector<int>& arr, const int& value) {
    int leftBound = 0;
    int rightBound = arr.size();

    while (leftBound < rightBound) {
        int middle = (leftBound + rightBound) / 2;
        if (arr[middle] == value)
            return true;
        else if (arr[middle] > value)
            rightBound = middle;
        else if (arr[middle] < value)
            leftBound = middle + 1;
    }
    return false;
}

void BinarySearch(const vector<int>& arr, vector <int> arrSec) {

    for (size_t i = 0; i < arrSec.size(); i++)
    {
        int inArr = 0;
        if (Binary(arr, arrSec[i])){ 
            inArr = 1;
        }
          
        cout << inArr << " ";
        cout << LowerBound(arr, arrSec[i]) << " ";
        cout << UpperBound(arr, arrSec[i]) << "\n";
        inArr = 0;
    }

}

int main() {
    int size;
    cin >> size;
    vector <int> arr(size);

    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;
    vector <int> arrSec(x);

    for (size_t i = 0; i < x; i++)
    {
        cin >> arrSec[i];
    }

    BinarySearch(arr, arrSec);
    return 0;
}