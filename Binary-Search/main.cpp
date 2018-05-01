#include<iostream> 
#include<cassert>
#include<ctime>

using namespace std;


// ���ֲ��ҷ�,����������arr��,����target
// ����ҵ�target,������Ӧ������index
// ���û���ҵ�target,����-1
template<typename T>
int binarySearch(T arr[], int n,  T target) {
	
	int left = 0;
	int right = n-1;
	
	while (left <= right) {
		
		//int mid = (left+right)/2;
		// ��ֹ��������µ����������ʹ��������߼����mid
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

//�õݹ�ķ�ʽʵ�ֶ��ֲ��� 
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

    // ���Էǵݹ���ֲ��ҷ�
    clock_t startTime = clock();

    // �������ǵĴ���������[0...N)
    // ��[0...N)�������ֵʹ�ö��ֲ��ң����ս��Ӧ�þ������ֱ���
    // ��[N...2*N)�������ֵʹ�ö��ֲ��ң���Ϊ��Щ���ֲ���arr�У����Ϊ-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;
	
	 // ���Եݹ�Ķ��ֲ��ҷ�
    startTime = clock();

    // �������ǵĴ���������[0...N)
    // ��[0...N)�������ֵʹ�ö��ֲ��ң����ս��Ӧ�þ������ֱ���
    // ��[N...2*N)�������ֵʹ�ö��ֲ��ң���Ϊ��Щ���ֲ���arr�У����Ϊ-1
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
