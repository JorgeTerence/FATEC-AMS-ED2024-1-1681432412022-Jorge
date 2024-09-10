/* -------------------------------------------
Fatec São Caetano do Sul - Estrutura de Dados
Professor: Carlos Veríssimo
Proposta: Implementação de algoritmos de busca
Autor: Jorge Terence
Data: 09/09/2024
------------------------------------------- */

int linear_search_sorted(int A[], int n, int x) {
  for (int i = 1; i <= n; i++) {
    if (A[i] == x)
      return i;
    else if (A[i] > x)
      return -1;
  }

  return -1;
}