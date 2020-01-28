#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
	int key;
	struct Node *parent;
	Node* left, *right;

	Node(const int& _key) :key(_key), left(NULL), right(NULL), parent(NULL) {
	};
	void setLeft(Node* newNode) { left = newNode; }
	void setRight(Node* newNode) { right = newNode; }

};

void deleteNode(Node* node) {
	if (node->left) deleteNode(node->left);
	if (node->right) deleteNode(node->right);
	delete node;
}

//핵심은 계속해서 루트에서부터 내려오는 것
Node* compare(Node*node, int key) {
	if (node == NULL) {
		node = new Node(key);
	}
	else {
		if (node->key > key) {
			node->left = compare(node->left, key);
		}
		else {
			node->right = compare(node->right, key);
		}
	}
	return node;

}

void postOrder(Node* node) {
	if (node->left) postOrder(node->left);
	if (node->right) postOrder(node->right);
	cout << node->key << "\n";
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num;
	vector<int> v;
	while (cin >> num) {
		v.push_back(num);
	}
	Node *root = new Node(v[0]);
	int v_size = v.size();

	for (int i = 1; i < v_size; i++) {
		compare(root, v[i]);
	}
	postOrder(root);
	deleteNode(root);
	return 0;
}