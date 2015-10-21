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
				,struct CapteurUs CDE);
		void setVitesse(int v){vitesse=v;};
		int getVitesse(){ return vitesse;};
		void tourner();
		void reculer();
		void avancer();
	private :
    bool avance=0;
		void setup();
    int vitesse=0;
		int fadeAmount=7;
		struct Moteur moteursGauche;
		struct Moteur moteursDroit;
		struct CapteurUs capteurDevant;
		struct CapteurUs capteurDroite;

};
