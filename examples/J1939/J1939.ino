#include <DFL168A.h>
DFL168A myDFL168A(&Serial1, J1939_PROTOCOL, 1000,250000, 9600,500); 
bool Vehicle_OK;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Vehicle_OK=myDFL168A.begin();
  if (Vehicle_OK) digitalWrite(13,HIGH);  else Serial.println("Vehicle is not ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
  String Vin;
  float VehicleSpeed;
  float BarometricPressure;
  int temperature;  
  if (Vehicle_OK)
  {
    if (myDFL168A.J1939.getVIN(Vin))
    {
      Serial.print("Vehicle Identification Number: ");   
      Serial.println(Vin);
    }
    else
    {
      Serial.println("Fail to get VIN");
    }

    if (myDFL168A.J1939.PGN65269.refresh())
    {
      Serial.println("Success-PGN65269 Refresh");
      if (myDFL168A.J1939.PGN65269.getBarometricPressure(BarometricPressure))
      {
        Serial.print("Barometrical Pressure: ");   
        Serial.print(BarometricPressure);  Serial.println(" kPa"); 
      }
      else
      {
        Serial.println("Fail to get Barometrical Pressure");
      } 

      if (myDFL168A.J1939.PGN65269.getAmbientTemp(temperature))
      {
        Serial.print("Ambient Air Temperature: ");   
        Serial.print(temperature);  Serial.println("Celcus Degree"); 
      }
      else
      {
        Serial.println("Fail to get Ambient Air Temperature");
      } 
      
    }
    else
    {
      Serial.println("Fail to Refresh in PGN65269");
    }
    
    if (myDFL168A.J1939.PGN65265.refresh())
    {
      Serial.println("Success-PGN65265 Refresh");
      if (myDFL168A.J1939.PGN65265.getWheelBasedVehicleSpeed(VehicleSpeed))
      {
        Serial.print("Vehicle Speed: ");   
        Serial.print(VehicleSpeed);  Serial.println(" km/h"); 
      }
      else
      {
        Serial.println("Fail to get vehicle speed");
      } 
   }
   else
   {
      Serial.println("Fail to Refresh in PGN65265");
   }
 
 
   
 
   if (myDFL168A.J1939.clearDTC())
   {
     Serial.println("Success clr dtc");   
   
   }
   else
   {
     Serial.println("Fail to CLR dtc");
   }
   
 }
 delay(3000);
}
