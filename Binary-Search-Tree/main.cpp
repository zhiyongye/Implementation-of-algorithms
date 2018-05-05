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
	//�����������Ľڵ�ṹ�� 
	struct Node{
		Key key;
		Value value;
		Node * left;
		Node * right;
		
		//���췽�������ڴ����½ڵ� 
		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}
		
		//���췽�������ڸ��ƽڵ� 
		Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
	};
	
	Node * root;   // ���ڵ�
	int count;     // �ڵ����

public:
	// ���캯��, Ĭ�Ϲ���һ�ÿն���������
	BST() {
		
		root = NULL;
		count = 0;
	}
	
	~BST() {
		destroy(root);
	}
	
	// ���ض����������Ľڵ����
    int size(){
        return count;
    }

    // ���ض����������Ƿ�Ϊ��
    bool isEmpty(){
        return count == 0;
    }
    
    // ������������в����µ����ݶ�(key, value)
	void insert(Key key, Value value) {
		root = insert(root, key, value);
	} 
	
	//�鿴�������������Ƿ��м�ֵkey
	bool contain(Key key) {
		return contain(root, key);
	} 
	
	// �ڶ�����������������key����Ӧ��ֵ��������ֵ������, �򷵻�NULL
	Value * search(Key key) {
		return search(root, key);
	}
	
	// ������������ǰ�����
	void preOrder() {
	 	preOrder(root);
	}
	
	// �������������������
	void inOrder() {
	 	inOrder(root);
	}
	 
	// �������������������
	void postOrder() {
	 	postOrder(root);
	}
	
	// �����������Ĳ������
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
	
	// Ѱ�Ҷ�������������С�ļ�ֵ
	Key mininum() {
		assert(count != 0);
		Node * node = mininum(root);
		
		return node->key;
	}
	
	// Ѱ�Ҷ��������������ļ�ֵ
	Key maxinum() {
		assert(count != 0);
		Node * node = maxinum(root);
		
		return node->key;
	}
	
	// �Ӷ�����������ɾ����Сֵ���ڽڵ�
	void removeMin() {
		if (root != NULL) {
			root = removeMin(root);
		}
	}
	
	// �Ӷ�����������ɾ�����ֵ���ڽڵ�
	void removeMax() {
		if (root != NULL) {
			root = removeMax(root);
		}
	}

	// �Ӷ�����������ɾ����ֵΪkey�Ľڵ�
    void remove(Key key){
    	if (root != NULL) {
    		root = remove(root, key);
		}
    }

	
private:
	// ����nodeΪ���Ķ�����������, ����ڵ�(key, value), ʹ�õݹ��㷨
    // ���ز����½ڵ��Ķ����������ĸ�
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
	
	// �鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�, ʹ�õݹ��㷨
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
	
	// ����nodeΪ���Ķ����������в���key����Ӧ��value, �ݹ��㷨
    // ��value������, �򷵻�NULL
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
	
	// ����nodeΪ���Ķ�������������ǰ�����, �ݹ��㷨
	void preOrder(Node * node) {
		if (node != NULL) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	
	// ����nodeΪ���Ķ��������������������, �ݹ��㷨
	void inOrder(Node * node) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}
	
	// ����nodeΪ���Ķ������������к������, �ݹ��㷨
	void postOrder(Node * node) {
		if (node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}
	
	// �ͷ���nodeΪ���Ķ��������������нڵ�
    // ���ú��������ĵݹ��㷨
    void destroy(Node * node) {
    	if (node != NULL ) {
    		destroy(node->left);
    		destroy(node->right);
    		
			delete node;
    		count--;
		}
	}
	
	// ������nodeΪ���Ķ�������������С��ֵ���ڵĽڵ�
	Node * mininum(Node * node) {
		if (node->left == NULL ) {
			return node;
		}
		
		return mininum(node->left);
	}
	
	// ������nodeΪ���Ķ���������������ֵ���ڵĽڵ�
	Node * maxinum(Node * node) {
		if (node->right == NULL ) {
			return node;
		}
		
		return maxinum(node->right);
	}
	
	// ɾ������nodeΪ���Ķ����������е���С�ڵ�
    // ����ɾ���ڵ���µĶ����������ĸ�
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
	
	// ɾ������nodeΪ���Ķ����������е����ڵ�
    // ����ɾ���ڵ���µĶ����������ĸ�
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
	
	// ɾ������nodeΪ���Ķ����������м�ֵΪkey�Ľڵ�, �ݹ��㷨
    // ����ɾ���ڵ���µĶ����������ĸ�
	Node * remove(Node * node, Key key) {
		if (node == NULL) {
			return NULL;
		}
		
		if (node->key == key) {
			if (node->left == NULL) {   // ��ɾ���ڵ�������Ϊ�յ����
				Node * rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			} else if (node->right == NULL) {  // ��ɾ���ڵ�������Ϊ�յ����
				Node *leftNode = node->left;
				delete node;
				count--;
				return leftNode; 
			} else {
				
				// ��ɾ���ڵ�������������Ϊ�յ����

           		// �ҵ��ȴ�ɾ���ڵ�����С�ڵ�, ����ɾ���ڵ�����������С�ڵ�
           		// ������ڵ㶥���ɾ���ڵ��λ��
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
	cout<< "����:" << endl;
	bst.inOrder();
	cout<< "��α�����" << endl; 
	bst.levelOrder();
	
	bst.remove(bst.mininum());
	bst.remove(bst.maxinum());
	cout<< "ɾ����:" << endl;
	bst.inOrder();
	
	/*
	cout<< "��Сֵ��" << bst.mininum() << endl;
	cout<< "���ֵ��" << bst.maxinum() << endl;
	bst.removeMin();
	bst.removeMax();
	cout<< "ɾ����" << endl; 
	cout<< "��Сֵ��" << bst.mininum() << endl;
	cout<< "���ֵ��" << bst.maxinum() << endl;
	*/
	 /*
	 // ʹ��ʥ����Ϊ���ǵĲ�������
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // ���� BST
        time_t startTime = clock();

        // ͳ��ʥ�������дʵĴ�Ƶ
        // ע: �����Ƶͳ�Ʒ���Լ�ª, û�п��Ǻܶ��ı������е���������
        // ������ֻ�����ܲ�����
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // ���ʥ����godһ�ʳ��ֵ�Ƶ��
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // ����˳����ұ� SST
        startTime = clock();

        // ͳ��ʥ�������дʵĴ�Ƶ
        // ע: �����Ƶͳ�Ʒ���Լ�ª, û�п��Ǻܶ��ı������е���������
        // ������ֻ�����ܲ�����
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // ���ʥ����godһ�ʳ��ֵ�Ƶ��
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
