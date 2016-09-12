//Code for particle.photon
// This #include statement was automatically added by the Particle IDE.
#include "MQTT/MQTT.h"

Servo servoRight;
Servo servoLeft;

//setup Wifi
#define SSID        "NETLIFE-MARIA"
#define PASSWORD    "password"
//#define SSID        "LabProto"
//#define PASSWORD    "password"

//setup mqtt
#define Broker "m12.cloudmqtt.com"
#define Port 15886
#define UserName "celula"
#define Password "password"

//topic
#define TOPWIN "win"
#define TOPLOSE "lose"

void callback(char* topic, byte* payload, unsigned int length);

/**
 * if want to use IP address,
 * byte server[] = { XXX,XXX,XXX,XXX };
 * MQTT client(server, 1883, callback);
 * want to use domain name,
 * MQTT client("www.sample.com", 1883, callback);
 **/
 // This #include statement was automatically added by the Particle IDE.

MQTT client(Broker, Port, callback);

void callback(char* topic, byte* payload, unsigned int length) {
    char p[length + 1];
    memcpy(p, payload, length);
    p[length] = NULL;
    String message(p);
    String topic2=String(topic);
    
    if (topic2.equals(TOPWIN))    
        if (message.equals("on")){
            servoRight.write(30);
            servoLeft.write(105);
        }
            
    if (topic2.equals(TOPLOSE)){  
        if (message.equals("on")){
            servoRight.write(90);
            servoLeft.write(45);
        }
    }
}

void setup() {
    Serial.begin(9600);
    
    servoRight.attach(A5);
    servoLeft.attach(A4);
    
    WiFi.setCredentials(SSID, PASSWORD);
    WiFi.connect();
    Serial.println(WiFi.localIP());
    // connect to the server
    client.connect("arduino",UserName,Password);
    // publish/subscribe
    if (client.isConnected()) {
        Serial.println("Connected");
        client.subscribe(TOPWIN);
        client.subscribe(TOPLOSE);
        client.publish("Devices","Arduino Conectado");
    }
}

void loop() {
    if (client.isConnected()){
        client.loop();
    }
}
