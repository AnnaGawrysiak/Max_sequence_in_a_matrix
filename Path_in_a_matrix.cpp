/*
 Otrzymujesz macierz A sk³adaj¹c¹ siê z N wierszy i M kolumn, gdzie ka¿da komórka zawiera cyfrê. Twoim zadaniem jest znaleŸæ ci¹g³¹ sekwencjê s¹siednich komórek, zaczynaj¹c¹ siê w lewym górnym rogu i koñcz¹c¹ siê w prawym dolnym rogu (id¹c tylko w dó³ i w prawo), która tworzy najwiêksz¹ mo¿liw¹ liczbê ca³kowit¹ poprzez po³¹czenie cyfr na œcie¿ce. Przez s¹siednie komórki rozumiemy komórki, które maj¹ dok³adnie jedn¹ wspóln¹ stronê.

Napisz funkcjê, która przy danej macierzy A sk³adaj¹cej siê z N wierszy i M kolumn zwraca ³añcuch reprezentuj¹cy sekwencjê komórek, które powinniœmy wybraæ, aby uzyskaæ najwiêksz¹ mo¿liw¹ liczbê ca³kowit¹.

Na przyk³ad, bior¹c pod uwagê nastêpuj¹c¹ macierz A:

       [9 9 7]
       [9 7 2]
       [6 9 5]
       [9 1 2]

funkcja powinna zwróciæ „997952”, poniewa¿ tak¹ sekwencjê mo¿na uzyskaæ, wybieraj¹c œcie¿kê, jak pokazano poni¿ej:

       [9 9 *]
       [* 7 *]
       [* 9 5]
       [* * 2]

Napisz wydajny algorytm dla nastêpuj¹cych za³o¿eñ:

N i M to liczby ca³kowite z zakresu [1–1 000];
ka¿dy element macierzy A jest liczb¹ ca³kowit¹ z zakresu [1..9].
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

