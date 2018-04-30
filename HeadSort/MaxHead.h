#include<iostream> 
#include<cassert>
#include<ctime>
#include<typeinfo>
#include<cmath>
#include<string>

using namespace std;

template<typename Item>
class MaxHead{

private:
	Item *data;
	int count;
	int capacity;
	
	//将第k个元素向上调整使满足最大堆的要求 
	void shiftUp(int k) {
		while (k>1 && data[k]>data[k/2]) {
			swap(data[k], data[k/2]);
			k /= 2;
		}
	}
	
	//将第k个元素向下调整使满足最大堆的要求 
	void shiftDown(int k) {
		while (2*k <= count) {
			int j = 2*k;       // 在此轮循环中,data[k]和data[j]交换位置
			if (j+1<=count && data[j]<data[j + 1]) {
				j++;           // data[j] 是 data[2*k]和data[2*k+1]中的最大值
			}
			if (data[k] >= data[j]) {
				break;
			}
			swap(data[k], data[j]);
			k = j;
		}
	}
	
public:
	// 构造函数, 构造一个空堆, 可容纳capacity个元素
	MaxHead(int capacity) {
		data = new Item[capacity+1];
		count = 0;
		this->capacity = capacity;
	}
	
	// 构造函数, 通过一个给定数组创建一个最大堆
    // 该构造堆的过程, 时间复杂度为O(n)
	MaxHead(Item arr[], int n) {
		data = new Item[n+1];
		this->capacity = n;
		for (int i=0; i<n; ++i) {
			data[i+1] = arr[i];
		}
		count = n;
		
		//Heapify过程 
		for (int i=count/2; i>=1; i--) {
			shiftDown(i);
		}
	}
	
	~MaxHead() {
		delete[] data;
	}
	
	// 返回堆中的元素个数
	int size() {
		return count;
	}
	
	 // 返回一个布尔值, 表示堆中是否为空
	bool isEmpty() {
		return count==0;
	}
	
	//向最大堆插入一个新元素item 
	void insert(Item item) {
		assert(count+1 <= capacity);
		data[count+1] = item;
		count++;
		shiftUp(count);
	}
	
	//从最大堆中取出堆顶元素, 即堆中所存储的最大数据
	Item extractMax() {
		assert( count > 0);
		
		Item max = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		
		return max;
		
	}
	
	//按层次遍历打印最大堆的数组元素 
	void print() {
		cout<<"堆的大小："<<size()<<endl;
		cout<<"堆的元素：";
		for (int i=0; i<count; ++i) {
			cout <<	data[i+1] << " ";
		}
		cout << endl;
	
	}
	
	
	
public:
    // 以树状打印整个堆结构
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }	
    
private:
    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
	
	
};

