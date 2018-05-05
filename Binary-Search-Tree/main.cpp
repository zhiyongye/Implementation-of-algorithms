#include<iostream>
#include<ctime>> 
#include<vector>
#include<string>
#include<queue>
#include "SequenceST.h"
#include "FileOps.h"

using namespace std;

template<typename Key, typename Value>
class BST{
	
private:
	//二叉搜索树的节点结构体 
	struct Node{
		Key key;
		Value value;
		Node * left;
		Node * right;
		
		//构造方法，用于创建新节点 
		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}
		
		//构造方法，用于复制节点 
		Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
	};
	
	Node * root;   // 根节点
	int count;     // 节点个数

public:
	// 构造函数, 默认构造一棵空二分搜索树
	BST() {
		
		root = NULL;
		count = 0;
	}
	
	~BST() {
		destroy(root);
	}
	
	// 返回二分搜索树的节点个数
    int size(){
        return count;
    }

    // 返回二分搜索树是否为空
    bool isEmpty(){
        return count == 0;
    }
    
    // 向二叉搜索树中插入新的数据对(key, value)
	void insert(Key key, Value value) {
		root = insert(root, key, value);
	} 
	
	//查看二叉搜索树中是否含有键值key
	bool contain(Key key) {
		return contain(root, key);
	} 
	
	// 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
	Value * search(Key key) {
		return search(root, key);
	}
	
	// 二分搜索树的前序遍历
	void preOrder() {
	 	preOrder(root);
	}
	
	// 二分搜索树的中序遍历
	void inOrder() {
	 	inOrder(root);
	}
	 
	// 二分搜索树的中序遍历
	void postOrder() {
	 	postOrder(root);
	}
	
	// 二分搜索树的层序遍历
	void levelOrder() {
		queue<Node *> q;
		q.push(root);
		while ( !q.empty() ) {
			Node * node = q.front();
			q.pop();
			
			cout << node->key << endl;
			if (node->left != NULL) {
				q.push(node->left);
			}
			if (node->right != NULL) {
				q.push(node->right);
			}
			
		}
	}
	
	// 寻找二分搜索树的最小的键值
	Key mininum() {
		assert(count != 0);
		Node * node = mininum(root);
		
		return node->key;
	}
	
	// 寻找二分搜索树的最大的键值
	Key maxinum() {
		assert(count != 0);
		Node * node = maxinum(root);
		
		return node->key;
	}
	
	// 从二分搜索树中删除最小值所在节点
	void removeMin() {
		if (root != NULL) {
			root = removeMin(root);
		}
	}
	
	// 从二分搜索树中删除最大值所在节点
	void removeMax() {
		if (root != NULL) {
			root = removeMax(root);
		}
	}

	// 从二分搜索树中删除键值为key的节点
    void remove(Key key){
    	if (root != NULL) {
    		root = remove(root, key);
		}
    }

	
private:
	// 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
	Node * insert(Node * node, Key key, Value value) {
		if (node == NULL) {
			count++;
			return new Node(key, value);
		}
		
		if (node->key == key) {
			node->value = value;
		} else if (node->key > key) {
			node->left = insert(node->left, key, value);
		} else {
			node->right = insert(node->right, key, value);
		}
		
		return node;
	}
	
	// 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
	bool contain(Node *node, Key key) {
		if (node == NULL) {
			return false;
		}
		
		if (node->key == key) {
			return true;
		}else if (node->key > key) {
			return contain(node->left, key);
		}else {
			return contain(node->right, key);
		}
	}
	
	// 在以node为根的二分搜索树中查找key所对应的value, 递归算法
    // 若value不存在, 则返回NULL
	Value * search(Node *node, Key key) {
		if ( node == NULL) {
			return NULL;
		}
		
		if (node->key == key) {
			return &(node->value);
		} else if (node->key > key) {
			return search(node->left, key);
		} else {
			return search(node->right, key);
		}
	}
	
	// 对以node为根的二叉搜索树进行前序遍历, 递归算法
	void preOrder(Node * node) {
		if (node != NULL) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	
	// 对以node为根的二叉搜索树进行中序遍历, 递归算法
	void inOrder(Node * node) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}
	
	// 对以node为根的二叉搜索树进行后序遍历, 递归算法
	void postOrder(Node * node) {
		if (node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}
	
	// 释放以node为根的二分搜索树的所有节点
    // 采用后续遍历的递归算法
    void destroy(Node * node) {
    	if (node != NULL ) {
    		destroy(node->left);
    		destroy(node->right);
    		
			delete node;
    		count--;
		}
	}
	
	// 返回以node为根的二分搜索树的最小键值所在的节点
	Node * mininum(Node * node) {
		if (node->left == NULL ) {
			return node;
		}
		
		return mininum(node->left);
	}
	
	// 返回以node为根的二分搜索树的最大键值所在的节点
	Node * maxinum(Node * node) {
		if (node->right == NULL ) {
			return node;
		}
		
		return maxinum(node->right);
	}
	
	// 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根
	Node * removeMin(Node * node) {
		if (node->left == NULL) {
			Node * rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		
		node->left = removeMin(node->left); 
		return node;
	}
	
	// 删除掉以node为根的二分搜索树中的最大节点
    // 返回删除节点后新的二分搜索树的根
	Node * removeMax(Node * node) {
		if (node->right == NULL) {
			Node * leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}
		
		node->right = removeMax(node->right); 
		return node;
	}
	
	// 删除掉以node为根的二分搜索树中键值为key的节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
	Node * remove(Node * node, Key key) {
		if (node == NULL) {
			return NULL;
		}
		
		if (node->key == key) {
			if (node->left == NULL) {   // 待删除节点左子树为空的情况
				Node * rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			} else if (node->right == NULL) {  // 待删除节点右子树为空的情况
				Node *leftNode = node->left;
				delete node;
				count--;
				return leftNode; 
			} else {
				
				// 待删除节点左右子树均不为空的情况

           		// 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
           		// 用这个节点顶替待删除节点的位置
				/*
				Node * minNode = mininum(node->right);
				node->key = minNode->key;
				node->value = minNode->value;
				removeMin(node->right);
				return node;
				*/
				Node * successor = new Node(mininum(node->right));
				count++;
				successor->right = removeMin(node->right);
				successor->left = node->left;
				
				delete node;
				count--;
				
				return successor;
				
			}
			 
		}else if (node->key > key) {
			node->left = remove(node->left, key);
			return node;
		} else {
			node->right = remove(node->right, key);
			return node;
		}
	}

	
};

int main() {
	
	BST<int, int> bst = BST<int ,int>();
	srand(time(NULL));
	for (int i=0; i<20; i++) {
		bst.insert(rand()%100, i*10);
	}
	bst.preOrder();
	cout<< "中序:" << endl;
	bst.inOrder();
	cout<< "层次遍历：" << endl; 
	bst.levelOrder();
	
	bst.remove(bst.mininum());
	bst.remove(bst.maxinum());
	cout<< "删除后:" << endl;
	bst.inOrder();
	
	/*
	cout<< "最小值：" << bst.mininum() << endl;
	cout<< "最大值：" << bst.maxinum() << endl;
	bst.removeMin();
	bst.removeMax();
	cout<< "删除后：" << endl; 
	cout<< "最小值：" << bst.mininum() << endl;
	cout<< "最大值：" << bst.maxinum() << endl;
	*/
	 /*
	 // 使用圣经作为我们的测试用例
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // 测试顺序查找表 SST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }

	*/
	return 0;
} 
