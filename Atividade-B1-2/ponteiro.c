#include <stdio.h>

float calc_final(float *price, float discount);
float ask_discount();

int main(void)
{
  float price, discount;
  printf("Valor do produto: ");
  scanf_s("%f", &price);
  discount = ask_discount();

  printf("O preço final é: %f.2f\n", calc_final(&price, discount));
  printf("O preço original é: %f.2f\n", price);
  printf("O desconto foi de: %f.2f", discount);

  return 0;
}

float calc_final(float *price, float discount)
{
  return *price - (*price * discount / 100);
}

float ask_discount()
{
  float value = 0;
  while (1)
  {
    printf("Porcentagem do desconto: ");
    scanf_s("%f", &value);

    if (value > 100 || value < 0)
      printf("Desconto deve estar entre 0%% e 100%%\n");
    else
      return value;
  }
}