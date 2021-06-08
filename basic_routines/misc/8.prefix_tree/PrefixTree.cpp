#include "PrefixTree.h"

PrefixTree::PrefixTree()
{
    this->root = new Node(0, 0);
    allNodes.push_back(this->root);
}

PrefixTree::~PrefixTree()
{
    cout << endl;
    //释放空间
    for (unsigned int i = 0; i < allNodes.size(); i++) {
        delete allNodes[i];
    }

    cout << this << " prefix tree deleted" << endl;
}

/* 添加一个字符串 */
void PrefixTree::insertString(string str)
{
    //空字符串别来捣乱
    if (str.length() == 0) {
        return;
    }

    //先让根节点的pass++
    this->root->pass++;
    Node *pCurNode = this->root;

    for (unsigned int i = 0; i < str.length(); i++) {
        int path = str[i] - 'a';

        //有没有这条路?
        if (pCurNode->nexts[path] == nullptr) {
            //生成新节点
            Node *nodeNew = new Node(1, 0);
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

void PrefixTree::deleteString(string str)
{
    //空字符串别来捣乱
    if (str.length() == 0) {
        return;
    }

    //检查该str是否存在
    if (searchStringCount(str) == 0) {
        return;
    }

    //先让根节点的pass--
    this->root->pass--;
    Node *pCurNode = this->root;

    for (unsigned int i = 0; i < str.length(); i++) {
        int path = str[i] - 'a';

        Node *pCurNodeTmp = pCurNode;       //先临时把上个节点的地址记录一下
        pCurNode = pCurNode->nexts[path];
        pCurNode->pass--;

        //已经没有后面的路径了, 直接删掉后面的所有节点
        if (pCurNode->pass == 0) {

            Node *pCurNodefirst = pCurNodeTmp;
            vector<Node *> nodes;
            for (unsigned int j = i; j < str.length(); j++) {
                int path = str[j] - 'a';
                pCurNodeTmp = pCurNodeTmp->nexts[path];
                //记录pCurNodeTmp
                nodes.push_back(pCurNodeTmp);
            }

            //表示该节点以下没有其他节点了
            pCurNodefirst->nexts[path] = nullptr;

            //释放空间
            for (unsigned int i = 0; i < nodes.size(); i++) {

                //从allNodes里面删除
                removeNodeFromList(nodes[i]);
                delete nodes[i];
            }

            return;
        }
    }
    pCurNode->end--;
}

/* 检查str之前被加入过几次 */
int PrefixTree::searchStringCount(string str)
{
    //空字符串别来捣乱
    if (str.length() == 0) {
        return 0;
    }

    Node *pCurNode = this->root;

    for (unsigned int i = 0; i < str.length(); i++) {
        int path = str[i] - 'a';

        //有没有这条路?
        if (pCurNode->nexts[path] == nullptr) {
            return 0;
        }
        else {
            pCurNode = pCurNode->nexts[path];
        }
    }

    return pCurNode->end;
}

/* 所有加入的字符串中, 有几个是以pre这个字符串作为前缀 */
int PrefixTree::prefixStringCount(string prefix)
{
    //空字符串别来捣乱
    if (prefix.length() == 0) {
        return 0;
    }

    Node *pCurNode = this->root;

    for (unsigned int i = 0; i < prefix.length(); i++) {
        int path = prefix[i] - 'a';

        //有没有这条路?
        if (pCurNode->nexts[path] == nullptr) {
            return 0;
        }
        else {
            pCurNode = pCurNode->nexts[path];
        }
    }

    return pCurNode->pass;
}

/* 移除allNodes里某个节点地址 */
void PrefixTree::removeNodeFromList(Node *nodePtr)
{
    for (vector<Node *>::iterator it = allNodes.begin(); it != allNodes.end(); it++) {
        if (nodePtr == *it) {
            allNodes.erase(it);
            return;
        }
    }
}
