import processing.serial.*;
Serial serial;

int vReal[]=new int [64];

void setup()
{
  printArray(Serial.list ());
  serial=new Serial (this, Serial.list()[0],9600);
  size(600,400);
}

void draw()
{
  //println(serial.read());
  if(serial.available()>64)
  {
    while(serial.read()!='2');
  for(int i=0;i<64;i++)
  {
    vReal[i]=serial.read();
  }
  }
  printArray(vReal);
}
