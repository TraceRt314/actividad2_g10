#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 3
#define DHTTYPE DHT22
#define LDRPIN A0

#define HEATER_PIN 4
#define COOLER_PIN 5

// LEDs de iluminación artificial
const int ledPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
const int numLEDs = 8;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long previousMillis = 0;
const long interval = 5000;
bool mostrarTemperatura = true;

void setup() {
  pinMode(HEATER_PIN, OUTPUT);
  pinMode(COOLER_PIN, OUTPUT);
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  // Actualizar mediciones y actuar en todo momento
  controlarTemperatura();
  controlarIluminacion();

  // Cambio automático entre pantallas
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    mostrarTemperatura = !mostrarTemperatura;
    lcd.clear();
  }

  if (mostrarTemperatura) {
    mostrarPantallaTemperatura();
  } else {
    mostrarPantallaLuz();
  }
}

void controlarTemperatura() {
  float temp = dht.readTemperature();

  if (temp < 22) {
    digitalWrite(HEATER_PIN, HIGH);
    digitalWrite(COOLER_PIN, LOW);
  } else if (temp > 28) {
    digitalWrite(HEATER_PIN, LOW);
    digitalWrite(COOLER_PIN, HIGH);
  } else {
    digitalWrite(HEATER_PIN, LOW);
    digitalWrite(COOLER_PIN, LOW);
  }
}

void controlarIluminacion() {
  int luz = analogRead(LDRPIN);
  int porcentaje = map(luz, 0, 1023, 100, 0); // 0 = mucha luz, 100 = oscuridad
  int ledsOn = map(porcentaje, 0, 100, 0, numLEDs);

  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], i < ledsOn ? HIGH : LOW);
  }
}

void mostrarPantallaTemperatura() {
  float temp = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  if (temp < 22) {
    lcd.print("Calentando...");
  } else if (temp > 28) {
    lcd.print("Enfriando... ");
  } else {
    lcd.print("Estable       ");
  }
}

void mostrarPantallaLuz() {
  int luz = analogRead(LDRPIN);
  int porcentaje = map(luz, 0, 1023, 100, 0);
  int ledsOn = map(porcentaje, 0, 100, 0, numLEDs);

  lcd.setCursor(0, 0);
  lcd.print("Luz: ");
  lcd.print(porcentaje);
  lcd.print(" %");

  lcd.setCursor(0, 1);
  lcd.print("LEDs: ");
  lcd.print(ledsOn);
  lcd.print("/8       ");
} 