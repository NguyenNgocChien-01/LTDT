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
 		if (G->A[x][i] == 1)
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
// Hàm min
int min(int x,int y){
	if (x < y) return x;
	else return y;
}
//
int num[Max_V];
int min_num[Max_V];
int on_stack[Max_S];
Stack S;
int lt;
int k=1;
// Thuat toan 
void strong_connect(Graph *G,int x){

	num[x] = min_num[x] = k ;
	k++;
	push_stack(&S,x);
	on_stack[x] = 1;
	// xet cac dinh ke
	List L = neighbors(G,x);
	int j;
	for (j = 1; j <= L.size; j++){
		int v = element_at(&L,j);
		
		if (num[v] < 0) {
			strong_connect(G,v);
			min_num[x] = min(min_num[x],min_num[v]);
		} else if (on_stack[v])
		min_num[x] = min(min_num[x],num[v]);
	}
		
	if ( num[x] == min_num[x] ){

		lt=0;
		int w;
		do {
			lt++;
			w = top(&S);
			pop(&S);
			on_stack[w] = 0;
		} while(w != x);

	}
}



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
	for (v = 1; v <= n; v++) {
		num[v] = -1;
		on_stack[v] = 0;
	}
	make_null_stack(&S);

strong_connect(&G, 1);
		
		
if (lt == G.n) 	printf("strong connected"); else printf("unconnected");
	return 0;
}