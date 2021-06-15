#ifndef __LIST_H__
#define __LIST_H__

//���Ա�Ԫ������
typedef char ElemType;

struct Node {
    struct Node *next;
    struct Node *random;
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

    //���ƴ���randomָ�������
    Node *copyListWithRand();

    //�������������л�Ҳ�����޻��ĵ�����, ͷ�ڵ�head1��head2
    //ʵ��һ������, ������������ཻ, �뷵���ཻ�ĵ�һ���ڵ�, ������뽻, ����null


    //����������Ƿ��л�, ���ҳ��뻷�ڵ�
    Node *getLoopNodeSet(Node *head);

    //����������Ƿ��л�, ���ҳ��뻷�ڵ�
    Node *getLoopNodeSF(Node *head);

    //��������޻������Ƿ��ཻ, �ཻʱ�����ཻ�ڵ�, ���򷵻�nullptr
    Node *check2NoLoopList(Node *head1, Node *head2);

    //��������л������Ƿ��ཻ, �ཻʱ�����ཻ�ڵ�, ���򷵻�nullptr
    Node *check2LoopList(Node *head1, Node *loop1, Node *head2, Node *loop2);

    //�����������Ƿ��ཻ
    Node *getIntersectNode(Node *head1, Node *head2);

private:
    Node *head;         //����ͷָ��

};



#endif
