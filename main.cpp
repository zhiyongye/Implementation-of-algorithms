#include<iostream>
#include"SortTestHelper.h"

using namespace std;

//选择排序 
template<typename T>
void selectionSort(T arr[], int n) {
	
	for(int i=0; i<n; i++) {
		// 寻找[i, n)区间里的最小值
		int minIndex = i;
		for(int j=i+1; j<n; j++) {
			if(arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		} 
		
		//交换 
		swap( arr[i] , arr[minIndex] );
		
	}
	
	return;
}

//插入排序
template<typename T>
void insertionSort(T arr[], int n) {
	
	for(int i=1; i<n; i++) {
		
		/*
		// 寻找元素arr[i]合适的插入位置
		for(int j=i; j>0 && arr[j]<arr[j-1]; j--) {
				swap(arr[j],arr[j-1]);     //交换 
		}
		*/
		
		/*
		//写法二 
		for(int j=i; j>0; j--) {
			if(arr[j]<arr[j-1]) 
				swap(arr[j],arr[j-1]);    //交换 
			else 
				break;
		}
		*/
		
		//写法三
		//写法一和二交换数组元素的次数多，效率比较慢
		T e = arr[i];
		int j;      // j保存元素e应该插入的位置
		for (j=i; j>0 && arr[j-1]>e; j--) {
			arr[j] = arr[j-1];
		} 
		arr[j] = e;
	}
	
	return;
}

int main() {
	int n = 10000;
	int * arr = SortTestHelper::generateRandomArray(n,0,n);
	int * arr2 = SortTestHelper::copyIntArray(arr,n);
	insertionSort(arr,n);
	SortTestHelper::printArray(arr,n);
	
	//SortTestHelper::testSort("selectSort",selectionSort,arr,n);
	//SortTestHelper::testSort("insertSort",insertionSort,arr2,n);

	
	delete[] arr;
	delete[] arr2;
		
	return 0;
}
