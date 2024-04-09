#include <iostream>
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
    fichin.open("tabla.dat");
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
    fichout.open("lagrange.dat");
    if(fichout.is_open())
    {
        double lagrange_input;
        
        for(lagrange_input=0.4;lagrange_input<=0.8;lagrange_input+=0.0025)
        {
            fichout << lagrange_input << " " << lagrange(x,y,lagrange_input) << endl;
        }

        fichout.close();
    }

    return 0;
}

double lagrange(vector<double> x, vector<double> y, double valor)
{
    int 
        n = ((x.size())-1) ;
    double 
        lagrange_result,
        lagrange_iesimo,
        top,
        bot;

    lagrange_result = 0;

    for(int i=0;i<=n;i++)
    {
        lagrange_iesimo = 1;
        for(int j=0;j<=n;j++)
        {
            if(j!=i)
            {
                top = valor - x[j];
                bot = x[i] - x[j];
                lagrange_iesimo *= top/bot;
            }
        }
        lagrange_result += y[i]*lagrange_iesimo;
    }

    return lagrange_result;
}
