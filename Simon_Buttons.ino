/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////BOTONES
void checkButtons(){  
  myButton=0;                           //Inicializamos la variable   
  if (digitalRead(BotonUP)==HIGH){      //Si se ha pulsado el botón UP
    myButton=7;                         //Almacenamos en la variable el número 7, que corresponde al led UP
    //delay(300);
  }
  if (digitalRead(BotonDOWN)==HIGH){    //Si se ha pulsado el botón DOWN
    myButton=4;                         //Almacenamos en la variable el número 4, que corresponde al led DOWN
    //delay(300);
  }
  if (digitalRead(BotonLEFT)==HIGH){    //Si se ha pulsado el botón LEFT
    myButton=5;                         //Almacenamos en la variable el número 5, que corresponde al led LEFT
    //delay(300); 
  }
  if (digitalRead(BotonRIGHT)==HIGH){   //Si se ha pulsado el botón RIGHT
    myButton=6;                         //Almacenamos en la variable el número 6, que corresponde al led RIGHT
    //delay(300); 
  }
}
/**********************************************************************************************/

/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
