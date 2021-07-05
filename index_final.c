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

bool venta(struct nodoHamburguesa *listaVenta, struct nodoIngrediente *ingredientes, int cant){
    bool sepuedevender=false;
    int aux1 = 1;
    struct nodoIngrediente *nuevoNodo= malloc(sizeof(struct nodoIngrediente));
    struct nodoIngrediente *aux= malloc(sizeof(struct nodoIngrediente));
    struct nodoHamburguesa *actual= malloc(sizeof(struct nodoHamburguesa));

    actual = listaVenta; 

    while(actual != NULL && aux1 ==1){
        aux = actual->IngrHamburguesa;
        while(aux != NULL){
            nuevoNodo = ingredientes;
            while(nuevoNodo != NULL){
                if(strcmp((aux->nombre),nuevoNodo->nombre)==0){
                    if(nuevoNodo->cant >= (aux->cant)*cant){
                        sepuedevender = true;
                        printf("\nHabia %d de %s y se le quieren descontar %d * %d",nuevoNodo->cant,nuevoNodo->nombre,aux->cant,cant);
                    }
                    else{
                        printf("\nNo hay suficiente %s, cantidad actual: %d\n",aux->nombre,nuevoNodo->cant);
                        sepuedevender = false;
                        aux1 = 0;
                    }
                }
                nuevoNodo=nuevoNodo->sig;
            }
            aux = aux->sig; 
        }
        actual=actual->sig;
    }

    actual = listaVenta;
    printf("\n%d",aux1);
    if(sepuedevender && aux1){
        while(actual != NULL){   
            aux = actual->IngrHamburguesa; 
            while(aux != NULL){  
                nuevoNodo = ingredientes;
                while(nuevoNodo != NULL){
                    if(strcmp((aux->nombre),nuevoNodo->nombre)==0){
                        printf("\nHabia %d %s y se descontaron %d * %d (cantidad de hambur pedidas)  y quedaron en total = ",nuevoNodo->cant,nuevoNodo->nombre,aux->cant,cant);      
                        nuevoNodo->cant =  nuevoNodo->cant- ((aux->cant)*cant);
                        printf("%d\n",nuevoNodo->cant);
                    }     
                    nuevoNodo=nuevoNodo->sig;
                }
                aux=aux->sig; 
            }   
            actual=actual->sig;
        }
    }

    return sepuedevender;
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
            printf("\n\n\t\t------------------ TICKET N%d --------------------\n",i);
            printf("\nProducto(s):");
            struct nodoHamburguesa *aux= malloc(sizeof(struct nodoHamburguesa));
            aux = actual->hamburVender;
            struct nodoCantidadH *aux1 =malloc(sizeof(struct nodoCantidadH));
            aux1 = actual->cantidad;
            while(aux != NULL){    
                printf("\n\t%s (%d) $%d.",aux->nombre,aux1->cant,aux->precio);
                aux = aux->sig;
                aux1 = aux1->sig;
            }
            printf("\nValor total: $%d.",actual->precio_total);
            printf("\nFecha y Hora: %s.\n\n",actual->fecha_hora);
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
        printf("\t\t---------------- Sistema Control ----------------\n");
        printf("\t\t-------------- Tito's Burguer & Co --------------\n");
        printf("\n1. Ingredientes.");
        printf("\n2. Hamburguesas.");
        printf("\n3. Ventas.");
        printf("\nF. Finalizar dia.\n");
        printf("\nOpcion a Ingresar: ");
        scanf("%c", &respuesta);
        fflush(stdin);
        switch (respuesta){

            case '1':
                do{
                system("cls");
                printf("\t\t---------------- Opcion 1 ----------------\n");
                printf("\t\t-------------- Ingredientes --------------\n\n");
                    printf("\n1. Cargar nuevo Ingrediente.");
                    printf("\n2. Actualizar Ingredientes.");
                    printf("\n3. Ver Lista de Ingredientes.");
                    printf("\nF. Salir\n");
                    printf("\nOpcion a Ingresar: ");
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
                                printf("Desea ingresar otro ingrediente? [Y/N]: ");
                                scanf("%c",&opc);
                                fflush(stdin);
                            }while(opc != 'n' && opc != 'N');
                        break;

                        case '2':
                            auxI = ingredientes;
                            aux=1;
                            printf("Ingredientes actuales:\n");
                            while (auxI != NULL){
                                printf("(%d) %s: %d\n",aux,auxI->nombre, auxI->cant);
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
                            printf("Saliendo...\n");
                            system("Pause");
                        break;

                        case 'F':
                            printf("Saliendo...\n");
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
                    printf("\t\t---------------- Opcion 2 ----------------\n");
                    printf("\t\t---------- Menu de Hamburguesas ----------\n");
                    printf("\n1. Ver Lista de Hambuguesas.");
                    printf("\n2. Cargar Nueva hamburguesa.");
                    printf("\nF. Salir\n");
                    printf("\nOpcion a Ingresar: ");
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
                                    printf("\tDesea ingresar otro ingrediente? [Y/N]: ");
                                    scanf("%c",&opc2);
                                    fflush(stdin);
                                }while(opc2 != 'n' && opc2 != 'N');               
                                hamburguesas = insertarNodoH(hamburguesas,nombre1,cant1,listaIngre);
                                printf("Desea agregar otra hamburguesa? [Y/N]: ");
                                scanf("%c",&opc);
                                fflush(stdin);
                            }while(opc != 'n' && opc != 'N');
                        break;

                        case 'f':
                            printf("Saliendo...\n");
                            system("Pause");
                        break;

                        case 'F':
                            printf("Saliendo...\n");
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
                    printf("\t\t---------------- Opcion 3 ----------------\n");
                    printf("\t\t------------- Menu de Ventas -------------\n\n");
                    printf("\n1. Realizar Venta.");
                    printf("\n2. Mostrar Ventas.");
                    printf("\nF. Salir\n");
                    printf("\nOpcion a Ingresar: ");
                    scanf("%c",&opc);
                    fflush(stdin);
                    switch (opc){
                        case '1':   
                                auxH=NULL; auxH1=NULL; cantidades=NULL;aux2=0;
                                int iterador_ventas=0;
                            do{
                                aux1=0;
                                aux=1;
                                printf("Hamburguesas disponibles:\n");
                                fflush(stdin);
                                auxH = hamburguesas;
                                while (auxH != NULL){
                                    printf("(%d) %s $%d\n",aux,auxH->nombre, auxH->precio);
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

                                printf("!! No hay ingredientes suficientes !!\n");

                                for(int i=0;i<iterador_ventas;i++){
                                    auxH1= auxH1->sig;
                                    printf("!! SE ENTRO AL IF ITERADOR DE AUXH1 !!\n");
                                }

                                if(venta(auxH1,ingredientes,aux1)){
                                    aux2 = 1;    
                                    cantidades = insertarNodoCantidad(cantidades,aux1);            
                                }

                                else printf("!! No hay ingredientes suficientes !!\n");
                                iterador_ventas++;
                                printf("\nDesea agregar otra Hamburguesa? [Y/N]: ");
                                scanf("%c",&opc);
                                fflush(stdin);

                            }while(opc != 'n' && opc != 'N');

                            if(aux2==1){
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
                                time_t tiempo = time(0);
                                struct tm *tlocal = localtime(&tiempo);
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
                            mostrarListaT(listaTicket);
                            system("pause");
                        break;

                        case 'f':
                            printf("Saliendo...\n");
                            system("Pause");
                        break;

                        case 'F':
                            printf("Saliendo...\n");
                            system("Pause");
                        break;

                        default:
                            printf("\nOpcion no valida. Por favor reingrese.\n");
                            system("Pause");
                        break;
                    }
                }while(opc != 'f' && opc != 'F');
            break;    

            case '5':
            break;

            case '6':
            break;
                
            case 'f':
                printf("Desea finalizar el dia?[y/n]:");
                scanf("%c",&opc);
                fflush(stdin);
                if(opc == 'y' || opc == 'Y')
                    menu = false;
            break;

            case 'F':
                printf("Desea finalizar el dia?[y/n]:");
                scanf("%c",&opc);
                fflush(stdin);
                if(opc == 'y' && opc == 'Y')
                    menu = false;
            break;

            default:
                printf("\nOpcion no valida. Por favor reingrese.\n");
                system("Pause");
            break;
            }
            
        system("cls");
    }while(menu);
    system("Pause");  
    return 0;
}
