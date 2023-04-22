
#include "ledBlink.hpp"

// -----------------------------------------------------------------
// Geração de um log na porta Serial
// -----------------------------------------------------------------
void log(String s){
    Serial.println(s);
}

// -----------------------------------------------------------------
// Definir a Plataforma
// -----------------------------------------------------------------
String platform(){
// Opção da plataforma de hardware
#ifdef esp32doit_devkit_v1
    #define esp32doit-devkit-v1
#endif
    return "ESP32";
}

IPAddress CharToIP(const char *str){
    sscanf(str, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[3]);
    return IPAddress(ip[0],ip[1],ip[2],ip[3]);
}

//------------------------------------------------------------------
// Retorna IPAddress em formato "n.n.n.n" de IP a String
//------------------------------------------------------------------
String ipStr(const IPAddress &ip){
    String sFn = "";
    for (byte bFn = 0; bFn < 3; bFn++)
    {
        sFn += String(((ip >> 8 * bFn)) & 0xFF) + ".";
    }
    sFn += String((ip >> 8 * 3) & 0xFF);
    return sFn;
}

// -----------------------------------------------------------------
// De Hex a String
// -----------------------------------------------------------------
String hexStr(const unsigned long &h, const byte &l = 8){
    String s;
    s = String(h, HEX);
    s.toUpperCase();
    s = ("00000000" + s).substring(s.length() + 8 - l);
    return s;
}
//---------------------------------------------------------
// Criar um ID unico desde a direção MAC
//---------------------------------------------------------
String idUnique(){
    // Retorna os ultimos 4 Bytes do MAC rotados
    char idunique[15];
    uint64_t chipid = ESP.getEfuseMac();
    uint16_t chip = (uint16_t)(chipid >> 32);
    snprintf(idunique, 15, "%04X", chip);
    return idunique;
}

String deviceID(){
    return String(platform()) + hexStr(ESP.getEfuseMac()) + String(idUnique());
}

// ------------------------------------------------------------------
// Configurar os Pinos de Saida
// ------------------------------------------------------------------
void settingPines(){
    pinMode(WIFILED, OUTPUT);
    pinMode(MQTTLED, OUTPUT);
    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);
    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY2, LOW);
    digitalWrite(MQTTLED, LOW);
    digitalWrite(WIFILED, LOW);
}