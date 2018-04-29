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



// 三路快排的递归实现 
template<typename T>
void __quickSort3Ways(T arr[], int left, int right) {
	
	// 对于小规模数组, 使用插入排序进行优化
    if( right-left <= 15 ){
        insertionSort(arr, left, right);
        return;
    }
	
	srand(time(NULL));
	swap(arr[left], arr[rand()%(right-left+1)+left]);   //对于近乎有序的数字，随机选择一个数作为基准可以避免分区时所有数都被放在一边 
	
	T e = arr[left];
	int lt = left;     // arr[l+1...lt] < e
	int gt = right+1;  // arr[gt...r] > e
	int i = left+1;    // arr[lt+1...i) == e
	while ( i<gt ) {
		if (arr[i] < e) {
			lt++;
			swap(arr[lt], arr[i]);
			i++;
		}else if (arr[i] > e){
			gt--;
			swap(arr[gt], arr[i]);
		}else {      // arr[i] == e
			i++;
		}
	}
	swap(arr[left], arr[lt]);
	
	__quickSort3Ways(arr, left, lt-1);
	__quickSort3Ways(arr, gt, right);
}


template<typename T>
void quickSort3Ways(T arr[],int n) {
	
	__quickSort3Ways(arr,0,n-1);
	
	return;
}

// 比较Merge Sort和双路快速排序和三路快排三种排序算法的性能效率
// 对于包含有大量重复数据的数组, 三路快排有巨大的优势
// 对于一般性的随机数组和近乎有序的数组, 三路快排的效率虽然不是最优的, 但是是在非常可以接受的范围里
// 因此, 在一些语言中, 三路快排是默认的语言库函数中使用的排序算法。比如Java
int main() {
	int n = 100000;
	//int * arr = SortTestHelper::generateRandomArray(n,0,n);
	int * arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
	//SortTestHelper::printArray(arr,n);
	//quickSort(arr,n);
	//SortTestHelper::printArray(arr,n);
	SortTestHelper::testSort("insertionSort",insertionSort,arr,n);
	SortTestHelper::testSort("quickSort3Ways",quickSort3Ways,arr,n);

	
	delete[] arr;
		
	return 0;
}

