#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> nodeMap;

        Node dummy(-1);

        Node* pCur = head;
        Node* pCurNew = &dummy;

        // 先复制一份
        while (pCur != nullptr) {

            Node* newNode = new Node(pCur->val);
            newNode->next = nullptr;

            pCurNew->next = newNode;

            pCurNew = newNode;

            nodeMap[pCur] = newNode;

            pCur = pCur->next;
        }

        //再处理random指针
        pCur = head;
        while (pCur != nullptr) {
            Node* copy = nodeMap[pCur];
            copy->random = nodeMap[pCur->random];

            pCur = pCur->next;
        }

        return dummy.next;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

