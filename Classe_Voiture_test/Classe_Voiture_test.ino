#include "Arduino.h"
#include "CVoiture.h"

// Création de l'object
CVoiture * voiture;

void setup() {

  //Création structures

  // Structures moteurs
  struct Moteur MG;
  MG.pinControle1 = 11;
  MG.pinControle2 = 10;
  MG.pinEnable = 6;

  struct Moteur MD;
  MD.pinControle1 = 8;
  MD.pinControle2 = 7;
  MD.pinEnable = 5;

  // Structures capteurs
  struct CapteurUs CDE;
  CDE.TRIG = 12;
  CDE.ECHO = 13;

  struct CapteurUs CDR;
  CDR.TRIG = 2;
  CDR.ECHO = 3;

  voiture = new CVoiture(MG,MD,CDR,CDE); // Constructeur Moteur droit, moteur gauche, capteur droit , capteur devant
}

void loop() {

  voiture->avancer();
  delay(300);
}
