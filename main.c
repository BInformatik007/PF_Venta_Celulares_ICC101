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

int idExiste(int totalRegistrados, int idsCelulares[MAX], int id){

    for(int i = 0; i < totalRegistrados; i++){

        if(idsCelulares[i] == id){
            return 1; // existe
        }
    }
    return 0; // no existe
}

int registrarCelularFunc(int *n, int totalRegistrados, int idsCelulares[MAX], char marcas[MAX][25], float almacenamiento[MAX], float ram[MAX], float precios[MAX], int vendido[MAX]){

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

            totalRegistrados = -1;
            return totalRegistrados;
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

                    // buscar el celular selecciono
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
                    while(continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n'){

                        limpiarBufferFunc();
                        printf("Opcion no valida, ingrese S o N: ");
                        scanf(" %c", &continuar);
                    }

                    if(continuar == 'S' || continuar == 's'){

                        vendido[posicion] = VENDIDO;
                        printf("\nCompra registrada exitosamente!!\n");
                    }
                }
            }    
                break;
                    
            case 2:{
                
                char marcaFiltrar[25];
                float mayorPrecio, menorAlmacenamiento, menorRam;

                printf("\nFavor introducir el m%cnimo permitido para las siguientes caracter%csticas:\n", 161, 161);
                printf("Mayor Precio Permitido: ");
                while(scanf("%f", &mayorPrecio) != 1 || mayorPrecio <= 0){

                    limpiarBufferFunc();
                    printf("Precio no valido: ");
                }

                printf("Menor Almacenamiento Permitido(GB): ");
                while(scanf("%f", &menorAlmacenamiento) != 1 || menorAlmacenamiento <= 0){

                    limpiarBufferFunc();
                    printf("Almacenamiento no valido: ");
                }

                printf("Menor RAM Permitida(GB): ");
                while(scanf("%f", &menorRam) != 1 || menorRam <= 0){

                    limpiarBufferFunc();
                    printf("RAM no valida: ");
                }

                int mejor1 = -1, mejor2 = -1;

                for(int i = 0; i < totalRegistrados; i++){

                    if(vendido[i] == NO_VENDIDO && precios[i] <= mayorPrecio &&  almacenamiento[i] >= menorAlmacenamiento && ram[i] >= menorRam){

                        if(mejor1 == -1){

                            mejor1 = i;
                        }else if(mejor2 == -1){

                            mejor2 = i;

                        } else {
                            // comparar por precio, luego ram, luego almacenamiento
                            int peor = mejor2;

                            if(precios[i] < precios[peor] || 
                            (precios[i] == precios[peor] && ram[i] > ram[peor]) ||
                            (precios[i] == precios[peor] && ram[i] == ram[peor] && almacenamiento[i] > almacenamiento[peor])){
                                
                                mejor2 = i;
                                //aqui ordena el mejor1 ya que debe tener el mejor
                                if(precios[mejor2] < precios[mejor1] ||
                                (precios[mejor2] == precios[mejor1] && ram[mejor2] > ram[mejor1]) ||
                                (precios[mejor2] == precios[mejor1] && ram[mejor2] == ram[mejor1] && almacenamiento[mejor2] > almacenamiento[mejor1])){
                                    
                                    int temp = mejor1;
                                    mejor1 = mejor2;
                                    mejor2 = temp;
                                }
                            }
                        }
                    }
                }

                if(mejor1 == -1){

                    printf("\nNo se encontraron celulares con esas caracter%csticas.\n", 161);
                    break;
                }

                printf("\n%-10s %-20s %10s %10s %15s\n", "ID", "Marca", "Disco", "RAM", "Precio");
                printf("------------------------------------------------------------------------\n");
                printf("%-10d %-20s %10.2f %12.2f %15.2f\n", idsCelulares[mejor1], marcas[mejor1], almacenamiento[mejor1], ram[mejor1], precios[mejor1]);

                if(mejor2 != -1){

                    printf("%-10d %-20s %10.2f %12.2f %15.2f\n", idsCelulares[mejor2], marcas[mejor2], almacenamiento[mejor2], ram[mejor2], precios[mejor2]);
                }
                printf("------------------------------------------------------------------------\n");

                int idSeleccionado;
                int idValido = 0;
                int posicion = -1;
                int compraValida = 0;
                char continuar;

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

                    if(idSeleccionado == idsCelulares[mejor1] || (mejor2 != -1 && idSeleccionado == idsCelulares[mejor2])){

                        posicion = (idSeleccionado == idsCelulares[mejor1]) ? mejor1 : mejor2;
                        idValido = 1;
                        compraValida = 1;

                    } else {

                        printf("\nID no valido, debe ser uno de los listados.\n");
                        printf("\nDesea especificar otro ID? (S/N): ");
                        limpiarBufferFunc();
                        scanf(" %c", &continuar);

                        if(continuar != 'S' && continuar != 's'){
                            printf("\nCompra cancelada....\n");
                            break;
                        }
                    }
                }

                if(compraValida == 1){

                    printf("\nA continuaci%cn los datos del celular seleccionado y monto a pagar:\n", 162);
                    printf("\n%-10s %-20s %10s %10s %15s\n", "ID", "Marca", "Disco", "RAM", "Precio");
                    printf("------------------------------------------------------------------------\n");
                    printf("%-10d %-20s %10.2f %12.2f %15.2f\n", idsCelulares[posicion], marcas[posicion], almacenamiento[posicion], ram[posicion], precios[posicion]);
                    printf("------------------------------------------------------------------------\n");
                    printf("\n%20s %.2f\n", "Total a Pagar:", precios[posicion]);

                    printf("\nDesea continuar con la compra(S/N)?: ");
                    limpiarBufferFunc();
                    scanf(" %c", &continuar); 
                    while(continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n'){

                        limpiarBufferFunc();
                        printf("Opcion no valida, ingrese S o N: ");
                        scanf(" %c", &continuar);
                    }

                    if(continuar == 'S' || continuar == 's'){
                        vendido[posicion] = VENDIDO;
                        printf("\nCompra registrada exitosamente!!\n");
                    }
                }
        
            }
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

void consultarInventario(int totalRegistrados, int idsCelulares[MAX], char marcas[MAX][25], float almacenamiento[MAX], float ram[MAX], float precios[MAX], int vendido[MAX]){

    char filtro = 'S';
    float montoRegistrado = 0.0f, montoInventario = 0.0f, montoVendido = 0.0f;
    float almacenamientoFiltrar = 0.0f, ramFiltrar = 0.0f, precioFiltrar = 0.0f;

    if(totalRegistrados == 0){
        printf("\nNo hay celulares registrados para consultar.\n");
        return;
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

            printf(" %-40s %2.2f", "Monto Total Registrado:", montoRegistrado);
            printf("\n %-40s %2.2f", "Monto Total Inventario:", montoInventario);
            printf("\n %-40s %2.2f\n", "Monto Total Vendido:", montoVendido);

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

            printf(" %-40s %.2f", "Monto Total Registrado:", montoRegistrado);
            printf("\n %-40s %.2f", "Monto Total Inventario:", montoInventario);
            printf("\n %-40s %.2f\n", "Monto Total Vendido:", montoVendido);
            
            presioneParaContinuarFunc();

            break;
    }
    return;
}

void consultarVentasMarca(int totalRegistrados, int idsCelulares[MAX], char marcas[MAX][25], float almacenamiento[MAX], float ram[MAX], float precios[MAX], int vendido[MAX]){

   if(totalRegistrados == 0){
        printf("\nNo hay celulares registrados para consultar ventas por marca.\n");
        return;
    }

    // encontrar marcas unicas
    char marcasUnicas[MAX][25];
    int totalMarcas = 0;

    for(int i = 0; i < totalRegistrados; i++){

        int existe = 0;

        for(int indiceMarca = 0; indiceMarca < totalMarcas; indiceMarca++){

            if(strcasecmp(marcas[i], marcasUnicas[indiceMarca]) == 0){

                existe = 1;
                break;
            }
        }

         if(existe == 0){

            strcpy(marcasUnicas[totalMarcas], marcas[i]);
            totalMarcas++;
            }
    }


    // totales por marca y rango
    // [marca][0]=ram 6-10, [marca][1]=ram 12-16, [marca][2]=alm 64-128, [marca][3]=alm 256-512
    float totales[MAX][4];

    for(int indiceMarca = 0; indiceMarca < totalMarcas; indiceMarca++){

        for(int rango = 0; rango < 4; rango++){

            totales[indiceMarca][rango] = 0.0f;
        }
    }

     for(int i = 0; i < totalRegistrados; i++){

        if(vendido[i] == VENDIDO){

            for(int indiceMarca = 0; indiceMarca < totalMarcas; indiceMarca++){

                if(strcasecmp(marcas[i], marcasUnicas[indiceMarca]) == 0){

                    if(ram[i] >= 6 && ram[i] <= 10)  
                    totales[indiceMarca][0] += precios[i];

                    if(ram[i] >= 12 && ram[i] <= 16) 
                    totales[indiceMarca][1] += precios[i];

                    if(almacenamiento[i] >= 64 && almacenamiento[i] <= 128)   
                    totales[indiceMarca][2] += precios[i];

                    if(almacenamiento[i] >= 256 && almacenamiento[i] <= 512)  
                    totales[indiceMarca][3] += precios[i];

                    break;
                }
            }
        }
    }

    printf("\n************ V E N T A S  D E  C E L U L A R E S  X  M A R C A ************\n\n");
    printf("\n%-16s", " ");
    printf("%34s", "MEMORIA RAM(GB)");
    printf("%50s\n", "ALMACENAMIENTO(GB)");
    printf("%-16s", " ");
    printf("%45s %47s\n", "----------------------------------", "--------------------------------------");
    printf("%-16s", " ");
    printf("%20s %22s", "6 - 10", "12 - 16");
    printf("%22s %25s\n", "64 - 128", "256 - 512");
    printf("%-16s", " ");
    printf("%24s %20s", "-------------", "-------------");
    printf("%23s %23s\n", "-------------", "-------------");

    float totalGeneral[4] = {0, 0, 0, 0};

     for(int indiceMarca = 0; indiceMarca < totalMarcas; indiceMarca++){

        printf("%-20s %14.2f %21.2f %21.2f %23.2f\n",marcasUnicas[indiceMarca],totales[indiceMarca][0], totales[indiceMarca][1],
            totales[indiceMarca][2], totales[indiceMarca][3]);

        for(int rango = 0; rango < 4; rango++){

            totalGeneral[rango] += totales[indiceMarca][rango];
        }
    }
            
    printf("                         --------------------------------------------------------------------------------------\n");
    printf("%-20s %14.2f %21.2f %21.2f %23.2f\n",
        "Total General:", totalGeneral[0], totalGeneral[1],totalGeneral[2], totalGeneral[3]);

    presioneParaContinuarFunc();
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
                totalRegistrados = registrarCelularFunc(&n, totalRegistrados, idsCelulares, marcas, almacenamiento, ram, precios, vendido);
                system("cls");

                if (totalRegistrados == -1){
                    printf("\nCapacidad maxima de celulares alcanzada.\n");
                    totalRegistrados = n;

                }
                    
                break;

            case 2:

                venderCelular(totalRegistrados, idsCelulares, marcas, almacenamiento, ram, precios, vendido);
                
                break;

            case 3:

                consultarInventario(totalRegistrados, idsCelulares, marcas,  almacenamiento,  ram,  precios, vendido);

                break;

            case 4:

                consultarVentasMarca(totalRegistrados, idsCelulares, marcas, almacenamiento, ram, precios, vendido);
                
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