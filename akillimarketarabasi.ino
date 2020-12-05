
 
#include <hid.h>                       
#include <hiduniversal.h>                  
#include <usbhub.h>
#include <avr/pgmspace.h>
#include <Usb.h>
#include <usbhub.h>
#include <avr/pgmspace.h>
#include <hidboot.h>

#include "U8glib.h"
U8GLIB_ST7920_128X64 u8g( 13,11,10,U8G_PIN_NONE); //U8G_PIN_NONE
 



int dizi[100];
int i=0;
int t=0;
int s=0;
//int x=0;
int toplam1=1;
float toplam2=0;
float agirlik=0;

/////////// URUNLER  ////////////////////////////////

char bumbo[]="ETI BUMBO BISKUVI 2 TL";            //579
char mendil[]="SELPAK MENDIL 1.5 TL";         //425
char caramio[]="ULKER CARAMIO 1 TL";          //595
char dido[]="ULKER DIDO 1.5 TL";              //537
char popkek[]="ETI POPKEK 0.75 TL";         //585
char su[]="KAYIN SU 0.5 LT 1 TL";         //539




 
USB     Usb;
USBHub     Hub(&Usb);     //                                     //I enable this line
HIDUniversal      Hid(&Usb);                                  //Add this line so that the barcode scanner will be recognized, I use "Hid" below 
HIDBoot<HID_PROTOCOL_KEYBOARD>    Keyboard(&Usb);      //
 
class KbdRptParser : public KeyboardReportParser
{
        void PrintKey(uint8_t mod, uint8_t key);             // Add this line to print character in ASCII
protected:
  virtual void OnKeyDown  (uint8_t mod, uint8_t key);
  virtual void OnKeyPressed(uint8_t key);
};
 
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)  
{
    uint8_t c = OemToAscii(mod, key);
    
    if (c)
    {
        OnKeyPressed(c);
         if(c!=19)
          {
            if(c!=48)
            {
            toplam1=toplam1+c;
            }
            if(c==48)
            {
              toplam1=toplam1+0;
            }  
          }
         else
          {
            
            dizi[i]=toplam1;
            toplam1=1;
            Serial.println(dizi[i]);
            i++;
            
           
            
          }
        
    }
    
}




void KbdRptParser::OnKeyPressed(uint8_t key)  
{
 

};

 
KbdRptParser Prs;
 
void setup(void)
{
    Serial.begin( 115200 );
    Serial.println("Start");
    
 
    if (Usb.Init() == -1) {
        Serial.println("OSC did not start.");
    }

   
 
    Hid.SetReportParser(0, (HIDReportParser*)&Prs);        //Here I change  "Keyboard" for "Hid"
    
}

 
void loop()
{
  
  u8g.firstPage();  
  do {
   draw();
  } while( u8g.nextPage() );
  Usb.Task();
}

void draw(void)
{
 ///////////////******************************************         1.SAYFA       ******************/////////////////////////////////////////////////////////////////////////////
  if(s==0)
 { 

    if(dizi[0]==425)
        {
         if(t==0)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
         
         }

         
    if(dizi[0]==595)
        {
         if(t==0)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         }

         if(dizi[0]==585)
        {
         if(t==0)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         }

         if(dizi[0]==537)
        {
         if(t==0)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         }

         if(dizi[0]==539)
        {
         if(t==0)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         }

         
    if(dizi[0]==579)
      {
           if(t==0)
           {
      
            toplam2+=2;
            agirlik+=35;
            t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
       
         
      }


         
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          
    
    if(dizi[1]==425)
       {
         if(t==1)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
        }
        


       if(dizi[1]==595)
       {
         if(t==1)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
        }

        if(dizi[1]==537)
       {
         if(t==1)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
        }

        if(dizi[1]==539)
       {
         if(t==1)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
        }

        if(dizi[1]==585)
       {
         if(t==1)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
        }

     if(dizi[1]==579)
       {
         if(t==1)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
          

       
       }
          

           
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    if(dizi[2]==579)
     {
         if(t==2)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
       
         }
         
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
      }

   if(dizi[2]==595)
     {
         if(t==2)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
       
         }
         
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
      }

      if(dizi[2]==537)
     {
         if(t==2)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
       
         }
         
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
      }

      if(dizi[2]==539)
     {
         if(t==2)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
       
         }
         
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
      }

       if(dizi[2]==585)
     {
         if(t==2)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
       
         }
         
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
      }

      if(dizi[2]==425)
     {
         if(t==2)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
       
         }
         
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
      }


         ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[3]==579)
     {
         if(t==3)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

       if(dizi[3]==425)
     {
         if(t==3)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[3]==595)
     {
         if(t==3)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[3]==585)
     {
         if(t==3)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[3]==537)
     {
         if(t==3)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[3]==539)
     {
         if(t==3)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }



         

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[4]==579)
      {
         if(t==4)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[4]==425)
      {
         if(t==4)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[4]==595)
      {
         if(t==4)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[4]==585)
      {
         if(t==4)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[4]==537)
      {
         if(t==4)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }

      if(dizi[4]==539)
      {
         if(t==4)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
      }


   ///// //// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     if(dizi[5]==579)
      {
         if(t==5)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
       }

       if(dizi[5]==425)
      {
         if(t==5)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
       }

       if(dizi[5]==595)
      {
         if(t==5)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
       }

       if(dizi[5]==585)
      {
         if(t==5)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
       }

       if(dizi[5]==537)
      {
         if(t==5)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
       }

       if(dizi[5]==539)
      {
         if(t==5)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         
         
       }
       
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     if(dizi[6]==579 || dizi[6]==595 || dizi[6]==537 || dizi[6]==425 || dizi[6]==585 || dizi[6]==539)
      {
         if(t==6)
         {
         t=t+1;
         s=s+1;
         }
         /*
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 54);
         u8g.print("BUMBO 2 TL 35GR");
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         */
         
       }
           
          
    
 }

           ////////////*****************************         2.sayfa        *********************************//////////////////////////////////////////////////////////////////////////
    
 if(s==1)
  {
    if(dizi[6]==425)
        {
         if(t==7)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
         
         }

    if(dizi[6]==579)
      {
           if(t==7)
           {
             toplam2+=2;
             agirlik+=35;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }


      if(dizi[6]==595)
      {
           if(t==7)
           {
             toplam2+=1;
             agirlik+=35;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[6]==585)
      {
           if(t==7)
           {
             toplam2+=0.75;
             agirlik+=60.50;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

        if(dizi[6]==537)
      {
           if(t==7)
           {
             toplam2+=1.5;
             agirlik+=35;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[6]==539)
      {
           if(t==7)
           {
             toplam2+=1;
             agirlik+=100;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }


         
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          
    
    if(dizi[7]==425)
      {
         if(t==8)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
       }
        
    if(dizi[7]==579)
      {
        if(t==8)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

     if(dizi[7]==595)
      {
        if(t==8)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[7]==585)
      {
        if(t==8)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[7]==537)
      {
        if(t==8)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[7]==539)
      {
        if(t==8)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }
          

           
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    if(dizi[8]==579)
     {
         if(t==9)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
  
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
      }

      if(dizi[8]==595)
     {
         if(t==9)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
  
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
      }

      if(dizi[8]==585)
     {
         if(t==9)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
  
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
      }

      if(dizi[8]==537)
     {
         if(t==9)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
  
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
      }

      if(dizi[8]==539)
     {
         if(t==9)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
  
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
      }

      if(dizi[8]==425)
     {
         if(t==9)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
  
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
      }


         /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     if(dizi[9]==579)
      {
         if(t==10)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[9]==595)
      {
         if(t==10)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[9]==585)
      {
         if(t==10)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[9]==537)
      {
         if(t==10)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[9]==539)
      {
         if(t==10)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[9]==425)
      {
         if(t==10)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }


         

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     if(dizi[10]==579)
      {
         if(t==11)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[10]==595)
      {
         if(t==11)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[10]==585)
      {
         if(t==11)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[10]==537)
      {
         if(t==11)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[10]==539)
      {
         if(t==11)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }

       if(dizi[10]==425)
      {
         if(t==11)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
       }


           ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[11]==579)
     {
         if(t==12)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[11]==595)
     {
         if(t==12)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[11]==585)
     {
         if(t==12)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[11]==537)
     {
         if(t==12)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

        if(dizi[11]==539)
     {
         if(t==12)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }

       if(dizi[11]==425)
     {
         if(t==12)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         
         
       }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[12]==579 || dizi[12]==595 || dizi[12]==537 || dizi[12]==425 || dizi[12]==585 || dizi[12]==539)
     {
         if(t==13)
         {
         t=t+1;
         s=s+1;
         }
         /*
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 54);
         u8g.print("BUMBO 2 TL 35GR");
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-1); u8g.print("ADET");
         */
 
       }
           
    
   }

   ///////////////////////////////////////////////**********************        3. SAYFA         ************************//////////////////////////////////////////////////////////////////

   if(s==2)
   {
    if(dizi[12]==425)
      {
         if(t==14)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");         
       }

    if(dizi[12]==579)
        {
           if(t==14)
           {
      
                  toplam2+=2;
                  agirlik+=35;
                  t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         }

         if(dizi[12]==595)
        {
           if(t==14)
           {
      
                  toplam2+=1;
                  agirlik+=35;
                  t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         }

         if(dizi[12]==585)
        {
           if(t==14)
           {
      
                  toplam2+=0.75;
                  agirlik+=60.50;
                  t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         }

         if(dizi[12]==537)
        {
           if(t==14)
           {
      
                  toplam2+=1.5;
                  agirlik+=35;
                  t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         }

         if(dizi[12]==539)
        {
           if(t==14)
           {
      
                  toplam2+=1;
                  agirlik+=100;
                  t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         }

         
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          
    
    if(dizi[13]==425)
      {
         if(t==15)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
      }
        


    if(dizi[13]==579)
      {
         if(t==15)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
       }

        if(dizi[13]==595)
      {
         if(t==15)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
       }

       if(dizi[13]==585)
      {
         if(t==15)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
       }

       if(dizi[13]==537)
      {
         if(t==15)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
       }

       if(dizi[13]==539)
      {
         if(t==15)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
       }
          

           
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


     if(dizi[14]==579)
      {
         if(t==16)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
       
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
       }

       if(dizi[14]==595)
      {
         if(t==16)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
       
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
       }

       if(dizi[14]==585)
      {
         if(t==16)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
       
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
       }

       if(dizi[14]==537)
      {
         if(t==16)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
       
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
       }

       if(dizi[14]==539)
      {
         if(t==16)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
       
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
       }

       if(dizi[14]==425)
      {
         if(t==16)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
       
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
       }



         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     if(dizi[15]==579)
      {
         if(t==17)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[15]==595)
      {
         if(t==17)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[15]==585)
      {
         if(t==17)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[15]==537)
      {
         if(t==17)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[15]==539)
      {
         if(t==17)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[15]==425)
      {
         if(t==17)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[16]==579)
     {
         if(t==18)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[16]==595)
     {
         if(t==18)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[16]==585)
     {
         if(t==18)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[16]==537)
     {
         if(t==18)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

      if(dizi[16]==539)
     {
         if(t==18)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }

       if(dizi[16]==425)
     {
         if(t==18)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
      }


     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     if(dizi[17]==579)
      {
         if(t==19)
         {
      
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
       }

       if(dizi[17]==595)
      {
         if(t==19)
         {
      
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
       }

       if(dizi[17]==585)
      {
         if(t==19)
         {
      
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
       }

       if(dizi[17]==537)
      {
         if(t==19)
         {
      
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
       }

       if(dizi[17]==539)
      {
         if(t==19)
         {
      
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
       }

       if(dizi[17]==425)
      {
         if(t==19)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-2); u8g.print("ADET");
         
         
       }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[18]==579 || dizi[18]==595 || dizi[18]==537  || dizi[18]==425 || dizi[18]==585 || dizi[18]==539)
      {
         if(t==20)
         {
         t=t+1;
         s=s+1; 
         }
         /*
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 54);
         u8g.print("BUMBO 2 TL 35GR");
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t); u8g.print("ADET");
         */
       }
          
   }
      ////////////***************************          4. SAYFA          ***************///////////////////////////////////////////////////////////////////////////////////////////////////

 if(s==3)
  {
    if(dizi[18]==425)
     {
         if(t==21)
         {
      
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

    if(dizi[18]==579)
      {
           if(t==21)
           {
               toplam2+=2;
               agirlik+=35;
               t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[18]==595)
      {
           if(t==21)
           {
               toplam2+=1;
               agirlik+=35;
               t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[18]==585)
      {
           if(t==21)
           {
               toplam2+=0.75;
               agirlik+=60.50;
               t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[18]==537)
      {
           if(t==21)
           {
               toplam2+=1.5;
               agirlik+=35;
               t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

        if(dizi[18]==539)
      {
           if(t==21)
           {
               toplam2+=1;
               agirlik+=100;
               t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }



         
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          
    
    if(dizi[19]==425)
      {
         if(t==22)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }
        


    if(dizi[19]==579)
     {
        if(t==22)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[19]==595)
     {
        if(t==22)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[19]==585)
     {
        if(t==22)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[19]==537)
     {
        if(t==22)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[19]==539)
     {
        if(t==22)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }
          

           
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    if(dizi[20]==579)
      {
         if(t==23)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[20]==595)
      {
         if(t==23)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[20]==585)
      {
         if(t==23)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[20]==537)
      {
         if(t==23)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[20]==539)
      {
         if(t==23)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[20]==425)
      {
         if(t==23)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }



         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[21]==579)
     {
        if(t==24)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[21]==595)
     {
        if(t==24)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[21]==585)
     {
        if(t==24)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[21]==537)
     {
        if(t==24)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

       if(dizi[21]==539)
     {
        if(t==24)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[21]==425)
     {
        if(t==24)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }



         

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[22]==579)
      {
         if(t==25)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[22]==595)
      {
         if(t==25)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[22]==585)
      {
         if(t==25)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[22]==537)
      {
         if(t==25)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[22]==539)
      {
         if(t==25)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

       if(dizi[22]==425)
      {
         if(t==25)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
       }

           ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[23]==579)
     {
        if(t==26)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[23]==595)
     {
        if(t==26)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[23]==585)
     {
        if(t==26)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

       if(dizi[23]==537)
     {
        if(t==26)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[23]==539)
     {
        if(t==26)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }

      if(dizi[23]==425)
     {
        if(t==26)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
      }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[24]==579 || dizi[24]==595 || dizi[24]==537 || dizi[24]==425 || dizi[24]==585 || dizi[24]==539)
     {
        if(t==27)
         {
         t=t+1;
         s=s+1;
         }
         /*
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 54);
         u8g.print("BUMBO 2 TL 35GR");
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
         */
      }
           
   }

  //////////////////////****************************************       5.SAYFA        *******************//////////////////////////////////////////////////////////////////////////////////////

if(s==4)
{
  if(dizi[24]==425)
    {
        if(t==28)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }


    if(dizi[24]==579)
      {
          if(t==28)
           {
      
             toplam2+=2;
             agirlik+=35;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[24]==595)
      {
          if(t==28)
           {
      
             toplam2+=1;
             agirlik+=35;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[24]==585)
      {
          if(t==28)
           {
      
             toplam2+=0.75;
             agirlik+=60.50;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[24]==537)
      {
          if(t==28)
           {
      
             toplam2+=1.5;
             agirlik+=35;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[24]==539)
      {
          if(t==28)
           {
      
             toplam2+=1;
             agirlik+=100;
             t=t+1;
           }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 7);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }


         
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          
    
   if(dizi[25]==425)
     {
        if(t==29)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 16);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }
        


     if(dizi[25]==579)
      {
        if(t==29)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

       if(dizi[25]==595)
      {
        if(t==29)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

       if(dizi[25]==585)
      {
        if(t==29)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

       if(dizi[25]==537)
      {
        if(t==29)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

        if(dizi[25]==539)
      {
        if(t==29)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0,16);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }
          

           
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


   if(dizi[26]==579)
     {
        if(t==30)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     if(dizi[26]==595)
     {
        if(t==30)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

      if(dizi[26]==585)
     {
        if(t==30)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     if(dizi[26]==537)
     {
        if(t==30)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     if(dizi[26]==539)
     {
        if(t==30)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     if(dizi[26]==425)
     {
        if(t==30)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 25);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }


         //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[27]==579)
      {
        if(t==31)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

       if(dizi[27]==595)
      {
        if(t==31)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

       if(dizi[27]==585)
      {
        if(t==31)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

       if(dizi[27]==537)
      {
        if(t==31)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

       if(dizi[27]==539)
      {
        if(t==31)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }

       if(dizi[27]==425)
      {
        if(t==31)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 34);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
       }


         

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[28]==579)
     {
        if(t==32)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[28]==595)
     {
        if(t==32)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[28]==585)
     {
        if(t==32)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[28]==537)
     {
        if(t==32)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[28]==539)
     {
        if(t==32)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

      if(dizi[28]==425)
     {
        if(t==32)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 43);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
      }

           ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   if(dizi[29]==579)
    {
        if(t==33)
         {
         toplam2+=2;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(bumbo);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     
     if(dizi[29]==595)
    {
        if(t==33)
         {
         toplam2+=1;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(caramio);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     if(dizi[29]==585)
    {
        if(t==33)
         {
         toplam2+=0.75;
         agirlik+=60.50;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(popkek);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     if(dizi[29]==537)
    {
        if(t==33)
         {
         toplam2+=1.5;
         agirlik+=35;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(dido);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     if(dizi[29]==539)
    {
        if(t==33)
         {
         toplam2+=1;
         agirlik+=100;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(su);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }

     if(dizi[29]==425)
    {
        if(t==33)
         {
         toplam2+=1.5;
         agirlik+=20;
         t=t+1;
         }
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 52);
         u8g.print(mendil);
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-4); u8g.print("ADET");
     }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(dizi[30]==579)
     {
        if(t==34)
         {
         t=t+1;
         s=s+1;
         }
         /*
         u8g.setFont(u8g_font_6x10);
         u8g.setPrintPos(0, 54);
         u8g.print("BUMBO 2 TL 35GR");
         u8g.setFont(u8g_font_6x13);
         u8g.setPrintPos(0, 64);
         u8g.print(toplam2); u8g.print("TL,"); u8g.print(agirlik);u8g.print("GR,"); u8g.print(t-3); u8g.print("ADET");
         */
         
         
         
     }
     
}
         

}

