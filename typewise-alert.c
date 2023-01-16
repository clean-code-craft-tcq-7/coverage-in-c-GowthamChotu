#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  (coolingType == PASSIVE_COOLING) ? upperLimit = 35 : ((coolingType == HI_ACTIVE_COOLING) ? upperLimit = 45 :upperLimit = 40);
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  Email(breachType);
}

void Email(BreachType breachType) {
  
  if(breachType == TOO_LOW)
  {
    printf("Hi, the temperature is too low\n");
  }
  else if(breachType == TOO_HIGH)
  {
    printf("Hi, the temperature is too high\n");
  }
  else
  {
    printf("Hi, the temperature is Normal\n");
  }
}

