#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int item;
const int indefinido=-9999;

struct nodo {
    item dato;
    struct nodo *siguiente;
};
typedef struct nodo *Nodo;

struct listaCircular {
    Nodo cabecera;
    int longitud;
};
typedef struct listaCircular LC;



LC LCVacia();
int esLCVacia(LC listaCirc);
LC insertar(LC listaCirc, item X);
LC borrar(LC listaCirc);
LC rotar(LC listaCirc);
item valor(LC listaCirc);
void mostrar(LC listaCirc);
int contarK(LC listaCirc, item X);


int main(){

    LC listaCirc;
    item primerElemento;

    listaCirc = LCVacia();
    
    listaCirc = insertar(listaCirc, 1);
    listaCirc = insertar(listaCirc, 2);
    listaCirc = insertar(listaCirc, 3);
    listaCirc = insertar(listaCirc, 4);
    listaCirc = insertar(listaCirc, 5);

    printf("\n\n------Comienza el programa------\n");

    mostrar(listaCirc);


    printf("\nAgrego dos elementos...");
    listaCirc = insertar(listaCirc, 55);
    listaCirc = insertar(listaCirc, 56);
    mostrar(listaCirc);


    printf("\nBorrando un elemento...");
    listaCirc = borrar(listaCirc);
    mostrar(listaCirc);


    printf("\nRotando lista...");
    listaCirc = rotar(listaCirc);
    mostrar(listaCirc);
    

    int cant = 0;
    cant = contarK(listaCirc, 2);
    printf("\nEl número [2] aparece [%d] veces\n", cant);

    
    
    return 0;
}


LC LCVacia()
{
    LC listaCirc;

    listaCirc.longitud = 0;
    listaCirc.cabecera = NULL;

    return listaCirc;
}

int esLCVacia(LC listaCirc)
{
    if (listaCirc.cabecera == NULL)
    {
        return(true);
    } else
    {
        return(false);
    }
}

LC insertar(LC listaCirc, item X)
{
    Nodo nuevo;

    nuevo = (Nodo)malloc(sizeof(struct nodo));

    nuevo->dato = X;

    if (esLCVacia(listaCirc))
    {
        listaCirc.cabecera = nuevo;
        nuevo->siguiente = listaCirc.cabecera;
    } else
    {
        nuevo->siguiente = listaCirc.cabecera->siguiente;
        listaCirc.cabecera->siguiente = nuevo;
    }
    
    listaCirc.longitud++;

    return listaCirc;
}

LC borrar(LC listaCirc)
{
    Nodo aux;
    aux = listaCirc.cabecera->siguiente;

    if (!esLCVacia(listaCirc))
    {
        if (listaCirc.longitud == 1)
        {
            listaCirc.cabecera = NULL;
        } else
        {
            listaCirc.cabecera->siguiente = aux->siguiente;            
        }
    }
    
    free(aux);
    listaCirc.longitud--;

    return listaCirc;
}

LC rotar(LC listaCirc)
{
    if (!esLCVacia(listaCirc))
    {
        listaCirc.cabecera = listaCirc.cabecera->siguiente;
    }

    return listaCirc;
}

item valor(LC listaCirc)
{
    return listaCirc.cabecera->siguiente->dato;
}

void mostrar(LC listaCirc)
{
    printf("\nNodos en la lista: |--");

    if (!esLCVacia(listaCirc))
    {
        for (int i = 0; i < listaCirc.longitud; i++)
        {
            printf("%d--",valor(listaCirc));
            listaCirc =rotar(listaCirc);
        }   
    }

    printf("|\n\n");
}

int contarK(LC listaCirc, item X)
{
    if (listaCirc.longitud == 0)
    {
        return 0;
    } else if (valor(listaCirc) == X)
    {   
        listaCirc.longitud--;
        return 1 + contarK(rotar(listaCirc), X);
    } else
    {
        listaCirc.longitud--;
        return contarK(rotar(listaCirc), X);
    }   
}

