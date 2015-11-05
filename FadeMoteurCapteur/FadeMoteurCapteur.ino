
int vitesse = 0;    // how bright the LED is
int fadeAmount = 7 ;    // how many points to fade the LED by
int CONTROLED1 =8;  // Control1 MoteurDroit
int CONTROLED2 =7;  // Control2 MoteurDroit
int MOTEURSD = 5;
int TRIGDevant = 12;
int ECHODevant = 13;
int TRIGD = 2;
int ECHOD = 3;
long distance_devant,distance_droite;
int MOTEURSG = 6;
int CONTROLEG1 =11;  // Control1 MoteurGauche
int CONTROLEG2 =10;  // Control2 MoteurGauche

void avancer(){
    analogWrite(MOTEURSG, vitesse); 
    analogWrite(MOTEURSD, vitesse);
    digitalWrite(CONTROLED1, HIGH);
    digitalWrite(CONTROLED2, LOW);
    digitalWrite(CONTROLEG1, HIGH);
    digitalWrite(CONTROLEG2, LOW);     
  }

  
void reculer(){
    analogWrite(MOTEURSG, vitesse); 
    analogWrite(MOTEURSD, vitesse);
    digitalWrite(CONTROLED1, LOW);
    digitalWrite(CONTROLED2, HIGH);
    digitalWrite(CONTROLEG1, LOW);
    digitalWrite(CONTROLEG2, HIGH);     
  }


void setup() {  
    pinMode(ECHODevant, INPUT);
    pinMode(TRIGDevant, OUTPUT);
    pinMode(MOTEURSD, OUTPUT);
    pinMode(CONTROLED1, OUTPUT);
    pinMode(CONTROLED2, OUTPUT);
    pinMode(MOTEURSG, OUTPUT);
    pinMode(CONTROLEG1, OUTPUT);
    pinMode(CONTROLEG2, OUTPUT);    
    pinMode(ECHOD, INPUT);
    pinMode(TRIGD, OUTPUT);
}


void loop() {
      // Calcul distance devant
    digitalWrite(TRIGDevant,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGDevant,LOW);
    delayMicroseconds(30);
    distance_devant=pulseIn(ECHODevant, HIGH);
    distance_devant=distance_devant/29/2;

    
    // Calcul distance à droite
    digitalWrite(TRIGD,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGD,LOW);
    delayMicroseconds(30);
    distance_droite=pulseIn(ECHOD, HIGH);
    distance_droite=distance_droite/29/2;
          
    vitesse= 150;
    avancer();
    delay(2000);
    if (distance_droite <30){
     reculer();
     delay(2000);
    }

    if (distance_devant<30){
      reculer();
      delay(2000);
    }

    
}
