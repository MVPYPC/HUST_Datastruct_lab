#include "def.h"

int main() {

	ElemType op, j = 0, k;
	LinkList L[listsnum];
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
				if (L[i]) 
				{
					printf("\n第%d个线性表\n", i + 1);
					ListTraverse(L[i]);
				}
				else
				{
					printf("系统暂无线性表,请先增加线性表\n");
					break;
				}
			}
			break;

		case 2:
			if (InitList(L[j]))
			{
				printf("%d号线性表创建成功！\n");
				j++;
			}
			else printf("线性表创建失败！请稍候再试\n");
			break;

		case 3:
			k = 0;
			printf("请输入需要删除的线性表：");
			scanf("%d", &k);
			if (DestroyList(L[k])) printf("%d号线性表删除成功！\n");//!!!!!
			else printf("线性表删除失败，请稍候再试\n");
			break;

		case 4:
			printf("请选择一个线性表进行操作：");
			scanf("%d", &k);
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
						break;

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
						printf("\n----ListLength功能待实现！\n");
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
						if (PriorElem(L[k], ee, xx) == OK) printf("%d的前驱是%d！", ee, xx);
						else printf("线性表不含%d或它是首元素！", ee);
						getchar(); getchar();
						break;

					case 9:
						int el, xl;
						if (L[k] == NULL) InitList(L[k]);
						printf("请输入你要查找其后继的元素：");
						scanf("%d", &el);
						if (NextElem(L[k], el, xl) == OK) printf("%d的后继是%d！", el, xl);
						else printf("线性表不含%d或它是尾元素！", el);
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
				 if (SaveList(L[k], Filename) == OK)printf("存文件成功！\n");
				 else printf("存文件失败！请稍候再试");
				 break;

			 case 2:
				 printf("请输入读入的文件名：");
				 scanf("%s", Filename);
				 printf("请输入读入的线性表：");
				 scanf("%d", &k);
				 if (LoadList( L[k], Filename) == OK)printf("读文件成功！\n");
				 else printf("读文件失败！请稍候再试");
				 break;

			 default:
				 printf("\n----请输入[0~2]实现菜单功能");
				 goto Lab;
			 }
			 break;

		 case 0:
			 printf("欢迎下次使用本系统！\n");
			 return 0;

		 default:
			 printf("请输入0~12的数字\n");
			 goto LL;
		}
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
}