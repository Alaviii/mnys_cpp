#include "avimatrix.h"

using namespace std;

int main(void)
{
    matrix 
        matrizuno("matrizuno.dat"),
        matrizdos("matrizdos.dat"),
        matrizresultado(0,0),
        matrizmax("matrizA.txt");

    matrizresultado = matrizuno*matrizdos;
    matrizresultado.print();

    matrizmax(1,1) = 3;
    matrizuno.resize(4,4);
    matrizuno.print();

    matrizmax.write("matrizresultado.dat");

    return 0;
}