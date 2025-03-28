# OrdenacionesAlgoritmos
A través de un programa en C++, se compara la velocidad de ejecución de 7 distintos algoritmos de ordenación
al ordenar arreglos de tamaño 10, hasta tamaño 1000. El objetivo es observar y comparar los distintos tiempos de ejecución
y asi, su efectividad.

## Requisitos del sistema
En la carpeta 'Ordenaciones Csv' los archivos generados fueron construidos en una computadora con los siguientes componentes:

- Procesador: AMD Ryzen 7 7800X3D
- Memoria RAM: 16 GB
- Almacenamiento: 1 Tb
- Sistema operativo: Windows 10

Pero los requisitos mínimos para ejecutar el programa son:

- Procesador: Intel Core i3
- Memoria RAM: 4GB como mínimo (recomendable 8 GB para un rendimiento óptimo)
- Almacemaniento: Mínimo 100 mb disponibles.
- Sistema operativo: 
  - Windows 10 o superior
  - macOS 10.14 
  - Linux


## Compilación y ejecución
Para ejecutar el programa, asegúrese de tener el archivo ```TiemposAlgoritmos.cpp``` en una carpeta.
A través de la terminal, acceder a la carpeta donde se encuentre el archivo. Una vez ubicado ejecutar los siguientes comandos
en la terminal para compilar el programa:

```
g++ TiemposAlgoritmos.cpp -o TiemposAlgoritmos
```

Después, usar el siguiente comando para ejecutar el programa:

```
.\TiemposAlgoritmos.exe
```

## Archivos generados
El programa creará 8 archivos distintos en la misma locación donde se haya ejecutado el programa. 7 de estos están nombrados como 
un algoritmo de ordenación, por ejemplo, '1_Insercion_Ordenamiento' y son de tipo '.csv' _(Coma Separated Values)_. 
Dentro de cada uno de estos archivos se encontrará por columna el tamaño del arreglo ordenado, mientras
que por renglon se encuentra el tiempo en **nanosegundos** de cuanto tardó en ejecutarse. El octavo archivo es uno llamado 'Promedios.csv', en el cual
se reunen los promedios de todos los algoritmos para una comparación más directa. Dentro del repositorio se encuentra un 
archivo llamado 'GraficasPromedios.xlsx' donde se comparan todos los promedios en forma de gráfica.

***(Ejemplo de lo que se creara dentro de la carpeta al ejecutar 'TiemposAlgoritmos.exe')***
![image](https://github.com/user-attachments/assets/f832be32-2b10-4bae-985b-71a10027eda9)



## Descripcion de los algoritmos de ordenación

#### Burbuja
Este algoritmo itera sobre el arreglo y va comparando los elementos adyacentes. Si detecta que estan en el orden incorrecto,
los intercambia de lugar. El proceso se repite hasta que no se realicen más cambios, así detectando que la lista ya esta arreglada.

#### Selección
El algoritmo selecciona el elemento más pequeño de la lista no ordenada y lo coloca en su posición correcta. Luego, repite el proceso hasta
que la lista quede ordenada.

#### Inserción
Este algoritmo construye la lista ordenada de izquierda a derecha, ya que va iterando sobre los elementos uno a uno e insertando el
valor actual en la posición correcta de la parte ya ordenada de la lista.

#### Shell
Shell Sort (o inserción con intervalos decrecientes) es una versión mejorada del algoritmo por insersción, en lugar de comparar elementos 
adyacentes, compara los elementos a una distancia mayor llamada **gaps**, mientras más va avanzando el algoritmo, esta distancia se va haciendo menor
hasta que se comporta como un algoritmo de inserción normal.

#### Montículos
Este algoritmo utiliza una estructura de datos llamada heap, el cual es un árbol binario que sigue una propiedad muy importante:

- Max-heap: El valor de cada nodo es mayor que el de sus hijos
- Min-heap: El valor de cada nodo es menor que el de sus hijos.

Primero, convierte la lista en un montículo. Una vez que tenemos el montículo se extrae el valor más grande o el valor más pequeño, y es colocado en la posición correcta de la lista ordenada. Al extraer un elemento y colocarlo en otro lado, la lista se desajusta, por lo que es necesario restaurar la propiedad y repetir el proceso hasta que todos los elementos estén ordenados.

#### Mezcla (Merge Sort)
El algoritmo "Ordenación por Mezcla" (o Merge Sort), está basado en la técnica de **divide y vencerás**. El algoritmo divide la lista en dos mitades, hasta que quedan arreglos de tamaño uno. Despúes va ordenando recursivamente cada mitad y luego fusiona las mitades de manera ordenada.

#### Mezcla rápida (Quick Sort)
Este algoritmo también está basado en **divide y vencerás**. Elige un pivote en la lista y reorganiza los elementos, colocando los valores que son de menor tamaño a la izquierda del pivote, y los valores que son de mayor tamaño al lado derecho del pivote. Luego, aplica el mismo proceso recursivamente a sublistas de menor tamaño.

### Tabla comparativa de la complejidad de los algoritmos
| Algoritmo de ordenación  | MEJOR CASO | CASO PROMEDIO | PEOR CASO  | ESPACIO ADICIONAL |
|--------------------------|------------|---------------|------------|-------------------|
|Burbuja                   |    $O(n)$  |    $O(n^2)$   | $O(n^2)$   |       $O(1)$      |
|Selección                 |   $O(n^2)$ |    $O(n^2)$   | $O(n^2)$   |       $O(1)$      |
|Inserción                 |    $O(n)$  |    $O(n^2)$   | $O(n^2)$   |       $O(1)$      |
|Shell                     |    $O(n)$  |    $O(n^2)$   | $O(n^2)$   |       $O(1)$      |
|Montículos (Heap Sort)    |$O(nlog(n))$|  $O(nlog(n))$ |$O(nlog(n))$|    $O(nlog(n))$   |
|Mezcla (Merge Sort)       |$O(nlog(n))$|  $O(nlog(n))$ |$O(nlog(n))$|       $O(n)$      |
|Mezcla rapida (Quick Sort)|  $O(n^2)$  |  $O(nlog(n))$ |$O(nlog(n))$|    $O(log(n))$    |

## Gráfica comparativa 

![image](https://github.com/user-attachments/assets/26c4bcd3-546b-4f85-a618-6f60ac9c78b7)

Esta es una gráfica comparativa. Aquí se puede ver claramente cuáles algoritmos son menos eficientes, ya que entre más pronunciada
esté la curva, demora más nanosegundos en ordenar un arreglo de tamaño n.

![image](https://github.com/user-attachments/assets/272a4a46-5829-458a-8bf2-1188ef0fa0d3)

En esta otra gráfica, hacemos un acercamiento a las funciones de menor tiempo de ejecución para ver más claramente su comportamiento.
Viéndolo de cerca, se puede ver claramente como las gráficas de Inserción, Selección y Burbuja tienen una complejidad $n^2$, por lo tanto, entre más grande sea el arreglo más tardarán, mientras que el resto de algoritmos crecen más lentamente.


## Análisis de los resultados
Al visualizar los datos dentro de los archivos '.csv', podemos ver patrones evidentes.
Cuando los arreglos son de tamaños pequeños, el tiempo de ejecución suele variar entre 200 y 700 nanosegundos, dependiendo del algoritmo usado. Sin embargo, mientras más va creciendo el tamaño del arreglo a ordenar, más incrementa el tiempo de ejecución.

Al observar los arreglos de tamaño 700, 800, 900 o 1000, podemos ver una diferencia **clara** entre los tiempos de ejecución y la eficiencia de cada algoritmo. Por ejemplo, el de burbuja puede llegar a tardar 1,700,000 nanosegundos, mientras que algoritmos como QuickSort o MergeSort se pueden ejecutar en menos de 200,000 nanosegundos.

Al analizar gráficamente los datos, podemos observar como las curvas de los algoritmos Inserción, Burbuja, y Selección crecen muy rapidamente, lo que refleja su complejidad $O(n^2)$, mientras que el resto de algoritmos pareciera que crecen linealmente. Sin embargo, al acercarnos a sus gráficas y analizarlas con más detalle, podemos ver que tienen un crecimiento lento pero parecido a $O(n^2)$, lo cual es lo esperado.



## Conclusiones
Este proyecto ha permitido analizar y comparar el rendimiento de múltiples algoritmos de ordenación. Pudimos observar, analizar, y comparar tanto analíticamente (a través de las tablas de tiempo de ejecución), como gráficamente los comportamientos de los algoritmos respecto a sus complejidades. 

A la hora de resolver un problema, es crucial destacar la adecuada elección del algoritmo de ordenación, dependiendo del tamaño del arreglo a ordenar. Por ejemplo, en arreglos de tamaño 10 o 20, la "Ordenacion por Burbuja" superaba a los algoritmos más rápidos como "MergeSort" o "QuickSort". Cuando se ordenaban arreglos de tamaño 10, el algoritmo de burbuja mostró tiempos de ejecución de entre 100 y 300 nanosegundos mientras que MergeSort con el mismo tamaño de arreglo, oscilaba entre 500 y 800 nanosegundos.
