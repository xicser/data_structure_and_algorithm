#ifndef __LIST_H__
#define __LIST_H__

//线性表元素类型
typedef int ElemType;

struct Node {
    struct Node *next;
    ElemType elemt;

    Node(ElemType elemt) {
        this->elemt = elemt;
    }
};

class List {

public:
    List(int limit);
    ~List();

    void insertHead(ElemType elemt);    //头插法
    void traverse();                    //遍历

    //快慢指针
    Node *getMiddleOrMiddleUp();        //奇数长度返回中点, 偶数长度返回上中点

private:
    Node *head;         //链表头指针

};



#endif
