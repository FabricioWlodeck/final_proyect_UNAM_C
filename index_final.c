#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<string.h>
#include<time.h>


struct nodoCantidadH{
    int cant;
    struct nodoCantidadH *sig;
};

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
    struct nodoHamburguesa *hamburVender;
    struct nodoCantidadH *cantidad;
    int precio_total;
    char fecha_hora[128];
    struct nodoTicket *sig;
};


/* ------------------- Colores ------------------- */

void titos(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("\t\t---------------- "); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(" Sistema Control ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf(" ----------------\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("\t\t--------------- ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Tito's Burguer & Co"); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf(" ---------------\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("1");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Ingredientes.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf("2");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Hamburguesas.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("3");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Ventas.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("F");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Finalizar dia.\n\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN);
    printf(" > ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Opcion a Ingresar: ");
}   

void menu1(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("\t\t---------------- "); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Opcion 1");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(" ----------------\n");
    printf("\t\t-------------- ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Ingredientes"); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(" --------------\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("1");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Cargar nuevo Ingrediente.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("2");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Actualizar Ingredientes.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("3");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Ver Lista de Ingredientes.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("F");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Salir\n\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("> ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Opcion a Ingresar: ");
}

void salir1(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("\nSaliendo...\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
}

void menu2(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf("\t\t---------------- "); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Opcion 2");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf(" ----------------\n");
    printf("\t\t---------- ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Menu de Hamburguesas"); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf(" ----------\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf("1");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Ver Lista de Hambuguesas.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf("2");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Cargar Nueva hamburguesa.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("F");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Salir\n\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf("> ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Opcion a Ingresar: ");    
}

void salir2(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE);
    printf("\nSaliendo...\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
}

void menu3(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("\t\t---------------- "); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Opcion 3");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf(" ----------------\n");
    printf("\t\t------------- ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Menu de Ventas"); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf(" -------------\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("1");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Realizar Venta.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("2");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Mostrar Ventas.\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("F");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf(". Salir\n\n");

    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
    printf("> ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("Opcion a Ingresar: "); 
}

void salir3(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("\nSaliendo...\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
}

void fin(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("S");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("/");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("N");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("]: ");
}

/* ------------------- Carga de Ingredientes ------------------- */

struct nodoIngrediente *crearNodoI(char nombre[30], int cant){
    struct nodoIngrediente *nuevoNodo; 
    nuevoNodo = malloc(sizeof(struct nodoIngrediente));        
    strcpy(nuevoNodo->nombre,nombre);
    nuevoNodo->cant = cant;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

struct nodoIngrediente *insertarNodoI(struct nodoIngrediente *ingrediente, char nombre[30], int cant){
    if(ingrediente == NULL) return crearNodoI(nombre, cant);
    else ingrediente->sig = insertarNodoI(ingrediente->sig,nombre,cant);
    return ingrediente;
}

/* ------------------- Muestra de Ingredientes ------------------- */

void mostrarListaI(struct nodoIngrediente *ingrediente){
    struct nodoIngrediente *actual=malloc(sizeof(struct nodoIngrediente));
    actual = ingrediente;
    if(ingrediente == NULL) printf("\n\n!! La lista de Ingredientes esta vacia !!\n\n");
    else{
        printf("\nIngredientes en stock: \n");
        while (actual != NULL){
            printf("%s: %d\n",actual->nombre, actual->cant);
            actual=actual->sig;
        }
    }
}

/* ------------------- Funcion Restock Ingredientes ------------------- */

void restock(struct nodoIngrediente *ingredientes, char nombre[30],int cant){
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

/* ------------------- Carga de Hamburguesas ------------------- */

struct nodoHamburguesa *crearNodoH(char nombre[30], int presio,struct nodoIngrediente *ingreHamb){
    struct nodoHamburguesa *nuevoNodo = malloc(sizeof(struct nodoHamburguesa));        
    strcpy(nuevoNodo->nombre,nombre);
    nuevoNodo->precio=presio;
    nuevoNodo->IngrHamburguesa = ingreHamb;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

struct nodoHamburguesa *insertarNodoH(struct nodoHamburguesa *hamburguesas, char nombre[30], int presio,struct nodoIngrediente *ingreHamb){
    if(hamburguesas == NULL){
        return crearNodoH(nombre, presio, ingreHamb);
    }
    else{
        hamburguesas->sig = insertarNodoH(hamburguesas->sig,nombre,presio,ingreHamb);
    }
    return hamburguesas;
}

/* ------------------- Muestra de Hamburguesas ------------------- */

void mostrarListaH(struct nodoHamburguesa *hamburguesas){
    int size_nodo = sizeof(struct nodoHamburguesa); //busco el tamano de la estructura
    struct nodoHamburguesa *actual=malloc(size_nodo); // creamos el nuevo nodo
    actual = hamburguesas;

    struct nodoIngrediente *ingredientes=malloc(size_nodo); // creamos el nuevo nodo
    
    if(hamburguesas == NULL){
        printf("\n\n!! La lista de Ingredientes esta vacia !!\n\n");
    }

    else{
        printf("\nLista de Hamburguesas: \n\n");
        while (actual != NULL){
            printf("%s \t$%d\n",actual->nombre, actual->precio);
            ingredientes = actual->IngrHamburguesa;
                while(ingredientes != NULL){
                    if(ingredientes->sig == NULL)
                        printf(" %s: %d\n",ingredientes->nombre, ingredientes->cant);
                    else
                        printf(" %s: %d ->",ingredientes->nombre, ingredientes->cant);
                    ingredientes=ingredientes->sig;
                }
            actual=actual->sig;
            printf("\n");
        }
    printf("\n\n");
    }
}

/* ------------------- FUNCION COMPARACION VENTAS ------------------- */

bool venta(struct nodoIngrediente *ingre_vender, struct nodoIngrediente *ingredientes, int cant){
    bool sepuedevender=false;
    int aux1 = 1;
    struct nodoIngrediente *nuevoNodo= malloc(sizeof(struct nodoIngrediente));
    struct nodoIngrediente *aux= malloc(sizeof(struct nodoIngrediente));
    struct nodoIngrediente *actual= malloc(sizeof(struct nodoIngrediente));

    actual = ingre_vender; 

    aux = actual;
    
    while(aux != NULL && aux1 ==1){
        nuevoNodo = ingredientes;
        while(nuevoNodo != NULL){
            if(strcmp((aux->nombre),nuevoNodo->nombre)==0){
                if(nuevoNodo->cant >= (aux->cant)*cant){
                    sepuedevender = true;
                }
                else{
                    printf("No hay suficiente %s, cantidad actual: %d\n",aux->nombre,nuevoNodo->cant);
                    sepuedevender = false;
                    aux1 = 0;
                }
            }
            nuevoNodo=nuevoNodo->sig;
        }
        aux = aux->sig; 
    }

    actual = ingre_vender;

    if(sepuedevender){
        aux = actual; 
        while(aux != NULL){  
            nuevoNodo = ingredientes;
            while(nuevoNodo != NULL){
                if(strcmp((aux->nombre),nuevoNodo->nombre)==0){
                //printf("habia: %s %d y desconte %s %d * %d",nuevoNodo->nombre,nuevoNodo->cant,aux->nombre,aux->cant,cant);
                    nuevoNodo->cant -= (aux->cant*cant);
                    if(nuevoNodo->cant < 10){
                        if(nuevoNodo->cant < 5){
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf("\n\tATENCION: Quedan menos de 5 %s en stock.\n",nuevoNodo->nombre);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
                        }
                        else{
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                            printf("\n\tATENCION: Quedan menos de 10 %s en stock.\n",nuevoNodo->nombre);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
                        }
                    }
                }
                nuevoNodo=nuevoNodo->sig;
            }
            aux=aux->sig; 
        }   
    }

    return sepuedevender;
}

/* ------------------- Carga de cantidades ------------------- */

struct nodoCantidadH *crearNodoCantidad(int cant){
    struct nodoCantidadH *nuevo_nodo =malloc(sizeof(struct nodoCantidadH));
    nuevo_nodo->cant = cant;
    nuevo_nodo->sig = NULL;
    return nuevo_nodo;
}

struct nodoCantidadH *insertarNodoCantidad(struct nodoCantidadH *cantidades, int cant){
    
    if(cantidades == NULL)
    return crearNodoCantidad(cant);
    
    else
    cantidades->sig = insertarNodoCantidad(cantidades->sig,cant);
}



/* ------------------  FUNCIONES TICKETS  ------------------ */

struct nodoTicket *crearNodoT(struct nodoHamburguesa *listaVenta,struct nodoCantidadH *cantidades, char tiempo[128],int preciofinal){
    struct nodoTicket *nuevoNodo = malloc(sizeof(struct nodoTicket));        
    nuevoNodo->hamburVender=listaVenta;
    nuevoNodo->cantidad=cantidades; 
    nuevoNodo->precio_total= preciofinal;
    strcpy(nuevoNodo->fecha_hora,tiempo);
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

struct nodoTicket *insertarNodoT(struct nodoTicket *tickets,struct nodoHamburguesa *listaVenta,struct nodoCantidadH *cantidades, char tiempo[128],int preciofinal){

    if(tickets == NULL)
    return crearNodoT(listaVenta, cantidades, tiempo,preciofinal);

    else
    tickets->sig = insertarNodoT(tickets->sig,listaVenta, cantidades, tiempo, preciofinal);

    return tickets;
}

void mostrarListaT(struct nodoTicket *tickets){
    int size_nodo = sizeof(struct nodoTicket); 
    struct nodoTicket *actual=malloc(size_nodo); 
    actual = tickets;
    int auxprecio=0,i=1;
    
    if(tickets == NULL){
        printf("\n\n!! La lista de Tickets esta vacia !!\n\n");
    }

    else{
        while (actual != NULL){ 
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("\n\t\t------------------ ");
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("TICKET N%d",i);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf(" --------------------\n");
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_GREEN);
            printf("\nProducto(s):");
            struct nodoHamburguesa *aux= malloc(sizeof(struct nodoHamburguesa));
            aux = actual->hamburVender;
            struct nodoCantidadH *aux1 =malloc(sizeof(struct nodoCantidadH));
            aux1 = actual->cantidad;
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            while(aux != NULL){    
                printf("\n\t%s (%d) $%d.",aux->nombre,aux1->cant,aux->precio);
                aux = aux->sig;
                aux1 = aux1->sig;
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("\nValor total: $%d.",actual->precio_total);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("\nFecha y Hora: %s.\n\n",actual->fecha_hora);
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            actual=actual->sig;
            
            i++;
        }
    }
}



int main(){
    struct nodoIngrediente *ingredientes=NULL;
    struct nodoIngrediente *auxI=NULL;
    struct nodoHamburguesa *hamburguesas=NULL;
    struct nodoHamburguesa *auxH=NULL;
    struct nodoHamburguesa *auxH1=NULL;
    struct nodoIngrediente *listaIngre=NULL;
    struct nodoTicket *listaTicket=NULL;
    struct nodoCantidadH *cantidades = NULL;

    //hora de inicii
    time_t tiempo = time(0);
    struct tm *tinicio = localtime(&tiempo);
    char inicio[128];
    strftime(inicio,128,"%Y-%m-%d  %H:%M:%S",tinicio);


    char nombre[30],nombre1[30],respuesta,opc,opc2;
    int aux,aux1,aux2=0,cant,cant1;
    bool menu=true;

    ingredientes = insertarNodoI(ingredientes,"Pan",20);
    ingredientes = insertarNodoI(ingredientes,"Medallon",20);
    ingredientes = insertarNodoI(ingredientes,"Cheddar",20);
    ingredientes = insertarNodoI(ingredientes,"Panceta",30);
    ingredientes = insertarNodoI(ingredientes,"Tomate",10);
    ingredientes = insertarNodoI(ingredientes,"Lechuga",30);

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

    listaIngre=NULL;

    listaIngre = insertarNodoI(listaIngre,"Pan",2);
    listaIngre = insertarNodoI(listaIngre,"Medallon lentejas",1);
    listaIngre = insertarNodoI(listaIngre,"Tomate",1);
    listaIngre = insertarNodoI(listaIngre,"Lechuga",1);
    hamburguesas = insertarNodoH(hamburguesas,"Vegana",18,listaIngre);

    do{
        titos();
        scanf("%c", &respuesta);
        fflush(stdin);
        switch (respuesta){

            case '1':
                do{
                system("cls");
                    menu1();            
                    scanf("%c",&opc);
                    fflush(stdin);
                    switch (opc){
                        case '1':
                            do{
                                printf("Nombre: ");
                                gets(nombre);
                                fflush(stdin);
                                printf("Cantidad: "); 
                                scanf("%d",&cant);
                                fflush(stdin);
                                ingredientes = insertarNodoI(ingredientes,nombre,cant);
                                printf("Desea ingresar otro ingrediente? [");
                                fin();
                                scanf("%c",&opc);
                                fflush(stdin);
                            }while(opc != 'n' && opc != 'N');
                        break;

                        case '2':
                            auxI = ingredientes;
                            aux=1;
                            printf("Ingredientes actuales:\n");
                            while (auxI != NULL){
                                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN);
                                printf("(%d)",aux); 
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
                                printf(" %s: %d\n",auxI->nombre, auxI->cant);
                                auxI=auxI->sig;
                                aux++;
                            }
                            printf("\nOpcion a elegir: ");
                            scanf("%d",&aux);
                            fflush(stdin);
                            printf("Cantidad a agregar: "); 
                            scanf("%d",&cant);
                            fflush(stdin);
                            auxI= ingredientes;

                            for(int i=0;i<(aux-1);i++){
                                auxI=auxI->sig;
                            }
                            restock(ingredientes,auxI->nombre,cant);
                        break;

                        case '3':
                            mostrarListaI(ingredientes);
                            system("pause");
                        break;

                        case 'f':
                            salir1();
                            system("Pause");
                        break;

                        case 'F':
                            salir1();
                            system("Pause");
                        break;

                        default:
                            printf("\nOpcion no valida. Por favor reingrese.\n");
                            system("Pause");
                        break;
                    }
                system("cls");
                }while(opc != 'f' && opc != 'F');
            break;

            case '2':
                do{
                    system("cls");
                    menu2();
                    scanf("%c",&opc);
                    fflush(stdin);
                    switch (opc){

                        case '1':
                            mostrarListaH(hamburguesas);
                            system("Pause");
                        break;

                        case '2':    
                            do{
                                printf("Nombre: ");
                                gets(nombre1);
                                fflush(stdin);
                                printf("Precio: "); 
                                scanf("%d",&cant1);
                                fflush(stdin); 
                                printf("Ingredientes: \n");
                                listaIngre = NULL; 
                                do{
                                    printf("\tNombre: ");
                                    gets(nombre);
                                    fflush(stdin);
                                    printf("\tCantidad: "); 
                                    scanf("%d",&cant);
                                    fflush(stdin);               
                                    listaIngre = insertarNodoI(listaIngre,nombre,cant);
                                    printf("\tDesea ingresar otro ingrediente? [");
                                    fin();
                                    scanf("%c",&opc2);
                                    fflush(stdin);
                                }while(opc2 != 'n' && opc2 != 'N');               
                                hamburguesas = insertarNodoH(hamburguesas,nombre1,cant1,listaIngre);
                                printf("Desea agregar otra hamburguesa? [");
                                fin();
                                scanf("%c",&opc);
                                fflush(stdin);
                            }while(opc != 'n' && opc != 'N');
                        break;

                        case 'f':
                            salir2();
                            system("Pause");
                        break;

                        case 'F':
                            salir2();
                            system("Pause");
                        break;

                        default:
                            printf("\nOpcion no valida. Por favor reingrese.\n");
                            system("Pause");
                        break;
                    }
                }while(opc != 'f' && opc != 'F');    
            break;

            case '3':

                do{
                    system("cls");
                    menu3();
                    scanf("%c",&opc);
                    fflush(stdin);
                    switch (opc){
                        case '1':   
                                auxH=NULL; auxH1=NULL; cantidades=NULL;aux2=0;
                            do{
                                aux1=0;
                                aux=1;
                                printf("Hamburguesas disponibles:\n");
                                fflush(stdin);
                                auxH = hamburguesas;
                                while (auxH != NULL){
                                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                                    printf("(%d)",aux); 
                                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
                                    printf("%s $%d\n",auxH->nombre, auxH->precio);
                                    auxH=auxH->sig;
                                    aux++;
                                }
                                fflush(stdin);
                                printf("\nOpcion a elegir: ");
                                scanf("%d",&aux);
                                fflush(stdin);
                                printf("Cantidad: ");
                                scanf("%d",&aux1);
                                fflush(stdin);
                                auxH = hamburguesas;
                                fflush(stdin);

                                for(int i=0;i<(aux-1);i++){
                                    auxH=auxH->sig;
                                }

                                auxH1=insertarNodoH(auxH1,auxH->nombre,auxH->precio,auxH->IngrHamburguesa);

                                if(venta(auxH->IngrHamburguesa,ingredientes,aux1)){
                                    aux2 = 1;    
                                    cantidades = insertarNodoCantidad(cantidades,aux1);              
                                }

                                else printf("!! No hay ingredientes suficientes !!\n");

                                printf("\nDesea agregar otra Hamburguesa? [");
                                fin();
                                scanf("%c",&opc);
                                fflush(stdin);

                            }while(opc != 'n' && opc != 'N');

                            if(aux2 == 1){
                                /* ----------------  obtengo precio total ---------------- */
                                struct nodoHamburguesa *aux4= malloc(sizeof(struct nodoHamburguesa));
                                aux4 = auxH1;
                                struct nodoCantidadH *aux5 =malloc(sizeof(struct nodoCantidadH));
                                aux5 = cantidades;
                                aux1 = 0;
                                while(aux4 != NULL){
                                    aux = aux4->precio*aux5->cant;
                                    aux1 += aux;
                                    aux5 = aux5->sig;
                                    aux4 = aux4->sig;
                                }

                                /* ------------------  obtengo la hora  ------------------ */
                                time_t tiempo1 = time(0);
                                struct tm *tlocal = localtime(&tiempo1);
                                char horario[128];
                                strftime(horario,128,"%Y-%m-%d  %H:%M:%S",tlocal);
                                printf("\n\nVenta Realizada exitosamente.");
                                printf("\nPrecio total: $%d",aux1);
                                printf("\n%s\n",horario);

                                /* ------------------  inserto el ticket  ------------------ */
                                listaTicket = insertarNodoT(listaTicket,auxH1,cantidades,horario,aux1);  
                            }

                            system("Pause");
                        break;

                        case '2':
                            system("cls");
                            mostrarListaT(listaTicket);
                            system("pause");
                        break;

                        case 'f':
                            salir3();
                            system("Pause");
                        break;

                        case 'F':
                            salir3();
                            system("Pause");
                        break;

                        default:
                            printf("\nOpcion no valida. Por favor reingrese.\n");
                            system("Pause");
                        break;
                    }
                }while(opc != 'f' && opc != 'F');
            break;    
                
            case 'f':
                printf("Desea finalizar el dia?[");
                fin();
                scanf("%c",&opc);
                fflush(stdin);
                if(opc == 's' || opc == 'S')
                    menu = false;
            break;

            case 'F':
                printf("Desea finalizar el dia?[");
                fin();
                scanf("%c",&opc);
                fflush(stdin);
                if(opc == 's' && opc == 'S')
                    menu = false;
            break;

            default:
                printf("\nOpcion no valida. Por favor reingrese.\n");
                system("Pause");
            break;
            }
            
        system("cls");
    }while(menu);

    system("cls");

    //hora de fin
    time_t tiempo2 = time(0);
    struct tm *tfinal = localtime(&tiempo2);
    char fin[128];
    strftime(fin,128,"%Y-%m-%d  %H:%M:%S",tfinal);

    aux = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    printf("\t\t\t\t\t VENTAS DEL DIA \n");
    mostrarListaT(listaTicket);
    while (listaTicket){
        aux += listaTicket->precio_total;
        listaTicket = listaTicket->sig;
    }
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    printf("\n\t\tInicio Jornada: %s\tFin de Jornada: %s\n",inicio,fin);
    printf("\n\t\t\t\t\t TOTAL GANADO: $%d\n\n",aux);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    system("Pause");  
    return 0;
}
