import processing.serial.*;
Serial serial;

int vReal[]=new int [64];

void setup()
{
  printArray(Serial.list ());
  serial=new Serial (this, Serial.list()[0],9600);
  size(700,640);
}

void draw()
{
  int i,j;
  
  if(serial.available()>64)
  {
    while(serial.read()!='2');  //Esperamos a recibir este dato por parte de Arduino para guardar los valores
    for(i=0;i<32;i++)
    {
      vReal[i]=serial.read();
    }
    while(serial.read()!='3');
    for(i=0;i<32;i++)
    {
      vReal[i+32]=serial.read();
    }
  }
  
  //Representamos gráficamente los resultados
  
  background(255);
  fill(0,100,100);
  
  for(i=0;i<64;i++)
  {
    for(j=0;j<=vReal[i];j++)
      rect(0, i*10, 100*j, 10);
  }
}
