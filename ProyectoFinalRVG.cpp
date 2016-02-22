#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
using namespace std;
class discos {
private:
	string artist;
	string album;
	int day;
	int month;
	int year;
public:
	discos(string, string, int, int, int);
	string getArtist(){return artist;}
	string getAlbum(){return album;}
	int getDay(){return day;}
	int getMonth(){return month;}
	int getYear(){return year;}
	void setArtista (string ar){artist=ar;}
	void setAlbum (string al){album=al;}
	void setDay (int d){day=d;}
	void setMonth (int m){month=m;}
	void setYear (int y){year=y;}

};
discos::discos(string ar, string al, int d, int m, int y){
	artist=ar;
	album=al;
	day=d;
	month=m;
	year=y;
}
void OrdenarDiscos(){
	discos d[7]={
		discos ("PINK FLOYD", "THE DARK SIDE OF THE MOON", 1, 3, 1973),
		discos ("LED ZEPPELIN", "HOUSES OF THE HOLY", 28, 3, 1973),
		discos ("THE ROLLING STONES", "BEGGARS BANQUET", 6, 12, 1968),
		discos ("VAN HALEN", "1984", 9, 1, 1984),
		discos ("GUNS N ROSES", "GREATEST HITS", 13, 2, 2004),
		discos ("LED ZEPPELIN", "LED ZEPPELIN IV", 8, 11, 1971),
		discos ("QUEEN", "A NIGHT AT THE OPERA ", 21, 11, 1975)
	};
	system ("cls");
	system ("color 0B");
    string tempArtist;
    tempArtist=" ";
    string tempAlbum;
    tempAlbum=" ";
    int tempDay=0, tempMonth=0, tempYear=0;
	cout<<"A continuación se le presentara la discografia que se tiene: "<<endl;
	int c;
	c=0;
	while (c<7){
		cout<<"-----------------------------------------"<<endl;
		cout<<"Artista: "<<d[c].getArtist()<<endl;
		cout<<"Album: "<<d[c].getAlbum()<<endl;
		cout<<"fecha de lanzamiento: "<<d[c].getDay()<<"/"<<d[c].getMonth()<<"/"<<d[c].getYear()<<endl;
		cout<<"------------------------------------------"<<endl;
		c++;
	}
	cout<<"Debido a la cantidad que se tiene de discos, la cual es muy reducida, se decidio utilizar ordenamiento de burbuja"<<endl;
    for(int i=0;i<8;i++){
		for(int j=i+1;j<7;j++){
			if(d[j].getArtist()<d[i].getArtist()){
				tempArtist=d[j].getArtist();
				tempAlbum=d[j].getAlbum();
				tempDay=d[j].getDay();
				tempMonth=d[j].getMonth();
				tempYear=d[j].getYear();
				d[j].setArtista(d[i].getArtist());
				d[j].setAlbum(d[i].getAlbum());
				d[j].setDay(d[i].getDay());
				d[j].setMonth(d[i].getMonth());
				d[j].setYear(d[i].getYear());
				d[i].setArtista(tempArtist);
				d[i].setAlbum(tempAlbum);
				d[i].setDay(tempDay);
				d[i].setMonth(tempMonth);
				d[i].setYear(tempYear);
			}
			if(d[j].getArtist()==d[i].getArtist()){
				if(d[j].getYear()<d[i].getYear()){
					tempArtist=d[j].getArtist();
                    tempAlbum=d[j].getAlbum();
                    tempDay=d[j].getDay();
                    tempMonth=d[j].getMonth();
                    tempYear=d[j].getYear();
                    d[j].setArtista(d[i].getArtist());
                    d[j].setAlbum(d[i].getAlbum());
                    d[j].setDay(d[i].getDay());
                    d[j].setMonth(d[i].getMonth());
                    d[j].setYear(d[i].getYear());
                    d[i].setArtista(tempArtist);
                    d[i].setAlbum(tempAlbum);
                    d[i].setDay(tempDay);
                    d[i].setMonth(tempMonth);
                    d[i].setYear(tempYear);
				}
			}
		}
	}
	//fin del algoritmo
	cout<<("Presione Enter")<<endl;
	system("Pause");
	system("cls");
	cout<<"Los albumes ordenados alfabeticamente son: \n";
	c=0;
	while (c<7){
		cout<<"-----------------------------------------"<<endl;
		cout<<"Artista: "<<d[c].getArtist()<<endl;
		cout<<"Album: "<<d[c].getAlbum()<<endl;
		cout<<"fecha de lanzamiento: "<<d[c].getDay()<<"/"<<d[c].getMonth()<<"/"<<d[c].getYear()<<endl;
		cout<<"------------------------------------------"<<endl;
		c++;
	}
	system("pause");
}
class Nodo{
  public:
    int dato;
    Nodo *izq;
    Nodo *der;
};

class ArbolABB{
  private:
    Nodo *raiz;
  public:
    ArbolABB();
    //~ArbolABB();
    int vacio(Nodo *r);
    int esHoja(Nodo *r);
    int buscar(int x, Nodo *p);
    void inOrden(Nodo *p);
    void posOrden(Nodo *p);
    void preOrden(Nodo *p);
    void insertar(int X, Nodo *&p);
    int contar (Nodo *a);
    int contarHojas(Nodo *a);
    bool esHoja(Nodo *p, int x);
    int altura(Nodo *p);
    int sumar(Nodo *r);
    int eliminar(Nodo *&p, int x);
	int numeroMenor(Nodo *p);
	int lados(Nodo *p, int numero);
    Nodo *apRaiz();
};
ArbolABB::ArbolABB(){
  raiz=NULL;
}
Nodo *ArbolABB::apRaiz(){
  return raiz;
}
void ArbolABB::inOrden(Nodo *p){
  if(p->izq!=NULL){
    inOrden(p->izq);
  }
  cout<<p->dato<<",";
  if (p->der!=NULL){
    inOrden(p->der);
  }
}
int ArbolABB::numeroMenor(Nodo *p){
	if ( p  == NULL){
		return 0;
	}
	if ( p-> izq != NULL){
	 numeroMenor(p->izq);}
	else{
		return p->dato;
	}
}
bool ArbolABB::esHoja(Nodo *p, int x){
	if(p == NULL){
		return false;
	}
	if (p->dato == x){
		if (( p-> izq == NULL)and (p->der == NULL)){
			return true;
		}else if (( p-> izq != NULL) and (p->der != NULL)){
		    return false;
			//p->dato = numeroMenor ( p->der);
			//esHoja(p->der, p -> dato);
		}else{
		return false;
		}
	}
	else if (x<p->dato){
		esHoja (p->izq,x);
	}
	else esHoja (p->der,x);
}
int ArbolABB::eliminar(Nodo *&p, int x){
		Nodo *aux;
	if(p == NULL){
		return 0;
	}
	if ( x == p->dato){
		if ( p-> izq == NULL){
			aux = p;
			p = p->der;
			delete aux;
		}
		else if (p->der == NULL){
			aux = p;
			p=p->izq;
			delete aux;
		}
		else {
			p->dato = numeroMenor ( p->der);
			eliminar(p->der, p -> dato);
		}
	}
	else if (x<p->dato){
		eliminar (p->izq,x);
	}
	else eliminar (p->der,x);
}

void ArbolABB::posOrden(Nodo *p){
  if(p!=NULL)
     {
          posOrden(p->izq);
          posOrden(p->der);
          cout << p->dato << " ";
     }
}

void ArbolABB::preOrden(Nodo *p){
  if(p!=NULL)
     {
          cout << p->dato <<" ";
          preOrden(p->izq);
          preOrden(p->der);
     }
}
void ArbolABB::insertar(int x, Nodo* &p){
  if (p==NULL){
    p=new Nodo();
    p->dato=x;
    p->izq=NULL;
    p->der=NULL;
   if(raiz==NULL){
         raiz=p;
    }
  }else if(x<p->dato){
        insertar(x,p->izq);
    }else if (x>p->dato){
        insertar(x,p->der);
    }else{
    cout<<"\n El dato ya existe.";
  }
}
int ArbolABB::contar(Nodo *a){
  if(a==NULL){
    return 0;
  }else{
    return (1+contar(a->der)+contar(a->izq));
  }
}
int ArbolABB::contarHojas(Nodo *p){
	if (p == NULL){
		return 0;
	}
	else if ( p->izq == NULL && p->der == NULL){
		return 1;
	}
	else
		return contarHojas(p->izq) + contarHojas(p->der);
}
int ArbolABB::altura(Nodo *p){
  if(p==NULL){
    return 0;
  }
  int altizq=altura(p->izq);
  int altder=altura(p->der);
  if(altizq>altder){
    return altizq+1;
  }else{
    return altder+1;
  }
}
int ArbolABB::sumar(Nodo *r){
  if(r==NULL){
    return 0;
 }else{
    return (r->dato+sumar(r->der)+sumar(r->izq));
  }
}
int ArbolABB::lados(Nodo *p, int numero){
	if(p->izq!=NULL){
    lados(p->izq, numero);
  	}
  	numero++;
  	if (p->der!=NULL){
    lados(p->der, numero);
  	}
  	return numero;
}

void menuArboles(){
	int z, numIzq, numDer;
	numIzq=0;
	numDer=0;
	system ("COLOR 0A");
	ArbolABB arbusto;
	Nodo *nacimiento;
	nacimiento=arbusto.apRaiz();
	arbusto.insertar(10, nacimiento);
	arbusto.insertar(5, nacimiento);
	arbusto.insertar(15, nacimiento);
	arbusto.insertar(3, nacimiento);
	arbusto.insertar(6, nacimiento);
	arbusto.insertar(14, nacimiento);
	arbusto.insertar(18, nacimiento);
	arbusto.insertar(17, nacimiento);
	arbusto.insertar(20, nacimiento);
	cout<<"Comenzemos por crear un arbol ;)"<<endl;
	cout<<"(Este arbol se muestra en inOrden)"<<endl;
	ArbolABB arbol;
	Nodo *raiz;
	raiz=arbol.apRaiz();
	arbol.insertar(8, raiz);
	arbol.insertar(2, raiz);
	arbol.insertar(12, raiz);
	arbol.insertar(1, raiz);
	arbol.insertar(3, raiz);
	arbol.insertar(10, raiz);
	arbol.insertar(15, raiz);
	arbol.inOrden(raiz);
	cout<<" "<<endl;
	cout<<"Utilizaremos este arbol para llevar a cabo todas las operaciones que deseemos"<<endl;
	cout<<"Presione Enter"<<endl;
	system("pause");
	system("cls");
	int eleccion;
	cout<<"**MENU DE ARBOLES**"<<endl;
	cout<<"1.-CONTAR Nodods"<<endl;
	cout<<"2.-ELIMINAR NODOS"<<endl;
	cout<<"3.-SUMAR NODOS"<<endl;
	cout<<"4.-inOrden"<<endl;
	cout<<"5.-posOrden"<<endl;
	cout<<"6.-preOrden"<<endl;
	cout<<"7.-ES HOJA?"<<endl;
	cout<<"8.-CONTAR HOJAS"<<endl;
	cout<<"9.-ALTURA DE UNA ARBOL"<<endl;
	cout<<"10.-LADO MAYOR Y LADO MENOR"<<endl;
	cin>>eleccion;
	switch(eleccion){
		case 1:
		    cout<<"El arbol tiene "<<arbol.contar(raiz)<<" Nodos \n";
		    system("pause");
		break;
		case 2:
			cout<<"Dato a eliminar \n";
			cin>>z;
			arbol.eliminar(raiz,z);
			cout<<"Dato eliminado"<<endl;
			arbol.inOrden(raiz);
			system("pause");
		break;
		case 3:
			cout<<"La suma es "<<arbol.sumar(raiz)<<endl;
			system("pause");
		break;
		case 4:
			arbol.inOrden(raiz);
			system("pause");
		break;
		case 5:
			arbol.posOrden(raiz);
			system("pause");
		break;
		case 6:
			arbol.preOrden(raiz);
			system("pause");
		break;
		case 7:
		    cout<<"Dato QUE DESEA COMPROBAR SI ES HOJA \n";
			cin>>z;
			if (arbol.esHoja(raiz, z)==true){
				cout<<"EL valor es una hoja"<<endl;
			}else{
				cout<<"El valor que incertO no existe o no es una hoja"<<endl;
			}
			system("pause");
		break;
		case 8:
			cout<<"El arbol tiene "<<arbol.contarHojas(raiz)<<" hojas \n";
			system("pause");
		break;
		case 9:
			cout<<"La altura del arbol es "<<arbol.altura(raiz)<<endl;
			system("pause");
		break;
		case 10:
			system("pause");
			system("cls");
			cout<<"Se ha creado un nuevo arbol, que se compone (inorden) de la siguiente manera:"<<endl;
			arbusto.inOrden(nacimiento);
			cout<<" "<<endl;
			numIzq=arbol.contar(nacimiento->izq);
			numDer=arbol.contar(nacimiento->der);
			if(numIzq>numDer){
				cout<<"El lado mayor de este arbol es el izquierdo Y el lado menor es el derecho"<<endl;
			}else if(numDer>numIzq){
				cout<<"El lado mayor de este arbol es el derecho Y el lado menor es el izquierdo"<<endl;
			}else if(numIzq==numDer){
				cout<<"Ambos lados son iguales"<<endl;
			}
			system("pause");
		break;
		case 11:
			//menu();
		break;
	}
}
void promedio(){
    int c=1, k=1, kalifCont=0;;
    string namae;
    float calif, prom;
    list <string> nombres;
    list <float> calificaciones;
    list <float> promedios;
    while (c<4){
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
void eliminarString(){
    int c=1, k=1;
    string $;
    string namae;
    list <string> nombres;
    while (c<9){
        cout<<"Escribe el nombre "<< c<<endl;
        cin>>namae;
        nombres.push_back(namae);
        c++;
    }
    cout<<"De los nombres que ingreso, cual desea eliminar?"<<endl;
    cin>>$;
    system("CLS");
    list<string>::iterator it = nombres.begin();
    it = nombres.begin();
    while( it != nombres.end() )
    {
      cout<< k++ <<".-"<< *it++ << endl;
    }
    it = nombres.begin();
    system("CLS");
    nombres.remove($);
    k=1;
    it = nombres.begin();
    while( it != nombres.end() )
    {
      cout<< k++ <<".-"<< *it++ << endl;
    }
}
void menuIteradores(){
	system ("COLOR 0F");
	int eleccion;
	cout<<"**MENU DE ITERADORES**"<<endl;
	cout<<"1.-ELIMINAR COMPONENTE"<<endl;
	cout<<"2.-PROMEDIO ESTUDIANTES"<<endl;
	cin>>eleccion;
	switch(eleccion){
		case 1:
			eliminarString();
			system("pause");
		break;
		case 2:
			promedio();
			system("pause");
		break;
		case 3:
			//menu();
		break;
	}
}
void insertion(){
	int z;
	cout<<"Ingrese el numero de valores para el arreglo"<<endl;
	cin>>z;
	int *a=new int[z];
	for(int i=0;i<z;i++){
		cout<<i+1<<": ";
		cin>>a[i];
	}
	for(int i=0;i<z;i++){
		int aux=a[i];
		int j=i-1;
		while(j>=0 && aux<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=aux;
	}
	cout<<"Los numeros ordenados son: "<<endl;
	for(int i=0;i<z;i++){
		cout<<a[i]<<" ";
	}
}
void selection(){
	int z;
	cout<<"Ingrese el numero de valores para el arreglo"<<endl;
	cin>>z;
	int *a=new int[z];
	for(int i=0;i<z;i++){
		cout<<i+1<<": ";
		cin>>a[i];
	}
	for(int i=0;i<z;i++){
		int aux=a[i];
		int j=i-1;
		while(j>=0 && aux<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=aux;
	}
	cout<<"Los numeros ordenados son: "<<endl;
	for(int i=0;i<z;i++){
		cout<<a[i]<<" ";
	}
}
void bubble(){
		string arr[5];
	string temp;
	int i, j;
	cout<<"Ingrese los datos que desea ordenar, max 5"<<endl;
	for(i=0;i<5;i++){
		cout<<i+1<<": ";
		cin>>arr[i];
	}
	for( i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<" "<<endl;
	i=0;
	j=1;

	//algoritmo
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(arr[j]<arr[i]){
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	//fin del algoritmo
	cout<<"Los numero ordenados son: \n";
	for(i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
}
void menuOrdenamiento(){
	system ("COLOR 0D");
	int eleccion;
	cout<<"**MENU DE ORDENAMIENTO**"<<endl;
	cout<<"1.-BUBBLE SORT"<<endl;
	cout<<"2.-INSERTION SORT"<<endl;
	cout<<"3.-SELECTION SORT"<<endl;
	cin>>eleccion;
	switch(eleccion){
		case 1:
			bubble();
			system("pause");
		break;
		case 2:
			insertion();
			system("pause");
		break;
		case 3:
			selection();
			system("pause");
		break;
		case 4:
			//menu();
		break;
	}
}
void busquedaSimple(int encontrar){
    int encontrado, i, posicion;
    int a[5];
    a[0]=3;
    a[1]=4;
    a[2]=7;
    a[3]=8;
    a[4]=2;
	encontrado=0;
	for (int i = 0; i < 4; ++i){
		if(a[i]==encontrar){
            encontrado=1;
			posicion=i;
		}
	}
	if(encontrado=1){
        cout<<"El numero "<<encontrar<<" Fue encontrado en la posicion "<<posicion+1<<endl;
	}else{
        cout<<"El numero "<<encontrar<<" No existe en el arreglo... perdon :("<<endl;
	}
}
int divide(int numIni, int numFin){
	int r;
	r=0;
	r=numIni+numFin;
	r=r/2;
	return r;
}
int busquedaBinaria ( int inicio, int tamano, int numBusq, int *arra){
	int posicion;
	if(arra[divide(inicio,tamano)]==numBusq){
		posicion=divide(inicio, tamano)+1;
	}
	if(arra[divide(inicio,tamano)]>numBusq){
		posicion=busquedaBinaria(inicio,tamano-1, numBusq, arra);
	}
	if(arra[divide(inicio,tamano)]<numBusq){
		posicion=busquedaBinaria(inicio, tamano+1, numBusq, arra);
	}
	return posicion;
}


void menuBusqueda(){
	system ("COLOR 0C");
	int eleccion;
	int arreglo[6], numero;
	arreglo[0]=1;
	arreglo[1]=5;
	arreglo[2]=7;
	arreglo[3]=10;
	arreglo[4]=12;
	arreglo[5]=13;
	cout<<"**Que metodo de busqueda desea usar**"<<endl;
	cout<<"1.-BUSQUEDA SIMPLE"<<endl;
	cout<<"2.-BUSQUEDA BINARIA"<<endl;
	cin>>eleccion;
	switch(eleccion){
		case 1:
		    cout<<"Que numero desea buscar??? :)"<<endl;
            cout<<"Quiero buscar el numero ";
            cin>>numero;
            cout<<" "<<endl;
			busquedaSimple(numero);
			system("pause");
		break;
		case 2:
		    cout<<"Que numero desea buscar??? :)"<<endl;
            cout<<"Quiero buscar el numero ";
            cin>>numero;
            cout<<" "<<endl;
			cout<<"El numero que deseas esta en la posicion "<<busquedaBinaria( 0, 6, numero, arreglo)<<endl;
			system("pause");
		break;
		case 3:
			//menu();
		break;
	}
}

int menu(int &bandera){
    system ("cls");
	system ("COLOR 08");
	int eleccion;
	cout<<"**MENU DE SELECCION**"<<endl;
	cout<<"1.-ARBOLES"<<endl;
	cout<<"2.-ITERADORES"<<endl;
	cout<<"3.-ORDENAMIENTO"<<endl;
	cout<<"4.-BUSQUEDA"<<endl;
	cout<<"5.-PROYECTO: DISCOGRAFIA"<<endl;
	cin>>eleccion;
	switch(eleccion){
		case 1:
		    system("cls");
			menuArboles();
		break;
		case 2:
		    system("cls");
			menuIteradores();
		break;
		case 3:
		    system("cls");
			menuOrdenamiento();
		break;
		case 4:
		    system("cls");
			menuBusqueda();
		break;
		case 5:
			system("cls");
			OrdenarDiscos();
		break;
	}
	return 0;
}
main(){
	int mainFlag;
	mainFlag=0;
	while (mainFlag==0){
		menu(mainFlag);
	}
}
//AGV