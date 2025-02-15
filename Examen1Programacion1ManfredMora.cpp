#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdio>
#include <cstring>

#define IVA 0.13

char nombre[15];
char TipoCategoria[15];
int cantidad=0;
int cedula=0;
int categoria=0;
float precio=0;
int totalEntradas=0;
int contador=0;

float subtotal=0;
float impuestos=0;
float total=0;

int contadorEstandar = 0;
int contadorVIP = 0;
int contadorEstudiante = 0;

float totalEstandar = 0;
float totalVIP = 0;
float totalEstudiante = 0;

void ingresarDatos(){
		system("CLS");
	
		printf("Ingrese su nombre: ");
		scanf("%s", nombre);
	
		printf("Ingrese su numero de cedula: ");
		scanf("%i", &cedula);
	do{
	
		printf("Ingrese la categoria que desea comprar\n1-Estandar\n2-VIP\n3-Estudiante \n");
		scanf("%i", &categoria);
	if (categoria <1 || categoria>3){
		printf("Ingrese una categoria correcta: \n");
	}
	
	}while (categoria<1 || categoria>3);
	do{
	
		printf("Ingrese la cantidad de entradas a comprar (Maximo 5): ");
		scanf("%i", &cantidad);
	if (cantidad<1 || cantidad>5){
		printf("Solo puedes comprar entre 1 y 5 entradas. Intentelo de nuevo.\n");
	}
	
	}while(cantidad<1 || cantidad>5);
}


float cobro(){
	switch (categoria) {
        case 1:
            precio = 100;
            strcpy(TipoCategoria, "Estandar");
            contadorEstandar+=cantidad;
            totalEstandar += (precio * cantidad) + ((precio * cantidad) * IVA);
            break;
        case 2:
            precio = 200;
            strcpy(TipoCategoria, "VIP");
            contadorVIP+=cantidad;
            totalVIP += (precio * cantidad) + ((precio * cantidad) * IVA);
            break;
        case 3:
            precio = 75;
            strcpy(TipoCategoria, "Estudiante");
            contadorEstudiante+=cantidad;
            totalEstudiante += (precio * cantidad) + ((precio * cantidad) * IVA);
            break;
        default:
            printf("Categoría no válida.\n");
            return 0;
    }
	subtotal = precio * cantidad;
	impuestos = subtotal * IVA;
	total = subtotal + impuestos;
	
	contador++;
	totalEntradas += cantidad;
	
    return total; 
    
}




void mostrarDatos() {
	float totalaPagar = cobro();
    printf("\n*** Detalles de la Compra ***\n");
    printf("Nombre: %s\n", nombre);
    printf("Cedula: %i\n", cedula);
    printf("Categoria: %s\n", TipoCategoria);
    printf("Cantidad de entradas: %i\n", cantidad);
    printf("Subtotal: %.2f\n", subtotal);
    printf("Impuestos: %.2f\n", impuestos);
    printf("Precio total a pagar: %.2f\n", totalaPagar);
}

void reporteVentas(){
	printf("\n*** Reporte de Ventas ***\n");
    printf("Total de ventas realizadas: %i\n", contador);
    printf("Total de entradas vendidas: %i\n", totalEntradas);

    printf("\n--- Ventas por Categoria ---\n");
    printf("Estandar -> Entradas vendidas: %i | Monto total: %.2f\n", contadorEstandar, totalEstandar);
    printf("VIP -> Entradas vendidas: %i | Monto total: %.2f\n", contadorVIP, totalVIP);
    printf("Estudiante -> Entradas vendidas: %i | Monto total: %.2f\n", contadorEstudiante, totalEstudiante);
}


void menu(){
	
	int opcion = 0;
	do{
		system("CLS");
		printf("************ Menu principal ************\n");
		printf("1) Ingreso de datos \n");
		printf("2) Resumen de venta \n");
		printf("3) Reporte \n");
		printf("4) Salir \n");
		printf("************************************ \n");
		printf("Digite una opcion \n");
		scanf("%i", &opcion);
		
		
		switch(opcion){
			case 1: 
			system("CLS");
			ingresarDatos();
			getch();
			break;
			
			case 2: 
			system("CLS");
			mostrarDatos();
			getch();
			break;
			
			case 3: 
			system("CLS");
			reporteVentas();
			getch();
			break;
			
			case 4: 
			system("CLS");
			printf("Gracias por usar el sistema XD\n");
			getch();
			break;
			
			default: printf ("Opcion incorrecta\n");
			getch();
			break;
		}
	} while(opcion!=4);
	
}

int main(int argc, char** argv) {
	
	menu();
	return 0;
}
