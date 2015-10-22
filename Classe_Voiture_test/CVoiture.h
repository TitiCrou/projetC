struct Moteur{
		int pinControle1;
		int pinControle2;
		int pinEnable;
};

struct CapteurUs{
		int TRIG;
		int ECHO;
};

class CVoiture{

	public : 
		CVoiture(struct Moteur MG, struct Moteur MD,  struct CapteurUs CDR
+
				,struct CapteurUs CDE);
		void setVitesse(int v){vitesse=v;};
		int getVitesse(){ return vitesse;};
		void tournerGauche(int time, unsigned char speed);
		void tournerDroite(int time, unsigned char speed);
		void reculer();
		void avancer();
		bool avance(){return avance;};
	private :
 		bool avance;
		void setup();
    		unsigned char vitesse;
		int fadeAmount;
		struct Moteur moteursGauche;
		struct Moteur moteursDroit;
		struct CapteurUs capteurDevant;
		struct CapteurUs capteurDroite;

};
