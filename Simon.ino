/*
  JUEGO SIMON
*/


int BotonUP = 8;              //VERDE
int BotonRIGHT = 9;           //AZUL
int BotonDOWN = 10;           //AMARILLO
int BotonLEFT = 11;           //BLANCO
int ledUP = 7;                //AMARILLO  
int ledRIGHT = 6;             //BLANCO
int ledDOWN = 4;              //VERDE
int ledLEFT = 5;              //AZUL

int buttons[4]={8,9,10,11};
int leds[4]={7,6,4,5};
#define maxLevel 20
int game[maxLevel] = {};
int level = 0;

int player[maxLevel]={};
int playerRound = 0;
bool myTurn=true;
int myButton=0;
bool endGame=false;

void setup() {
  Serial.begin(9600);
  for (int i=0;i<(sizeof(buttons)/sizeof(buttons[0]));i++){
    pinMode (buttons[i], INPUT);
  }
  for (int i=0;i<(sizeof(leds)/sizeof(leds[0]));i++){
    pinMode (leds[i], OUTPUT);
  }
  randomSeed(analogRead(A0));
  ledsRotateOnOff(100);
  ledsRotate(1, 200);  
  ledsRotate(0, 200); 
  ledsBlink(1, 300);
  
}

void loop() {  
  if (endGame==false){
    CPU();
    Player();  
  }  
}

void CPU(){
  
  game[level] = leds[random(0,3)];
  Serial.print("CPU: ");
  for (int i=0;i<=level;i++){
    if (game[i]!=0){
      Serial.print(game[i]);
      Serial.print(" ");
      turnLedOn(game[i], 500);
    }    
  }      
  Serial.println("");
}

/**********************************************************************************************/
/////////////////LUCES
void turnLedOn(int ledN, int pause){
  digitalWrite(ledN, HIGH);
  delay(pause);
  digitalWrite(ledN, LOW);
  delay(pause);
}

void ledsBlink(int times, int pause){
  for (int n=0;n<times;n++){
    for (int i=0;i<(sizeof(leds)/sizeof(leds[0]));i++){
      digitalWrite(leds[i], HIGH);   
    }
    delay(200);
    for (int i=0;i<(sizeof(leds)/sizeof(leds[0]));i++){
      digitalWrite(leds[i], LOW);   
    }
    delay(pause);  
  }  
}

void ledsRotateOnOff(int pause){
  for (int i=0;i<(sizeof(leds)/sizeof(leds[0]));i++){
    digitalWrite(leds[i], HIGH);
    delay(pause);
    digitalWrite(leds[i], LOW);
  }  
  delay(200);
}

void ledsRotate(int state, int pause){
  for (int i=0;i<(sizeof(leds)/sizeof(leds[0]));i++){
    digitalWrite(leds[i], state);
    delay(pause);    
  }
}

void ledsGameOver(){
  ledsBlink(3, 50);
  turnLedOn(7, 100);
  turnLedOn(5, 100);
  turnLedOn(6, 100);
  turnLedOn(4, 100);  
}

void ledsWin(){
 ledsRotateOnOff(100);
 ledsRotateOnOff(100);
 ledsRotateOnOff(100); 
 ledsRotate(1, 100);
 ledsRotate(0, 500);
}
/////////////////LUCES
/**********************************************************************************************/

void Player(){
  myTurn=true;
  playerRound = 0;
  Serial.print("Player: ");      
  while (myTurn==true){
    checkButtons();
    if (myButton!=0){
      player[level]=myButton;      
      Serial.print(myButton);        
      Serial.print(" ");        
      if (myButton==game[playerRound]){
        turnLedOn(player[playerRound], 300);
        playerRound++; 
        if (playerRound>level){        
        level++;
        if (level>maxLevel){
          youWin();
        }
        myTurn=false;
        Serial.println(" ");
        ledsRotateOnOff(50);     
      }       
      } else {
        youLose();
      }
                       
      myButton=0;                       
    }                        
  }
}


void checkButtons(){     
  if (digitalRead(BotonUP)==HIGH){        //Devuelve el numero que corresponde al led que tiene esa posición
    myButton=7;
    delay(300);
  }
  if (digitalRead(BotonDOWN)==HIGH){
    myButton=4;
    delay(300);
  }
  if (digitalRead(BotonLEFT)==HIGH){
    myButton=5;   
    delay(300);   
  }
  if (digitalRead(BotonRIGHT)==HIGH){
    myButton=6;   
    delay(300);   
  }
}


void youLose(){
  Serial.println("LOSE");
  myTurn=false;
  endGame = true;
  ledsGameOver();
}

void youWin(){
  Serial.println("WIN");
  myTurn=false;
  endGame = true;
  ledsWin();
}
