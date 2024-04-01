#include "avimatrix.h"

using namespace std;

int main(void)
{
    matrix 
        matrizuno("C:\\Users\\alexr\\Desktop\\metodos\\phoenix\\matrizuno.dat"),
        matrizdos("C:\\Users\\alexr\\Desktop\\metodos\\phoenix\\matrizdos.dat"),
        matrizresultado(0,0),
        matrizmax("C:\\Users\\alexr\\Desktop\\metodos\\phoenix\\matrizA.txt");

    matrizresultado = matrizuno*matrizdos;
    matrizresultado.print();

    matrizmax(1,1) = 3;
    matrizuno.resize(4,4);
    matrizuno.print();

    matrizmax.write("C:\\Users\\alexr\\Desktop\\metodos\\phoenix\\matrizresultado.dat");

    return 0;
}