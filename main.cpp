#include <stdio.h>
#include <math.h>

float findDiscriminant(int a, int b, int c)
{
  float d;
  
  d = b*b - 4*a*c;

  return d;

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
        printf("Бесконечное множество корней");
      else
        printf("Корней нет");
    }
    else
      printf("Единственный корень: x = %.3f", -c/b);  
  } else
  {
    discriminant = findDiscriminant(a, b, c); 
    printf("Дискриминат равен: %.3f \n", discriminant);

    if (discriminant < 0)
      printf("Нет решений");
    else if (discriminant == 0)
    {
      printf("Одно решение: x = %.3f", (-b/2.0)/a);
    } else 
      {
      float x1;
      float x2;

      x1 = (-b + sqrt(discriminant)) / 2.0 / a; 
      x2 = (-b - sqrt(discriminant)) / 2.0 / a;

      printf("Уравнение имеет два решения: х1 = %.3f, x2 = %.3f", x1, x2);
      }
  }
  
  return 0;
}
