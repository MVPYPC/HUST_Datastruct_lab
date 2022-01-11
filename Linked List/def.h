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
typedef int ElemType; //数据元素类型定义
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode {  //单链表（链式结构）结点的定义
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;


// 链表L不存在，构造一个空的链表，返回OK，否则返回INFEASIBLE。
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

// 如果链表L存在，销毁链表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
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


// 如果链表L存在，删除链表L中的所有元素，返回OK，否则返回INFEASIBLE。
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


// 如果链表L存在，判断链表L是否为空，空就返回TRUE，否则返回FALSE；如果链表L不存在，返回INFEASIBLE。
status ListEmpty(LinkList L)
{
    if (L == NULL) return INFEASIBLE;
    else if (L->next == NULL) return TRUE;
    else return FALSE;
}

// 如果链表L存在，返回链表L的长度，否则返回INFEASIBLE。
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

// 如果链表L存在，获取链表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果链表L不存在，返回INFEASIBLE。
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


// 如果链表L存在，查找元素e在链表L中的位置序号；如果e不存在，返回ERROR；当链表L不存在时，返回INFEASIBLE。
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


// 如果链表L存在，获取链表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果链表L不存在，返回INFEASIBLE。
status PriorElem(LinkList L, ElemType e, ElemType& pre)
{
    if (L == NULL) return INFEASIBLE;
    if (L->next == NULL) return ERROR;
    else if (L->next->next == NULL) return ERROR;//只有一个元素显然没有前驱 
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



// 如果链表L存在，获取链表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果链表L不存在，返回INFEASIBLE。
status NextElem(LinkList L, ElemType e, ElemType& next)
{
    if (L == NULL) return INFEASIBLE;
    if (L->next == NULL) return ERROR;
    else if (L->next->next == NULL) return ERROR;//只有一个元素显然没有后继 
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


// 如果链表L存在，将元素e插入到链表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果链表L不存在，返回INFEASIBLE。
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


// 如果链表L存在，删除链表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果链表L不存在，返回INFEASIBLE。
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


// 如果链表L存在，依次显示链表中的元素，返回OK；如果链表L不存在，返回INFEASIBLE。
status ListTraverse(LinkList L) {
    int i, length;
    LNode * p = L -> next;
    length = ListLength(L);
    printf("-------共%d个元素-------\n", length);
    for (i = 0; i < length; i++) {
        printf("第%d个元素：%d\n", i + 1, p->data);
        p = p->next;
    }
    printf("-------浏览结束-------\n");
    return OK;
}

// 如果链表L存在，将链表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
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


// 如果链表L不存在，将FileName文件中的数据读入到链表L中，返回OK，否则返回INFEASIBLE。
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