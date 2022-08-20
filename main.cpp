#include <stdio.h>
#include <math.h>


struct Coefficents 
{
  double a;
  double b;
  double c;
};

struct Solution
{
  double x1;
  double x2;
  int numberOfRoots;
};

double findDiscriminant(Coefficents *coefficents)
{
  return coefficents->b * coefficents->b - 4 * coefficents->a * coefficents->c;
}

void coefficentReading(Coefficents *coefficents)
{
  printf("Введите коэфиценты уравнения a*x^2 + b*x + c = 0\n");
  scanf("%lf %lf %lf", &coefficents->a, &coefficents->b, &coefficents->c);

  return;
}

void linealEquation(Coefficents *coefficents)
{
    if (coefficents->b == 0)
    {
      if (coefficents->c == 0)
        printf("Бесконечное множество корней\n");
      else
        printf("Корней нет\n");
    }
    else
      printf("Единственный корень: x = %.3f\n", -(coefficents->c) / coefficents->b);
}

void quadraticEquation(Coefficents *coefficents)
{
    double discriminant = findDiscriminant(coefficents);

    if (discriminant < 0)
    {
      printf("Дискриминат отрицательный\n");
      printf("Нет решений\n");
    }
    else if (discriminant == 0)
    {
      printf("Дискриминант равен нулю\n");
      printf("Одно решение: x = %.3f", -(coefficents->b) / (2 * coefficents->a));
    }
    else
    {

    double x1 = NAN;
    double x2 = NAN;

    printf("Дискриминант равен: %f\n", sqrt(discriminant));

    x1 = (-(coefficents->b) + sqrt(discriminant)) / (2 * coefficents->a);
    x2 = (-(coefficents->b) - sqrt(discriminant)) / (2 * coefficents->a);

    printf("Уравнение имеет два решения: х1 = %.3f, x2 = %.3f\n", x1, x2);
    }
}

int main()
{
  Coefficents coefficents = {};

  coefficentReading(&coefficents);

  if (coefficents.a == 0)
  {
    linealEquation(&coefficents);
  }
  else
  {
    quadraticEquation(&coefficents);
  }

  return 0;
}

