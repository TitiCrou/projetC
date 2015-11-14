#include "CVoiture.h"
#include "Arduino.h"

CVoiture::CVoiture(struct Moteur MG, struct Moteur MD, struct CapteurUs CDR , struct CapteurUs CDV){
		// Moteurs Gauche

		moteursGauche.pinControle1 = MG.pinControle1;
		moteursGauche.pinControle2 = MG.pinControle2;
		moteursGauche.pinEnable = MG.pinEnable;
		moteursGauche.vitesse = MG.vitesse;

		// Moteurs Droit

		moteursDroit.pinControle1 = MD.pinControle1;
		moteursDroit.pinControle2 = MD.pinControle2;
		moteursDroit.pinEnable = MD.pinEnable;
		moteursDroit.vitesse = MD.vitesse;

		// CapteurDevant

		capteurDevant.TRIG = CDV.TRIG;
		capteurDevant.ECHO = CDV.ECHO;

		// CapteurDroit

		capteurDroite.TRIG = CDR.TRIG;
		capteurDroite.ECHO = CDR.ECHO;

		setupUS();


}

CVoiture::CVoiture(struct Moteur MG, struct Moteur MD, int IRGauche, int IRDroit){
		// Moteurs Gauche

		moteursGauche.pinControle1 = MG.pinControle1;
		moteursGauche.pinControle2 = MG.pinControle2;
		moteursGauche.pinEnable = MG.pinEnable;
		moteursGauche.vitesse = MG.vitesse;

		// Moteurs Droit

		moteursDroit.pinControle1 = MD.pinControle1;
		moteursDroit.pinControle2 = MD.pinControle2;
		moteursDroit.pinEnable = MD.pinEnable;
		moteursDroit.vitesse = MD.vitesse;
		
		// Capteurs IR
		IR_Gauche = IRGauche;
		IR_Droit = IRDroit;
		
		setupIR();
}

void CVoiture::setupIR(){
	
		pinMode(moteursGauche.pinControle1, OUTPUT);
		pinMode(moteursGauche.pinControle2, OUTPUT);
		pinMode(moteursGauche.pinEnable, OUTPUT);

		pinMode(moteursDroit.pinControle1, OUTPUT);
		pinMode(moteursDroit.pinControle2, OUTPUT);
		pinMode(moteursDroit.pinEnable, OUTPUT);
		
		pinMode(IR_Gauche,INPUT);
		pinMode(IR_Droit, INPUT);
		
}


int CVoiture:: get_IR_Gauche(){
	return digitalRead(IR_Gauche);
}
int CVoiture:: get_IR_Droit(){
	return digitalRead(IR_Droit);
}
void CVoiture::setupUS(){

		pinMode(moteursGauche.pinControle1, OUTPUT);
		pinMode(moteursGauche.pinControle2, OUTPUT);
		pinMode(moteursGauche.pinEnable, OUTPUT);

		pinMode(moteursDroit.pinControle1, OUTPUT);
		pinMode(moteursDroit.pinControle2, OUTPUT);
		pinMode(moteursDroit.pinEnable, OUTPUT);

		pinMode(capteurDevant.TRIG, OUTPUT);
		pinMode(capteurDevant.ECHO, INPUT);

		pinMode(capteurDroite.TRIG, OUTPUT);
		pinMode(capteurDroite.ECHO, INPUT);

		vitesse=0;
}

void CVoiture::avancer(int vit){
    if (avance ==0){
        digitalWrite(moteursGauche.pinControle1,HIGH);
        digitalWrite(moteursGauche.pinControle2,LOW);
        digitalWrite(moteursDroit.pinControle1,HIGH);
        digitalWrite(moteursDroit.pinControle2,LOW);
      }
    avance =1;
	if (vit==-1){
		if (vitesse <=248){
			vitesse = vitesse + fadeAmount;   
		        analogWrite(moteursGauche.pinEnable,vitesse);
    			analogWrite(moteursDroit.pinEnable,vitesse);
		}
	}
	else {
	    	analogWrite(moteursGauche.pinEnable,vit);
    		analogWrite(moteursDroit.pinEnable,vit);
        vitesse=vit;

	}

}

void CVoiture::reculer(int vit){
  if (avance==1){
        digitalWrite(moteursGauche.pinControle1,LOW);
        digitalWrite(moteursGauche.pinControle2,HIGH);
        digitalWrite(moteursDroit.pinControle1,LOW);
        digitalWrite(moteursDroit.pinControle2,HIGH);
  }
  avance=0; 
  if(vit==-1){
    if(vitesse <=248){
        vitesse = vitesse + fadeAmount;
        analogWrite(moteursGauche.pinEnable,vitesse);
        analogWrite(moteursDroit.pinEnable,vitesse);
    }
  }
  else {
        analogWrite(moteursGauche.pinEnable,vit);
        analogWrite(moteursDroit.pinEnable,vit);
        vitesse=vit;

  }
}

void CVoiture::tournerGauche(int time, unsigned char vit){
	vitesse = vit;
	digitalWrite(moteursDroit.pinEnable,vit);
	digitalWrite(moteursDroit.pinControle1,LOW);
	digitalWrite(moteursDroit.pinControle2,HIGH);

	analogWrite(moteursGauche.pinEnable,vit);
	digitalWrite(moteursGauche.pinControle1,HIGH);
	digitalWrite(moteursGauche.pinControle2,LOW);
	delay(time);
  avance=0;

/*// On remet les états conformes aux états d'arrivés
  if (avance){
      digitalWrite(moteursDroit.pinEnable,vitesse);
      digitalWrite(moteursDroit.pinControle1,HIGH);
      digitalWrite(moteursDroit.pinControle2,LOW);
  }
  else{
      digitalWrite(moteursDroit.pinEnable,vitesse);
      digitalWrite(moteursDroit.pinControle1,LOW);
     digitalWrite(moteursDroit.pinControle2,HIGH);
  }*/
}

void CVoiture::tournerDroite(int time, unsigned char vit){
	vitesse = vit;
	digitalWrite(moteursGauche.pinEnable,vit);
	digitalWrite(moteursGauche.pinControle1,LOW);
	digitalWrite(moteursGauche.pinControle2,HIGH);

	analogWrite(moteursDroit.pinEnable,vit);
	digitalWrite(moteursDroit.pinControle1,HIGH);
	digitalWrite(moteursDroit.pinControle2,LOW);
	delay(time);
  avance=0;
  
 /* // On remet les états conformes aux états d'arrivés
  if (avance){
      digitalWrite(moteursGauche.pinEnable,vitesse);
      digitalWrite(moteursGauche.pinControle1,HIGH);
      digitalWrite(moteursGauche.pinControle2,LOW);
  }
  else {
      digitalWrite(moteursGauche.pinEnable,vitesse);
      digitalWrite(moteursGauche.pinControle1,LOW);
      digitalWrite(moteursGauche.pinControle2,HIGH);
  }*/
}

int CVoiture::get_US_Gauche(){
	int distance_gauche;
	digitalWrite(capteurDevant.TRIG,HIGH);
	delayMicroseconds(10);
    	digitalWrite(capteurDevant.TRIG,LOW);
    	delayMicroseconds(30);
    	distance_gauche=pulseIn(capteurDevant.ECHO, HIGH);
    	distance_gauche=distance_gauche/29/2;
     return distance_gauche;
}

int CVoiture::get_US_Droite(){
	int distance_droite;
	digitalWrite(capteurDroite.TRIG,HIGH);
	delayMicroseconds(10);
    	digitalWrite(capteurDroite.TRIG,LOW);
    	delayMicroseconds(30);
    	distance_droite=pulseIn(capteurDroite.ECHO, HIGH);
    	distance_droite=distance_droite/29/2;
      return distance_droite;
}
