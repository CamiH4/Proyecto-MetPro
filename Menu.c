#include <stdio.h>
#include "MostrarPacientes.c"

void imprimirMenu()
{
    printf("1. Registrar paciente.\n");
    printf("2. Mostrar pacientes.\n");
}

void menuMostrarPacientes()
{
    cargarNumPacientes();
    int opc;
    printf("1. Pacientes menores de 16 anios. \n");
    printf("2. Pacientes de 16 anios en adelante. \n");
    printf("3. Mostrar Todos los pacientes\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opc);
    if (opc == 1) mostrarPacientesMenores();
    else if (opc == 2) mostrarPacientesMayores(); 
    else if (opc == 3){
        mostrarPacientesMayores();
        mostrarPacientesMenores();
    }
    else printf("Error....");
}