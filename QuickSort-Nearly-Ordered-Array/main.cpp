#include<iostream>
#include"SortTestHelper.h"

using namespace std;


//��������
template<typename T>
void insertionSort(T arr[], int n) {
	
	for(int i=1; i<n; i++) {
		
		T e = arr[i];
		int j;      // j����Ԫ��eӦ�ò����λ��
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

// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int left, int rigth) {
	
	swap(arr[left], arr[rand()%(rigth-left+1)+left]);   //���ڽ�����������֣����ѡ��һ������Ϊ��׼���Ա������ʱ��������������һ�� 
	
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
	
	// ����С��ģ����, ʹ�ò�����������Ż�
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

