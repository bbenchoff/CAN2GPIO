//CAN 2 GPIO
//Uses the Adafruit Feather M4 CAN as a GPIO expander
//Functions on id 4200 to 4207; sending 0x00 makes a pin go low
//and sending 0xFF makes a pin go high.
//
//only eight bits are implemented
//Arduino pins 13,14,15,16,17,18,19,25,24
//are 0 through 7.
//
// Builtin LED (pin13) is available at address 4208
//

#include <CAN.h>

int pin13 = 13;
int pin14 = 14;
int pin15 = 15;
int pin16 = 16;
int pin17 = 17;
int pin18 = 18;
int pin19 = 19;
int pin25 = 25;
int pin24 = 24;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("CAN Receiver to GPIO / responds on address 0x420x\n0x00 makes a pin go low, 0xFF makes a pin go high");

  pinMode(PIN_CAN_STANDBY, OUTPUT);
  digitalWrite(PIN_CAN_STANDBY, false); // turn off STANDBY
  pinMode(PIN_CAN_BOOSTEN, OUTPUT);
  digitalWrite(PIN_CAN_BOOSTEN, true); // turn on booster

  //turn on ouput pins
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  pinMode(pin15, OUTPUT);
  pinMode(pin16, OUTPUT);
  pinMode(pin17, OUTPUT);
  pinMode(pin18, OUTPUT);
  pinMode(pin19, OUTPUT);
  pinMode(pin25, OUTPUT);
  pinMode(pin24, OUTPUT);
  
  // start the CAN bus at 500 kbps
  if (!CAN.begin(500000)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = CAN.parsePacket();
  int dataBit;

  if (packetSize) {
    if(CAN.packetId() == 4200)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin14, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin14, HIGH);
    }
    if(CAN.packetId() == 4201)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin15, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin15, HIGH);
    }
    if(CAN.packetId() == 4202)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin16, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin16, HIGH);
    }
    if(CAN.packetId() == 4203)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin17, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin17, HIGH);
    }
    if(CAN.packetId() == 4204)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin18, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin18, HIGH);
    }
    if(CAN.packetId() == 4205)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin19, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin19, HIGH);
    }
    if(CAN.packetId() == 4206)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin25, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin25, HIGH);
    }
    if(CAN.packetId() == 4207)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin24, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin24, HIGH);
    }
    if(CAN.packetId() == 4208)
    {
      dataBit = CAN.read();
      if(dataBit == 0x00)
        digitalWrite(pin13, LOW);
      else if(dataBit = 0xFF)
        digitalWrite(pin13, HIGH);
    }
  }
}