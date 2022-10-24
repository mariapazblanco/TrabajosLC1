#include <stdio.h>
#include <stdlib.h>


const int tam = 2;
struct estructuraEnvio
{
    int numerosID[2];
    float pesos[2];
    int destinos[2];
    int horasPlanificadas[2];
    int estados[2];
};


void cargarEnvios();
void mostrarEnvios();
void modificarEstadoDeUnEnvio();
void mostrarEnvioParaDestino(int destino);

struct estructuraEnvio envio[2];
void main()
{
    int opcion = 0;
    int des = 0;

    do
    {
        printf("\n1- Cargar env%cos planificados.", 161);
        printf("\n2- Mostrar env%cos planificados.", 161);
        printf("\n3- Modificar estado de un env%co.", 161);
        printf("\n4- Mostrar env%cos para un destino.", 161);
        printf("\n5- Salir.\n\n");
        scanf("%d", &opcion);

        if (opcion != 5)
        {
            switch (opcion)
            {
            case 1:
                // Cargar envíos planificados
                cargarEnvios();
                break;
            case 2:
                // Mostrar envíos planificados
                mostrarEnvios();
                break;
            case 3:
                // Modificar estado de un envío
                modificarEstadoDeUnEnvio();
                break;
            case 4:
                // Mostrar envíos para un destino
                printf("Destino a buscar: ");
                printf("\n1- Rosario");
                printf("\n2- Funes");
                printf("\n3- Roldan");
                printf("\n4- Baigorria");
                printf("\n");
                scanf("%i", &des);

                mostrarEnvioParaDestino(des);

                break;
            default:
                printf("La opci%cn ingresada es inv%clida\n", 162, 160);
            }
        }

    } while (opcion != 5);
}

void cargarEnvios()
{
    printf("--Ingrese los datos de los env%cos--\n", 161);

    for (int i = 0; i < tam; i++)
    {
        printf("Env%co numero: ", 161);
        scanf("%i", &envio->numerosID[i]);

        while (envio->numerosID[i] < 100 || envio->numerosID[i] > 999)
        {
            printf("ingrese un numero de identificacion correcto, entre 100 y 999.");
            scanf("%d", &envio->numerosID[i]);
        }

        printf("Ingrese el peso: ");
        scanf("%f", &envio->pesos[i]);

        printf("Ingrese el destino: ");
        printf("\n1- Rosario");
        printf("\n2- Funes");
        printf("\n3- Roldan");
        printf("\n4- Baigorria");
        printf("\n");
        scanf("%i", &envio->destinos);
        while (envio->destinos[i] < 1 || envio->destinos[i] > 4)
        {
            printf("Ingrese un destino correcto.");
            printf("\n1- Rosario");
            printf("\n2- Funes");
            printf("\n3- Roldan");
            printf("\n4- Baigorria");
            printf("\n");
            scanf("%i", &envio->destinos[i]);
        }

        printf("Ingrese la hora: ");
        scanf("%d", &envio->horasPlanificadas[i]);
        while (envio->horasPlanificadas[i] < 8 || envio->horasPlanificadas[i] > 22)
        {
            printf("ingrese una hora correcta (entre las 8 y 22 hs.)\n");
            scanf("%i", &envio->horasPlanificadas[i]);
        }

        printf("Ingrese el estado: ");
        printf("\n0- Pendiente");
        printf("\n1- Despachado");
        printf("\n");
        scanf("%i", &envio->estados[i]);
        while (envio->estados[i] < 0 || envio->estados[i] > 1)
        {
            printf("ingrese un estado correcto.\n");
            printf("\n0- Pendiente");
            printf("\n1- Despachado");
            printf("\n");
            scanf("%i", &envio->estados[i]);
        }
    }
}

void mostrarEnvios()
{
    for (int i = 0; i < tam; i++)
    {
        mostrarEnvio(i);
    }
}

void mostrarEnvioParaDestino(int destino)
{
    for (int i = 0; i < tam; i++)
    {
        if (destino == envio->destinos[i])
        {
            mostrarEnvio(i);
        }
    }
}

void mostrarEnviosDespachados()
{
    for (int i = 0; i < tam; i++)
    {
        if (1 == envio->estados[i])
        {
            mostrarEnvio(i);
        }
    }
}

void mostrarEnviosPendientes()
{
    for (int i = 0; i < tam; i++)
    {
        if (0 == envio->estados[i])
        {
            mostrarEnvio(i);
        }
    }
}

void modificarEstadoDeUnEnvio()
{
    int nroID = 0, est = 0, i = 0;
    int encontrado = 0;

    printf("Nro del env%co a modificar:", 161);
    scanf("%i", &envio->numerosID[i]);

    for (i = 0; i < tam; i++)
    {
        if (nroID == envio->numerosID[i])
        {
            encontrado = 1; 
            printf("ingrese un nuevo estado del envio: ");
            scanf("%i", &envio->estados[i]);
            while (&envio->estados[i] < 0 || envio->estados[i] > 1)
            {
                printf("ingrese un estado correcto, 0 o 1.");
                scanf("%d", &envio->estados[i]);
            }
        }

    }
    if (encontrado == 0)
    {
        printf("no se encontro el envio a modificar.\n");
    }
}

void mostrarEnvio(int i)
{
    printf(" %d \t", envio->numerosID[i]);
    printf(" %.2f \t", envio->pesos[i]);
    switch (envio->destinos[i])
    {
    case 1:
        printf("Rosario");
        break;
    case 2:
        printf("Funes");
        break;
    case 3:
        printf("Roldan");
        break;
    case 4:
        printf("Baigorria");
        break;
    default:
        printf("Destino inv%clido\n", 160);
    }
    printf("\t");
    printf(" %d hs \t", envio->horasPlanificadas[i]);

    switch (envio->estados[i])
    {
    case 0:
        printf("Pendiente");
        break;
    case 1:
        printf("Despachado");
        break;
    default:
        printf("Estado inv%clido\n", 160);
    }

    printf("\n");
}