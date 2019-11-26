/**
 * @author Dariusz Rumiński 
 * 
 */ 
#include <ESP8266mDNS.h>
#include "MemoryFree.h"
#include "CORS_CONST.h"
#include "MexicanWave.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>


#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO 
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)


const char* ssid = "ssid"; 
const char* password = "yourpasswordToAP";


// led for esp
const int led = D4;

// async web server listening on 80
AsyncWebServer server(80);

// pin given by a user via GET method
int pin = D0;

// voltage given by a user via GET method
int voltage = 0;

// request counter
unsigned int reqCounter = 0;

// pins pointing to particular fingers
unsigned char rightHandPins[] = {D1, D2, D5, D6, D7};

void setupWifi() {
    pinMode(led, OUTPUT);

    Serial.begin(115200);
    delay(2000);
    Serial.println("Booting...---");
    WiFi.mode(WIFI_STA);
    //WiFi.setOutputPower(1);
    
    int teltje = 0;
    pinMode(led, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
    while (WiFi.status()!= WL_CONNECTED) {
      delay(20);
      digitalWrite(led, HIGH);   
      delay(300);
      digitalWrite(led, LOW);   
      if (teltje==0) {
        WiFi.begin(ssid, password); // only do WiFi.begin if not already connected
      }
      teltje++;
      Serial.print(".");
      if (teltje>20) {
        Serial.println("Connection Failed! Rebooting...");
        delay(500);
        ESP.restart();
      }
    }
    Serial.println("Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(led, HIGH);   

  }


void setup(void){

 //oldWiFiStuff(); 
  setupWifi();


  startServer();

  // sets esp pins as output
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  //MexicanWave wave(rightHandPins);
  //wave.start();
  
}


void runCoinMotor(int &pinVar, int &powerVar) {
  switch(pinVar) {
    case 1:
      pin = D1;
      break;
    case 2:
      pin = D2;
      break;
    case 5:
      pin = D5;
      break;
    case 6:
      pin = D6;
      break;
    case 4:
      pin = D4;
      break;
    case 7:
      pin = D7;
      break;
    default: 
      return;
  }

  if (powerVar == 0) {
    analogWrite(pin, LOW);  
  } else {
    analogWrite(pin, powerVar);
  }
  
}



const char* INFO = "Coin motor ON! D";
const char* INFO2 = "To many parameters! I only need 'pin' and 'voltage'";
const char* INFO3 = "Not enough parameters! I only need 'pin' and 'voltage'";

// for tracking memory leakage stuff
uint32_t memcurr = 0;
uint32_t memlast = 0;
uint32_t counter = 0;


void startServer() {

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      //digitalWrite(led, 0);
      request->send(200, TEXT_PLAIN, INFO_FOR_D);
      //digitalWrite(led, 1);

  });

  server.on("/motor", [] (AsyncWebServerRequest *request) {

    // String freeMem = String(freemem());
    // Serial.println(freeMem);
    //memcurr = ESP.getFreeHeap();
    //Serial.printf("FREEHeap: %d; DIFF %d; request No: %d\n", memcurr, memcurr - memlast, counter);
    //memlast = memcurr;


	// handling parameters
    String pinStr = request->getParam(PARAM_PIN)->value();
    String volStr = request->getParam(PARAM_VOLTAGE)->value();

        
    int pin = pinStr.toInt();
    int voltage = volStr.toInt();
    //Serial.printf("Pin: %d; Voltage: %d\t", pin, voltage);
    

	// here we start a fun       
    runCoinMotor(pin, voltage);
    request->send(200, TEXT_PLAIN, OK_);
    counter++;

	// setting headers CORS 
	DefaultHeaders::Instance().addHeader(ACCESS_CONTROL_ALLOW_ORIGIN, ASTERIX);
	DefaultHeaders::Instance().addHeader(ACCESS_CONTROL_ALLOW_METHODS, METHODS);
	DefaultHeaders::Instance().addHeader(ACCESS_CONTROL_ALLOW_HEADERS, HEADERS);


	server.begin();
	//server.setNoDelay(true);
	Serial.println("async HTTP server started");

  
}

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

// Main loop
void loop(void){
}





