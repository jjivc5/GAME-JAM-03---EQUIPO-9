#include "Matriz.h"
Matriz::Matriz()
{

}
Matriz::~Matriz()
{

}
Matriz::Matriz(int filas, int columnas, int valor) {
    datos.resize(filas, std::vector<int>(columnas, valor));
    this->filas = filas; this->columnas = columnas;
}
//setters
void Matriz::setValor(int fila, int columna, int valor) {
    datos[fila][columna] = valor;
}
//getters
int Matriz::getValor(int fila, int columna) const {
    return datos[fila][columna];
}
int Matriz::getFilas()
{
    return filas;
}
int Matriz::getColumnas()
{
    return columnas;
}
std::vector<std::vector<int>> Matriz::retornarMatriz() {
    return datos;
}
//otros métodos
void Matriz::opuesta(Matriz otra_matriz)
{
    for (int i = 0; i < otra_matriz.getFilas();i++)
    {
        for (int j = 0; j < otra_matriz.getColumnas(); j++)
        {
            if (otra_matriz.getValor(i, j) == 1)
            {
                this->setValor(i, j, 0);
            }
            else if (otra_matriz.getValor(i, j) == 0)
            {
                this->setValor(i, j, 1);
            }
        }
    }
}