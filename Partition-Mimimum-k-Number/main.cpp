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


// partition ����, �Ϳ��ŵ�partitionһ��
// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int left, int rigth) {
	
	srand(time(NULL));
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

// ���arr[l...r]��Χ���kС����
template<typename T>
int __select(T arr[], int left, int right, int k) {
	
	if (left == right) {
		return arr[left];
	}
	
	int p = __partition(arr, left, right);
	
	if (p == k) {                              // ��� k == p, ֱ�ӷ���arr[p]
		return arr[p];
	}else if (k < p) {                         // ��� k < p, ֻ��Ҫ��arr[l...p-1]���ҵ�kСԪ�ؼ���
		return __select(arr, left, p-1, k);
	}else {                                   // ��� k > p, ����Ҫ��arr[p+1...r]���ҵ�k-p-1СԪ�أ���������һ��������Ȼ��k 
		return __select(arr, p+1, right, k);
	}
	
}

// Ѱ��arr�����е�kС��Ԫ��, k��0��ʼ����, ����СԪ���ǵ�0СԪ��, �Դ�����
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


