#include <stdio.h>
#include <stdlib.h>

int n = 0, m = 0, en[1001], em[1001];

int maior(int ini, int fim, int *vet){
	int i = 0, maior = -1;
	
	for(i = ini; i < fim; i++)
		if(i == ini || vet[i] > vet[maior])
			maior = i;
			
	return maior;
}

int soma(int *vet, int i, int size){
	int ret = 0;
	for(; i < size; i++)
		ret += vet[i];
	return ret;
}

int quebrar(int iniL, int fimL, int iniC, int fimC){
	int n = maior(iniL, fimL, en), m = maior(iniC, fimC, em);
	
	if(n < 0)
		return soma(em, iniC, fimC);
	
	if(m < 0)
		return soma(en, iniL, fimL);
	
	if(n < 0 && m < 0)
		return 0;
	
	if(n < 0 || (m >= 0 && en[n] < em[m]))
		return em[m] + quebrar(iniL, fimL, iniC, m) + quebrar(iniL, fimL, m + 1, fimC);
	
	return en[n] + quebrar(iniL, n, iniC, fimC) + quebrar(n + 1, fimL, iniC, fimC);
}

int main(){
	
	int i = 0, j = 0, T = 0, R = 0;
	
	scanf("%d\n\n", &T);
	
	while(T--){
		scanf("%d %d", &m, &n);
		
		n--;
		m--;
		
		for(i = 0; i < m; i++)
			scanf("%d", &em[i]);
		
		for(i = 0; i < n; i++)
			scanf("%d", &en[i]);
		
		printf("%d\n", quebrar(0, n, 0, m));
		
	}

	return 0;
}
