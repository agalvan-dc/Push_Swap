*Este proyecto ha sido creado como parte del currículo de 42 por caperale.*

# ft_printf

## Descripción

`ft_printf` es una reimplementación parcial de la función estándar `printf()` de C.

El objetivo del proyecto es comprender el funcionamiento de las funciones variádicas, el manejo de distintos tipos de datos y la impresión formateada utilizando únicamente funciones de bajo nivel como `write()`.

La implementación soporta los siguientes especificadores:

| Especificador | Descripción |
|---|---|
| `%c` | Carácter |
| `%s` | String |
| `%d` / `%i` | Entero con signo |
| `%u` | Entero sin signo |
| `%x` | Hexadecimal minúscula |
| `%X` | Hexadecimal mayúscula |
| `%p` | Dirección de memoria |
| `%%` | Carácter `%` |

---

# Instrucciones

## Compilación

Compilar la librería:

```bash
make
```

Eliminar archivos objeto:

```bash
make clean
```

Eliminar todos los archivos generados:

```bash
make fclean
```

Recompilar completamente:

```bash
make re
```

---

## Uso

Incluir el header:

```c
#include "ft_printf.h"
```

Ejemplo:

```c
#include "ft_printf.h"

int	main(void)
{
	int n = 42;

	ft_printf("Número: %d\n", n);
	ft_printf("Hexadecimal: %x\n", n);
	ft_printf("Pointer: %p\n", &n);
	return (0);
}
```

Compilar junto a la librería:

```bash
cc main.c libftprintf.a
```

---

# Funcionamiento

La función `ft_printf` recorre el string de formato carácter por carácter.  
Cuando encuentra `%`, interpreta el siguiente carácter como un especificador y llama a la función correspondiente para imprimir el valor recibido.

El proyecto utiliza funciones variádicas mediante:

- `va_start`
- `va_arg`
- `va_end`

---

# Algoritmo y estructura de datos

La implementación utiliza un recorrido lineal del string de formato, con una complejidad temporal de:

```text
O(n)
```

Cada conversión se encuentra separada en funciones independientes para mejorar la organización y reutilización del código.

Las conversiones numéricas utilizan recursividad para imprimir los dígitos en el orden correcto.

No se utilizan estructuras de datos complejas ni memoria dinámica, ya que el objetivo del proyecto es mantener una implementación simple, eficiente y fácil de mantener.

---

# Organización del proyecto

| Función | Descripción |
|---|---|
| `ft_putchar_pf` | Imprime un carácter |
| `ft_putstr_pf` | Imprime strings |
| `ft_putnbr_pf` | Imprime enteros |
| `ft_putu_pf` | Imprime enteros sin signo |
| `ft_puthex_pf` | Imprime hexadecimal |
| `ft_putptr` | Imprime punteros |

---

# Recursos

## Documentación

- https://man7.org/linux/man-pages/man3/printf.3.html
- https://cplusplus.com/reference/cstdarg/
- https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html

---

# Uso de IA

Se utilizó inteligencia artificial como apoyo teórico para comprender mejor el funcionamiento de las funciones variádicas y el uso de:

- `va_list`
- `va_start`
- `va_arg`
- `va_end`

También se utilizó para revisar la estructura y redacción del README.

La implementación y depuración del código fueron realizadas manualmente.

---

# Posibles mejoras

- Soporte para flags
- Width y precision
- Buffering interno
- Compatibilidad más completa con `printf`

---

# Autor

caperale