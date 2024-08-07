/* -----------------------------------------------------------------
Fatec São Caetano do Sul - Estrutura de Dados
Professor: Carlos Veríssimo
Proposta: Calculo do tempo de execução do algoritmo Insertion Sort
Autor: Jorge Terence
Data: 07/08/2024
----------------------------------------------------------------- */


void isort(int *v, int len) {
  for (
    int j = 2; // t (atribuição)
    j < len; // tn (lógica)
    j = j + 1 // 2tn (atribuição + aritmética)
  ) {
    int key = v[j]; // 2tn (acesso + atribuição)
    int i = j - 1; // 2tn (atribuição + aritmética)

    while (
      i > 0 // tn² (lógica)
      && // tn² (lógica)
      v[i] > key // 2tn² (acesso + lógica)
    ) {
      v[i + 1] = v[i]; // 3tn² (acesso + aritmética + atribuição)
      i--; // 2tn² (atribuição + aritmética)
    }

    v[i + 1] = key; // 2tn (atribuição + aritmética)
  }
}

/*
Calculo total:
t + 3n + 4tn + 4tn² + 5tn² + 2tn = 9tn² + 9tn + t

Simplificado:
9tn(n + 1) + t
*/