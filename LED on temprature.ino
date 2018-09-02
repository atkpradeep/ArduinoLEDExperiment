// Example testing sketch for ON/OF LED on DHT humidity/temperature sensors
//light-up the Red LED whenever the temperature is above 32C.
// Written by Pradeep Atkari

#include "DHT.h" //Include DHT library
#define DHTTYPE  DHT11   // we are using DHT 11 sensor

int arduionPin=2; //Arduino board input pin connect with DHT sensor signal pin
int greenLED=13; //Arduino pin D13 for green LED pin as output
int redLED=12;   //Arduino pin D12 for red LED pin as output
int normalTemp=31; //Normal temperature value set on 31 degree Celsius

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(arduionPin, DHTTYPE);

void setup() {

  Serial.begin(9600); //For debbuging perpose, we can see temperature in serial port 
  Serial.println("DHT11 test!"); //Message saying application has been started 
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  dht.begin(); //Start DHT sensor to read temperature  
}

void loop() {
  
  // To get correct value of temperature, Wait for few seconds.
  delay(2000);

  // Read temperature as Celsius (the default) or (isFahrenheit = true)
  float temperature = dht.readTemperature();
 
  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature is: "); //Print temperature reading from DHT sensor
  Serial.print(temperature);
  serial.println("");
  //If temperature is greater than normal temperature glow red led else green led.
  if(temperature > normalTemp)
  {
      digitalWrite(greenLED,LOW);
      digitalWrite(redLED,HIGH);
  }
  else
  {
      digitalWrite(redLED,LOW);
      digitalWrite(greenLED,HIGH);
  }
}
