Aquí tienes el texto de la hoja de evaluación completamente corregido, eliminando las palabras repetidas, los errores de traducción ("evaluación electoral", "error seguidor") y estructurado en un formato Markdown limpio, profesional y fácil de leer durante la defensa.

---

# Hoja de Evaluación: Push_swap

## Parte Preliminar

### Asistencia del Grupo

* La evaluación solo se realizará si **todas** las personas del grupo se encuentran presentes.
* Se busca la interacción entre pares: todos los integrantes deben estar presentes, explicar el código y debatir con el evaluador.
* En el momento en el que un ejercicio no funcione correctamente, **la evaluación se detiene**. El evaluador podrá seguir mirando el código, pero el proyecto no será aprobado.

### Comprobaciones Previas

* **Autoría:** Verifica que las personas del grupo sean las dueñas reales del repositorio Git.
* **Defensa:** Comprueba que todos los integrantes explican, defienden y conocen el proceso de implementación.
* **README.md:** Confirma que en el archivo `README.md` queden documentadas las contribuciones de cada parte.
* **Conocimiento global:** Todos los componentes del grupo deben demostrar que entienden todo el proyecto en su totalidad, no solamente la parte en la que han contribuido individualmente. *Si alguno de estos requisitos no se cumple, la evaluación será suspendida inmediatamente.*

### Cumplimiento del README.md

Verifica que el archivo `README.md` esté presente en la raíz del repositorio e incluya lo siguiente:

* **Primera línea:** Debe estar en cursiva y formateada exactamente como: *Este proyecto ha sido creado como parte del currículo de 42 por , .*
* **Descripción:** Una sección que presente claramente el proyecto, incluyendo su objetivo principal y una breve visión general.
* **Instrucciones:** Una sección que contenga información sobre la compilación, instalación y/o ejecución del programa.
* **Recursos:** Lista de referencias analizadas (documentación, tutoriales, etc.) y una **descripción explícita del uso de la IA**, especificando para qué tareas y en qué partes del proyecto se ha utilizado.
* **Algoritmos:** Explicación detallada y justificación de los algoritmos seleccionados (Estrategia Simple $O(n^2)$, Intermedia $O(n\sqrt{n})$, Compleja $O(n \log n)$ y Adaptativa).
* **Contribuciones:** Documentación detallada de las aportaciones individuales de cada miembro.

---

## Parte Obligatoria

> ⚠️ **Nota Crítica:** Durante la defensa no debe ocurrir ningún fallo de segmentación (Segmentation fault), crasheo, bus error o incidentes similares que terminen la ejecución de forma abrupta. Si esto ocurre, la nota final será automáticamente **0**. Esta regla se aplica a toda la evaluación.

### Norminette

* Ejecuta la Norminette en el repositorio. Si arroja algún error, **la evaluación se detiene** (puedes continuar discutiendo el código con tus compañeros, pero no será evaluado).

### Compilación

* Comprueba la existencia de un `Makefile` con las reglas requeridas: `NAME`, `all`, `clean`, `fclean`, `re`.
* El `Makefile` debe compilar usando las flags `-Wall -Wextra -Werror` y **no debe hacer relink**.
* Compila usando el comando `make` y verifica que se cree correctamente el ejecutable `push_swap`.
* Comprueba que los comandos `make clean`, `make fclean` y `make re` funcionen correctamente.
* Si surge algún error de compilación o el `Makefile` no cumple las reglas, la evaluación termina con **0**.

### Fugas y Pérdidas de Memoria

* Monitorea la memoria del programa `push_swap` (por ejemplo, usando herramientas como `top`, `leaks` o `valgrind`) para asegurarte de que toda la memoria asignada se libere correctamente al finalizar.
* Si existen fugas de memoria (*memory leaks*) significativas, la nota final será **0**.
* *Nota:* Pequeños descuidos aislados pueden ser aceptables, pero no se tolerarán grandes fugas recurrentes ni cierres inesperados.

### Manejo de Errores

El programa debe gestionar correctamente los errores enviando el mensaje `Error\n` a la **salida de errores estándar (stderr / fd 2)**.
*Para superar esta sección se deben validar correctamente al menos 3 de las siguientes 4 pruebas:*

1. **Parámetros no numéricos:** Ejecuta `./push_swap 2 3 a 4`. Debe mostrar `Error`.
2. **Números duplicados:** Ejecuta `./push_swap 2 3 4 2`. Debe mostrar `Error`.
3. **Desbordamiento de INT:** Ejecuta un comando con un valor mayor a `MAXINT` o menor a `MININT` (ej: `./push_swap 2147483648`). Debe mostrar `Error`.
4. **Sin argumentos:** Ejecuta `./push_swap` sin parámetros. El programa no debe mostrar nada y debe devolver el control al usuario inmediatamente.

### Selector de Estrategia (Tests Básicos)

Comprueba que el programa responda correctamente a las banderas de selección manual de estrategia. *(Deben pasar al menos 3 de los 5 tests)*.

* **Simple:** `$> ./push_swap --simple 5 4 3 2 1` (Debe imprimir las operaciones para ordenarlo).
* **Medio:** `$> ./push_swap --medio 5 4 3 2 1` (Debe imprimir las operaciones para ordenarlo).
* **Complex:** `$> ./push_swap --complex 5 4 3 2 1` (Debe imprimir las operaciones para ordenarlo).
* **Adaptive:** `$> ./push_swap --adaptive 5 4 3 2 1` (Debe imprimir las operaciones para ordenarlo).
* **Por defecto:** Comprueba que al ejecutar el programa **sin flags**, el comportamiento por defecto sea equivalente al uso de `--adaptive`.

### Pruebas de Identidad (Ya Ordenadas)

El programa no debe realizar ninguna instrucción si los números ya se encuentran ordenados. *(Deben pasar al menos 3 de los 4 tests)*.

* `$> ./push_swap 42` $\rightarrow$ No debe mostrar ninguna instrucción.
* `$> ./push_swap 2 3` $\rightarrow$ No debe mostrar ninguna instrucción.
* `$> ./push_swap 0 1 2 3` $\rightarrow$ No debe mostrar ninguna instrucción.
* `$> ./push_swap 0 1 2 3 4 5 6 7 8 9` $\rightarrow$ No debe mostrar ninguna instrucción.

### Entradas Pequeñas (3 Números)

Prueba el programa con combinaciones de 3 números aleatorios y utiliza el checker de la escuela para comprobar la validez de la ordenación:

* `$> ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG`
* Comprueba que el checker devuelva **`OK`**.
* **Métricas de rendimiento:** * $\le 5$ operaciones es **Aceptable**.
* $\le 3$ operaciones se considera un **Buen trabajo**.


* Varía con otras combinaciones como `"0 2 1"` o `"1 0 2"` para asegurar la consistencia.

### Entradas Medianas (5 Números)

Prueba el programa con combinaciones de 5 números:

* `$> ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG`
* Comprueba que el checker devuelva **`OK`**.
* **Métricas de rendimiento:** * $\le 15$ operaciones es **Aceptable**.
* $\le 12$ operaciones se considera un **Buen trabajo**.


* Haz pruebas adicionales con combinaciones aleatorias como `"5 1 4 2 3"` o `"3 5 1 4 2"`.

### Modo "Benchmark" y Porcentaje de Desorden

Comprueba el funcionamiento del modo de análisis de rendimiento. Si no funciona perfectamente el proyecto no se suspende, pero los estudiantes deben justificar su implementación según el enunciado.

* **Salida Estándar:** `$> ./push_swap --bench --simple 5 4 3 2 1 2>/dev/null` debe seguir mostrando los movimientos normales para ordenar la pila.
* **Salida de Errores (Métricas):** `$> ./push_swap --bench --simple 5 4 3 2 1 >/dev/null` (redireccionando el resultado a un archivo o viéndolo por `stderr`). El benchmark debe contener:
* Porcentaje de desorden inicial detectado.
* Nombre de la estrategia y su complejidad algorítmica ($O$).
* Número total de operaciones ejecutadas.
* Conteo pormenorizado e individualizado de cada operación (`sa`, `pb`, `ra`, etc.).


* **Verificación del cálculo de desorden:**
* Lista perfectamente ordenada (`1 2 3 4 5`) $\rightarrow$ El desorden debe ser **0.00%**.
* Lista inversamente ordenada (`5 4 3 2 1`) $\rightarrow$ El desorden debe ser **100.00%**.



### Entradas Grandes (100 Números)

Prueba el programa con un set masivo de 100 elementos. Puedes generar listas aleatorias con comandos como: `shuf -i 1-500 -n 100`.

* Realiza 2 o 3 pruebas distintas con sets de 100 números y valida con el checker (`OK`).
* **Métricas de rendimiento:**
* $\le 2000$ operaciones para **Aprobar** esta sección.
* $< 1500$ operaciones es un **Buen rendimiento**.
* $< 700$ operaciones es un **Rendimiento excelente**.



### Consulta del Código y Explicación de los Algoritmos

Pídele al grupo una explicación clara y práctica (no puramente teórica de libro) sobre sus estrategias:

* ¿Cómo funciona la estrategia `--simple`? (Enfoque de $O(n^2)$).
* ¿Cómo funciona la estrategia `--medio`? (Enfoque de $O(n\sqrt{n})$).
* ¿Cómo funciona la estrategia `--complex`? (Enfoque de $O(n \log n)$).
* ¿Qué métricas evalúa el método `--adaptive` para autoseleccionar la estrategia adecuada?

### Pruebas de las Banderas de Estrategias

* Genera una lista de 50 números: `shuf -i 1-200 -n 50`.
* Ejecuta la **misma entrada** usando consecutivamente las banderas `--simple`, `--medio` y `--complex`.
* Todas deben ordenar correctamente la lista, pero se debe apreciar la diferencia en eficiencia: por regla general, `--complex` debe requerir sustancialmente menos operaciones que `--simple`.
* El modo `--adaptive` (o no poner banderas) debe escoger automáticamente la ruta óptima.

### Entradas Muy Grandes (500 Números)

Genera listas aleatorias de 500 números usando: `shuf -i 1-1000 -n 500`.

* Realiza al menos 2 pruebas distintas y pásalas por el checker (`OK`).
* **Métricas de rendimiento:**
* $\le 12000$ operaciones para **Aprobar** la sección.
* $< 8000$ operaciones indica una **Buena implementación**.
* $< 5500$ operaciones es un **Rendimiento excelente**.



### Modificación del Código en Directo

Pídele al grupo que añada una nueva bandera llamada `--count-only` a su código.

* **Comportamiento:** Al ejecutarse (ej: `./push_swap --count-only 3 2 1`), el programa **no debe imprimir la lista de operaciones**, sino únicamente el número total entero de operaciones que le costaría ordenarlo (ej: imprimiría simplemente `3\n`).
* **Condiciones:** El grupo debe localizar el código de parseo y salida pertinente, realizar la modificación y compilar demostrando su funcionamiento en un tiempo **máximo de 10 minutos**.

---

## Parte Bonus

> ⚠️ **Regla del Bonus:** El bonus solo se corregirá si la parte obligatoria es **perfecta e impecable (100%)**. Si la parte obligatoria no alcanza la máxima puntuación, los bonus se ignoran por completo. Las reglas de crasheos/segfaults se aplican idénticamente aquí.

### Programa Checker - Manejo de Errores

El programa checker debe gestionar los mismos casos de error que la parte obligatoria, imprimiendo `Error\n` en la **salida de errores (stderr)**. *(Deben pasar todos los casos para puntuar)*.

1. **Parámetros no numéricos:** `$> ./checker 1 2 a 4` $\rightarrow$ `Error`.
2. **Números duplicados:** `$> ./checker 1 2 3 1` $\rightarrow$ `Error`.
3. **Desbordamiento de INT:** `$> ./checker 2147483648` $\rightarrow$ `Error`.
4. **Sin argumentos:** `$> ./checker` $\rightarrow$ No hace nada y devuelve el control al usuario.
5. **Operación inexistente:** `$> ./checker 1 2 3`, introduces por teclado `abc` $\rightarrow$ `Error`.
6. **Operación válida mal formateada (Espacios/Tabs):** `$> ./checker 1 2 3`, introduces ` sa` o `sa ` $\rightarrow$ `Error`.

### Programa Checker - Casos KO (Falsos)

Comprueba que el checker detecte de forma efectiva cuándo una lista de instrucciones **no** ordena la pila. *(Usa `CTRL+D` para indicar el fin de las instrucciones por teclado)*.

* `$> ./checker 0 9 1 8 2 7 3 6 4 5` $\rightarrow$ Introduces las instrucciones `sa`, `pb`, `rrr` $\rightarrow$ Debe devolver **`KO`**.
* Realiza pruebas con combinaciones numéricas propias para asegurarte de que el checker no está hardcodeado para las pruebas de la hoja de evaluación. Si la lista no queda ordenada, debe devolver **`KO`**.

### Programa Checker - Casos OK (Reales)

Comprueba que el checker detecte cuándo una lista de instrucciones ordena la lista de forma legítima.

* `$> ./checker 0 1 2` $\rightarrow$ Pulsas `CTRL+D` inmediatamente (ya está ordenada) $\rightarrow$ Debe devolver **`OK`**.
* `$> ./checker 0 9 1 8 2` $\rightarrow$ Introduces las operaciones `pb`, `ra`, `pb`, `ra`, `sa`, `ra`, `pa`, `pa` y luego `CTRL+D` $\rightarrow$ Debe devolver **`OK`**.
* Realiza una prueba personalizada metiendo una lista desordenada, las operaciones obtenidas a través de tu `push_swap` y valida que el resultado sea siempre **`OK`**.