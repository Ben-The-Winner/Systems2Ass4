#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <memory>
using namespace std;



template <typename T>
class Node {
public:
    T data;
    vector<shared_ptr<Node<T>>> children;

    Node(T val) : data(val) {}
    ~Node() {
        cout << "Deleting node with data: " << data << endl;
    }
};

template <typename T>
class Tree {
public:
    shared_ptr<Node<T>> root;
    int k;

    Tree(T rootData, int k=2) : k(k) {
        root = make_shared<Node<T>>(rootData);
    }

    // Destructor to delete the whole tree
    ~Tree() {
        deleteTree(root);
    }

    // Method to delete the tree recursively
    void deleteTree(shared_ptr<Node<T>>& node) {
        if (!node) return;
        for (auto& child : node->children) {
            deleteTree(child);
        }
        node.reset(); // Explicitly reset the shared_ptr
    }

    
    void add_root(T rootData) {
        auto newRoot = make_shared<Node<T>>(rootData);
        newRoot->children.push_back(root); // Set current root as a child of new root
        root = newRoot; // Update the root to the new root
    }

    
        
    shared_ptr<Node<T>> add_sub_node(shared_ptr<Node<T>> parent, T childData) {
        if (parent->children.size() <= k) {
            auto subNode = make_shared<Node<T>>(childData);
            parent->children.push_back(subNode);
            return subNode;
        } else {
            cout << "Cannot add more children. Maximum limit reached." << endl;
            return nullptr;
        }
    }


void preorder(shared_ptr<Node<T>> node, ostream& os) const {
        if (!node) 
            return;
        os << node->data << " ";
        if (!node->children.empty()) 
            preorder(node->children[0], os); // Left child
        if (node->children.size() > 1) 
            preorder(node->children[1], os); // Right child
    }

    // Postorder traversal helper function
    void postorder(shared_ptr<Node<T>> node, ostream& os) const {
        if (!node) 
            return;
        if (!node->children.empty()) 
            postorder(node->children[0], os); // Left child
        if (node->children.size() > 1) 
            postorder(node->children[1], os); // Right child
        os << node->data << " ";
    }

    // Inorder traversal helper function
    void inorder(shared_ptr<Node<T>> node, ostream& os) const {
        if (!node) 
            return;
        if (!node->children.empty()) 
            inorder(node->children[0], os); // Left child
        os << node->data << " ";
        if (node->children.size() > 1) 
            inorder(node->children[1], os); // Right child
    }

    // BFS traversal function
    void bfs(ostream& os) const {
        if (!root) return;

        queue<shared_ptr<Node<T>>> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            os << node->data << " ";

            for (const auto& child : node->children) {
                q.push(child);
            }
        }
    }

    // DFS traversal function
    void dfs(ostream& os) const {
        if (!root) return;

        stack<shared_ptr<Node<T>>> s;
        s.push(root);

        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            os << node->data << " ";

            // Push children to stack in reverse order for correct traversal
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                s.push(*it);
            }
        }
    }

    // Overload the << operator for preorder traversal
    friend ostream& operator<<(ostream& os, const Tree<T>& tree) {
        tree.preorder(tree.root, os);
        return os;
    }

    // Overload the % operator for BFS traversal
   friend ostream& operator%(ostream& os, const Tree<T>& tree) {
        tree.bfs(os);
        return os;
    }

    // Overload the & operator for DFS traversal
    friend ostream& operator&(ostream& os, const Tree<T>& tree) {
        tree.dfs(os);
        return os;
    }

    // Overload the >> operator for postorder traversal
    friend ostream& operator>>(ostream& os, const Tree<T>& tree) {
        tree.postorder(tree.root, os);
        return os;
    }

    // Overload the | operator for inorder traversal
    friend ostream& operator|(ostream& os, const Tree<T>& tree) {
        tree.inorder(tree.root, os);
        return os;
    }


    // Flatten the tree into an array (in-order traversal)
    void flatten(shared_ptr<Node<T>> node, vector<T>& arr) const {
        if (!node) return;
        if (!node->children.empty()) 
            flatten(node->children[0], arr); // Left child
        arr.push_back(node->data);
        if (node->children.size() > 1) 
            flatten(node->children[1], arr); // Right child
    }

    // Heapify the array to build a min-heap
    void heapify(vector<T>& arr, int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(arr, n, smallest);
        }
    }

    // Build the min-heap from the array
    void buildMinHeap(vector<T>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    // Method to convert the tree to a min-heap
    void myHeap() {
        vector<T> arr;
        flatten(root, arr); // Flatten the tree into an array
        buildMinHeap(arr); // Build the min-heap
        // Print the min-heap
        cout << "Min-heap array: ";
        for (const auto& val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }





};




