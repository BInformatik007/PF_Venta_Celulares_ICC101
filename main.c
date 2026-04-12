#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

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


int venderCelular(int totalRegistrados, int idsCelulares[MAX], char marcas[MAX][25], float almacenamiento[MAX], float ram[MAX], float precios[MAX], int vendido[MAX]){

    if(totalRegistrados == 0){
        printf("\nNo hay celulares registrados para vender.\n");
        return totalRegistrados;
    }
    printf("\n************ V E N T A  C E L U L A R E S ************\n");

    int opcionVenta;

    do{
        printf("\nFavor seleccionar una de las siguentes opciones:\n");
        printf("1. Seleccionar celular de una lista\n");
        printf("2. Recomendar un Celular Basado en su Preferencia\n");
        printf("3. Cancelar Venta\n");

        printf("\nSeleccione  una opci%cn: ",162);
        while(scanf("%d", &opcionVenta) != 1 || opcionVenta < 1 || opcionVenta > 3){

            limpiarBufferFunc();
            printf("\nOpci%cn no valida, intente de nuevo: ", 162);
        }

        switch(opcionVenta){
    
            case 1:{
                
                char marcaFiltrar[25];
                printf("\nEspecificar marca: ");
                limpiarBufferFunc();
                gets(marcaFiltrar);

                printf("\n%-10s %-20s %10s %10s %15s\n", "ID", "Marca", "Disco", "RAM", "Precio");
                printf("------------------------------------------------------------------------\n");

                int encontrado = 0;

                for(int i = 0; i < totalRegistrados; i++){

                    if(vendido[i] == NO_VENDIDO && strcasecmp(marcas[i], marcaFiltrar) == 0){

                        printf("%-10d %-20s %10.2f %11.2f %15.2f\n", idsCelulares[i], marcas[i], almacenamiento[i], ram[i], precios[i]);
                        encontrado++;
                    }
                }
                printf("------------------------------------------------------------------------\n");

                if(encontrado == 0){

                    printf("\nNo hay celulares disponibles para esa marca.\n");
                    break;
                }

                int idSeleccionado;
                int idValido = 0;
                int posicion = -1;
                char continuar;
                int compraValida = 0;

                while(idValido == 0){
                
                    printf("\nFavor especificar el ID del celular que desea o -1 para cancelar la compra: ");
                    while(scanf("%d", &idSeleccionado) != 1){

                        limpiarBufferFunc();
                        printf("ID no valido: ");
                    }

                    if(idSeleccionado == -1){

                        printf("\nCompra cancelada....\n");
                        break;
                    }

                    // buscar el celular seleccionada
                    for(int i = 0; i < totalRegistrados; i++){

                        if(idsCelulares[i] == idSeleccionado && vendido[i] == NO_VENDIDO && strcasecmp(marcas[i], marcaFiltrar) == 0){

                            posicion = i;
                            break;
                        }
                    }

                    if(posicion == -1){

                        printf("\nID: %d No existe para la marca %s.\n", idSeleccionado, marcaFiltrar);

                        printf("\nDesea especificar otro ID?(S/N): ");
                        limpiarBufferFunc();
                        scanf(" %c", &continuar);

                        if(continuar != 'S' && continuar != 's'){
                             printf("\nCompra cancelada....\n");
                            break;
                            
                        } 
                    }else{

                      idValido = 1;
                      compraValida = 1;
                    }        
                }

                if(compraValida == 1){
                    printf("\nA continuaci%cn los datos del celular seleccionado y monto a pagar:\n", 162);

                    printf("\n%-10s %-20s %10s %10s %15s\n", "ID", "Marca", "Disco", "RAM", "Precio");
                    printf("------------------------------------------------------------------------\n");

                    printf("%-10d %-20s %10.2f %11.2f %15.2f\n", idsCelulares[posicion], marcas[posicion], almacenamiento[posicion], ram[posicion], precios[posicion]);

                    printf("------------------------------------------------------------------------\n");
                    printf("\n%20s %.2f\n", "Total a Pagar:", precios[posicion]);

                    printf("\nDesea continuar con la compra(S/N)?: ");
                    limpiarBufferFunc();
                    scanf(" %c", &continuar);

                    if(continuar == 'S' || continuar == 's'){

                        vendido[posicion] = VENDIDO;
                        printf("\nCompra registrada exitosamente!!\n");
                    }
                }
            }    
                break;
    
            case 2:
                    
                break;
    
            case 3:

                printf("\nVenta cancelada...\n");
                break;
        }

    }while(opcionVenta != 3);  


    presioneParaContinuarFunc();
    system("cls");
    return 0;
}


int consultarInventario(int totalRegistrados, int idsCelulares[MAX], char marcas[MAX][25], float almacenamiento[MAX], float ram[MAX], float precios[MAX], int vendido[MAX]){
    char filtro = 'S';
    float montoRegistrado = 0.0f, montoInventario = 0.0f, montoVendido = 0.0f;
    float almacenamientoFiltrar = 0.0f, ramFiltrar = 0.0f, precioFiltrar = 0.0f;

    if(totalRegistrados == 0){
        printf("\nNo hay celulares registrados para consultar.\n");
        return 0;
    }

    printf("\n************ I N V E N T A R I O  D E  C E L U L A R E S ************\n");

    printf("\nSi desea aplicar un filtro, favor introducir S: ");
    while(scanf(" %c", &filtro) != 1 || (filtro != 's' && filtro != 'n' && filtro != 'S' && filtro != 'N')){

        limpiarBufferFunc();
        printf("\nDato Inv%clido, intente de nuevo: ", 160);
        continue;
    }

    filtro = toupper(filtro);

    switch(filtro){

        case 'S':

            printf("\nA continuaci%cn especificar los datos por los que desea filtrar.\n", 162);

            printf("\n*** Si no desea filtrar por alguno de ellos, especificar con -1 ***\n");
            printf("Almacenamiento (GB): ");
            while(scanf("%f", &almacenamientoFiltrar) != 1 || almacenamientoFiltrar < -1){
                printf("Cantidad no v%clida. Intente de nuevo:", 160);
                limpiarBufferFunc();
                continue;
            }

            printf("Memoria RAM (GB): ");
            while(scanf("%f", &ramFiltrar) != 1 || ramFiltrar < -1){
                printf("Cantidad no v%clida. Intente de nuevo: ", 160);
                limpiarBufferFunc();
                continue;
            }

            printf("Precio venta: ");
            while(scanf("%f", &precioFiltrar) != 1 || precioFiltrar < -1){
                printf("Cantidad no v%clida. Intente de nuevo: ", 160);
                limpiarBufferFunc();
                continue;
            }

            printf("\n %-12s %-25s %14s %14s %20s \t%-12s", "ID", "Marca", "Disco", "Ram", "Precio", "Vendido");
            printf("\n--------------------------------------------------------------------------------------------------------");

            for(int i = 0 ; i < totalRegistrados ; i++){

                if( (almacenamientoFiltrar == -1 || almacenamientoFiltrar == almacenamiento[i]) && 
                    (ramFiltrar == -1 || ramFiltrar == ram[i] ) && 
                    (precioFiltrar == -1 || precioFiltrar == precios[i])){


                        printf("\n %-12d %-25s %14.2f %14.2f %20.2f \t%-12s", idsCelulares[i], marcas[i], almacenamiento[i], ram[i], precios[i], vendido[i] == 1 ? "Si" : "No");

                        montoRegistrado = montoRegistrado + precios[i];
        
                        if(vendido[i] == 1){
                            montoVendido = montoVendido + precios[i];
                        }else if(vendido[i] == 0){
                            montoInventario = montoInventario + precios[i];
                        }
                }
            }

            printf("\n--------------------------------------------------------------------------------------------------------\n");

            printf(" %-40s %12.2f", "Monto Total Registrado:", montoRegistrado);
            printf("\n %-40s %12.2f", "Monto Total Inventario:", montoInventario);
            printf("\n %-40s %12.2f\n", "Monto Total Vendido:", montoVendido);

            presioneParaContinuarFunc();

            break;

        case 'N':

            printf("\n %-12s %-25s %14s %14s %20s \t%-12s", "ID", "Marca", "Disco", "Ram", "Precio", "Vendido");
            printf("\n--------------------------------------------------------------------------------------------------------");

            for(int i = 0 ; i < totalRegistrados ; i++){

                printf("\n %-12d %-25s %14.2f %14.2f %20.2f \t%-12s", idsCelulares[i], marcas[i], almacenamiento[i], ram[i], precios[i], vendido[i] == 1 ? "Si" : "No");

                montoRegistrado = montoRegistrado + precios[i];

                if(vendido[i] == 1){
                    montoVendido = montoVendido + precios[i];
                }else if(vendido[i] == 0){
                    montoInventario = montoInventario + precios[i];
                }
            }

            printf("\n--------------------------------------------------------------------------------------------------------\n");

            printf(" %-40s %12.2f", "Monto Total Registrado:", montoRegistrado);
            printf("\n %-40s %12.2f", "Monto Total Inventario:", montoInventario);
            printf("\n %-40s %12.2f\n", "Monto Total Vendido:", montoVendido);
            
            presioneParaContinuarFunc();

            break;
    }
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

                venderCelular(totalRegistrados, idsCelulares, marcas, almacenamiento, ram, precios, vendido);
                
                break;

            case 3:

                consultarInventario(totalRegistrados, idsCelulares, marcas,  almacenamiento,  ram,  precios, vendido);

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