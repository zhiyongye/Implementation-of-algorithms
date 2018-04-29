#include<iostream>
#include"SortTestHelper.h"

using namespace std;

// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int left, int rigth) {
	
	T e = arr[left];
	int j = left;
	for (int i=left+1; i<=rigth; ++i) {   //ʹ�� arr[l+1...j] < v ; arr[j+1...i) > v
		if (arr[i] < e) {
			j++;
			swap(arr[i], arr[j]);
		}
	}
	
	//����left��j��Ԫ�� 
	swap(arr[left], arr[j]);
	
	return j;
	
}

// ��arr[l...r]���ֽ��п�������
template<typename T>
void __quickSort(T arr[], int left, int right) {
	
	if (left >= right) {
		return;
	}
	
	int p = __partition(arr, left, right);
	__quickSort(arr, left, p);
	__quickSort(arr, p+1, right);
}


template<typename T>
void quickSort(T arr[],int n) {
	
	__quickSort(arr,0,n-1);
	
	return;
}

int main() {
	int n = 100;
	int * arr = SortTestHelper::generateRandomArray(n,0,n);
	SortTestHelper::printArray(arr,n);
	quickSort(arr,n);
	SortTestHelper::printArray(arr,n);
	//SortTestHelper::testSort("insertSort",insertionSort,arr2,n);

	
	delete[] arr;
		
	return 0;
}
