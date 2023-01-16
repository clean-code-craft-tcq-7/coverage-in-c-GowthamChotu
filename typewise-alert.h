#pragma once

typedef enum {
  PASSIVE_COOLING = 0,
  HI_ACTIVE_COOLING = 1,
  MED_ACTIVE_COOLING = 2
} CoolingType;

typedef enum {
  NORMAL = 0,
  TOO_LOW = 1,
  TOO_HIGH = 2
} BreachType;

typedef enum {
  TO_CONTROLLER = 0,
  TO_EMAIL = 1
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef struct{
  int lowerLimit;
  int upperLimit;
} coolingLimitType;

typedef struct {
  int normal;
  int too_low;
  int too_high;
} breachStructType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
