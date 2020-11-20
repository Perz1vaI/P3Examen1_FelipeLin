/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: felipelinzhao
 *
 * Created on November 20, 2020, 1:19 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>


using namespace std;

void conway(int**, int, int, int, int, int);

int** LlenarMatriz(int**&, int, int, int);

int** InicializarMatriz(int, int);

void liberarMatriz(int**&, int);

void printMatrix(int**, int, int);

int main(int argc, char** argv) {
    int menu;
    cout << "1. Jugar con un tablero aletorio\n2. Jugar con tablero predefinido\n3. Salida\n";
    cout << "Ingrese la opcion: ";
    cin >> menu;
    while (menu != 3) {
        switch (menu) {
            case 1:
            {
                int fila = 0, columna = 0, celulas_vivas = 0, turnos = 0;
                int** Matrix = NULL;
                cout << "Elija la fila de su matriz: " << endl;
                cin >> fila;
                cout << "Elija la columna de su matriz: " << endl;
                cin >> columna;
                cout << "Elija el numero de celulas vidas en su matriz: " << endl;
                cin >> celulas_vivas;
                cout << "Elija el numero de turnos en su matriz: " << endl;
                cin >> turnos;

                Matrix = InicializarMatriz(fila, columna);

                Matrix = LlenarMatriz(Matrix, fila, columna, celulas_vivas);

                printMatrix(Matrix, fila, columna);

                conway(Matrix, 0, 0, turnos, fila, columna);


                break;
            }
            case 2:
            {

                int x = 20;
                int y = 20;

                int temp_mat [20][20] = {
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                };

                int ** mat = new int*[y];
                for (int i = 0; i < y; i++) {
                    mat[i] = new int[x];
                    for (int j = 0; j < x; j++) {
                        mat[i][j] = temp_mat[i][j];
                    }
                }

                int turnos = 0;

                cout << "Elija el numero de turnos en su matriz: " << endl;
                cin >> turnos;


                conway(mat, 0, 0, turnos, x, y);
                liberarMatriz(mat, x);


                break;
            }
            default:
            {
                cout << "No existe esa opcion\n";
                break;
            }
        }

        cout << "1. Jugar con un tablero aletorio\n2. Jugar con tablero predefinido\n3. Salida\n";
        cout << "Ingrese la opcion: ";
        cin >> menu;

    }




}

void conway(int** tablero, int x, int y, int turnos, int max_x, int max_y) {
    int vecinos = 0;
    if (turnos == 0) {
        cout << "termine la cosa" << endl;
        printMatrix(tablero, max_x, max_y);
    } else {
        cout << "inicio del ciclo " << turnos << endl;
        if (x == max_x - 1 && y == max_y - 1) {
            cout << "termino un turno" << endl;
            printMatrix(tablero, max_x, max_y);
            conway(tablero, x, y, turnos - 1, max_x, max_y);
        }
        if (y == max_y) {
            cout << " aqui se lleno la y al max" << endl;
            conway(tablero, x + 1, 0, turnos, max_x, max_y);
            if (tablero[x][y] == 1) {
                if (y == 0 && x == max_x - 1) {
                    if (tablero[x + 1][y] == 0 && tablero[x][y + 1] == 0) {
                        tablero[x][y] = 0;
                    }

                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;


                } else if (y == 0) {
                    if (tablero[x - 1][y] == 0 && tablero[x + 1][y] == 0 && tablero[x][y + 1] == 0 &&
                            tablero[x - 1][y + 1] == 0 && tablero[x + 1][y + 1] == 0) {
                        tablero[x][y] = 0;
                    }

                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;
                }
            } else if (tablero[x][y] == 0) {
                if (y == 0 && x == max_x - 1) {
                    if (tablero[x + 1][y] == 0 && tablero[x][y + 1] == 0) {
                        tablero[x][y] = 0;
                    }

                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (vecinos == 3) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;
                } else if (y == 0) {
                    if (tablero[x - 1][y] == 0 && tablero[x + 1][y] == 0 && tablero[x][y + 1] == 0 &&
                            tablero[x - 1][y + 1] == 0 && tablero[x + 1][y + 1] == 0) {
                        tablero[x][y] = 0;
                    }

                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (vecinos == 3) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;
                }
            }
        }
        else {
            cout << "aqui incremento la y" << endl;

            if (tablero[x][y] == 1) {
                cout << " (Incremento en y) tablero es igual a 1 " << endl;
                if (x == 0 && y == 0) {
                    cout << " (Incremento en y) tablero es igual a 1 y x=0 y=0 " << endl;

                    if (tablero[x + 1][y] == 0 && tablero[x][y + 1] == 0 && tablero[x + 1][y + 1] == 0) {
                        tablero[x][y] = 0;
                    }
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y + 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;

                } 
                else if (x == 0 && y == max_y - 1) {
                    if (tablero[x][y - 1] == 0 && tablero[x + 1][y] == 0 && tablero[x + 1][y - 1] == 0) {
                        tablero[x][y] = 0;

                    }

                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y - 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;

                } 
                else if (x != 0 && y == max_y - 1) {
                    if (tablero[x][y - 1] == 0 && tablero[x - 1][y] == 0 && tablero[x - 1][y - 1] == 0 && tablero[x + 1][y] == 0 &&
                            tablero[x + 1][y - 1] == 0) {
                        tablero[x][y] = 0;
                    }

                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y - 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;

                } 
                else if (x != 0 && y == 0) {
                    if (tablero[x][y + 1] == 0 && tablero[x - 1][y] == 0) {
                        tablero[x][y] = 0;
                    }

                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x 1][y + 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;


                } 
                else if (x == max_x - 1 && y == max_y - 1) {
                    if (tablero[x - 1][y] == 0 && tablero[x][y - 1] == 0 && tablero[x - 1][y - 1] == 0) {
                        tablero[x][y] = 0;
                    }

                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y - 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;

                } 
                else if (x == 0 && y > 0) {
                    if (tablero[x + 1][y] == 0 && tablero[x][y + 1] == 0 && tablero[x + 1][y + 1] == 0 &&
                            tablero[x][y - 1] == 0 && tablero[x + 1][y - 1] == 0) {
                        tablero[x][y] = 0;
                    }
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y - 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;
                } 
                else if (x > 0 && y > 0) {
                    if (tablero[x + 1][y] == 0 && tablero[x - 1][y] == 0 && tablero[x][y + 1] == 0 && tablero[x][y - 1] == 0 &&
                            tablero[x - 1][y - 1] == 0 && tablero[x + 1][y - 1] == 0 && tablero[x - 1][y + 1] == 0 &&
                            tablero[x + 1][y + 1] == 0) {
                        tablero[x][y] = 0;
                    }
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (vecinos == 3 || vecinos == 2) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;
                }
            } else if (tablero[x][y] == 0) {
                cout << " (Incremento en y) tablero es igual a 0 " << endl;
                if (x == 0 && y == 0) {
                    cout << " (Incremento en y) tablero es igual a 0 y x=0 y=0 " << endl;

                    if (tablero[x + 1][y] == 1) {

                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {

                        vecinos++;
                    }
                    if (tablero[x + 1][y + 1] == 1) {

                        vecinos++;
                    }

                    if (vecinos == 3) {

                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;

                } 
                else if (x == 0 && y == max_y - 1) {
                    cout << " (Incremento en y) tablero es igual a 0 y x=0 y=19" << endl;

                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y - 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;

                }
                else if (x != 0 && y == max_y - 1) {
                    cout << " (Incremento en y) tablero es igual a 0 y x!=0 y=19" << endl;

                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y - 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;

                }
                else if (x != 0 && y == 0) {


                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x 1][y + 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;


                } 
                else if (x == max_x - 1 && y == max_y - 1) {
                    cout << " (Incremento en y) tablero es igual a 0 y x=19 y=19" << endl;

                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y - 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;

                }
                else if (x == 0 && y > 0) {
                    cout << " (Incremento en y) tablero es igual a 0 y x=0 y>0" << endl;
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y - 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                    vecinos = 0;
                }
                else if (x > 0 && y > 0) {
                    cout << " (Incremento en y) tablero es igual a 0 y x>0 y>0" << endl;
                    if (tablero[x + 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y - 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x - 1][y + 1] == 1) {
                        vecinos++;
                    }
                    if (tablero[x + 1][y + 1] == 1) {
                        vecinos++;
                    }

                    if (vecinos == 3) {
                        tablero[x][y] = 1;
                    } else {
                        tablero[x][y] = 0;
                    }
                }
            }
            conway(tablero, x, y + 1, turnos, max_x, max_y);
        }


    }

}

int** InicializarMatriz(int fila, int columna) {
    if (fila > 0 && columna > 0) {
        int** intArray = new int*[fila];
        for (int i = 0; i < fila; i++) {
            intArray[i] = new int[columna];
        }
        return intArray;

    }
    return NULL;

}

int** LlenarMatriz(int**& matriz, int fila, int columna, int celulas_vivas) {
    if (fila > 0 && columna > 0) {
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < columna; j++) {
                if (celulas_vivas != 0) {
                    matriz[i][j] = rand() % 2;
                    if (matriz[i][j] == 1) {
                        celulas_vivas--;

                    }

                } else {
                    matriz[i][j] = 0;
                }
            }
        }
    }
    return matriz;

}

void liberarMatriz(int**& matriz, int fila) {
    if (matriz != NULL && fila > 0) {
        for (int i = 0; i < fila; i++) {
            if (matriz[i] != NULL) {
                delete[] matriz[i];
                matriz[i] = NULL;
            }
        }
        delete[] matriz;
        matriz = NULL;
    }
}

void printMatrix(int** matriz, int fila, int columna) {
    if (fila > 0 && matriz != NULL && columna > 0) {
        for (int i = 0; i < fila; i++) {
            if (matriz[i] != NULL) {
                cout << "[";
                for (int j = 0; j < columna; j++) {

                    if (matriz[i][j] == 1) {
                        cout << "*" << " ";
                    } else {
                        cout << "_" << " ";
                    }
                }
                cout << "]" << endl;
            }



        }
        cout << endl;
    }

}





