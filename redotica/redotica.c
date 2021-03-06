#include <stdio.h>
#include <stdlib.h>
#define M 101
#define INFTY 101

int G[M][M], prt[M], prints[M][2], printsSize = 0;

inline int isthere(int n1, int n2){
	int i = 0;
	
	for(i = 0; i < printsSize; i++){
		if((prints[i][0] == n1 && prints[i][1] == n2) || (prints[i][0] == n2 && prints[i][1] == n1))
			return 1;
	}
	
	prints[printsSize][0] = n1;
	prints[printsSize++][1] = n2;

	return 0;
}

inline int min(int a, int b) {
        return a < b ? a : b;
}

inline int max(int a, int b) {
        return a > b ? a : b;
}

void prim(int N){
	int min = 0, v = 0, w = 0, cost[M], frj[M];
	
	for(w = 1; w < N; w++){
		prt[w] = -1;
		cost[w] = G[0][w];
		frj[w] = 0;
	}
	
	prt[0] = 0;
	
	while(1){
		min = INFTY;
		
		for(w = 0; w < N; w++){
			if(prt[w] == -1 && cost[w] < min){
				v = w;
				min = cost[w];
			}
		}
		
		if(min == INFTY)
			break;
			
		prt[v] = frj[v];
		
		for(w = 0; w < N; w++){
			if(G[v][w] != INFTY && prt[w] == -1 && cost[w] > G[v][w]){
				cost[w] = G[v][w];
				frj[w] = v;
			}
		}
	}
	
}

int main(){
	int i = 0, j = 0, n = 0, m = 0, x = 0, y = 0, z = 0, k = 1;
	
	while(1){
		
		scanf("%d %d", &n, &m);
		
		if(!n && !m)
			break;
		
		printsSize = 0;
			
		for(i = 0; i < n; i++)		
			for(j = 0; j < n; j++)
				G[i][j] = (i == j) ? 0 : INFTY;
		
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			
			G[x - 1][y - 1] = z;
			G[y - 1][x - 1] = z;
		}
		
		prim(n);
		
		printf("Teste %d\n", k++);
		
		for(i = 0; i < n; i++){
			if(prt[i] >= 0 && prt[i] != i && !isthere(prt[i], i))
				printf("%d %d\n", min(i + 1, prt[i] + 1), max(i + 1, prt[i] + 1));
		}

		printf("\n");
	}

	return 0;
}
