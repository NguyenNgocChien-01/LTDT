#include "stdio.h"
#define Max 20
#define No_E -1

typedef struct {
	int n,m;
	int A[Max][Max];
}Graph;

void init_graph(Graph *G,int n){
	G->n = n;
	int i,j;
	for (i = 1 ; i <= n ; i ++){
		for (j = 1; j <= n ; j ++){
			G->A[i][j] = 0;
		}
	}
}
// Vo Huong
void add_edge(Graph *G,int u,int v,int e){
	G->A[u][v] = e;
	G->A[v][u] = e;
}

void printf(Graph G){
	int i,j;
		for (i = 1 ; i <= G.n ; i ++){
		for (j = 1; j <= G.n ; j ++){
			printf(" %d ",G.A[i][j]);
		}
		printf("\n");
	}
	
}

int main(){
	Graph G;
	freopen("dothi.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	
	int u,v,e;
	for (int i = 1; i <= m ; i ++){
			scanf("%d%d%d",&u,&v,&e);
			add_edge(&G,u,v,e);
	}
	
	
	printf(G);
	
	


	
}