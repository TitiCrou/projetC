struct Moteur{
		int pinControle1;
		int pinControle2;
		int vitesse;
		int pinEnable;
};

struct CapteurUs{
		int TRIG;
		int ECHO;
};

class CVoiture{

	public : 
		CVoiture(struct Moteur MG, struct Moteur MD,  struct CapteurUs CDR
				,struct CapteurUs CDE);
		void setVitesse(int v){vitesse=v;};
		int getVitesse(){ return vitesse;};
		void tourner();
		void reculer();
		void avancer();
	private :
		void setup();
		int vitesse;
		int fadeAmount;
		struct Moteur moteursGauche;
		struct Moteur moteursDroit;
		struct CapteurUs capteurDevant;
		struct CapteurUs capteurDroite;

};
