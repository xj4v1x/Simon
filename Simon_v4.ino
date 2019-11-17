/*
  JUEGO SIMON  v4.0
  STZMAKERS
*/

//1.- Definir variables

//Pulsadores y leds
int BotonUP = 8;              //VERDE
int BotonRIGHT = 9;           //AZUL
int BotonDOWN = 10;           //AMARILLO
int BotonLEFT = 11;           //BLANCO

int ledDOWN = 4;              //VERDE
int ledLEFT = 5;              //AZUL
int ledRIGHT = 6;             //BLANCO
int ledUP = 7;                //AMARILLO  


//Array con los pines de los leds
int leds[4]={7,6,4,5};

//Otras variables
#define maxLevel 20     //Constante, no se pone ";"
int game[maxLevel] = {};  //Array para guardar las jugadas correctas

int level = 0;          //Nivel actual del juego
bool myTurn=true;       //Para comprobar cuando finaliza el turno
int myButton=0;         //Donde se guarda la pulsación del jugador
bool endGame=false;     //Fin de juego
byte gameMode = 0;      //Mode 1 -> Normal  //  Mode 2 -> Inverso  //  Mode 3 -> A ciegas

int ledPause = 400;
int minPause = 100;


//2.SETUP 
void setup() {
  Serial.begin(9660);
  // Pines de ENTRADA
  pinMode (BotonUP, INPUT);
  pinMode (BotonRIGHT, INPUT);
  pinMode (BotonDOWN, INPUT);
  pinMode (BotonLEFT, INPUT);
  
  // Pines de SALIDA
  pinMode (ledUP, OUTPUT);
  pinMode (ledRIGHT, OUTPUT);
  pinMode (ledDOWN, OUTPUT);
  pinMode (ledLEFT, OUTPUT);
  
  //Semilla RANDOM
  randomSeed(analogRead(A0));

  //Secuencia luces inicio
  ledsInit();
  
  //Elegir modo de juego
  while (gameMode == 0){
    selectGameMode();    
  }   
  ledsBlink(1, 300);   //Enciende y apaga todos los leds 1 vez, con un delay 300 
}

void loop() {
  if (endGame==false){  //Si el juego no acaba
    CPU();              //Turno del CPU
    Player();           //Turno del Player
  }    
}
