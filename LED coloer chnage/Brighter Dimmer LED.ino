/*Interface a potentiometer to one of the Analog input pins of Arduino.
  Write a simple code to read the value from Analog input pin and log it to serial output.
  Turn the knob of potentiometer and observe the values logged in Serial Monitor.*/

  int ledPin = 9;     //Digital pin no 9 to led connected  
  int portPin= A0;   //Analog pin no A0 to get input from potentiometer 
  int readValue;    //Read analog value from potentiometer (0 to 1023)
  int writeValue;   //Write value on LED to brighterand dimmer (0-255)

  void setup()
  {
      pinMode(ledPin, OUTPUT);  //Output pin to set voltage
      pinMode(portPin,INPUT);   //Input pin to read value from potentiometer
      Serial.begin(9600);       //For debuggin purpose. you can see value in serial window
  }

  void loop()
  {
      readValue=analogRead(portPin);    //Read input value from potentiometer (0-1023)
      writeValue=(255./1023)*readValue; //Calculate writevalue for LED voltage (0-5)
      analogWrite(ledPin,writeValue);   //Send voltage to LED for brighter or dimmer smoothly 
      Serial.print("You are at value: "); //For debuggin, you can see actual write value on LED
      Serial.println(writeValue);
  }