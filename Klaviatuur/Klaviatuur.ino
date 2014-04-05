/*
 * Klaviatuur
 * 
 * Sketš loeb 16-klahviliselt klaviatuurilt skanneerimismeetodi abil vajutatavate klahvide väärtuseid.
 */



byte rows[] = { 1, 2, 3, 4 }; // klemmid, mille küljes on klahvistiku read
byte cols[] = { 5, 6, 7, 8 }; // klemmid, mille küljes on klahvistiku veerud
byte keys[4][4] = {           // klaviatuuri nuppude kaardistus
  { 0xD, 0xE, 0, 0xF },
  { 0xC, 9, 8, 7 },
  { 0xB, 6, 5, 4 },
  { 0xA, 3, 2, 1 }
};



void setup() {

  Serial.begin(9600);

  // seame kõik read väljunditeks ja tõstame nende potentsiaalid üles
  for (int i = 0; i < 4; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH);
  }

  // seame kõik veerud sisenditeks ja tõstame nende potentsiaali samuti üles
  for (int i = 0; i < 4; i++) {
    pinMode(cols[i], INPUT_PULLUP);
  }

}



void loop() {

  // käime kogu klaviatuuri maatriksi läbi, seame ridade potentsiaali ühekaupa
  // madalaks ja vaatame, kas ja millist rida see mõjutas, mille kaudu saame teada,
  // mis klahv alla vajutatud on
  for (byte i = 0; i < 4; i++) {
    digitalWrite(rows[i], LOW);
    for (byte j = 0; j < 4; j++) {
      if (!digitalRead(cols[j])) {
        Serial.println(keys[j][i], HEX); // trükime klahvi kuuetestkümnendväärtuse välja
        delay(300); // siin asemel võib toimuda mingi tegevus
      }
    }
    digitalWrite(rows[i], HIGH);
  }

}

