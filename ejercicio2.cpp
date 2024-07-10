/*
Inventario de Productos y Ventas
Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar 
productos, así como gestionar las ventas.
Requisitos:
• Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
• Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad 
(entero), precioTotal (flotante).
• Implementa un menú con las siguientes opciones:
A: Registrar un nuevo producto.
B: Listar los productos registrados.
C: Buscar un producto por nombre.
D: Actualizar los datos de un producto.
E: Eliminar un producto.
F: Registrar una venta.
G: Listar las ventas realizadas.
H: Calcular el total de ventas realizadas.
S: Salir del programa.
• El menú debe estar ciclado y permitir volver al menú principal después de cada opción
*/
#include <iostream>
#include <string.h>
using namespace std;
const int limite = 10;
struct producto{
	string nombre;
	float precio;
};
struct venta{
	int idventa;
	string producto;
	int cantidad;
	float preciototal;
};
void registrarproducto(producto prod[], int &cantidadproducto){
	if (cantidadproducto >= limite){
		cout << "La cantidad es mayor al limite" << endl;
		
	}else{
		producto art;
		cout << "Digite el producto";
		cin.ignore();
		getline(cin,art.nombre);
		cout << "Ingrese el precio del producto";
		cin >> art.precio;
		cout << "\n";
		prod[cantidadproducto] = art;
		cantidadproducto++;
		cout << "producto registrado"<< endl;
	}
} 
void listarproducto(producto prod[], int cantidadproducto){
	if(cantidadproducto == 0){
		cout<<"\nNingun producto añadido "<<endl;
	}else{
	   for(int i=0; i<cantidadproducto; ++i){
	   		
	    	cout<<"Nombre: "<<art[i].nombre<<endl;
	   		cout<<"Precio: "<<art[i].precio<endl;
	   		cout<<"\n"; 
	   }
	}
}

int main(){
	producto prod[limite];
	venta	 vent[limite];
	int respuesta;
	int cantidadproducto = 0;
	do {
		cout << "INVENTARIO DE PRODUCTOS Y VENTAS" << endl;
		cout << "Elije una opcion" << endl;
		cout << "1-Registrar un nuevo producto."<< endl;
		cout << "2- Listar los productos registrados."<< endl;
		cout << "3-Buscar un producto por nombre."<< endl;
		cout << "4-Actualizar los datos de un producto."<< endl;
		cout << "5- Eliminar un producto."<< endl;
		cout << "6- Registrar una venta."<< endl;
		cout << "7- Listar las ventas realizadas."<< endl;
		cout << "8- Calcular el total de ventas realizadas."<< endl;
		cout << "9- salir del programa."<< endl;
		cin >> respuesta;
			
		switch (respuesta){
			case 1:
				registrarproducto(prod, cantidadproducto);
				break;
			case 2:
				listarproductos(prod, cantidadproducto)
			default:
				break;
		}
	}while(9!=0);
	
	return 0;
}
