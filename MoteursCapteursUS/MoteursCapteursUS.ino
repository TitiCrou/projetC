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
  
    voiture = new CVoiture(MG,MD,CDR,CDE); // Constructeur Moteur gauche, moteur droit, capteur droit , capteur devant
}

void loop() {

    int distance_gauche ,distance_droite ;
    distance_gauche=voiture->get_US_Gauche();
    distance_droite=voiture->get_US_Droite();

       voiture->avancer(150);
        // On va en marche arrière si obstacle 2 capteurs
    if (distance_gauche <20 && distance_droite < 20){
        voiture->reculer(200);
        delay(500);
    }  
    //On tourne sur le coté où le mur est le plus proche sinon on avance
    else if (distance_droite <15){
        voiture->tournerGauche(200,150);
       
    }
    //On tourne sur le coté où le mur est le plus proche sinon on avance
    else if (distance_gauche<15){
        voiture->tournerDroite(200,150);
       
    }

    
   

  /*  if (distance_gauche < 20)
      voiture->avancer(0);
    else if (distance_droite < 20)
      voiture->avancer(0);
    else voiture->avancer(150);*/
}
