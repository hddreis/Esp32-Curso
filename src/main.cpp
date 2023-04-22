#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

#include "settings.hpp"
#include "functions.hpp"
#include "settingsResset.hpp"
#include "settingsRead.hpp"
#include "settingsSave.hpp"
#include "esp32_wifi.hpp"

void setup() {
  //baudrate
  Serial.begin(115200);
  // CPU freq
  setCpuFrequencyMhz(240);
  // Inicio de log para serial
  log("\nInfo: Iniciando Setup");
  // Configurar os pinos
  settingPines();
  // Inicio de SPIFFS
  if(!SPIFFS.begin(true)){
    log(F("Error: Falha na inicialização de SPIFFS"));
    while (true);
  }
  // Lê as configurações de WiFi
  settingsReadWifi();
  // Configuração WiFi
  WiFi.disconnect(true);
  delay(1000);
  // Setup do WiFi
  wifi_setup();
}

void loop() {
  yield();
  // -------------------------------------------------
  // WIFI
  // -------------------------------------------------
  if (wifi_mode == WIFI_STA){
    wifiLoop();
  }
  if (wifi_mode == WIFI_AP){
    wifiAPLoop();
  }
}