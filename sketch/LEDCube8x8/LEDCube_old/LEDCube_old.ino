
#define CLK  3
#define DATA 1
#define LE   2

#define P1 0
#define P2 1
#define P3 2
#define P4 3
#define P5 4
#define P6 5
#define P7 6
#define P8 7

#include "IRremote.h"
IRrecv irrecv(16); // указываем вывод, к которому подключен приемник
decode_results results;
int PP[8]={P1,P2,P3,P4,P5,P6,P7,P8};

byte matrix[8][8][8] = {
  {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
  },
  {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
  },
  {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
  },
  {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
  },
  {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
  },
  {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
  },
  {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
  },  
  {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
  }
};
//////=========================================================
void clearMatrix(byte val=0)
{
   for(int z=0;z<8;z++)
   {
    for (int x=0;x<8;x++)
    {
        for (int y=0;y<8;y++)
        {
          matrix[z][x][y]=val;
        }
    }
   }
}
//////=========================================================
void drawText(int n)
{
  clearMatrix();

   switch (n)
    {
        case 0:
         matrix[0][2][3]=1;matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[1][2][3]=1;matrix[1][5][3]=1;matrix[2][1][3]=1;matrix[2][5][3]=1;matrix[3][1][3]=1;matrix[3][5][3]=1;matrix[4][1][3]=1;matrix[4][5][3]=1;matrix[5][1][3]=1;matrix[5][5][3]=1;
        ;matrix[6][1][3]=1;matrix[6][5][3]=1;matrix[7][2][3]=1;matrix[7][3][3]=1;matrix[7][4][3]=1;
        break;
        case 1:
        matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[0][5][3]=1;matrix[1][3][3]=1;matrix[2][3][3]=1;matrix[3][3][3]=1;matrix[4][3][3]=1;matrix[5][3][3]=1;matrix[6][3][3]=1;matrix[7][2][3]=1;matrix[7][3][3]=1;matrix[7][4][3]=1;matrix[7][5][3]=1;
        break;
        case 2:
        matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[1][2][3]=1;matrix[1][5][3]=1;matrix[2][2][3]=1;matrix[3][2][3]=1;matrix[4][3][3]=1;matrix[5][4][3]=1;matrix[6][5][3]=1;matrix[7][2][3]=1;matrix[7][3][3]=1;matrix[7][4][3]=1;matrix[7][5][3]=1;
        break;
        case 3:
        matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[1][2][3]=1;matrix[1][5][3]=1;matrix[2][2][3]=1;matrix[3][3][3]=1;matrix[4][3][3]=1;matrix[4][4][3]=1;matrix[5][2][3]=1;matrix[6][2][3]=1;matrix[7][3][3]=1;matrix[7][4][3]=1;matrix[7][5][3]=1;
        break;
        case 4:
        matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[1][3][3]=1;matrix[1][4][3]=1;matrix[2][3][3]=1;matrix[2][5][3]=1;matrix[3][3][3]=1;matrix[3][5][3]=1;matrix[4][3][3]=1;matrix[4][6][3]=1;matrix[5][2][3]=1;matrix[5][3][3]=1;matrix[5][4][3]=1;
        matrix[5][5][3]=1;matrix[5][6][3]=1;matrix[6][3][3]=1;matrix[7][3][3]=1;
        break;
        case 5:
        matrix[0][2][3]=1;matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[0][5][3]=1;matrix[2][5][3]=1;matrix[3][5][3]=1;matrix[4][3][3]=1;matrix[4][4][3]=1;matrix[4][5][3]=1;matrix[5][2][3]=1;matrix[6][2][3]=1;matrix[7][3][3]=1;matrix[7][4][3]=1;
        matrix[7][5][3]=1;matrix[7][6][3]=1;
        break;
        case 6:
        matrix[0][4][3]=1;matrix[1][5][3]=1;matrix[2][6][3]=1;matrix[3][3][3]=1;matrix[3][4][3]=1;matrix[3][5][3]=1;matrix[3][6][3]=1;matrix[4][2][3]=1;matrix[4][6][3]=1;matrix[5][2][3]=1;matrix[5][6][3]=1;matrix[6][2][3]=1;matrix[6][6][3]=1;
        matrix[7][3][3]=1;matrix[7][4][3]=1;matrix[7][5][3]=1;
        break;
        case 7:
        matrix[0][2][3]=1;matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[0][5][3]=1;matrix[0][6][3]=1;matrix[1][3][3]=1;matrix[2][3][3]=1;matrix[3][4][3]=1;matrix[4][4][3]=1;matrix[5][4][3]=1;matrix[6][4][3]=1;matrix[7][5][3]=1;
        break;
        case 8:
        matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[1][2][3]=1;matrix[1][5][3]=1;matrix[2][2][3]=1;matrix[2][5][3]=1;matrix[3][3][3]=1;matrix[3][4][3]=1;matrix[3][5][3]=1;matrix[4][2][3]=1;matrix[4][6][3]=1;matrix[5][2][3]=1;matrix[5][6][3]=1;
        matrix[6][2][3]=1;matrix[6][6][3]=1;matrix[7][3][3]=1;matrix[7][4][3]=1;matrix[7][5][3]=1;
        break;
        case 9:
        matrix[0][3][3]=1;matrix[0][4][3]=1;matrix[0][5][3]=1;matrix[1][2][3]=1;matrix[1][6][3]=1;matrix[2][2][3]=1;matrix[2][6][3]=1;matrix[3][2][3]=1;matrix[3][6][3]=1;matrix[4][2][3]=1;matrix[4][3][3]=1;matrix[4][5][3]=1;matrix[5][2][3]=1;
        matrix[6][3][3]=1;matrix[7][4][3]=1;
        break;
    }
}
//////=========================================================
//////=========================================================
bool on = false;
int counter = 0;
int counter2 = 0;
int counter3 = 8000;
int cX,cY,cZ,xPos,yPos,zPos = 0;
int xSign = 1;
int ySign = 1;
int zSign = 1;
int mode = 0;
int modeCount = 9;
int val1 = 1;
int val2 = 2;
int val3 = 1;
bool oneTime = true;
int rC2 = 0;
int rotator = 1;
int drawCounter = 0;
bool textVisible = false;
int cadr = 0;
bool scrolling = false;
//=============================================================================
//==============================================================================
void rotatePlane(byte (&plane)[8][8],int rc)
{
  
  //rotate 4 ring
    byte temp=plane[0][0];
    for (int i=0;i<7;i++) plane[i][0]=plane[i+1][0];
    for (int i=0;i<7;i++) plane[7][i]=plane[7][i+1];
    for (int i=7;i>0;i--) plane[i][7]=plane[i-1][7];
    for (int i=7;i>0;i--) plane[0][i]=plane[0][i-1];
    plane[0][1]=temp;
   //rotate 3 ring
   if (!(rc==3||rc==7||rc==10||rc==14||rc==17||rc==21||rc==24||rc==28))
   {
        temp=plane[1][1];
        for (int i=1;i<6;i++) plane[i][1]=plane[i+1][1];
        for (int i=1;i<6;i++) plane[6][i]=plane[6][i+1];
        for (int i=6;i>1;i--) plane[i][6]=plane[i-1][6];
        for (int i=6;i>1;i--) plane[1][i]=plane[1][i-1];
        plane[1][2]=temp;
   }
   
   //rotate 2 ring
   if (!(rc==2||rc==4||rc==5||rc==7||rc==9||rc==10||rc==12||rc==14||rc==15||rc==17||rc==19||rc==20||rc==22||rc==24||rc==25||rc==27))
   {
          temp=plane[2][2];
          for (int i=2;i<5;i++) plane[i][2]=plane[i+1][2];
          for (int i=2;i<5;i++) plane[5][i]=plane[5][i+1];
          for (int i=5;i>2;i--) plane[i][5]=plane[i-1][5];
          for (int i=5;i>2;i--) plane[2][i]=plane[2][i-1];
          plane[2][3]=temp;
    }
  
}
//==============================================================================
void rotateMatrix()
{
  for(int i=0;i<8;i++)
  {
    rotatePlane(matrix[i],rotator);
  }
  rotator++;
  if (rotator>28)rotator=1;
}

//==============================================================================
void tifun(byte (&plane)[8][8])
{
  
  //rotate 4 ring
    byte temp=plane[0][0];
    for (int i=0;i<7;i++) plane[i][0]=plane[i+1][0];
    for (int i=0;i<7;i++) plane[7][i]=plane[7][i+1];
    for (int i=7;i>0;i--) plane[i][7]=plane[i-1][7];
    for (int i=7;i>0;i--) plane[0][i]=plane[0][i-1];
    plane[0][1]=temp;
   //rotate 3 ring
    temp=plane[1][1];
    for (int i=1;i<6;i++) plane[i][1]=plane[i+1][1];
    for (int i=1;i<6;i++) plane[6][i]=plane[6][i+1];
    for (int i=6;i>1;i--) plane[i][6]=plane[i-1][6];
    for (int i=6;i>1;i--) plane[1][i]=plane[1][i-1];
    plane[1][2]=temp;
   
   //rotate 2 ring
    temp=plane[2][2];
    for (int i=2;i<5;i++) plane[i][2]=plane[i+1][2];
    for (int i=2;i<5;i++) plane[5][i]=plane[5][i+1];
    for (int i=5;i>2;i--) plane[i][5]=plane[i-1][5];
    for (int i=5;i>2;i--) plane[2][i]=plane[2][i-1];
    plane[2][3]=temp;
   //rotate 1 ring
    temp=plane[3][3];
    for (int i=3;i<4;i++) plane[i][3]=plane[i+1][3];
    for (int i=3;i<4;i++) plane[4][i]=plane[4][i+1];
    for (int i=4;i>3;i--) plane[i][4]=plane[i-1][4];
    for (int i=4;i>3;i--) plane[3][i]=plane[3][i-1];
    plane[3][4]=temp;
}
//==============================================================================
void tifunMatrix()
{
  for(int i=0;i<8;i++)
  {
    tifun(matrix[i]);
  }
}
//==============================================================================
void setup() {
    DDRC=1<<CLK|1<<DATA|1<<LE;
    DDRD=1<<P1|1<<P2|1<<P3|1<<P4|1<<P5|1<<P6|1<<P7|1<<P8;
    irrecv.enableIRIn(); // запускаем прием
}
//==============================================================================
void sentData()
{
 for(int z=0;z<8;z++)
 {
    PORTC&=~(1<<DATA);
    for (int x=0;x<8;x++)
    {
      for (int y=0;y<8;y++)
      {
          PORTC|=(matrix[z][x][y]<<DATA);
          PORTC|=1<<CLK;
          PORTC&=~1<<CLK;
      }
    }
    PORTC|=1<<LE;
    PORTD&=~(1<<PP[7-z]);
    delayMicroseconds(100);
    PORTD=0b11111111;
 }
}
//==============================================================================
void processMode(int subMode)
{
  switch (subMode)
    {
        case 1:
              if (oneTime)
             {
                  oneTime=false;
                  clearMatrix(1);
             }
        break;
        case 2:
            if (counter>20)
            {
               for(int z=7;z>0;z--)
               {
                for (int x=0;x<8;x++)
                {
                    for (int y=0;y<8;y++)
                    {
                      matrix[z][x][y]=matrix[z-1][x][y];
                      matrix[z-1][x][y]=0;
                    }
                }
               }
              int xx=random(0,7);
              int yy=random(0,7);
              matrix[0][xx][yy]=1;
              xx=random(0,7);
              yy=random(0,7);
              matrix[0][xx][yy]=1;
              xx=random(0,7);
              yy=random(0,7);
              matrix[0][xx][yy]=1;
              counter=0;
            }else
            {
              counter++;
            }
            
        break;
        case 3:
            if (counter>4)
            {
              counter2++;
              float fi=(counter2*3.14f/36);
              counter=0;
              clearMatrix();
              float xSin=sin(fi);
              float yCos=cos(fi);
              for (int u=-4;u<5;u++)
              {
                  int x=int(4+xSin*float(u)); if (x==8)x=0;
                  int y=int(4+yCos*float(u)); if (y==8)y=0;
                  for (int z=0;z<8;z++)  matrix[z][x][y]=1;
              }
            }else  counter++;
        break;
        case 4:
            if (oneTime){int xx=random(2,5); int yy=random(2,5);int zz= random(2,5);xPos=xx;yPos=yy;zPos=zz;matrix[zPos][yPos][xPos]=1;oneTime=false;}
            if (counter>80)
            {
              counter=0;
              xPos+=xSign;
              yPos+=ySign;
              zPos+=zSign;
              val1=random(1,3);
              val2=random(1,3);
              val3=random(1,3);
              if (xPos>6){xSign=-val1*(xSign/abs(xSign));xPos=6;}
              if (xPos<1){xSign=-val1*(xSign/abs(xSign));xPos=0;}
              if (yPos>6){ySign=-val2*(ySign/abs(ySign));yPos=6;}
              if (yPos<1){ySign=-val2*(ySign/abs(ySign));yPos=0;}
              if (zPos>6){zSign=-val3*(zSign/abs(zSign));zPos=6;}
              if (zPos<1){zSign=-val3*(zSign/abs(zSign));zPos=0;}

              clearMatrix();
              matrix[zPos][yPos][xPos]=1;
            }else  counter++;
        break;
         case 5:
             if (counter>4)
            {
              counter2++;
              float fi=(counter2*3.14f/36);
              counter=0;
              clearMatrix();
              float xSin=sin(fi);
              float yCos=cos(fi);
              float zSin=sin(fi/10);
              for (int u=-4;u<5;u++)
              {
                  int x=int(4+xSin*float(u)); if (x==8)x=7;
                  int y=int(4+yCos*float(u)); if (y==8)y=7;
                  int z=int(4+zSin*float(u)); if (z==8)z=7;
                  matrix[z][x][y]=1;
              }
              matrix[3][3][3]=1;
              matrix[4][3][3]=1;
              matrix[4][4][3]=1;
              matrix[4][4][4]=1;
              matrix[3][4][4]=1;
              matrix[3][3][4]=1;
              matrix[3][4][3]=1;
              matrix[4][3][4]=1;
            
            }else  counter++;
        break;
        case 6:
             if (oneTime)
             {
                  oneTime=false;
                  matrix[3][3][3]=1;
                  matrix[4][3][3]=1;
                  matrix[4][4][3]=1;
                  matrix[4][4][4]=1;
                  matrix[3][4][4]=1;
                  matrix[3][3][4]=1;
                  matrix[3][4][3]=1;
                  matrix[4][3][4]=1;

                  matrix[4][3][2]=1;
                  matrix[4][4][1]=1;
                  matrix[4][5][1]=1;                  
                  matrix[4][6][2]=1;
                  matrix[4][7][3]=1;
                  

                  matrix[4][4][5]=1;
                  matrix[4][3][6]=1;
                  matrix[4][2][6]=1;                  
                  matrix[4][1][5]=1;
                  matrix[4][0][4]=1;
             }
             //rotate triangle
            if (counter>20)
            {
              counter=0;
              rotateMatrix();
            }else  counter++;
              
        break;
        case 7:
            if (oneTime)
            {
              for (int x=0;x<4;x++) {int xx=random(0,7); int yy=random(0,7);matrix[0][xx][yy]=1;}
              for (int x=0;x<4;x++) {int xx=random(0,7); int yy=random(0,7);matrix[1][xx][yy]=1;}
              for (int x=0;x<3;x++) {int xx=random(1,6); int yy=random(1,6);matrix[2][xx][yy]=1;}
              for (int x=0;x<3;x++) {int xx=random(1,6); int yy=random(1,6);matrix[3][xx][yy]=1;}
              for (int x=0;x<2;x++) {int xx=random(2,5); int yy=random(2,5);matrix[4][xx][yy]=1;}
              for (int x=0;x<2;x++) {int xx=random(2,5); int yy=random(2,5);matrix[5][xx][yy]=1;}
              for (int x=0;x<1;x++) {int xx=random(3,4); int yy=random(3,4);matrix[6][xx][yy]=1;}
              for (int x=0;x<1;x++) {int xx=random(3,4); int yy=random(3,4);matrix[7][xx][yy]=1;}
              oneTime=false;
              
            }
            //rotate triangle
            if (counter>20)
            {
              counter=0;
              tifunMatrix();
            }else  counter++;
        break;
        case 8:
               if (oneTime)
               {
                    oneTime=false;
                    matrix[0][1][4]=1;matrix[0][2][4]=1;matrix[0][5][4]=1;matrix[0][6][4]=1;matrix[1][0][4]=1;matrix[1][3][4]=1;matrix[1][4][4]=1;matrix[1][7][4]=1;matrix[2][0][4]=1;matrix[2][7][4]=1;matrix[3][1][4]=1;
                    matrix[3][6][4]=1;matrix[4][1][4]=1;matrix[4][6][4]=1;matrix[5][2][4]=1;matrix[5][5][4]=1;matrix[6][3][4]=1;matrix[6][4][4]=1;  
                    matrix[0][1][3]=1;matrix[0][2][3]=1;matrix[0][5][3]=1;matrix[0][6][3]=1;matrix[1][0][3]=1;matrix[1][3][3]=1;matrix[1][4][3]=1;matrix[1][7][3]=1;matrix[2][0][3]=1;matrix[2][7][3]=1;matrix[3][1][3]=1;
                    matrix[3][6][3]=1;matrix[4][1][3]=1;matrix[4][6][3]=1;matrix[5][2][3]=1;matrix[5][5][3]=1;matrix[6][3][3]=1;matrix[6][4][3]=1;
               }
            if (counter>80)
              {
                counter=0;
                rotateMatrix();
              }else  counter++;
        break;

        case 10:
            if (oneTime)
               {
                    oneTime=false;
                    matrix[0][3][4]=1;matrix[2][2][4]=1;matrix[2][3][4]=1;matrix[2][4][4]=1;matrix[4][1][4]=1;matrix[4][2][4]=1;matrix[4][3][4]=1;matrix[4][4][4]=1;matrix[4][5][4]=1;matrix[6][0][4]=1;matrix[6][1][4]=1;
                    matrix[6][2][4]=1;matrix[6][3][4]=1;matrix[6][4][4]=1;matrix[6][5][4]=1;matrix[6][6][4]=1;matrix[7][3][4]=1;
               }
            if (counter>80)
              {
                counter=0;
                
              }else  counter++;
        break;
        case 11:
            if (oneTime)
               {
                    oneTime=false;
                    matrix[0][3][4]=1;matrix[1][1][4]=1;matrix[1][3][4]=1;matrix[1][5][4]=1;matrix[2][2][4]=1;matrix[2][3][4]=1;matrix[2][4][4]=1;matrix[3][0][4]=1;matrix[3][1][4]=1;matrix[3][2][4]=1;matrix[3][3][4]=1;
                    matrix[3][4][4]=1;matrix[3][5][4]=1;matrix[3][6][4]=1;matrix[4][2][4]=1;matrix[4][3][4]=1;matrix[4][4][4]=1;matrix[5][1][4]=1;  
                    matrix[5][3][4]=1;matrix[5][5][4]=1;matrix[6][3][4]=1;
               }
            if (counter>80)
              {
                counter=0;
                //rotateMatrix();
              }else  counter++;
        break;
    }
}
//==============================================================================
void loop() 
{

  if ( irrecv.decode( &results )) 
  { // если данные пришли
      oneTime=true;
      drawCounter=0;
      textVisible=true;
      
      switch (results.value)
      {
        case 0xFF00FF:
          on = !on;
          mode = 1;
          scrolling = false;
        break;
        case 0xFF9867:
          on = true;
          mode = 1;
          scrolling = true;
        break;
        case 0xFFC837:
          on = true;
          mode = 1;
          scrolling = false;
        break;
        case 0xFFD02F:
          on = true;
          mode = 2;
          scrolling = false;
        break;
        case 0xFFD827:
          on = true;
          mode = 3;
          scrolling = false;
        break;
        case 0xFFC03F:
          on = true;
          mode = 4;
          scrolling = false;
        break;
        case 0xFF28D7:
          on = true;
          mode = 5;
          scrolling = false;
        break;
        case 0xFF30CF:
          on = true;
          mode = 6;
          scrolling = false;
        break;
        case 0xFF38C7:
          on = true;
          mode = 7;
          scrolling = false;
        break;
        case 0xFF20DF:
          on = true;
          mode = 8;
          scrolling = false;
        break;
      }
      irrecv.resume(); // принимаем следующую команду
  }

  if(on)
  {
        if (textVisible)
        {
          if (drawCounter<400)
          {
            if (scrolling)
            {
              drawText(0);
            }else
            {
              drawText(mode);
            }
            drawCounter++;
          }else 
          {
            drawCounter=0;
            textVisible=false;
            clearMatrix();
          }
          
        }else
        {
              if (scrolling)
              {
                if (counter3>8000)
                {
                  counter3=0;
                  mode++;
                  oneTime=true;
                  if (mode>modeCount)mode = 1;
                  clearMatrix();
                }
                counter3++;
              }
              processMode(mode);
        }
       sentData();
  } else
  {
    drawCounter=0;
    textVisible=false;
    clearMatrix();
  }
}
