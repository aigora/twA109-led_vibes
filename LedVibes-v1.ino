#include "arduinoFFT.h"
#define N 128 //numero de muestras (debe ser múltiplo de 2)
#define F 1000  //frecuencia de muestreo (debe ser inferior a 10000 por limitaciones del ADC de Arduino

arduinoFFT FFT = arduinoFFT();

void setup() {
  Serial.begin(9600);
  }

void loop() {
  
  //La FFT emplea números imaginarios en sus cálculos
  int i;
  float pb = 0.0;
  float mic,alfa = 0.5;
  
  double vReal[N];  //Parte real
  double vImag[N];  //Parte imaginaria
  long microseconds;

  for(int i=0; i<N; i++)
    {
        microseconds = micros();    
        mic = 1.1*analogRead(A0);
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

}