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
    /*
    //Calcul distance devant
    distance_devant=getDistanceDevant();

    // Calcul distance à droite
    distance_droite=getDistanceDroite();
    
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
    }*/
    /*creneau(1, 150);
    delay(5000);
    */
    murDroit();
}

long getDistanceDevant(){
    digitalWrite(TRIGG,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGG,LOW);
    delayMicroseconds(30);
    distance_devant=pulseIn(ECHOG, HIGH);
    return distance_devant/58;
}

long getDistanceDroite(){
    digitalWrite(TRIGD,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGD,LOW);
    delayMicroseconds(30);
    distance_droite=pulseIn(ECHOD, HIGH);
    return distance_droite/58;
}

void tourneDroite(int speed, int time){
  digitalWrite(CONTROLED1, LOW);
  digitalWrite(CONTROLED2, HIGH);
  digitalWrite(CONTROLEG1, HIGH);
  digitalWrite(CONTROLEG2, LOW);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
  delay(time);
  digitalWrite(CONTROLED1, HIGH);
  digitalWrite(CONTROLED2, LOW);
  digitalWrite(CONTROLEG1, HIGH);
  digitalWrite(CONTROLEG2, LOW);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
}


void tourneGauche(int speed, int time){
  digitalWrite(CONTROLED1, HIGH);
  digitalWrite(CONTROLED2, LOW);
  digitalWrite(CONTROLEG1, LOW);
  digitalWrite(CONTROLEG2, HIGH);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
  delay(time);
  digitalWrite(CONTROLED1, HIGH);
  digitalWrite(CONTROLED2, LOW);
  digitalWrite(CONTROLEG1, HIGH);
  digitalWrite(CONTROLEG2, LOW);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
}

void tourneArriereDroite(int speed, int time){
  digitalWrite(CONTROLED1, LOW);
  digitalWrite(CONTROLED2, HIGH);
  digitalWrite(CONTROLEG1, LOW);
  digitalWrite(CONTROLEG2, HIGH);
  analogWrite(MOTEURSD, 0);
  analogWrite(MOTEURSG, speed);
  delay(time);
}


void tourneArriereGauche(int speed, int time){
  digitalWrite(CONTROLED1, LOW);
  digitalWrite(CONTROLED2, HIGH);
  digitalWrite(CONTROLEG1, LOW);
  digitalWrite(CONTROLEG2, HIGH);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, 0);
  delay(time);
}

void avance(int speed, int time){
  digitalWrite(CONTROLED1, HIGH);
  digitalWrite(CONTROLED2, LOW);
  digitalWrite(CONTROLEG1, HIGH);
  digitalWrite(CONTROLEG2, LOW);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
  delay(time);
}

void recule(int speed, int time){
  digitalWrite(CONTROLED1, LOW);
  digitalWrite(CONTROLED2, HIGH);
  digitalWrite(CONTROLEG1, LOW);
  digitalWrite(CONTROLEG2, HIGH);
  analogWrite(MOTEURSD, speed);
  analogWrite(MOTEURSG, speed);
  delay(time);
}

void stopMoteurs(){
  analogWrite(MOTEURSD, 0);
  analogWrite(MOTEURSG, 0);
}

void creneau(int direction, int speed){
  // 0 à gauche, 1 à droite
  if (direction = 1){
    recule(speed, 300);
    delay(50);
    tourneArriereDroite(speed, 1000);
    delay(50);
    recule(speed, 500);
    delay(50);
    tourneArriereGauche(speed, 1400);
    delay(50);
    avance(speed, 500);
    stopMoteurs();
  } else {
    recule(speed, 300);
    delay(50);
    tourneArriereGauche(speed, 1000);
    delay(50);
    recule(speed, 500);
    delay(50);
    tourneArriereDroite(speed, 1400);
    delay(50);
    avance(speed, 500);
    stopMoteurs();
  }
}

void murDroit(){
    distance_droite=getDistanceDroite();

    if (distance_droite>=10 && distance_droite<=15){
      avance(250, 0);
    } else if (distance_droite < 10){
      tourneGauche(250, 100);
      delay(100);
      tourneDroite(250, 100);
    } else if (distance_droite > 15){
      tourneDroite(250, 100);
      delay(100);
      tourneGauche(250, 100);
    }
}

