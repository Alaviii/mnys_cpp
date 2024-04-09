#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

double newton(vector<double>, vector<double> , double);
double diferencia_dividida(vector<double>, vector<double>);

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
    fichout.open("newton.dat");
    if(fichout.is_open())
    {
        double newton_input;

        for(newton_input=0.4;newton_input<=0.8;newton_input+=0.0025)
        {
            fichout << newton_input << " " << newton(x,y,newton_input) << endl;
        }

        fichout.close();
    }

    return 0;
}

double diferencia_dividida(vector<double> x, vector<double> y)
{
    if(x.size() == 1)
        return y[0];
    else 
    {
        vector<double>
            x1k = {x.begin() + 1, x.end()},
            y1k = {y.begin() + 1, y.end()},
            x0k = {x.begin(), x.end() - 1},
            y0k = {y.begin(), y.end() - 1};

        return (diferencia_dividida(x1k,y1k)-diferencia_dividida(x0k,y0k))/(x.back()-x.front());
    }
}

double newton(vector<double> x, vector<double> y, double valor)
{
    double 
        newton_result = 0,
        suma = 0;

    for(int i = 0; i <= x.size()-1; i++)
    {
        double prod = 1;
        vector<double> 
            vector_para_coeficiente_ck_x = {x.begin(),x.begin()+i+1},
            vector_para_coeficiente_ck_y = {y.begin(),y.begin()+i+1};

        for(int j = 0; j <= i-1 ; j++)
        {
            prod *= valor - x[j];
        }

        suma += diferencia_dividida(vector_para_coeficiente_ck_x,vector_para_coeficiente_ck_y)*prod;
    }   

    return suma;
}