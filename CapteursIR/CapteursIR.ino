#include "Arduino.h"
#include "CVoiture.h"

// Création de l'object
CVoiture * voiture;

void setup() {

  //Création structures

  // Structures moteurs
  struct Moteur MD;
  MD.pinControle1 = 11;
  MD.pinControle2 = 10;
  MD.pinEnable = 6;

  struct Moteur MG;
  MG.pinControle1 = 8;
  MG.pinControle2 = 7;
  MG.pinEnable = 5;

  int IRG = 4;
  int IRD = 9;
  
  voiture = new CVoiture(MG,MD,IRG,IRD); // Constructeur Moteur gauche, moteur droit, capteur droit , capteur devant
}

void loop() {

  int levelG;
  int levelD;

  levelG = voiture->get_IR_Gauche();
  levelD = voiture-> get_IR_Droit();

  if (levelG==1) //Quand on capte le noir sur la ligne gauche
  {
    voiture->tournerGauche(230,90);
  }
  else if (levelD==1) //Quand on capte le noir sur la ligne droite
  {
    voiture->tournerDroite(230,90);
  }
    else{
      voiture->avancer(200); //Impulsion pour entrainer les moteurs
          // Puis ralentir pour avoir une vitesse faible
      voiture->avancer(60);
    }

}
