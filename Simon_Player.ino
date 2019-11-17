/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////PLAYER
void Player(){
  if (gameMode == 2){
    playerMode2();
  } else {
    playerMode1();
  }  
}

void playerMode1(){
  myTurn=true;                          //Empieza el turno del jugador
  int playerRound = 0;                  //En la jugada 0    
  while (myTurn==true){                 //Mientras sea su turno...    
    checkButtons();                     //Comprueba la pulsación del botón
    if (myButton!=0){                   //Si se ha pulsado algún botón
      if (myButton==game[playerRound]){     //Si ese botón es igual a lo grabado en game[playerRond]
        turnLedOn(game[playerRound], ledPause);      //Enciende ese led durante ledPause ms
        playerRound++;                          //Siguiente jugada
        if (playerRound>level){                 //Si la jugada llega al número del nivel (cada nivel añade una jugada nueva)
          level++;                                  //Sube de nivel
          if ((level%3 == 0) and (ledPause>minPause)){
            ledPause-=50;
          }
          if (level>maxLevel){                      //Si hemos llegado al nivel máximo...          
            youWin();                                   //YOU WIN
          }
          myTurn=false;                             //Acaba el turno del jugador        
          //ledsRotateOnOff(50);                      //Secuencia de luces
        }       
      } else {                              //si no...                      
        youLose();                              //Pierdes
      }                            
    }                        
  }
}

void playerMode2(){
  myTurn=true;                          //Empieza el turno del jugador
  int playerRound = level;                  //En la jugada level
  while (myTurn==true){                 //Mientras sea su turno...    
    checkButtons();                     //Comprueba la pulsación del botón
    if (myButton!=0){                   //Si se ha pulsado algún botón
      if (myButton==game[playerRound]){     //Si ese botón es igual a lo grabado en game[playerRond]
        turnLedOn(game[playerRound], ledPause);      //Enciende ese led durante ledPause ms
        playerRound--;                          //Siguiente jugada
        if (playerRound<0){                 //Si la jugada llega al número del nivel (cada nivel añade una jugada nueva)
          level++;                                  //Sube de nivel
          if ((level%3 == 0) and (ledPause>minPause)){
            ledPause-=50;
          }
          if (level>maxLevel){                      //Si hemos llegado al nivel máximo...          
            youWin();                                   //YOU WIN
          }
          myTurn=false;                             //Acaba el turno del jugador        
          //ledsRotateOnOff(50);                      //Secuencia de luces
        }       
      } else {                              //si no...                      
        youLose();                              //Pierdes
      }                            
    }                        
  }
}

/**********************************************************************************************/

/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
