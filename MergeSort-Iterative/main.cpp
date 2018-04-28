#include<iostream>
#include"SortTestHelper.h"

using namespace std;

// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename T>
void __merge(T arr[], int left, int mid, int right) {
	
	//����һ����ʱ�ռ� 
	T *temp = new T[right-left+1];
	for(int i=left; i<=right; ++i) 
		temp[i-left] = arr[i];     //ע��temp��arr��left��ƫ�� 
	
	int i = left;      //iָ����벿�ֵ���ʼ����λ��
	int j = mid+1;     //jָ���Ұ벿����ʼ����λ��
	for(int k=left; k<=right; ++k) {
	
		if(i > mid) {     // �����벿��Ԫ���Ѿ�ȫ���������
			arr[k] = temp[j-left];
			j++;
		}else if(j > right) {     // ����Ұ벿��Ԫ���Ѿ�ȫ���������
			arr[k] = temp[i-left];
			i++;
		}else if(temp[i-left] < temp[j-left]) {    // ��벿����ָԪ�� < �Ұ벿����ָԪ��
			arr[k] = temp[i-left];
			i++;
		}else{                                     // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
			arr[k] = temp[j-left];
			j++;
		}
	}
	
	delete[] temp;
	
	return;
}

// ʹ���Ե����ϵ����Ĺ鲢�����㷨
template<typename T>
void mergeSort(T arr[],int n) {
	
	for(int size=1; size<=n; size+=size) {
		for(int i=0; i<n-size; i+=size+size) {
			// �� arr[i...i+sz-1] �� arr[i+sz...i+2*sz-1] ���й鲢
			if( arr[i+size-1] > arr[i+size] ) {
				__merge(arr, i, i+size-1, min(i+size+size-1, n-1));
			} 
		}
	}
	
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
