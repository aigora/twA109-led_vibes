#include "arduinoFFT.h"
#include <SoftwareSerial.h>
#define N 128//numero de muestras (debe ser potencia de 2)
#define F 8000  //frecuencia de muestreo (debe ser inferior a 10000 por limitaciones del ADC de Arduino)

#define PIN_A 2
#define PIN_B 3
#define PIN_C 4

#define PIN_D 7
#define PIN_E 6
#define PIN_F 5

#define PIN_G 8
#define PIN_H 9
#define PIN_I 10

#define PIN_J 22
#define PIN_K 24
#define PIN_L 26

#define PIN_M 28
#define PIN_N 30
#define PIN_O 32

#define PIN_P 34
#define PIN_Q 36
#define PIN_R 38

arduinoFFT FFT = arduinoFFT();

void encenderLed1(int);
void encenderLed2(int);
void encenderLed3(int);
void encenderLed4(int);
void encenderLed5(int);
void encenderLed6(int);

void setup() {
   Serial.begin(9600);
    int i;
    //  para ver si se encienden bien los LEDs(matriz)
    for(int i=1; i<=6; i++)
    {
        encenderLed1(i);
        delay(100);
        encenderLed2(i);
        delay(100);
        encenderLed3(i);
        delay(100);
        encenderLed4(i);
        delay(100); 
        encenderLed5(i);
        delay(100);
        encenderLed6(i);
        delay(100);
        
}
    while(!Serial); //Espera a que el puerto esté listo
}
void loop() {
  int i,j;
  int ledsc=6; //Número de LEDs por columna
  int ledsf=6; //Número de LEDs por fila
  double hz;
  double vReal[N];
  double vImag[N];
  float pb = 0.0;
  float mic,alfa = 0.5;

  //Tomamos 10 muestras para que los datos se estabilicen

  for(i=0;i<10;i++)
  {
    mic = 2*analogRead(A0);
    pb = alfa * mic + (1 - alfa) * pb;
  }
  
  for(i=0; i<N; i++)
  {
    mic = 2*analogRead(A0);
    pb = alfa * mic + (1 - alfa) * pb;
    
    vReal[i]=pb;
    vImag[i] = 0;
  }
  
  FFT.Windowing(vReal, N, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, N, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, N);

  for (i = 0; i < N/2; i++)
  {
    hz = ((i * 1.0 * F) / N);

    vReal[i]= constrain(vReal[i], 0, 50);
    vReal[i] = map(vReal[i], 0, 50, 0, ledsf);   
  }

  Serial.write(50);
  for(i=0;i<32;i++)
  {
    Serial.write(int (vReal[i]+1));
  }

  Serial.write(51);
  for(i=0;i<32;i++)
  {
    Serial.write(int (vReal[32+i]+1));
  }
 //Adaptamos los datos que tenemos para poder representarlos en la matriz de leds
 
 double media[ledsc];

 int intervalo = (N/2)/ledsc; 
 int c=0;
 int k;
 
    for(i=0; i<(N/2); i+=intervalo)  
    {
      media[c] = 0;
      for (k=0 ; k< intervalo ; k++) {
          media[c] = media[c] + vReal[i+k];
      }
      media[c] = media[c]/intervalo; 
      c++;
    }

  //Encendemos los leds

   for(j=0;j<100;j++)
   {
    for(i=0;i<media[0];i++)
    {
      encenderLed1(i);
    }

    for(i=0;i<media[1];i++)
    {
      encenderLed2(i);
    }
    for(i=0;i<media[2];i++)
    {
      encenderLed3(i);
    }

    for(i=0;i<media[3];i++)
    {
      encenderLed4(i);
    }
    for(i=0;i<media[4];i++)
    {
      encenderLed5(i);
    }

    for(i=0;i<media[5];i++)
    {
      encenderLed6(i);
    }
 }
 
}
// Esta función se va a encargar de aplicar la lógica dependiendo del LED que queramos encender

 void ponerEstados(int pinHigh, int pinLow, int pinInput)
{
    pinMode(pinHigh,OUTPUT);
    digitalWrite(pinHigh,HIGH);
    pinMode(pinLow,OUTPUT);
    digitalWrite(pinLow,LOW);
    pinMode(pinInput,INPUT);
}

// Las 6 funciones siguientes se encargan de encender los LEDs deseados

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
void encenderLed4 (int led_num)
{
    switch(led_num)
    {
        case 1:
            ponerEstados(PIN_J,PIN_K,PIN_L);
            break;
        case 2:
            ponerEstados(PIN_K,PIN_J,PIN_L);
            break;
        case 3:
            ponerEstados(PIN_K,PIN_L,PIN_J);
            break;
        case 4:
            ponerEstados(PIN_L,PIN_K,PIN_J);
            break;
        case 5:
            ponerEstados(PIN_J,PIN_L,PIN_K);
            break;
        case 6:
            ponerEstados(PIN_L,PIN_J,PIN_K);
            break;   
        
    }
    
}
void encenderLed5(int led_num)
{
    switch(led_num)
    {
        case 1:
            ponerEstados(PIN_M,PIN_N,PIN_O);
            break;
        case 2:
            ponerEstados(PIN_N,PIN_M,PIN_O);
            break;
        case 3:
            ponerEstados(PIN_N,PIN_O,PIN_M);
            break;
        case 4:
            ponerEstados(PIN_O,PIN_N,PIN_M);
            break;
        case 5:
            ponerEstados(PIN_M,PIN_O,PIN_N);
            break;
        case 6:
            ponerEstados(PIN_O,PIN_M,PIN_N);
            break;   
        
    }
    
}
void encenderLed6(int led_num)
{
    switch(led_num)
    {
        case 1:
            ponerEstados(PIN_P,PIN_Q,PIN_R);
            break;
        case 2:
            ponerEstados(PIN_Q,PIN_P,PIN_R);
            break;
        case 3:
            ponerEstados(PIN_Q,PIN_R,PIN_P);
            break;
        case 4:
            ponerEstados(PIN_R,PIN_Q,PIN_P);
            break;
        case 5:
            ponerEstados(PIN_P,PIN_R,PIN_Q);
            break;
        case 6:
            ponerEstados(PIN_R,PIN_P,PIN_Q);
            break;   
    }
    
}
