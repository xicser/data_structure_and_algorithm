#include "PrefixTree.h"

PrefixTree::PrefixTree()
{
    this->root = new Node(0, 0);
    allNodes.push_back(this->root);
}

PrefixTree::~PrefixTree()
{
    cout << endl;
    //�ͷſռ�
    for (unsigned int i = 0; i < allNodes.size(); i++) {
        delete allNodes[i];
    }

    cout << this << " prefix tree deleted" << endl;
}

/* ���һ���ַ��� */
void PrefixTree::insertString(string str)
{
    //���ַ�����������
    if (str.length() == 0) {
        return;
    }

    //���ø��ڵ��pass++
    this->root->pass++;
    Node *pCurNode = this->root;

    for (unsigned int i = 0; i < str.length(); i++) {
        int path = str[i] - 'a';

        //��û������·?
        if (pCurNode->nexts[path] == nullptr) {
            //�����½ڵ�
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
    //���ַ�����������
    if (str.length() == 0) {
        return;
    }

    //����str�Ƿ����
    if (searchStringCount(str) == 0) {
        return;
    }

    //���ø��ڵ��pass--
    this->root->pass--;
    Node *pCurNode = this->root;

    for (unsigned int i = 0; i < str.length(); i++) {
        int path = str[i] - 'a';

        Node *pCurNodeTmp = pCurNode;       //����ʱ���ϸ��ڵ�ĵ�ַ��¼һ��
        pCurNode = pCurNode->nexts[path];
        pCurNode->pass--;

        //�Ѿ�û�к����·����, ֱ��ɾ����������нڵ�
        if (pCurNode->pass == 0) {

            Node *pCurNodefirst = pCurNodeTmp;
            vector<Node *> nodes;
            for (unsigned int j = i; j < str.length(); j++) {
                int path = str[j] - 'a';
                pCurNodeTmp = pCurNodeTmp->nexts[path];
                //��¼pCurNodeTmp
                nodes.push_back(pCurNodeTmp);
            }

            //��ʾ�ýڵ�����û�������ڵ���
            pCurNodefirst->nexts[path] = nullptr;

            //�ͷſռ�
            for (unsigned int i = 0; i < nodes.size(); i++) {

                //��allNodes����ɾ��
                removeNodeFromList(nodes[i]);
                delete nodes[i];
            }

            return;
        }
    }
    pCurNode->end--;
}

/* ���str֮ǰ����������� */
int PrefixTree::searchStringCount(string str)
{
    //���ַ�����������
    if (str.length() == 0) {
        return 0;
    }

    Node *pCurNode = this->root;

    for (unsigned int i = 0; i < str.length(); i++) {
        int path = str[i] - 'a';

        //��û������·?
        if (pCurNode->nexts[path] == nullptr) {
            return 0;
        }
        else {
            pCurNode = pCurNode->nexts[path];
        }
    }

    return pCurNode->end;
}

/* ���м�����ַ�����, �м�������pre����ַ�����Ϊǰ׺ */
int PrefixTree::prefixStringCount(string prefix)
{
    //���ַ�����������
    if (prefix.length() == 0) {
        return 0;
    }

    Node *pCurNode = this->root;

    for (unsigned int i = 0; i < prefix.length(); i++) {
        int path = prefix[i] - 'a';

        //��û������·?
        if (pCurNode->nexts[path] == nullptr) {
            return 0;
        }
        else {
            pCurNode = pCurNode->nexts[path];
        }
    }

    return pCurNode->pass;
}

/* �Ƴ�allNodes��ĳ���ڵ��ַ */
void PrefixTree::removeNodeFromList(Node *nodePtr)
{
    for (vector<Node *>::iterator it = allNodes.begin(); it != allNodes.end(); it++) {
        if (nodePtr == *it) {
            allNodes.erase(it);
            return;
        }
    }
}
