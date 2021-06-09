#ifndef __LIST_H__
#define __LIST_H__

//���Ա�Ԫ������
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

    void insertHead(ElemType elemt);    //ͷ�巨
    void traverse();                    //����

    //����ָ��
    Node *getMiddleOrMiddleUp();        //�������ȷ����е�, ż�����ȷ������е�

private:
    Node *head;         //����ͷָ��

};



#endif
