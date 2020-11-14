#include <Adafruit_CircuitPlayground.h>

uint8_t pixeln = -1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(2));

  CircuitPlayground.begin();
}

void loop() {
  while (1==1){ //Continuous loop that checks for the beginning of a game
  
  if (CircuitPlayground.leftButton()&&CircuitPlayground.rightButton()){ //Indicating the beginning of a game
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

    //Begin game sounds
    CircuitPlayground.playTone(262, 200); //C4
    CircuitPlayground.playTone(220, 100); //A3
    CircuitPlayground.playTone(262, 100); //C4
    CircuitPlayground.playTone(392, 100); //G4
    delay(500);
    CircuitPlayground.clearPixels();
    
    //Defining Variables
      int input_count = 0;
      int display_count = 0;
      int round_input = 1;
      int time_to_check = 0;
      int input_vect[20];
      int end_game = 0;
      int win_condition = 0;
      //Time Variables
      float display_time = 500;  //Default display time is 500 milliseconds
      float max_display_time = 500; //Maximum time the color of the pattern will be displayed.  Also is the length of the break afterwards
      float min_display_time = 100; //Minimum time the color of the pattern will be displayed.  Also is the length of the break afterwards
    
    //Set Difficulty
      int game_length = 10 + selected_difficulty; //defult game length is 11 rounds

    // Random Number Generator for Pattern Array
    int pattern[20]; //Array of 20 random numbers between 1:4

    for (int i = 0; i < game_length; i++){
      //pattern[i] = 1; //for testing purposes
     pattern[i] = random(1,5); //Fill pattern array with random numbers 1:4 upper bound is exclusive
    }

    while(end_game == 0 && win_condition == 0) //Loop that runs while the game is progressing (ie not won or lost)
    {
      display_count = 0;
      input_count = 0;
      
      delay(1000);
      
      while((display_count < round_input) && round_input <= game_length) //Loop to display the pattern to the user
      {
        // Set Display Time Based on Game Length
        display_time = min_display_time + (max_display_time - min_display_time)*(((double)game_length - (double)round_input)/((double)game_length - 1.0)); //Decrease display_time based on the round number
        
        if(pattern[display_count] == 1) //Quadrant 1: Green
        {
          CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(85));
          CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(85));
          CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(85));
          CircuitPlayground.playTone(196, display_time); //G4
          CircuitPlayground.clearPixels();
          delay(display_time);
        }
        else if (pattern[display_count] == 2) //Quadrant 2: Yellow
        {
          CircuitPlayground.setPixelColor(2,255,255,0);
          CircuitPlayground.setPixelColor(3,255,255,0);
          CircuitPlayground.setPixelColor(4,255,255,0);
          CircuitPlayground.playTone(277, display_time); //C#4
          CircuitPlayground.clearPixels();
          delay(display_time);
        }
        else if (pattern[display_count] == 3) //Quadrant 3: Blue
        {
          CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(170));
          CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(170));
          CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(170));
          CircuitPlayground.playTone(330, display_time); //E4
          CircuitPlayground.clearPixels();
          delay(display_time);
        }
        else if (pattern[display_count] == 4) //Quadrant 4: Red
        {
          CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(0));
          CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(0));
          CircuitPlayground.playTone(220, display_time); //A3
          CircuitPlayground.clearPixels();
          delay(display_time);
        }
        ++display_count;
      }
      
      while(input_count < round_input) //Loop to accept the user input
      {
        
      if (CircuitPlayground.readCap(3) > 285 || CircuitPlayground.readCap(2) > 285) //Quadrant 1
      {
        CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(85));
        CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(85));
        CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(85));
        CircuitPlayground.playTone(196, display_time); //G4
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 1;
        time_to_check = 1;
      }
      
      else if (CircuitPlayground.readCap(0) > 300 || CircuitPlayground.readCap(1) > 300) //Quadrant 2
      {
        CircuitPlayground.setPixelColor(2,255,255,0);
        CircuitPlayground.setPixelColor(3,255,255,0);
        CircuitPlayground.setPixelColor(4,255,255,0);
        CircuitPlayground.playTone(277, display_time); //C#4
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 2;
        time_to_check = 1;
      }
      
      else if (CircuitPlayground.readCap(12) > 285 || CircuitPlayground.readCap(6) > 285) //Quadrant 3
      {
        CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(170));
        CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(170));
        CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(170));
        CircuitPlayground.playTone(330, display_time); //E4
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 3;
        time_to_check = 1;
      }
      
      else if (CircuitPlayground.readCap(9) > 285 || CircuitPlayground.readCap(10) > 285) //Quadrant 4
      {
        CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(0));
        CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(0));
        CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(0));
        CircuitPlayground.playTone(220, display_time); //A3
        CircuitPlayground.clearPixels();
        input_vect[input_count] = 4;
        time_to_check = 1;
      }
      
      if (time_to_check == 1 && input_vect[input_count] != pattern[input_count]) //If user input is not correct
        {
          //Display Red on all LEDs for 1 second
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
          for (int i = 0; i < 10; ++i)
          {
            CircuitPlayground.playTone((700-50*i), 20);
          }
          delay(800);
          CircuitPlayground.clearPixels();
          
          //Now flash the expected quadrant's LEDs 3 times
          if (pattern[input_count] == 1) //If quadrant 1 was expected
          {
            for (int j = 0; j < 3; ++j)
            {
              CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(85));
              CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(85));
              CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(85));
              CircuitPlayground.playTone(196, 250); //G4
              CircuitPlayground.clearPixels();
              delay(250);
            }
          }
          
          else if (pattern[input_count] == 2) //If quadrant 2 was expected
          {
            for (int j = 0; j < 3; ++j)
            {
              CircuitPlayground.setPixelColor(2,255,255,0);
              CircuitPlayground.setPixelColor(3,255,255,0);
              CircuitPlayground.setPixelColor(4,255,255,0);
              CircuitPlayground.playTone(277, 250); //C#4
              CircuitPlayground.clearPixels();
              delay(250);
            }
          }
          
          else if (pattern[input_count] == 3) //If quadrant 3 was expected
          {
            for (int j = 0; j < 3; ++j)
            {
              CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(170));
              CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(170));
              CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(170));
              CircuitPlayground.playTone(330, 250); //E4
              CircuitPlayground.clearPixels();
              delay(250);
            }
          }
          
          else if (pattern[input_count] == 4) //If quadrant 4 was expected
          {
            for (int j = 0; j < 3; ++j)
            {
              CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(0));
              CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(0));
              CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(0));
              CircuitPlayground.playTone(220, 250); //A3
              CircuitPlayground.clearPixels();
              delay(250);
            }
          }
          
          end_game = 1; //Allows us to exit the game execution loop
          break;
        }
        
        else if (time_to_check == 1 && input_vect[input_count] == pattern[input_count]) //If input is correct
        {
        ++input_count;
        time_to_check = 0;
        }
        
      }
      //All inputs are correct: increase round
      round_input = round_input + 1;
      
      if (round_input-1 == game_length) //User successfully passed 10 rounds, indicate win by setting win_condition to 1
      {
        win_condition = 1;
      }
      
    }
    
    if (win_condition == 1) //If user won the game
      {
        //Flash all LEDs Green
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

        //Play win sounds
        CircuitPlayground.playTone(440, 100); //A4
        CircuitPlayground.playTone(523, 100); //C5
        CircuitPlayground.playTone(784, 100); //G5
        CircuitPlayground.playTone(1047, 250); //C6

        for(int i = 1; i <= 15; ++i)
          {
            CircuitPlayground.setPixelColor(0,CircuitPlayground.colorWheel(25*i));
            CircuitPlayground.setPixelColor(1,CircuitPlayground.colorWheel(25*i));
            CircuitPlayground.setPixelColor(2,CircuitPlayground.colorWheel(25*i));
            CircuitPlayground.setPixelColor(3,CircuitPlayground.colorWheel(25*i*2));
            CircuitPlayground.setPixelColor(4,CircuitPlayground.colorWheel(25*i*2));
            CircuitPlayground.setPixelColor(5,CircuitPlayground.colorWheel(25*i*3));
            CircuitPlayground.setPixelColor(6,CircuitPlayground.colorWheel(25*i*3));
            CircuitPlayground.setPixelColor(7,CircuitPlayground.colorWheel(25*i*3));
            CircuitPlayground.setPixelColor(8,CircuitPlayground.colorWheel(25*i*4));
            CircuitPlayground.setPixelColor(9,CircuitPlayground.colorWheel(25*i*4));
            delay(350);
            CircuitPlayground.clearPixels();
          }
        win_condition = 0;
      }
  }
  }
}
