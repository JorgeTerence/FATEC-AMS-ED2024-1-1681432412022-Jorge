#include <stdio.h>

float calc_final(float *price, float discount);

int main(void) {
  float price, discount;
  printf("Valor do produto: ");
  scanf_s("%f", &price);
  printf("Porcentagem do desconto: ");
  scanf_s("%f", &discount);

  printf("O preço final é: %f", calc_final(&price, discount));
  printf("\nO preço original é: %f", price);
  printf("\nO desconto foi de: %f", discount);
  
  return 0;
}

float calc_final(float *price, float discount) {
  return *price - (*price * discount / 100);
}