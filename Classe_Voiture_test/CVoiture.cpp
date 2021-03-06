#include "CVoiture.h"
#include "Arduino.h"
CVoiture::CVoiture(struct Moteur MG, struct Moteur MD, struct CapteurUs CDR , struct CapteurUs CDV){
		// Moteurs Gauche

		moteursGauche.pinControle1 = MG.pinControle1;
		moteursGauche.pinControle2 = MG.pinControle2;
		moteursGauche.pinEnable = MG.pinEnable;


		// Moteurs Droit

		moteursDroit.pinControle1 = MD.pinControle1;
		moteursDroit.pinControle2 = MD.pinControle2;
		moteursDroit.pinEnable = MD.pinEnable;

		// CapteurDevant

		capteurDevant.TRIG = CDV.TRIG;
		capteurDevant.ECHO = CDV.ECHO;

		// CapteurDroit

		capteurDroite.TRIG = CDR.TRIG;
		capteurDroite.ECHO = CDR.ECHO;

		this->setup();
		vitesse =0;
		avance =0;
		fadeAmount=7;

}

void CVoiture::setup(){

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
}

void CVoiture::avancer(){
    if (avance ==0){
        digitalWrite(moteursGauche.pinControle1,HIGH);
        digitalWrite(moteursGauche.pinControle2,LOW);
        digitalWrite(moteursDroit.pinControle1,HIGH);
        digitalWrite(moteursDroit.pinControle2,LOW);
      }
    avance =1;
		if (vitesse <=248){
			vitesse = vitesse + fadeAmount;   
		        analogWrite(moteursGauche.pinEnable,vitesse);
    			analogWrite(moteursDroit.pinEnable,vitesse);
		}


}

void CVoiture::tournerGauche(int time, int speed){
	vitesse = speed;
	digitalWrite(moteursDroit.pineEnable,LOW);
	digitalWrite(moteursDroit.pinControle1,LOW);
	digitalWrite(moteursDroit.pinControle2,LOW);

	analogWrite(moteursGauche.pinEnable,speed);
	digitalWrite(moteursGauche.pinControle1,HIGH);
	digitalWrite(moteursGauche.pinControle2,LOW);
	delay(time);
}

void CVoiture::tournerDroite(int time, int speed){
	vitesse = speed;
	digitalWrite(moteursGauche.pinEnable,LOW);
	digitalWrite(moteursGauche.pinControle1,LOW);
	digitalWrite(moteursGauche.pinControle2,LOW);

	analogWrite(moteursDroit.pinEnable,speed);
	digitalWrite(moteursDroit.pinControle1,HIGH);
	digitalWrite(moteursDroit.pinControle2,LOW);
	delay(time);
}
