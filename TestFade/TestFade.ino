
int vitesse = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int CONTROLED1 =8;  // Control1 MoteurDroit
int CONTROLED2 =7;  // Control2 MoteurDroit
int MOTEURSD = 5;


void setup() {
 
    pinMode(MOTEURSD, OUTPUT);
    pinMode(CONTROLED1, OUTPUT);
    pinMode(CONTROLED2, OUTPUT);
}


void loop() {

    analogWrite(MOTEURSD, vitesse);

    vitesse = vitesse + fadeAmount;

    // reverse the direction of the fading at the ends of
    // the fade:
    if (vitesse == 0 || vitesse == 255) {
        fadeAmount = -fadeAmount ;
    }
    // wait for 30 milliseconds to see the dimming
    // effect
    delay(30);
}
