
int vitesse = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int CONTROLED1 =8;  // Control1 MoteurDroit
int CONTROLED2 =7;  // Control2 MoteurDroit
int MOTEURSD = 5;
int TRIGG = 12;
int ECHOG = 13;
long distance_gauche;

void setup() {
 
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
    
    analogWrite(MOTEURSD, vitesse);         
    digitalWrite(CONTROLED1, LOW);
    digitalWrite(CONTROLED2, HIGH);
    
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
