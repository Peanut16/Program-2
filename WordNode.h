#ifndef WORDNODE_H
#define WORDNODE_H
#include <vector>
#include <string>
using namespace std;

class WordNode {
	public:
		string m_key;
		int m_count;
		vector <int> m_lineNumbers;
		WordNode* m_left;
		WordNode* m_right;
		WordNode* m_parent;

	protected:

	private:
};
#endif // WORDNODE_H
