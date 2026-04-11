#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define VENDIDO 1
#define NO_VENDIDO 0

int main() 
{

    printf("hola");

    #define MAX 100
#define VENDIDO 1
#define NO_VENDIDO 0#define MAX 100
#define VENDIDO 1
#define NO_VENDIDO 0#define MAX 100
#define VENDIDO 1
#define NO_VENDIDO 0

    int n = 0; // maximo de celulares
    int totalRegistrados = 0; // celulares registrados hasta ahora

    int idsCelulares[MAX];
    char marcas[MAX][25];
    float almacenamiento[MAX];
    float ram[MAX];
    float precios[MAX];
    int vendido[MAX];

    int opcion;

    do{

        printf("\n**************** PUComunicaciones, SRL ****************\n\n");
        printf("1. Registrar Celular\n");
        printf("2. Vender Celular\n");
        printf("3. Consultar Inventario de Celular\n");
        printf("4. Consultar Ventas x Marca\n");
        printf("5. Generar Solicitud Compra Celulares\n");
        printf("6. salir\n");

        printf("\nSeleccione opci%cn: ",162);
        while(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6){

            while(getchar() != '\n');
            printf("\nOpcion no valida, intente de nuevo: ");
        }

        system("cls");

        switch(opcion){

            case 1:

                if(n == 0){

                printf("Favor introduzca la cantidad total de celulares a registrar: ");
                    while(scanf("%d", &n) != 1 || n <= 0){

                        while(getchar() != '\n');
                        printf("Cantidad no valida: ");
                    }
                }
                printf("\n************ R E G I S T R O  C E L U L A R E S ************\n");

                for(int i = 0; i < n; i++){

                    printf("\nIntroducir los datos del celular N0.%d\n",i + 1);
                    printf("ID: \n");
                    //scanf();
                    printf("Marca: \n");
                    //scanf();
                    printf("Almacenamiento(GB): \n");
                    //scanf();
                    printf("Memoria RAM(GB): \n");
                    //scanf();
                    printf("Precio de Venta: \n");
                    //scanf();

                    printf("\nDesea registrar otro celular(S/N)?: \n");


                }

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                printf("\nSaliendo del programa....\n");
                break;



        }


    }while(opcion != 6);
    
    return 0;
}
