#include "avimatrix.h"

//CONSTRUCTORES

matrix::matrix(std::size_t rows, std::size_t cols) //FUNCIFONA con basicamente todo
: mRows(rows),
  mCols(cols)
{
    mData.resize(rows*cols);
    for(auto &v : mData)
        v = 0;
}

matrix::matrix(std::string filename)
{
    std::ifstream matrix_input;

    matrix_input.open(filename.c_str());

    if (matrix_input.is_open()&&matrix_input.good())
    {
        matrix_input >> mRows;
        matrix_input >> mCols;

        mData.clear();
        mData.resize(mRows*mCols);

        for(auto &v : mData)
            matrix_input >> v;

        matrix_input.close();
    }
    else
    {
        mRows = mCols = 1;
        mData.resize(1);
    }

    return;
}

//Acceso a matrices

double& matrix::operator()(std::size_t i, std::size_t j)
{
    return mData[i * mCols + j];
}

double matrix::operator()(std::size_t i, std::size_t j) const
{
    return mData[i * mCols + j];
}

double& matrix::operator[](const std::size_t i)
{
    return mData[i];
}

double matrix::operator[](const std::size_t i) const
{
    return mData[i];
}

//Asignación e igualdad

void matrix::operator=(matrix matrizcopiada) //parece funcifona
{
    mRows = matrizcopiada.getRows();
    mCols = matrizcopiada.getCols();
    mData.resize(mCols*mRows);
    {
        int i=0;
        for(auto &v : mData)
        {
            v = matrizcopiada[i];
            i++;
        }
    }

    return;
}

//Resize de matrices

void matrix::resize(const std::size_t rows, const std::size_t cols) //parece funcifona
{
    matrix temporaryMatrix(mRows, mCols);
    
    std::size_t
        tempRows{mRows},
        tempCols{mCols};

    for(int i=0; i<(tempRows*tempCols);i++)
        temporaryMatrix[i] = mData[i];

    mRows = rows;
    mCols = cols;

    mData.clear();
    mData.resize(rows*cols);


    if(tempCols<mCols)
    {
        for(int i=0;i<tempRows;i++)
            for(int j=0;j<tempCols;j++)
                mData[i*cols + j] = temporaryMatrix[i*tempCols + j];

    }
    else
    {
        for(int i=0;i<mRows;i++)
            for(int j=0;j<mCols;j++)
                mData[i*cols + j] = temporaryMatrix[i*tempCols + j];
    }


    
    return;
}

//Write de matrices

bool matrix::write(std::string filename) //tampoco va la perra
{
    std::ofstream matrix_output;

    matrix_output.open(filename.c_str());

    if (matrix_output.is_open()&&matrix_output.good())
    {
        matrix_output << mRows << " " << mCols << '\n';

        for(int i=0;i<mRows;i++)
            {
                for(int j=0;j<mCols;j++)
                    matrix_output << mData[i*mCols + j] << " ";
                matrix_output << '\n';
            }
        return true;
    }
    else return false;
}

//Lectura secundaria de matrices

bool matrix::read(std::string filename)
{
    std::ifstream matrix_input;

    matrix_input.open(filename.c_str());

    if (matrix_input.is_open()&&matrix_input.good())
    {
        matrix_input >> mRows;
        matrix_input >> mCols;

        mData.clear();
        mData.resize(mRows*mCols);

        for(auto &v : mData)
            matrix_input >> v;

        matrix_input.close();

        return true;
    }
    else return false;
}

//Print de matrices

void matrix::print()
{
    for(int i=0;i<mRows;i++)
            {
                for(int j=0;j<mCols;j++)
                    std::cout << mData[i*mCols + j] << " ";
                std::cout << '\n';
            }
}

//Getters

std::size_t matrix::getRows() const
{
    return mRows;
}

std::size_t matrix::getCols() const
{
    return mCols;
}

//Operadores sobrecargados: + , - , *

matrix matrix::operator+(matrix matriz_ajena)
{
    if((mRows==matriz_ajena.getRows())&&(mCols==matriz_ajena.getCols()))
        {
            matrix matrix_result(mRows,mCols);
            for(int i=0;i<mRows;i++)
                for(int j=0;j<mCols;j++)
                    matrix_result(i,j) = mData[i*mCols + j] + matriz_ajena(i,j);
                
            return matrix_result;
        }
    else return matrix(0,0);
}

matrix matrix::operator-(matrix matriz_ajena)
{
    if((mRows==matriz_ajena.getRows())&&(mCols==matriz_ajena.getCols()))
        {
            matrix matrix_result(mRows,mCols);
            for(int i=0;i<mRows;i++)
                for(int j=0;j<mCols;j++)
                    matrix_result(i,j) = mData[i*mCols + j] - matriz_ajena(i,j);
                
            return matrix_result;
        }
    else return matrix(0,0);
}

matrix matrix::operator*(matrix matriz_ajena)
{
    if(mCols==matriz_ajena.getRows())
        {
            double 
                suma{};
            std::size_t  
                resultRows{ mRows },
                resultCols{ matriz_ajena.getCols() };
            matrix 
                matrix_result(mRows,matriz_ajena.getCols());

            for(int i=0;i<resultCols;i++)
                for(int j=0;j<resultRows;j++)
                {
                    suma = 0;
                    for(int k=0;k<mCols;k++)
                        suma += mData[i*mCols + k]*matriz_ajena(k,j);
                    matrix_result(i,j) = suma;
                }
                
            return matrix_result;
        }
    else return matrix(0,0); //El código de error es una matriz 0,0
}

//Trasposición de matrices

matrix matrix::transpose() //funcifona
{
    matrix transpose_matrix(mCols, mRows);
    
    for(int i=0; i<mRows; i++)
        for(int j=0; j<mCols; j++)
            transpose_matrix(j,i) = mData[i*mCols + j];
    
    return transpose_matrix;
}

