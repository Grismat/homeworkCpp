#ifndef TASK_8_1_DICTIONARY_H
#define TASK_8_1_DICTIONARY_H

#include <utility>
#include <stdexcept>

template <class Key, class Value>
class Dictionary {
using Element = std::pair<Key, Value>;
public:
    Dictionary()
        : mRoot(nullptr), mSize(0) {}
    ~Dictionary() {
        deleteSubtree(mRoot);
    }

    Dictionary(Dictionary& dictionary) = delete;
    Dictionary& operator=(Dictionary & dictionary) = delete;
    Dictionary& operator=(Dictionary && dictionary) = delete;

    Dictionary(Dictionary && dictionary) noexcept {
        deleteSubtree(mRoot);
        mSize = 0;
        mRoot = nullptr;

        std::swap(mSize, dictionary.mSize);
        std::swap(mRoot, dictionary.mRoot);
    }



    void addElementByKey(Key const& key, Value const& value) {
        Node* const newNode = new Node(key, value);
        addNode(mRoot, newNode);
    }

    bool isElementStored(Key const& key) const noexcept {
        return isNodeStored(mRoot, key);
    }

    Value getElementByKey(Key const& key) const {
        Node* node = getNodeByKey(mRoot, key);
        if (node == nullptr) {
            throw std::out_of_range("Element not found");
        }
        else {
            return node->data.second;
        }
    }

    void deleteElementByKey(Key const& key) {
        mRoot = deleteNodeByKey(mRoot, key);
    }

private:
    struct Node {
        Node() = default;
        Node(Key key, Value value)
            : data(std::move(Element(key, value))), leftChild(nullptr), rightChild(nullptr)
        {}

        Element data;
        Node* leftChild;
        Node* rightChild;
    };

    Node* mRoot;
    std::size_t mSize;

    void addNode(Node* & root, Node* const newNode) noexcept {
        if (root == nullptr) {
            root = newNode;
            mSize++;
            return;
        }

        if (newNode->data.first > root->data.first) {
            addNode(root->rightChild, newNode);
        }
        else if (newNode->data.first < root->data.first)  {
            addNode(root->leftChild, newNode);
        }
        else {
            root->data.second = newNode->data.second;
            delete newNode;
        }
    }

    bool isNodeStored(Node const* const root, Key const& key) const noexcept {
        if (root == nullptr) {
            return false;
        }

        if (key > root->data.first) {
            return isNodeStored(root->rightChild, key);
        }
        else if (key < root->data.first)  {
            return isNodeStored(root->leftChild, key);
        }
        else {
            return true;
        }
    }

    Node* getNodeByKey(Node* root, Key const& key) const noexcept {
        if (root == nullptr) {
            return nullptr;
        }

        if (key > root->data.first) {
            return getNodeByKey(root->rightChild, key);
        }
        else if (key < root->data.first) {
            return getNodeByKey(root->leftChild, key);
        }
        else {
            return root;
        }
    }

    Node* deleteNodeByKey(Node* node, Key const& key) {
        if (node == nullptr) {                                              //if tree is empty
            return nullptr;
        }

        if (key > node->data.first) {
            node->rightChild = deleteNodeByKey(node->rightChild, key);
            return node;
        }
        else if (key < node->data.first) {
            node->leftChild = deleteNodeByKey(node->leftChild, key);
            return node;
        }
        else {                                                            //found node to delete
            mSize--;
            if(node->rightChild == nullptr && node->leftChild == nullptr) {     //if node is a leaf
                delete node;
                return nullptr;
            }
            else if (node->leftChild == nullptr) {                              //if node has only right sibling
                delete node;
                return node->rightChild;
            }
            else if (node->rightChild == nullptr) {                             //if node has only left sibling
                delete node;
                return node->leftChild;
            }
            else {                                                              //the only case left when the node has both left and right subtrees
                Node* leastRightNode = findLeastRightNode(node->rightChild);

                Node* newNode = new Node();
                newNode->leftChild = node->leftChild;
                newNode->rightChild = node->rightChild;
                newNode->data = leastRightNode->data;

                deleteNodeByKey(node, leastRightNode->data.first);              //delete least right node
                delete node;

                return newNode;
            }
        }
    }

    Node* findLeastRightNode(Node* node) const noexcept {        //guaranteed that node != nullptr
        if (node->leftChild == nullptr) {
            return node;
        }
        return findLeastRightNode(node->leftChild);
    }

    void deleteSubtree(Node* node) noexcept {
        if (node->leftChild != nullptr) {
            deleteSubtree(node->leftChild);
        }

        if (node->rightChild != nullptr) {
            deleteSubtree(node->rightChild);
        }

        delete node;
    }
};

#endif //TASK_8_1_DICTIONARY_H