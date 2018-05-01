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
	Item * data;     // 最大索引堆中的数据
	int * indexs;    // 最大索引堆中的索引
	int count;
	int capacity;
	
	//将索引为k的元素向上调整使满足最大堆的要求 
	// 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
	void shiftUp(int k) {
		while (k>1 && data[indexs[k]]>data[indexs[k/2]]) {
			swap(indexs[k], indexs[k/2]);
			k /= 2;
		}
	}
	
	//将第引为k的元素向下调整使满足最大堆的要求 
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
	// 构造函数, 构造一个空的索引堆, 可容纳capacity个元素
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
	
	// 返回索引堆中的元素个数
	int size() {
		return count;
	}
	
	 // 返回一个布尔值, 表示索引堆中是否为空
	bool isEmpty() {
		return count==0;
	}
	
	// 向最大索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
    // 传入的i对用户而言,是从0索引的
	void insert(int i, Item item) {
		assert(count+1 <= capacity);
		assert(i+1>=1 && i+1<=capacity);
		
		i+=1;
		data[i] = item;
		indexs[count+1] = i;
		count++;
		shiftUp(count);
	}
	
	//从最大堆中取出堆顶元素, 即堆中所存储的最大数据
	Item extractMax() {
		assert( count > 0);
		
		Item max = data[indexs[1]];
		swap(indexs[1], indexs[count]);
		count--;
		shiftDown(1);
		
		return max;
		
	}
	
	// 从最大索引堆中取出堆顶元素的索引
	int extractMaxIndex() {
		assert( count > 0);
		
		int maxIndex = indexs[1]-1;
		swap(indexs[1], indexs[count]);
		count--;
		shiftDown(1);
		
		return maxIndex;
		
	}
	
	// 获取最大索引堆中的堆顶元素
    Item getMax(){
        assert( count > 0 );
        return data[indexs[1]];
    }

    // 获取最大索引堆中的堆顶元素的索引
    int getMaxIndex(){
        assert( count > 0 );
        return indexs[1]-1;
    }

    // 获取最大索引堆中索引为i的元素
    Item getItem( int i ){
        assert( i + 1 >= 1 && i + 1 <= capacity );
        return data[i+1];
    }
    
     // 将最大索引堆中索引为i的元素修改为newItem
    void change( int i , Item newItem ) {
    	assert(i+1>=1 && i+1<=count);
    	
    	i += 1;
    	data[indexs[i]] = newItem;
    	
    	// 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
    	for (int j=1; j<=count; j++) {
    		if (indexs[j] == i) {
    			shiftUp(j);
    			shiftDown(j);
    			break;
			}
		}
    	
	}
	
	//按层次遍历打印最大堆的数组元素 
	void print() {
		cout<<"堆的大小："<<size()<<endl;
		cout<<"堆的元素：";
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
