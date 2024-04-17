// Evelyn Sofia Andrade Luna
// 9959-23-1224
#include <iostream>
#include <usuario.h>
#include <menuG.h>
#include <caratula.h>
using namespace std;

int main()
{

    Juego juego;
    juego.dibujarPortada("Portada.txt");

    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.get();    // Esperar a que el usuario presione una tecla
    system("cls");
// ---------------------------------------------------------------------------------------------
    //variables de user y contraseña
    string user,contrasena;
    //llmamos al objeto e ingresamos los parametros
    usuario ingreso(user,contrasena);

     string id, nombre, precio, cantidad;
        menuG catalogos(id, nombre, precio, cantidad);

    //creamos un bool  que verifique y despliegue el metodo verificarUsuario
    bool UsuarioCorrecto=ingreso.VerificarUsuario();


    //luego de ingresar con usuario y contraseña se nos desplega otro menu
    if(UsuarioCorrecto)
    {
        int opcion;
        char  x;
        do
        {
        	system("cls");

    cout <<"\t\t\t--------------------------------------------"<<endl;
    cout <<"\t\t\t |       BIENVENIDO AL MENU PRINCIPAL      |"<<endl;
    cout <<"\t\t\t |Nombre: Evelyn Sofia Andrade Luna"<<endl;
    cout <<"\t\t\t |Carnet: 9959-23-1224                     |"<<endl;
    cout <<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Al Menu de Usurios"<<endl;
	cout<<"\t\t\t 2. Ingreso Al Menu de Catalogos"<<endl;
	cout<<"\t\t\t 3. Salir del sistema"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;
    switch(opcion){
    case 1:
        ingreso.MenuUser();//ingresa al menu de usuarios
        break;
    case 2:
        catalogos.menuPrincipal();//ingresa el submenu del catalogos
        break;
    case 3:
        exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;}
        }while(opcion!= 3);

    }
    return 0;
}
