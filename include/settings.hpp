// -------------------------------------------------------
// Definiçoes
// -------------------------------------------------------
#define RELAY1  27       //GPI027 para saida de rele 1
#define RELAY2  26       //GPI026 para saida de rele 2
#define WIFILED 2
#define MQTTLED 13
// -------------------------------------------------------
// Versão do Hardhare
// -------------------------------------------------------
#define HW "ADMINESP32 v1 0000000"
// -------------------------------------------------------
// Zona Configuraçao Geral
// -------------------------------------------------------
char id[30];
int bootCount;
// -------------------------------------------------------
// Zona WIFI
// -------------------------------------------------------
bool wifi_staticIP;
char wifi_ssid[30];
char wifi_passw[30];
char wifi_ip_static[15];
char wifi_gateway[15];
char wifi_subnet[15];
char wifi_primaryDNS[15];
char wifi_secondaryDNS[15];
// -------------------------------------------------------
// Zona AP
// -------------------------------------------------------
bool ap_accessPoint;
char ap_nameap[31];
char ap_passwordap[63];
int ap_canalap;
int ap_hiddenap;
int ap_connetap;

uint8_t ip[4];