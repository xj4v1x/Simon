/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
void selectGameMode(){
  checkButtons();
  switch (myButton){
    case 7:
      Serial.println("MODE 1");
      gameMode = 1;
      turnLedOn(7, ledPause); 
      break;
    case 4:
      Serial.println("MODE 2");
      gameMode = 2;
      turnLedOn(4, ledPause); 
      break;
    case 6:
      Serial.println("MODE 3");
      gameMode = 3;
      turnLedOn(6, ledPause); 
      break;
  }  
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////END GAME

void youLose(){           //HAS PERDIDO
  myTurn=false;           //Mi turno es falso
  endGame = true;         //Fin de juego es verdadero
  ledsGameOver();         //Secuencia de luces
  asm volatile (" jmp 0");  //SoftReset
}

void youWin(){            //HAS GANADO
  myTurn=false;           //Mi turno es falso
  endGame = true;         //Fin de juego es verdadero
  ledsWin();              //Secuencia de luces
}
