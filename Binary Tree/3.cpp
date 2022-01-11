#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define treesnum 100
#define _CRT_SECURE_NO_WARNINGS 1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define root T
#define name others
#define filename Filename
#define L T
#define NODENUMBER 100//��������ֵ 
typedef int ElemType; //����Ԫ�����Ͷ���
typedef int status;
typedef int KeyType;
typedef struct {
	KeyType  key;
	char others[20];
} TElemType; //������������Ͷ���

typedef struct BiTNode { //����������Ķ���
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
typedef BiTNode BTN;


status Dis_visit(char e);
void visit(BTN *T);
status InitBiTree(BiTree *T);
status CreateBiTree(BTN *&T);
status DestroyBiTree(BTN *&T);
status ClearBiTree(BTN *&T);
status BiTreeEmpty(BTN *T);
int BiTreeDepth(BTN *T);
BTN* LocateNode(BTN *T,int e);//e�ǹؼ���
status Assign(BTN *&T,BTN *&value); //�Ѽ򻯣��ؼ��ְ�����valueָ��Ľṹ����
BTN* GetParent(BTN *T,int e);//���ֵ�����˫��
BTN* GetSibling(BTN *T,int e);
status InsertNode(BTN *&T,int e,int LR,BTN *&c);
status DeleteNode(BTN *&T,int e);
status PreOrderTraverse(BTN *T);//�Ѽ򻯣��ǵݹ�
status InOrderTraverse(BTN *T);
status PostOrderTraverse(BTN *T);
void OneLevel(BTN *T,int h);//����һ��
status LevelOrderTraverse(BTN *T);
void read(BTN *&T,FILE *fp);
status ReadBiTree(BTN *&T);//���ļ�
status SaveBiTree(BTN *T);
status TreeDisplay(BiTree T,int depth,status (* visit)(char e));


int main() {
	ElemType op, j = 0, k, lr = 3;
	BiTree T[treesnum];
	BiTNode *pforassign=(BTN *)malloc(sizeof(BTN));
	BTN *pforsib=(BTN *)malloc(sizeof(BTN));
	BTN *pforloc=(BTN *)malloc(sizeof(BTN));
	BTN *pforins=(BTN *)malloc(sizeof(BTN));
	for(j = 0; j < treesnum -1; j++) T[j] = NULL;
	j = 0;
	char Filename[100];
	printf("                     ���ڶ������Ķ���������������ʾϵͳ\n");
	printf("               **********************************************\n");
	printf("               *              1.��ʾȫ��������              *\n");
	printf("               *              2.����һ��������              *\n");
	printf("               *              3.ɾ��һ��������              *\n");
	printf("               *              4.ѡ�������                  *\n");
	printf("               *              5.�ļ�����                    *\n");
	printf("               *              0.�˳�ϵͳ                    *\n");
	printf("               **********************************************\n");
	printf("               ��������Ҫ���еĲ�����");
	scanf("%d", &op);
	while (op) {
		switch (op) {
			case 1:
				ElemType i;
				for (i = 0; i < treesnum - 1; i++) {
					if (T[0] == NULL) {
						printf("               ϵͳ���޶�����,�������Ӷ�����\n");
						break;
					}
					if (T[i]) {
T1:
						printf("               **********************************************\n");
						printf("               *                 1.�������                 *\n");
						printf("               *                 2.�������                 *\n");
						printf("               *                 3.�������                 *\n");
						printf("               **********************************************\n");
						printf("               ��ѡ�����˳��");
						scanf("%d", &op);
						switch(op) {
							case 1:
								printf("\n               ��%d��������\n", i + 1);
								PreOrderTraverse(T[i]);
								break;

							case 2:
								printf("\n               ��%d��������\n", i + 1);
								InOrderTraverse(T[i]);
								break;

							case 3:
								printf("\n               ��%d��������\n", i + 1);
								PostOrderTraverse(T[i]);
								break;

							default:
								printf("               ����������1~3!\n");
								goto T1;
						}
					}
				}
				break;

			case 2:
				if (InitBiTree(&T[j])) printf("               %d�Ŷ����������ɹ���\n", ++j);
				else printf("               ����������ʧ�ܣ����Ժ�����\n");
				break;

			case 3:
				k = 0;
				printf("               ��������Ҫɾ���Ķ�������");
				scanf("%d", &k);
				DestroyBiTree(T[k - 1]);
				printf("               %d�Ŷ�����ɾ���ɹ���\n",k);//�����д�������
				break;

			case 4:
T4:
				printf("               ��ѡ��һ�����������в�����");
				scanf("%d", &k);
				if (T[--k]) {
					while (T[k]) {
LL:
						printf("                                            �� �� �� �� �� �� �� �� \n");
						printf("            ****************************************************************************************\n");
						printf("            *    	  1. CreateBiTree(����������)       8.InsertNode(������)                     *\n");
						printf("            *    	  2. DestroyBiTree�����ٶ�������    9.DeleteNode(ɾ�����)                     *\n");
						printf("            *    	  3. ClearBiTree����ն�������      10. PreOrderTraverse(����������ǵݹ�)     *\n");
						printf("            *    	  4. BiTreeDepth(���������)        11. InOrderTraverse(�������)              *\n");
						printf("            *    	  5. LocateNode(���ҽ��)           12. PostOrderTraverse(�������)            *\n");
						printf("            *    	  6. Assign(��㸳ֵ)               13. LevelOrderTraverse(�������)           *\n");
						printf("            *    	  7. GetSibling���ֵܽ�㣩         14. TreeDisplay(����ͼ�νṹ)              *\n");
						printf("            *   	  0. Exit                                                                      *\n");
						printf("            ****************************************************************************************\n");
						printf("            ��ѡ����Ĳ���[0~12]:");
						scanf("%d", &op);
						switch (op) {
							case 0:
								goto L1;

							case 1:
								if(CreateBiTree(T[k])) printf("               �����������ɹ���\n");
								else printf("               ����������ʧ�ܣ�\n");
								break;

							case 2:
								if (DestroyBiTree(T[k]) == OK) printf("               ���������ٳɹ���\n");
								else printf("               ����������ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 3:
								if (DestroyBiTree(T[k]) == OK) printf("               ����������ɹ���\n");
								getchar();
								getchar();
								break;

							case 4:
								printf("               �����������Ϊ%d��\n", BiTreeDepth(T[k]));
								getchar();
								getchar();
								break;

							case 5:
								int keyforlocate;
								printf("               ��������Ҫ���ҽ��Ĺؼ��֣�");
								scanf("%d",&keyforlocate);
								pforloc = LocateNode(T[k],keyforlocate);
								if(pforloc) {
									printf("               ���ҵ��������Ϣ���£�\n");
									visit(pforloc);
								} else printf("               δ�ҵ���\n");
								getchar();
								getchar();
								break;

							case 6:
								pforassign->lchild=NULL;
								pforassign->rchild=NULL;//��֤��ȫ
								printf("               ��������Ҫ��ֵ�Ľ��Ĺؼ��֣�");
								scanf("%d",&pforassign->data.key);
								printf("               ������������");
								scanf("%s",&pforassign->data.others);
								if(Assign(T[k],pforassign)) {
									printf("               ��ֵ��ɣ����ڸý����Ϣ���£�\n");
									visit(LocateNode(T[k],pforassign->data.key));
								} else printf("               δ�ҵ���\n");
								getchar();
								getchar();
								break;

							case 7:
								int keyforsib;
								printf("               ��������Ҫ�������ֵܵĽ���keyֵ��");
								scanf("%d",&keyforsib);
								pforsib = GetSibling(T[k],keyforsib);
								if(pforsib) {
									printf("               ���ҵ����ֵܽ����Ϣ���£�\n");
									visit(pforsib);
								} else printf("               δ�ҵ���\n");
								getchar();
								getchar();
								break;

							case 8:
								int keyforins;
								BTN * pForInsert;
								printf("               ��������Ҫ����Ľ��keyֵ(0��ʾ���ڵ�)��");
								scanf("%d",&keyforins);
								if(keyforins == 0) {
									pForInsert = (BiTNode*)malloc(sizeof(BiTNode));
									printf("               ��������Ҫ��ֵ�Ľ���keyֵ��");
									scanf("%d",&pForInsert -> data.key);
									printf("               ������others��");
									scanf("%s",pForInsert -> data.others);//�½������
									pForInsert -> rchild = T[k];
									T[k] = pForInsert;
									break;
								}
								lr=3;
								while(lr != 0 && lr != 1) {
									printf("               ������0�����ӣ���1���Һ���)��");
									scanf("%d",&lr);
								}
								pforins=(BTN *)malloc(sizeof(BTN));
								pforins -> lchild = NULL;
								pforins -> rchild = NULL;//��֤��ȫ
								printf("               ��������Ҫ��ֵ�Ľ���keyֵ��");
								scanf("%d",&pforins->data.key);
								printf("               ������others��");
								scanf("%s",&pforins->data.others);
								if(InsertNode(T[k],keyforins,lr,pforins)==OK) printf("               ������ɣ�\n");
								else printf("               ����ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 9:
								int keyfordel;
								printf("               ��������Ҫɾ���Ľ��Ĺؼ��֣�");
								scanf("%d",&keyfordel);
								if(DeleteNode(T[k],keyfordel)==OK) printf("               ɾ���ɹ���\n");
								else printf("               ɾ��ʧ�ܣ�");
								getchar();
								getchar();
								break;

							case 10:
								if(PreOrderTraverse(T[k])==OK) printf("               ǰ�������ɣ�\n");
								else printf("               ǰ�����ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 11:
								if(InOrderTraverse(T[k])==OK) printf("               ���������ɣ�\n");
								else printf("               �������ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 12:
								if(PostOrderTraverse(T[k])==OK) printf("               ���������ɣ�\n");
								else printf("               �������ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 13:
								if(LevelOrderTraverse(T[k])==OK) printf("               ���������ɣ�\n");
								else printf("               �������ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 14:
								if (!T[k]) {
									printf("                   �����������ڣ�\n");
									getchar();
									getchar();
									break;
								}
								if(BiTreeEmpty(T[k]) == OK)
									printf("                   ������Ϊ������\n");
								else {
									printf("                   �ö�����Ϊ:\n");
									TreeDisplay(T[k],1, Dis_visit);
								}
								getchar();
								getchar();
								break;

							default://ȷ�����������������
								printf("                   ������[0~14]ʵ�ֲ˵�����");
								break;
						}//end of switch
					}//end of while
				}//end of if
				else {
					printf("               %d�Ŷ����������ڣ����ȴ�����\n");
					goto T4;
				}

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
				switch (op) {
					case 0:
						break;

					case 1:
						if(ReadBiTree(T[k])==OK) printf("               ��ȡ�ɹ���\n");
						else printf("               ��ȡʧ�ܣ�\n");
						getchar();
						break;

					case 2:
						if(SaveBiTree(T[k])==OK) printf("               ����ɹ���\n");
						else printf("               ����ʧ�ܣ�\n");
						getchar();
						break;

					default:
						printf("\n               ������[0~2]ʵ�ֲ˵�����\n");
						goto Lab;
				}
				break;

			default:
				printf("               ������0~12������\n");
				goto LL;
		}

L1:
		printf("                     ���ڶ������Ķ���������������ʾϵͳ\n");
		printf("               **********************************************\n");
		printf("               *              1.��ʾȫ��������              *\n");
		printf("               *              2.����һ��������              *\n");
		printf("               *              3.ɾ��һ��������              *\n");
		printf("               *              4.ѡ�������                  *\n");
		printf("               *              5.�ļ�����                    *\n");
		printf("               *              0.�˳�ϵͳ                    *\n");
		printf("               **********************************************\n");
		printf("               ��������Ҫ���еĲ�����");
		scanf("%d", &op);
	}//end of while

	printf("               ��ӭ�´�ʹ�ñ�ϵͳ��\n");
	return 0;
}

/**
 * ��������: visit
 * ��ʼ������������T����
 * �������: ��ӡ������
 *
 */
/**
 * ��������: visit
 * �������: ��ӡ�ַ�e
 */
status Dis_visit(char e) {
	printf("%c",e);//���ε��øú�����������ӡ
}


void visit(BTN *T) {
	printf("               key��%d,others��%s\n",T->data.key,T->data.others);
}

/**
 * ��������: InitBiTree
 * ��ʼ������������T������
 * �������: �������������T
 *
 */
status InitBiTree(BiTree *T) {
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T) -> lchild = NULL;
	(*T) -> rchild = NULL;
	strcpy((*T) -> data.others,"#");
	(*T) -> data.key = 0;//��ʼ��������,������ָ��ָ���

	return OK;
}


/**
 * ��������: DestroyBiTree
 * ��ʼ������������T�Ѵ���
 * �������: ���ٶ�����T
 *
 */
status DestroyBiTree(BTN *&T) {

	free(T);
	T = NULL;
	return OK;
}

status ClearBiTree(BTN *&T) {
	if(T) {
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
	}
	InitBiTree(&T);
	return OK;
}


/**
 * ��������: CreateBiTree
 * ��ʼ������������T�Ѵ���
 * �������: ����������
 *ȡ���ڿα�,��������ڵ�ֵ������key��ǽڵ�
 */
status CreateBiTree(BTN *&T) {
	int definition;
	printf("               ����key�������ظ���Ϊ��������0��");
	scanf("%d",&definition);
	getchar();
	if(!definition) {
		T=NULL;
	} else {
		T=(BTN*)malloc(sizeof(BTN));
		T->data.key=definition;
		printf("               ����others��");
		scanf("%s",&T->data.others);
		getchar();
		getchar();
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}




/**
 * ��������: BiTreeEmpty
 * ��ʼ��������
 * �������: �������п�
 *
 */
status BiTreeEmpty(BTN *T) {
	if(T) return FALSE;
	else return TRUE;
}





/**
 * ��������: BiTreeDepth
 * ��ʼ������������T�Ѵ���
 * �������: ����T�����
 *
 */
status BiTreeDepth(BiTree T) {
	int depth = 0;
	if(T) {
		int lchilddepth = BiTreeDepth(T->lchild);
		int rchilddepth = BiTreeDepth(T->rchild);
		depth = (lchilddepth>=rchilddepth?(lchilddepth+1):(rchilddepth+1));
	}//ʹ�õݹ�,�õ��������������,���Ƚϴ�С,֮�󷵻��������
	return depth;
}


BiTNode* LocateNode(BiTNode *T,int e) {
	if (!T) return NULL;

	BTN *pForLocate=NULL;
	if(T->data.key==e) {
		pForLocate=T;
		return pForLocate;
	} else {
		pForLocate=LocateNode(T->lchild,e);
		if(pForLocate) 	return pForLocate;
		else {
			pForLocate=LocateNode(T->rchild,e);
			if(pForLocate) 	return pForLocate;
		}
	}
	return NULL;
}

status Assign(BTN *&T,BTN *&value) {
	BTN *locating=LocateNode(T,value->data.key);
	if(!locating) return ERROR;
	strcpy(locating->data.others,value->data.others);
	return OK;
}


BTN* GetParent(BTN *T,int e) {
	if (!T) return NULL;
	BTN *pForParent=NULL;

	if(!T->lchild && !T->rchild) return NULL;
	else if(!T->lchild) {
		if(T->rchild->data.key==e) {
			pForParent=T;
			return pForParent;
		}
	} else if(!T->rchild) {
		if(T->lchild->data.key==e) {
			pForParent=T;
			return pForParent;
		}
	} else if(T->lchild->data.key==e||T->rchild->data.key==e) {
		pForParent=T;
		return pForParent;
	}

	pForParent=GetParent(T->lchild,e);
	if(pForParent) 	return pForParent;
	pForParent=GetParent(T->rchild,e);
	if(pForParent) 	return pForParent;

	return NULL;
}

BTN* GetSibling(BTN *T,int e) {
	BTN *pforsib = GetParent(T,e);//��˫��
	if (!pforsib) return NULL;
	else if(!pforsib->lchild||!pforsib->rchild) return NULL;
	else if(pforsib->lchild->data.key==e) return pforsib->rchild;
	else if(pforsib->rchild->data.key==e) return pforsib->lchild;
	else return NULL;//���������ã���֤��ȫ��
}

status InsertNode(BTN *&T,int e,int LR,BTN *&c) {
	BTN *pforinsert=LocateNode(T,e);
	if(!pforinsert) return ERROR;//�ؼ���e�Ľ��e������
	else if(LR==0) {
		if(!pforinsert->lchild) {
			pforinsert->lchild=c;
		} else {
			BTN *inserttemp=pforinsert->lchild;
			pforinsert->lchild=c;
			c->rchild=inserttemp;
		}
		return OK;
	} else if(LR==1) {
		if(!pforinsert->rchild) {
			pforinsert->rchild=c;
		} else {
			BTN *inserttemp=pforinsert->rchild;
			pforinsert->rchild=c;
			c->rchild=inserttemp;
		}
		return OK;
	} else {
		printf("               LR��ֵӦΪ1��0");
		return ERROR;
	}

}

status DeleteNode(BTN *&T,int e) {
	BTN *pfordelpar=GetParent(T,e);//�丸ĸ�����ӽ�����һ������NULL
	BTN *pfordelete=NULL;
	if(!pfordelpar) return ERROR;//�ؼ���e�Ľ��e������
	if(pfordelpar->lchild && e==pfordelpar->lchild->data.key) { //������Ҫɾ���Ľ��
		pfordelete=pfordelpar->lchild;
		if(!pfordelete->lchild && !pfordelete->rchild) {
			free(pfordelete);
			pfordelpar->lchild=NULL;
		} else if(!pfordelete->rchild) {
			pfordelpar->lchild=pfordelete->lchild;
			free(pfordelete);
		} else if(!pfordelete->lchild) {
			pfordelpar->lchild=pfordelete->rchild;
			free(pfordelete);
		} else {
			BTN *rightest=pfordelete->lchild;
			while(rightest->rchild) rightest=rightest->rchild;
			rightest->rchild=pfordelete->rchild;
			pfordelete->rchild=NULL;
			pfordelpar->lchild=pfordelete->lchild;
			free(pfordelete);
		}
	}

	else { //�ҽ����Ҫɾ���ģ���Ϊ�������ҵĸ�ĸ������ֱ��else
		pfordelete=pfordelpar->rchild;
		if(!pfordelete->lchild && !pfordelete->rchild) {
			free(pfordelete);
			pfordelpar->rchild=NULL;
		} else if(!pfordelete->rchild) {
			pfordelpar->rchild=pfordelete->lchild;
			free(pfordelete);
		} else if(!pfordelete->lchild) {
			pfordelpar->rchild=pfordelete->rchild;
			free(pfordelete);
		} else {
			BTN *rightest=pfordelete->lchild;
			while(rightest->rchild) rightest=rightest->rchild;
			rightest->rchild=pfordelete->rchild;
			pfordelete->rchild=NULL;
			pfordelpar->rchild=pfordelete->lchild;
			free(pfordelete);
		}
	}
	return OK;
}

status PreOrderTraverse(BTN *T) { //�ǵݹ�
	BTN *stack[NODENUMBER];//����ָ��ջ���ռ任ʱ��
	int top=0;//ջ��
	BTN *pforPreT=T;
	do {
		while(pforPreT) {
			if(top==NODENUMBER-1) return OVERFLOW;//ջ��
			stack[top++]=pforPreT;//��ǰ�����ջ
			visit(pforPreT);
			pforPreT=pforPreT->lchild;
		}
		if(top) {
			top--;
			pforPreT=stack[top]->rchild;
		}
	} while(top||pforPreT);
	return OK;
}

status InOrderTraverse(BTN *T) {
	if(T) {
		InOrderTraverse(T->lchild);
		visit(T);
		InOrderTraverse(T->rchild);
	}
	return OK;
}

status PostOrderTraverse(BTN *T) {
	if(T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T);
	}
	return OK;
}

void OneLevel(BTN *T,int h) {
	if(T) {
		if(h==1) visit(T);
		else {
			OneLevel(T->lchild,h-1);
			OneLevel(T->rchild,h-1);
		}
	}
}

status LevelOrderTraverse(BTN *T) {
	if(!T) return ERROR;

	int d=BiTreeDepth(T);
	int i;
	for(i=1; i<=d; i++) {
		OneLevel(T,i);
	}
	return OK;
}

status TreeDisplay(BiTree T,int depth,status (* visit)(char e)) {
	if(!T) {
		printf("\n");
		return OK;
	}
	int i=0;
	for(; i<depth; i++)
		printf("                ");
	Dis_visit(*(T -> data.others));
	printf("\n");
	if(T->lchild||T->rchild) {
		TreeDisplay(T->lchild,depth+1,Dis_visit);
		TreeDisplay(T->rchild,depth+1,Dis_visit);
	}
	return OK;
}

void read(BTN *&T,FILE *fp) {
	int definition;
	fscanf(fp," %d ",&definition);
	if(!definition) T=NULL;
	else {
		T=(BTN*)malloc(sizeof(BTN));
		T->data.key=definition;

		fscanf(fp," %s ",&T->data.others);
		read(T->lchild,fp);
		read(T->rchild,fp);
	}
}

status ReadBiTree(BTN *&T) {
	FILE *fp;
	char filename[100];
	printf("               ����Ҫ��ȡ���ļ�����");
	scanf("%s",&filename);
	getchar();
	if ((fp=fopen(filename,"rb"))==NULL) {
		printf("               ��ȡ��������\n");
		return ERROR;
	}
	read(T,fp);

	fclose(fp);

	return OK;
}

status SaveBiTree(BTN *T) { //�ǵݹ����򴢴�
	FILE *fp;
	BTN *pforsave=T;
	BTN *stack[NODENUMBER];
	int top=0;
	char filename[100];
	printf("����Ҫ������ļ���: ");
	scanf("%s",&filename);

	if((fp=fopen(filename,"wb"))==NULL) {
		printf("�洢��������\n");
		return ERROR;
	}

	do {
		while(pforsave) {
			if(top==NODENUMBER-1) return OVERFLOW;//ջ��
			stack[top++]=pforsave;//��ǰ�����ջ
			fprintf(fp," %d ",pforsave->data.key);//���á� %d "��lr=3Ϊ���ڶ�ȡʱǰ���������ݲ������
			fprintf(fp," %s ",pforsave->data.name);
			pforsave=pforsave->lchild;
		}
		fprintf(fp," %d ",0);
		if(top) {
			top--;
			pforsave=stack[top]->rchild;
		}
	} while(top||pforsave);
	fprintf(fp," %d ",0);
	fclose(fp);
	return OK;
}




