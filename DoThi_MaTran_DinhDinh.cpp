// Do thi vo huong

// Do thi vo huong
#include "stdio.h"
#define Max_V 20
#define Max_L 20
typedef struct {
	int A[Max_V][Max_V];
	int n;  // so luong dinh	
}Graph;

// Khai bao cau truc ds
typedef struct {
	int D[Max_L];
	int size;
}List;

// Ham tao ds rong
void make_null(List *L){
	L->size =0;
} 

// Them mot phan tu vao ds
void push_back(List *L, int x){
	L->D[L->size] = x;
	L->size++;
}
 //Lay 1 phan tu trong ds tai vi tri i
int element_at(List *L,int i){
	return L->D[i-1];
}
// Khoi tao do thi
void init_Graph(Graph *G, int n){
	int i,j;
	G->n=n;
		for(i=1; i<=n; i++) // dong cua ma tran
			for(j=1; j<=n; j++)// cot cua ma tran
				G->A[i][j] = 0;
}
// Them cung vao do thi
void add_edge(Graph *G,int x, int y){
	G->A[x][y]+=1;
	G->A[y][x]+=1;
}

//Doc du lieu do thi tu tap tinh (file)
void Read_file(Graph *G){
		FILE* file = fopen("dothi.txt", "r");
	int n,m; //n dinh, m cung
	fscanf(file, "%d%d", &n,&m);
	init_Graph(G, n);
	int u,v; //dinh dau u, dinh cuoi v
	for (int e=1; e<=m; e++){
		fscanf(file,"%d%d",&u,&v);
		add_edge(G,u,v);
	}
	fclose(file);
}

// In ma tran 
void Printf(Graph G){
		for (int i=1; i<=G.n; i++){
		for (int j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
			printf("\n");
	}	
}

// Kiem tra 2 dinh co ke nhau khong
void adjacent(Graph *G,int x,int y){
	if (G->A[x][y] == 1) printf("dinh %d va %d ke nhau\n",x,y);
		else printf("dinh %d va %d khong ke nhau\n",x,y);
}

// Tinh  bac
void  degree(Graph *G, int u){
	int i, deg_u=0;
	for (i=1; i<=G->n; i++){
		if ( G->A[i][u] != 0) deg_u+=G->A[i][u];
	}
	 printf("\nBac cua dinh %d co gia tri la : %d \n",u,deg_u);
}
////Dinh co bat lon nhat
//int deg_max(Graph *G){
//	int i,t=1,max = deg(G,t);
//	for (i = 2 ; i<= G->n ; i++){
//		if (deg(G,i) > max){
//		max = deg(G,i);
//		t = i;
//		} 
//		
//	}
//	return t;
//}
//
////Dinh co bat be nhat
//int deg_min(Graph *G){
//	int i,t=1,min = deg(G,t);
//	for (i = 2 ; i<= G->n ; i++){
//		if (deg(G,i) < min){
//		min = deg(G,i);
//		t = i;
//		} 
//		
//	}
//	return t;
//}

// Tim dinh ke cua dinh x
List neighbors(Graph *G,int x){
	List L;
	make_null(&L);
	for (int i=1; i<=G->n; i++){
		if(G->A[i][x] == 1) {
			push_back(&L,i);
		}	
	}
	return L;   
}
// Dem so cung cua do thi
 int edgeCount(Graph* G) {
 	int i,j,dem=0;
 	for (i=1; i<=G->n;i++)
 		for(j=1;j<=G->n;j++)
 			dem+=G->A[i][j];
 			
 			return dem/2;
 }
int main(){
	int i,j;
	Graph G;
	 //In ma tran
	 Read_file(&G);
	printf("So luong dinh = %d\n", G.n);
	Printf(G);
	//Tinh bac cua dinh u trong do thi
//	for (i=1; i<=G.n; i++){
//		degree(&G,i);
//	}
//	 

	//Can tim dinh ke cua x
	for (i=1; i<=G.n; i++){
		List L = neighbors(&G,i);
		printf("\nCac dinh ke cua dinh %d la = [",i);
	for (j=1; j<=L.size; j++)
	printf(" %d",element_at(&L,j));
	printf(" ]");
	}
	
	for ( i = 1; i <=G.n; i++){
		degree(&G,i);
	}
}