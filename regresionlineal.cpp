#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    double a0, a1, sumax, sumay, sumaxy, sumaxx;
    vector<double>
        x,
        y;
    ifstream fichin;
    ofstream fichout;

    //Entrada de datos
    fichin.open("C:\\Users\\alexr\\Desktop\\metodos\\phoenix\\tabla.dat");
    if(fichin.is_open())
    {
        int parejas;
        fichin >> parejas;

        x.resize(parejas);
        y.resize(parejas);

        for(int i=0;i<parejas;i++)
        {
            fichin >> x[i];
            fichin >> y[i];
        }

        fichin.close();
    }

    //Calculo del polinomio
    N = (x.size())-1;

    sumax = sumay = sumaxy = sumaxx = 0;

    for(int i=0;i<=N;i++)
    {
        sumax += x[i];
        sumay += y[i];
        sumaxy += x[i]*y[i];
        sumaxx += x[i]*x[i];
    }

    a1 = (((N+1)*sumaxy-sumax*sumay))/((N+1)*sumaxx-sumax*sumax);

    a0 = (sumaxx*sumay-sumaxy*sumax)/((N+1)*sumaxx-sumax*sumax);

    //Salida de datos

    fichout.open("C:\\Users\\alexr\\Desktop\\metodos\\phoenix\\mincuad.dat");
    if(fichout.is_open())
    {
        fichout << "P(x) = " << a1 << "x + " << a0;
        fichout.close();
    }

    return 0;
}
