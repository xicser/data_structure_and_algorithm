#include <iostream>

using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {
        this->fakeHead = new Node_t(-1);
        this->fakeHead->next = nullptr;
        this->listLen = 0;
    }
    ~MyLinkedList() {
        delete this->fakeHead;
    }

    int get(int index) {

        if (index >= listLen || index < 0) {
            return -1;
        }

        Node_t* pCur = fakeHead->next;
        int pos = 0;
        while (pCur != nullptr) {
            if (pos == index) {
                return pCur->val;
            }
            pCur = pCur->next;
            pos++;
        }

        return -1;
    }

    void addAtHead(int val) {
        Node_t* newNode = new Node_t(val);
        newNode->next = fakeHead->next;
        fakeHead->next = newNode;
        this->listLen++;
    }

    void addAtTail(int val) {

        Node_t* pCur = fakeHead->next;

        while (pCur != nullptr) {

            Node_t* pNext = pCur->next;
            if (pNext == nullptr) {
                break;
            }
            else {
                pCur = pCur->next;
            }
        }

        if (pCur != nullptr) {
            Node_t* newNode = new Node_t(val);
            newNode->next = nullptr;
            pCur->next = newNode;
            this->listLen++;
        }
        else {
            Node_t* newNode = new Node_t(val);
            newNode->next = fakeHead->next;
            fakeHead->next = newNode;
            this->listLen++;
        }
    }

    void addAtIndex(int index, int val) {

        if (index == this->listLen) {
            addAtTail(val);
            return;
        }
        else if (index < 0) {
            addAtHead(val);
            return;
        }
        else if (index > this->listLen) {
            return;
        }

        int pos = 0;
        Node_t* prev = fakeHead;
        Node_t* pCur = fakeHead->next;
        while (pCur != nullptr) {

            if (pos == index) {
                Node_t* newNode = new Node_t(val);
                newNode->next = pCur;
                prev->next = newNode;
                this->listLen++;
                return;
            }
            pos++;
            prev = pCur;
            pCur = pCur->next;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= this->listLen || index < 0) {
            return;
        }

        int pos = 0;
        Node_t* prev = fakeHead;
        Node_t* pCur = fakeHead->next;
        while (pCur != nullptr) {

            if (pos == index) {
                Node_t* nodeNext = pCur->next;
                delete pCur;
                prev->next = nodeNext;
                this->listLen--;
                return;
            }
            pos++;
            prev = pCur;
            pCur = pCur->next;
        }
    }

    void printList() {
        Node_t* pCur = fakeHead->next;
        while (pCur != nullptr) {
            cout << pCur->val << " ";
            pCur = pCur->next;
        }
        cout << endl;
    }

private:
    typedef struct Node_t {
        int val;
        Node_t *next;
        Node_t(int _val) {
            val = _val;
        }
    } Node_t;

    Node_t* fakeHead;
    int listLen;
};

int main()
{
    MyLinkedList mylist;

    mylist.addAtIndex(1, 0);
    mylist.printList();

    cout << mylist.get(0) << endl;

//[[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]

    return 0;
}
