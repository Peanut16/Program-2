#include "WordTree.h"
#include <iostream>

WordTree::WordTree() {
    m_root = nullptr;
    m_numberWords = 0;
}

void WordTree::printTreeInOrder() {
    printTreeInOrder(m_root);
}

void WordTree::printTreeInOrder(WordNode* node) {
    if (node == NULL)
        return;
    printTreeInOrder(node->m_left);
    std::cout << node->m_key << " ";
    printTreeInOrder(node->m_right);
}

void WordTree::insert(string key, int lineNumber) {
    m_root = insert(m_root, key, lineNumber);
}

WordNode* WordTree::insert(WordNode* node, string key, int lineNumber) {
    if (node == NULL) {
        node = new WordNode;
        node->m_key = key;
        node->m_left = NULL;
        node->m_right = NULL;
        node->m_parent = NULL;
        node->m_count = 1;
        node->m_lineNumbers.push_back(lineNumber);
    } else if (node->m_key < key) {
        node->m_right = insert(node->m_right, key, lineNumber);
        node->m_right->m_parent = node;
    } else if (node->m_key > key) {
        node->m_left = insert(node->m_left, key, lineNumber);
        node->m_left->m_parent = node;
    } else {
        node->m_count++;
        node->m_lineNumbers.push_back(lineNumber);
    }

    return node;
}

int WordTree::countWords() {
    return countWords(m_root);
}

int WordTree::countWords(WordNode* node) {
    if (node == NULL)
        return 0;
    return node->m_count + countWords(node->m_left) + countWords(node->m_right);
}

int WordTree::countUniqueWords() {
    return countUniqueWords(m_root);
}

int WordTree::countUniqueWords(WordNode* node) {
    if (node == NULL)
        return 0;
    return 1 + countUniqueWords(node->m_left) + countUniqueWords(node->m_right);
}

string WordTree::firstWord() {
    if (!m_root) return "Not found";
    return firstWord(m_root);
}

string WordTree::firstWord(WordNode* node) {
    while (node->m_left != NULL) {
        node = node->m_left;
    }
    return node->m_key;
}

string WordTree::lastWord() {
    if (!m_root) return "Not found";
    return lastWord(m_root);
}

string WordTree::lastWord(WordNode* node) {
    while (node->m_right != NULL) {
        node = node->m_right;
    }
    return node->m_key;
}

vector<int> WordTree::wordLines(string word) {
    WordNode* current = m_root;
    while (current) {
        if (word == current->m_key) return current->m_lineNumbers;
        current = (word < current->m_key) ? current->m_left : current->m_right;
    }
    return {};
}

vector<string> WordTree::mostFrequent() {
    vector<string> mostFrequentWords;
    int maxFrequency = 0;
    findMostFrequent(m_root, mostFrequentWords, maxFrequency);
    return mostFrequentWords;
}

void WordTree::findMostFrequent(WordNode* node, vector<string>& mostFrequentWords, int& maxFrequency) {
    if (node == nullptr) return;
    findMostFrequent(node->m_left, mostFrequentWords, maxFrequency);
    if (node->m_count > maxFrequency) {
        mostFrequentWords.clear();
        mostFrequentWords.push_back(node->m_key);
        maxFrequency = node->m_count;
    } else if (node->m_count == maxFrequency) {
        mostFrequentWords.push_back(node->m_key);
    }
    findMostFrequent(node->m_right, mostFrequentWords, maxFrequency);
}
