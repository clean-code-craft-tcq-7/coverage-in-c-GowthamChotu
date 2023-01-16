#pragma once

typedef enum {
  PASSIVE_COOLING=0,
  HI_ACTIVE_COOLING=1,
  MED_ACTIVE_COOLING=2
} CoolingType;

typedef enum {
  NORMAL=0,
  TOO_LOW=1,
  TOO_HIGH=2
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER=0,
  TO_EMAIL=1
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

void Email(BreachType breachType);
