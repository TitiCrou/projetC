
int vitesse = 0;    // how bright the LED is
int fadeAmount = 7 ;    // how many points to fade the LED by
int CONTROLED1 =8;  // Control1 MoteurDroit
int CONTROLED2 =7;  // Control2 MoteurDroit
int MOTEURSD = 5;
int TRIGG = 12;
int ECHOG = 13;
int TRIGD = 2;
int ECHOD = 3;
long distance_gauche,distance_droite;
int MOTEURSG = 6;
int CONTROLEG1 =11;  // Control1 MoteurGauche
int CONTROLEG2 =10;  // Control2 MoteurGauche

void start(){
  
  }

void setup() {
  
    pinMode(ECHOG, INPUT);
    pinMode(TRIGG, OUTPUT);
    pinMode(MOTEURSD, OUTPUT);
    pinMode(CONTROLED1, OUTPUT);
    pinMode(CONTROLED2, OUTPUT);
}


void loop() {
      // Calcul distance à gauche
    digitalWrite(TRIGG,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGG,LOW);
    delayMicroseconds(30);
    distance_gauche=pulseIn(ECHOG, HIGH);
    distance_gauche=distance_gauche/29/2;

    
    // Calcul distance à droite
    digitalWrite(TRIGD,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGD,LOW);
    delayMicroseconds(30);
    distance_droite=pulseIn(ECHOD, HIGH);
    distance_droite=distance_droite/29/2;

    analogWrite(MOTEURSG, vitesse); 
    analogWrite(MOTEURSD, vitesse);
    digitalWrite(CONTROLED1, HIGH);
    digitalWrite(CONTROLED2, LOW);
    digitalWrite(CONTROLEG1, HIGH);
    digitalWrite(CONTROLEG2, LOW);         

    
    if ( vitesse <=250){
        vitesse = vitesse + fadeAmount;
    }

    
    if (distance_gauche <20) {
        vitesse =0;
    }
    // wait for 30 milliseconds to see the dimming
    // effect
    delay(30);
}
