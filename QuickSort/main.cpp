#include<iostream>
#include"SortTestHelper.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int left, int rigth) {
	
	T e = arr[left];
	int j = left;
	for (int i=left+1; i<=rigth; ++i) {   //使得 arr[l+1...j] < v ; arr[j+1...i) > v
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
	
	if (left >= right) {
		return;
	}
	
	int p = __partition(arr, left, right);
	__quickSort(arr, left, p-1);
	__quickSort(arr, p+1, right);
}


template<typename T>
void quickSort(T arr[],int n) {
	
	__quickSort(arr,0,n-1);
	
	return;
}


/*
//写法二
template<typename T> 
void quickSort(T nums[], int left, int right) {
	
	if (left >= right) 
		return;
	
	T ele = nums[left];
	
	int j = left;
	for (int i=left+1; i<=right; ++i) {
		if (nums[i] < ele) {
			j++;
			swap(nums[i], nums[j]);
		}
	}
	
	swap(nums[left], nums[j]);
	
	quickSort(nums, left, j-1);
	quickSort(nums, j+1, right);
	
}

*/

int main() {
	int n = 1000;
	int * arr = SortTestHelper::generateRandomArray(n,0,n);
	SortTestHelper::printArray(arr,n);
	quickSort(arr,n);
	SortTestHelper::printArray(arr,n);
	//SortTestHelper::testSort("insertSort",insertionSort,arr2,n);

	
	delete[] arr;
		
	return 0;
}
