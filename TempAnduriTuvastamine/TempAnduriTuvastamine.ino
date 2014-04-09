/*
 * Temperatuurianduri DS18B20 tuvastamine
 *
 * Leiab digitallklemmi 3 külge kinnitatud temperatuurianduri(te) aadressi(d) ja arvutab välja nende mõõtmistulemused.
 */



#include <OneWire.h>

OneWire ds(3);



void setup() {
  Serial.begin(9600);
}



void loop() {
  byte i;
  byte present = 0;
  byte done = 0;
  byte data[12];
  byte addr[8];

  while ( !done ) {
    if ( ds.search(addr) != 1) {
      ds.reset_search();
      done = 1;
      return;
    } else {
      // trükime välja anduri aadressi
      for( i = 1; i < 7; i++) {
        Serial.print(addr[i], HEX);
        Serial.print(":");
      }
      Serial.print(" ");
      // pärime temperatuuri ja trükime selle välja
      Serial.print(temperatuur(addr));
      Serial.println();
    }
    delay(1000);
  }
}

// andes ette anduri aadressi, tagastab see funtsioon temperatuuri
float temperatuur(uint8_t* addr) {
  byte i;
  byte data[12];
  int temp;
  // leiame anduri üles
  ds.search(addr);
  // alustame mõõtmist
  ds.write(0x44, 0); // parasiittoite välja lülitamine
  //delay(850); // vajalik ainult parasiittoitega
  ds.reset();
  ds.select(addr);
  // anduri registri lugemise käsklus
  ds.write(0xBE);
  // võtame vastu 9 baiti andmeid
  for ( i = 0; i < 9; i++) {
    data[i] = ds.read();
  }
  ds.reset_search();
  // paneme need kokku
  temp = ( (data[1] << 8) + data[0] );
  // kontrollime, kas väärtus on negatiivne
  if (temp & 0x8000) {
    // komplementaarväärtus
    temp = (temp ^ 0xffff) + 1;
    temp |= 0x8000; // sätime esimese biti kõrgeks
  }
  // arvutame väärtuse celsiuse kraadides
  float temperatuur = (float)temp / 16;
  return temperatuur; // tagastame tulemuse
}
