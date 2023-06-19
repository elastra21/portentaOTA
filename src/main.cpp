#include <Arduino.h>

// #if !( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) )
// 	#error For Portenta_H7 only
// #endif

// #define _PORTENTA_H7_AWS_LOGLEVEL_     1

// #define USE_WIFI_PORTENTA_H7        true

// #include <WiFi.h>
// #warning Using WiFi for Portenta_H7.

// #include <Portenta_H7_AsyncWebServer.h>


// char ssid[] = "Pez Gordo";        // your network SSID (name)
// char pass[] = "SardinaMacarena2021";         // your network password (use for WPA, or use as key for WEP), length must be 8+

// int status = WL_IDLE_STATUS;

// AsyncWebServer    server(80);

// #define LED_OFF             HIGH
// #define LED_ON              LOW

// #define BUFFER_SIZE         64
// char temp[BUFFER_SIZE];

// void handleRoot(AsyncWebServerRequest *request) {
// 	digitalWrite(LED_BUILTIN, LED_ON);

// 	snprintf(temp, BUFFER_SIZE - 1, "Hello from Async_HelloServer2 on %s\n", BOARD_NAME);
// 	request->send(200, "text/plain", temp);

// 	digitalWrite(LED_BUILTIN, LED_OFF);
// }

// void handleNotFound(AsyncWebServerRequest *request) {
// 	digitalWrite(LED_BUILTIN, LED_ON);
// 	String message = "File Not Found\n\n";

// 	message += "URI: ";
// 	//message += server.uri();
// 	message += request->url();
// 	message += "\nMethod: ";
// 	message += (request->method() == HTTP_GET) ? "GET" : "POST";
// 	message += "\nArguments: ";
// 	message += request->args();
// 	message += "\n";

// 	for (uint8_t i = 0; i < request->args(); i++) {
// 		message += " " + request->argName(i) + ": " + request->arg(i) + "\n";
// 	}

// 	request->send(404, "text/plain", message);
// 	digitalWrite(LED_BUILTIN, LED_OFF);
// }

// void printWifiStatus() {
// 	// print the SSID of the network you're attached to:
// 	Serial.print("SSID: ");
// 	Serial.println(WiFi.SSID());

// 	// print your board's IP address:
// 	IPAddress ip = WiFi.localIP();
// 	Serial.print("Local IP Address: ");
// 	Serial.println(ip);

// 	// print the received signal strength:
// 	long rssi = WiFi.RSSI();
// 	Serial.print("signal strength (RSSI):");
// 	Serial.print(rssi);
// 	Serial.println(" dBm");
// }

// void setup() {
// 	pinMode(LED_BUILTIN, OUTPUT);
// 	digitalWrite(LED_BUILTIN, LED_OFF);

// 	Serial.begin(115200);

// 	while (!Serial && millis() < 5000);

// 	delay(200);

// 	Serial.print("\nStart Async_HelloServer2 on ");
// 	Serial.print(BOARD_NAME);
// 	Serial.print(" with ");
// 	Serial.println(SHIELD_TYPE);
// 	Serial.println(PORTENTA_H7_ASYNC_TCP_VERSION);
// 	Serial.println(PORTENTA_H7_ASYNC_WEBSERVER_VERSION);

// 	///////////////////////////////////

// 	// check for the WiFi module:
// 	if (WiFi.status() == WL_NO_MODULE){
// 		Serial.println("Communication with WiFi module failed!");

// 		// don't continue
// 		while (true);
// 	}

// 	Serial.print(F("Connecting to SSID: "));
// 	Serial.println(ssid);

// 	status = WiFi.begin(ssid, pass);

// 	delay(1000);

// 	// attempt to connect to WiFi network
// 	while ( status != WL_CONNECTED){
// 		delay(500);

// 		// Connect to WPA/WPA2 network
// 		status = WiFi.status();
// 	}

// 	printWifiStatus();

// 	///////////////////////////////////

// 	server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
// 		handleRoot(request);
// 	});

// 	server.on("/inline", [](AsyncWebServerRequest * request) {
// 		request->send(200, "text/plain", "This works as well");
// 	});

// 	server.on("/gif", [](AsyncWebServerRequest * request) {
// 		static const uint8_t gif[] = {
// 			0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x10, 0x00, 0x10, 0x00, 0x80, 0x01,
// 			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x2c, 0x00, 0x00, 0x00, 0x00,
// 			0x10, 0x00, 0x10, 0x00, 0x00, 0x02, 0x19, 0x8c, 0x8f, 0xa9, 0xcb, 0x9d,
// 			0x00, 0x5f, 0x74, 0xb4, 0x56, 0xb0, 0xb0, 0xd2, 0xf2, 0x35, 0x1e, 0x4c,
// 			0x0c, 0x24, 0x5a, 0xe6, 0x89, 0xa6, 0x4d, 0x01, 0x00, 0x3b
// 		};

// 		char gif_colored[sizeof(gif)];

// 		memcpy(gif_colored, gif, sizeof(gif));

// 		// Set the background to a random set of colors
// 		gif_colored[16] = millis() % 256;
// 		gif_colored[17] = millis() % 256;
// 		gif_colored[18] = millis() % 256;

// 		request->send(200, (char *) "image/gif", gif_colored);
// 	});

// 	server.onNotFound(handleNotFound);

// 	server.begin();

// 	// Serial.print("HTTP Async_HelloServer2 started @ IP : ");
// 	Serial.print("You sucked to much dick @ IP : ");
// 	Serial.println(WiFi.localIP());
// }

// void heartBeatPrint() {
// 	static int num = 1;

// 	Serial.print(F("."));

// 	if (num == 80) {
// 		Serial.println();
// 		num = 1;
// 	}
// 	else if (num++ % 10 == 0) {
// 		Serial.print(F(" "));
// 	}
// }

// void check_status() {
// 	static unsigned long checkstatus_timeout = 0;

// #define STATUS_CHECK_INTERVAL     10000L

// 	// Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
// 	if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0)) {
// 		heartBeatPrint();
// 		checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
// 	}
// }

// void loop() {
// 	check_status();
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <Arduino_Portenta_OTA.h>
#include <WiFi.h>

char SSID[] = "Pez Gordo";        // your network SSID (name)
char PASS[] = "SardinaMacarena2021";         // your network password (use for WPA, or use as key for WEP), length must be 8+

static char const OTA_FILE_LOCATION[] = "http://192.168.100.53:4000/download";

void setup(){
  Serial.begin(115200);
  while (!Serial) {}

  if (WiFi.status() == WL_NO_SHIELD){
    Serial.println("Communication with WiFi module failed!");
    return;
  }

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED){
    Serial.print  ("Attempting to connect to '");
    Serial.print  (SSID);
    Serial.println("'");
    status = WiFi.begin(SSID, PASS);
    delay(10000);
  }
  Serial.print  ("You're connected to '");
  Serial.print  (WiFi.SSID());
  Serial.println("'");

  Arduino_Portenta_OTA_QSPI ota(QSPI_FLASH_FATFS_MBR, 2);
  Arduino_Portenta_OTA::Error ota_err = Arduino_Portenta_OTA::Error::None;

  if (!ota.isOtaCapable()){
    Serial.println("Higher version bootloader required to perform OTA.");
    Serial.println("Please update the bootloader.");
    Serial.println("File -> Examples -> STM32H747_System -> STM32H747_updateBootloader");
    return;
  }

  Serial.println("Initializing OTA storage");
  if ((ota_err = ota.begin()) != Arduino_Portenta_OTA::Error::None){
    Serial.print  ("Arduino_Portenta_OTA::begin() failed with error code ");
    Serial.println((int)ota_err);
    return;
  }

  Serial.println("Starting download to QSPI ...");
  int const ota_download = ota.download(OTA_FILE_LOCATION, false /* is_https */);
  if (ota_download <= 0){
    Serial.print  ("Arduino_Portenta_OTA_QSPI::download failed with error code ");
    Serial.println(ota_download);
    return;
  }
  Serial.print  (ota_download);
  Serial.println(" bytes stored.");


  Serial.println("Decompressing LZSS compressed file ...");
  int const ota_decompress = ota.decompress();
  if (ota_decompress < 0){
    Serial.print("Arduino_Portenta_OTA_QSPI::decompress() failed with error code");
    Serial.println(ota_decompress);
    return;
  }
  Serial.print(ota_decompress);
  Serial.println(" bytes decompressed.");


  Serial.println("Storing parameters for firmware update in bootloader accessible non-volatile memory ...");
  if ((ota_err = ota.update()) != Arduino_Portenta_OTA::Error::None){
    Serial.print  ("ota.update() failed with error code ");
    Serial.println((int)ota_err);
    return;
  }

  Serial.println("Performing a reset after which the bootloader will update the firmware.");
  Serial.println("Hint: Portenta H7 LED will blink Red-Blue-Green.");
  delay(1000); /* Make sure the serial message gets out before the reset. */
  ota.reset();
}

void loop(){
}