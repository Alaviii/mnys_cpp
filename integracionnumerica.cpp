#include "avimatrix.h"

using namespace std;

double newtoncotes(double, double, int, vector<int>);
double f(double);

int main(void)
{
    matrix
        cotes("cotes.dat");
    
    vector<int>
        vector_cotes;
    
    int n;

    cout << "Introduce n" << '\n';
    cin >> n;

    vector_cotes.resize(n+1);
    {
        int i = 0;
        for(auto v : vector_cotes)
        {
            v = cotes(n-1, i);
            i++;
        }
    }

    cout << "n = " << n << ", I = " << newtoncotes(0,1,n,vector_cotes) << endl;
}

double newtoncotes(double a, double b, int n, vector<int> cotes)
{
    double 
        suma = 0,
        integral = 0,
        h = (b-a)/n;

    for(int i = 0; i <=n ; i++)
    {
        suma += ((cotes[i]*1.0)/cotes[9])*f(a + i*h);
    }

    integral = (b-a) * suma;

    return integral;
}

double f(double x)
{
    return 1/(1+x);
}