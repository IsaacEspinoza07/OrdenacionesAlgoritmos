# OrdenacionesAlgoritmos
A través de un programa en C++, se compara la velocidad de ejecución de 7 distintos algoritmos de ordenación
al ordenar arreglos de tamaño 10, hasta tamaño 1000. El objetivo es observar y comparar los distintos tiempos de ejecución
y asi, su efectividad.

## Requisitos del sistema


## Compilación y ejecución
Para ejecutar el programa, asegúrese de tener el archivo ```TiemposAlgoritmos.cpp``` en una carpeta.
A través de la terminal, acceder a la carpeta donde se encuentre el archivo. Una vez ubicado ejecutar los siguientes comandos
en la terminal para compilar el programa:

```
g++ TiemposAlgoritmos.cpp -o TiemposAlgoritmos
```

Despues, usar el siguiente comando para ejecutar el programa:

```
.\TiemposAlgoritmos.exe
```

## Archivos generados
El programa creara 8 archivos distintos en la misma locacion donde se haya ejecutado el programa. 7 de estos estan nombrados como 
un algoritmo de ordenacion, por ejemplo, '1_Insercion_Ordenamiento' y son de tipo .csv _(Coma Separated Values)_. 
Dentro de cada uno de estos archivos se encontrara por columna el tamaño del arreglo ordenado, mientras
que por renglon se encuentra el tiempo en **nanosegundos** de cuanto tardó en ejecutarse. El octavo archivo es uno llamado 'Promedios.csv', en el cual
se reunen los promedios de todos los algoritmos para una comparación más directa. Dentro del repositorio se encuentra un 
archivo tipo .xlsx donde se comparan todos los promedios en forma de gráfica.

![image](https://github.com/user-attachments/assets/f832be32-2b10-4bae-985b-71a10027eda9)



## Descripcion de los algoritmos de ordenación
### Burbuja

### Selección

### Inserción

### Shell

### Montículos

### Mezcla (Merge Sort)

### Mezcla rápida (Quick Sort)


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

Esta es una gráfica comparativa. Aqui se puede ver claramente cuales algoritmos son menos eficientes, ya que entre mas pronunciada
este la curva, significa que le demora mas nanosegundos en ordenar un arreglo de tamaño n.

![image](https://github.com/user-attachments/assets/272a4a46-5829-458a-8bf2-1188ef0fa0d3)

En esta otra gráfica, hacemos un acercamiento a las funciones de menor tiempo de ejecución para ver más claramente su comportamiento.
Viendolo de cerca, se puede ver claramente como las gráficas de Incersion, Selección y Burbuja tienen una complejidad $n^2$, por lo tanto, entre
más grande sea el arreglo más tardara, mientras que el resto de algoritmos crecen más lentamente.


$[[1,2,3][3,2,1][4,5,6]]$

## Análisis de los resultados


## Conclusiones





