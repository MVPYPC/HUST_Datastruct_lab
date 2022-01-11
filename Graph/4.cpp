#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define Gnum 100
typedef int status;
typedef int KeyType;
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef struct {
	KeyType  key;
	char others[20];
} VertexType; //顶点类型定义


typedef struct ArcNode {         //表结点类型定义
	int adjvex;              //顶点位置编号
	struct ArcNode* nextarc;	   //下一个表结点指针
} ArcNode;
typedef struct VNode {				//头结点及其数组类型定义
	VertexType data;       	//顶点信息
	ArcNode* firstarc;      	 //指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM];
typedef  struct {  //邻接表的类型定义
	AdjList vertices;     	 //头结点数组
	int vexnum, arcnum;   	  //顶点数、弧数
	GraphKind  kind;        //图的类型
} ALGraph;

void (*VisitFunc)(VertexType);
int visited[MAX_VERTEX_NUM];
void DFS(ALGraph G, int v);
int w;

status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]);
status DestroyGraph(ALGraph &G);
status LocateVex(ALGraph G,KeyType u);
status PutVex(ALGraph &G,KeyType u,VertexType value);
status FirstAdjVex(ALGraph G,KeyType u);
status NextAdjVex(ALGraph G,KeyType v,KeyType w);
status InsertVex(ALGraph &G,VertexType v);
status DeleteVex(ALGraph &G,KeyType v);
status InsertArc(ALGraph &G,KeyType v,KeyType w);
status DeleteArc(ALGraph &G,KeyType v,KeyType w);
void visit(VertexType v);
void DFS(ALGraph G, int v);
status DFSTraverse(ALGraph &G,void (*visit)(VertexType));
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));
void Putin(int VR[][2], ArcNode *p, int &k, int i);
status SaveGraph(ALGraph G,char FileName[]);
status LoadGraph(ALGraph &G, char FileName[]) ;

int main(void) {
	KeyType op, j = 0, j1 = 0, k = 0,i = 0,u,v,w;
	VertexType V[30],value;
	KeyType VR[100][2];
	ALGraph G[Gnum];
	char FileName[100];
	printf("                       基于邻接表的图表基本操作演示系统\n");
	printf("               **********************************************\n");
	printf("               *              1.显示全部图表                *\n");
	printf("               *              2.增加一个图表                *\n");
	printf("               *              3.删除一个图表                *\n");
	printf("               *              4.选择图表                    *\n");
	printf("               *              5.文件操作                    *\n");
	printf("               *              0.退出系统                    *\n");
	printf("               **********************************************\n");
	printf("               请输入需要进行的操作：");
	scanf("%d", &op);
	while (op) {
		switch (op) {
			case 1:
				if(!G[0].arcnum) {
					printf("               系统暂无图表，请先创建！\n");
					goto L1;
				}

				while(G[k].arcnum) {
T1:
					printf("               **********************************************\n");
					printf("               *                 1.深度优先遍历             *\n");
					printf("               *                 2.广度优先遍历             *\n");
					printf("               *                 0.返回上一级               *\n");
					printf("               **********************************************\n");
					printf("               请选择遍历顺序：");
					scanf("%d", &op);
					switch(op) {
						case 1:
							printf("\n               %d号图表\n", k + 1);
							DFSTraverse(G[k],visit);
							break;

						case 2:
							printf("\n               %d号图表\n", k + 1);
							BFSTraverse(G[k],visit);
							break;

						case 0:
							goto L1;

						default:
							printf("               请输入数字0~2!\n");
							goto T1;
					}


					k++;
				}
				break;


			case 2:
				G[j].arcnum = 1;
				G[j].vexnum = 0;
				G[j].kind = UDG;
				G[j].vertices[0].firstarc = NULL;
				G[j].vertices[0].data.key = 0;
				printf("               %d号图表创立成功!\n",++j);
				break;

			case 3:
				k = 0;
				printf("               请输入需要删除的图表：");
				scanf("%d", &k);
				DestroyGraph(G[k-1]);
				printf("               %d号图表删除成功！\n",k);//可能有错！！！！
				break;

			case 4:
T4:
				printf("               请选择一个图表进行操作：");
				scanf("%d", &k);
				if (G[--k].arcnum) {
					while (G[k].arcnum) {
LL:
						printf("                                             图 表 的 基 本 操 作 \n");
						printf("            ****************************************************************************************\n");
						printf("            *    	  1. Createraph(创建图表)            7. InsertVex(插入顶点)                    *\n");
						printf("            *    	  2. DestroyGraph（销毁图表）        8. DeleteVex(删除顶点)                    *\n");
						printf("            *    	  3. LocateVex（查找顶点）           9.InsertArc(插入弧)                       *\n");
						printf("            *    	  4. PutVex(顶点赋值)                10.DeleteArc(删除弧)                      *\n");
						printf("            *    	  5. FirstAdjVex(第一邻接点)         11. DFSTraverse(深度优先搜索遍历          *\n");
						printf("            *    	  6. NextAdjVex(下一邻接点)          12. BFSTraverse(广度优先搜索遍历)         *\n");
						printf("            *   	  0. Exit                            13. Adjacency List(邻接表)                *\n");
						printf("            ****************************************************************************************\n");
						printf("            请选择你的操作[0~12]:");
						scanf("%d", &op);
						switch (op) {
							case 0:
								goto L1;

							case 1:
								printf("               请输入数据：") ;
								do {
									scanf("%d%s",&V[i].key,V[i].others);
								} while(V[i++].key!=-1);
								i=0;
								do {
									scanf("%d%d",&VR[i][0],&VR[i][1]);
								} while(VR[i++][0]!=-1);
								if (CreateCraph(G[k],V,VR)==ERROR) printf("               输入数据错，无法创建\n");
								else printf("               %d号图表创建成功！\n",k + 1);
								break;

							case 2:
								if (DestroyGraph(G[k]) == OK) printf("               图表销毁成功！\n");
								else printf("               图表销毁失败！\n");
								getchar();
								getchar();
								break;

							case 3:
								printf("               请输入需要查找结点的key值：");
								scanf("%d",&u);
								i = LocateVex(G[k],u);
								if(i != -1) {
									printf("               查找成功！该结点信息为：\n");
									visit(G[k].vertices[i].data);
								} else printf("               查找失败！\n");
								getchar();
								getchar();
								break;

							case 4:
								printf("               请输入需要赋值的结点key值:");
								scanf("%d",&u);
								printf("               请输入赋值后的结点key值:");
								scanf("%d",&value.key);
								printf("               请输入赋值后的结点others值:");
								scanf("%s",value.others);
								if(PutVex(G[k],u,value)) {
									printf("赋值成功！现在该结点的信息为：\n");
									visit(G[k].vertices[LocateVex(G[k],value.key)].data);
								}else printf("赋值失败！\n");
								getchar();
								getchar();
								break;

							case 5:
								printf("               请输入你要查找第一邻接点结点的key值：");
								scanf("%d",&u);
								i = FirstAdjVex(G[k],u);
								if(i != -1) {
									printf("               已找到，第一邻接点信息如下：\n");
									visit(G[k].vertices[i].data);
								} else printf("               查找失败！\n");
								getchar();
								getchar();
								break;

							case 6:
								printf("               请输入你要查找下一邻接点结点的key值v：");
								scanf("%d",&v);
								printf("               请输入你要查找下一邻接点结点的key值w：");
								scanf("%d",&w);
								i = NextAdjVex(G[k], v, w);
								if(i != -1) {
									printf("               查找成功，v的邻接顶点相对于w的下一邻接顶点信息如下：\n");
									visit(G[k].vertices[i].data);
								} else printf("               查找失败！\n");
								getchar();
								getchar();
								break;

							case 7:
								int keyforsib;
								printf("               请输入你要插入的结点的key值：");
								scanf("%d",&value.key);
								printf("               请输入你要插入的结点的others：");
								scanf("%s",value.others);
								i = InsertVex(G[k],value);
								if(i == OK) {
									printf("               插入成功！\n");
								} else printf("               插入失败！\n");
								getchar();
								getchar();
								break;

							case 8:
								printf("               请输入你要删除的结点key值：");
								scanf("%d",&v);
								i = DeleteVex(G[k],v);
								if(i == OK) {
									printf("               删除成功！\n");
								} else printf("               删除失败！\n");
								getchar();
								getchar();
								break;

							case 9:
								printf("               请输入你要插入的弧头的key值：");
								scanf("%d",&v);
								printf("               请输入你要插入的弧尾的key值：");
								scanf("%d",&w);
								i = InsertArc(G[k],v,w);
								if(i == OK) printf("               插入弧成功！\n");
								else printf("               插入弧失败！");
								getchar();
								getchar();
								break;

							case 10:
								printf("               请输入你要删除的弧头的key值：");
								scanf("%d",&v);
								printf("               请输入你要删除的弧尾的key值：");
								scanf("%d",&w);
								i = DeleteArc(G[k],v,w);
								if(i == OK) printf("               删除弧成功！\n");
								else printf("               删除弧失败！");
								getchar();
								getchar();
								break;

							case 11:
								DFSTraverse(G[k],visit);
								printf("               深度优先搜索遍历完成！\n");
								getchar();
								getchar();
								break;

							case 12:
								BFSTraverse(G[k],visit);
								printf("               广度优先搜索遍历完成！\n");
								getchar();
								getchar();
								break;

							case 13:
								for(i=0; i<G[k].vexnum; i++) {
									ArcNode *p=G[k].vertices[i].firstarc;
									printf("               %d %s",G[k].vertices[i].data.key,G[k].vertices[i].data.others);
									while (p) {
										printf(" %d",p->adjvex);
										p=p->nextarc;
									}
									printf("\n");
								}
								break;

							default://确保输入的数字有意义
								printf("                   请输入[0~14]实现菜单功能");
								break;
						}//end of switch
					}//end of while
				}//end of if
				else printf("%d号图表未创建！\n");
				goto L1;

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
				switch (op) {
					case 0:
						break;

					case 1:
						printf("请输入存入的文件名：");
						scanf("%s", FileName);
						printf("请输入存入的图表：");
						scanf("%d", &k);
						if (SaveGraph(G[--k],FileName) == OK)printf("存文件成功！\n");
						else printf("存文件失败！请稍候再试\n");
						break;

					case 2:
						printf("请输入读入的文件名：");
						scanf("%s", FileName);
						printf("请输入读入的图表：");
						scanf("%d", &k);
						/*-if (*/LoadGraph(G[k - 1],FileName);/* == OK)*/printf("读文件成功！\n");
						//else printf("读文件失败！请稍候再试\n");
						break;

					default:
						printf("\n           请输入[0~2]实现菜单功能\n");
						goto Lab;
				}
				break;

			default:
				printf("               请输入0~12的数字\n");
				goto LL;
		}

L1:
		printf("                       基于邻接表的图表基本操作演示系统\n");
		printf("               **********************************************\n");
		printf("               *              1.显示全部图表                *\n");
		printf("               *              2.增加一个图表                *\n");
		printf("               *              3.删除一个图表                *\n");
		printf("               *              4.选择图表                    *\n");
		printf("               *              5.文件操作                    *\n");
		printf("               *              0.退出系统                    *\n");
		printf("               **********************************************\n");
		printf("               请输入需要进行的操作：");
		scanf("%d", &op);
	}//end of while

	printf("               欢迎下次使用本系统！\n");
	return 0;
}


/*************************
 * 函数名称: CreateGraph
 * 初始条件：图G不存在
 * 操作结果: 创建图G
 *************************/
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]) {
	int i = 0,j,one = -1,two = -1;
	do {
		if(i > MAX_VERTEX_NUM) return ERROR;
		G.vertices[i].data = V[i];
		G.vertices[i].firstarc = NULL;
	} while (V[i++].key != -1);//添加头结点
	G.vexnum = i - 1;
	for(i = 0, j = 0; i < G.vexnum; i++) {
		for(j = 0; j < G.vexnum ; j++) {
			if(V[i].key == V[j].key && i != j)
				return ERROR;
		}
	}
	i = 0;
	ArcNode *p;
	while (VR[i][0] != -1) {
		one = -1;
		for(j = 0; j < G.vexnum; j++)
			if (VR[i][0] == G.vertices[j].data.key) {
				one = j;
				break;
			}
		if(one == -1)return ERROR;
		for(j = 0; j < G.vexnum; j++)
			if (VR[i][1] == G.vertices[j].data.key) {
				two = j;
				break;
			}
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p -> adjvex = two;
		p -> nextarc = G.vertices[one].firstarc;
		G.vertices[one].firstarc = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p -> adjvex = one;
		p -> nextarc = G.vertices[two].firstarc;
		G.vertices[two].firstarc = p;
		i++;
	}//添加边结点
}

/**************************
 * 函数名称: DestroyGraph
 * 初始条件：图G已存在
 * 操作结果: 销毁图G
 *
 *************************/
status DestroyGraph(ALGraph &G) {
	int i;
	ArcNode *p, *q;//边类型的指针p,q
	for(i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;//p指向第i个节点的 第一条依附于该节点的指针
		while(p) { //p不为空,就依次将q指向下一条弧,释放p,最后再将p指向q，开始下一次循环
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	G.vexnum = 0;//之后将图的信息,顶点数目,边数目,kind置为0
	G.arcnum = 0;
	return OK;
}

/******************************************************************
 * 函数名称: LocateVex
 * 初始条件：图G存在，u和G中的顶点具有相同特征
 * 函数功能: 若u在图G中存在，返回顶点u的信息，否则返回其它信息
 *
 ******************************************************************/
status LocateVex(ALGraph G,KeyType u) {
	int i;
	for(i=0; i<G.vexnum; i++) {
		if(u == G.vertices[i].data.key)//判断节点名称是否相同
			return i;//如果查找成功，返回i的值
	}
	return -1;
}


/***************************************
 * 函数名称: PutVex
 * 初始条件：图G存在，v是G中的某个顶点
 * 函数功能: 对v赋值value
 **************************************/
status PutVex(ALGraph &G,KeyType u,VertexType value) {
	int i = LocateVex(G,u);
	if(i != -1) {

		if(LocateVex(G,value.key) != -1) return ERROR;
		else {
			G.vertices[i].data.key = value.key;
			strcpy(G.vertices[i].data.others,value.others);
			return OK;
		}
	} else return ERROR;
}

/********************************************************************
 * 函数名称: FirstAdjVex
 * 初始条件：图G存在，v是G中的某个顶点
 * 函数功能: 返回v的第一个邻接顶点，如果v没有邻接顶点，返回"空"
 ********************************************************************/
status FirstAdjVex(ALGraph G,KeyType u) {
	ArcNode *p;
	status v1 = LocateVex(G, u);
	if(v1 == -1)  return -2;
	p = G.vertices[v1].firstarc;//调用LocateVex函数,根据返回值，将p指向边
	if(p)  return p->adjvex;
	else   return -1;

}

/***********************************************************************************
 * 函数名称: NextAdjVex
 * 初始条件：图G存在，v是G的一个顶点,w是v的邻接顶点
 * 函数功能: 返回v的（相对于w）下一个邻接顶点，如果w是最后一个邻接顶点，返回"空"
 ***********************************************************************************/
status NextAdjVex(ALGraph G,KeyType v,KeyType w) {
	ArcNode *p;
	int v1 = LocateVex(G, v);
	int w1 = LocateVex(G, w);
	if(v1 == -1 || w1 == -1)
	return -1;
	p = G.vertices[v1].firstarc;
	while (p && p->adjvex != w1)
	{
		p = p->nextarc;
	}
	if(!p) return -3;//根据返回值来判断是否有邻接点,是否是最后一个邻接点
	if(!p->nextarc) return -1;
	else return p->nextarc->adjvex;
}


/*************************************************
 * 函数名称: InsertVex
 * 初始条件：图G存在，v和G中的顶点具有相同特征
 * 函数功能: 在图G中增加新顶点v
 *************************************************/
status InsertVex(ALGraph &G,VertexType v) {
	int i = 0;
	if(G.vexnum >= MAX_VERTEX_NUM || LocateVex(G,v.key) != -1)return ERROR;
	while(G.vertices[i].data.key != -1)i++;
	G.vertices[i].data.key = v.key;
	G.vertices[i].firstarc = NULL;
	strcpy(G.vertices[i].data.others,v.others);
	G.vexnum++;
	return OK;
}


/***************************************************
 * 函数名称: DeleteVex
 * 初始条件：图G存在，v是G的一个顶点
 * 函数功能: 在图G中删除顶点v和与v相关的弧
 ***************************************************/
status DeleteVex(ALGraph &G,KeyType v) {
	int i = 0, j;
	ArcNode *p, *q;
	if(G.vertices[0].data.key != -1 && G.vertices[1].data.key == -1) return ERROR;
	j = LocateVex(G, v);
	if(j == -1 )
		return ERROR;
	p = G.vertices[j].firstarc;
	while(p) {
		q = p;
		p = p->nextarc;
		free(q);
		G.arcnum--;
		i++;
	}
	G.vexnum--;
	for(i = j; i < G.vexnum; i++)
		G.vertices[i] = G.vertices[i+1];
	for(i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		while(p) {
			if(p->adjvex == j) {
				if(p == G.vertices[i].firstarc) {
					G.vertices[i].firstarc = p->nextarc;
					free(p);
					p = G.vertices[i].firstarc;
				} else {
					q -> nextarc = p -> nextarc;
					free(p);
					p = q -> nextarc;
				}
			} else {
				if(p->adjvex > j)
					p->adjvex--;
				q = p;
				p = p->nextarc;
			}
		}
	}
	return OK;
}


/********************************************************************
 * 函数名称: InsertArc
 * 初始条件:图G存在，v、w是G的顶点
 * 函数功能: 在图G中增加弧<v,w>，如果图G是无向图，还需要增加<w,v>
 ********************************************************************/
status InsertArc(ALGraph &G,KeyType v,KeyType w) {
	ArcNode *p,*q;
	int  i, j;
	i = LocateVex(G, v);
	j = LocateVex(G, w);
	if(i == -1 || j == -1)
		return ERROR;
	p = G.vertices[i].firstarc;
	while(p) {
		if( p -> adjvex == j)return ERROR;
		p = p -> nextarc;
	}
	G.arcnum++;
	p=(ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->nextarc = G.vertices[i].firstarc;
	G.vertices[i].firstarc = p;
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = i;
	p->nextarc = G.vertices[j].firstarc;
	G.vertices[j].firstarc = p;
	return OK;
}

/*********************************************************************
 * 函数名称: DeleteArc
 * 初始条件:图G存在，v、w是G的顶点
 * 函数功能: 在图G中删除弧<v,w>，如果图G是无向图，还需要删除<w,v>
 *********************************************************************/
status DeleteArc(ALGraph &G,KeyType v,KeyType w) {
	ArcNode *p, *q;
	int i, j;
	i = LocateVex(G, v);
	j = LocateVex(G, w);
	if(i < 0 || j < 0)
		return ERROR;

	p = G.vertices[i].firstarc;
	while(p && p->adjvex != j) {
		q = p;
		p = p->nextarc;
	}
	if(p && p->adjvex == j) {
		if(p == G.vertices[i].firstarc)
			G.vertices[i].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		free(p);
		G.arcnum--;
	} else if(!p) return ERROR;
	p = G.vertices[j].firstarc;
	while(p && p->adjvex != i) {
		q = p;
		p = p->nextarc;
	}
	if(p && p->adjvex == i) {
		if(p == G.vertices[j].firstarc)
			G.vertices[j].firstarc=p->nextarc;
		else
			q->nextarc=p->nextarc;
		free(p);
	}
	return OK;
}


/*************************************************
 * 函数名称: DFS
 * 初始条件：图G存在
 * 函数功能: 对为访问的节点进行深度优先搜索遍历
 *************************************************/
void DFS(ALGraph G, int v) {
	visited[v] = TRUE;
	VisitFunc(G.vertices[v].data);
	for(w = FirstAdjVex(G,G.vertices[v].data.key); w >= 0; w = NextAdjVex(G,G.vertices[v].data.key,w))
		if(!visited[w]) DFS(G,w);
}


/***************************************************************************************************
 * 函数名称: DFSTraverse
 * 初始条件：图G存在
 * 函数功能: 进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
 ***************************************************************************************************/
status DFSTraverse(ALGraph &G,void (*visit)(VertexType)) {
	int i = -1;
	VisitFunc = visit;
	for(; i < G.vexnum; i++) visited[i] = FALSE;
	for(i = 0; i < G.vexnum; i++)
		if(!visited[i]) DFS(G,i);
}


/***********************************************************************************************
 * 函数名称: BFSTraverse
 * 初始条件：图G存在
 * 函数功能: 进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
 ***********************************************************************************************/
status BFSTraverse(ALGraph &G,void (*visit)(VertexType)) {
	int queue[21] = { MAX_VERTEX_NUM };
	int flag[20] = { MAX_VERTEX_NUM };
	int head = 0, tail = 1;
	queue[0] = 0;
	flag[0] = 1;
L1:
	while (head != tail) {
		if(head < G.vexnum)visit(G.vertices[queue[head]].data);
		ArcNode* p = G.vertices[queue[head]].firstarc;
		while (p) {
			int loc = LocateVex(G, G.vertices[p->adjvex].data.key);
			if (!flag[loc]) {
				queue[tail] = loc;
				tail++;
				flag[loc] = 1;
			}
			p = p->nextarc;
		}

		head++;
	}
	if(tail <= G.vexnum)  {
		tail++;
		queue[head] = LocateVex(G, G.vertices[head].data.key);
		goto L1;
	}
}

/****************************
 * 函数名称: visit
 * 初始条件：图G存在
 * 函数功能: 访问节点一次
 ****************************/
void visit(VertexType v) {
	printf("               key = %d,others = %s\n",v.key,v.others);
}

/*****************************
 * 函数名称: Putin
 * 初始条件：p存在
 * 函数功能: 将图中关系保存在VR数组中
 *****************************/
void Putin(int VR[][2], ArcNode *p, int &k, int i) {
	if(p==NULL) return;
	if(p->nextarc) Putin(VR, p->nextarc, k, i);
	int d;
	for(d=0; d<k; d++) {
		if(VR[d][1]==i&&VR[d][0]==p->adjvex) return;
	}
	VR[k][0]=i;
	VR[k][1]=p->adjvex;
	k++;
}


/*****************************
 * 函数名称: SaveGraph
 * 初始条件：图G存在
 * 函数功能: 保存图为文件
 *****************************/
status SaveGraph(ALGraph G, char FileName[]) {
	FILE* fp;
	int VR[100][2]= {0};
	fp=fopen(FileName,"w");
	int i, j, k, f;
	k=0;
	for(i=0; i<G.vexnum; i++) {
		fprintf(fp,"%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
	}
	fprintf(fp,"-1 nil ");
	for(i=0; i<G.vexnum; i++) {
		Putin(VR, G.vertices[i].firstarc, k, i);
	}
	for(i=0; i<k; i++) {
		j=VR[i][0];
		f=VR[i][1];
		fprintf(fp,"%d %d ", G.vertices[j].data.key, G.vertices[f].data.key);
	}
	fprintf(fp,"-1 -1");
	fclose(fp);
	return OK;
}

/*****************************
 * 函数名称: LoadGraph
 * 初始条件:文件存在
 * 函数功能: 从文件中加载图
 *****************************/
status LoadGraph(ALGraph &G, char FileName[]) {
	FILE* fp;
	fp=fopen(FileName,"r");
	int i, j, k;
	char str[20];
	VertexType V[20];
	KeyType VR[100][2];
	i=0;
	while(fscanf(fp,"%d %s ", &V[i].key, V[i].others)!=EOF) {
		if(V[i].key<0) break;
		i++;
	}
	i=0;
	while(fscanf(fp,"%d %d ", &VR[i][0], &VR[i][1])!=EOF) {
		i++;
	}
	fclose(fp);
	if(CreateCraph(G,V,VR)==OK) {
		ArcNode *f, *q;
		f=G.vertices[2].firstarc;
		q=f->nextarc;
		f->nextarc=q->nextarc;
		q->nextarc=f;
		G.vertices[2].firstarc=q;
		return OK;
	} else return ERROR;
}
