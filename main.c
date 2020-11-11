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
      int input_count = 0;
      int display_count = 0;
      int round_input = 1;
      int time_to_check = 0;
      int input_vect[10];
      int end_game = 0;

    // Random Number Generator for Pattern Array
    int pattern[10]; //Array of 10 random numbers between 1:4
    int seed=0; //Seed number for random number generator
    int i;

    seed = analogRead(12); //Taking noise from the unconnected pads to seed the random number generator
    seed = analogRead(7);
    seed = analogRead(9);
    seed = analogRead(10);

    for (i = 0; i < 10; i++){
     pattern[i] = random(1,4); //Fill pattern array with random numbers 1:4
    }

    while(end_game == 0)
    {
      display_count = 0;
      input_count = 0;
      delay(1000);
      while((display_count < round_input) && round_input < 10)
      {
        if(pattern[display_count] == 1)
        {
          CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(85));
          CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(85));
          CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(85));
          delay(500);
          CircuitPlayground.clearPixels();
          delay(500);
        }
        else if (pattern[display_count] == 2)
        {
          CircuitPlayground.setPixelColor(2,255,255,0);
          CircuitPlayground.setPixelColor(3,255,255,0);
          CircuitPlayground.setPixelColor(4,255,255,0);
          delay(500);
          CircuitPlayground.clearPixels();
          delay(500);
        }
        else if (pattern[display_count] == 3)
        {
          CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(170));
          CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(170));
          CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(170));
          delay(500);
          CircuitPlayground.clearPixels();
          delay(500);
        }
        else if (pattern[display_count] == 4)
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
        time_to_check = 1;
      }
      else if (CircuitPlayground.readCap(0) > 300 || CircuitPlayground.readCap(1) > 300)
      {
        CircuitPlayground.setPixelColor(2,255,255,0);
        CircuitPlayground.setPixelColor(3,255,255,0);
        CircuitPlayground.setPixelColor(4,255,255,0);
        delay(500);
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 2;
        time_to_check = 1;
      }
      else if (CircuitPlayground.readCap(12) > 285 || CircuitPlayground.readCap(6) > 285)
      {
        CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(170));
        CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(170));
        CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(170));
        delay(500);
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 3;
        time_to_check = 1;
      }
      else if (CircuitPlayground.readCap(9) > 285 || CircuitPlayground.readCap(10) > 285)
      {
        CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(0));
        CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(0));
        CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(0));
        delay(500);
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 4;
        time_to_check = 1;
      }
      if (time_to_check == 1 && input_vect[input_count] != pattern[input_count])
        {
          CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(3,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(4,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(0));
          delay(1000);
          CircuitPlayground.clearPixels();
          if (pattern[input_count] == 1)
          {
            for (int j = 0; j < 3; ++j)
            {
              CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(85));
              CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(85));
              CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(85));
              delay(250);
              CircuitPlayground.clearPixels();
              delay(250);
            }
          }
          else if (pattern[input_count] == 2)
          {
            for (int j = 0; j < 3; ++j)
            {
              CircuitPlayground.setPixelColor(2,255,255,0);
              CircuitPlayground.setPixelColor(3,255,255,0);
              CircuitPlayground.setPixelColor(4,255,255,0);
              delay(250);
              CircuitPlayground.clearPixels();
              delay(250);
            }
          }
          else if (pattern[input_count] == 3)
          {
            for (int j = 0; j < 3; ++j)
            {
              CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(170));
              CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(170));
              CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(170));
              delay(250);
              CircuitPlayground.clearPixels();
              delay(250);
            }
          }
          else if (pattern[input_count] == 4)
          {
            for (int j = 0; j < 3; ++j)
            {
              CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(0));
              CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(0));
              CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(0));
              delay(250);
              CircuitPlayground.clearPixels();
              delay(250);
            }
          }
          end_game = 1;
          break;
        }
        else if (time_to_check == 1 && input_vect[input_count] == pattern[input_count])
        {
        ++input_count;
        time_to_check = 0;
        }
      }
      round_input = round_input + 1;
    }
  }
  }
}
