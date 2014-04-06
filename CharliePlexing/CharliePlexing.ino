
/* 
 * CharliePlexing
 *
 * Näide, kuidas CharliePlexing-meetodi abil vähemate klemmidega rohkem valgusdioode juhtida saab.
 */



#define KLEMME 3
#define PIRNE 6

const byte klemmid[KLEMME] = { 6, 7, 8 };
const byte anoodid[PIRNE] = { 7, 6, 8, 6, 8, 7 };
const byte katoodid[PIRNE] = { 6, 7, 6, 8, 7, 8 };

byte suund = 0, p = 0;



void setup () {
  // tühi
}



void loop() {
  
  // muudame pirnilt pirnile liikumise suunda peale 0. ja 5. pirni vilgutamist
  if (p == PIRNE - 1) suund = -1;
  if (p == 0) suund = 1;
  
  on(p); // lülitame pirni sisse
  
  delay(100); // viidame veidi aega
  
  off(p); // kustutame pirni ära

  p += suund; // liigume järgmise pirni juurde

}



// pirni sisselülitamise funtsioon, esimene pirn on 0, teine 1 jne
void on(byte pirn) {
  pinMode(anoodid[pirn], OUTPUT);
  digitalWrite(anoodid[pirn], HIGH);
  pinMode(katoodid[pirn], OUTPUT);
}

// pirni välja lülitamiseks indeksi järgi
void off(byte pirn) {
  pinMode(anoodid[pirn], INPUT);
  pinMode(katoodid[pirn], INPUT);
}

// pirni välja lülitamiseks ilma indeksita
void off() {
  for (int i = 0; i < KLEMME; i++) {
    pinMode(klemmid[i], INPUT);
  }
}

