#include "stdio.h"
#define MAX_M 500

// Cài đặt danh sách cung/cạnh
	typedef struct {
		int u,v;  				// đỉnh đầu u, đỉnh cuối v
} Edge;

	typedef struct {
		int n,m;			// n đỉnh, m cung
		Edge edges[MAX_M]; //Lưu các cung của đồ thị
} Graph;
//
//// Cài đặt danh sách đỉnh kề
//	typedef struct {
//		int n;
//		int A[n];
//} List ;
//
//	typedef struct {
//
//	List adj[MAX_N]; // mảng các danh sách
//	int n,m;
//	
//} Graph;
// Khởi tạo cho cấu trúc của đồ thị
void init_graph(Graph *pG, int n){
	
	pG->n = n;
	pG->m = 0;
	
}

//Thêm cung u và v vào đồ thị do pG trỏ đến 
void add_edge(Graph *pG, int u, int v){
	// Đưa cung u,v vào đồ thị
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	
	//Tăng số cung lên 1
	pG->m ++;
}


//Kiểm tra 2 đỉnh kề nhau trong đồ thị vô hướng
int adjacent(Graph *pG,int u,int v){
	//Duyệt qua từng cung 0,1,2,3...m-1.
	for (int e = 0 ; e < pG->m ; e++ )
		if( (pG->edges[e].u == u && pG->edges[e].v == v) ||
			(pG->edges[e].u == u && pG->edges[e].v == v)) 
			return 1;
	// Không có cung nào dạng u,v or v,u
	return 0;
}

//Tính bậc của định u trong đồ thị bất kì
int degree(Graph *pG, int u){
	int e, deg_u = 0;
	
	// Duyệt qua từng cung 0,1,2...m-1
	for (e = 0 ; e < pG->m ; e++){
		// Nếu cung có dạng (u,..)
		if (pG->edges[e].u == u)
			deg_u++;
		//Nếu cung có dạng (..,u)
		if (pG->edges[e].v == u)
			deg_u++;
	}
	
	return deg_u;
}





int main(){
	int i,j;
	Graph G;
	init_graph(&G,4);
	add_edge(&G,2,6); // Them cung
	add_edge(&G,6,4);
	add_edge(&G,5,6);
	add_edge(&G,1,4);
	add_edge(&G,1,5);
	add_edge(&G,2,3);
	add_edge(&G,2,4);
	add_edge(&G,4,5);
	
	printf("%d dinh, %d cung",G.n,G.m);
	for(i=0;i<G.m;i++){
		printf("\n %d %d ",G.edges[i].u,G.edges[i].v);
	}
	
}