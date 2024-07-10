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
const int ventalimite = 10;
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
		cout << "La cantidad es mayor al limite\n" << endl;
		
	}else{
		producto art;
		cout << "Digite el producto: ";
		cin.ignore();
		getline(cin,art.nombre);
		cout << "Ingrese el precio del producto: ";
		cin >> art.precio;
		cout << "\n";
		prod[cantidadproducto] = art;
		cantidadproducto++;
		cout << "producto registrado\n"<< endl;
	}
} 
void listarproducto(producto prod[], int cantidadproducto){
	if(cantidadproducto == 0){
		cout<<"\nNingun producto añadido "<<endl;
	}else{
	   for(int i=0; i<cantidadproducto; ++i){
	   		cout<<"Nombre: "<<prod[i].nombre<<endl;
	   		cout<<"Precio: "<<prod[i].precio<<endl;
	   		cout<<"\n"; 
	   }
	}
}
void buscarProducto(producto articulo[], int cantidadproducto, const string& nombre){ 
		bool confirmacion = false; 
        cout<<"Busqueda del producto\n"; 
	 	for(int i=0; i<cantidadproducto; ++i){
	 		if(articulo[i].nombre == nombre){
	 			cout<<"Producto: "<<i+1<<" | "<<" -> "<<"INDICE: "<<i<<endl; 
 				cout<<"Nombre del producto: "<<articulo[i].nombre<<endl;
 				cout<<"Precio del producto: "<<articulo[i].precio<<endl;
				cout<<"\n";
				confirmacion = true; 
		 		break; 
 	        }
         }
 	        if (confirmacion == false){
    	        cout<<"\nEl producto:  '"<<nombre<<"' no se logro encontraro.\n";
   		    }
}
void actualizarproducto(producto articulo[], int cantidadproducto, int indice){
	if(indice<0 || indice>=cantidadproducto){
	 	cout<<"Indice no valido. "; 
		 return;
	}
        cout<<"\nActualizando producto...\n"; 
        cout<<"Digite el nuevo producto: ";
		cin.ignore();
		getline(cin,articulo[indice].nombre); 
		cout<<"Ingrese su nuevo precio: "; 
		cin>>articulo[indice].precio; 
		cout<<"\n"; 
	cout<<"Actualizado producto\n";
}
void eliminarproducto(producto articulo[], int cantidadproducto, int indice){
	if(indice<0 || indice>=cantidadproducto){
		cout << "Indice no valido" << endl;
		return;
	}	
	for (int i=indice; i<cantidadproducto-1; i++){
		articulo[i]=articulo[i+1];
	}
	cantidadproducto--;
	cout << "Producto eliminado\n " << endl;
}

void registrarventa(venta vent[], producto prod[], int cantidadproducto, int &cantidadventa) {
    if (cantidadventa >= ventalimite) {
        cout << "Sin espacio suficiente\n";
        return;
    }
    venta nuevaventa;
    cout <<"Nombre del producto vendido: ";
    cin.ignore();
    getline(cin, nuevaventa.producto);
    bool confirmacion = false;
    for (int i = 0; i < cantidadproducto; ++i) {
        if (prod[i].nombre == nuevaventa.producto) {
            confirmacion = true;
            nuevaventa.preciototal = prod[i].precio;
            break;
        }
    }
    if (confirmacion = false) {
        cout << "El producto no existe. No se puede registrar la venta.\n";
        return;
    }
    cout << "Ingrese la cantidad vendida: ";
    cin >> nuevaventa.cantidad;
    nuevaventa.preciototal *= nuevaventa.cantidad;
    nuevaventa.idventa = cantidadventa + 1;
    vent[cantidadventa] = nuevaventa;
    cantidadventa++;
    cout << "Venta registrada\n";
}
void listaventa(venta vent[], int cantidadventa){
	if(cantidadventa == 0){
		cout<<"Nose registro ninguna venta. :( "<<endl;  
	}
	else{
		cout<<"Registro de venta: "<<endl; 
		for(int i=0; i<cantidadventa; ++i){
			cout<<"Venta : "<<i+1<<" | "<<"INDICE: "<<" -> "<<i<<endl; 
			cout<<"Identificador venta: "<<vent[i].idventa<<endl; 
			cout<<"Nombre del producto vendido: "<<vent[i].producto<<endl; 
			cout<<"Cantidad que se vendio: "<<vent[i].cantidad<<endl; 
			cout<<"Precio en el que se vendio: "<<vent[i].preciototal<<endl; 
			cout<<"\n"; 
		}
	}
} 
int main(){
	producto prod[limite];
	venta	 vent[ventalimite];
	int respuesta, indice;
	int cantidadproducto = 0;
	int cantidadventa = 0;
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
				listarproducto(prod, cantidadproducto);
			case 3:
				{
				string nombre; 
	      	    cout<<"\nNombre del producto para buscar: "; 
	      	    cin.ignore(); 
	      	    getline(cin, nombre); 
     	        buscarProducto(prod, cantidadproducto, nombre); 
     	        break;
				}
			case 4:
				cout << "Ingrese el indice a actualizar el producto: " << endl;
				cin >> indice;
				actualizarproducto(prod, cantidadproducto, indice);
				break;
			case 5:
				cout << "Ingresar el indice a eliminar su producto: " << endl;
				cin >> indice;
				eliminarproducto(prod, cantidadproducto, indice);
				break;
			case 6:
				registrarventa(vent, prod, cantidadproducto, cantidadventa);
				break;
			case 7:
				listaventa(vent, cantidadventa);
				break;
			default:
				break;
		}
	}while(9!=0);
	return 0;
}
