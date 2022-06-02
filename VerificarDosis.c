#include <stdio.h>

int verificarDosis()
{
  int dosis;
  int op;

  printf("Es la primera vez que se vacuna? (Escriba 1.Si o 2.No): ");
  scanf("%i", &op);

  if (op == 2)
  {
    printf("Cuantas dosis le han administrado? ");
    scanf("%d", &dosis);
    printf("Ha presentado efectos secundarios? (Escriba 1.Si o 2.No) ");
    scanf("%i", &op);

    if (op == 1)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return 0;
}