#include "Arduino.h"
#include "DFL168A.h"
J1708Class::J1708Class() {
  Pareant=NULL;
}

J1708Class::J1708Class(class DFL168A * Pareant) {
  this->Pareant=Pareant;
}

bool J1708Class::getAirPressure(int &AirPressure)   //0.0 to 1055 kPa,4.14 kPa/bit, PID=7
{
  bool retrnV;
  char cmd[]="07";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat, /*float scale*/4.14);
  AirPressure=(int)(tempFloat+0.5);
  return retrnV;
}
bool J1708Class::getEngineOilPressure(int &EngineOilPressure)  //0.0 to 1020 kPa, 4kpa/bit, PID=19
{
  bool retrnV;
  char cmd[]="13";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat, /*float scale*/4.00);
  EngineOilPressure=(int)(tempFloat+0.5);
  return retrnV;
}
bool J1708Class::getEngineCoolantPressure(int &EngineCoolantPressure)  //0.0 to 510 kPa ,  2 kPa/bit,pid=20
{
  bool retrnV;
  char cmd[]="14";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat, /*float scale*/2.00);
  EngineCoolantPressure=(int)(tempFloat+0.5);
  return retrnV;
}
bool J1708Class::getFuelLevel1(float &FuelLevel1)  //Primary fuel, 0.0 to 127.5% 0.5%/bit pid=96
{
  bool retrnV;
  char cmd[]="60";  
  retrnV=getPhysical_float(cmd,FuelLevel1,  /*float scale*/0.5);  
  return retrnV;
}
bool J1708Class::getFuelLevel2(float &FuelLevel2)   //righ side fuel, 0.0 to 127.5% 0.5%/bit pid=38
{
  bool retrnV;
  char cmd[]="26";  
  retrnV=getPhysical_float(cmd,FuelLevel2, /*float scale*/0.5);  
  return retrnV;
}
bool J1708Class::getBarometricPressure(float &Pressure)  //0.0 to 153.0 kPa, 0.6 kPa/bit, PID=48
{
  bool retrnV;
  char cmd[]="30";  
  retrnV=getPhysical_float(cmd,Pressure,  /*float scale*/0.6);  
  return retrnV;
}
bool J1708Class::getEngineThrottlePos(float &EngineThrottlePos) //0.0 to 102.0%, 0.4%/bit, pid=51
{
  bool retrnV;
  char cmd[]="33";  
  retrnV=getPhysical_float(cmd,EngineThrottlePos, /*float scale*/0.4);  
  return retrnV;
}
bool J1708Class::getWasherFluidLevel(float &WasherFluidLevel)  //0.0 to 127.5%, 0.5%/bit, pid=80
{
  bool retrnV;
  char cmd[]="50";  
  retrnV=getPhysical_float(cmd,WasherFluidLevel, /*float scale*/0.5);  
  return retrnV;
}
bool J1708Class::getVehicleSpeed(float &VehicleSpeed)  //0.0 to 205.2 km/h , 0.805 km/h/bit, pid=84
{
  bool retrnV;
  char cmd[]="54";  
  retrnV=getPhysical_float(cmd,VehicleSpeed,  /*float scale*/0.805);  
  return retrnV;
}
bool J1708Class::getAccelPedalPosi1(float &AccelPedalPosi1)  //0.0 to 102.0%,0.4%/bit, pid=91, If only one is available, please use this one
{
  bool retrnV;
  char cmd[]="5B";  
  retrnV=getPhysical_float(cmd,AccelPedalPosi1,  /*float scale*/0.4);  
  return retrnV;
}
bool J1708Class::getAccelPedalPosi2(float &AccelPedalPosi2)  //0.0 to 102.0%,0.4%/bit, pid=29
{
  bool retrnV;
  char cmd[]="1D";  
  retrnV=getPhysical_float(cmd,AccelPedalPosi2,  /*float scale*/0.4);  
  return retrnV;
}
bool J1708Class::getAccelPedalPosi3(float &AccelPedalPosi3)  //0.0 to 102.0%,0.4%/bit, pid=28
{
  bool retrnV;
  char cmd[]="1C";  
  retrnV=getPhysical_float(cmd,AccelPedalPosi3,/*float scale*/0.4);  
  return retrnV;
}
bool J1708Class::getEngineLoad(float &Percent)//0.0 to 127.5%, 0.5%/bit, pid=92
{
  bool retrnV;
  char cmd[]="5C";  
  retrnV=getPhysical_float(cmd,Percent,/*float scale*/0.5);  
  return retrnV;
}
bool J1708Class::getEngineOilLevel(float &EngineOilLevel)  //0.0 to 127.5%.0.5%/BIT PID=98
{
  bool retrnV;
  char cmd[]="62";  
  retrnV=getPhysical_float(cmd,EngineOilLevel,  /*float scale*/0.5);  
  return retrnV;
}
bool J1708Class::getCoolantTemperature(int &temp)  //We still use °C even though definition: 0.0 to 255.0 °F, 1.0 °F, PID=110
{
  bool retrnV;
  char cmd[]="6E";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat,  /*float scale*/1.00);
  tempFloat=(tempFloat-32)/1.8;
  if (tempFloat>=0) temp=(int)(tempFloat+0.5); else temp=(int)(tempFloat-0.5);
  return retrnV;
}
bool J1708Class::getEngineCoolantLevel(float &EngineCoolantLevel) //0.0 to 127.5%, 0.5%/bit, PID=111
{
  bool retrnV;
  char cmd[]="6F";  
  retrnV=getPhysical_float(cmd,EngineCoolantLevel, /*float scale*/0.5);  
  return retrnV;
}
bool J1708Class::getTransmissionOilLevel(float &Percent)//0.0 to 127.5%, 0.5%/bit, pid=124
{
  bool retrnV;
  char cmd[]="7C";  
  retrnV=getPhysical_float(cmd,Percent,  /*float scale*/0.5);  
  return retrnV;
}
bool J1708Class::getTransmissionOilLevelHighLow(float &HighLow) //–60.6 to 60.1 L,0.473L/bit,PID=125
{  
  bool retrnV;
  char cmd[]="7D";  
  retrnV=getPhysical_float(cmd,HighLow,  /*float scale*/0.473,true);    
  return retrnV;
}
bool J1708Class::getTransmissionOilPressure(float &Pressure) //0.0 to 3516 kPa, 13.8 kPa/bit, pid=127
{
  bool retrnV;
  char cmd[]="7F";  
  retrnV=getPhysical_float(cmd,Pressure,  /*float scale*/13.8);  
  return retrnV;
}
bool J1708Class::getTransmissionOilTemp(float &Temperature) //We still use °C, even though definition: –8192.00 to +8191.75 °F, 0.25 °F, PID=177
{
  bool retrnV;
  char cmd[]="B1";  
  retrnV=getPhysical_float(cmd,Temperature,  /*float scale*/0.25,true);  
  Temperature=(Temperature-32)/1.8;
  return retrnV;
}
bool J1708Class::getPowerSpecificInstantFuelEconomy(float &Rate) //0.0 to 129.1 kW·h/L, 1.97 x 10–3 kW·h/L /Bit, PID=130
{
  bool retrnV;
  char cmd[]="82";  
  retrnV=getPhysical_float(cmd,Rate,  /*float scale*/0.00197);  
  return retrnV;
}
bool J1708Class::getAvgFuelRate(float &FuelRate)   //0.0 to 1.07665 L/s , 16.428 x 10–6 L/s/Bit, PID=133
{
  bool retrnV;
  char cmd[]="85";  
  retrnV=getPhysical_float(cmd,FuelRate,  /*float scale*/0.000016428);  
  return retrnV;
}
bool J1708Class::getInstantFuelEconomy(float &InstantFuelEconomy) //0.0 to 108.835 km/L, 1.66072 x 10–3 km/L/Bit, PID=184
{
  bool retrnV;
  char cmd[]="B8";  
  retrnV=getPhysical_float(cmd,InstantFuelEconomy,  /*float scale*/0.00166072);  
  return retrnV;
}
bool J1708Class::getAvgFuelEconomy(float &AvgFuelEconomy) //0.0 to 108.835 km/L, 1.66072 x 10–3 km/L/Bit, PID=185
{
  bool retrnV;
  char cmd[]="B9";  
  retrnV=getPhysical_float(cmd,AvgFuelEconomy,  /*float scale*/0.00166072);  
  return retrnV;
}
bool J1708Class::getElectricalVoltage(float &BatteryVoltage) //0.0 to 3276.75 V, 0.05 V/Bit, PID=158 After switch
{
  bool retrnV;
  char cmd[]="9E";  
  retrnV=getPhysical_float(cmd,BatteryVoltage,  /*float scale*/0.05);  
  return retrnV;
}
bool J1708Class::getRatedEnginePower(float &Power) //0.0 to 48869.4 kW, 0.745 kW/bit, PID=166
{
  bool retrnV;
  char cmd[]="A6";  
  retrnV=getPhysical_float(cmd,Power,  /*float scale*/0.745);  
  return retrnV;
}
bool J1708Class::getBatteryVoltage(float &BatteryVoltage)  //0.0 to 3276.75 V, 0.05V/bit  PID=168
{
  bool retrnV;
  char cmd[]="A8";  
  retrnV=getPhysical_float(cmd,BatteryVoltage,  /*float scale*/0.05);  
  return retrnV;
}
bool J1708Class::getAlternatorVoltage(float &AlternatorVoltage)   //0.0 to 3276.75 V,0.05V/Bit, PID=167
{
  bool retrnV;
  char cmd[]="A7";  
  retrnV=getPhysical_float(cmd,AlternatorVoltage,  /*float scale*/0.05);  
  return retrnV;
}
bool J1708Class::getAmbientTemp(int &AmbientTemp)  //We still use °C, even though definition:–8192.00 to +8191.75 °F,0.25 °F/Bit, PID=171
{
  bool retrnV;
  char cmd[]="AB";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) AmbientTemp=(int)(TempFloat+0.5); else AmbientTemp=(int)(TempFloat-0.5);
  return retrnV;
}
bool J1708Class::getCargoAmbientTemp(int &CargoTemp)  //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=169
{
  bool retrnV;
  char cmd[]="A9";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) CargoTemp=(int)(TempFloat+0.5); else CargoTemp=(int)(TempFloat-0.5);
  return retrnV;
}
bool J1708Class::getRoadTemp(int &RoadTemp) //We still use °C, even though definition:–320.0 to +317.5 °F, 2.5 °F/Bit, PID=79
{
  bool retrnV;
  char cmd[]="4F";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/2.5,true);  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) RoadTemp=(int)(TempFloat+0.5); else RoadTemp=(int)(TempFloat-0.5);
  return retrnV;
}
bool J1708Class::getCabInteriorTemp(int &CabInteriorTemp) //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=170
{
  bool retrnV;
  char cmd[]="AA";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) CabInteriorTemp=(int)(TempFloat+0.5); else CabInteriorTemp=(int)(TempFloat-0.5);
  return retrnV;
}
bool J1708Class::getInletTemp(int &InletTemp) //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=172
{
  bool retrnV;
  char cmd[]="AC";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) InletTemp=(int)(TempFloat+0.5); else InletTemp=(int)(TempFloat-0.5);
  return retrnV;
}
bool J1708Class::getFuelTemp(int &temp) //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=174
{
  bool retrnV;
  char cmd[]="AE";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) temp=(int)(TempFloat+0.5); else temp=(int)(TempFloat-0.5);
  return retrnV;
}
bool J1708Class::getOilTemp(int &temp) //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=175
{
  bool retrnV;
  char cmd[]="AF";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) temp=(int)(TempFloat+0.5); else temp=(int)(TempFloat-0.5);
  return retrnV;
}
bool J1708Class::getCargoWeight(float &CargoW) //0.0 to 1166056.9 N, 17.792 N/bit PID=181
{
  bool retrnV;
  char cmd[]="B5";  
  retrnV=getPhysical_float(cmd,CargoW,  /*float scale*/17.792);  
  return retrnV;
}
bool J1708Class::getEngineTripFuel(float &EngineTripFuel)  //0.0 to 31009.6 L, 0.473 L/Bit, PID=182
{
  bool retrnV;
  char cmd[]="B6";  
  retrnV=getPhysical_float(cmd,EngineTripFuel,  /*float scale*/0.473);  
  return retrnV;
}

bool J1708Class::getEngineTotalFuelUsed(float &EngineTotalFuelUsed)  //0.0 to 2032277476 L L, 0.473 L L/Bit, PID=250
{
	bool retrnV;
	char cmd[] = "FA";
	retrnV = getPhysical_float(cmd, EngineTotalFuelUsed,  /*float scale*/0.473);
	if (EngineTotalFuelUsed < 0) EngineTotalFuelUsed = EngineTotalFuelUsed + 4294967296 * 0.473;   //because ulong => unsigned long
	return retrnV;
}

bool J1708Class::getFuelRate(float &FuelRate)    //0.0 to 1.07665 L/s , 16.428 x 10–6 L/s/Bit, PID=183
{
  bool retrnV;
  char cmd[]="B7";  
  retrnV=getPhysical_float(cmd,FuelRate,  /*float scale*/0.000016428);  
  return retrnV;
}
bool J1708Class::getRatedEngineSpeed(float &RatedEngineSpeed)   //0.0 to 16383.75 rpm, 0.25 rpm/bit, PID=189
{
  bool retrnV;
  char cmd[]="BD";  
  retrnV=getPhysical_float(cmd,RatedEngineSpeed,  /*float scale*/0.25);  
  return retrnV;
}
bool J1708Class::getEngineSpeed(int &EngineSpeed)   //0.0 to 16383.75 rpm, 0.25rpm/Bit, pid=190
{
  bool retrnV;
  char cmd[]="BE";
  float tempFloat;  
  retrnV=getPhysical_float(cmd,tempFloat,  /*float scale*/0.25);  
  EngineSpeed=(int)(tempFloat+0.5);
  return retrnV;
}
bool J1708Class::getIntakeManifoldTemp(int &IntakeManifoldTemp)  ////We still use °C even though definition: 0.0 to 255.0 °F, 1.0 °F/Bit  PID=105
{
  bool retrnV;
  char cmd[]="69";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat,  /*float scale*/1.00);
  tempFloat=(tempFloat-32)/1.8;
  if (tempFloat>=0) IntakeManifoldTemp=(int)(tempFloat+0.5); else IntakeManifoldTemp=(int)(tempFloat-0.5);
  return retrnV;
}
bool J1708Class::getPowerTakeoffStatus(bool &PTOModeActive, bool &ClutchSwitchOn, bool &BrakeSwitchOn, bool &AccelSwitchOn, bool &ResumeSwitchOn, bool &CoastSwitchOn, bool &SetSwitchOn, bool &PTOControlSwitchOn) //Bit-Mapped,PID=89 
{
  bool retrnV;
  char cmd[]="59";
  long tempV; 
  PTOModeActive=false;ClutchSwitchOn=false;BrakeSwitchOn=false;AccelSwitchOn=false;ResumeSwitchOn=false; CoastSwitchOn=false; SetSwitchOn=false;PTOControlSwitchOn=false;  
  retrnV=getbyte(cmd,tempV);
  if (tempV&0x80) PTOModeActive=true;
  if (tempV&0x40) ClutchSwitchOn=true;
  if (tempV&0x20) BrakeSwitchOn=true;
  if (tempV&0x10) AccelSwitchOn=true;
  if (tempV&0x08) ResumeSwitchOn=true;
  if (tempV&0x04) CoastSwitchOn=true;
  if (tempV&0x02) SetSwitchOn=true;
  if (tempV&0x01) PTOControlSwitchOn=true;
  return retrnV;
}
bool J1708Class::getTripDistance(float &TripDistance)   //0.0 to 691207984.6 km, 0.160934 km/bit, PID=244
{
  bool retrnV;
  char cmd[]="F4";
  long tempV; 
  retrnV=getbyte(cmd,tempV);
  if (tempV<0) 
  {
    TripDistance=4294967296+tempV;  //change to unsigned 
     
  }
  else
  {
    TripDistance=tempV;
  }
  TripDistance=TripDistance*0.160934;   
  return retrnV;
}
bool J1708Class::J1708Class::getTotalDistance(float &TotalDistance) //0.0 to 691207984.6 km, 0.160934 km/bit, PID=245
{
  bool retrnV;
  char cmd[]="F5";
  long tempV; 
  retrnV=getbyte(cmd,tempV);
  if (tempV<0) 
  {
    TotalDistance=4294967296+tempV;  //change to unsigned 
     
  } 
  else 
  {
    TotalDistance=tempV;
  }
  TotalDistance=TotalDistance*0.160934; 
  return retrnV; 
}
bool J1708Class::getTotalEngineHours(float &TotalEngineHours) //0.0 to 214748364.8 h, 0.05h/bit, PID=247
{
  bool retrnV;
  char cmd[]="F7";
  long tempV; 
  retrnV=getbyte(cmd,tempV);
  if (tempV<0) 
  {
    TotalEngineHours=4294967296+tempV;  //change to unsigned 
     
  }
  else
  {
    TotalEngineHours=tempV;
  }
  TotalEngineHours=TotalEngineHours*0.05;  
  return retrnV;
}
bool J1708Class::getTotalEngineRevolutions(float &TotalEngineRevolutions)  //0 to 4294967295000 r.  1000 r/BIT, PID=249
{
  bool retrnV;
  char cmd[]="F9";
  long tempV; 
  retrnV=getbyte(cmd,tempV);
  if (tempV<0) 
  {
    TotalEngineRevolutions=4294967296+tempV;  //change to unsigned 
     
  }
  else
  {
    TotalEngineRevolutions=tempV;
  }
  TotalEngineRevolutions=TotalEngineRevolutions*1000.0;  
  return retrnV;
}


bool J1708Class::getDTC(byte &DTC_Num,byte &MID,int (&PID_SID)[8],bool (&IsPID)[8], byte (&FMI)[8],bool (& IsActive)[8],bool (&OccurrenceExist)[8],byte (&OccurrenceCount)[8])   //PID=194
{
  byte ByteData[28];
  byte Len;
  char HexValue[]="0x00";
  int i;   
  char tryTimes;
   //AT H1
  while (!Pareant->ATCommand("AT H1"));
  
  DTC_Num=0;
  tryTimes=0;
  while(!Pareant->DigitalCommand("C2"))  //PID=194
  {
    tryTimes++;
    if (tryTimes>=5) {while (!Pareant->ATCommand("AT H0")); return false;}
  }     
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();    

  HexValue[2]=Pareant->ReturnStr.charAt(0);
  HexValue[3]=Pareant->ReturnStr.charAt(1);
  MID=strtol(HexValue,NULL,16);  
   
  if (Pareant->ReturnStr.substring(2,4)!="C2") { while(!Pareant->ATCommand("AT H0")); return false;}
  HexValue[2]=Pareant->ReturnStr.charAt(4);
  HexValue[3]=Pareant->ReturnStr.charAt(5);
  Len=strtol(HexValue,NULL,16);
  Pareant->ReturnStr=Pareant->ReturnStr.substring(6); 
  if (!Len) {while(!Pareant->ATCommand("AT H0")); return true;}  //no fault
  if (Len!=(Pareant->ReturnStr.length())/2) { while(!Pareant->ATCommand("AT H0")); return false;}
  //correct data
  for (i=0;i<Len;i++)  //how about Len>20?
  {
    HexValue[2]=Pareant->ReturnStr.charAt(2*i);
    HexValue[3]=Pareant->ReturnStr.charAt(2*i+1);
    ByteData[i]=strtol(HexValue,NULL,16);
    if ((2*i+1)>=55)  break;  //limit because of ByteData[28]    
  }         
  i=0;  //byte Postion of handled Data
  while (true)
  {    
    FMI[DTC_Num]=ByteData[i+1]&0x0f;  //b.4 to b.1
    if (ByteData[i+1]&0x20)   //b.6
    {
       //standard diagnostic code       
       PID_SID[DTC_Num]=ByteData[i];  //a
    }
    else
    {
      //expansion diagnostic code (PID or SID from page 2)      
      PID_SID[DTC_Num]=ByteData[i]+256;  //a
    }
    if (ByteData[i+1]&0x40)   //b.7
    {
      //fault is not active      
      IsActive[DTC_Num]=false;
    }
    else
    {
      //fault is active      
      IsActive[DTC_Num]=true;
    }
    if (ByteData[i+1]&0x10)   //b.5
    {
      //SID
      IsPID[DTC_Num]=false;
    }
    else
    {
      //PID
      IsPID[DTC_Num]=true;
    }
    if (ByteData[i+1]&0x80)   //b.8
    {
       //Occurrence Count included
       OccurrenceExist[DTC_Num]=true; 
       OccurrenceCount[DTC_Num]=ByteData[i+2];  //c
       i=i+3;
    }
    else
    {
      //Occurrence Count NOT included
      OccurrenceExist[DTC_Num]=false;  
      OccurrenceCount[DTC_Num]=0;
      i=i+2;
    }
    DTC_Num++;    
    if (i>=Len-2) break;
    if (i>=26) break;
  }  //end of "while..."
  while(!Pareant->ATCommand("AT H0"));
  return true;
}

bool J1708Class::clearDTC(byte MID,int PID_SID, bool IsPID)  //PID=195, and clear all fault related to MID
{
  byte byteD;
  char HexValue[]="0x00";
  char tryTimes;
  char cmd[]="C303000000";
  String tempStr;
  bool ExtendedPID=false;
  if (MID<=15) tempStr+="0";
  tempStr+=String(MID,16);
  cmd[4]=tempStr.charAt(0);
  cmd[5]=tempStr.charAt(1);  //MID
  if (PID_SID>=256)
  {
    ExtendedPID=true;
    PID_SID=PID_SID-256;
  }
  tempStr="";
  if (PID_SID<=15) tempStr+="0";
  tempStr+=String(PID_SID,16);
  cmd[6]=tempStr.charAt(0);
  cmd[7]=tempStr.charAt(1);  //PID
  if (ExtendedPID )
  {
    //Extendt PID/SID
    if (IsPID) cmd[8]='8'; else cmd[8]='9';
  }
  else
  {
    //Standard PID/SID
    if (IsPID) cmd[8]='A'; else cmd[8]='B';
  }
  tryTimes=0;
  while(!Pareant->DigitalCommand(cmd))  //PID=195
  {
    tryTimes++;
    if (tryTimes>=5) { return false;}
  }     
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();  
  //verify pid=196 which is respond from pid=195
  if (Pareant->ReturnStr.substring(0,2)!="C4") { return false;}  
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  if (byteD<2) return false; 
  Pareant->ReturnStr=Pareant->ReturnStr.substring(4);   //Data
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  if ((byteD&0xC0)!=0x80) return false;
  return true;
}

bool J1708Class::getFaultDescription(byte MID,int PID_SID, bool IsPID,byte FMI, String & FaultDescription) //PID=195,
{
  char bufferx[40];
  byte i;
  byte byteD;
  char HexValue[]="0x00";
  char tryTimes;
  char cmd[]="C303000000";
  String tempStr;
  bool ExtendedPID=false;
  if (MID<=15) tempStr+="0";
  tempStr+=String(MID,16);
  cmd[4]=tempStr.charAt(0);
  cmd[5]=tempStr.charAt(1);  //MID
  if (PID_SID>=256)
  {
    ExtendedPID=true;
    PID_SID=PID_SID-256;
  }
  tempStr="";
  if (PID_SID<=15) tempStr+="0";
  tempStr+=String(PID_SID,16);
  cmd[6]=tempStr.charAt(0);
  cmd[7]=tempStr.charAt(1);  //PID

  byteD=0X0F&FMI;
  if (ExtendedPID )
  {
    //Extendt PID/SID
    if (IsPID) byteD+=0xC0; else byteD+=0xD0;
  }
  else
  {
    //Standard PID/SID
    if (IsPID) byteD+=0xE0; else byteD+=0xF0;
  }
  tempStr==String(byteD,16);
  cmd[8]=tempStr.charAt(0);
  cmd[9]=tempStr.charAt(1);  //c: CONTROL 
  
 
  tryTimes=0;
  while(!Pareant->DigitalCommand(cmd))  //PID=195
  {
    tryTimes++;
    if (tryTimes>=5) { return false;}
  }     
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();  
  //get pid=196 which is respond from pid=195
  if (Pareant->ReturnStr.substring(0,2)!="C4") { return false;}  
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  if (byteD<3) return false; 
  Pareant->ReturnStr=Pareant->ReturnStr.substring(4);   //Data
  HexValue[2]=Pareant->ReturnStr.charAt(0);
  HexValue[3]=Pareant->ReturnStr.charAt(1);
  byteD=strtol(HexValue,NULL,16); //SID
  if (byteD!=PID_SID) return false;
  //control field
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  
  if ((byteD&0xC0)!=0xC0) return false;  //Not: Get DTC description
  if ((byteD&0x0F)!=(FMI&0x0F)) return false;  //wrong FMI

  for (i=0;i<(Pareant->ReturnStr.length())/2-2;i++)
  {
     HexValue[2]=Pareant->ReturnStr.charAt(i*2+4);
     HexValue[3]=Pareant->ReturnStr.charAt(i*2+5);
     bufferx[i]=strtol(HexValue,NULL,16);
     if (i>=38) break;
  }
  if (((Pareant->ReturnStr.length())/2-2)<=39)  
    bufferx[(Pareant->ReturnStr.length())/2-2]='\0';
  else
    bufferx[39]='\0';  
  FaultDescription=bufferx;
  
  return true;
}

bool J1708Class::getPIDSIDDescription(byte MID,int PID_SID, bool IsPID, String & PID_SID_Description) //PID=195,
{
  char bufferx[40];
  byte i;
  byte byteD;
  char HexValue[]="0x00";
  char tryTimes;
  char cmd[]="C303000000";
  String tempStr;
  bool ExtendedPID=false;
  if (MID<=15) tempStr+="0";
  tempStr+=String(MID,16);
  cmd[4]=tempStr.charAt(0);
  cmd[5]=tempStr.charAt(1);  //MID
  if (PID_SID>=256)
  {
    ExtendedPID=true;
    PID_SID=PID_SID-256;
  }
  tempStr="";
  if (PID_SID<=15) tempStr+="0";
  tempStr+=String(PID_SID,16);
  cmd[6]=tempStr.charAt(0);
  cmd[7]=tempStr.charAt(1);  //PID

  //byteD=0X0F&FMI;
  byteD==0;
  if (ExtendedPID )
  {
    //Extendt PID/SID
    if (IsPID) byteD+=0x00; else byteD+=0x10;
  }
  else
  {
    //Standard PID/SID
    if (IsPID) byteD+=0x20; else byteD+=0x30;
  }
  tempStr==String(byteD,16);
  cmd[8]=tempStr.charAt(0);
  cmd[9]=tempStr.charAt(1);  //c: CONTROL 
  
 
  tryTimes=0;
  while(!Pareant->DigitalCommand(cmd))  //PID=195
  {
    tryTimes++;
    if (tryTimes>=5) { return false;}
  }     
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();  
  //get pid=196 which is respond from pid=195
  if (Pareant->ReturnStr.substring(0,2)!="C4") { return false;}  
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  if (byteD<3) return false; 
  Pareant->ReturnStr=Pareant->ReturnStr.substring(4);   //Data
  HexValue[2]=Pareant->ReturnStr.charAt(0);
  HexValue[3]=Pareant->ReturnStr.charAt(1);
  byteD=strtol(HexValue,NULL,16); //SID
  if (byteD!=PID_SID) return false;
  //control field
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  
  if ((byteD&0xC0)!=0x00) return false;  //Not: Get PID/SID description  

  for (i=0;i<(Pareant->ReturnStr.length())/2-2;i++)
  {
     HexValue[2]=Pareant->ReturnStr.charAt(i*2+4);
     HexValue[3]=Pareant->ReturnStr.charAt(i*2+5);
     bufferx[i]=strtol(HexValue,NULL,16);
     if (i>=38) break;
  }
  if (((Pareant->ReturnStr.length())/2-2)<=39)  
    bufferx[(Pareant->ReturnStr.length())/2-2]='\0';
  else
    bufferx[39]='\0';  
  PID_SID_Description=bufferx;
  
  return true;
}

bool J1708Class::getVIN(String &VIN)
{
  char bufferx[30];
  char HexValue[]="0x00";
  byte i;
  char tryTimes;
  tryTimes=0;
  while(!Pareant->DigitalCommand("ED"))  //PID=237
  {
    tryTimes++;
    if (tryTimes>=5) {VIN="";  return false;}
  }     
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();    
  if (Pareant->ReturnStr.substring(0,2)!="ED") { VIN=""; return false;} 
    
  Pareant->ReturnStr=Pareant->ReturnStr.substring(4); 
  for (i=0;i<(Pareant->ReturnStr.length())/2;i++)
  {
     HexValue[2]=Pareant->ReturnStr.charAt(i*2);
     HexValue[3]=Pareant->ReturnStr.charAt(i*2+1);
     bufferx[i]=strtol(HexValue,NULL,16);
  }
  bufferx[(Pareant->ReturnStr.length())/2]='\0';
  VIN=bufferx;
  return true;
}

// cmd= pid. pid mus be <=254  When 4 byte, No matter what Signed is false or true, Out1byte always is  signed
bool J1708Class::getbyte(char cmd[],long &Out1byte, bool Signed=false)
{
  char Hex1Byte[]="0x00";
  char Hex2Byte[]="0x0000";  
  char Hex4Byte[]="0x00000000";    
  long temp;
  unsigned long temp2;
  char tryTimes;
  tryTimes=0;
  while(!Pareant->DigitalCommand(cmd))
  {
    tryTimes++;
    if (tryTimes>=5) {Out1byte=0;  return false;}
  }  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();  
  if (Pareant->ReturnStr.substring(0,2)!=cmd) {Out1byte=0; return false;}

  Hex1Byte[2]=Pareant->ReturnStr.charAt(0);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(1);  
  temp=strtol(Hex1Byte,NULL,16);       
  if (temp<128)
  {
    //single byte
    Hex1Byte[2]=Pareant->ReturnStr.charAt(2);
    Hex1Byte[3]=Pareant->ReturnStr.charAt(3);  
    Out1byte=strtol(Hex1Byte,NULL,16);   
    if (Signed)
    {
      if (Out1byte>=128) Out1byte=Out1byte-256;
    }
  } 
  else if (temp<192)
  {
    // 2 bytes
    Hex2Byte[2]=Pareant->ReturnStr.charAt(4);
    Hex2Byte[3]=Pareant->ReturnStr.charAt(5);  
    Hex2Byte[4]=Pareant->ReturnStr.charAt(2);
    Hex2Byte[5]=Pareant->ReturnStr.charAt(3);  
    Out1byte=strtol(Hex2Byte,NULL,16);      
    if (Signed)
    {
      if (Out1byte>=32768) Out1byte=Out1byte-65536;
    }    
  }
  else 
  {
    //variable bytes (in geberal, more than 2 bytes)
    Hex1Byte[2]=Pareant->ReturnStr.charAt(2);
    Hex1Byte[3]=Pareant->ReturnStr.charAt(3);  
    temp=strtol(Hex1Byte,NULL,16); 
    if (1==temp)
    {
      //single byte
      Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
      Hex1Byte[3]=Pareant->ReturnStr.charAt(5);  
      Out1byte=strtol(Hex1Byte,NULL,16);   
      if (Signed)
      {
        if (Out1byte>=128) Out1byte=Out1byte-256;
      }
    }
    else if (2==temp)
    {
      // 2 bytes
      Hex2Byte[2]=Pareant->ReturnStr.charAt(6);
      Hex2Byte[3]=Pareant->ReturnStr.charAt(7);  
      Hex2Byte[4]=Pareant->ReturnStr.charAt(4);
      Hex2Byte[5]=Pareant->ReturnStr.charAt(5);  
      Out1byte=strtol(Hex2Byte,NULL,16);      
      if (Signed)
      {
        if (Out1byte>=32768) Out1byte=Out1byte-65536;
      }    
    }
    else if (4==temp)
    {
      // 4 bytes      
      //High 16 bit
      Hex4Byte[2]=Pareant->ReturnStr.charAt(10);
      Hex4Byte[3]=Pareant->ReturnStr.charAt(11);  
      Hex4Byte[4]=Pareant->ReturnStr.charAt(8);
      Hex4Byte[5]=Pareant->ReturnStr.charAt(9); 
      temp=strtol(Hex4Byte,NULL,16);
      temp2=temp;
      //Low 16 bit 
      Hex4Byte[6]=Pareant->ReturnStr.charAt(6);
      Hex4Byte[7]=Pareant->ReturnStr.charAt(7);  
      Hex4Byte[8]=Pareant->ReturnStr.charAt(4);
      Hex4Byte[9]=Pareant->ReturnStr.charAt(5);  
      temp=strtol(Hex4Byte,NULL,16);    
      temp2=(temp2<<16)+temp;

      //changed to Signed long
      if (temp2>=2147483648) 
        Out1byte=temp2-4294967296;   
      else
        Out1byte=temp2;     
      //Serial.print("Data:"); Serial.println(Out1byte);      
    }
    else
    {      
      return false;
    }
    
    
          
  }
  return true;
}

//We cannot use it when 4 bytes, and unsigned long for respond result
 bool J1708Class::getPhysical_float(char cmd[],float &OutFloat, float scale,bool Signed=false)
 {
  bool returnV;
  long tempV; 
  returnV=getbyte(cmd,tempV,Signed);
  OutFloat=tempV*scale;  
  return returnV;
 }

