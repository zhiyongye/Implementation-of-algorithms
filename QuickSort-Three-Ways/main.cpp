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



// ��·���ŵĵݹ�ʵ�� 
template<typename T>
void __quickSort3Ways(T arr[], int left, int right) {
	
	// ����С��ģ����, ʹ�ò�����������Ż�
    if( right-left <= 15 ){
        insertionSort(arr, left, right);
        return;
    }
	
	srand(time(NULL));
	swap(arr[left], arr[rand()%(right-left+1)+left]);   //���ڽ�����������֣����ѡ��һ������Ϊ��׼���Ա������ʱ��������������һ�� 
	
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

// �Ƚ�Merge Sort��˫·�����������·�������������㷨������Ч��
// ���ڰ����д����ظ����ݵ�����, ��·�����о޴������
// ����һ���Ե��������ͽ������������, ��·���ŵ�Ч����Ȼ�������ŵ�, �������ڷǳ����Խ��ܵķ�Χ��
// ���, ��һЩ������, ��·������Ĭ�ϵ����Կ⺯����ʹ�õ������㷨������Java
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

