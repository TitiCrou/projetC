  int TRIGG = 12;
  int ECHOG = 13;
  int TRIGD = 2;
  int ECHOD = 3;
  int MOTEURSG = 6;
  int MOTEURSD = 5;
  int vitesse = 0;  // how bright the LED is
  int fadeAmount = 7;  // how many points to fade the LED by
  long distance_devant,distance_droite;
  int dist,i;
  int CONTROLED1 =8;  // Control1 MoteurDroit
  int CONTROLED2 =7;  // Control2 MoteurDroit
  int CONTROLEG1 =11;  // Control1 MoteurGauche
  int CONTROLEG2 =10;  // Control2 MoteurGauche
  

void setup() {
    pinMode(MOTEURSG, OUTPUT);
    pinMode(MOTEURSD, OUTPUT);
    pinMode(CONTROLED1, OUTPUT);
    pinMode(CONTROLED2, OUTPUT);
    pinMode(CONTROLEG1, OUTPUT);
    pinMode(CONTROLEG2, OUTPUT);
    pinMode(TRIGD, OUTPUT);
    pinMode(ECHOD, INPUT);
    pinMode(ECHOG, INPUT);
    pinMode(TRIGG, OUTPUT);
}

void loop() {

    //Calcul distance devant
    digitalWrite(TRIGG,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGG,LOW);
    delayMicroseconds(30);
    distance_devant=pulseIn(ECHOG, HIGH);
    distance_devant=distance_devant/58;

    // Calcul distance à droite
    digitalWrite(TRIGD,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGD,LOW);
    delayMicroseconds(30);
    distance_droite=pulseIn(ECHOD, HIGH);
    distance_droite=distance_droite/58;

    analogWrite(MOTEURSG, vitesse); 
    analogWrite(MOTEURSD, vitesse);
    digitalWrite(CONTROLED1, HIGH);
    digitalWrite(CONTROLED2, LOW);
    digitalWrite(CONTROLEG1, HIGH);
    digitalWrite(CONTROLEG2, LOW);
  
    if (distance_devant >30 && distance_droite >30){
      if (vitesse <= 250) {
        vitesse += fadeAmount;
      }
      digitalWrite(CONTROLED1, HIGH);
      digitalWrite(CONTROLED2, LOW);
      digitalWrite(CONTROLEG1, HIGH);
      digitalWrite(CONTROLEG2, LOW);
      analogWrite(MOTEURSD,vitesse);
      analogWrite(MOTEURSG,vitesse);
    } else if (distance_devant <=30 && distance_droite >30){
        tourneDroite(175);
    } else if (distance_devant <=30 && distance_droite <=30){
        tourneGauche(175);
    }
}


void tourneDroite(int speed){
  digitalWrite(CONTROLED1, LOW);
  digitalWrite(CONTROLED2, HIGH);
  digitalWrite(CONTROLEG1, HIGH);
  digitalWrite(CONTROLEG2, LOW);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
  delay(200);
  digitalWrite(CONTROLED1, HIGH);
  digitalWrite(CONTROLED2, LOW);
  digitalWrite(CONTROLEG1, HIGH);
  digitalWrite(CONTROLEG2, LOW);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
}


void tourneGauche(int speed){
  digitalWrite(CONTROLED1, HIGH);
  digitalWrite(CONTROLED2, LOW);
  digitalWrite(CONTROLEG1, LOW);
  digitalWrite(CONTROLEG2, HIGH);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
  delay(200);
  digitalWrite(CONTROLED1, HIGH);
  digitalWrite(CONTROLED2, LOW);
  digitalWrite(CONTROLEG1, HIGH);
  digitalWrite(CONTROLEG2, LOW);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
}
