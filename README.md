# Sistema de Control Climático Inteligente

Un sistema inteligente de gestión ambiental que mantiene automáticamente condiciones óptimas de temperatura e iluminación utilizando control basado en Arduino con monitorización de sensores en tiempo real y algoritmos de respuesta adaptativa.

![Licencia](https://img.shields.io/badge/license-Apache%202.0-blue)
![Plataforma](https://img.shields.io/badge/platform-Arduino-orange)
![Lenguaje](https://img.shields.io/badge/language-C%2B%2B-blue)
![Estado](https://img.shields.io/badge/status-Active-green)

## 📋 Información del Proyecto

Este proyecto ha sido desarrollado por el **Grupo 10** del **Máster Universitario en Ingeniería de Telecomunicación** de la **Universidad Internacional de La Rioja (UNIR)**.

### Autores
- Iván Pérez Doña
- Samuel González Rojas
- Pablo Martín Rodríguez
- Juan Gonzalo Martínez Rubio

## 🎯 Descripción General

Este sistema demuestra principios avanzados de IoT a través de una implementación de control en lazo cerrado que monitorea las condiciones ambientales y responde automáticamente para mantener zonas de confort definidas por el usuario. El proyecto integra múltiples sensores, actuadores y una interfaz hombre-máquina (HMI) para crear una solución completa de gestión climática.

### Características Principales

- **🌡️ Control Inteligente de Temperatura**: Mantiene un rango de 22°C-28°C con calefacción/refrigeración automática
- **💡 Sistema de Iluminación Adaptativo**: Matriz LED de 8 canales con compensación de luz ambiental
- **📱 Pantalla en Tiempo Real**: LCD 16x2 con visualización de información en modo dual
- **🔄 Operación Autónoma**: Monitorización continua con algoritmos de control responsivos
- **⚡ Diseño de Bajo Consumo**: Optimizado para operación eficiente con consumo mínimo de corriente

## 🚀 Video Demostrativo

*Próximamente - Demostración del sistema mostrando el control de temperatura e iluminación en acción*

## 📋 Índice

- [Descripción del Hardware](#-descripción-del-hardware)
- [Arquitectura del Software](#-arquitectura-del-software)
- [Instalación y Configuración](#-instalación-y-configuración)
- [Guía de Uso](#-guía-de-uso)
- [Documentación Técnica](#-documentación-técnica)
- [Contribuciones](#-contribuciones)
- [Licencia](#-licencia)

## 🔧 Descripción del Hardware

### Componentes Principales

| Componente | Modelo | Función | Interfaz |
|-----------|-------|----------|-----------|
| **Microcontrolador** | Arduino Uno | Unidad de procesamiento principal | - |
| **Sensor de Temperatura** | DHT22 | Monitorización de temperatura/humedad | Pin Digital 3 |
| **Sensor de Luz** | LDR | Detección de luz ambiental | Pin Analógico A0 |
| **Pantalla** | LCD 16x2 I2C | Visualización de estado | I2C (A4/A5) |
| **Matriz LED** | 8x LEDs Blancos | Sistema de iluminación artificial | Pines Digitales 6-13 |

### Salidas de Control

- **Control de Calefacción**: Pin Digital 4 (controlado por relé/MOSFET)
- **Control de Refrigeración**: Pin Digital 5 (controlado por relé/MOSFET)
- **LEDs de Estado**: Indicación visual del estado del sistema

### Arquitectura del Sistema

```
┌─────────────┐    ┌──────────────┐    ┌─────────────┐
│   Sensores  │───▶│   Arduino    │───▶│  Actuadores │
│             │    │   Control    │    │             │
│ DHT22 (T/H) │    │   Lógica     │    │ Cal/Ref    │
│ LDR (Luz)   │    │              │    │ Matriz LED │
└─────────────┘    └──────┬───────┘    └─────────────┘
                          │
                   ┌──────▼───────┐
                   │  Pantalla LCD│
                   │   (Estado)   │
                   └──────────────┘
```

## 💻 Arquitectura del Software

### Entornos de Desarrollo

El proyecto soporta dos entornos de desarrollo:

1. **PlatformIO (Producción)**
   - Ubicado en `/firmware/`
   - Utiliza estructura C++ moderna
   - Soporte completo de IDE con depuración
   - Recomendado para desarrollo

2. **Wokwi (Simulación)**
   - Ubicado en `/simulation/`
   - Formato de sketch compatible con Arduino
   - Entorno de simulación online
   - Perfecto para pruebas y prototipado

### Algoritmo de Control

El sistema implementa una **estrategia de control de doble lazo**:

#### Lazo de Control de Temperatura
```cpp
if (temperatura < 22°C) {
    activarCalefaccion();
    desactivarRefrigeracion();
} else if (temperatura > 28°C) {
    activarCalefaccion();
    activarRefrigeracion();
} else {
    // Mantener estado estable
    desactivarTodo();
}
```

#### Lazo de Control de Iluminación
```cpp
int nivelLuz = map(lecturaLDR, 0, 1023, 100, 0);
int ledsActivos = map(nivelLuz, 0, 100, 0, 8);
// Activación progresiva de LEDs según oscuridad
```

### Características del Software

- **Diseño No Bloqueante**: Usa `millis()` para temporización sin `delay()`
- **Máquina de Estados**: Gestión robusta de estados para todos los modos del sistema
- **Manejo de Errores**: Detección de fallos de sensores y modos de respaldo
- **Código Modular**: Clara separación de responsabilidades con funciones dedicadas

## 🛠️ Instalación y Configuración

### Prerrequisitos

- **PlatformIO IDE** (recomendado) o Arduino IDE
- **Git** para control de versiones
- **Cable USB** para programación Arduino

### Ensamblaje del Hardware

1. **Conectar Sensores**:
   ```
   DHT22:  VCC→5V, GND→GND, DATOS→Pin 3
   LDR:    Una pata→5V, Otra→A0 + 10kΩ→GND
   ```

2. **Conectar Pantalla**:
   ```
   LCD I2C: VCC→5V, GND→GND, SDA→A4, SCL→A5
   ```

3. **Conectar Matriz LED**:
   ```
   LEDs: Pines 6-13 → resistencias 220Ω → ánodos LED
   Cátodos LED → GND
   ```

### Instalación del Software

#### Configuración PlatformIO (Producción)

1. **Clonar Repositorio**:
   ```bash
   git clone https://github.com/your-username/smart-climate-control.git
   cd smart-climate-control
   ```

2. **Instalar Dependencias**:
   ```bash
   pio lib install
   # o instalar manualmente:
   # - Biblioteca DHT sensor
   # - LiquidCrystal I2C
   ```

3. **Subir Firmware**:
   ```bash
   pio run --target upload --environment uno
   ```

#### Configuración Wokwi (Simulación)

1. **Abrir Simulación**:
   - Visitar [Proyecto Wokwi](https://wokwi.com/projects/431119934237886465)
   - O crear nuevo proyecto e importar `/simulation/wokwi.ino`

2. **Configurar Bibliotecas**:
   - Añadir biblioteca DHT sensor
   - Añadir biblioteca LiquidCrystal I2C

3. **Ejecutar Simulación**:
   - Hacer clic en "Iniciar Simulación"
   - Ajustar valores de temperatura y luz
   - Observar respuesta del sistema

### Pruebas de Simulación

El proyecto incluye un entorno de simulación completo usando Wokwi:

1. **Pruebas Rápidas**:
   - Abrir [Proyecto Wokwi](https://wokwi.com/projects/431119934237886465)
   - Ejecutar simulación para verificar funcionalidad
   - Modificar parámetros para probar diferentes escenarios

2. **Simulación Personalizada**:
   - Usar `/simulation/wokwi.ino` como base
   - Importar en nuevo proyecto Wokwi
   - Personalizar componentes y comportamiento

3. **Características de Simulación**:
   - Control de temperatura en tiempo real
   - Simulación dinámica de iluminación
   - Emulación de pantalla LCD
   - Visualización de matriz LED

## 📖 Guía de Uso

### Operación Normal

El sistema opera de forma autónoma una vez encendido:

1. **Inicialización** (2 segundos): Calibración de sensores
2. **Fase de Monitorización**: Lectura continua de sensores
3. **Fase de Control**: Respuesta automática a condiciones
4. **Actualizaciones de Pantalla**: Refresco de información cada 5 segundos

### Información en Pantalla

#### Modo Temperatura (5s visualización)
```
Temp: 24.5 C
Estable
```

#### Modo Iluminación (5s visualización)
```
Luz: 65 %
LEDs: 5/8
```

### Indicadores de Estado

| Color LED | Estado | Significado |
|-----------|-------|---------|
| Rojo | ON | Calefacción activa |
| Azul | ON | Refrigeración activa |
| Ambos OFF | - | Temperatura estable |

## 📚 Documentación Técnica

### Especificaciones de Rendimiento

- **Rango de Temperatura**: -40°C a 80°C (límite del sensor)
- **Precisión de Control**: ±1°C
- **Tiempo de Respuesta**: <1 segundo
- **Consumo de Energía**: 230mA @ 5V (excluyendo calefacción/refrigeración)
- **Tasa de Actualización**: 200ms sondeo de sensores, 5s actualización de pantalla

### Referencia de API

#### Funciones Principales

```cpp
void controlarTemperatura()     // Lógica de control de temperatura
void controlarIluminacion()     // Lógica de control de iluminación
void mostrarPantallaTemperatura() // Visualización de temperatura
void mostrarPantallaLuz()       // Visualización de iluminación
```

#### Constantes de Configuración

```cpp
#define TEMP_MIN 22    // Umbral mínimo de temperatura
#define TEMP_MAX 28    // Umbral máximo de temperatura
#define LED_COUNT 8    // Número de LEDs controlables
#define DISPLAY_INTERVAL 5000 // Intervalo de actualización de pantalla (ms)
```

### Solución de Problemas

Para problemas comunes y soluciones, ver [Manual de Usuario](docs/user_manual.md).

## 🔬 Características Avanzadas

### Posibles Mejoras

- **Conectividad WiFi**: Monitorización remota vía interfaz web
- **Registro de Datos**: Almacenamiento en tarjeta SD para análisis histórico
- **Aplicación Móvil**: Control y notificaciones por smartphone
- **Múltiples Zonas**: Control independiente de diferentes áreas
- **Aprendizaje Automático**: Control predictivo de temperatura

### Opciones de Personalización

- **Umbrales de Temperatura**: Modificar `TEMP_MIN` y `TEMP_MAX`
- **Sensibilidad de Iluminación**: Ajustar función de mapeo LDR
- **Contenido de Pantalla**: Personalizar pantallas de información
- **Algoritmos de Control**: Implementar control PID para precisión

## 🤝 Contribuciones

¡Bienvenidas las contribuciones! Por favor, lee nuestras [Directrices de Contribución](CONTRIBUTING.md) antes de enviar pull requests.

### Configuración de Desarrollo

1. Hacer fork del repositorio
2. Crear rama de características: `git checkout -b nombre-caracteristica`
3. Realizar cambios y probar exhaustivamente
4. Enviar pull request con descripción detallada

### Estilo de Código

- Seguir convenciones Arduino/C++
- Usar nombres de variables descriptivos
- Comentar algoritmos complejos
- Probar en hardware antes de enviar

## 📄 Licencia

Este proyecto está licenciado bajo la Licencia Apache 2.0 - ver el archivo [LICENSE](LICENSE) para más detalles.

```
Copyright 2024 Grupo 10 - Máster en Ingeniería de Telecomunicación UNIR

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```

## 📞 Soporte y Contacto

- **Issues**: [GitHub Issues](https://github.com/your-username/smart-climate-control/issues)
- **Discusiones**: [GitHub Discussions](https://github.com/your-username/smart-climate-control/discussions)
- **Email**: support@your-domain.com

## 🙏 Agradecimientos

Este proyecto fue inspirado por aplicaciones modernas de IoT y sistemas de automatización del hogar. Agradecimientos especiales a las comunidades de Arduino y hardware de código abierto por proporcionar las herramientas y bibliotecas que hicieron posible este proyecto.

---

**⭐ Si encuentras útil este proyecto, ¡considera darle una estrella!** 