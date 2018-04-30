#include<iostream>
#include"SortTestHelper.h"
#include"MaxHead.h" 

using namespace std;


// heapSort1, �����е�Ԫ��������ӵ�����, �ڽ�����Ԫ�شӶ�������ȡ����, �����������
// �����Ǵ����ѵĹ���, ���ǴӶ�������ȡ��Ԫ�صĹ���, ʱ�临�ӶȾ�ΪO(nlogn)
// ���������������ʱ�临�Ӷ�ΪO(nlogn)
template<typename T>
void headSort(T arr[], int n) {
	
	MaxHead<T> maxhead = MaxHead<T>(n);
	
	for (int i=0; i<n; ++i ) {
		maxhead.insert(arr[i]);
	}
	
	for (int i=n-1; i>=0; i--) {
		arr[i] = maxhead.extractMax();
	}
}

// heapSort2, ����heapify���̴�����
// ��ʱ, �����ѵĹ���ʱ�临�Ӷ�ΪO(n), ������Ԫ�����δӶ���ȡ����, ʵ�����Ӷ�ΪO(nlogn)
// �����������ʱ�临�Ӷ���Ȼ��O(nlogn), ���Ǳ�����heapSort1���ܸ���, ��Ϊ�����ѵ����ܸ���
template<typename T>
void headSort2(T arr[], int n) {
	MaxHead<T> maxhead = MaxHead<T>(arr,n);
	
	for (int i=n-1; i>=0; i--) {
		arr[i] = maxhead.extractMax();
	}
}

int main() {
	int n = 100000;
	int * arr = SortTestHelper::generateRandomArray(n,0,n);
	int * arr2 = SortTestHelper::copyIntArray(arr,n);
	//int * arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
	//SortTestHelper::printArray(arr,n);
	//quickSort(arr,n);
	//SortTestHelper::printArray(arr,n);
	SortTestHelper::testSort("headSort",headSort,arr,n);
	SortTestHelper::testSort("headSort2",headSort2,arr2,n);

	
	delete[] arr;
	delete[] arr2;
		
	return 0;
}

