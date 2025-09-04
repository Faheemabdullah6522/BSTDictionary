#pragma once

#include <iostream>
#include <fstream>
#include <string>

template <typename K, typename V>
struct Node
{
    K key;
    V value;
    Node *left;
    Node *right;

    Node(const K &k, const V &v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

template <typename K, typename V>
class Dictionary
{
private:
    Node<K, V> *root;

    Node<K, V> *insertRec(Node<K, V> *node, const K &key, const V &value);
    Node<K, V> *findRec(Node<K, V> *node, const K &key) const;
    Node<K, V> *removeRec(Node<K, V> *node, const K &key);
    Node<K, V> *findMin(Node<K, V> *node) const;
    void inorder(Node<K, V> *node) const;

    void saveRec(Node<K, V> *node, std::ofstream &ofs) const;

public:
    Dictionary();

    void insert(const K &key, const V &value);
    V *find(const K &key);
    /
        void remove(const K &key);
    void show() const;

    void loadFromFile(const std::string &filename);
    void saveToFile(const std::string &filename) const;
};

#include "Dictionary.tpp"
