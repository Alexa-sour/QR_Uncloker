/*-----<Libraries>-----*/
#include <Serial.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESP32QRCodeReader.h>

/*------<WIFI Setings>-----*/
// SSID
#define WIFI_SSID MyWIFI
// PASSWORD
#define WIFI_PSK MyPSK
// Connect retries
#define WIFI_CONNECT_RETRIES 10
#define WIFI_CONNECTED 1

ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);

bool connectWIFI() {
	int retries = WIFI_CONNECT_RETRIES;
	WiFi.begin(WIFI_SSID, WIFI_PSK);
	while (WiFi.status() != WL_CONNECTES) {
		delay(500);
		retries--;
		Serial.println(retries);
		if (retries <= 0) {
			break;
		}
	}
}

void setup() {
	Serial.begin(115200); // Init debug UART
	connectWIFI(); // Connect to WIFI
}

void loop() {
	
}
