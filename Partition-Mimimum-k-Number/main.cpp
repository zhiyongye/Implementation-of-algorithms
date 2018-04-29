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


// partition 过程, 和快排的partition一样
// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int left, int rigth) {
	
	srand(time(NULL));
	swap(arr[left], arr[rand()%(rigth-left+1)+left]);   //对于近乎有序的数字，随机选择一个数作为基准可以避免分区时所有数都被放在一边 
	
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

// 求出arr[l...r]范围里第k小的数
template<typename T>
int __select(T arr[], int left, int right, int k) {
	
	if (left == right) {
		return arr[left];
	}
	
	int p = __partition(arr, left, right);
	
	if (p == k) {                              // 如果 k == p, 直接返回arr[p]
		return arr[p];
	}else if (k < p) {                         // 如果 k < p, 只需要在arr[l...p-1]中找第k小元素即可
		return __select(arr, left, p-1, k);
	}else {                                   // 如果 k > p, 则需要在arr[p+1...r]中找第k-p-1小元素，传入的最后一个参数依然是k 
		return __select(arr, p+1, right, k);
	}
	
}

// 寻找arr数组中第k小的元素, k从0开始索引, 即最小元素是第0小元素, 以此类推
template<typename T>
int select(T arr[], int n, int k) {	
	
	assert( k >= 0 && k < n );
	
	return __select(arr, 0, n-1, k);
}


int main() {
	int n = 100;
	int * arr = SortTestHelper::generateRandomArray(n,0,n);
	SortTestHelper::printArray(arr,n);
	cout << select(arr, n, 8) << endl;
	insertionSort(arr, n);
	SortTestHelper::printArray(arr,n);
	
	delete[] arr;
		
	return 0;
}


