/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////CPU
void CPU(){
  game[level] = leds[random(0,3)];    //Añade al array game en posición level, un número al azar entre 0 y 3
  if (gameMode != 3){
    for (int i=0;i<=level;i++){         //Empieza a recorrer el array desde la posición 0, hasta la posición level
      if (game[i]!=0){                  //Si el valor no es cero quiere decir que se ha grabado algún valor
        turnLedOn(game[i], ledPause);        //Enciende el led game[i] durante 500ms
      }    
    }        
  } else {
    turnLedOn(game[level], ledPause);
  }     
}
/**********************************************************************************************/
