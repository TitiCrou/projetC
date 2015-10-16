  int TRIGG = 12;
  int ECHOG = 13;
  int TRIGD = 2;
  int ECHOD = 3;
  int MOTEURSG = 6;
  int MOTEURSD = 5;
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

    digitalWrite(CONTROLED1, HIGH);
    digitalWrite(CONTROLED2, LOW);
    digitalWrite(CONTROLEG1, HIGH);
    digitalWrite(CONTROLEG2, LOW);
  
    if (distance_droite >30 && distance_devant >30){
      for (int i=100; i<200; i+=20){
        digitalWrite(CONTROLED1, HIGH);
        digitalWrite(CONTROLED2, LOW);
        digitalWrite(CONTROLEG1, HIGH);
        digitalWrite(CONTROLEG2, LOW);
        analogWrite(MOTEURSD,i);
        analogWrite(MOTEURSG,i);
        delay(100);
      }
      
      //delay(1000);
    } else {
      digitalWrite(CONTROLED1, LOW);
      digitalWrite(CONTROLED2, HIGH);
      digitalWrite(CONTROLEG1, LOW);
      digitalWrite(CONTROLEG2, HIGH);

      for (int i=200; i>=100; i-=20){
        analogWrite(MOTEURSD,i);
        analogWrite(MOTEURSG,i);
        delay(100);
      }
    }
 

}
