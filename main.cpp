#include <stdio.h>
#include <math.h>

float findDiscriminant(int a, int b, int c)
{
  return b * b - 4 * a * c; 
}

int main()
{
  float a;
  float b;
  float c;
  float discriminant;

  printf("Введите коэфиценты уравнения a*x^2 + b*x + c = 0\n");
  scanf("%f %f %f", &a, &b, &c);

  if (a == 0)
  {
    if (b == 0)
    {
      if (c == 0)
        printf("Бесконечное множество корней\n");
      else
        printf("Корней нет\n");
    }
    else
      printf("Единственный корень: x = %.3f\n", -c / b);  
  } 
  else
  {
    discriminant = findDiscriminant(a, b, c); 

    if (discriminant < 0)
    {
      printf("Дискриминат отрицательный\n");
      printf("Нет решений\n");
    }
    else if (discriminant == 0)
    {
      printf("Дискриминант равен нулю\n");
      printf("Одно решение: x = %.3f", -b / (2 * a));
    }
    else 
    {

    float x1;
    float x2;

    printf("Дискриминант равен: %f\n", discriminant);

    x1 = (-b + sqrt(discriminant)) / (2 * a); 
    x2 = (-b - sqrt(discriminant)) / (2 * a);

    printf("Уравнение имеет два решения: х1 = %.3f, x2 = %.3f\n", x1, x2);
    }
  }
  
  return 0;
}

