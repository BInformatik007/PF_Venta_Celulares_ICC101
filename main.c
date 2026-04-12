#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 100
#define VENDIDO 1
#define NO_VENDIDO 0

void limpiarBufferFunc(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}


void presioneParaContinuarFunc(){
    printf("\nPresione una tecla para continuar...\n");
    limpiarBufferFunc();
    getche();
    system("cls");
}


void registrarCelularFunc(int n, int totalRegistrados, int idsCelulares[MAX], char marcas[MAX][25], int almacenamiento[MAX], int ram[MAX], float precios[MAX], int vendido[MAX]){

    printf("\n************ R E G I S T R O  C E L U L A R E S ************\n");

    char continuar = 'S';

    while(continuar == 'S' || continuar == 's'){

        if(totalRegistrados >= n){

            system("cls");
            printf("\nCapacidad maxima de celulares alcanzada.\n");
            break;
        }

        printf("\nIntroducir los datos del celular No.%d\n", totalRegistrados + 1);
        
        printf("ID: ");
        while(scanf("%d", &idsCelulares[totalRegistrados]) != 1 || idsCelulares[totalRegistrados] <= 0){

            limpiarBufferFunc();
            printf("\nID no valido: ");
        }
        
        printf("Marca: ");
        limpiarBufferFunc();
        gets(marcas[totalRegistrados]);
        
        printf("Almacenamiento(GB): ");
        while(scanf("%d", &almacenamiento[totalRegistrados]) != 1 || almacenamiento[totalRegistrados] <= 0){

            limpiarBufferFunc();
            printf("\nAlmacenamiento no valido: ");
        }
        
        printf("Memoria RAM(GB): ");
        while(scanf("%d", &ram[totalRegistrados]) != 1 || ram[totalRegistrados] <= 0){

            limpiarBufferFunc();
            printf("\nRAM no valida: ");
        }
        
        printf("Precio de Venta: ");
        while(scanf("%f", &precios[totalRegistrados]) != 1 || precios[totalRegistrados] <= 0){

            limpiarBufferFunc();
            printf("\nPrecio no valido: ");
        }
        
        vendido[totalRegistrados] = NO_VENDIDO;
        totalRegistrados++;
        
        printf("\nDesea registrar otro celular(S/N)?: ");
        while(scanf(" %c", &continuar) != 1 || (continuar != 's' && continuar != 'n' && continuar != 'S' && continuar != 'N')){

            limpiarBufferFunc();
            printf("\nDato Inv%clido, intente de nuevo: ", 160);

        }

        if(continuar == 'n' || continuar == 'N'){
            
            system("cls");
            break;
        }

    }
}

int idExiste(int totalRegistrados, int idsCelulares[MAX], int id){

    for(int i = 0; i < totalRegistrados; i++){

        if(idsCelulares[i] == id){
            return 1; // existe
        }
    }
    return 0; // no existe
}

int registrarCelular(int *n, int totalRegistrados, int idsCelulares[MAX], char marcas[MAX][25], float almacenamiento[MAX], float ram[MAX], float precios[MAX], int vendido[MAX]){

    if(*n == 0){
        printf("Favor introduzca la cantidad total de celulares a registrar: ");
        while(scanf("%d", n) != 1 || *n <= 0){
            limpiarBufferFunc();
            printf("Cantidad no valida: ");
        }
    }

    printf("\n************ R E G I S T R O  C E L U L A R E S ************\n");

    char continuar = 'S';

    while(continuar == 'S' || continuar == 's'){

        if(totalRegistrados >= *n){
            printf("\nCapacidad maxima de celulares alcanzada.\n");
            break;
        }

        printf("\nIntroducir los datos del celular No.%d\n", totalRegistrados + 1);

        int idTemp;
        printf("ID: ");
        while(scanf("%d", &idTemp) != 1 || idTemp <= 0 || idExiste(totalRegistrados, idsCelulares, idTemp)){

            limpiarBufferFunc();
            if(idTemp <= 0){
                printf("ID debe ser mayor a 0: ");
            } else {
                printf("ID ya existe, ingrese uno diferente: ");
            }
        }
        idsCelulares[totalRegistrados] = idTemp; 

        printf("Marca: ");
        limpiarBufferFunc();
        gets(marcas[totalRegistrados]);

        printf("Almacenamiento(GB): ");
        while(scanf("%f", &almacenamiento[totalRegistrados]) != 1 || almacenamiento[totalRegistrados] <= 0){
            limpiarBufferFunc();
            printf("Almacenamiento no valido: ");
        }

        printf("Memoria RAM(GB): ");
        while(scanf("%f", &ram[totalRegistrados]) != 1 || ram[totalRegistrados] <= 0){
            limpiarBufferFunc();
            printf("RAM no valida: ");
        }

        printf("Precio de Venta: ");
        while(scanf("%f", &precios[totalRegistrados]) != 1 || precios[totalRegistrados] <= 0){
            limpiarBufferFunc();
            printf("Precio no valido: ");
        }

        vendido[totalRegistrados] = NO_VENDIDO;
        totalRegistrados++;

        printf("\nDesea registrar otro celular(S/N)?: ");
        limpiarBufferFunc();
        scanf(" %c", &continuar);
    }

    return totalRegistrados;
}

int main() {

    int n = 0;
    int totalRegistrados = 0;

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
        printf("6. Salir\n");

        printf("\nSeleccione opci%cn: ",162);
        while(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6){

            limpiarBufferFunc();
            printf("\nOpci%cn no valida, intente de nuevo: ", 162);
        }

        system("cls");

        switch(opcion){

            case 1:
                totalRegistrados = registrarCelular(&n, totalRegistrados, idsCelulares, marcas, almacenamiento, ram, precios, vendido);
                system("cls");
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