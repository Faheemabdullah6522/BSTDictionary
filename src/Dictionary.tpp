#pragma once

#include <sstream>
#include <algorithm>

template <typename K, typename V>
Dictionary<K, V>::Dictionary() : root(nullptr) {}

template <typename K, typename V>
Node<K, V> *Dictionary<K, V>::insertRec(Node<K, V> *node, const K &key, const V &value)
{
    if (!node)
    {

        return new Node<K, V>(key, value);
    }
    if (key < node->key)
    {
        node->left = insertRec(node->left, key, value);
    }
    else if (key > node->key)
    {
        node->right = insertRec(node->right, key, value);
    }
    else
    {

        node->value = value;
    }
    return node;
}

template <typename K, typename V>
void Dictionary<K, V>::insert(const K &key, const V &value)
{
    root = insertRec(root, key, value);
}

template <typename K, typename V>
Node<K, V> *Dictionary<K, V>::findRec(Node<K, V> *node, const K &key) const
{
    if (!node || node->key == key)
        return node;
    if (key < node->key)
        return findRec(node->left, key);
    return findRec(node->right, key);
}

template <typename K, typename V>
V *Dictionary<K, V>::find(const K &key)
{
    Node<K, V> *res = findRec(root, key);
    return res ? &(res->value) : nullptr;
}

template <typename K, typename V>
Node<K, V> *Dictionary<K, V>::findMin(Node<K, V> *node) const
{
    while (node && node->left)
        node = node->left;
    return node;
}

template <typename K, typename V>
Node<K, V> *Dictionary<K, V>::removeRec(Node<K, V> *node, const K &key)
{
    if (!node)
        return node;

    if (key < node->key)
    {
        node->left = removeRec(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = removeRec(node->right, key);
    }
    else
    {
        if (!node->left)
        {
            Node<K, V> *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node<K, V> *temp = node->left;
            delete node;
            return temp;
        }

        Node<K, V> *temp = findMin(node->right);

        node->key = temp->key;
        node->value = temp->value;

        node->right = removeRec(node->right, temp->key);
    }
    return node;
}

template <typename K, typename V>
void Dictionary<K, V>::remove(const K &key)
{
    root = removeRec(root, key);
}

template <typename K, typename V>
void Dictionary<K, V>::inorder(Node<K, V> *node) const
{
    if (!node)
        return;
    inorder(node->left);
    std::cout << node->key << " : " << node->value << '\n';
    inorder(node->right);
}

template <typename K, typename V>
void Dictionary<K, V>::show() const
{
    inorder(root);
}

template <typename K, typename V>
void Dictionary<K, V>::loadFromFile(const std::string &filename)
{
    std::ifstream ifs(filename);
    if (!ifs)
    {

        return;
    }

    std::string line;
    while (std::getline(ifs, line))
    {
        if (line.empty())
            continue;

        std::istringstream iss(line);
        K key;
        if (!(iss >> key))
            continue;

        std::string val;
        std::getline(iss, val);

        auto it = std::find_if_not(val.begin(), val.end(), ::isspace);
        if (it != val.end())
            val = std::string(it, val.end());
        else
            val.clear();

        insert(key, val);
    }
    ifs.close();
}

template <typename K, typename V>
void Dictionary<K, V>::saveRec(Node<K, V> *node, std::ofstream &ofs) const
{
    if (!node)
        return;
    saveRec(node->left, ofs);
    ofs << node->key << ' ' << node->value << '\n';
    saveRec(node->right, ofs);
}

template <typename K, typename V>
void Dictionary<K, V>::saveToFile(const std::string &filename) const
{
    std::ofstream ofs(filename, std::ofstream::trunc);
    if (!ofs)
    {
        std::cerr << "Warning: could not open file for saving: " << filename << '\n';
        return;
    }
    saveRec(root, ofs);
    ofs.close();
};
