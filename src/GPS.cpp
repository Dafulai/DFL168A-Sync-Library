#include "Arduino.h"
#include "DFL168A.h"
GPSClass::GPSClass(){
  Baudrate=9600;
  Timeout=500;  //time out is 500ms;
  Pareant=NULL;
}

GPSClass::GPSClass(long Baudrate,int Timeout, class DFL168A * Pareant ){
  this->Baudrate=Baudrate;
  this->Timeout=Timeout;
  this->Pareant=Pareant;
}

bool GPSClass::getGPSinfo(float &Latitude,float &Longitude, int &Speed /*Km/h*/, String &Time /*hh:mm::ss*/, String &Date /*dd/mm/yyyy*/)
{
  String StrResult;
  String subStringR;
  int Space_Index;
  float tempF;
  char XXX[15];
  bool Minus_Result;
  Pareant->mySerial->setTimeout(Timeout+50);
  if (!Pareant->ATCommand("ATDEV1SIGBSOF1")) {  Pareant->mySerial->setTimeout((Pareant->Timeout)+50); return false;}   //"AT DEV1 SI GB SOF 3" FOR GMC Sentence
  Pareant->mySerial->setTimeout((Pareant->Timeout)+50);
  
  Pareant->mySerial->println("AT DEV1 LAT"); 
  StrResult=Pareant->mySerial->readStringUntil('>'); 
  StrResult.trim();  //"+25 33.456'"

  if (StrResult=="") return false;
  if ('?'==StrResult.charAt(0)) return false;
  if ('N'==StrResult.charAt(0)) return false;

  if ('-'==StrResult.charAt(0)) Minus_Result=true;  else Minus_Result=false; //in case "-0 22.89'" ,How about ""-78.98'" ? we don't know if it has "0 " before 78.98'  Check 20 0' situation: 20 or 20 0' in DFL168A source code
  Space_Index=StrResult.indexOf(' ');
  subStringR=StrResult.substring(0,Space_Index);
  subStringR.toCharArray(XXX,15);
  tempF=atof(XXX);
  Latitude=tempF;

  StrResult=StrResult.substring(Space_Index+1);
  Space_Index=StrResult.indexOf('\'');
  subStringR=StrResult.substring(0,Space_Index);
  subStringR.toCharArray(XXX,15);
  tempF=atof(XXX);
  tempF=tempF/60.0;
  if (Minus_Result) Latitude-=tempF; else Latitude+=tempF;

  Pareant->mySerial->println("AT DEV1 LONG"); 
  StrResult=Pareant->mySerial->readStringUntil('>'); 
  StrResult.trim();  //"+25 33.456'"     

  if (StrResult=="") return false;
  if ('?'==StrResult.charAt(0)) return false;
  if ('N'==StrResult.charAt(0)) return false;

  if ('-'==StrResult.charAt(0)) Minus_Result=true;  else Minus_Result=false;  //in case "-0 22.89'" ,How about ""-78.98'" ? we don't know if it has "0 " before 78.98'
  Space_Index=StrResult.indexOf(' ');
  subStringR=StrResult.substring(0,Space_Index);
  subStringR.toCharArray(XXX,15);
  tempF=atof(XXX);
  Longitude=tempF;

  StrResult=StrResult.substring(Space_Index+1);
  Space_Index=StrResult.indexOf('\'');
  subStringR=StrResult.substring(0,Space_Index);
  subStringR.toCharArray(XXX,15);
  tempF=atof(XXX);
  tempF=tempF/60.0;
  if (Minus_Result) Longitude-=tempF; else Longitude+=tempF;

  Pareant->mySerial->println("AT DEV1 SPEED"); 
  StrResult=Pareant->mySerial->readStringUntil('>'); 
  StrResult.trim();  //"56.7"     

  if (StrResult=="") return false;
  if ('?'==StrResult.charAt(0)) return false;
  if ('N'==StrResult.charAt(0)) return false;  
  StrResult.toCharArray(XXX,15);
  tempF=atof(XXX);
  Speed=tempF*1.852;

  Pareant->mySerial->println("AT DEV1 TIME"); 
  StrResult=Pareant->mySerial->readStringUntil('>'); 
  StrResult.trim();  //"20:58:31"     

  if (StrResult=="") return false;
  if ('?'==StrResult.charAt(0)) return false;
  if ('N'==StrResult.charAt(0)) return false;  
  Time=StrResult;

  
  Pareant->mySerial->println("AT DEV1 DATE"); 
  StrResult=Pareant->mySerial->readStringUntil('>'); 
  StrResult.trim();  //"20:58:31"     

  if (StrResult=="") return false;
  if ('?'==StrResult.charAt(0)) return false;
  if ('N'==StrResult.charAt(0)) return false;  
  Date=StrResult;
  
  return true;
}

bool GPSClass::getAltitude(float &Altitude /*Meter*/)
{
  String StrResult;
  String subStringR;
  int Space_Index;
  char XXX[15];
  bool Minus_Result;
  Pareant->mySerial->setTimeout(Timeout+50);
  if (!Pareant->ATCommand("ATDEV1SIGBSOF2")) {  Pareant->mySerial->setTimeout((Pareant->Timeout)+50); return false;}   //"AT DEV1 SI GB SOF 2" FOR GCA Sentence
  Pareant->mySerial->setTimeout((Pareant->Timeout)+50);

  Pareant->mySerial->println("AT DEV1 ALT"); 
  StrResult=Pareant->mySerial->readStringUntil('>'); 
  StrResult.trim();  //"5608"     

  if (StrResult=="") return false;
  if ('?'==StrResult.charAt(0)) return false;
  if ('N'==StrResult.charAt(0)) return false;  
  StrResult.toCharArray(XXX,15);
  Altitude=atof(XXX);    
  return true;
}

