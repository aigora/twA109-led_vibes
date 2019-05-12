# Ecualizador 3D

El proyecto consiste en un cubo de leds, con dimensiones mínimas de 4x4x4 que en función de la frecuencia y el volumen de sonidos que capte un sensor de sonido, se iluminen con colores correspondientes a cada frecuencia y altura correspondiente al volumen. También incluirá un módulo para interactuar con el cubo de leds manualmente.
Los componentes clave serán:

* Sensores:
  1. Módulo sensor de audio (micrófono).
  2. Botones para interactuar manualmente.
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

* Recibir y almacenar la señal proveniente del micrófono. Se necesitará un amplificador, ya sea incorporado o no.
* Determinar la intensidad del sonido (medida en decibelios).
* Estudiar la frecuencia del sonido a través de la transformada rápida de Fourier (FFT) o la transformada rápida de Hartley (FHT).
* Representar los cambios en el tiempo de estos datos encendiendo y apagando los leds que correspondan.

## Recursos
Amplificador:
  * http://www.educachip.com/construye-tu-propio-amplificador-de-audio/
  * https://forum.arduino.cc/index.php?topic=164436.0
  
Reducción de ruido: filtros de paso bajo y de paso alto:
  * https://www.luisllamas.es/arduino-paso-bajo-exponencial/
