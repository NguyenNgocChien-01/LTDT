#include "stdio.h"
#define Max 20
#define Max_E 100
//Cai dat cau truc
 typedef struct {
 	int n,m;   // n dinh, m cung
 	int A[Max][Max];
 }Graph;
 // Khoi tao ma tran
 void init_graph(Graph *G,int n,int m){
 	int i,j;
 	G->n = n;
 	G->m = m;
 	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j] = 0;
 }
 
 // Them vao ma tran
 void add_edges(Graph *G, int e,int x, int y){
 	G->A[x][e] = 1;
 	G->A[y][e] = 1;
 }
 //Kiem tra x va y ke nhhau
 int adjacent(Graph G,int x,int y){
 	int i;
 	for (i=1;i<=G.m;i++){
 		if (G.A[x][i] == 1 && G.A[y][i] ==1) return 1;
	 }
	 return 0;
 }
 // Cai dat cau truc ds
 typedef struct {
 	int Data[Max_E];
 	int size;
 }List;
 //Tao ds rong
 void make_null(List *L){
 	L->size =0;
 }
 // Them pt vao ds
 void push_back(List *L,int x){
 	L->Data[L->size] = x;
 	L->size++;
 }
 
//Lay pha tu tai vi tri i
int element_at(List* L,int i){
	return L->Data[i-1];
}

 //Danh sach cac dinh ke cua x
 List neighbors(Graph *G,int x){
 	List L;
 	make_null(&L);
 	for (int i=1;i<=G->m;i++){
 		if (adjacent(*G,x,i) && i!=x) push_back(&L,i);
	 }
	 return L;
 }
 //Tinh bac cua dinh 
 int deg(Graph G,int u){
 	int deg = 0;
 	int i,j;
 	for (i=1;i<=G.m;i++){
 		if(G.A[u][i] == 1 ) deg++;
	 }
	 return deg;
 }
 
 
 int main (){
 	Graph G;
 	init_graph(&G,4,5);
 	add_edges(&G,1,1,2);
 	add_edges(&G,2,1,3);
 	add_edges(&G,3,1,3);
 	add_edges(&G,4,3,4);
 	add_edges(&G,5,1,4);
 	
 		for (int i=1; i<=G.n; i++){
		for (int j=1; j<=G.m; j++)
			printf("%d ",G.A[i][j]);
			printf("\n");
	}	
	
	for(int i=1;i<=G.n;i++){
		printf("deg(%d) = %d ",i,deg(G,i));
	}
	
		for (int i=1; i<=G.n; i++){
		List L = neighbors(&G,i);
		printf("\nCac dinh ke cua dinh %d la = [",i);
	for (int j=1; j<=L.size; j++)
	printf(" %d",element_at(&L,j));
	printf(" ]");
	}
 }