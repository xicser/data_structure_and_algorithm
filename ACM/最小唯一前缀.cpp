#include <string>
#include <iostream>
#include <vector>

using namespace std;

//节点
class Node {
public:
    int pass;
    int end;
    Node* nexts[26];     //暂定所有的字符只包含26个小写字母

    Node(int pass, int end) {
        this->pass = pass;
        this->end = end;

        for (int i = 0; i < 26; i++) {
            nexts[i] = nullptr;
        }
    }
};

class PrefixTree
{
public:
    PrefixTree() {
        this->root = new Node(0, 0);
        allNodes.push_back(this->root);
    }

    void insertString(const string& str) {
        //空字符串别来捣乱
        if (str.length() == 0) {
            return;
        }

        //先让根节点的pass++
        this->root->pass++;
        Node* pCurNode = this->root;

        for (unsigned int i = 0; i < str.length(); i++) {
            int path = str[i] - 'a';

            //有没有这条路?
            if (pCurNode->nexts[path] == nullptr) {
                //生成新节点
                Node* nodeNew = new Node(1, 0);
                allNodes.push_back(nodeNew);
                pCurNode->nexts[path] = nodeNew;
                pCurNode = nodeNew;
            }
            else {
                pCurNode = pCurNode->nexts[path];
                pCurNode->pass++;
            }
        }
        pCurNode->end++;
    }
    
    string searchString(const string& str) {
        string result;
        Node* pCurNode = this->root;
        for (unsigned int i = 0; i < str.length(); i++) {
            int path = str[i] - 'a';

            result.push_back(str[i]);

            pCurNode = pCurNode->nexts[path];
            if (pCurNode->pass == 1) {
                break;
            }
        }

        return result;
    }

private:
    Node* root; //根节点
    vector<Node*> allNodes;
};
int main()
{
    int n;
    cin >> n;

    vector<string> inputStr(n);

    PrefixTree prefixTree;
    for (int i = 0; i < n; i++) {
        cin >> inputStr[i];
        prefixTree.insertString(inputStr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << prefixTree.searchString(inputStr[i]) << endl;
    }

    return 0;
}
