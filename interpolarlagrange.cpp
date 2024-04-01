#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

double lagrange(vector<double>, vector<double>, double);

int main(void)
{
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

    //Salida de datos
    fichout.open("C:\\Users\\alexr\\Desktop\\metodos\\phoenix\\lagrange.dat");
    if(fichout.is_open())
    {
        double lagrange_input;
        
        for(lagrange_input=0.4;lagrange_input<=0.8;lagrange_input+=0.01)
        {
            fichout << " " << lagrange(x,y,lagrange_input) << endl;
        }

        fichout.close();
    }

    return 0;
}

double lagrange(vector<double> x, vector<double> y, double valor)
{
    int n;
    double lagranger,li,top,bot;

    n = (x.size())-1;

    lagranger = 0;

    for(int i=0;i<=n;i++)
    {
        li = 1;
        for(int j=0;j<=n;j++)
        {
            if(j!=i)
            {
                top = valor - x[j];
                bot = x[i] - x[j];
                li *= top/bot;
            }
        }
        lagranger += y[i]*li;
    }

    return lagranger;
}
