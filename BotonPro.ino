void BotonPro() {
  if (digitalRead(PULSADOR)==1){
    timer=millis()+1000;
    while (digitalRead(PULSADOR)==1){
      
     // Serial.println("While");
      delay (5);
      timer2=millis();
      
    }
    
    if (timer2>timer){
      tone(7,261,300);
      /*Serial.println("Usted esta en el menu");
      Serial.println("Aprete el boton una vez para entrar al modo 1 o dos veces para entrar al modo 2");*/
      
      Disp_Selec_Menu (2, 2, "Usted esta", "en el menu", delayDisp);
      Disp_Selec_Menu (1, 2, "Presione 1 vez", "Riego Interno", delayDisp+300);
      Disp_Selec_Menu (0, 2, "Presione 2 veces", "Riego Externo", delayDisp+300);
      Disp_Selec_Menu (0, 4, "Presione 3 veces", "Stand By", delayDisp+300);
      modo = 1;
      cont=0;
      Serial.println(cont);
      timer=millis()+5000; 
      while (menu==false){   
       // Serial.println("Entro al while");
        if (digitalRead(PULSADOR)==1){
          cont++;
          /*Serial.print("Ha ingresado en el modo: ");
          Serial.println(cont);*/
          Disp_Selec_Menu (3, 7, "Selecciono", String (cont), 10);
          delay (200);
          tone(7,261,300);          
          delay (300); 
          if (cont==3){
            cont=3;
            break;
            }      
        }
        if (timer< millis()){
           menu=true;  
          }
        }
      }
    
    menu=false;
     /*lcd.clear();
      lcd.setCursor(0, 0);
        lcd.print("Presione 4 seg");
      lcd.setCursor(0, 1);
        lcd.print("para volver menu");*/
      
  }
  
  
  if (cont==1) {
   // Serial.println ("menu1");
         modo = 1;
         //menu_displ();
          cambioM= false;
  }else if (cont==2) {
          modo = 2;
          //menu_displ();
           cambioM= false;
    //Serial.println ("menu2");
  }else if (cont==3){
          modo=3;
          cambioM= false;
  }
 
}
