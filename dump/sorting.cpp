#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InsertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(vector<int>& arr, int left, int right){
    int pivot = arr[left];
    int i = left;
    int j = right;
    while(i < j){
        while(arr[i] <= pivot && i < right) i++;
        while(arr[j] > pivot && j > left) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int left, int right){
    if(left < right) {
        int pIndex = partition(arr, left, right);
        quickSort(arr, left, pIndex);
        quickSort(arr, pIndex + 1, right);

    }
}

void merge(vector<int>& arr, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= right){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = left; k <= right; k++){
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right) return;
    else{
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

    }
}

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}