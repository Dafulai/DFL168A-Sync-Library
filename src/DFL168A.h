#ifndef DFL168A_h
#define DFL168A_h
#define AUTO_PROTOCOL 0
#define ISO15765_11_500_PROTOCOL 6
#define ISO15765_29_500_PROTOCOL 7
#define ISO15765_11_250_PROTOCOL 8
#define ISO15765_29_250_PROTOCOL 9
#define J1939_PROTOCOL 10
#define USER1_PROTOCOL 11
#define USER2_PROTOCOL 12
#define J1708_PROTOCOL 13

class PGN65256Class
{
  public:
   class DFL168A * Pareant;
   PGN65256Class();
   PGN65256Class(class DFL168A * Pareant);
   bool refresh();
   bool getAltitude(float &Altitude);
   bool getNavBasedSpeed(float &Speed);
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65269Class
{
  public:
   class DFL168A * Pareant;
   PGN65269Class();
   PGN65269Class(class DFL168A * Pareant);
   bool refresh();
   bool getBarometricPressure(float &BaroPressure);
   bool getAmbientTemp(int &AmbientTemp);
   bool getInletTemp(int &InletTemp);
   bool getRoadTemp(int &RoadTemp);
   bool getCabInteriorTemp(int &CabInteriorTemp);
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65257Class
{
  public:
   class DFL168A * Pareant;
   PGN65257Class();
   PGN65257Class(class DFL168A * Pareant);
   bool refresh();
   bool getEngineTripFuel(float &EngineTripFuel);
   bool getEngineTotalFuelUsed(float &EngineTotalFuelUsed);
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN61444Class
{
  public:
   class DFL168A * Pareant;
   PGN61444Class();
   PGN61444Class(class DFL168A * Pareant);
   bool refresh();
   bool getActualEngineTorque(int &ActualEngineTorque);  //-125 to +125 (%)
   bool getEngineSpeed(int &EngineSpeed);
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN61443Class
{
  public:
   class DFL168A * Pareant;
   PGN61443Class();
   PGN61443Class(class DFL168A * Pareant);
   bool refresh();
   bool getAccelPedalPosi1(float &AccelPedalPosi1);  //0 to 100 (%)
   bool getAccelPedalPosi2(float &AccelPedalPosi2);  //0 to 100 (%)
   bool getEnginePerLoadAtCurrSpeed(int &EnginePerLoadAtCurrSpeed);  //0 to 125 (%)
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65270Class
{
  public:
   class DFL168A * Pareant;
   PGN65270Class();
   PGN65270Class(class DFL168A * Pareant);
   bool refresh();
   bool getIntakeManifoldPressure(int &IntakeManifoldPressure);   //0-500kpa 2kPa/Bit, BoostPressure=IntakeManifold1# pressure
   bool getIntakeManifoldTemp(int &IntakeManifoldTemp);  //-40 to 210, 1 degree c/bit
   bool getEngineAirInletPressure(int &EngineAirInletPressure);  //0-500kPa, 2kPa/bit
   bool getEngineExhaustGasTemp(int &EngineExhaustGasTemp);  //-273 to 1734.96875  0.03125C/bit
   bool getEngineAirFilterDiffPressure(float &EngineAirFilterDiffPressure);  //0 to 12.5kPa, 0.05kPa/bit (%)
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
class PGN65271Class
{
  public:
   class DFL168A * Pareant;
   PGN65271Class();
   PGN65271Class(class DFL168A * Pareant);
   bool refresh();
   bool getAlternatorVoltage(float &AlternatorVoltage);   //0.05V/Bit
   bool getElectricalVoltage(float &ElectricalVoltage);  
   bool getBatteryVoltage(float &BatteryVoltage); 
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
class PGN65272Class
{
  public:
   class DFL168A * Pareant;
   PGN65272Class();
   PGN65272Class(class DFL168A * Pareant);
   bool refresh();
   bool getTransmissionOilLevel(float &Percent);
   bool getTransmissionOilLevelHighLow(float &HighLow);
   bool getTransmissionOilPressure(float &Pressure); //0 to 4000 kPa, 16 kPa/bit, 4th posion
   bool getTransmissionOilTemp(float &Temperature);//-273 to 1734.96875 deg C, 0.03125 deg C/bit, 5th and 6th
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
class PGN65266Class
{
  public:
   class DFL168A * Pareant;
   PGN65266Class();
   PGN65266Class(class DFL168A * Pareant);
   bool refresh();
   bool getFuelRate(float &FuelRate);   
   bool getInstantFuelEconomy(float &InstantFuelEconomy);  
   bool getAvgFuelEconomy(float &AvgFuelEconomy); 
   bool getEngineThrottlePos(float &EngineThrottlePos); 
   
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65263Class
{
  public:
   class DFL168A * Pareant;
   PGN65263Class();
   PGN65263Class(class DFL168A * Pareant);
   bool refresh();
   bool getFueDeliveryPressure(int &FueDeliveryPressure);   
   bool getEngineOilLevel(float &EngineOilLevel);  
   bool getEngineOilPressure(int &EngineOilPressure); 
   bool getEngineCoolantPressure(int &EngineCoolantPressure); 
   bool getEngineCoolantLevel(float &EngineCoolantLevel); 
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65253Class
{
  public:
   class DFL168A * Pareant;
   PGN65253Class();
   PGN65253Class(class DFL168A * Pareant);
   bool refresh();
   bool getTotalEngineHours(float &TotalEngineHours);   
   bool getTotalEngineRevolutions(float &TotalEngineRevolutions);     
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65214Class
{
  public:
   class DFL168A * Pareant;
   PGN65214Class();
   PGN65214Class(class DFL168A * Pareant);
   bool refresh();
   bool getRatedEngineSpeed(float &RatedEngineSpeed);      
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65248Class
{
  public:
   class DFL168A * Pareant;
   PGN65248Class();
   PGN65248Class(class DFL168A * Pareant);
   bool refresh();
   bool getTripDistance(float &TripDistance);   
   bool getTotalDistance(float &TotalDistance);      
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65276Class
{
  public:
   class DFL168A * Pareant;
   PGN65276Class();
   PGN65276Class(class DFL168A * Pareant);
   bool refresh();
   bool getWasherFluidLevel(float &WasherFluidLevel);   
   bool getFuelLevel1(float &FuelLevel1);  
   bool getFuelLevel2(float &FuelLevel2);      
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65265Class
{
  public:
   class DFL168A * Pareant;
   PGN65265Class();
   PGN65265Class(class DFL168A * Pareant);
   bool refresh();
   bool getWheelBasedVehicleSpeed(float &WheelBasedVehicleSpeed);    
   //Mar07 2019 add SPN70 and SPN597 start (version 1.0.3)
   bool getParkingBrake(bool &ParkingBreakSet);
   bool getBrake(bool &BreakPedalDepressed);
   //Mar07 2019 add SPN70 and SPN597 end
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
class PGN57344Class
{
 public:
   class DFL168A * Pareant;
   PGN57344Class();
   PGN57344Class(class DFL168A * Pareant);
   bool refresh();
   //bool getSeatBelt(bool buckled);   //fix bug    Mar 07 2019 
   bool getSeatBelt(bool &buckled);  
 private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
//*********************************************

class PGN65267Class
{
  public:
   class DFL168A * Pareant;
   PGN65267Class();
   PGN65267Class(class DFL168A * Pareant);
   bool refresh();
   bool getLatitude(float &Latitude);
   bool getLongitude(float &Longitude);
  private:
   boolean SuccessFresh;
   //float Latitude; 
   //float Longitude;
   String FreshResultStr;
};

class PGN65262Class
{
  public:  
   class DFL168A * Pareant;
   PGN65262Class();
   PGN65262Class(class DFL168A * Pareant);
   boolean refresh();
   bool getCoolantTemperature(int &temp);
   bool getFuelTemp(int &temp);
   bool getOilTemp(int &temp);
  private:
   boolean SuccessFresh;
   //int CoolantTemp; 
   //int FuelTemp;
   //int OilTemp;
   String FreshResultStr;
};

//version 1.0.2 add ---start
class PGN64996Class
{
public:
	class DFL168A * Pareant;
	PGN64996Class();
	PGN64996Class(class DFL168A * Pareant);
	boolean refresh();
	bool getPayLoad(int &PayLoad);	  //0 to 250%, 1%/bit, 0 offset
private:
	boolean SuccessFresh;	
	String FreshResultStr;
};

class PGN61445Class
{
public:
	class DFL168A * Pareant;
	PGN61445Class();
	PGN61445Class(class DFL168A * Pareant);
	boolean refresh();
	bool getCurrentGear(int &CurrentGear);   //-125 to 125 and 251,  1 gear value/bit, -125 offset, negative values are reverse gears, positive values are forward gears, zero is neutral. 251(0xFB) is park. 251 actual= 126, but I still use "251" for matching spec
	bool getSelectedGear(int &SelectedGear);   //-125 to 125 and 251,  1 gear value/bit, -125 offset, negative values are reverse gears, positive values are forward gears, zero is neutral. 251(0xFB) is park. 251 actual= 126, but I still use "251" for matching spec
private:
	boolean SuccessFresh;
	String FreshResultStr;
};
//version 1.0.2 add ----end

class J1939Class
{
  friend class DFL168A;
  public:
   class DFL168A * Pareant;
   J1939Class();
   J1939Class(long Baudrate,class DFL168A * Pareant );
   PGN65267Class PGN65267;
   PGN65262Class PGN65262;
   PGN65256Class PGN65256;
   PGN65269Class PGN65269;
   PGN65257Class PGN65257;
   PGN61444Class PGN61444;
   PGN61443Class PGN61443;
   PGN65270Class PGN65270;
   PGN65271Class PGN65271;
   PGN65272Class PGN65272;
   PGN65266Class PGN65266;
   PGN65263Class PGN65263;
   PGN65253Class PGN65253;
   PGN65214Class PGN65214;
   PGN65248Class PGN65248;
   PGN65276Class PGN65276;
   PGN65265Class PGN65265;
   PGN57344Class PGN57344;
   PGN64996Class PGN64996;//version 1.0.2 add
   PGN61445Class PGN61445;//version 1.0.2 add

   bool getVIN(String &VIN);  
   //bool GetDTC(String &DTC);
   bool getDTC(byte &DTC_Num, long  (&SPN)[5], byte (&FMI)[5], byte (&CM)[5],byte (&OC)[5], byte DTCFormat=1 );
   boolean clearDTC();
  private:
    long Baudrate;
    //char VIN[18];
    //char DTC[8]; 
};

class J1708Class
{
  public:
   class DFL168A * Pareant;
   J1708Class();
   J1708Class(class DFL168A * Pareant);
   bool getAirPressure(int &AirPressure);   //0.0 to 1055 kPa,4.14 kPa/bit, PID=7
   bool getEngineOilPressure(int &EngineOilPressure);  //0.0 to 1020 kPa, 4kpa/bit, PID=19
   bool getEngineCoolantPressure(int &EngineCoolantPressure);  //0.0 to 510 kPa ,  2 kPa/bit,pid=20
   bool getFuelLevel1(float &FuelLevel1);  //Primary fuel, 0.0 to 127.5% 0.5%/bit pid=96
   bool getFuelLevel2(float &FuelLevel2);   //righ side fuel, 0.0 to 127.5% 0.5%/bit pid=38
   bool getBarometricPressure(float &Pressure);  //0.0 to 153.0 kPa, 0.6 kPa/bit, PID=48
   bool getEngineThrottlePos(float &EngineThrottlePos); //0.0 to 102.0%, 0.4%/bit, pid=51
   bool getWasherFluidLevel(float &WasherFluidLevel);  //0.0 to 127.5%, 0.5%/bit, pid=80
   bool getVehicleSpeed(float &VehicleSpeed);  //0.0 to 205.2 km/h , 0.805 km/h/bit, pid=84
   bool getAccelPedalPosi1(float &AccelPedalPosi1);  //0.0 to 102.0%,0.4%/bit, pid=91  If only one is available, please use this one
   bool getAccelPedalPosi2(float &AccelPedalPosi2);  //0.0 to 102.0%,0.4%/bit, pid=29  
   bool getAccelPedalPosi3(float &AccelPedalPosi3);  //0.0 to 102.0%,0.4%/bit, pid=28  
   bool getEngineLoad(float &Percent);//0.0 to 127.5%, 0.5%/bit, pid=92
   bool getEngineOilLevel(float &EngineOilLevel);  //0.0 to 127.5%.0.5%/BIT PID=98
   bool getCoolantTemperature(int &temp);  //We still use °C even though definition: 0.0 to 255.0 °F, 1.0 °F, PID=110
   bool getEngineCoolantLevel(float &EngineCoolantLevel); //0.0 to 127.5%, 0.5%/bit, PID=111
   bool getTransmissionOilLevel(float &Percent);//0.0 to 127.5%, 0.5%/bit, pid=124
   bool getTransmissionOilLevelHighLow(float &HighLow);//–60.6 to 60.1 L,0.473L/bit,PID=125
   bool getTransmissionOilPressure(float &Pressure);//0.0 to 3516 kPa, 13.8 kPa/bit, pid=127
   bool getTransmissionOilTemp(float &Temperature); //We still use °C, even though definition: –8192.00 to +8191.75 °F, 0.25 °F, PID=177
   bool getPowerSpecificInstantFuelEconomy(float &Rate); //0.0 to 129.1 kW·h/L, 1.97 x 10–3 kW·h/L /Bit, PID=130
   bool getAvgFuelRate(float &FuelRate);    //0.0 to 1.07665 L/s , 16.428 x 10–6 L/s/Bit, PID=133
   bool getInstantFuelEconomy(float &InstantFuelEconomy); //0.0 to 108.835 km/L, 1.66072 x 10–3 km/L/Bit, PID=184
   bool getAvgFuelEconomy(float &AvgFuelEconomy); //0.0 to 108.835 km/L, 1.66072 x 10–3 km/L/Bit, PID=185
   bool getElectricalVoltage(float &BatteryVoltage); //0.0 to 3276.75 V, 0.05 V/Bit, PID=158, after switch
   bool getRatedEnginePower(float &Power); //0.0 to 48869.4 kW, 0.745 kW/bit, PID=166      
   bool getBatteryVoltage(float &BatteryVoltage);  //0.0 to 3276.75 V, 0.05V/bit  PID=168
   bool getAlternatorVoltage(float &AlternatorVoltage);   //0.0 to 3276.75 V,0.05V/Bit, PID=167
   bool getAmbientTemp(int &AmbientTemp);  //We still use °C, even though definition:–8192.00 to +8191.75 °F,0.25 °F/Bit, PID=171
   bool getCargoAmbientTemp(int &CargoTemp);  //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=169
   bool getRoadTemp(int &RoadTemp);//We still use °C, even though definition:–320.0 to +317.5 °F, 2.5 °F/Bit, PID=79
   bool getCabInteriorTemp(int &CabInteriorTemp);//We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=170
   bool getInletTemp(int &InletTemp);//We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=172
   bool getFuelTemp(int &temp); //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=174
   bool getOilTemp(int &temp); //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=175
   bool getCargoWeight(float &CargoW); //0.0 to 1166056.9 N, 17.792 N/bit PID=181
   bool getEngineTripFuel(float &EngineTripFuel);  //0.0 to 31009.6 L, 0.473 L/Bit, PID=182
   bool getEngineTotalFuelUsed(float &EngineTotalFuelUsed);
   bool getFuelRate(float &FuelRate);    //0.0 to 1.07665 L/s , 16.428 x 10–6 L/s/Bit, PID=183
   bool getRatedEngineSpeed(float &RatedEngineSpeed);   //0.0 to 16383.75 rpm, 0.25 rpm/bit, PID=189   
   bool getEngineSpeed(int &EngineSpeed);   //0.0 to 16383.75 rpm, 0.25rpm/Bit, pid=190
     
   bool getIntakeManifoldTemp(int &IntakeManifoldTemp);  //We still use °C even though definition: 0.0 to 255.0 °F, 1.0 °F/Bit  PID=105
   bool getPowerTakeoffStatus(bool &PTOModeActive, bool &ClutchSwitchOn, bool &BrakeSwitchOn, bool &AccelSwitchOn, bool &ResumeSwitchOn, bool &CoastSwitchOn, bool &SetSwitchOn, bool &PTOControlSwitchOn); //Bit-Mapped,PID=89
   bool getTripDistance(float &TripDistance);   //0.0 to 691207984.6 km, 0.160934 km/bit, PID=244
   bool getTotalDistance(float &TotalDistance); //0.0 to 691207984.6 km, 0.160934 km/bit, PID=245
   bool getTotalEngineHours(float &TotalEngineHours); //0.0 to 214748364.8 h, 0.05h/bit, PID=247
   bool getTotalEngineRevolutions(float &TotalEngineRevolutions);   //0 to 4294967295000 r.  1000 r/BIT, PID=249  


   bool getVIN(String &VIN);  
   bool getDTC(byte &DTC_Num,byte &MID,int (&PID_SID)[8],bool (&IsPID)[8], byte (&FMI)[8],bool (& IsActive)[8],bool (&OccurrenceExist)[8],byte (&OccurrenceCount)[8]);  //PID=194
   bool clearDTC(byte MID,int PID_SID, bool IsPID);  //PID=195, and clear all fault related to MID,and PID or SID
   bool getFaultDescription(byte MID,int PID_SID, bool IsPID,byte FMI, String & FaultDescription); //PID=195,
   bool getPIDSIDDescription(byte MID,int PID_SID, bool IsPID, String & PID_SID_Description); //PID=195,
 private:
   byte MID4Vehicle;
   bool getbyte(char cmd[],long &Out1byte, bool Signed=false);   
   bool getPhysical_float(char cmd[],float &OutFloat, float scale,bool Signed=false);   
   //char VIN[18];
   //char DTC[8]; 
};

class ISO15765Class
{
  friend class DFL168A;
  public:
   class  DFL168A * Pareant;
   ISO15765Class();
   ISO15765Class(class  DFL168A * Pareant);  
   bool getCoolantTemperature(int &temp); 
   bool getEngineSpeed(int &EngineSpeed);
   bool getVehicleSpeed(float &VehicleSpeed); 
   bool getIntakeManifoldPressure(int &IntakeManifoldPressure);   //0-255kpa 1kPa/Bit, 
   bool getFuelSystemStatus(bool &A_Openloop, bool &A_Closedloop,bool &A_OpenloopByDriving_Con,bool &A_OpenloopByFault,bool &A_ClosedloopButFault,
                            bool &B_Openloop, bool &B_Closedloop,bool &B_OpenloopByDriving_Con,bool &B_OpenloopByFault,bool &B_ClosedloopButFault);
   bool getCalculatedLoadValue(int &CalculatedLoad);  //0 to 100%
   bool getShortTermFuelTrimBank13(float &Bank1,float &Bank3); //-100 to 99.22%
   bool getLongTermFuelTrimBank13(float &Bank1,float &Bank3); //-100 to 99.22%
   bool getShortTermFuelTrimBank24(float &Bank2,float &Bank4); //-100 to 99.22%
   bool getLongTermFuelTrimBank24(float &Bank2,float &Bank4); //-100 to 99.22%
   bool getIgnitionTimingAdvance(float &Angle);  //-64 63.5 degree
   bool getIntakeAirTemperature(int &temp); 
   bool getAirFlowRateFrmMAF(float &FlowRate);   //unit: g/s
   bool getAbsThrottlePosition(float &Percent); //0 to 100%
   bool getOxygenSensorLocation(bool &Bank1_Sensor1Present, bool &Bank1_Sensor2Present, bool &Bank1_Sensor3Present,bool &Bank1_Sensor4Present, bool &Bank3_Sensor1Present,bool &Bank3_Sensor2Present,
                                bool &Bank2_Sensor1Present, bool &Bank2_Sensor2Present, bool &Bank2_Sensor3Present,bool &Bank2_Sensor4Present, bool &Bank4_Sensor1Present,bool &Bank4_Sensor2Present);
   bool getBank1OSensor1Voltage(float &OutVoltage);  // 0 to 1.275V   
   bool getBank1OSensor2Voltage(float &OutVoltage);  // 0 to 1.275V  
   bool getBank1OSensor3Voltage(float &OutVoltage);  // 0 to 1.275V 
   bool getBank1OSensor4Voltage(float &OutVoltage);  // 0 to 1.275V  
   bool getBank2OSensor1Voltage(float &OutVoltage);  // 0 to 1.275V
   bool getBank2OSensor2Voltage(float &OutVoltage);  // 0 to 1.275V  
   bool getBank2OSensor3Voltage(float &OutVoltage);  // 0 to 1.275V 
   bool getBank2OSensor4Voltage(float &OutVoltage);  // 0 to 1.275V      
   bool getBank3OSensor1Voltage(float &OutVoltage);  // 0 to 1.275V  
   bool getBank3OSensor2Voltage(float &OutVoltage);  // 0 to 1.275V 
   bool getBank4OSensor1Voltage(float &OutVoltage);  // 0 to 1.275V  
   bool getBank4OSensor2Voltage(float &OutVoltage);  // 0 to 1.275V    
   bool getOBDCertified(String &OBD);  
   bool getTimeSinceEngineStart(unsigned int &TotalTime);  
   bool getDistanceTraveledMIL(unsigned int &Distance);    //Distance Traveled While MIL is  Activated  
   bool getFuelRailPressure(float &Pressure);    //kPa
   bool getFuelLevelInput(float &Percent);  //%
   bool getDistanceTraveledSinceDTC_Clear(unsigned int &Distance);  //Distance traveled since DTCs cleared
   bool getBarometricPressure(int &Pressure);  //0 to 255 kPa
   bool getControlModuleVoltage(float &Voltage);  
   bool getRelativeThrottlePosition(float &Percent);  //% 
   bool getAmbientTemp(int &AmbientTemp); //C
   bool getCommandedThrottleActuatorControl(float &Percent);  //%
   bool getEngineRunTimeMIL(unsigned int &TotalTime); //Minutes
   bool getEngineRunTimeSinceDTC_Clear(unsigned int &TotalTime); //Minutes
   bool getTypeOfFuelUsedCurrently(String & FuelType);  //Type of fuel currently being utilized by the vehicle
   bool getRelativeAcceleratorPedalPosition(float &Percent);  //%
   bool getHybridBatteryPackRemainingLife(float &Percent);  //%
   bool getEngineOilTemperature(int &Tem); //C
   bool getFuelRate(float &FuelRate);    //Engine Fuel Rate: L/h
   bool getActualEngineTorque(int &ActualEngineTorque);  //-125 to +130 (%)
   bool getMILStatus(bool &MIL_IS_ON);
   bool getEngineRunTime(unsigned long &TotalEngineRunTime, unsigned long &TotalIdleRunTime,unsigned long &TotalRunTimeWithPTOActive);  //Time unit: Seconds,  PID 7F, their value must not zero, it means it does not support if zero
    
   bool getVIN(String &VIN);  
   bool getDTC(byte &DTC_Num,String ( &DTC)[8]);
   boolean clearDTC(); 
  private:
   //bool DigitalCommand(const char * DigitalCMD);
    //int Baudrate; 
    //char VIN[18]; 
    //char DTC[8]; 
    bool PID_13support;
    bool PID_1DSupport;
    bool get1byte(char cmd[],long &Out1byte);
    bool get2byte(char cmd[],long &Out2byte);
    bool getPhysical2byte_float(char cmd[],float &OutFloat, float offset, float scale);
    bool getPhysicalbyte_float(char cmd[],float &OutFloat, float offset, float scale);
};

class GPSClass
{
  friend class DFL168A;
  public:
   class DFL168A * Pareant;
   GPSClass();
   GPSClass(long Baudrate, int Timeout,class DFL168A * Pareant );    
   bool getGPSinfo(float &Latitude /*degree*/,float &Longitude, int &Speed/*Km/h*/, String &Time /*hh:mm::ss*/, String &Date /*dd/mm/yyyy*/);
   bool getAltitude(float &Altitude /*Meter*/);   
  
  private:
    long Baudrate;
    int Timeout;   
      
};

class DFL168A
{
   friend class GPSClass;
   friend class ISO15765Class;
   friend class J1708Class;
   friend class J1939Class;
   friend class PGN65267Class;
   friend class PGN65262Class;
   friend class PGN65256Class;
   friend class PGN65269Class;
   friend class PGN65257Class;  
   friend class PGN61444Class; 
   friend class PGN61443Class; 
   friend class PGN65270Class;
   friend class PGN65271Class;
   friend class PGN65272Class;
   friend class PGN65266Class;
   friend class PGN65263Class;
   friend class PGN65253Class;
   friend class PGN65214Class;
   friend class PGN65248Class;
   friend class PGN65276Class;
   friend class PGN65265Class;
   friend class PGN57344Class;
   friend class PGN64996Class; //version 1.0.2 add
   friend class PGN61445Class; //version 1.0.2 add
   public:
    DFL168A();
    //DFL168A(byte SerialNo, byte currProtocol,int Timeout, long J1939Baudrate, long DEV_Baudrate);
    DFL168A(HardwareSerial * XX, byte currProtocol,int Timeout, long J1939Baudrate, long DEV_Baudrate, int DEV_timeout);
    bool begin(bool intrude=true,bool Fast=false);
    void end();
    J1939Class J1939;
    J1708Class J1708;
    ISO15765Class ISO15765;
    GPSClass GPS; 
   
    bool getOnewireID(byte (&ID)[7]);
    boolean getDIN(int portNo);
    void setDOUT(int portNo, bool Value);
    float getAnalog(); //0.0 to 999.00
    void beginTransparentSerial();
    void endTransparentSerial();
    bool setExitTransparentKey(byte EndTransparentChar);  //must after begin()
    bool serialPortAvailable();  //if TransparentSerialAvailable is true, it will return true

	//version1.0.1 add--start
	bool setSleepDelay(unsigned int SleepDelayms);
	//version1.0.1 add--End

    //    bool DigitalCommand(const char * CMD);
   private:
    HardwareSerial * mySerial;
    bool ATCommand(const char * CMD);
    void HandleResponse(String &Resp);
    bool DigitalCommand(const char * CMD);
   //byte SerialNo;
    //byte OnewireID[8];
    byte currentProtocol;
    bool TransparentSerialAvailable;  
    byte EndTransparentChar;     
    int Timeout;    
    boolean SuccessCurrentProtocol;  // it is true When  begin() return true,Or  setCuurentProtocol(byte cuurProtocol)return true  
    String ReturnStr;
};
#endif


