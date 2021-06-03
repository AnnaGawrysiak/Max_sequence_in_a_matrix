/*
 Otrzymujesz macierz A sk�adaj�c� si� z N wierszy i M kolumn, gdzie ka�da kom�rka zawiera cyfr�. Twoim zadaniem jest znale�� ci�g�� sekwencj� s�siednich kom�rek, zaczynaj�c� si� w lewym g�rnym rogu i ko�cz�c� si� w prawym dolnym rogu (id�c tylko w d� i w prawo), kt�ra tworzy najwi�ksz� mo�liw� liczb� ca�kowit� poprzez po��czenie cyfr na �cie�ce. Przez s�siednie kom�rki rozumiemy kom�rki, kt�re maj� dok�adnie jedn� wsp�ln� stron�.

Napisz funkcj�, kt�ra przy danej macierzy A sk�adaj�cej si� z N wierszy i M kolumn zwraca �a�cuch reprezentuj�cy sekwencj� kom�rek, kt�re powinni�my wybra�, aby uzyska� najwi�ksz� mo�liw� liczb� ca�kowit�.

Na przyk�ad, bior�c pod uwag� nast�puj�c� macierz A:

       [9 9 7]
       [9 7 2]
       [6 9 5]
       [9 1 2]

funkcja powinna zwr�ci� �997952�, poniewa� tak� sekwencj� mo�na uzyska�, wybieraj�c �cie�k�, jak pokazano poni�ej:

       [9 9 *]
       [* 7 *]
       [* 9 5]
       [* * 2]

Napisz wydajny algorytm dla nast�puj�cych za�o�e�:

N i M to liczby ca�kowite z zakresu [1�1 000];
ka�dy element macierzy A jest liczb� ca�kowit� z zakresu [1..9].
*/
#include <iostream>
#include <memory>
#include "Tree.h"

int main()
{
    int rows = 4;// N
    int cols = 3; // M

    std::vector<std::vector<int>> matrix = { {9, 9, 7},
                                           { 9, 7, 2 },
                                           { 6, 9, 5 },
                                           { 9, 1, 2 }};

    Tree my_tree;
    my_tree.insert_matrix(matrix);
    std::cout << "Breadth First Search: " << std::endl;
    my_tree.BFS();
    std::cout << std::endl;
    std::cout << "Max sum from root to leaf: " << my_tree.MaxSumFromRootToLeaf() << std::endl;

    return 0;
}

