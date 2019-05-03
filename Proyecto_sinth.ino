
/*Código para cubo 3x3 
 *    
 *
 *  
 *int Columnas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  
int Filas[] = {12, 11, 10};
int RandFila; //Variable para fila aleatoria
int RandColumna; //Variable para columna aleatoria
 
void setup() {
  int contador;
 
  for (int contador = 0; contador < 10; contador++) {
    pinMode(Columnas[contador], OUTPUT); 
  }
 
  for (int contador = 0; contador < 4; contador++) {
    pinMode(Filas[contador], OUTPUT); 
  }
}
 
void loop() {
  RandLed();
}
 
void RandLed() {
  RandFila = random(0,3);
  RandColumna = random(0,9);
 
  digitalWrite(Filas[RandFila], HIGH);
  digitalWrite(Columnas[RandColumna], HIGH);
  delay(75);
 
  digitalWrite(Filas[RandFila], LOW);
  digitalWrite(Columnas[RandColumna], LOW);
  delay(50);
}
*/

int volumen;
int salida;
void setup() {
  Serial.begin(9600);
  int i;
  //Encender y apagar todos los LEDS para probar que funcionan
  for(i=5;i<=11;i++){
    pinMode(i,OUTPUT);
  }
  for (i=5;i<=11;i++){
    digitalWrite(i,HIGH);
    delay(100);
  };
  for (i=5;i<=11;i++){
    digitalWrite(i,LOW);
    delay(100);
  };
}



void loop() {
  int rango=0;
  int contador=0;
  int i;
  salida = analogRead(A0);
  volumen = salida*log(salida)/10;
  Serial.println(volumen);
  for (i=5;i<=11;i++){
    contador=contador+1;
    rango=(rango+(contador*volumen)/6);
    if (rango>=0 && rango<=contador*volumen/6){
      digitalWrite(i,HIGH);
    }
  }
  for (i=5;i<=11;i++){
    digitalWrite(i,LOW);
  };
  delay(10);
}
