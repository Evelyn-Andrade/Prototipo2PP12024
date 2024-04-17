#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

class menuG
{
    public:
        menuG(string id, string nombre, string precio, string cantidad);
       string setId(string id);
        string getId();

        string setNombre(string nombre);
        string getNombre();

        string setPrecio(string precio);
        string getPrecio();

        string setCantidad(string cantidad);
        string getCantidad();

};
