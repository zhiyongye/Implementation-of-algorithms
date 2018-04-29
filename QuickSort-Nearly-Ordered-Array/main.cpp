#include<iostream>
#include"SortTestHelper.h"

using namespace std;


//插入排序
template<typename T>
void insertionSort(T arr[], int n) {
	
	for(int i=1; i<n; i++) {
		
		T e = arr[i];
		int j;      // j保存元素e应该插入的位置
		for (j=i; j>0 && arr[j-1]>e; j--) {
			arr[j] = arr[j-1];
		} 
		arr[j] = e;
	}
	
	return;
}

template<typename T>
void insertionSort(T arr[], int left, int right){

    for( int i=left+1 ; i<=right ; i++ ) {

        T e = arr[i];
        int j;
        for (j = i; j>left && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int left, int right) {
	
	swap(arr[left], arr[rand()%(right-left+1)+left]);   //对于近乎有序的数字，随机选择一个数作为基准可以避免分区时所有数都被放在一边 
	
	T e = arr[left];
	int j = left;
	for (int i=left+1; i<=right; ++i) {   //使得 arr[l+1...j] < v ; arr[j+1...i) > v
		if (arr[i] < e) {
			j++;
			swap(arr[i], arr[j]);
		}
	}
	
	//交换left和j的元素 
	swap(arr[left], arr[j]);
	
	return j;
	
}

// 对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort(T arr[], int left, int right) {
	
	// 对于小规模数组, 使用插入排序进行优化
    if( right-left <= 15 ){
        insertionSort(arr, left, right);
        return;
    }
	
	srand(time(NULL));
	int p = __partition(arr, left, right);
	__quickSort(arr, left, p-1);
	__quickSort(arr, p+1, right);
}


template<typename T>
void quickSort(T arr[],int n) {
	
	__quickSort(arr,0,n-1);
	
	return;
}


int main() {
	int n = 100000;
	//int * arr = SortTestHelper::generateRandomArray(n,0,n);
	int * arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
	//SortTestHelper::printArray(arr,n);
	//quickSort(arr,n);
	//SortTestHelper::printArray(arr,n);
	SortTestHelper::testSort("insertionSort",insertionSort,arr,n);
	SortTestHelper::testSort("quickSort",quickSort,arr,n);

	
	delete[] arr;
		
	return 0;
}

