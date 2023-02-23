void Imp_Modo (String modo, String selec, int pos) {
 lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print(modo);
  lcd.setCursor(pos, 1);
  lcd.print(selec);
  delay(delayDisp);
}