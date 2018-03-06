#include <DFL168A.h>
DFL168A myDFL168A(&Serial1, AUTO_PROTOCOL, 1000,250000, 9600,500); 
bool Vehicle_OK;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Vehicle_OK=myDFL168A.begin();
  if (Vehicle_OK) digitalWrite(13,HIGH); else Serial.println("Vehicle is not ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
  String Vin;
  int EngineSpeed;  
  if (Vehicle_OK)
  {
    if (myDFL168A.ISO15765.getVIN(Vin))
    {
      Serial.print("Vehicle Identification Number: ");   
      Serial.println(Vin);
    }
    else
    {
      Serial.println("Fail to get VIN");
    }
 
    if (myDFL168A.ISO15765.getEngineSpeed(EngineSpeed))
    {
      Serial.print("Engine Speed: ");   
      Serial.print(EngineSpeed);  Serial.println(" rpm"); 
   
    }
    else
    {
      Serial.println("Fail to get Engine speed");
    }
   
 }
 delay(3000);
}
