# Max_sequence_in_a_matrix
Otrzymujesz macierz A składającą się z N wierszy i M kolumn, gdzie każda komórka zawiera cyfrę. Twoim zadaniem jest znaleźć ciągłą sekwencję sąsiednich komórek, zaczynającą się w lewym górnym rogu i kończącą się w prawym dolnym rogu (idąc tylko w dół i w prawo), która tworzy największą możliwą liczbę całkowitą poprzez połączenie cyfr na ścieżce. Przez sąsiednie komórki rozumiemy komórki, które mają dokładnie jedną wspólną stronę.  Napisz funkcję, która przy danej macierzy A składającej się z N wierszy i M kolumn zwraca łańcuch reprezentujący sekwencję komórek, które powinniśmy wybrać, aby uzyskać największą możliwą liczbę całkowitą.  Na przykład, biorąc pod uwagę następującą macierz A:  

[9 9 7]        
[9 7 2]        
[6 9 5]        
[9 1 2]  

funkcja powinna zwrócić „997952”, ponieważ taką sekwencję można uzyskać, wybierając ścieżkę, jak pokazano poniżej:  

[9 9 *]        
[* 7 *]        
[* 9 5]        
[* * 2]  

Napisz wydajny algorytm dla następujących założeń:  N i M to liczby całkowite z zakresu [1–1 000]; każdy element macierzy A jest liczbą całkowitą z zakresu [1..9].
