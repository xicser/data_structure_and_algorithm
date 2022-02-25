#include <iostream>

using namespace std;

class MyLinkedList {
private:
    typedef struct Node_t {
        int val;
        Node_t *next, *prev;
        Node_t(int _val) {
            val = _val;
        }
    } Node_t;

    Node_t* fakeHead, *fakeTail;
    int listLen;

public:
    MyLinkedList() {
        this->fakeHead = new Node_t(-1);
        this->fakeTail = new Node_t(-1);

        this->fakeHead->next = fakeTail;
        this->fakeHead->prev = nullptr;

        this->fakeTail->prev = fakeHead;
        this->fakeTail->next = nullptr;

        this->listLen = 0;
    }
    ~MyLinkedList() {
        delete this->fakeHead;
        delete this->fakeTail;
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
        Node_t* next = fakeHead->next;

        fakeHead->next = newNode;
        newNode->prev = fakeHead;
        newNode->next = next;
        next->prev = newNode;

        this->listLen++;
    }

    void addAtTail(int val) {
        Node_t* newNode = new Node_t(val);
        Node_t* prev = fakeTail->prev;

        prev->next = newNode;
        newNode->prev = prev;
        newNode->next = fakeTail;
        fakeTail->prev = newNode;

        this->listLen++;
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
        Node_t* pCur = fakeHead->next;
        while (pCur != nullptr) {

            if (pos == index) {
                Node_t* newNode = new Node_t(val);
                Node_t* prev = pCur->prev;
                prev->next = newNode;
                newNode->prev = prev;
                newNode->next = pCur;
                pCur->prev = newNode;

                this->listLen++;
                return;
            }
            pos++;
            pCur = pCur->next;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= this->listLen || index < 0) {
            return;
        }

        int pos = 0;
        Node_t* pCur = fakeHead->next;
        while (pCur != nullptr) {

            if (pos == index) {
                Node_t* prev = pCur->prev;
                Node_t* next = pCur->next;
                delete pCur;

                prev->next = next;
                next->prev = prev;

                this->listLen--;
                return;
            }
            pos++;
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
