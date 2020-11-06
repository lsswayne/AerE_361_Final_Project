#include <Adafruit_CircuitPlayground.h>

uint8_t pixeln = -1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (1==1){
  if (CircuitPlayground.leftButton()&&CircuitPlayground.rightButton()){
    CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(3,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(4,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(85));
    CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(85));
    delay(1000);
    CircuitPlayground.clearPixels();
    while(1==1)
    {
      int input_count = 0;
      int display_count = 0;
      int round_input = 4;
      int check_input[4];
      int input_vect[10];
  
      check_input[0] = 1;
      check_input[1] = 2;
      check_input[2] = 3;
      check_input[3] = 4;
      while(display_count <= (round_input+1))
      {
        if(check_input[display_count] == 1)
        {
          CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(85));
          CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(85));
          CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(85));
          delay(500);
          CircuitPlayground.clearPixels();
          delay(500);
        }
        else if (check_input[display_count] == 2)
        {
          CircuitPlayground.setPixelColor(2,255,255,0);
          CircuitPlayground.setPixelColor(3,255,255,0);
          CircuitPlayground.setPixelColor(4,255,255,0);
          delay(500);
          CircuitPlayground.clearPixels();
          delay(500);
        }
        else if (check_input[display_count] == 3)
        {
          CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(170));
          CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(170));
          CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(170));
          delay(500);
          CircuitPlayground.clearPixels();
          delay(500);
        }
        else if (check_input[display_count] == 4)
        {
          CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(0));
          delay(500);
          CircuitPlayground.clearPixels();
          delay(500);
        }
        ++display_count;
      }
      
      while(input_count < round_input)
      {
      if (CircuitPlayground.readCap(3) > 285 || CircuitPlayground.readCap(2) > 285)
      {
        CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(85));
        CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(85));
        CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(85));
        delay(500);
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 1;
        ++input_count;
      }
      else if (CircuitPlayground.readCap(0) > 300 || CircuitPlayground.readCap(1) > 300)
      {
        CircuitPlayground.setPixelColor(2,255,255,0);
        CircuitPlayground.setPixelColor(3,255,255,0);
        CircuitPlayground.setPixelColor(4,255,255,0);
        delay(500);
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 2;
        ++input_count;
      }
      else if (CircuitPlayground.readCap(12) > 285 || CircuitPlayground.readCap(6) > 285)
      {
        CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(170));
        CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(170));
        CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(170));
        delay(500);
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 3;
        ++input_count;
      }
      else if (CircuitPlayground.readCap(9) > 285 || CircuitPlayground.readCap(10) > 285)
      {
        CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(0));
        CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(0));
        CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(0));
        delay(500);
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 4;
        ++input_count;
      }
      }
    }
  }

  
  if (CircuitPlayground.leftButton()){
    CircuitPlayground.clearPixels();
    pixeln = pixeln + 1;
    CircuitPlayground.setPixelColor(pixeln,CircuitPlayground.colorWheel(25*pixeln));
    delay(250);
  }
  if (CircuitPlayground.rightButton()){
    CircuitPlayground.clearPixels();
    pixeln = pixeln -1;
    CircuitPlayground.setPixelColor(pixeln,CircuitPlayground.colorWheel(25*pixeln));
    delay(250);
  }
  }
//  if (pixeln == 11) {
//    pixeln = 0;
//    CircuitPlayground.clearPixels();
//  }
//  delay(10);
}
