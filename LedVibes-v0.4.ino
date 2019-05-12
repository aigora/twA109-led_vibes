#include "arduinoFFT.h"
#define N 128 //numero de muestras (debe ser múltiplo de 2)
#define F 1000  //frecuencia de muestreo (debe ser inferior a 10000 por limitaciones del ADC de Arduino

//
#define PIN_A 2
#define PIN_B 3
#define PIN_C 4

#define PIN_D 7
#define PIN_E 6
#define PIN_F 5

#define PIN_G 8
#define PIN_H 9
#define PIN_I 10

int volumen;
int salida;
void encenderLed1(int);
void encenderLed2(int);
void encenderLed3(int);

arduinoFFT FFT = arduinoFFT();

void setup() {
    Serial.begin(9600);
    int i;
    //  para ver si se encienden bien los leds(matriz)
    for(int i=1; i<=6; i++)
    {
        encenderLed1(i);
        delay(100);
        encenderLed2(i);
        delay(100);
        encenderLed3(i);
        delay(100);
    }

  }

void loop() {
  
//La FFT emplea números complejos en sus cálculos
  
  int i;
  float pb = 0.0;
  float pb2 = 0.0;
  float mic,alfa = 0.5;
  
  double vReal[N];  //Parte real
  double vImag[N];  //Parte imaginaria
  long microseconds;

  for(int i=0; i<N; i++)
    {
        microseconds = micros();    
        mic = 2*analogRead(A0);
        pb = alfa * mic + (1 - alfa) * pb;
        vReal[i]=pb;
        vImag[i] = 0; //Como los valores que recibimos provienen del micrófono (números reales), la parte imaginaria debe ser 0
     
        while(micros() < (microseconds + 1000)){
        }
    }
    
    FFT.Windowing(vReal, N, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, N, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, N);
    double peak = FFT.MajorPeak(vReal, N, F); 

    Serial.print("Frecuencia: ");
    Serial.println(peak); // Se imprime el valor en Hz de la frecuencia dominante en la muestra
    Serial.println(pb);
    //Mandamos los datos a los leds
    int rango=1;
    
    volumen = pb;
  
    if (peak>=0 && peak<200){
        for(i=1;i<=6;i++){
          //if(rango<=0 && rango<i*pb/6)
            encenderLed1(i);
            delay(100);
        }
    }
    else if (peak>200 && peak<=400){
        for(i=1;i<=6;i++){
          //if(rango<=0 && rango<i*pb/6)
            encenderLed2(i);
            delay(100);
        }
    }
   else if (peak>400 && peak<=600){
        for(i=1;i<=6;i++){
          //if(rango<=0 && rango<i*pb/6)
            encenderLed3(i);
            delay(100);
        }
    }
    

}
    
// Función que pondrá en los estados correctos para encender un LED (HIGH, LOW e INPUT)
void ponerEstados(int pinHigh, int pinLow, int pinInput)
{
    pinMode(pinHigh,OUTPUT);
    digitalWrite(pinHigh,HIGH);
    pinMode(pinLow,OUTPUT);
    digitalWrite(pinLow,LOW);
    pinMode(pinInput,INPUT);
}
 
// Esta función se va a encargar de aplicar la lógica dependiendo del LED que queramos encender
void encenderLed1 (int led_num)
{
    switch(led_num)
    {
        case 1:
            ponerEstados(PIN_A,PIN_B,PIN_C);
            break;
        case 2:
            ponerEstados(PIN_B,PIN_A,PIN_C);
            break;
        case 3:
            ponerEstados(PIN_B,PIN_C,PIN_A);
            break;
        case 4:
            ponerEstados(PIN_C,PIN_B,PIN_A);
            break;
        case 5:
            ponerEstados(PIN_A,PIN_C,PIN_B);
            break;
        case 6:
            ponerEstados(PIN_C,PIN_A,PIN_B);
            break;   
        
    }
    
}
void encenderLed2(int led_num)
{
    switch(led_num)
    {
        case 1:
            ponerEstados(PIN_D,PIN_E,PIN_F);
            break;
        case 2:
            ponerEstados(PIN_E,PIN_D,PIN_F);
            break;
        case 3:
            ponerEstados(PIN_E,PIN_F,PIN_D);
            break;
        case 4:
            ponerEstados(PIN_F,PIN_E,PIN_D);
            break;
        case 5:
            ponerEstados(PIN_D,PIN_F,PIN_E);
            break;
        case 6:
            ponerEstados(PIN_F,PIN_D,PIN_E);
            break;   
        
    }
    
}
void encenderLed3(int led_num)
{
    switch(led_num)
    {
        case 1:
            ponerEstados(PIN_G,PIN_H,PIN_I);
            break;
        case 2:
            ponerEstados(PIN_H,PIN_G,PIN_I);
            break;
        case 3:
            ponerEstados(PIN_H,PIN_I,PIN_G);
            break;
        case 4:
            ponerEstados(PIN_I,PIN_H,PIN_G);
            break;
        case 5:
            ponerEstados(PIN_G,PIN_I,PIN_H);
            break;
        case 6:
            ponerEstados(PIN_I,PIN_G,PIN_H);
            break;   
    }
    
}
