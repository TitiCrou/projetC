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
		CVoiture(struct Moteur MG, struct Moteur MD, int IRGauche, int IRDroit);
		void setVitesse(int v){vitesse=v;};
		int getVitesse(){ return vitesse;};
		void tournerGauche(int time, unsigned char speed);
		void tournerDroite(int time, unsigned char speed);
		void reculer(int vitesse);
		void avancer(int vitesse);
		int get_IR_Gauche();
		int get_IR_Droit();
		bool avance(){return avance;};
	private :
		bool avance;
		int IR_Gauche;
		int IR_Droit;
		void setupUS();
		void setupIR();
		unsigned char vitesse;
		int fadeAmount;
		struct Moteur moteursGauche;
		struct Moteur moteursDroit;
		struct CapteurUs capteurDevant;
		struct CapteurUs capteurDroite;

};
