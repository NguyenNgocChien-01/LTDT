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
//Ds ang giang cua x
List neighbors(Graph *G, int x){
	List L;
	make_null(&L);
	int i;
	for (i=1; i<=G->n; i++){
		if (G->A[x][i] == 1)
		push_back(&L,i);
	}
	return L;
}

//	if ( u da duyet) return ;
//	Duyet u
//	Danh dau u da duyet
//	
//	for ( cac dinh ke v cu u)
//		DFS_DeQuy(G,v);
	int mark[Max_V];
	int parent[Max_V];

	// Lien thong
void DFS_DeQuy(Graph *G,int u,int p){
	int i;
	if (mark[u] == 1) return ; 
		parent[u] = p;
		mark[u] = 1;
		List L = neighbors(G,u);
		for (i=1; i<=L.size; i++){
			int v = element_at(&L,i);
			DFS_DeQuy(G,v,u);
		}
	
}

void Printf(Graph G){
	int i,j;
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.n; j++)
		printf("%d ",G.A[i][j]);
		
		printf("\n");
	}
}
//
int main (){
	Graph G;
	int i;
	freopen("dothi.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	int lt=0;

	for (int i = 1; i <= G.n; i++){
			mark[i] = 0;
			parent[i] = -1;
	}
	
		for (i = 1; i<=n; i++){
			if (mark[i] == 0) {
				DFS_DeQuy(&G,i,0) ;
				lt++;
			}
		}

	
	for (i=1;i<=n;i++){
		printf("%d %d\n",i,parent[i]);
	}
	printf("%d",lt);
	if (lt > 1) printf("NO"); else printf("YES");
	return 0;
}