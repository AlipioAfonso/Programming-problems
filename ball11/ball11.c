#include <stdio.h>
#define MAX 1001

/*
maxLinha
CB: um elemento, nesse caso o melhor � ele mesmo.
HI: Para n - 1 elementos, para n > 1, sabemos o melhor valor a partir do primeiro elemento k at� n.
PI: Dados n n�meros, retiramos seu primeiro (k) obtendo n - 1 n�meros. Por HI sabemos a melhor sequ�ncia de soma para ele, e n�o s� isso, que o elemento v[k + 1] tem este valor.
Voltando k, temos que analizar o valor de k + 1 (v[k + 1]): se este � negativo, a melhor soma para k � ele pr�prio (nunca � bom pegar um negativo); se v[k + 1] � positivo, ent�o a melhor soma para k � v[k] + v[k + 1], logo v[k] += v[k + 1] e zeramos v[k + 1] (pois ele j� foi utilizado).

keepDependencies
Seja j o n�mero da coluna atual, dizemos que ela est� reajustada com as dependencias quando um dado item P[i][j] com i em 0..j � o seu valor original acrescido de P[i - 1][j - 1], isto �, o elemento superior � esquerda. Obviamente se j = 0, nada deve ser feito, pois P[i][-1] n�o � definido.

bestSum
CB: Um elemento, neste caso a melhor soma � ele mesmo. Retorne ele e fim.
HI: Dada uma pilha P de n�meros represetados em uma matriz com n - 1 colunas (n > 1) respeitando as regras de escolha, sabemos encontrar a melhor soma para ela.
PI: Dada uma pilha P com n colunas e n linhas, retiramos a primeira coluna C. Primeiramente mantemos as dependencias (com keepDependencies) com a coluna anterior para a coluna C e encontramos a melhor solu��o para esta coluna (que pelo maxLinha sabemos fazer) e isso nos d� que na posi��o P[i][i] temos a melhor escolha para as bolas abaixo e n�o s� isso, temos tamb�m as depend�ncias certas para aquela coluna, isto �, aquelas que tem n�meros negativos os mantem, j� que n�o s�o boas de serem escolhidas, mas futuramente podem ser no reajuste das depend�ncias.
Al�m, sabemos que todas as depend�ncias s�o mantidas, mesmo que keepDependencies n�o some para cada bola todos acima dela, pois se uma determinada bola for escolhida, ent�o todas acima dela tamb�m o foram (isto � garantido pelo maxLinha) e as bolas acima j� tomaram os valores das demais necess�rias �s bolas inferiores.
Por HI sabemos calcular o melhor valor da pilha com n - 1 colunas, isto �, sem C. Logo, nossa solu��o � o maior entre o topo atual e o melhor para a pilha menor.
*/

int T[MAX][MAX], n = 0;

inline int max(int a, int b){
	return a > b ? a : b;
}

void maxLinha(int i, int j){
	if(i == n - 1)
		return;
	
	maxLinha(i + 1, j);
	
	if(T[i + 1][j] > 0){
		T[i][j] += T[i + 1][j];
		T[i + 1][j] = 0;
	}
}

void keepDependencies(int c){
	if(!c)
		return;
		
	int i = 0;
	
	for(i = c; i < n; i++)
		T[i][c] += T[i - 1][c - 1];
}

int bestSum(int c){	
	keepDependencies(c);
	maxLinha(c, c);
	
	if(c == n - 1)
		return T[c][c];
	
	return max(T[c][c], bestSum(c + 1));
}

int main(){
	int i = 0, j = 0;
	
	while(1){
		scanf("%d", &n);
		getchar();
		
		if(!n)
			break;
		
		for(i = 0; i < n; i++)
			for(j = 0; j <= i; j++){
				scanf("%d", &T[i][j]);
				getchar();
			}
			
		printf("%d\n", max(bestSum(0), 0));
	}

	return 0;
}
