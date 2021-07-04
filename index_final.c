#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<string.h>
#include <time.h>

/* ------------------  ESTRUCTURAS BASE  ------------------ */
struct nodoIngrediente {
    char nombre[30];
    int cant;
    struct nodoIngrediente *sig; 
};

struct nodoHamburguesa{
    char nombre[30];
    int precio;
    struct nodoIngrediente *IngrHamburguesa;
    struct nodoHamburguesa *sig;
};

struct nodoTicket{
    char nombre[30];
    /* int cantidad; */
    int precio_total;
    char fecha_hora[128];
    struct nodoTicket *sig;
};

/* ------------------  FUNCIONES  ------------------ */
/* ------------------  FUNCIONES INGREDIENTE  ------------------ */
struct nodoIngrediente *crearNodoI(char nombre[30], int cant){
    struct nodoIngrediente *nuevoNodo; 
    nuevoNodo = malloc(sizeof(struct nodoIngrediente));        
    strcpy(nuevoNodo->nombre,nombre);
    nuevoNodo->cant = cant;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

struct nodoIngrediente *insertarNodoI(struct nodoIngrediente *ingrediente, char nombre[30], int cant){

    if(ingrediente == NULL)
    return crearNodoI(nombre, cant);

    else
    ingrediente->sig = insertarNodoI(ingrediente->sig,nombre,cant);
    
    return ingrediente;
}


void mostrarListaI(struct nodoIngrediente *ingrediente){
    
    int size_nodo = sizeof(struct nodoIngrediente); 
    struct nodoIngrediente *actual=malloc(size_nodo); 
    actual = ingrediente;

    if(ingrediente == NULL){
        printf("\n\n!! La lista de Ingredientes esta vacia !!\n\n");
    }
    else{
        printf("\n\nIngredientes en stock: \n");
        while (actual != NULL){
            printf("%s: %d\n",actual->nombre, actual->cant);
            actual=actual->sig;
        }
        
    }
}

/* ------------------  FUNCIONES HAMBURGUESAS  ------------------ */

struct nodoHamburguesa *crearNodoH(char nombre[30], int presio,struct nodoIngrediente *ingreHamb){
    struct nodoHamburguesa *nuevoNodo = malloc(sizeof(struct nodoHamburguesa));        
    strcpy(nuevoNodo->nombre,nombre);
    nuevoNodo->precio=presio;
    nuevoNodo->IngrHamburguesa = ingreHamb;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

struct nodoHamburguesa *insertarNodoH(struct nodoHamburguesa *hamburguesas, char nombre[30], int presio,struct nodoIngrediente *ingreHamb){

    if(hamburguesas == NULL)
    return crearNodoH(nombre, presio, ingreHamb);

    else
    hamburguesas->sig = insertarNodoH(hamburguesas->sig,nombre,presio,ingreHamb);
    
    return hamburguesas;
}

void mostrarListaH(struct nodoHamburguesa *hamburguesas){
    int size_nodo = sizeof(struct nodoHamburguesa); 
    struct nodoHamburguesa *actual=malloc(size_nodo); 
    actual = hamburguesas;

    struct nodoIngrediente *ingredientes=malloc(size_nodo); 
    
    if(hamburguesas == NULL){
        printf("\n\n!! La lista de Ingredientes esta vacia !!\n\n");
    }

    else{
        printf("\nLista de Hamburguesas: \n");
        while (actual != NULL){
            printf("\n%s \t$%d\n",actual->nombre, actual->precio);
            ingredientes = actual->IngrHamburguesa;
                while(ingredientes != NULL){
                    if(ingredientes->sig == NULL)
                        printf(" %s: %d\n",ingredientes->nombre, ingredientes->cant);
                    else
                        printf(" %s: %d ->",ingredientes->nombre, ingredientes->cant);
                    ingredientes=ingredientes->sig;
                }
            actual=actual->sig;
        }
    printf("\n\n");
    }
}

/* ------------------  FUNCIONES TICKETS  ------------------ */

struct nodoTicket *crearNodoT(char nombre[30]/* ,int cantidad */ ,int presio, char tiempo[128]){
    struct nodoTicket *nuevoNodo = malloc(sizeof(struct nodoTicket));        
    strcpy(nuevoNodo->nombre,nombre);
    /* nuevoNodo->cantidad=cantidad; */
    nuevoNodo->precio_total= presio;
    strcpy(nuevoNodo->fecha_hora,tiempo);
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

struct nodoTicket *insertarNodoT(struct nodoTicket *tickets, char nombre[30]/* ,int cantidad  */,int presio, char tiempo[128]){

    if(tickets == NULL)
    return crearNodoT(nombre/* , cantidad */, presio, tiempo);

    else
    tickets->sig = insertarNodoT(tickets->sig,nombre/* , cantidad */, presio, tiempo);
    
    return tickets;
}

void mostrarListaT(struct nodoTicket *tickets){
    int size_nodo = sizeof(struct nodoTicket); 
    struct nodoTicket *actual=malloc(size_nodo); 
    actual = tickets;
    int i=1;
    
    if(tickets == NULL){
        printf("\n\n!! La lista de Tickets esta vacia !!\n\n");
    }

    else{
        while (actual != NULL){
            
            printf("\n\n\t\t------------------ TICKET N%d --------------------\n",i);
            printf("\nProducto: %s.",actual->nombre);
            /* printf("\nCantidad: %d. \n",actual->cantidad); */
            printf("\nValor total: $%d.",actual->precio_total);

            printf("\nFecha y Hora: %s.\n",actual->fecha_hora);
            actual=actual->sig;
            i++;
        }
    }
}

/* ------------------  FUNCION VENTA ------------------ */

bool venta(struct nodoIngrediente *ingreHamb, struct nodoIngrediente *ingredientes){
    int size_nodo = sizeof(struct nodoIngrediente); 
    struct nodoIngrediente *actual=malloc(size_nodo);

    struct nodoIngrediente *actual2=malloc(size_nodo);
    actual2 = ingreHamb;
    bool sepuedevender=false;
    while(actual2 != NULL){
        actual = ingredientes;
        while(actual != NULL){
            if(strcmp(actual2 ->nombre,actual->nombre)==0){
                if(actual->cant >= actual2 ->cant){
                    //devuelve si salio bien la venta
                    sepuedevender = true;
                }
                else{
                    printf("No hay suficiente %s",actual2 ->nombre);
                    //devuelve si salio mal la venta
                    sepuedevender = false;
                }
            }
            actual=actual->sig;
        }
        actual2 =actual2 ->sig;    
    }
    actual2 = ingreHamb;
    if(sepuedevender == true){
        while(actual2  != NULL){
        actual = ingredientes;
        while(actual != NULL){
            if(strcmp(actual2 ->nombre,actual->nombre)==0){
                if(actual->cant >= actual2 ->cant){

                    actual->cant -= actual2 ->cant;
                    if(actual->cant <= 6){
                        
                    }
                }
            }
            actual=actual->sig;
        }
        actual2 =actual2 ->sig;    
        }   
    }
    return sepuedevender;
}

/* ------------------  FUNCION RESTOCK DE INGREDIENTES ------------------ */

void restockear(struct nodoIngrediente *ingredientes, char nombre[30],int cant){
    int size_nodo = sizeof(struct nodoIngrediente); 
    struct nodoIngrediente *actual=malloc(size_nodo);
    actual = ingredientes;
    while(actual != NULL){
        if(strcmp(actual->nombre,nombre)==0){
            actual->cant += cant;
        }
        actual= actual->sig;
    }
}

int main(){
    struct nodoIngrediente *ingredientes=NULL;
    struct nodoHamburguesa *hamburguesas=NULL;
    struct nodoIngrediente *auxI=NULL;
    struct nodoHamburguesa *auxH=NULL;
    struct nodoIngrediente *listaIngre=NULL;
    /* ------------------  TICKET  ------------------ */
    struct nodoTicket *listaTicket=NULL;

    char nombreI[30],nombreH[30],respuesta,opc,opc2;
    int aux=0,cantI,cantH;
    bool menu=true;

    ingredientes = insertarNodoI(ingredientes,"Pan",2);
    ingredientes = insertarNodoI(ingredientes,"Medallon",2);
    ingredientes = insertarNodoI(ingredientes,"Cheddar",2);
    ingredientes = insertarNodoI(ingredientes,"Panceta",3);

    listaIngre = insertarNodoI(listaIngre,"Pan",2);
    listaIngre = insertarNodoI(listaIngre,"Medallon",2);
    listaIngre = insertarNodoI(listaIngre,"Cheddar",2);
    listaIngre = insertarNodoI(listaIngre,"Panceta",3);
    hamburguesas = insertarNodoH(hamburguesas,"Bacon&Cheddar",30,listaIngre);

    listaIngre=NULL;

    listaIngre = insertarNodoI(listaIngre,"Pan",2);
    listaIngre = insertarNodoI(listaIngre,"Medallon",1);
    listaIngre = insertarNodoI(listaIngre,"Tomate",2);
    listaIngre = insertarNodoI(listaIngre,"Lechuga",1);
    hamburguesas = insertarNodoH(hamburguesas,"Simple",20,listaIngre);


    do{
        printf("\t\t---------------- Sistema Control ----------------\n");
        printf("\t\t-------------- Tito's Burguer & Co --------------\n");
        printf("\n1. Cargar Ingredientes.");
        printf("\n2. Ver lista de Ingredientes.");
        printf("\n3. Realizar Venta.");
        printf("\n4. Ver ventas hasta el momento. ---- LAST UPDATE ----");
        printf("\n5. ---- OUT OF SERVICE ---- .");
        printf("\n6. ---- OUT OF SERVICE ---- .");
        printf("\n7. ---- OUT OF SERVICE ---- .");
        printf("\n8. Ver Lista de hamburguesas.");
        printf("\n9. Ingresar nueva hamburguesa."); // posible error cuando quieres realizar venta de hamburguesa cargada
        printf("\nF. Salir\n");
        printf("\nOpcion a Ingresar: ");
        scanf("%c", &respuesta);
        fflush(stdin);
        switch (respuesta){

            case '1':
                system("cls");
                printf("\t\t---------------- Opcion 1 ----------------\n");
                printf("\t\t---------- Carga de Ingredientes ---------\n\n");
                do{
                    printf("\n1. Restockear Ingredientes.");
                    printf("\n2. Cargar nuevo Ingrediente.");
                    printf("\nF. Salir\n");
                    scanf("%c",&opc);
                    fflush(stdin);
                    switch (opc)
                    {
                        case '1':
                            auxI = ingredientes;
                            aux=1;
                            printf("Ingredientes actuales:\n");
                            while (auxI != NULL){
                                printf("(%d) %s :%d\n",aux,auxI->nombre, auxI->cant);
                                auxI=auxI->sig;
                                aux++;
                            }
                            printf("\nOpcion a elegir: ");
                            scanf("%d",&aux);
                            fflush(stdin);
                            printf("Cantidad: "); 
                            scanf("%d",&cantI);
                            fflush(stdin);
                            auxI= ingredientes;

                            for(int i=0;i<(aux-1);i++){
                                auxI=auxI->sig;
                            }
                            restockear(ingredientes,auxI->nombre,cantI);
                            break;
                            
                        case '2':
                            do{
                                printf("Nombre: ");
                                gets(nombreI);
                                fflush(stdin);
                                printf("Cantidad: "); 
                                scanf("%d",&cantI);
                                fflush(stdin);                
                                ingredientes = insertarNodoI(ingredientes,nombreI,cantI);
                                printf("Desea ingresar otro ingrediente? [Y/N]: ");
                                scanf("%c",&opc);
                                fflush(stdin);
                            }while(opc != 'n' && opc != 'N');
                            break;

                        default:
                            break;
                    }
                }while(opc != 'f' && opc != 'f');
                
            break;
            
            case '2':
                system("cls");
                printf("\t\t---------------- Opcion 2 ----------------\n");
                printf("\t\t---------- Lista de Ingredientes ---------\n");
                mostrarListaI(ingredientes);
                system("pause");
            break;

            case '3':
                system("cls");
                printf("\t\t---------------- Opcion 3 ----------------\n");
                printf("\t\t------------- Menu de Ventas -------------\n\n");
                aux=1;
                bool resultado = false;
                printf("Hamburguesas disponibles:\n");

                auxH = hamburguesas;
                while (auxH != NULL){
                    printf("(%d) %s $%d\n",aux,auxH->nombre, auxH->precio);
                    auxH=auxH->sig;
                    aux++;
                }

                printf("\nOpcion a elegir: ");
                scanf("%d",&aux);
                fflush(stdin);
                auxH = hamburguesas;

                for(int i=0;i<(aux-1);i++){
                    auxH=auxH->sig;
                }
                
                listaIngre = auxH->IngrHamburguesa;
                if(venta(listaIngre,ingredientes)){
                    printf("Vendido.");
                    /* ------------------  obtengo la hora  ------------------ */
                    time_t tiempo = time(0);
                    struct tm *tlocal = localtime(&tiempo);
                    char horario[128];
                    strftime(horario,128,"%Y-%m-%d  %H:%M:%S",tlocal);
                    printf("\n%s\n",horario);
                    listaTicket = insertarNodoT(listaTicket,auxH->nombre/* ,cantidad */,auxH->precio,horario);
                }
                    
                else printf("No hay ingredientes suficientes");
                system("Pause");
            break;

            case '4':
                system("cls");
                printf("\t\t-------------------- Opcion 4 ---------------------\n");
                printf("\t\t---------- Lista de Hamburguesas Vendidas ---------\n");
                
                mostrarListaT(listaTicket);
                system("pause");
            break;

            case '5':
            break;

            case '6':
            break;

            case '7':
            break;
            
            case '8':
               mostrarListaH(hamburguesas);
               system("Pause");
            break;

            case '9':
            //CAPAZ HAY ALGO MAL ACA !!!!!!!!
                printf("\t\t---------------- Opcion 6 ----------------\n");
                printf("\t\t---------- Carga de Hamburguesa ----------\n");
                do{
                    printf("Nombre: ");
                    gets(nombreH);
                    fflush(stdin);
                    printf("Precio: "); 
                    scanf("%d",&cantH);
                    fflush(stdin); 
                    printf("Ingredientes: \n");
                    listaIngre=NULL;
                    do{
                        printf("\tNombre: ");
                        gets(nombreI);
                        fflush(stdin);
                        printf("\tCantidad: "); 
                        scanf("%d",&cantI);
                        fflush(stdin);                
                        listaIngre = insertarNodoI(listaIngre,nombreI,cantI);
                        printf("\tDesea ingresar otro ingrediente? [Y/N]: ");
                        scanf("%c",&opc2);
                        fflush(stdin);
                    }while(opc2 != 'n' && opc2 != 'N');               
                    hamburguesas = insertarNodoH(hamburguesas,nombreH,cantH,listaIngre);
                    printf("Desea agregar otra hamburguesa? [Y/N]: ");
                    scanf("%c",&opc);
                    fflush(stdin);
                }while(opc != 'n' && opc != 'N');
            break;
                
            case 'f':
                printf("Desea finalizar el programa?[y/n]:");
                scanf("%c",&opc);
                fflush(stdin);
                if(opc == 'y' || opc == 'Y')
                    menu = false;
            break;

            case 'F':
                printf("Desea finalizar el programa?[y/n]:");
                scanf("%c",&opc);
                fflush(stdin);
                if(opc == 'y' && opc == 'Y')
                    menu = false;
            break;

            default:
                printf("Opcion no valida. Por favor reingrese.\n");
                system("Pause");
            break;

            }
    system("cls");
    }while(menu);
    system("Pause");  
    return 0;
}
