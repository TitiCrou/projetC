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

		setup();


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

		vitesse=0;
}

void CVoiture::avancer(){
		if (vitesse <=255){
			vitesse += fadeAmount;
		}

		digitalWrite(moteursGauche.pinControle1,HIGH);
		digitalWrite(moteursGauche.pinControle2,LOW);
		analogWrite(moteursGauche.pinEnable,vitesse);

		digitalWrite(moteursDroit.pinControle1,HIGH);
		digitalWrite(moteursDroit.pinControle2,LOW);
		analogWrite(moteursDroit.pinEnable,vitesse);

}
