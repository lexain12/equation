#include <stdio.h>
#include <math.h>

float findDiscriminant(int a, int b, int c)
{
  return b * b - 4 * a * c; 
}

float* input()
{
  float a = NAN;
  float b = NAN;
  float c = NAN;

  printf("Введите коэфиценты уравнения a*x^2 + b*x + c = 0\n");
  scanf("%f %f %f", &a, &b, &c); 

  float *arg = (float*)malloc(sizeof(float)*3);

  arg[0] = a;
  arg[1] = b;
  arg[2] = c;

  return arg; 
}

void linealEquation(float b, float c)
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

void quadraticEquation(float a, float b, float c)
{
    float discriminant = findDiscriminant(a, b, c); 

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

    float x1 = NAN;
    float x2 = NAN;

    printf("Дискриминант равен: %f\n", sqrt(discriminant));

    x1 = (-b + sqrt(discriminant)) / (2 * a); 
    x2 = (-b - sqrt(discriminant)) / (2 * a);

    printf("Уравнение имеет два решения: х1 = %.3f, x2 = %.3f\n", x1, x2);
    }
}

int main()
{
  float a = NAN;
  float b = NAN;
  float c = NAN;
  float discriminant = NAN;
  float* arg = NULL;

  
  arg = input();
  a = arg[0];
  b = arg[1];
  c = arg[2];

  free(arg);


  if (a == 0)
  {
    linealEquation(b, c);
  } 
  else
  {
    quadraticEquation(a, b, c);
  }
  
  return 0;
}

