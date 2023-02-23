void control_tiempo(unsigned long *temporizador1, unsigned long *temporizador2 , unsigned long tempM, unsigned long tempPa){

if (modo == 3){
  digitalWrite(mosfet, LOW);
  bombaEc = false;
  Serial.println("Bomba Apagada");
  //apaga bomba
}else{
  if ((bombaEc == false) && (*temporizador2 < millis())){
    //encender bomba
    Serial.println("Bomba Encendida");
    analogWrite(mosfet, 90);
    bombaEc = true;
    *temporizador1 = millis() + tempM;
    
    }else{
       Serial.print("temporizador2: ");
      Serial.println(*temporizador2);
      if ((bombaEc == true) && (*temporizador1 < millis())){
        //apagar bomba
        Serial.println("Bomba Apagada");
        *temporizador2 = tempPa + millis();
        digitalWrite(mosfet, LOW);
        bombaEc = false;
        }
    }
  }
}
