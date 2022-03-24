# Caso2 ADA
# Por: Sebastián Bermúdez Acuña - 2021110666
# Fecha: 2022-03-23

Compilado con g++ en MAC.
Todos los tiempos de ejecución están dados en nanosegundos.

# QuickSort Logarítmico
    • Pivote random
T1 = Entradas: 1000, tiempo de ejecución --> 287008
T2 = Entradas: 10000, tiempo de ejecución --> 3871718, 3380094
T3 = Entradas: 50000, tiempo de ejecución --> 18082261

L1: n = 1000 --> n*log(n) = 3000
L2: n = 10000 --> n*log(n) = 40000
L3: n = 50000 --> n*log(n) = 234948,5

L2/L1 = 13.333 | T2/T1 = 13.489930
L3/L2 = 5,87   | T3/T2 = 5.349

La proporción entre los números consecutivos en cuanto a las entradas utilizadas en ambas operaciones del n*log(n) como el quickSort con pivote random
es muy similar tras varias pruebas con diferentes tiempos de ejecución, por lo que se concluye a quicksort con pivote random como el caso de nlog(n).

# QuickSort Cuadrático
    • Pivote fijo alto
T1 = Entradas: 1000, tiempo de ejecución --> 3243315
T2 = Entradas: 10000, tiempo de ejecución -->324446466
T2 = Entradas: 50000, tiempo de ejecución -->8437645160


L1: n = 1000 --> n^2 = 1000000
L2: n = 10000 --> n^2 = 100000000
L2: n = 50000 --> n^2 = 2500000000

L2/L1 = 100 | T2/T1 = 100.03544
L3/L2 = 25  | T3/T2 = 26.006

Al utilizar un pivote fijo alto, tras varios tiempos de ejecución como resultado, se demuestra como la proporción real de n^2 es muy aproximada a la de
2 resultados del algoritmo real. El pivote fijo del quicksort aplica para su caso O(n^2).

# Insertion Sort Lineal

T1 = Entradas: 1000, tiempo de ejecución --> 7506
T2 = Entradas: 10000, tiempo de ejecución -->71260
T3 = Entradas: 100000, tiempo de ejecución-->764155

L1: n = 1000 --> n = 1000
L2: n = 10000 --> n = 10000
L3: n = 100000 --> n = 100000

L2/L1 = 10 | T2/T1 = 9.49373
L3/L2 = 10 | T3/T2 = 10.72347

Al ser lineal, la proporción de los L es la misma. Ambas proporciones T2 con T1 y T3 con T2 son muy cercanas a las del grado de la función. Eso confirma
que el insertion sort con el mejor caso (arreglo ordenado) es de grado n.

# Insertion Sort Cuadrático

T1 = Entradas: 1000, tiempo de ejecución --> 1680672
T2 = Entradas: 10000, tiempo de ejecución --> 163618815   
T3 = Entradas: 50000, tiempo de ejecución --> 3984653696

L1: n = 1000 --> n^2 = 1000000
L2: n = 10000 --> n^2 = 100000000
L3: n = 50000 --> n^2 = 2500000000


L2/L1 = 100 | T2/T1 = 97.3532
L3/L2 = 25  | T3/T2 = 24.3532

Evaluando resultados de tiempos de ejecución del peor caso de insertion sort (arreglo completamente desordenado) con diferentes tamaños, la proporción
entre la función de f(n) y el algoritmo con el mismo n es muy similar. Efectivamente el O(n^2) para el insertion sort.

# Algoritmo freetext
    El algoritmo de de Z es lineal. Con un comportamiento de O(n+m). Con comlejidad de espacio lineal
m = 1 --> 1627793411, 2168293870 
m = 5 --> 961363020 , 906628479
m = 9 --> 946759242 , 949881274
          |           •
          |         •
1500000000|
          |      •
9500000   |     •
          |    •
          |  •
          -----------------------------
