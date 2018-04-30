#include<iostream>
#include"SortTestHelper.h"
#include"MaxHead.h" 

using namespace std;


// heapSort1, 将所有的元素依次添加到堆中, 在将所有元素从堆中依次取出来, 即完成了排序
// 无论是创建堆的过程, 还是从堆中依次取出元素的过程, 时间复杂度均为O(nlogn)
// 整个堆排序的整体时间复杂度为O(nlogn)
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

// heapSort2, 借助heapify过程创建堆
// 此时, 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 实践复杂度为O(nlogn)
// 堆排序的总体时间复杂度依然是O(nlogn), 但是比上述heapSort1性能更优, 因为创建堆的性能更优
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

