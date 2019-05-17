# Analizador de espectro

Este proyecto consiste en analizador de espectro de leds, con dimensiones de 6x6 que se iluminan en función de las frecuencias y volumen de sonidos que recibe a través de un micrófono.
Los componentes clave serán:

* Sensores:
  1. Módulo sensor de audio (micrófono).
* Actuadores:
  1. Leds

## Integrantes del equipo

* Marcelo Luna Diaz, @mlunad88i
* Francisco Padilla De Aguiar, @fpadilla00
* Maria Lisa Salto Molodojen, @mlsalto

## Objetivos del trabajo

El trabajo pretende ilustrar de forma visual el sonido, como se comportan sus frecuencias y lo fascinante que puede ser mezclar luz y sonido. Puede ser usado a nivel instructivo, decorativo e incluso artístico. Creemos que va a ser un proyecto muy bonito.

## Subprogramas (funciones)

Las funciones a utilizar realizarán las siguientes tareas:

* Recibir y almacenar la señal proveniente del micrófono. 
* Determinar la intensidad del sonido.
* Estudiar la frecuencia del sonido a través de la transformada rápida de Fourier (FFT) o la transformada rápida de Hartley (FHT).
* Representar los cambios en el tiempo de estos datos encendiendo y apagando los leds que correspondan.

## Recursos
Amplificador:
  * http://www.educachip.com/construye-tu-propio-amplificador-de-audio/
  * https://forum.arduino.cc/index.php?topic=164436.0
  
Reducción de ruido: filtros de paso bajo y de paso alto:
  * https://www.luisllamas.es/arduino-paso-bajo-exponencial/
