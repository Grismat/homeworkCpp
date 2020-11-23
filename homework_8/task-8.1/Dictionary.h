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

    ~Dictionary() { //TODO: delete all nodes
        delete mRoot;
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

    bool deleteElementByKey(Key const& key) {
        return deleteNodeByKey(key);
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

    Node* getNodeByKey(Node* root, Key const& key) const {
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

    bool deleteNodeByKey(Node* parent, Node* node, Key const& key) {
        if (node == nullptr) {
            return true;
        }

        if (key > node->data.first) {
            return deleteNodeByKey(node, node->rightChild, key);
        }
        else if (key < node->data.first) {
            return deleteNodeByKey(node, node->leftChild, key);
        }
        else {
            return deleteNode(parent, node);
        }
    }

    bool deleteNode(Node* parent, Node* nodeToDelete) {
        if (parent == nullptr) {

        }

        if (nodeToDelete->rightChild == nullptr
                && nodeToDelete->leftChild == nullptr) {
            delete nodeToDelete;
        }
        else if (nodeToDelete->rightChild == nullptr) {
            delete nodeToDelete;
        }
    }
};

#endif //TASK_8_1_DICTIONARY_H
