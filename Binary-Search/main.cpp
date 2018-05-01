#include<iostream> 
#include<cassert>
#include<ctime>

using namespace std;


// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
template<typename T>
int binarySearch(T arr[], int n,  T target) {
	
	int left = 0;
	int right = n-1;
	
	while (left <= right) {
		
		//int mid = (left+right)/2;
		// 防止极端情况下的整形溢出，使用下面的逻辑求出mid
		int mid = left + (right-left)/2;
		
		if(arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	
	return -1;
}

//用递归的方式实现二分查找 
template<typename T> 
int __binarySearch2(T arr[], int left, int right,  T target) {
	
	if( left > right ) {
		return -1;
	}
	
	int mid = left + (right-left)/2;
	
	if(arr[mid] == target) {
		return mid;
	} else if (arr[mid] < target) {
		return __binarySearch2(arr, mid+1, right, target);
	} else {
		return __binarySearch2(arr, left, mid-1, target);
	}
}

template<typename T>
int binarySearch2(T arr[], int n, T target){

    return __binarySearch2( arr , 0 , n-1, target);
}

int main() {
	
	 int n = 1000000;
    int* a = new int[n];
    for( int i = 0 ; i < n ; i ++ )
        a[i] = i;

    // 测试非递归二分查找法
    clock_t startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;
	
	 // 测试递归的二分查找法
    startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch2(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

    delete[] a;
	
	return 0;
} 
