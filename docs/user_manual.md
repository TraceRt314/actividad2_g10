# Manual de Usuario - Sistema de Control Climático Inteligente

## Introducción

Este manual proporciona instrucciones detalladas para la instalación, configuración y uso del Sistema de Control Climático Inteligente. El sistema está diseñado para mantener automáticamente condiciones óptimas de temperatura e iluminación en su entorno.

## Índice

1. [Requisitos del Sistema](#requisitos-del-sistema)
2. [Instalación](#instalación)
3. [Configuración Inicial](#configuración-inicial)
4. [Uso Diario](#uso-diario)
5. [Mantenimiento](#mantenimiento)
6. [Solución de Problemas](#solución-de-problemas)

## Requisitos del Sistema

### Hardware Necesario

- Arduino Uno o compatible
- Sensor de temperatura/humedad DHT22
- Sensor de luz LDR
- Pantalla LCD 16x2 con interfaz I2C
- 8 LEDs blancos
- Resistencias de 220Ω (8 unidades)
- Resistencias de 10kΩ (2 unidades)
- Cables de conexión
- Fuente de alimentación 5V/1A

### Software Requerido

- Arduino IDE o PlatformIO
- Bibliotecas:
  - DHT sensor library
  - LiquidCrystal I2C

## Instalación

### Montaje Físico

1. **Conectar el Sensor DHT22**
   - VCC → 5V
   - GND → GND
   - DATOS → Pin 3
   - Añadir resistencia pull-up de 10kΩ entre VCC y DATOS

2. **Conectar el Sensor LDR**
   - Un extremo → 5V
   - Otro extremo → Pin A0
   - Resistencia de 10kΩ entre A0 y GND

3. **Conectar la Pantalla LCD**
   - VCC → 5V
   - GND → GND
   - SDA → A4
   - SCL → A5

4. **Conectar la Matriz LED**
   - Pines 6-13 → Resistencias 220Ω → LEDs
   - Cátodos de LEDs → GND

### Instalación del Software

1. **Preparar el Entorno**
   ```bash
   # Clonar el repositorio
   git clone https://github.com/your-username/smart-climate-control.git
   cd smart-climate-control
   ```

2. **Instalar Dependencias**
   ```bash
   # Usando PlatformIO
   pio lib install
   ```

3. **Subir el Código**
   ```bash
   # Compilar y subir
   pio run --target upload
   ```

## Configuración Inicial

### Ajustes Básicos

1. **Umbrales de Temperatura**
   - Temperatura mínima: 22°C
   - Temperatura máxima: 28°C
   - Estos valores pueden ajustarse en el código

2. **Configuración de Iluminación**
   - Sensibilidad del LDR: Ajustable
   - Número de LEDs: 8
   - Modo de activación: Progresivo

### Calibración

1. **Sensor de Temperatura**
   - Dejar el sensor a temperatura ambiente
   - Verificar lecturas con un termómetro de referencia
   - Ajustar offset si es necesario

2. **Sensor de Luz**
   - Calibrar en condiciones de luz normal
   - Ajustar umbrales según necesidades

## Uso Diario

### Operación Normal

1. **Encendido**
   - Conectar la alimentación
   - Esperar 2 segundos para inicialización
   - El sistema comenzará a operar automáticamente

2. **Monitorización**
   - La pantalla LCD mostrará:
     - Temperatura actual
     - Estado del sistema
     - Nivel de luz
     - LEDs activos

3. **Control Automático**
   - El sistema mantendrá la temperatura entre 22°C y 28°C
   - La iluminación se ajustará según la luz ambiental
   - No se requiere intervención manual

### Modos de Operación

1. **Modo Normal**
   - Control automático de temperatura
   - Control automático de iluminación
   - Actualización de pantalla cada 5 segundos

2. **Modo de Diagnóstico**
   - Accesible durante la inicialización
   - Muestra valores de sensores en bruto
   - Útil para solución de problemas

## Mantenimiento

### Tareas Periódicas

1. **Limpieza**
   - Limpiar sensores mensualmente
   - Verificar conexiones
   - Inspeccionar LEDs

2. **Verificación**
   - Comprobar lecturas de sensores
   - Verificar respuesta del sistema
   - Revisar consumo de energía

3. **Actualizaciones**
   - Mantener el firmware actualizado
   - Revisar nuevas versiones
   - Seguir las notas de versión

### Almacenamiento

1. **Corto Plazo**
   - Desconectar la alimentación
   - Cubrir los sensores
   - Proteger de polvo

2. **Largo Plazo**
   - Guardar en lugar seco
   - Proteger de temperaturas extremas
   - Mantener en embalaje original

## Solución de Problemas

### Problemas Comunes

1. **Lecturas de Temperatura Incorrectas**
   - Verificar conexiones del DHT22
   - Comprobar resistencia pull-up
   - Limpiar el sensor

2. **Pantalla LCD No Funciona**
   - Verificar dirección I2C
   - Comprobar conexiones SDA/SCL
   - Verificar alimentación

3. **LEDs No Responden**
   - Verificar conexiones
   - Comprobar resistencias
   - Medir voltaje en LEDs

### Diagnóstico

1. **Modo de Diagnóstico**
   - Mantener presionado botón durante inicio
   - Observar valores de sensores
   - Verificar respuesta del sistema

2. **Registro de Errores**
   - Revisar mensajes de error
   - Documentar problemas
   - Seguir procedimientos de solución

### Contacto y Soporte

Para asistencia técnica:
- Email: support@your-domain.com
- GitHub: [Issues](https://github.com/your-username/smart-climate-control/issues)
- Foro: [Discusiones](https://github.com/your-username/smart-climate-control/discussions)

## Apéndices

### A. Especificaciones Técnicas

- **Microcontrolador**: Arduino Uno
- **Sensores**: DHT22, LDR
- **Pantalla**: LCD 16x2 I2C
- **Iluminación**: 8 LEDs blancos
- **Alimentación**: 5V DC, 1A

### B. Diagramas

1. **Esquema de Conexiones**
   ```
   [Diagrama de conexiones]
   ```

2. **Flujo de Control**
   ```
   [Diagrama de flujo]
   ```

### C. Glosario

- **DHT22**: Sensor de temperatura y humedad
- **LDR**: Light Dependent Resistor (Resistor dependiente de la luz)
- **I2C**: Inter-Integrated Circuit (Protocolo de comunicación)
- **LCD**: Liquid Crystal Display (Pantalla de cristal líquido)

### D. Referencias

- [Documentación Arduino](https://www.arduino.cc/reference/en/)
- [Manual DHT22](https://www.mouser.com/datasheet/2/758/DHT22-Technical-Data-Sheet-Translated-Version-1143054.pdf)
- [Guía LCD I2C](https://www.waveshare.com/wiki/LCD1602_Module) 