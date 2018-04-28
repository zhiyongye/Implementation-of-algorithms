#include<iostream>
#include"SortTestHelper.h"

using namespace std;

//ѡ������ 
template<typename T>
void selectionSort(T arr[], int n) {
	
	for(int i=0; i<n; i++) {
		// Ѱ��[i, n)���������Сֵ
		int minIndex = i;
		for(int j=i+1; j<n; j++) {
			if(arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		} 
		
		//���� 
		swap( arr[i] , arr[minIndex] );
		
	}
	
	return;
}

//��������
template<typename T>
void insertionSort(T arr[], int n) {
	
	for(int i=1; i<n; i++) {
		
		/*
		// Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		for(int j=i; j>0 && arr[j]<arr[j-1]; j--) {
				swap(arr[j],arr[j-1]);     //���� 
		}
		*/
		
		/*
		//д���� 
		for(int j=i; j>0; j--) {
			if(arr[j]<arr[j-1]) 
				swap(arr[j],arr[j-1]);    //���� 
			else 
				break;
		}
		*/
		
		//д����
		//д��һ�Ͷ���������Ԫ�صĴ����࣬Ч�ʱȽ���
		T e = arr[i];
		int j;      // j����Ԫ��eӦ�ò����λ��
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
