# Andrade.Lucas-Beiza.Vicente-Oteiza.Pascual-Vicuña.Sebastian-Tarea3.2025.1

Proyecto de **algoritmo _Publisher–Subscriber_** en **C++17** desarrollado con **Qt 6** (Qt Creator).  
El sistema permite publicar y suscribir mensajes de dos dominios: *video* y *telemetría GPS*.

**Profesor:** Patricio Olivares  
**Ayudantes:** Byron Agurto, Ignacio González  
**Integrantes:** Lucas Andrade, Vicente Beiza, Pascual Oteiza, Sebastián Vicuña

---

## 1. Prerrequisitos

| Herramienta            | Versión mínima | Uso                           |
|------------------------|---------------:|-------------------------------|
| Qt Creator             | 10 / Qt 6.7    | IDE: compilación y depuración |
| CMake / QMake          | —              | Compilación desde terminal    |
| GCC / Clang            | C++17          | Compilador C++                |

> **Sistemas probados:** Ubuntu 24.04 LTS y Windows 10 x64.

---

## 2. Estructura de archivos (etapa final)

- **TareaPOO.pro**

### Código fuente

- `broker.cpp`
- `broker.h`
- `component.cpp`
- `component.h`
- `gpscarpublisher.cpp`
- `gpscarpublisher.h`
- `gpsfollower.cpp`
- `gpsfollower.h`
- `main.cpp`
- `mainwindow.cpp`
- `mainwindow.h`
- `mainwindow.ui`
- `publisher.cpp`
- `publisher.h`
- `subscriber.cpp`
- `subscriber.h`
- `topic.cpp`
- `topic.h`
- `videofollower.cpp`
- `videofollower.h`
- `videoplayerwindow.cpp`
- `videoplayerwindow.h`
- `videopublisher.cpp`
- `videopublisher.h`

### Datos de prueba

- `trayectoria.txt`

## 3. Compilación

### 3.1 Con **Qt Creator** (recomendado)

1. *File → Open File or Project…* y seleccione **TareaPOO.pro**.  
2. Elija un *Kit* con Qt 6 y C++17.  
3. Pulse **Build (F5)**. Los binarios aparecerán en `./build/bin/`

## 4. Ejecución

> **Orden recomendado:** primero el **Broker**, luego los publicadores y, por último, los suscriptores.

### 4.1 Publicadores

videopublisher:
    Envía frames JPEG desde un vídeo.

gpscarpublisher:
    Envía posiciones desde trayectoria.txt

### 4.2 Suscriptores

videofollower:
    Muestra el stream de vídeo en una ventana.

gpsfollower:
    Dibuja la trayectoria en un QGraphicsScene.

## 5. Formato de trayectoria.txt

Cada línea:
<tiempo_segundo>  <x_coord>  <y_coord>

Ejemplo:
```md
0   10   45
1   12   46
3   20   50
```

videoplayerwindow.(h|cpp)
    Añade controles de reproducción (play/pause, seek) y ajuste de FPS.
