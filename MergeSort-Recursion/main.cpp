#include<iostream>
#include"SortTestHelper.h"

using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int left, int mid, int right) {
	
	//分配一块临时空间 
	T *temp = new T[right-left+1];
	for(int i=left; i<=right; ++i) 
		temp[i-left] = arr[i];     //注意temp与arr有left的偏移 
	
	int i = left;      //i指向左半部分的起始索引位置
	int j = mid+1;     //j指向右半部分起始索引位置
	for(int k=left; k<=right; ++k) {
	
		if(i > mid) {     // 如果左半部分元素已经全部处理完毕
			arr[k] = temp[j-left];
			j++;
		}else if(j > right) {     // 如果右半部分元素已经全部处理完毕
			arr[k] = temp[i-left];
			i++;
		}else if(temp[i-left] < temp[j-left]) {    // 左半部分所指元素 < 右半部分所指元素
			arr[k] = temp[i-left];
			i++;
		}else{                                     // 左半部分所指元素 >= 右半部分所指元素
			arr[k] = temp[j-left];
			j++;
		}
	}
	
	delete[] temp;
	
	return;
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int left, int right) {
	
	if(left >= right) {
		return;
	}
	
	int mid = (left+right)/2;
	__mergeSort(arr, left, mid);
	__mergeSort(arr, mid+1, right);
	if (arr[mid] > arr[mid+1]) {
		__merge(arr, left, mid, right);
	}
	
	return;
}

template<typename T>
void mergeSort(T arr[],int n) {
	
	__mergeSort(arr,0,n-1);
	
	return;
}

int main() {
	int n = 100;
	int * arr = SortTestHelper::generateRandomArray(n,0,n);
	SortTestHelper::printArray(arr,n);
	mergeSort(arr,n);
	SortTestHelper::printArray(arr,n);
	//SortTestHelper::testSort("insertSort",insertionSort,arr2,n);

	
	delete[] arr;
		
	return 0;
}
