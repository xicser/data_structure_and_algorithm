#ifndef __LIST_H__
#define __LIST_H__

//线性表元素类型
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

    void insertHead(ElemType elemt);    //头插法
    void traverse();                    //遍历

    //反转链表



    //快慢指针
    Node *getMiddleOrMiddleUp();        //奇数长度返回中点, 偶数长度返回上中点
    Node *comparatorGetMiddleOrMiddleUp();


    //回文判断:
    //用栈的方法特别简单, 笔试用
    //改变原链表的方法就需要注意边界了, 面使用
    bool detectionPalindrome();         //检测当前链表是否是回文

    //将单向链表按照某个值划分成左边小、中间相等、右边大的形式
    //把链表放入数组里, 在数组上做partition, 笔试用
    //用6个指针, 分成小, 中, 大三部分, 再把各个部分之间串起来, 面试用

    //



private:
    Node *head;         //链表头指针

};



#endif
