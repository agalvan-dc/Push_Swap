*Este proyecto ha sido creado como parte del currículo de 42 por agalvan-, caperale.*

# Push_swap

## Descripción

**Push_swap** es un proyecto de desarrollo algorítmico clásico en el currículo de 42. El objetivo principal es ordenar un conjunto de datos numéricos en una estructura de pila (Stack A), utilizando una pila auxiliar (Stack B) y un conjunto limitado de instrucciones permitidas. El desafío reside en lograr la ordenación con el **mínimo número posible de operaciones**.

El proyecto pone a prueba la capacidad de análisis de complejidad temporal y espacial, la manipulación de estructuras de datos lineales (listas doblemente enlazadas) y el diseño de estrategias algorítmicas adaptativas según el volumen de datos de entrada.

---

## División del Trabajo y Colaboración

Para optimizar el desarrollo y garantizar la modularidad del código, el proyecto fue dividido equitativamente entre los miembros del equipo:

* **`caperale`**: Responsable del desarrollo de los algoritmos de ordenación pequeños y medianos (**Simple Sort** y **Medium Sort**), la implementación base y control de todas las **operaciones** de las pilas (`sa`, `pb`, `ra`, etc.).
* **`agalvan-`**: Responsable del algoritmo para grandes volúmenes de datos (**Complex Sort**), la arquitectura del **parseo** robusto de argumentos en la línea de comandos, y el sistema de **Benchmarking** integrado (`--bench`) encargado de medir el rendimiento y las métricas de desorden.

---

## Análisis y Justificación de Algoritmos

El núcleo del proyecto utiliza un enfoque híbrido y adaptativo. Dependiendo de la cantidad de números introducidos, el programa selecciona automáticamente la estrategia de ordenación más eficiente:

### 1. Simple Sort (Para inputs pequeños: ≤ 5 elementos)

* 
**Complejidad Temporal:** $O(n^2)$ en el peor de los casos.


* **Explicación:** Diseñado específicamente para optimizar conjuntos de 3 a 5 elementos. Evalúa las posiciones relativas de los nodos mediante condiciones fijas (*fuerza bruta* inteligente). Para 5 elementos, busca recursivamente los dos números más pequeños, los desplaza a la Stack B, ordena los 3 restantes en un máximo de 2 pasos y vuelve a insertar los elementos de B.
* **Justificación:** A pesar de su complejidad teórica $O(n^2)$, para tamaños de muestra tan reducidos, el sobrecoste de indexación de algoritmos avanzados gastaría más operaciones de las necesarias. Garantiza la ordenación de 3 elementos en ≤ 3 operaciones y de 5 elementos en ≤ 12 operaciones.

### 2. Chunk Sort (Para inputs medianos: ≈ 100 elementos)

* 
**Complejidad Temporal:** $O(n\sqrt{n})$.


* **Explicación:** Este algoritmo pre-ordena conceptualmente los elementos asignándoles un índice relativo de 0 a n-1. Luego, divide el espectro total de números en subconjuntos o bloques (*chunks*), cuyo tamaño óptimo suele determinarse mediante la raíz cuadrada del total. Los elementos pertenecientes al bloque actual se van enviando a la Stack B de manera cruda, reduciendo la distancia de rotación necesaria para localizarlos.
* **Justificación:** Reduce drásticamente el espacio de búsqueda en comparación con el método simple. Al segmentar la pila, la cantidad de operaciones de rotación (`ra`, `rra`) requeridas para empujar elementos disminuye significativamente, manteniéndose cómodamente por debajo del límite de las 700 operaciones exigidas para 100 números.



### 3. Ksort / Estrategia Compleja (Para inputs grandes: ≥ 500 elementos)

* 
**Complejidad Temporal:** $O(n \log n)$.


* **Explicación:** Inspirado en variaciones de ordenamiento por rango (*Range Sort*) y mecánicas similares a *Radix*. Utiliza una ventana deslizante dinámica basada en una fórmula matemática construida a partir de la raíz del volumen total. El algoritmo recorre la Stack A y traslada a B aquellos elementos cuyo índice sea menor o igual al paso actual del bucle. Si el índice se encuentra en la mitad inferior del rango, el elemento se rota al fondo de B (`rb`), generando una estructura en forma de "reloj de arena" o mariposa en la Stack B. Finalmente, se devuelven a A buscando eficientemente siempre el número mayor disponible.
* **Justificación:** Es el algoritmo más eficiente para el escalado masivo de datos. Al mantener una estructura matemática predecible en B, la fase de retorno a la Stack A minimiza drásticamente el uso de operaciones costosas, permitiendo ordenar 500 números de manera consistente en un promedio menor a las 5500 operaciones.



### 4. Algoritmo Adaptativo (Modo por defecto: `--adaptive`)

* 
**Explicación del Índice de Desorden:** Antes de realizar ningún movimiento, el programa calcula el nivel de desorden inicial de la pila A comparando todos los pares posibles de números. Cada vez que un número mayor aparece antes que uno menor, se contabiliza como un error. Este índice es un valor entre 0 (totalmente ordenado) y 1 (desorden absoluto).


* 
**Justificación de Umbrales y Complejidad:** El modo adaptativo selecciona el motor interno de ordenación basándose estrictamente en este cálculo inicial para garantizar la máxima eficiencia de operaciones. Los umbrales definidos cumplen con los requisitos del modelo de Push_swap:



| Nivel de Desorden | Umbral de Activación | Complejidad Requerida | Estrategia Interna Delegada |
| --- | --- | --- | --- |
| **Bajo** | Desorden < 0,2 

 | <br>$O(n)$ 

 | Resolución lineal / Inserción directa |
| **Medio** | 0,2 ≤ Desorden < 0,5 

 | <br>$O(n\sqrt{n})$ 

 | Chunk Sort (Algoritmo intermedio) |
| **Alto** | Desorden ≥ 0,5 

 | <br>$O(n \log n)$ 

 | Ksort (Algoritmo complejo) |

---

## Instrucciones

### Compilación e Instalación

Clona el repositorio y compila el proyecto ejecutando el comando `make` en la raíz del mismo:

```bash
git clone <url-del-repositorio> push_swap
cd push_swap
make

```

Esto generará el ejecutable `push_swap`. Si deseas compilar el verificador de instrucciones (Bonus):

```bash
make bonus

```

### Ejecución

El programa recibe como parámetros la lista de números enteros a ordenar, ya sea como argumentos independientes o integrados en una cadena de texto entrecomillada.

**Formato Estándar:**

```bash
./push_swap 4 67 3 87 23

```

**Formato con Cadena de Texto:**

```bash
./push_swap "4 67 3 87 23"

```

**Modo de Pruebas con Flags y Checker:**

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

```

**Uso de la Opción Bench (Desarrollada por agalvan-):**
Permite analizar métricas de desorden inicial y el comportamiento adaptativo interno del programa.

```bash
./push_swap --complex --bench "1 5 2 4 3 85 54"

```

---

## Recursos

### Referencias Consultadas

* *Push_swap Tutorial - De $O(n^2)$ a $O(n \log n)$* (Análisis de algoritmos de ordenación por bloques).
* Documentación de manejo de bits y optimización de estructuras lineales en C.

### Uso de Inteligencia Artificial

En este proyecto se ha utilizado Inteligencia Artificial como herramienta de soporte técnico en las siguientes tareas específicas:

* **Cumplimiento Norminette:** Optimización sintáctica para adaptar funciones extensas al estándar de codificación exigido por la escuela sin perder legibilidad ni rendimiento.
* 
**Redacción y Documentación (README.md):** Estructuración, síntesis de las responsabilidades del equipo y redacción técnica de este documento para cumplir estrictamente con las directrices y requisitos de entrega solicitados en el currículo.