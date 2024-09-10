/* -------------------------------------------
Fatec São Caetano do Sul - Estrutura de Dados
Professor: Carlos Veríssimo
Proposta: Implementação de algoritmos de busca
Autor: Jorge Terence
Data: 09/09/2024
------------------------------------------- */

int binary_search(int A[], int n, int x) {
  int bottom = 1;
  int top = n;

  while (bottom <= top) {
    int mid = (((int)(bottom + top)) / 2);

    if (A[mid] == x)
      return mid;
    else if (x > A[mid])
      bottom = mid + 1;
    else
      top = mid - 1;
  }

  return -1;
}