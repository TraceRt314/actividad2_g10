# Esquema del Hardware

## Descripción General del Circuito

Este proyecto implementa un sistema inteligente de control climático e iluminación utilizando un Arduino Uno como controlador principal.

## Lista de Componentes

### Microcontrolador
- **Arduino Uno** - Unidad de procesamiento principal

### Sensores
- **DHT22** - Sensor digital de temperatura y humedad
  - Voltaje de operación: 3.3V a 5V
  - Rango de temperatura: -40°C a 80°C
  - Rango de humedad: 0% a 100% HR
  - Precisión: ±0.5°C para temperatura, ±1% HR para humedad
  - Conectado al pin 3

- **LDR (Resistor Dependiente de Luz)** - Fotorresistor para detección de luz ambiental
  - Conectado al pin analógico A0
  - Forma divisor de tensión con resistencia pull-up

### Actuadores
- **Elemento Calefactor** - Control de temperatura (calefacción)
  - Conectado al pin digital 4
  - Controlado mediante relé o MOSFET

- **Elemento Refrigerador** - Control de temperatura (refrigeración)
  - Conectado al pin digital 5
  - Controlado mediante relé o MOSFET

### Pantalla
- **LCD 16x2 con adaptador I2C**
  - Dirección: 0x27
  - Conectado mediante I2C (SDA: A4, SCL: A5)
  - Muestra temperatura/humedad y estado de iluminación

### Sistema de Iluminación
- **8x LEDs Blancos** - Matriz de iluminación artificial
  - Conectados a los pines digitales 6-13
  - Cada LED con resistencia limitadora de corriente de 220Ω
  - Proporciona compensación automática de iluminación

### Indicadores de Estado
- **LED Rojo** - Indicador de estado del calefactor (pin 4)
- **LED Azul** - Indicador de estado del refrigerador (pin 5)

## Configuración de Pines

| Componente | Pin | Tipo | Descripción |
|-----------|-----|------|-------------|
| DHT22 | 3 | Digital | Sensor de temperatura/humedad |
| LDR | A0 | Analógico | Sensor de nivel de luz |
| Calefactor | 4 | Digital | Control del elemento calefactor |
| Refrigerador | 5 | Digital | Control del elemento refrigerador |
| Matriz LED | 6-13 | Digital | Iluminación artificial (8 LEDs) |
| LCD SDA | A4 | I2C | Línea de datos de la pantalla |
| LCD SCL | A5 | I2C | Línea de reloj de la pantalla |

## Requisitos de Energía

- **Voltaje de Operación**: 5V DC
- **Consumo de Corriente**: 
  - Arduino Uno: ~50mA
  - DHT22: ~1mA
  - LCD: ~20mA
  - LEDs (8x): ~160mA (20mA cada uno)
  - Total: ~230mA (excluyendo calefactor/refrigerador)

## Protección del Circuito

- Resistencias limitadoras de corriente (220Ω) para todos los LEDs
- Conexión a tierra adecuada para todos los componentes
- Se recomiendan condensadores de desacoplo para operación estable 