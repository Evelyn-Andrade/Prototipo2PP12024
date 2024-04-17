#include "menuG.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

menuG::menuG(string id, string nombre, string precio, string cantidad)
{
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

string menuG::setId( string id)
{
    this-> id=id;
}
string menuG::getId()
{
    return this -> id;
}

string menuG::setNombre(string nombre)
{
    this->nombre=nombre;
}

string menuG::getNombre()
{
    return this->nombre;
}

string menuG::setPrecio(string precio)
{
    this->precio=precio;
}

string menuG::getPrecio()
{
    return this->precio;
}

string menuG::setCantidad(string cantidad)
{
    this->cantidad=cantidad;
}

string menuG::getCantidad()
{
    return this->cantidad;
}

void menuG::menuPrincipal()
{
        bool salir = false;
    int opcion;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|       MENU DE CATALOGOS         |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. CRUD CATALOGOS"<<endl;
	cout<<"\t\t\t 2. INFORMES"<<endl;
	cout<<"\t\t\t 3. Retroceder"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        submenu();
		break;
	case 2:

		desplegar();
		system("pause");
        system ("cls");
		break;
	case 3:
	    salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu catalogo";
	}
    }while(opcion!= 3);
}

void menuG::submenu()
{
int opcion;
    char x;
    bool repetir=true;
    system("cls");
   do
   {

     cout <<"\t\t\t--------------------------------------------"<<endl;
    cout <<"\t\t\t |       MENU De USUARIOS     |"<<endl;
    cout <<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso nuevos productos"<<endl;
	cout<<"\t\t\t 2. Modificar Productos"<<endl;
	cout<<"\t\t\t 3. Borrar Productos"<<endl;
	cout<<"\t\t\t 4. Retroceder"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";

    cin>>opcion;

    switch(opcion)

   //--------------------------------------------------------------------------------------------------
    {

    case 1:
        do
            {  insertar(); //metodo para ingresar usuarios
                cout<<"\n\t\t\t Agregar otra persona (S/N)"<<endl;
                cin>>x;//Recibe algo del usuario
            } while(x=='s'|| x=='S');// si el char que recive el usuario es S o s repetir el ciclo
            system("cls");
        break;
 //--------------------------------------------------------------------------------------------------

    case 2:
        modificar();
        system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 3:
         borrar();
         system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 4:
        break;
 //-------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    break;}
        }while(opcion!= 4);

}
void menuG::desplegar()
{
   system("cls");
int total=0;

//imprimir encabezado
cout<<"\n-------------------------Tabla de Productos Registrados-------------------------"<<endl;
fstream fileDesplegar;
fileDesplegar.open("catalogos.txt",ios::in);
//condicion si el archivo no se puede abrir
if(!fileDesplegar)
    {
    cout<<"\n\t\t\tNo hay información..."; // muestra un mensaje de error
		fileDesplegar.close(); // cierra el archivo
    }
else
    {
        fileDesplegar >> id>> nombre>>precio>>cantidad;//lee el primer registro del archivo
        //condicion de seguir leyendo registrso hasta llegar al final del registro
        while(!fileDesplegar.eof())
        {
         total++;//contado de usuarios
         cout<<"\t\t\t ID "<<id<<endl; // muestra el nombre del usuario
         cout<<"\t\t\t NOMBRE: "<<nombre<<endl;
         cout<<"\t\t\t PRECIO: "<<precio<<endl;
        cout<<"\t\t\t CANTIDAD: "<<cantidad<<endl<<endl<<endl;
        fileDesplegar >> id>> nombre>>precio>>cantidad;//leera el siguiente registro del archivo
        }

        if(total==0)//si no llegara a encontrar ningun registro en el archivo
        {
            cout<<"\n\t\t\tNo hay informacion..."; // muestra un mensaje de error
        }
    }
    fileDesplegar.close();
}

void menuG::insertar()
{
    system("cls");
    string id,nombre,precio,cantidad;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Producto--------------------------------------------"<<endl;
    cout << "\t\t\t\nIngrese el ID de producto):         ";
    cin >> id;
      cout << "\t\t\t\nIngrese el nombre de producto:         ";
    cin >> nombre;
      cout << "\t\t\t\nIngrese el precio de producto:         ";
    cin >> precio;
      cout << "\t\t\t\nIngrese la cantidad de producto:         ";
    cin >> cantidad;

    // Abre el archivo "" en modo de apendizaje y escritura
    fstream fileIngresar;
    fileIngresar.open("catalogos.txt",ios::app| ios:: out);

    // Escribe en el archivo los datos del usuario ingresados por el usuario
    fileIngresar<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< precio<<std::left <<std::setw(15)<< cantidad<<"\n";

    //cierre del archivo
    fileIngresar.close();
    //mensaje de exito

    cout << "\t\t\t\n registrado exitosamente."<<endl;


}

void menuG::modificar()
{

	system("cls");
    fstream fileOri, fileModif;  // Se crean dos objetos de archivo para leer y escribir en archivos de texto
    string productoModificar;  // Se define una cadena para almacenar el nombre del usuario a modificar

    int contador=0;  // Se define una variable para contar si se encuentra el usuario en el archivo
    cout<<"\n-------------------------Modificar Productos-------------------------"<<endl;  // Muestra un mensaje en pantalla
    fileOri.open("catalogos.txt",ios::in);  // Abre el archivo de texto en modo lectura

    if(!fileOri)  // Si el archivo no se pudo abrir
    {
        cout<<"\n\t\t\tNo hay informacion..,";  // Muestra un mensaje en pantalla
        fileOri.close();  // Cierra el archivo
    }
    else  // Si el archivo se pudo abrir
    {
        cout<<"\n Ingrese el nombre del producto que quiere modificar: ";  // Muestra un mensaje en pantalla para ingresar el usuario a modificar
        cin>>productoModificar;  // Lee el nombre del usuario a modificar
        fileModif.open("record2.txt",ios::app | ios::out);  // Abre otro archivo de texto en modo escritura y agrega el contenido al final del archivo
        fileOri >> id>> nombre>>precio>>cantidad;  // Lee el primer usuario y contraseña del archivo

        while(!fileOri.eof())  // Mientras no se llegue al final del archivo
        {
            if(productoModificar!=nombre)  // Si el usuario no es el que se quiere modificar
                {
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar


                }

            else  // Si se encuentra el usuario a modificar
                {
                cout << "\t\t\t\nIngrese el nuevo ID:         ";
                cin >> id;
                cout << "\t\t\t\nIngrese el nuevo nombre:         ";
                cin >> nombre;
                cout << "\t\t\t\nIngrese el nuevo precio:         ";
                cin >> precio;
                cout << "\t\t\t\nIngrese la nueva cantidad:         ";
                cin >> cantidad;
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar
                contador++;  // Incrementa el contador de usuarios modificados
                cout << "\t\t\t\n Modificado exitosamente.";
                }

                    fileOri >> id>> nombre>>precio>>cantidad; // Lee el siguiente usuario y contraseña del archivo
        }

        fileModif.close();  // Cierra el archivo temporal
        fileOri.close();  // Cierra el archivo original

        remove("catalogos.txt");  // Elimina el archivo original
        rename("record2.txt","catalogos.txt");  // Renombra el archivo temporal con el nombre del archivo original
         cout << "\t\t\t\n ...";
          // Muestra un mensaje en pantalla
    }
}

