#ifndef __LIST_H__
#define __LIST_H__

//���Ա�Ԫ������
typedef char ElemType;

struct Node {
    struct Node *next;
    ElemType elemt;

    Node(ElemType elemt) {
        this->elemt = elemt;
    }
};

class List {

public:
    List();
    ~List();

    void insertHead(ElemType elemt);    //ͷ�巨
    void traverse();                    //����

    //��ת����



    //����ָ��
    Node *getMiddleOrMiddleUp();        //�������ȷ����е�, ż�����ȷ������е�
    Node *comparatorGetMiddleOrMiddleUp();


    //�����ж�:
    //��ջ�ķ����ر��, ������
    //�ı�ԭ����ķ�������Ҫע��߽���, ��ʹ��
    bool detectionPalindrome();         //��⵱ǰ�����Ƿ��ǻ���

    //������������ĳ��ֵ���ֳ����С���м���ȡ��ұߴ����ʽ
    //���������������, ����������partition, ������
    //��6��ָ��, �ֳ�С, ��, ��������, �ٰѸ�������֮�䴮����, ������

    //



private:
    Node *head;         //����ͷָ��

};



#endif
