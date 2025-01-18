#include <iostream>
#include <string>
#include <algorithm>

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;
    
    Node(int value=0, Node* parent=nullptr) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = parent;
    }
};


class BST {
private:
    Node* insert_helper(Node* node, int value) {
        if (node == nullptr) {
            this->root = new Node(value);
            return this->root;
        }
        
        if (value > node->value) {
            if (node->right == nullptr) {
                node->right = new Node(value, node);
                return node->right;
            }
            return this->insert_helper(node->right, value);
        } else if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new Node(value, node);
                return node->left;
            }
            return this->insert_helper(node->left, value);
        }
        return node;
    }

    void print_helper(Node* node, int level=0) {
        if (node == nullptr) {
            return;
        }
        level += 4;
        print_helper(node->right, level);
        std::cout << std::endl;
        std::cout << std::string(level-4, ' ') << node->value << " ";
        print_helper(node->left, level);
    }
    
    bool search_helper(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        }
        return this->search_helper(node->left, value) || this->search_helper(node->right, value);
    }

    Node* find_node_helper(Node* node, int value) {
        if (node == nullptr || node->value == value) {
            return node;
        }
        if (value > node->value) {
            return this->find_node_helper(node->right, value);
        }
        return this->find_node_helper(node->left, value);
    }

    int remove_leaf(Node* node) {
        if ((node->left == nullptr) && (node->right == nullptr)) {
            int return_value = node->value;
            if (node->parent->right == node) {
                node->parent->right = nullptr;
            } else {
                node->parent->left = nullptr;
            }
            return return_value;
        }
    }

    int remove_one_child(Node* node){
        if (node->left == nullptr || node->right == nullptr){
            Node* child_node = nullptr;
            // If node has only right child
            if (node->left == nullptr) {
                child_node = node->right;
            }
            // If node has only left child
            if (node->right == nullptr) {
                child_node = node->left;
            }
            if (node == node->parent->right) {
                node->parent->right = child_node;
            }
            else if (node == node->parent->left) {
                node->parent->left = child_node;      
            }
            child_node->parent = node->parent;
            int return_value = node->value;
            node = nullptr;
            return return_value;
        }
    }

    int remove_helper(Node* node, int value) {
        if (node == nullptr) {
            return 0;
        }
        node = this->find_node_helper(node, value);
        // If node is a leaf node
        if (node->left == nullptr && node->right == nullptr){
            return this->remove_leaf(node);
        }
        // if node has only one child
        if (node->left == nullptr || node->right == nullptr) {
            return this->remove_one_child(node);
        }
        
        Node* successor = get_in_order_successor(this->find_node(value));
        int temp = successor->value;
        successor->value = node->value;
        node->value = temp;
        if (successor->right != nullptr) {
            return this->remove_one_child(successor);
        } else {
            return this->remove_leaf(successor);
        }
    }

    void mirror_helper(Node* node) {
        if (node == nullptr) {
            return;
        }
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        mirror_helper(node->left);
        mirror_helper(node->right);
    }

public:
    Node* root;
    
    BST(int value=0) {
        this->root = new Node(value);
    }
    
    Node* insert(int value) {
        return this->insert_helper(this->root, value);
    }
    
    bool search(int value) {
        return this->search_helper(this->root, value);
    }

    int remove(int value) {
        if (this->search(value)) {
            return this->remove_helper(this->root, value);
        }
        return -1;
    }

    void print() {
        print_helper(this->root);
        std::cout << std::endl;
        return;
    }

    Node* find_node(int value) {
        return this->find_node_helper(this->root, value);
    }

    Node* get_in_order_successor(Node* current) {
        if (current->right != nullptr) {
            current = current->right;
            while (current->left != nullptr) {
                current = current->left;
            }
            return current;
        }
        if (current->parent != nullptr) {
            current = current->parent;
            while (current->parent != nullptr && current->parent->left == current) {
                current = current->parent;
            }
        }   
        return current;
    }

    void mirror() {
        mirror_helper(this->root);
    }

};


int main()
{
    BST bst = BST(8);
    bst.insert(5);
    bst.insert(10);
    bst.insert(7);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);
    bst.insert(10);
    bst.print();
    std::cout << "bst.search(10) = " << bst.search(10) << std::endl;
    std::cout << "bst.search(99) = " << bst.search(99) << std::endl;
    bst.print();
    std::cout << "bst.remove(5) = " << bst.remove(5) << std::endl;
    bst.print();
    bst.mirror();
    std::cout << "After mirroring" << std::endl;
    bst.print();


    return 0;
}