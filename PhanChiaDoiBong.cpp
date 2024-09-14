#include "stdio.h"
#define Max_V 20
// Duuyet do thi theo chieu sau bang de quy

//Khai bao do thi
	typedef struct {
		int A[100][100];
		int n;
	}Graph;
	
// Khoi tao do thi
void init_graph(Graph *G,int n){
	int i,j;
	G->n = n;
	for (i=1 ; i<=n; i++)
		for (j=1; j<=n; j++)
			G->A[i][j] = 0;
}

// Them cung vao do thi
void add_edge(Graph *G,int u,int v){
	G->A[u][v] = 1;
	G->A[v][u] = 1;
}
// Kiem tra lang gieng
int adjacent(Graph *G,int x,int y){
	return G->A[x][y] == 1;
}
//Khai bao ds
	typedef struct {
		int D[20];
		int size;
	}List;
//Khoi tao ds
void make_null(List *L){
	L->size = 0;
}
//Them pt
void push_back(List *L,int x){
	L->D[L->size] = x;
	L->size++;
}
//Lay pt trong ds tai vi tri i
int element_at(List *L,int i){
	return L->D[i-1];
}
// 
int empty(List *L){
	return L->size == 0;
}
//In ds
void Print_List(List L){
	for (int i=1; i<=L.size;i++){
 	int v = element_at(&L,i);
 	printf("%d ",v);
 }
}
// Kiem tra 1 co nham trong ds ko
int gr_1(List L){
	int gr = 0;
	for (int i = 1; i <=L.size; i++){
		int v  = element_at(&L,i);
		if (v == 1) gr = 1;
	}
	return gr;
}


void PhanChiaDoiBong(Graph *G,List *L1,List *L2){
	int doi[Max_V];
	int i,j;
	for(i=1;i<=G->n; i++){
		doi[i] = 0;
	}
	for (i=1; i <= G->n; i++){
		for(j = i; j<=G->n; j++)
		{
			if (G->A[i][j] == 0 && i!=j) {
				doi[i] = 1; doi[j] = 1;
			}
		}
	}
	
		for(i=1;i<=G->n; i++){
		if (doi[i] != 1) doi[i] =2;
	}

			for(i=1;i<=G->n; i++){
		if (doi[i] == 1) push_back(L1,i);
		else if (doi[i] == 2 )push_back(L2,i);
	}
	
}

int main (){
	Graph G;
	int i,j;
	freopen("dothi.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int u,v;
	for (i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
 List L1;
 List L2;
 make_null(&L1);
 make_null(&L2);

 
	PhanChiaDoiBong(&G,&L1,&L2);
	
	
	if (empty(&L1) || empty(&L2)) printf("IMPOSSIBLE");
	else {
		if (gr_1(L1)){
			Print_List(L1);
			printf("\n");
			Print_List(L2);
		}
		else {
			Print_List(L2);
			printf("\n");
			Print_List(L1);
		}
	}




	return 0;
}