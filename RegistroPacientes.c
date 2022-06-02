#include <stdio.h>
#include <stdbool.h>

FILE *salida;
FILE *salida2;
FILE *cPacientes;
int cantPacientesMayores = 0;
int cantPacientesMenores = 0;

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
} Paciente;


Paciente RegistroPaciente;


void numPacientesMayores(){
    FILE *cPacientes = fopen("cantPacientesMayores.bin", "rb");
    if (cPacientes == NULL)
    {
        cPacientes = fopen("cantPacientesMayores.bin", "wb");
        cantPacientesMayores = 0;
        fwrite(&cantPacientesMayores, sizeof(int), 1, cPacientes);
    } else
    {
       fread(&cantPacientesMayores, sizeof(int), 1, cPacientes);
    }
    fclose(cPacientes);
}

void numPacientesMenores(){
    FILE *cPacientes = fopen("cantPacientesMenores.bin", "rb");
    if (cPacientes == NULL)
    {
        cantPacientesMenores = 0;
        fwrite(&cantPacientesMenores, sizeof(int), 1, cPacientes);
    } else
    {
       fread(&cantPacientesMenores, sizeof(int), 1, cPacientes);
    }
    fclose(cPacientes);
}

//Verifica si existen los ficheros donde se almacenan los datos de los pacientes
void verificarFicherosPacientes()
{
    salida = fopen("registroPacientesMayores.bin", "rb");
    salida2 = fopen("registroPacientesMenores.bin", "rb");
    if(salida == NULL) salida = fopen("registroPacientesMayores.bin", "wb");
    if(salida2 == NULL) salida = fopen("registroPacientesMenores.bin", "wb");
    fclose(salida);
    fclose(salida2);
}

void VerificarEdad(bool tieneCedula){
    
  if(tieneCedula == true){
      printf("Digite el numero de tu cedula: ");
      scanf(" %[^\n]", RegistroPaciente.numCedula);
      printf("Digita tu fecha de nacimiento (Por ejemplo: 06-05-2001 ): ");
      scanf(" %[^\n]", RegistroPaciente.fechaNac);
      printf("Digita tu lugar de nacimiento: ");
      scanf(" %[^\n]", RegistroPaciente.lugarNac);
      printf("Escribe tu domicilio: ");
      scanf(" %[^\n]", RegistroPaciente.domicilio);
  } 
  else{
      printf("Escribe los nombres del tutor: ");
      scanf(" %[^\n]", RegistroPaciente.nomTutor);
      printf("Escribe los apellidos del tutor: ");
      scanf(" %[^\n]", RegistroPaciente.apTutor);
      printf("Digita tu fecha de nacimiento (Por ejemplo: 06-05-2001 ): ");
      scanf(" %[^\n]", RegistroPaciente.fechaNac);
      printf("Digita tu lugar de nacimiento: ");
      scanf(" %[^\n]", RegistroPaciente.lugarNac);
      printf("Escribe tu domicilio: ");
      scanf(" %[^\n]", RegistroPaciente.domicilio);
  }
}

void registroPacientes()
{
    bool tieneCedula = false;
    numPacientesMayores();
    numPacientesMenores();
    verificarFicherosPacientes();

    printf("Escriba su sexo (tiene que ser Masculino o Femenino): ");
    scanf(" %[^\n]", RegistroPaciente.sexo);
    printf("Escriba sus nombres: ");
    scanf(" %[^\n]", RegistroPaciente.nombres);
    printf("Escriba sus apellidos: ");
    scanf(" %[^\n]", RegistroPaciente.apellidos);
    printf("Digita tu edad: ");
    scanf("%d", &RegistroPaciente.edad);

    if(RegistroPaciente.edad >= 16)
    {
        salida = fopen("registroPacientesMayores.bin", "ab");
        cPacientes = fopen("cantPacientesMayores.bin", "wb");
        tieneCedula = true;
        VerificarEdad(tieneCedula);
        cantPacientesMayores++;
        fwrite(&cantPacientesMayores, sizeof(int), 1, cPacientes);
        fwrite(&RegistroPaciente, sizeof(Paciente), 1, salida);
    }
    else 
    {
        salida = fopen("registroPacientesMenores.bin", "ab");
        cPacientes = fopen("cantPacientesMenores.bin", "wb");
        VerificarEdad(tieneCedula);
        cantPacientesMenores++;
        fwrite(&cantPacientesMenores, sizeof(int), 1, cPacientes);
        fwrite(&RegistroPaciente, sizeof(Paciente), 1, salida);
    }
    fclose(salida);
    fclose(cPacientes);
}
