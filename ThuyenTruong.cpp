#include "stdio.h"
#define Max_V 20
#define gray 2
#define white 0
#define black 1

// Duuyet do thi theo chieu sau bang de quy

//Khai bao do thi
	typedef struct {
		int A[Max_V][Max_V];
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
		if (G->A[i][x] == 1)
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
    int color[Max_V];
    int cycle=0;
	// Lien thong
void DFS(Graph *G,int x,int parent){
    color[x] = gray;
	int i;
		List L = neighbors(G,x);
		if (L.size != 0 ){
		
		for (i=1; i<=L.size; i++){
			int v = element_at(&L,i);
		if (v == parent) continue;
		    if (color[v] == gray){
		        cycle ++;
		       return;
		    }
		    if (color[v] == white)
		    DFS(G,v,x);
		}
	}
		color[x] = black;
}

//
int con_cycle(Graph *G){
    int i;
    	for (i = 1; i <= G->n; i++){
			color[i] = white;
	}
	cycle = 0;
	
		for (int j = 1; j<=G->n; j++){
			if (color[j] == white) 	DFS(G,j,0);
		return cycle;
		    
		}
		return cycle;;
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
	freopen("thuyentruong.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
Printf(G);
int c = con_cycle(&G);
printf("%d\n",c);
if(c > 0 ) printf("NO"); else printf("YES");
	

	return 0;
}