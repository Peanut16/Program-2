#ifndef WORDTREE_H
#define WORDTREE_H

#include "WordNode.h"
#include <string>
#include <vector>

using namespace std;

class WordTree {
public:
    WordTree(); 
    void insert(string word, int lineNumber);
    void printTreeInOrder();
    bool search(int count);
    int countUniqueWords();
    int countWords();
    string lastWord();
    string firstWord();
    vector<int> wordLines(string word);
    vector<string> mostFrequent();

protected:
    WordNode* insert(WordNode* node, string key, int lineNumber);
    void printTreeInOrder(WordNode* node);
    bool search(WordNode* node, int count);
    int countUniqueWords(WordNode* node);
    int countWords(WordNode* node);
    string lastWord(WordNode* node);
    string firstWord(WordNode* node);
    vector<int> wordLines(WordNode* node);
    void findMostFrequent(WordNode* node, vector<string>& mostFrequentWords, int& maxFrequency);

private:
    WordNode* m_root;
    int m_numberWords;
};

#endif // WORDTREE_H

