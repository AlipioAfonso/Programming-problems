#include <stdio.h>
#define MAX 101

int G[MAX][MAX], vis[MAX];
int B = 0, C = 0, N = 0;
int Depth[3] = {0, 0, 0}; // Depth de B, C e w

inline int min(int a, int b){
	return  a < b ? a : b;
}

inline void edge(int v, int w){
	G[v][w] = 1;
	G[w][v] = 1;
}

void dfs(int v, int depth){
	
	int w = 0, candidate = 0;
	
	vis[v] = 1;
	
	if(v == B || v == C){
		v = (v == B) ? 0 : 1;
		Depth[v] = depth;
	}

	candidate = !Depth[0] && !Depth[1]; // Nao conhecer ninguem
	
	for(w = 0; w < N; w++){
		if(G[v][w] && !vis[w]){			
			dfs(w, depth + 1);
		}
	}	
	
	if(candidate && Depth[0] && Depth[1] && Depth[2] > MAX) // primeiro que nao conhecia e passou a conhecer
		Depth[2] = depth;
}

int main(){
	
	int A = 0, v = 0, w = 0, i = 0;
	int lw = 0, lbc = 0;
	double r = 0;
	
	while(scanf("%d %d %d %d", &N, &A, &B, &C) != EOF){
		
		for(v = 0; v < N; v++){
			vis[v] = 0;
		
			for(w = 0; w < N; w++)
				G[v][w] = 0;
		}
				
		for(i = 0; i < N - 1; i++){
			scanf("%d %d", &v, &w);
			edge(v - 1, w - 1);
		}
		
		Depth[0] = Depth[1] = 0;
		Depth[2] = 2 * MAX;
		
		A--;
		B--;
		C--;
		
		dfs(A, 0);
		
		// printf("%d %d %d\n", Depth[0], Depth[1], Depth[2]);
		
		lbc = Depth[1] + Depth[0] - 2 * Depth[2];
		lw = Depth[0] - Depth[2];
		
		r = ((double) lw) / ((double) lbc);
 		// r = 1 - r;
		
		printf("%.6lf\n", r);
		
	}

	return 0;
}
