void Imp_Ent_Menu() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Presione el");
  lcd.setCursor(0, 1);
  lcd.print("boton 4 segundos");
  delay(delayDisp);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("para volver");
  lcd.setCursor(4, 1);
  lcd.print("al menu");
  delay(delayDisp);
}