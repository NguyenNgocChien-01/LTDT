// Duyet theo chieu sau

#include "stdio.h"
#define Max_V 20
#define Max_L 20
#define Max_S 40
// Khai bao cau truc
typedef struct {
	int A[Max_V][Max_V];
	int n;
}Graph;
 // Khia bao cau truc ds
 typedef struct {
 	int D[Max_L];
 	int size;
 }List;
 //Khoi tao ds
 void make_null(List *L){
 	L->size = 0;
 }
 //Them phan tu vao cuoi ds
 void push_back(List *L,int x){
 	L->D[L->size] = x;
 	L->size++;
 }
 //Lay han tu ai vtri x
 int element_at(List *L,int i){
	return L->D[i-1];
}

// Khoi tao do thi
void init_Graph(Graph *G,int n){
	int i,j;
	G->n = n;
	for (i=1; i<=G->n;i++)
		for(j=1; j<=G->n; j++)
			G->A[i][j] = 0;
		}
		
//Them cung vao do thi
void add_edge(Graph *G,int x,int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}
//Doc file
void Read(Graph *G){
	FILE* file = fopen("dothiDFS.txt","r");
	int n,m;
	fscanf(file,"%d%d",&n,&m);
	init_Graph(G,n);
	int u,v;
	for (int i=1;i<=m;i++){
		fscanf(file,"%d%d",&u,&v);
		add_edge(G,u,v);
	}
	fclose(file);
	
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
		if ( G->A[i][u] == 1) deg_u++;
	}
	 printf("\nBac cua dinh %d co gia tri la : %d \n",u,deg_u);
}
 //Ds cac diem lan can cua dinh x
 List neighbors(Graph *G,int x){
 	List L;
 	make_null(&L);
 	for (int i=1; i<=G->n; i++){
 		if (G->A[i][x] == 1)
 			push_back(&L,i);
	 }
	 return L;
 }
//In ma tran
void Printf(Graph G){
	int i,j;
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.n; j++)
		printf("%d ",G.A[i][j]);
		
		printf("\n");
	}
}
//Cai dat ngan xep
 typedef struct {
 	int Data[Max_S];
 	int size;
 }Stack;
 // Khoi tao ngan xep rong
 void make_null_stack(Stack *S){
 	S->size = 0;
 }
 // Them phan tu vao ngan xep
 void push_stack(Stack *S,int x){
 	S->Data[S->size] = x;
 	S->size++;
 }
 //Lay 1 phan tu trong Stack
 int top(Stack *S){
 	return S->Data[S->size-1];
 }
 // Xoa 1 phan tu thuoc stack 
 void pop(Stack *S){
 	S->size--;
 }
 // Kiem tra ngan xep rong
 int empty(Stack *S){
 	return S->size == 0;
 }
// Thuat toan duyet theo chieu sau
//
//	Ðua 1 dinh s bat kì vào ngan xep
//	while ngan xep khác rong {
//	u = lay mot dinh ngan xep ra
//	if ( u dã duyet) continue; //bo qua
//	
//	Duyet u
//	Ðánh dau u dã duyet
//	for các dinh ke v cua u
//		if v chua duoc duyet
//			dua v vào ngan xep
//	}
	int mark[Max_V];
void DFS(Graph *G,int x,int p[]){ //bat dau tu dinh x
	Stack S;
	int i,j;
	p[x] = 0;
	make_null_stack(&S);
	push_stack(&S,x);
	
	while (!empty(&S)) {
		int u = top(&S);
		pop(&S);
		if (mark[u] == 1 ) continue;
		printf("Duyet : %d \n",u); mark[u] = 1;
		List L = neighbors(G,u);
		for (i=1; i<=L.size; i++){
			int v = element_at(&L,i);
			if (mark[v] == 0) {
				push_stack(&S,v);
				p[v] = u;
			}
			
		}
		
	}
}
// Thuat toan duyet chieu sau banh de quy



int main(){
	Graph G;
	int i;
	freopen("dothi.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	init_Graph(&G,n);
	
	int u,v;
	for(i = 1; i<= m; i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
		int parent[Max_V];
	for (i=1; i <= n; i++){
		parent[i] = -1;
	}
	for (i=1; i<=G.n;i++)
		mark[i] = 0;
	for (i=1; i<=G.n;i++)
	if ( mark[i] == 0) DFS(&G,i,parent);

	for (int e=1; e <=G.n; e++){
		printf("%d %d\n", e ,parent[e]);
	}
	return 0;
}