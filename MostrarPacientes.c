#include <stdio.h>

typedef struct
{
    char nombres[50];
    char sexo[50];
    char apellidos[70];
    int edad;
    char numCedula [50];
    char nomTutor [50];
    char apTutor [50];
    char fechaNac [50];
    char lugarNac [50];
    char domicilio [150];
} ContenedorPaciente;

ContenedorPaciente registrosMayoresDeEdad[1000];
ContenedorPaciente registrosMenoresDeEdad[1000];

FILE *numPacientes;
FILE *registro;
int cantidadPacientesMayores = 0;
int cantidadPacientesMenores = 0;

void cargarNumPacientes()
{
    numPacientes = fopen("cantPacientesMayores.bin", "rb");
    fread(&cantidadPacientesMayores, sizeof(int), 1, numPacientes);
    fclose(numPacientes);
    numPacientes = fopen("cantPacientesMenores.bin", "rb");
    fread(&cantidadPacientesMenores, sizeof(int), 1, numPacientes);
    fclose(numPacientes);
}

void leerDatosPacientes()
{
    registro = fopen("registroPacientesMayores.bin", "rb");
    fread(&registrosMayoresDeEdad, sizeof(ContenedorPaciente) * cantidadPacientesMayores, 1, registro);
    fclose(registro);
    registro = fopen("registroPacientesMenores.bin", "rb");
    fread(&registrosMenoresDeEdad, sizeof(ContenedorPaciente) * cantidadPacientesMenores, 1, registro);
    fclose(registro);
}

void mostrarPacientesMayores()
{
    leerDatosPacientes();
    for(int i = 0; i < cantidadPacientesMayores; i++) 
    {
        printf("==================================\n");
        printf("Nombre: %s\n", registrosMayoresDeEdad[i].nombres);
        printf("Apellidos: %s\n", registrosMayoresDeEdad[i].apellidos);
        printf("Sexo: %s\n", registrosMayoresDeEdad[i].sexo);
        printf("Edad: %d\n", registrosMayoresDeEdad[i].edad);
        printf("Cedula: %s\n", registrosMayoresDeEdad[i].numCedula);
        printf("Fecha de nacimiento: %s\n", registrosMayoresDeEdad[i].fechaNac);
        printf("Lugar de nacimiento: %s\n", registrosMayoresDeEdad[i].lugarNac);
        printf("Domicilio: %s\n", registrosMayoresDeEdad[i].domicilio);
        printf("==================================\n");
    }
}

void mostrarPacientesMenores()
{
    leerDatosPacientes();
    for(int i = 0; i < cantidadPacientesMenores; i++) 
    {
        printf("==================================\n");
        printf("Nombre: %s\n", registrosMenoresDeEdad[i].nombres);
        printf("Apellidos: %s\n", registrosMenoresDeEdad[i].apellidos);
        printf("Sexo: %s\n", registrosMenoresDeEdad[i].sexo);
        printf("Edad: %d\n", registrosMenoresDeEdad[i].edad);
        printf("Nombres de tutor: %s\n", registrosMenoresDeEdad[i].nomTutor);
        printf("Apellidos de tutor: %s\n", registrosMenoresDeEdad[i].apTutor);
        printf("Fecha de nacimiento: %s\n", registrosMenoresDeEdad[i].fechaNac);
        printf("Lugar de nacimiento: %s\n", registrosMenoresDeEdad[i].lugarNac);
        printf("Domicilio: %s\n", registrosMenoresDeEdad[i].domicilio);
        printf("==================================\n");
    }
}