#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define mosfet 3
#define LEDROJO 13 // define pin de led rojo
#define LEDBLANCO 12 // define pin de led blanco
#define PULSADOR 2
const unsigned long PaM1= 900000, PaM2=1800000,  tempM=180000;
LiquidCrystal_I2C lcd(0x3F,16,2); //Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
//const byte rele = 8; //define pin de rele (pero no utilizamos)
int modo = 1; //define valor inicial de la variable como volatil 
int modo_ant = 0, cont=0; // define valor inicial de la variable como entero
unsigned long temporizador1, temporizador2=0, tempPa, timer, timer2, delayDisp=2500; // define lo temporizadores
bool bombaEc = false, cambioM = false, menu=false, cambioIni= false;  // define las variables booleanas 

void setup(){

// se inicializan los pines y los interruptores
  pinMode(PULSADOR, INPUT);
// pinMode(rele, OUTPUT);
  pinMode(LEDROJO,OUTPUT);
  pinMode(LEDBLANCO,OUTPUT);
  pinMode(mosfet, OUTPUT);
  Serial.begin(9600);// inicia la transmision de datos en 9600
  
 // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Incializando");
  lcd.setCursor(4, 1);
  lcd.print("Sistema");
  delay (2000);
 
}

void loop(){
  menu_displ(modo, true);
  //Serial.println (cambioM);
  switch (modo){
  
    case 1:
       tempPa=PaM1;
       if (cambioIni == false){
       temporizador2  = 0;
       cambioIni = true;
        }
       //entra a modo interior
       //display "modo interior"
       break;
       
   case 2:
       tempPa=PaM2;

       //entra a modo exterior 
       //display "modo exterior"

       break;

   case 3:
       //display "modo stand by"
       //stand by
       //apagar motor
       break;
        
 }
  control_tiempo (&temporizador1, &temporizador2, tempM, tempPa);
  BotonPro();

}
