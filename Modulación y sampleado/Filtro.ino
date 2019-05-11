//Código de ejemplo de aplicación de un filtro de paso bajo
//Se emplea con la finalidad de reducir el ruido presente en la señal

//Las últimas 4 instrucciones permiten comparar los valores que toma el micrófono y los valores filtrados
//Se puede observar en el Serial Monitor o en el Serial Plotter de Arduino

#define N 100000

void setup() {
  Serial.begin(9600);
}

void loop() {
  int i, mic;
  int pb = 0;
  float alfa = 0.5; //puede tomar valores entre 0 y 1

  for (i = 0; i < N; i++)
  {
    mic = analogRead(A0);
    pb = alfa * mic + (1 - alfa) * pb;

    Serial.print("lectura: ");
    Serial.println(mic);

    Serial.print("filtro: ");
    Serial.println(pb);
  }
}
