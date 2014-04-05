
/**
 * Patarei pinge mõõtmise sketš
 *
 * Eeldab et analoogklemmi 5 sisend ei ületaks 1,1 V.
 */


void setup() {
  // testimiseks
  Serial.begin(9600);

  // aktiveerime võrdlemisteks sisemise 1,1V pingeallika
  analogReference(INTERNAL);
}


void loop() {
  // loeb analoogklemmi 5 ja tagastab väärtuse vahemikus 0-1023
  int patarei = analogRead(5);

  // trükib tulemuse jadaporti
  Serial.println(patarei);

  // ootab ühe sekundi
  delay(1000);
}

