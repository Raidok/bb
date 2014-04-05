/*
 * Vilgutaja
 * 
 * Vilgutab 7. ja 8. digitaalklemmi külge ühendatud LED-pirni, polaarsus ei ole oluline.
 * Samade klemmide külge võib ühendada ka kaks pirni, üks ühte pidi, teine teist pidi.
 * Sellisel juhul vilguvad pirnid kordamööda. Kaks pirni ühte pidi ühendada pole soovitatav,
 * sest see ületab mikrokontrolleri soovitatava tarbitava voolu (20 mA).
 */

int pin1 = 7;
int pin2 = 8;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void loop() {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  delay(1000);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(1000);
}
