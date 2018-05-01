#include<iostream> 
#include<cassert>
#include<ctime>
#include<typeinfo>
#include<cmath>
#include<string>

using namespace std;

template<typename Item>
class MaxIndexHead{

private:
	Item * data;     // ����������е�����
	int * indexs;    // ����������е�����
	int count;
	int capacity;
	
	//������Ϊk��Ԫ�����ϵ���ʹ�������ѵ�Ҫ�� 
	// ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
	void shiftUp(int k) {
		while (k>1 && data[indexs[k]]>data[indexs[k/2]]) {
			swap(indexs[k], indexs[k/2]);
			k /= 2;
		}
	}
	
	//������Ϊk��Ԫ�����µ���ʹ�������ѵ�Ҫ�� 
	void shiftDown(int k) {
		while (2*k <= count) {
			int j = 2*k;       
			if (j+1<=count && data[indexs[j]]<data[indexs[j+1]]) {
				j++;          
			}
			if (data[indexs[k]] >= data[indexs[j]]) {
				break;
			}
			swap(indexs[k], indexs[j]);
			k = j;
		}
	}
	
public:
	// ���캯��, ����һ���յ�������, ������capacity��Ԫ��
	MaxIndexHead(int capacity) {
		data = new Item[capacity+1];
		indexs = new int[capacity+1];
		count = 0;
		this->capacity = capacity;
	}
	
	~MaxIndexHead() {
		delete[] data;
		delete[] indexs;
	}
	
	// �����������е�Ԫ�ظ���
	int size() {
		return count;
	}
	
	 // ����һ������ֵ, ��ʾ���������Ƿ�Ϊ��
	bool isEmpty() {
		return count==0;
	}
	
	// ������������в���һ���µ�Ԫ��, ��Ԫ�ص�����Ϊi, Ԫ��Ϊitem
    // �����i���û�����,�Ǵ�0������
	void insert(int i, Item item) {
		assert(count+1 <= capacity);
		assert(i+1>=1 && i+1<=capacity);
		
		i+=1;
		data[i] = item;
		indexs[count+1] = i;
		count++;
		shiftUp(count);
	}
	
	//��������ȡ���Ѷ�Ԫ��, ���������洢���������
	Item extractMax() {
		assert( count > 0);
		
		Item max = data[indexs[1]];
		swap(indexs[1], indexs[count]);
		count--;
		shiftDown(1);
		
		return max;
		
	}
	
	// �������������ȡ���Ѷ�Ԫ�ص�����
	int extractMaxIndex() {
		assert( count > 0);
		
		int maxIndex = indexs[1]-1;
		swap(indexs[1], indexs[count]);
		count--;
		shiftDown(1);
		
		return maxIndex;
		
	}
	
	// ��ȡ����������еĶѶ�Ԫ��
    Item getMax(){
        assert( count > 0 );
        return data[indexs[1]];
    }

    // ��ȡ����������еĶѶ�Ԫ�ص�����
    int getMaxIndex(){
        assert( count > 0 );
        return indexs[1]-1;
    }

    // ��ȡ���������������Ϊi��Ԫ��
    Item getItem( int i ){
        assert( i + 1 >= 1 && i + 1 <= capacity );
        return data[i+1];
    }
    
     // �����������������Ϊi��Ԫ���޸�ΪnewItem
    void change( int i , Item newItem ) {
    	assert(i+1>=1 && i+1<=count);
    	
    	i += 1;
    	data[indexs[i]] = newItem;
    	
    	// �ҵ�indexes[j] = i, j��ʾdata[i]�ڶ��е�λ��
        // ֮��shiftUp(j), ��shiftDown(j)
    	for (int j=1; j<=count; j++) {
    		if (indexs[j] == i) {
    			shiftUp(j);
    			shiftDown(j);
    			break;
			}
		}
    	
	}
	
	//����α�����ӡ���ѵ�����Ԫ�� 
	void print() {
		cout<<"�ѵĴ�С��"<<size()<<endl;
		cout<<"�ѵ�Ԫ�أ�";
		for (int i=0; i<count; ++i) {
			cout <<	data[indexs[i+1]] << " ";
		}
		cout << endl;
	
	}
	
};

int main() {
	
	MaxIndexHead<int> maxindexhead = MaxIndexHead<int>(100);
	srand(time(NULL));
	for (int i=0; i<10; ++i) {
		maxindexhead.insert(i, rand()%100 );
	}
	maxindexhead.print();
	while ( !maxindexhead.isEmpty()) {
		cout << maxindexhead.extractMax() << " ";
	}
	cout << endl;
	
	return 0;
} 
