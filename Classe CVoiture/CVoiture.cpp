#include "CVoiture.h"

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

void CVoiture::avancer(int vitesse=-1){
    if (avance ==0){
        digitalWrite(moteursGauche.pinControle1,HIGH);
        digitalWrite(moteursGauche.pinControle2,LOW);
        digitalWrite(moteursDroit.pinControle1,HIGH);
        digitalWrite(moteursDroit.pinControle2,LOW);
      }
    avance =1;
	if (vitesse!=-1){
		if (vitesse <=248){
			vitesse = vitesse + fadeAmount;   
		        analogWrite(moteursGauche.pinEnable,vitesse);
    			analogWrite(moteursDroit.pinEnable,vitesse);
		}
	}
	else {
		analogWrite(moteursGauche.pinEnable,vitesse);
    		analogWrite(moteursDroit.pinEnable,vitesse);

	}

}

void CVoiture::reculer(int vitesse=-1){
  if (avance==1){
        digitalWrite(moteursGauche.pinControle1,LOW);
        digitalWrite(moteursGauche.pinControle2,HIGH);
        digitalWrite(moteursDroit.pinControle1,LOW);
        digitalWrite(moteursDroit.pinControle2,HIGH);
  }
  avance=0; 
  if(vitesse!=-1){
    if(vitesse <=248){
        vitesse = vitesse + fadeAmount;
        analogWrite(moteursGauche.pinEnable,vitesse);
        analogWrite(moteursDroit.pinEnable,vitesse);
    }
  }
  else {
   analogWrite(moteursGauche.pinEnable,vitesse);
        analogWrite(moteursDroit.pinEnable,vitesse);

  }
}

void CVoiture::tournerGauche(int time, unsigned char speed){
	vitesse = speed;
	digitalWrite(moteursDroit.pinEnable,LOW);
	digitalWrite(moteursDroit.pinControle1,LOW);
	digitalWrite(moteursDroit.pinControle2,LOW);

	analogWrite(moteursGauche.pinEnable,speed);
	digitalWrite(moteursGauche.pinControle1,HIGH);
	digitalWrite(moteursGauche.pinControle2,LOW);
	delay(time);
}

void CVoiture::tournerDroite(int time, unsigned char speed){
	vitesse = speed;
	digitalWrite(moteursGauche.pinEnable,LOW);
	digitalWrite(moteursGauche.pinControle1,LOW);
	digitalWrite(moteursGauche.pinControle2,LOW);

	analogWrite(moteursDroit.pinEnable,speed);
	digitalWrite(moteursDroit.pinControle1,HIGH);
	digitalWrite(moteursDroit.pinControle2,LOW);
	delay(time);
}