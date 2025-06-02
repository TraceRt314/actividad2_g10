# Referencia de API - Sistema de Control Climático

## Descripción General

Este documento proporciona una referencia técnica detallada para el Sistema de Control Climático Inteligente, incluyendo todas las funciones, constantes y estructuras de datos disponibles para desarrolladores.

## Índice

1. [Funciones Principales](#funciones-principales)
2. [Constantes de Configuración](#constantes-de-configuración)
3. [Estructuras de Datos](#estructuras-de-datos)
4. [Ejemplos de Uso](#ejemplos-de-uso)
5. [Solución de Problemas](#solución-de-problemas)

## Funciones Principales

### Control de Temperatura

```cpp
void controlarTemperatura()
```
**Descripción**: Implementa la lógica de control de temperatura del sistema.
- Activa la calefacción cuando la temperatura está por debajo de 22°C
- Activa la refrigeración cuando la temperatura está por encima de 28°C
- Mantiene el sistema en estado estable entre estos umbrales

**Parámetros**: Ninguno
**Retorno**: void

### Control de Iluminación

```cpp
void controlarIluminacion()
```
**Descripción**: Gestiona el sistema de iluminación adaptativa.
- Lee el nivel de luz ambiental del sensor LDR
- Calcula el número de LEDs necesarios
- Activa progresivamente los LEDs según la oscuridad

**Parámetros**: Ninguno
**Retorno**: void

### Visualización

```cpp
void mostrarPantallaTemperatura()
void mostrarPantallaLuz()
```
**Descripción**: Funciones para mostrar información en la pantalla LCD.
- Alternan automáticamente cada 5 segundos
- Muestran temperatura actual y estado del sistema
- Muestran nivel de luz y LEDs activos

**Parámetros**: Ninguno
**Retorno**: void

## Constantes de Configuración

### Umbrales de Temperatura

```cpp
#define TEMP_MIN 22    // Temperatura mínima en grados Celsius
#define TEMP_MAX 28    // Temperatura máxima en grados Celsius
```

### Configuración de Iluminación

```cpp
#define LED_COUNT 8    // Número total de LEDs en el sistema
#define LDR_MIN 0      // Valor mínimo de lectura del LDR
#define LDR_MAX 1023   // Valor máximo de lectura del LDR
```

### Temporización

```cpp
#define DISPLAY_INTERVAL 5000  // Intervalo de actualización de pantalla (ms)
#define SENSOR_INTERVAL 200    // Intervalo de lectura de sensores (ms)
```

## Estructuras de Datos

### Configuración del Sistema

```cpp
struct SystemConfig {
    float tempMin;
    float tempMax;
    int ldrThreshold;
    int displayInterval;
};
```

### Estado del Sistema

```cpp
struct SystemState {
    float currentTemp;
    int currentLight;
    bool heaterActive;
    bool coolerActive;
    int activeLEDs;
};
```

## Ejemplos de Uso

### Configuración Básica

```cpp
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Inicialización de componentes
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    // Configuración inicial
    dht.begin();
    lcd.init();
    lcd.backlight();
    
    // Configurar pines
    pinMode(HEATER_PIN, OUTPUT);
    pinMode(COOLER_PIN, OUTPUT);
    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}
```

### Control de Temperatura

```cpp
void controlarTemperatura() {
    float temp = dht.readTemperature();
    
    if (temp < TEMP_MIN) {
        digitalWrite(HEATER_PIN, HIGH);
        digitalWrite(COOLER_PIN, LOW);
    } else if (temp > TEMP_MAX) {
        digitalWrite(HEATER_PIN, LOW);
        digitalWrite(COOLER_PIN, HIGH);
    } else {
        digitalWrite(HEATER_PIN, LOW);
        digitalWrite(COOLER_PIN, LOW);
    }
}
```

### Control de Iluminación

```cpp
void controlarIluminacion() {
    int luz = analogRead(LDRPIN);
    int porcentaje = map(luz, LDR_MIN, LDR_MAX, 100, 0);
    int ledsOn = map(porcentaje, 0, 100, 0, LED_COUNT);
    
    for (int i = 0; i < LED_COUNT; i++) {
        digitalWrite(ledPins[i], i < ledsOn ? HIGH : LOW);
    }
}
```

## Solución de Problemas

### Errores Comunes

1. **Lecturas de Sensor Inestables**
   - Verificar conexiones del sensor DHT22
   - Asegurar alimentación estable de 5V
   - Comprobar resistencia pull-up en pin de datos

2. **Pantalla LCD No Funciona**
   - Verificar dirección I2C (normalmente 0x27)
   - Comprobar conexiones SDA y SCL
   - Asegurar alimentación correcta

3. **LEDs No Responden**
   - Verificar conexiones de los LEDs
   - Comprobar resistencias limitadoras
   - Verificar pines de salida digital

### Diagnóstico

```cpp
void diagnosticarSistema() {
    // Verificar sensor de temperatura
    float temp = dht.readTemperature();
    if (isnan(temp)) {
        Serial.println("Error en sensor de temperatura");
    }
    
    // Verificar sensor de luz
    int luz = analogRead(LDRPIN);
    if (luz < 0 || luz > 1023) {
        Serial.println("Error en sensor de luz");
    }
    
    // Verificar pantalla LCD
    lcd.begin(16, 2);
    lcd.print("Test LCD");
    delay(1000);
    lcd.clear();
}
```

## Mejores Prácticas

1. **Manejo de Errores**
   - Implementar verificación de valores de sensor
   - Usar valores por defecto seguros
   - Registrar errores para diagnóstico

2. **Optimización de Energía**
   - Minimizar uso de `delay()`
   - Implementar modos de bajo consumo
   - Optimizar intervalos de lectura

3. **Mantenimiento**
   - Limpiar sensores regularmente
   - Verificar conexiones periódicamente
   - Actualizar firmware cuando sea necesario

## Referencias

- [Documentación DHT22](https://www.mouser.com/datasheet/2/758/DHT22-Technical-Data-Sheet-Translated-Version-1143054.pdf)
- [Documentación LCD I2C](https://www.waveshare.com/wiki/LCD1602_Module)
- [Guía de Arduino](https://www.arduino.cc/reference/en/) 