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

int main() {

    int n = 0; // maximo de celulares
    int totalRegistrados = 0; // celulares registrados hasta ahora

    int idsCel[MAX];
    char marcas[MAX][25];
    float almacenamiento[MAX];
    float ram[MAX];
    float precios[MAX];
    int vendido[MAX];

    int opcion;
    char nuevoReg;

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

                if(n == 0){

                printf("Favor introduzca la cantidad total de celulares a registrar: ");
                    while(scanf("%d", &n) != 1 || n <= 0){

                        limpiarBufferFunc();
                        printf("Cantidad no valida: ");
                    }
                }
                printf("\n************ R E G I S T R O  C E L U L A R E S ************\n");

                for(int i = 0; i < n; i++){

                    printf("\nIntroducir los datos del celular N0.%d\n",i + 1);
                    printf("ID: ");
                    while(scanf("%d", &idsCel[i]) != 1 || idsCel[i] <= 0){
                        
                        limpiarBufferFunc();
                        printf("Dato inv%clido. Intente de nuevo: ", 160);
                    }

                    printf("Marca: ");
                    while(scanf("%24s", &marcas[i]) != 1){
                        
                        limpiarBufferFunc();
                        printf("Dato inv%clido. Intente de nuevo: ", 160);
                    }

                    printf("Almacenamiento(GB): ");
                    while(scanf("%d", &almacenamiento[i]) != 1 || almacenamiento[i] <= 0){
                        
                        limpiarBufferFunc();
                        printf("Dato inv%clido. Intente de nuevo: ", 160);
                    }

                    printf("Memoria RAM(GB): ");
                    while(scanf("%d", &ram[i]) != 1 || ram[i] <= 0){
                        
                        limpiarBufferFunc();
                        printf("Dato inv%clido. Intente de nuevo: ", 160);
                    }

                    printf("Precio de Venta: ");
                    while(scanf("%f", &precios[i]) != 1 || precios[i] <= 0){
                        
                        limpiarBufferFunc();
                        printf("Dato inv%clido. Intente de nuevo: ", 160);
                    }

                    printf("\nDesea registrar otro celular(S/N)?: ");
                    while(scanf(" %c", &nuevoReg) != 1 || (nuevoReg != 's' && nuevoReg != 'n' && nuevoReg != 'S' && nuevoReg != 'N')){
                        
                        limpiarBufferFunc();
                        printf("Dato inv%clido. Intente de nuevo: ", 160);
                        
                        if(nuevoReg == 'N' || nuevoReg == 'n'){
                            presioneParaContinuarFunc();
                            return 0;
                        }else if(nuevoReg == 'S' || nuevoReg == 's'){
                            continue;
                        }
                    }
                    

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