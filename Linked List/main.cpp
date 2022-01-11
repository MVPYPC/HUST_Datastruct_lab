#include "def.h"

int main() {

	ElemType op, j = 0, k;
	LinkList L[listsnum];
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
				if (L[i]) 
				{
					printf("\n��%d�����Ա�\n", i + 1);
					ListTraverse(L[i]);
				}
				else
				{
					printf("ϵͳ�������Ա�,�����������Ա�\n");
					break;
				}
			}
			break;

		case 2:
			if (InitList(L[j]))
			{
				printf("%d�����Ա����ɹ���\n");
				j++;
			}
			else printf("���Ա���ʧ�ܣ����Ժ�����\n");
			break;

		case 3:
			k = 0;
			printf("��������Ҫɾ�������Ա�");
			scanf("%d", &k);
			if (DestroyList(L[k])) printf("%d�����Ա�ɾ���ɹ���\n");//!!!!!
			else printf("���Ա�ɾ��ʧ�ܣ����Ժ�����\n");
			break;

		case 4:
			printf("��ѡ��һ�����Ա���в�����");
			scanf("%d", &k);
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
						break;

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
						printf("\n----ListLength���ܴ�ʵ�֣�\n");
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
						if (PriorElem(L[k], ee, xx) == OK) printf("%d��ǰ����%d��", ee, xx);
						else printf("���Ա���%d��������Ԫ�أ�", ee);
						getchar(); getchar();
						break;

					case 9:
						int el, xl;
						if (L[k] == NULL) InitList(L[k]);
						printf("��������Ҫ�������̵�Ԫ�أ�");
						scanf("%d", &el);
						if (NextElem(L[k], el, xl) == OK) printf("%d�ĺ����%d��", el, xl);
						else printf("���Ա���%d������βԪ�أ�", el);
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
				 if (SaveList(L[k], Filename) == OK)printf("���ļ��ɹ���\n");
				 else printf("���ļ�ʧ�ܣ����Ժ�����");
				 break;

			 case 2:
				 printf("�����������ļ�����");
				 scanf("%s", Filename);
				 printf("�������������Ա�");
				 scanf("%d", &k);
				 if (LoadList( L[k], Filename) == OK)printf("���ļ��ɹ���\n");
				 else printf("���ļ�ʧ�ܣ����Ժ�����");
				 break;

			 default:
				 printf("\n----������[0~2]ʵ�ֲ˵�����");
				 goto Lab;
			 }
			 break;

		 case 0:
			 printf("��ӭ�´�ʹ�ñ�ϵͳ��\n");
			 return 0;

		 default:
			 printf("������0~12������\n");
			 goto LL;
		}
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
}