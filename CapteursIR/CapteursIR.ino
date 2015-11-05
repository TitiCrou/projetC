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

  int IRG = 4;
  int IRD = 9;
  
  voiture = new CVoiture(MG,MD,IRG,IRD); // Constructeur Moteur gauche, moteur droit, capteur droit , capteur devant
}

void loop() {

  int levelG;
  int levelD;

  levelG = voiture->get_IR_Gauche();
  levelD = voiture-> get_IR_Droit();

  if (levelG==0) //Quand on capte le noir sur la ligne gauche
  {
    voiture->tournerGauche(300,120);
    voiture->tournerDroite(300,110);
    }
    else if (levelD==0) //Quand on capte le noir sur la ligne gauche
    {
      voiture->tournerDroite(300,120);
      voiture->tournerGauche(300,110);
    }
    else voiture->reculer();

}
