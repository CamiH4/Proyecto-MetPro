#include <stdio.h>
#include <stdlib.h>
#include "VerificarDosis.c"
#include "RegistroPacientes.c"
#include "Seguimiento.c"
#include "Menu.c"

int verificarDosis();
void RegistroPacientes();
void seguimiento();
void imprimirMenu();

int main(int argc, char const *argv[])
{
    char efectos[500];
    int op;
    int primeraDosis;
    char numHosp[50] = "2289-6471";

    do
    {
        imprimirMenu();
        printf("Ingrese una opcion: \n");
        scanf("%d", &op);
        printf("==================================\n");

        switch (op)
        {
        case 1:
            system("cls");
            primeraDosis = verificarDosis();
            if (primeraDosis == 1)
            {
                printf("Cuales? \n");
                scanf("%s", &efectos);
                printf("Se evaluara su condicion, por favor solicite seguimiento. \n");
                printf("Por favor llame a este numero: %s. \n", numHosp);
                printf("Vuelva dentro de una semana. \n");
                printf("==================================\n");
            }
            else
            {
                registroPacientes();
                seguimiento();
            }
            break;
        case 2:
            menuMostrarPacientes();
            break;
        default:
            printf("Opcion no valida... \n");
            printf("==================================\n");
            break;
        }
    } while (op != 2);

    return 0;
}