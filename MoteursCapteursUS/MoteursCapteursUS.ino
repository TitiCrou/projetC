  int TRIGG = 12;
  int ECHOG = 13;
  int TRIGD = 2;
  int ECHOD = 3;
  int MOTEURSG = 6;
  int MOTEURSD = 5;
  long distance_gauche,distance_droite;
  int dist,i;
  int CONTROLED1 =8;  // Control1 MoteurDroit
  int CONTROLED2 =7;  // Control2 MoteurDroit
  int CONTROLEG1 =11;  // Control1 MoteurGauche
  int CONTROLEG2 =10;  // Control2 MoteurGauche
  

void setup() {
    pinMode(ECHOG, INPUT);
    pinMode(TRIGG, OUTPUT);
    pinMode(ECHOD, INPUT);
    pinMode(TRIGD, OUTPUT);    
    pinMode(MOTEURSG, OUTPUT);
    pinMode(MOTEURSD, OUTPUT);
    pinMode(CONTROLEG1, OUTPUT);
    pinMode(CONTROLEG2, OUTPUT);
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

        // On va en marche arrière si obstacle 2 capteurs
      if (distance_gauche <20 && distance_droite < 20){
      digitalWrite(MOTEURSD,HIGH);
      digitalWrite(MOTEURSG,HIGH);
      
      digitalWrite(CONTROLED1, LOW);
      digitalWrite(CONTROLED2, HIGH);

      digitalWrite(CONTROLEG1, LOW);
      digitalWrite(CONTROLEG2, HIGH);

      delay(1000);
      }
    
    //On tourne sur le coté où le mur est le plus proche sinon on avance
    if (distance_droite <20){
        digitalWrite(CONTROLED1, LOW);
        digitalWrite(CONTROLED2, HIGH);
            delay (800);
      }
    //On tourne sur le coté où le mur est le plus proche sinon on avance

    else if (distance_gauche<20){
        digitalWrite(CONTROLEG1, LOW);
        digitalWrite(CONTROLEG2, HIGH);
        delay(500);
    }

    
    else {
      digitalWrite(MOTEURSD,HIGH);
      digitalWrite(MOTEURSG,HIGH);
      digitalWrite(CONTROLED1, HIGH);
      digitalWrite(CONTROLED2, LOW);

      digitalWrite(CONTROLEG1, HIGH);
      digitalWrite(CONTROLEG2, LOW);
      }
    
    

}
