//Elaborar un programa utilizando iterator que pide nombre y tres calificaciones, imprime el nombre y el promedio
#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;
void insertar()
{
    int c=1, k=1, kalifCont=0;;
    string namae;
    float calif, prom;
    list <string> nombres;
    list <float> calificaciones;
    list <float> promedios;
    while (c<4){
        system("COLOR 0B");
        cout<<"ESCRIBE EL NOMBRE DEL ALUMNO NUMERO "<< c<<endl;
        cin>>namae;
        nombres.push_back(namae);
        c++;
    }
    list<string>::iterator it = nombres.begin();
    it = nombres.begin();
    system("CLS");
    while (it != nombres.end()){
        cout<< "Del alumno "<< *it<<", ";
        k=1;
        prom=0;
        while (k<4){
            cout<<"escribe la calificacion numero "<<k<<endl;
            cin>>calif;
            calificaciones.push_back(calif);
            k++;
            prom=prom+calif;
        }
        prom=prom/3;
        promedios.push_back(prom);
        it++;
    }
    list<float>::iterator itProm = promedios.begin();
    itProm = promedios.begin();
    it = nombres.begin();
    system("CLS");
    while(it != nombres.end()){
        cout<<"El alumno "<<*it<<" Tiene un promedio de "<<*itProm<<endl;
        it++;
        itProm++;
    }
}

int main(int argc, char *argv[])
{
    insertar();
    system("PAUSE");
    return EXIT_SUCCESS;
}
