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


// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
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

// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
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


// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
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


// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
status ListEmpty(LinkList L)
{
    if (L == NULL) return INFEASIBLE;
    else if (L->next == NULL) return TRUE;
    else return FALSE;
}

// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
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

// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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


// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
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


// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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



// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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


// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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


// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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


// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�����OK��������Ա�L�����ڣ�����INFEASIBLE��
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

// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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


// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
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

	printf("                      ���ڵ���������Ա����������ʾϵͳ\n");
	printf("               **********************************************\n");
	printf("               *              1.��ʾȫ�����Ա�              *\n");
	printf("               *              2.����һ�����Ա�              *\n");
	printf("               *              3.ɾ��һ�����Ա�              *\n");
	printf("               *              4.ѡ�����Ա�                  *\n");
	printf("               *              5.�ļ�����                    *\n");
	printf("               *              0.�˳�ϵͳ                    *\n");
	printf("               **********************************************\n");
	printf("               ��������Ҫ���еĲ�����");
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
					printf("ϵͳ�������Ա�,�����������Ա�\n");
					break;
				}
				if (L[i]) 
				{
					printf("\n��%d�����Ա�\n", i + 1);
					ListTraverse(L[i]);
				}
				
			}
			break;

		case 2:
			if (InitList(L[j]))
			{
				printf("%d�����Ա����ɹ���\n",j + 1);
				j++;
			}
			else printf("���Ա���ʧ�ܣ����Ժ�����\n");
			break;

		case 3:
			k = 0;
			printf("��������Ҫɾ�������Ա�");
			scanf("%d", &k);
			DestroyList(L[k - 1]);
			printf("%d�����Ա�ɾ���ɹ���\n",k);//!!!!!
			break;

		case 4:
			printf("��ѡ��һ�����Ա���в�����");
			scanf("%d", &k);
			k--;
			if (L[k])
			{
				while (L[k]) {
					LL:
					printf("                                    ������Ļ������� \n");
					printf("            ************************************************************\n");
					printf("            *    	  1. InitList             7. LocateElem            *\n");
					printf("            *    	  2. DestroyList          8. PriorElem             *\n");
					printf("            *    	  3. ClearList            9. NextElem              *\n");
					printf("            *    	  4. ListEmpty            10. ListInsert           *\n");
					printf("            *    	  5. ListLength           11. ListDelete           *\n");
					printf("            *    	  6. GetElem              12. ListTraverse         *\n");
					printf("            *   	  0. Exit                                          *\n");
					printf("            ************************************************************\n");
					printf("            ��ѡ����Ĳ���[0~12]:");
					scanf("%d", &op);
					switch (op) {
					case 0:
						goto L1;

					case 1:
						if (InitList(L[k]) == OK) printf("���Ա����ɹ���\n");
						else printf("���Ա���ʧ�ܣ�\n");
						getchar(); getchar();
						break;

					case 2:
						if (DestroyList(L[k]) == OK) printf("���Ա����ٳɹ���\n");
						else printf("���Ա�����ʧ�ܣ�\n");
						getchar(); getchar();
						break;

					case 3:
						if (L[k] == NULL) InitList(L[k]);//ȷ��L[m]���ڣ���ͬ 
						if (ClearList(L[k]) == OK) printf("���Ա�����ɹ���\n");
						getchar(); getchar();
						break;

					case 4:
						if (L[k] == NULL) InitList(L[k]);
						if (ListEmpty(L[k]) == TRUE) printf("���Ա�Ϊ�գ�\n");
						else printf("���Ա�Ϊ�գ�\n");
						getchar(); getchar();
						break;

					case 5:
						if (L[k] == NULL) InitList(L[k]);
						printf("���Ա�ı�Ϊ%d��", ListLength(L[k]));
						getchar(); getchar();
						break;

					case 6:
						int x, y;
						if (L[k] == NULL) InitList(L[k]);
						printf("��������Ҫ����Ԫ�ص�λ�ã�");
						scanf("%d", &x);
						if (GetElem(L[k], x, y) == OK)
							printf("��%d��Ԫ��Ϊ%d��\n", x, y);
						else printf("%d��û��Ԫ��\n");
						getchar(); getchar();
						break;

					case 7:
						int f, e;
						if (L[k] == NULL) InitList(L[k]);
						printf("��������Ҫ���ҵ�Ԫ�أ�");
						scanf("%d", &e);
						f = LocateElem(L[k], e);
						if (f) printf("%d�ǵ�%d��Ԫ�أ�", e, f);
						else printf("�Ҳ�����Ԫ�أ�");
						getchar(); getchar();
						break;

					case 8:
						int ee, xx;
						if (L[k] == NULL) InitList(L[k]);
						printf("��������Ҫ������ǰ����Ԫ�أ�");
						scanf("%d", &ee);
						if (L[k] -> next -> data == ee)
						{
							printf("%d����Ԫ�أ�",ee);
							break;
						}
						if (PriorElem(L[k], ee, xx) == OK) printf("%d��ǰ����%d��\n", ee, xx);
						else printf("���Ա���%d��", ee);
						getchar(); getchar();
						break;

					case 9:
						int el, xl;
						if (L[k] == NULL) InitList(L[k]);
						printf("��������Ҫ�������̵�Ԫ�أ�");
						scanf("%d", &el);
						p = L[k];
						while(p -> next != NULL)p = p -> next;
						if(p -> data == el)
						{
							printf("%d��βԪ�أ�\n",el);
							break;
						}
						
						if (NextElem(L[k], el, xl) == OK) printf("%d�ĺ����%d��", el, xl);
						else printf("���Ա���%d��", el);
						getchar(); getchar();
						break;

					case 10:
						int loc, ele, ff;
						if (L[k] == NULL) InitList(L[k]);
						printf("��������Ҫ�����λ�ã�");
						scanf("%d", &loc);
						printf("��������Ҫ�����Ԫ�أ�");
						scanf("%d", &ele);
						ff = ListInsert(L[k], loc, ele);
						if (ff == ERROR) printf("�����λ�ò�����Ҫ��");
						else if (ff == OVERFLOW) printf("�����");
						else printf("����ɹ���");
						getchar(); getchar();
						break;

					case 11:
						int loca, elemn, fl;
						if (L[k] == NULL) InitList(L[k]);
						printf("��������Ҫɾ����λ�ã�");
						scanf("%d", &loca);
						fl = ListDelete(L[k], loca, elemn);
						if (fl == ERROR) printf("�����λ�ò�����Ҫ��");
						else printf("ɾ���ɹ�����Ԫ�ص�ֵΪ%d", elemn);
						getchar(); getchar();
						break;

					case 12:
						if (L[k] == NULL) InitList(L[k]);
						if (!ListTraverse(L[k])) printf("���Ա��ǿձ�\n");
						getchar(); getchar();
						break;

					default://ȷ����������������� 
						printf("\n----������[0~12]ʵ�ֲ˵�����");
						break;
					}//end of switch
				}//end of while
			}//end of if
         case 5:
			 Lab:
			 printf("                                   �ļ�����\n");
			 printf("               **********************************************\n");
			 printf("               *                1.���ļ�                    *\n");
			 printf("               *                2.���ļ�                    *\n");
			 printf("               *                0.������һ��                *\n");
			 printf("               **********************************************\n");
			 printf("               ��������Ҫ���еĲ�����");
			 scanf("%d", &op);
			 switch (op)
			 {
			 case 0:
				 break;

			 case 1:
				 printf("�����������ļ�����");
				 scanf("%s", Filename);
				 printf("�������������Ա�");
				 scanf("%d", &k);
				 if (SaveList(k-1, L, Filename) == OK)printf("���ļ��ɹ���\n");
				 else printf("���ļ�ʧ�ܣ����Ժ�����\n");
				 break;

			 case 2:
				 printf("�����������ļ�����");
				 scanf("%s", Filename);
				 printf("�������������Ա�");
				 scanf("%d", &k);
				 p = L[k - 1];
				 if (LoadList(L[k - 1], Filename) == OK)printf("���ļ��ɹ���\n");
				 else printf("���ļ�ʧ�ܣ����Ժ�����\n");
				 break;

			 default:
				 printf("\n           ������[0~2]ʵ�ֲ˵�����\n");
				 goto Lab;
			 }
			 break;

		 default:
			 printf("������0~12������\n");
			 goto LL;
		}
		
		L1:
		printf("                      ���ڵ���������Ա����������ʾϵͳ\n");
		printf("               **********************************************\n");
		printf("               *              1.��ʾȫ�����Ա�              *\n");
		printf("               *              2.����һ�����Ա�              *\n");
		printf("               *              3.ɾ��һ�����Ա�              *\n");
		printf("               *              4.ѡ�����Ա�                  *\n");
		printf("               *              5.�ļ�����                    *\n");
		printf("               *              0.�˳�ϵͳ                    *\n");
		printf("               **********************************************\n");
		printf("               ��������Ҫ���еĲ�����");
		scanf("%d", &op);
	}//end of while
	
	printf("               ��ӭ�´�ʹ�ñ�ϵͳ��\n");
	return 0;
}
