#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#include <chrono>




using namespace std;
using namespace std::chrono;





int aleatorio(short inicio, short fin);
void CrearArreglo(int s[],int n);
void EscrituraArchivo(double tabla[][1000][100],int k,double promedio[][100],const string NombreArchivo);
void CopiarArreglo(int s[], int r[], int n);
void ImprimirArreglo(int s[], int n, const char texto[]);

void OrdenacionInsercion(int s[],int n);
void OrdenacionBurbuja(int s[],int n);
void OrdenacionSeleccion(int s[], int n);

void OrdenacionMerge(int s[], int inicio, int fin);
void Merge2(int s[], int inicio, int medio, int fin);

void OrdenacionMonticulo(int s[], int n);
void BuildMaxHeap(int s[], int n);
void MaxHeapify(int s[], int i, int n);

void OrdenacionRapida(int s[], int inicio, int fin);
int Particion(int s[], int inicio, int fin);

void OrdenacionShell(int s[], int n);


#define NUM_PRUEBAS 1000
#define MIN_TAMANO 10
#define MAX_TAMANO 1000
#define INCREMENTO 10
#define NUM_ALG 7

double Tabla[7][1000][100];


auto inicio = high_resolution_clock::now();
auto fin = high_resolution_clock::now();
long long duracion = duration_cast<nanoseconds>(fin - inicio).count();


//***********************************//
//******FUNCION PRINCIPAL(MAIN)******//
//***********************************//
int main(){



    srand(time(NULL));

    //Declaracion de variables
    int n=10, s[MAX_TAMANO],r[MAX_TAMANO];
    double promedio[7][100];

    for(int i=0;i<7;++i){
        for(int j=0;j<100;++j){
            promedio[i][j] = 0;
        }
    }


    string NombresArchivos[] ={
        "1_Insercion_Ordenamiento.csv",
        "2_Burbuja_Ordenamiento.csv",
        "3_Seleccion_Ordenamiento.csv",
        "4_Merge_Ordenamiento.csv",
        "5_Quick_Ordenamiento.csv",
        "6_Monticulos_Ordenamiento.csv",
        "7_Shell_Ordenamiento.csv",
    };




    //////////////////////////////////////

    for(int j=0;j<100;++j){//Cantidad de ejecuciones

        for(int i=0;i<1000;i++){
            CrearArreglo(s,n);

            //************Ordenacion Insercion************/

            inicio=high_resolution_clock::now();
            OrdenacionInsercion(r,n);
            fin=high_resolution_clock::now();
            duracion = duration_cast<nanoseconds>(fin - inicio).count();


            Tabla[0][i][j] = duracion;
            promedio[0][j] += duracion;

            CopiarArreglo(s,r,n);
            //****************************************/


            //************Ordenacion Burbuja************/

            inicio=high_resolution_clock::now();
            OrdenacionBurbuja(r,n);
            fin=high_resolution_clock::now();
            duracion = duration_cast<nanoseconds>(fin - inicio).count();

            Tabla[1][i][j] = duracion;
            promedio[1][j] += duracion;

            CopiarArreglo(s,r,n);
            //****************************************/


            //************Ordenacion Seleccion************/
            inicio=high_resolution_clock::now();
            OrdenacionSeleccion(r,n);
            fin=high_resolution_clock::now();
            duracion = duration_cast<nanoseconds>(fin - inicio).count();

            Tabla[2][i][j] = duracion;
            promedio[2][j] += duracion;

            CopiarArreglo(s,r,n);
            //****************************************/


            //************Ordenacion Mezcla(Merge)************/
            inicio=high_resolution_clock::now();
            OrdenacionMerge(r,0,n-1);
            fin=high_resolution_clock::now();
            duracion = duration_cast<nanoseconds>(fin - inicio).count();

            Tabla[3][i][j] = duracion;
            promedio[3][j] += duracion;

            CopiarArreglo(s,r,n);
            //****************************************/


            //************Ordenacion Rapida************/
            inicio=high_resolution_clock::now();
            OrdenacionRapida(r,0,n-1);
            fin=high_resolution_clock::now();
            duracion = duration_cast<nanoseconds>(fin - inicio).count();

            Tabla[4][i][j] = duracion;
            promedio[4][j] += duracion;

            CopiarArreglo(s,r,n);
            //****************************************/


            //************Ordenacion Monticulo************/
            inicio=high_resolution_clock::now();
            OrdenacionMonticulo(r,n);
            fin=high_resolution_clock::now();
            duracion = duration_cast<nanoseconds>(fin - inicio).count();

            Tabla[5][i][j] = duracion;
            promedio[5][j] += duracion;

            CopiarArreglo(s,r,n);
            //****************************************/


            //************Ordenacion Shell************/
            inicio=high_resolution_clock::now();
            OrdenacionShell(r,n);
            fin=high_resolution_clock::now();
            duracion = duration_cast<nanoseconds>(fin - inicio).count();

            Tabla[6][i][j] = duracion;
            promedio[6][j] += duracion;

            CopiarArreglo(s,r,n);
            //****************************************/

        }
        cout << endl << endl<<"--------------------" << NUM_PRUEBAS <<" pasadas"  << "--------------------" << endl;
        cout << "Ordenacion Insercion tama\244o " << n << ": Listo." << endl;
        cout << "Ordenacion Burbuja tama\244o " << n << ": Listo." << endl;
        cout << "Ordenacion Seleccion tama\244o " << n << ": Listo." << endl;
        cout << "Ordenacion Merge tama\244o " << n << ": Listo." << endl;
        cout << "Ordenacion Quick tama\244o " << n << ": Listo." << endl;
        cout << "Ordenacion Monticulos tama\244o " << n << ": Listo." << endl;
        cout << "Ordenacion Shell tama\244o " << n << ": Listo." << endl;
        cout << "----------------------------------------------------";
        n+=10;
    }


    for(int alg=0;alg<7;++alg){
        EscrituraArchivo(Tabla,alg,promedio,NombresArchivos[alg]);
    }




    system("pause");
    return 0;
}
//***********************************//
//***********************************//
//***********************************//









//*********************************************************//
int aleatorio(short inicio, short fin)
{
    return inicio + rand()%(fin-inicio+1);
}

//************************//
void CrearArreglo(int s[],int n){
    for(int i=0;i<n;++i){
        s[i] = aleatorio(1,1000);
    }
}


//************************//
void CopiarArreglo(int s[], int r[], int n){//s[] es el original, y 'n' el tamaño de los 2 (porque deben ser del mismo tamaño).
    for(int i=0;i<n;i++){
        r[i] = s[i];
    }
}


//************************//
void EscrituraArchivo(double Tabla[][1000][100],int k,double promedio[][100],const string NombreArchivo){

    ofstream myFile;
    myFile.open(NombreArchivo);

    myFile << "Array Size: " << ',';
    for(int i=10;i<=1000;i+=10){
        myFile << i << ',';
    }
    myFile << endl << endl;


    for(int i=0;i<1000;++i){

        for(int j=0;j<100;++j){
            myFile << ',' <<Tabla[k][i][j];
        }
        myFile << endl;
    }


    /*Dice los promedios en la columna de cada quien.*/
    myFile << endl;
    myFile << endl <<"Promedios:";

    myFile << ',';
    for(int i=0;i<100;++i){
        myFile << promedio[k][i]/1000 << ',';
    }

    myFile.close();
    ///////////////////////////////
    ofstream ArchPromedios;
    ArchPromedios.open("Promedios.csv");

    string Nombres[] = {
        "Insercion: ",
        "Burbuja: ",
        "Seleccion: ",
        "Merge: ",
        "Quick: ",
        "Monticulos: ",
        "Shell: "
    };


    ArchPromedios << "Array Size: " << ',';
    for(int i=10;i<=1000;i+=10){
        ArchPromedios << i << ',';
    }
    ArchPromedios << endl << endl;
    for(int i=0;i<7;i++){
        ArchPromedios << Nombres[i] << ',';
        for(int j=0;j<100;j++){
            ArchPromedios << promedio[i][j]/1000 << ',';
        }
        ArchPromedios << endl;
    }

}
//************************//

void OrdenacionInsercion(int s[],int n)
{
    int j,val;

    for(int i=1;i<n;++i){
        val = s[i];
        j = i-1;
        while(j>=0 && val <s[j]){
            s[j+1] = s[j];
            --j;
        }
        s[j+1] = val;
    }

    return;
}
//************************//
void OrdenacionBurbuja(int s[],int n)
{
    bool intercambiado = true;
    int aux;

    while(intercambiado){
        intercambiado = false;
        for(int j=0;j!=(n-1);j++){
            if(s[j]>s[j+1]){
                aux = s[j];
                s[j] = s[j+1];
                s[j+1] = aux;
                intercambiado = true;
            }
        }
    }
}
//************************//
void OrdenacionSeleccion(int s[], int n)
{
    int min_indice;
    int aux;
    for(int i=0; i!=n-1;i++){
        min_indice = i;
        for(int j=i; j!= n;j++){
            if(s[j]<s[min_indice]){
                min_indice = j;
            }
        }
        if(min_indice != i){
            aux = s[i];
            s[i] = s[min_indice];
            s[min_indice] = aux;
        }

    }

}
//***********ORDENACION POR MEZCLA (MERGE)*************//
void OrdenacionMerge(int s[], int inicio, int fin)
{
    int medio;
    if (inicio < fin) {
        medio = (inicio + fin) / 2;
        OrdenacionMerge(s, inicio, medio);
        OrdenacionMerge(s, medio + 1, fin);
        Merge2(s, inicio, medio, fin);
    }
}
void Merge2(int s[], int inicio, int medio, int fin)
{
    int n1, n2;

    n1 = medio - inicio + 1;
    n2 = fin - medio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = s[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = s[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            s[k] = L[i];
            ++i;
        } else {
            s[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        s[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        s[k] = R[j];
        ++j;
        ++k;
    }
}


//***********ALGORITOMO DE ORDENACION RAPIDA*************//
void OrdenacionRapida(int s[], int inicio, int fin)
{
    int pivote_idx;

    if(inicio < fin){
        pivote_idx = Particion(s,inicio,fin);
        OrdenacionRapida(s,inicio,pivote_idx-1);
        OrdenacionRapida(s,pivote_idx+1,fin);
    }
}

int Particion(int s[], int inicio, int fin)
{
    int pivote = s[fin];
    int i = inicio - 1;
    int aux;

    for(int j = inicio; j < fin; j++){
        if(s[j] < pivote){
            ++i;
            aux = s[i];
            s[i] = s[j];
            s[j] = aux;

        }
    }

    aux = s[fin];
    s[fin] = s[i+1];
    s[i+1] = aux;

    return i+1;
}
//*********************************//
void OrdenacionShell(int s[], int n)
{
    int aux,j;
    int gaps[] = {n/2,n/4,n/6,n/8,1};

    for(int gap: gaps){
        for(int i = gap; i <n; i++){
            aux = s[i];
            j = i;

            while(j>=gap && s[j-gap]>aux){
                s[j] = s[j-gap];
                j -=gap;
            }
            s[j] = aux;
        }
    }
}
//*********************************//


void OrdenacionMonticulo(int s[], int n) {
    int aux;
    BuildMaxHeap(s, n);

    for (int i = n - 1; i > 0; --i) {

        aux = s[0];
        s[0] = s[i];
        s[i] = aux;


        MaxHeapify(s, 0, i - 1);
    }
}
void BuildMaxHeap(int s[], int n) {

    for (int i = n / 2 - 1; i >= 0; --i) {
        MaxHeapify(s, i, n - 1);
    }
}
void MaxHeapify(int s[], int i, int n) {
    int izquierdo = 2 * i + 1;
    int derecho = 2 * i + 2;
    int mayor = i;
    int aux;

    if (izquierdo <= n && s[izquierdo] > s[mayor]) {
        mayor = izquierdo;
    }
    if (derecho <= n && s[derecho] > s[mayor]) {
        mayor = derecho;
    }
    if (mayor != i) {
        aux = s[i];
        s[i] = s[mayor];
        s[mayor] = aux;


        MaxHeapify(s, mayor, n);
    }
}


void ImprimirArreglo(int s[], int n, const char texto[])
{

    cout <<endl<< texto << "[";
    for(int i=0;i<n;++i){
        cout << s[i] << ", ";
    }
    cout << "\b\b]"<<endl;
}

