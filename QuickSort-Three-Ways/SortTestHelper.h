#include<iostream>
#include<ctime>
#include<cassert>

using namespace std;

namespace SortTestHelper {
	
	// ������n��Ԫ�ص��������,ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
	int * generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);

		int *arr = new int[n];
		
		srand(time(NULL));
		for(int i=0; i<n; ++i ) {
			arr[i] = rand() % (rangeR-rangeL+1) + rangeL;
		}
		return arr;
	}
	
	// ������������a�е�����Ԫ�ص�һ���µ�����, �������µ�����
	int * copyIntArray(int * a, int n) {
		int * arr = new int[n];
		
		for(int i=0; i<n; ++i) {
			arr[i] = a[i];
		}
		
		return arr;
	} 
	
	// ����һ���������������
    // ��������һ������[0...n-1]����ȫ��������, ֮���������swapTimes������
    // swapTimes���������������̶�
    int *generateNearlyOrderedArray(int n, int swapTimes){

        int *arr = new int[n];
        for(int i = 0 ; i < n ; i ++ )
            arr[i] = i;

        srand(time(NULL));
        for( int i = 0 ; i < swapTimes ; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            swap( arr[posx] , arr[posy] );
        }

        return arr;
	}
	
	// ��ӡarr�������������
	template<typename T>
	void printArray(T arr[], int n) {
		for(int i=0; i<n; ++i) {
			cout<< arr[i] <<" ";
		}
		cout<<endl;
		
		return;
	}
	
	// �ж�arr�����Ƿ����򣬼�������Ƿ���ȷ
	template<typename T>
	bool isSorted(T arr[], int n) {
		for(int i=0; i<n-1; ++i) {
			if(arr[i] > arr[i+1])
				return false;
		}
		
		return true;
	} 
	
	// ����sort�����㷨����arr�������õ��������ȷ�Ժ��㷨����ʱ��
	template<typename T>
	void testSort(const string sortName,void(*sort)(T[],int n),T arr[], int n) {
		clock_t startTime = clock();
		sort(arr,n);
		clock_t endTime = clock();
		
		assert(isSorted(arr,n));
		cout<< sortName << ":" << double(endTime-startTime) / CLOCKS_PER_SEC << " s" <<endl;
		return;
	}
};
