#ifndef __ORDER_STORAGE_H__
#define __ORDER_STORAGE_H__


#define LIST_INIT_SIZE  100		//˳�������Ԫ�ش洢�ռ�ĳ�ʼ������
#define LIST_INCREASE	10		//˳�������Ԫ�ش洢�ռ�ķ�������


//���Ա�Ԫ������
typedef int ElemType;

//����˳�������
typedef struct
{
	ElemType	*base;		    //����Ԫ�ش洢�ռ����ַ
	int          length;		//˳�����(��sizeof(ElemType)Ϊ��λ)
	int          size;			//��ǰ�洢�ռ�����(��sizeof(ElemType)Ϊ��λ)
}List;//ListΪ�ṹ������


int  CreateList(List *L, int n, void(*input)(ElemType *));//����˳���
int  LocateElem(List L, ElemType e, int(*compare)(ElemType *, ElemType *));//���Ա����
int  ListInsert(List *L, int i, ElemType e);//���Ա����
int  ListDelete(List *L, int i, ElemType *e);//���Ա�ɾ��
void ListTraverse(List L, void(*visit)(ElemType*));//���Ա����
int  InitList(List *L);//����һ���յ�˳���L
void DestroyList(List *L);//����˳���L
void ClearList(List *L);//�����Ա�L��Ϊ�ձ�
int  ListEmpty(List L);//������Ա�L�Ƿ�Ϊ�ձ�
int  ListLength(List L);//�������Ա�L��Ԫ�ظ����������Ա���
int  GetElem(List L, int i, ElemType *e);//��*e����L�еĵ�i������Ԫ��
int  PriorElem(List L, ElemType cur_e, ElemType *pre_e);//��*pre_e����cur_e��ǰ��
int  NextElem(List L, ElemType cur_e, ElemType *next_e);//��*next_e����cur_e�ĺ��

void Union(List *LA, List *LB);//���������ϵĲ�
//������������������Ϊ�����
void MergeList(List La, List Lb, List *Lc);





#endif
