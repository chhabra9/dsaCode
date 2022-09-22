#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>&arr,int lastPos){
    int parent=lastPos/2;
    while(arr[parent]<=arr[lastPos]&&parent>=1){
        swap(arr[parent],arr[lastPos]);
        lastPos=parent;
        parent=parent/2;
    }
}
void createHeap(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        insert(arr,i);
    }
}
void deleteHeap(vector<int>&arr,int lastPos){
    swap(arr[1],arr[lastPos]);
    int i=1,j=2;
    while(j<lastPos){
        if(j<lastPos-1&&arr[j+1]>arr[j])
                j=j+1;
        if(arr[i]<arr[j]){
            swap(arr[i],arr[j]);
            i=j;
            j=2*j;
        }
        else
            break;
    }
}
void heapSort(vector<int>&arr){
    createHeap(arr);

    for(int i=1;i<arr.size();i++){
        deleteHeap(arr,arr.size()-i);
    }
}
int main(){
    vector<int>arr={0,10,20,30,25,5,40,35};
    heapSort(arr);
      for(int i=1;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
