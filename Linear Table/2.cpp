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


// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
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

// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
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


// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
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


// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
status ListEmpty(LinkList L)
{
    if (L == NULL) return INFEASIBLE;
    else if (L->next == NULL) return TRUE;
    else return FALSE;
}

// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
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

// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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


// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
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


// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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



// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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


// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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


// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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


// 如果线性表L存在，依次显示线性表中的元素，返回OK；如果线性表L不存在，返回INFEASIBLE。
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

// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
status SaveList(int k,LinkList L[], char FileName[])
{
    if (L[k] == NULL) return INFEASIBLE;
    else
    {
        FILE* fp;
        LinkList a = L[k];
        fp = fopen(FileName, "w");
        a = a -> next;
        while (a)
        {
            fprintf(fp, "%d ", a->data);
            a = a->next;
        }
        fclose(fp);
        return OK;
    }
}


// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
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



int main() {
	ElemType op, j = 0, k;
	LinkList L[listsnum];
	LNode *p, **a ;
	for(j = 0; j < listsnum -1; j++)
	{
		L[j] = NULL;
	}
	j = 0;
	char Filename[100];

	printf("                      基于单链表的线性表基本操作演示系统\n");
	printf("               **********************************************\n");
	printf("               *              1.显示全部线性表              *\n");
	printf("               *              2.增加一个线性表              *\n");
	printf("               *              3.删除一个线性表              *\n");
	printf("               *              4.选择线性表                  *\n");
	printf("               *              5.文件操作                    *\n");
	printf("               *              0.退出系统                    *\n");
	printf("               **********************************************\n");
	printf("               请输入需要进行的操作：");
	scanf("%d", &op);
	while (op)
	{
		switch (op)
		{
		case 1:
			ElemType i;
			for (i = 0; i < listsnum - 1; i++)
			{
				if (L[0] == NULL) 
				{
					printf("系统暂无线性表,请先增加线性表\n");
					break;
				}
				if (L[i]) 
				{
					printf("\n第%d个线性表\n", i + 1);
					ListTraverse(L[i]);
				}
				
			}
			break;

		case 2:
			if (InitList(L[j]))
			{
				printf("%d号线性表创建成功！\n",j + 1);
				j++;
			}
			else printf("线性表创建失败！请稍候再试\n");
			break;

		case 3:
			k = 0;
			printf("请输入需要删除的线性表：");
			scanf("%d", &k);
			DestroyList(L[k - 1]);
			printf("%d号线性表删除成功！\n",k);//!!!!!
			break;

		case 4:
			printf("请选择一个线性表进行操作：");
			scanf("%d", &k);
			k--;
			if (L[k])
			{
				while (L[k]) {
					LL:
					printf("                                    单链表的基本操作 \n");
					printf("            ************************************************************\n");
					printf("            *    	  1. InitList             7. LocateElem            *\n");
					printf("            *    	  2. DestroyList          8. PriorElem             *\n");
					printf("            *    	  3. ClearList            9. NextElem              *\n");
					printf("            *    	  4. ListEmpty            10. ListInsert           *\n");
					printf("            *    	  5. ListLength           11. ListDelete           *\n");
					printf("            *    	  6. GetElem              12. ListTraverse         *\n");
					printf("            *   	  0. Exit                                          *\n");
					printf("            ************************************************************\n");
					printf("            请选择你的操作[0~12]:");
					scanf("%d", &op);
					switch (op) {
					case 0:
						goto L1;

					case 1:
						if (InitList(L[k]) == OK) printf("线性表创建成功！\n");
						else printf("线性表创建失败！\n");
						getchar(); getchar();
						break;

					case 2:
						if (DestroyList(L[k]) == OK) printf("线性表销毁成功！\n");
						else printf("线性表销毁失败！\n");
						getchar(); getchar();
						break;

					case 3:
						if (L[k] == NULL) InitList(L[k]);//确保L[m]存在，下同 
						if (ClearList(L[k]) == OK) printf("线性表清除成功！\n");
						getchar(); getchar();
						break;

					case 4:
						if (L[k] == NULL) InitList(L[k]);
						if (ListEmpty(L[k]) == TRUE) printf("线性表为空！\n");
						else printf("线性表不为空！\n");
						getchar(); getchar();
						break;

					case 5:
						if (L[k] == NULL) InitList(L[k]);
						printf("线性表的表长为%d！", ListLength(L[k]));
						getchar(); getchar();
						break;

					case 6:
						int x, y;
						if (L[k] == NULL) InitList(L[k]);
						printf("请输入你要查找元素的位置：");
						scanf("%d", &x);
						if (GetElem(L[k], x, y) == OK)
							printf("第%d个元素为%d！\n", x, y);
						else printf("%d上没有元素\n");
						getchar(); getchar();
						break;

					case 7:
						int f, e;
						if (L[k] == NULL) InitList(L[k]);
						printf("请输入你要查找的元素：");
						scanf("%d", &e);
						f = LocateElem(L[k], e);
						if (f) printf("%d是第%d个元素！", e, f);
						else printf("找不到此元素！");
						getchar(); getchar();
						break;

					case 8:
						int ee, xx;
						if (L[k] == NULL) InitList(L[k]);
						printf("请输入你要查找其前驱的元素：");
						scanf("%d", &ee);
						if (L[k] -> next -> data == ee)
						{
							printf("%d是首元素！",ee);
							break;
						}
						if (PriorElem(L[k], ee, xx) == OK) printf("%d的前驱是%d！\n", ee, xx);
						else printf("线性表不含%d！", ee);
						getchar(); getchar();
						break;

					case 9:
						int el, xl;
						if (L[k] == NULL) InitList(L[k]);
						printf("请输入你要查找其后继的元素：");
						scanf("%d", &el);
						p = L[k];
						while(p -> next != NULL)p = p -> next;
						if(p -> data == el)
						{
							printf("%d是尾元素！\n",el);
							break;
						}
						
						if (NextElem(L[k], el, xl) == OK) printf("%d的后继是%d！", el, xl);
						else printf("线性表不含%d！", el);
						getchar(); getchar();
						break;

					case 10:
						int loc, ele, ff;
						if (L[k] == NULL) InitList(L[k]);
						printf("请输入你要插入的位置：");
						scanf("%d", &loc);
						printf("请输入你要插入的元素：");
						scanf("%d", &ele);
						ff = ListInsert(L[k], loc, ele);
						if (ff == ERROR) printf("输入的位置不符合要求！");
						else if (ff == OVERFLOW) printf("溢出！");
						else printf("插入成功！");
						getchar(); getchar();
						break;

					case 11:
						int loca, elemn, fl;
						if (L[k] == NULL) InitList(L[k]);
						printf("请输入你要删除的位置：");
						scanf("%d", &loca);
						fl = ListDelete(L[k], loca, elemn);
						if (fl == ERROR) printf("输入的位置不符合要求！");
						else printf("删除成功，该元素的值为%d", elemn);
						getchar(); getchar();
						break;

					case 12:
						if (L[k] == NULL) InitList(L[k]);
						if (!ListTraverse(L[k])) printf("线性表是空表！\n");
						getchar(); getchar();
						break;

					default://确保输入的数字有意义 
						printf("\n----请输入[0~12]实现菜单功能");
						break;
					}//end of switch
				}//end of while
			}//end of if
         case 5:
			 Lab:
			 printf("                                   文件操作\n");
			 printf("               **********************************************\n");
			 printf("               *                1.存文件                    *\n");
			 printf("               *                2.读文件                    *\n");
			 printf("               *                0.返回上一级                *\n");
			 printf("               **********************************************\n");
			 printf("               请输入需要进行的操作：");
			 scanf("%d", &op);
			 switch (op)
			 {
			 case 0:
				 break;

			 case 1:
				 printf("请输入存入的文件名：");
				 scanf("%s", Filename);
				 printf("请输入存入的线性表：");
				 scanf("%d", &k);
				 if (SaveList(k-1, L, Filename) == OK)printf("存文件成功！\n");
				 else printf("存文件失败！请稍候再试\n");
				 break;

			 case 2:
				 printf("请输入读入的文件名：");
				 scanf("%s", Filename);
				 printf("请输入读入的线性表：");
				 scanf("%d", &k);
				 p = L[k - 1];
				 if (LoadList(L[k - 1], Filename) == OK)printf("读文件成功！\n");
				 else printf("读文件失败！请稍候再试\n");
				 break;

			 default:
				 printf("\n           请输入[0~2]实现菜单功能\n");
				 goto Lab;
			 }
			 break;

		 default:
			 printf("请输入0~12的数字\n");
			 goto LL;
		}
		
		L1:
		printf("                      基于单链表的线性表基本操作演示系统\n");
		printf("               **********************************************\n");
		printf("               *              1.显示全部线性表              *\n");
		printf("               *              2.增加一个线性表              *\n");
		printf("               *              3.删除一个线性表              *\n");
		printf("               *              4.选择线性表                  *\n");
		printf("               *              5.文件操作                    *\n");
		printf("               *              0.退出系统                    *\n");
		printf("               **********************************************\n");
		printf("               请输入需要进行的操作：");
		scanf("%d", &op);
	}//end of while
	
	printf("               欢迎下次使用本系统！\n");
	return 0;
}
