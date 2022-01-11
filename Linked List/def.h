#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define listsnum 100
#define _CRT_SECURE_NO_WARNINGS 1
typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode {  //��������ʽ�ṹ�����Ķ���
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;


// ����L�����ڣ�����һ���յ���������OK�����򷵻�INFEASIBLE��
status InitList(LinkList& L)
{
    if (L != NULL)
    {
        return INFEASIBLE;
    }
    LNode * p = (LinkList)malloc(sizeof(LNode));
    p->data = 0;
    p->next = NULL;
    L = p;
    return OK;
}

// �������L���ڣ���������L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
status DestroyList(LinkList& L)
{
    if (L == NULL)
        return INFEASIBLE;
    LNode* p = L, * q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    L = NULL;
    return OK;
}


// �������L���ڣ�ɾ������L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
status ClearList(LinkList& L)
{
    if (L == NULL)
        return INFEASIBLE;
    LNode* p = L->next, * q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    L->data = 0;
    L->next = NULL;
    return OK;
}


// �������L���ڣ��ж�����L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE���������L�����ڣ�����INFEASIBLE��
status ListEmpty(LinkList L)
{
    if (L == NULL) return INFEASIBLE;
    else if (L->next == NULL) return TRUE;
    else return FALSE;
}

// �������L���ڣ���������L�ĳ��ȣ����򷵻�INFEASIBLE��
int ListLength(LinkList L)
{
    if (L == NULL) return INFEASIBLE;
    ElemType n = 0;
    LNode* p = L;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

// �������L���ڣ���ȡ����L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR���������L�����ڣ�����INFEASIBLE��
status GetElem(LinkList L, int i, ElemType& e)
{
    if (L == NULL) return INFEASIBLE;
    LNode* p = L;
    ElemType n = 0;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    if (i > n || i < 1) return ERROR;
    for (n = 0, p = L; n < i; n++)
    {
        p = p->next;
    }
    e = p->data;
    return OK;
}


// �������L���ڣ�����Ԫ��e������L�е�λ����ţ����e�����ڣ�����ERROR��������L������ʱ������INFEASIBLE��
status LocateElem(LinkList L, ElemType e)
{
    if (L == NULL) return INFEASIBLE;
    LNode* p = L->next;
    ElemType i = 1;
    if (p == NULL)  return ERROR;
    while (p->data != e)
    {
        i++;
        p = p->next;
        if (p == NULL) return ERROR;
    }
    return i;
}


// �������L���ڣ���ȡ����L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR���������L�����ڣ�����INFEASIBLE��
status PriorElem(LinkList L, ElemType e, ElemType& pre)
{
    if (L == NULL) return INFEASIBLE;
    if (L->next == NULL) return ERROR;
    else if (L->next->next == NULL) return ERROR;//ֻ��һ��Ԫ����Ȼû��ǰ�� 
    LNode* p = L->next->next;
    LNode* q = L->next;
    while (p) {
        if (p->data == e) {
            pre = q->data;
            return OK;
        }
        q = q->next;
        p = p->next;
    }
    return ERROR;
}



// �������L���ڣ���ȡ����LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR���������L�����ڣ�����INFEASIBLE��
status NextElem(LinkList L, ElemType e, ElemType& next)
{
    if (L == NULL) return INFEASIBLE;
    if (L->next == NULL) return ERROR;
    else if (L->next->next == NULL) return ERROR;//ֻ��һ��Ԫ����Ȼû�к�� 
    LNode* p = L->next->next;
    LNode* q = L->next;
    while (p) {
        if (q->data == e) {
            next = p->data;
            return OK;
        }
        q = q->next;
        p = p->next;
    }
    return ERROR;
}


// �������L���ڣ���Ԫ��e���뵽����L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR���������L�����ڣ�����INFEASIBLE��
status ListInsert(LinkList& L, int i, ElemType e)
{
    if (L == NULL) return INFEASIBLE;
    if (i < 1) return ERROR;
    LNode* p = L, * q = p->next, * ist = (LNode*)malloc(sizeof(LNode));
    ElemType j = 1;
    for (p = L; j < i; j++)
    {
        p = q;
        q = p->next;
        if (q == NULL && i >= j + 2) return ERROR;
    }
    ist->data = e;
    ist->next = q;
    p->next = ist;
    return OK;
}


// �������L���ڣ�ɾ������L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR���������L�����ڣ�����INFEASIBLE��
status ListDelete(LinkList& L, int i, ElemType& e)
{
    if (L == NULL) return INFEASIBLE;
    int length = 0, j;
    LNode* p = L;
    while (p->next != NULL)
    {
        length++;
        p = p->next;
    }
    if (i < 1 || i > length) return ERROR;
    p = L;
    for (j = 1; j < i; j++) {
        p = p->next;
    }
    LNode* del = p->next;
    e = del->data;
    p->next = del->next;
    free(del);
    return OK;
}


// �������L���ڣ�������ʾ�����е�Ԫ�أ�����OK���������L�����ڣ�����INFEASIBLE��
status ListTraverse(LinkList L) {
    int i, length;
    LNode * p = L -> next;
    length = ListLength(L);
    printf("-------��%d��Ԫ��-------\n", length);
    for (i = 0; i < length; i++) {
        printf("��%d��Ԫ�أ�%d\n", i + 1, p->data);
        p = p->next;
    }
    printf("-------�������-------\n");
    return OK;
}

// �������L���ڣ�������L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
status SaveList(LinkList L, char FileName[])
{
    if (L == NULL) return INFEASIBLE;
    else
    {
        FILE* fp;
        fp = fopen(FileName, "w");
        L = L->next;
        while (L)
        {
            fprintf(fp, "%d ", L->data);
            L = L->next;
        }
        fclose(fp);
        return OK;
    }
}


// �������L�����ڣ���FileName�ļ��е����ݶ��뵽����L�У�����OK�����򷵻�INFEASIBLE��
status LoadList(LinkList& L, char FileName[])
{
    if (L != NULL) return INFEASIBLE;
    else
    {
        FILE* fp;
        LinkList p, q;
        L = (LinkList)malloc(sizeof(LNode));
        q = L;
        fp = fopen(FileName, "r");
        while (!feof(fp))
        {
            L->next = (LinkList)malloc(sizeof(LNode));
            fscanf(fp, "%d ", &L->next->data);
            L = L->next;
        }
        L->next = NULL;
        L = q;
        fclose(fp);
        return OK;
    }
}