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


## Descripcion de los algoritmos de ordenación

## Gráfica comparativa 
![image](https://github.com/user-attachments/assets/26c4bcd3-546b-4f85-a618-6f60ac9c78b7)
Esta grafica tiene en el eje 'x' el tamaño de los arreglos, y en el eje 'y' el tiempo de ejecución en nanosegundos.Podemos observar como
los algoritmos menos eficientes son: Burbuja, Inserción, y Selección.


## Análisis de los resultados


## Conclusiones





