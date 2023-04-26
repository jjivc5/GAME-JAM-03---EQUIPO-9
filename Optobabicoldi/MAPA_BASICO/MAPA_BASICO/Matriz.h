#pragma once
#include<vector>

class Matriz
{
private:
    std::vector<std::vector<int>> datos;
    int filas;
    int columnas;
public:
    Matriz();
    ~Matriz();
    // Constructor que inicializa la matriz con un valor dado
    Matriz(int filas, int columnas, int valor);    
    // Método que cambia el valor de una celda
    void setValor(int fila, int columna, int valor);
    /*Devuelve el objeto Matriz como objeto vector<vector<int>> 
    Probablemente ya no sirva y se puede quitar*/ 
    std::vector<std::vector<int>> retornarMatriz();
    //Método falopa
    void opuesta(Matriz otra_matriz);
    //getters
    int getValor(int fila, int columna) const;
    int getFilas();
    int getColumnas();
};

