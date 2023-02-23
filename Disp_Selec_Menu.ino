void Disp_Selec_Menu (int posF0C, int posF1C, String texF0, String textF1, unsigned long demora){
  lcd.clear();
  lcd.setCursor(posF0C, 0);
  lcd.print(texF0);
  lcd.setCursor(posF1C, 1);
  lcd.print(textF1);
  delay(demora);
}