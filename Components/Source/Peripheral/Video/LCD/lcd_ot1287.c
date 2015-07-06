/*
ot1287 lcd
*/
#include "System.h"
#include "Nand.h"
#include "Display.h"

 void init_ot1287_lcd()
{
	printf("ot1287\n");
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x00);
	GP_COMMAD_PA(4);SPI_WriteData(0xff);SPI_WriteData(0x12);SPI_WriteData(0x84);SPI_WriteData(0x01);	//EXTC=1

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x80);	        //Orise mode enable
	GP_COMMAD_PA(3);SPI_WriteData(0xff);SPI_WriteData(0x12);SPI_WriteData(0x84);

//-------------------- panel setting --------------------//
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x80);             //TCON Setting
	GP_COMMAD_PA(10);SPI_WriteData(0xc0);SPI_WriteData(0x00);SPI_WriteData(0x64);SPI_WriteData(0x00);SPI_WriteData(0x10);SPI_WriteData(0x10);SPI_WriteData(0x00);SPI_WriteData

(0x64);SPI_WriteData(0x10);SPI_WriteData(0x10);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x90);             //Panel Timing Setting
	GP_COMMAD_PA(7);SPI_WriteData(0xc0);SPI_WriteData(0x00);SPI_WriteData(0x60);SPI_WriteData(0x00);SPI_WriteData(0x01);SPI_WriteData(0x00);SPI_WriteData(0x04);  //Hold Time 3u 0x52

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xa4);             //source pre. 
	GP_COMMAD_PA(2);SPI_WriteData(0xc0);SPI_WriteData(0x09);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb3);             //Interval Scan Frame: 0 frame);SPI_WriteData( column inversion
	GP_COMMAD_PA(3);SPI_WriteData(0xc0);SPI_WriteData(0x00);SPI_WriteData(0x55);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x81);             //frame rate:60Hz
	GP_COMMAD_PA(2);SPI_WriteData(0xc1);SPI_WriteData(0x55);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xB4);             //COLOUM  INVERSION
	GP_COMMAD_PA(2);SPI_WriteData(0xC0);SPI_WriteData(0x55);				

//-------------------- power setting --------------------//
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xa0);             //dcdc setting
	GP_COMMAD_PA(15);SPI_WriteData(0xc4);SPI_WriteData(0x05);SPI_WriteData(0x10);SPI_WriteData(0x06);SPI_WriteData(0x02);SPI_WriteData(0x05);SPI_WriteData(0x15);SPI_WriteData

(0x10);SPI_WriteData(0x05);SPI_WriteData(0x10);SPI_WriteData(0x07);SPI_WriteData(0x02);SPI_WriteData(0x05);SPI_WriteData(0x15);SPI_WriteData(0x10);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb0);             //clamp voltage setting
	GP_COMMAD_PA(3);SPI_WriteData(0xc4);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x91);             //VGH=15V);SPI_WriteData( VGL=-10V);SPI_WriteData( pump ratio:VGH=6x);SPI_WriteData( VGL=-5x
	GP_COMMAD_PA(3);SPI_WriteData(0xc5);SPI_WriteData(0x46);SPI_WriteData(0x42);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x00);             //GVDD=5.008V);SPI_WriteData( NGVDD=-5.008V
	GP_COMMAD_PA(3);SPI_WriteData(0xd8);SPI_WriteData(0xc7);SPI_WriteData(0xc7);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x00);             //VCOMDC=-1.62
	GP_COMMAD_PA(2);SPI_WriteData(0xd9);SPI_WriteData(0x80);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb3);             //VDD_18V=1.7V);SPI_WriteData( LVDSVDD=1.6V
	GP_COMMAD_PA(2);SPI_WriteData(0xc5);SPI_WriteData(0x84);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xbb);             //LVD voltage level setting
	GP_COMMAD_PA(2);SPI_WriteData(0xc5);SPI_WriteData(0x8a);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x82);             //chopper
	GP_COMMAD_PA(2);SPI_WriteData(0xc4);SPI_WriteData(0x0a);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xc6);		        //debounce 
	GP_COMMAD_PA(2);SPI_WriteData(0xB0);SPI_WriteData(0x03); 

	//GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xc2);             //precharge disable
	//GP_COMMAD_PA(2);SPI_WriteData(0xf5);SPI_WriteData(0x40);             //0x40 Disable 

	//GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xc3);             //sample hold gvdd
	//GP_COMMAD_PA(2);SPI_WriteData(0xf5);SPI_WriteData(0x85);

//-------------------- control setting --------------------//
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x00);             //ID1
	GP_COMMAD_PA(2);SPI_WriteData(0xd0);SPI_WriteData(0x40);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x00);             //ID2);SPI_WriteData( ID3
	GP_COMMAD_PA(3);SPI_WriteData(0xd1);SPI_WriteData(0x00);SPI_WriteData(0x00);

//-------------------- panel timing state control --------------------//
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x80); 
	GP_COMMAD_PA(12);SPI_WriteData(0xcb);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x90); 
	GP_COMMAD_PA(16);SPI_WriteData(0xcb);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xa0); 
	GP_COMMAD_PA(16);SPI_WriteData(0xcb);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb0);  
	GP_COMMAD_PA(16);SPI_WriteData(0xcb);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xc0); 
	GP_COMMAD_PA(16);SPI_WriteData(0xcb);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x05);SPI_WriteData(0x05);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xd0); 
	GP_COMMAD_PA(16);SPI_WriteData(0xcb);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xe0);
	GP_COMMAD_PA(15);SPI_WriteData(0xcb);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x05);SPI_WriteData

(0x05);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xf0);
	GP_COMMAD_PA(12);SPI_WriteData(0xcb);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData

(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);

//-------------------- panel pad mapping control --------------------//

   GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x80); 
	GP_COMMAD_PA(16);SPI_WriteData(0xcc);SPI_WriteData(0x0E);SPI_WriteData(0x10);SPI_WriteData(0x0A);SPI_WriteData(0x0C);SPI_WriteData(0x02);SPI_WriteData(0x04);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x2E);SPI_WriteData(0x2D);SPI_WriteData(0x00);SPI_WriteData(0x29);SPI_WriteData(0x2A);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x90);    
	GP_COMMAD_PA(16);SPI_WriteData(0xcc);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x0D);SPI_WriteData(0x0F);SPI_WriteData(0x09);SPI_WriteData(0x0B);SPI_WriteData(0x01);SPI_WriteData(0x03);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xa0); 
	GP_COMMAD_PA(15);SPI_WriteData(0xcc);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x2E);SPI_WriteData(0x2D);SPI_WriteData(0x00);SPI_WriteData(0x29);SPI_WriteData

(0x2A);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);




	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb0); 
	GP_COMMAD_PA(16);SPI_WriteData(0xcc);SPI_WriteData(0x0B);SPI_WriteData(0x09);SPI_WriteData(0x0F);SPI_WriteData(0x0D);SPI_WriteData(0x03);SPI_WriteData(0x01);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x2D);SPI_WriteData(0x2E);SPI_WriteData(0x00);SPI_WriteData(0x29);SPI_WriteData(0x2A);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xc0); 
	GP_COMMAD_PA(16);SPI_WriteData(0xcc);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x0C);SPI_WriteData(0x0A);SPI_WriteData(0x10);SPI_WriteData(0x0E);SPI_WriteData(0x04);SPI_WriteData(0x02);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xd0);  
	GP_COMMAD_PA(15);SPI_WriteData(0xcc);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x2D);SPI_WriteData(0x2E);SPI_WriteData(0x00);SPI_WriteData(0x29);SPI_WriteData

(0x2A);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);
    

   
   
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb5);             //TCON_GOA_OUT Setting
	GP_COMMAD_PA(7);SPI_WriteData(0xc5);SPI_WriteData(0x00);SPI_WriteData(0x6f);SPI_WriteData(0xfF);SPI_WriteData(0x00);SPI_WriteData(0x6f);SPI_WriteData(0xfF);

   
	


//-------------------- panel timing setting --------------------//
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x80);             //panel VST setting
	GP_COMMAD_PA(13);SPI_WriteData(0xce);SPI_WriteData(0x8B);SPI_WriteData(0x03);SPI_WriteData(0x18);SPI_WriteData(0x8A);SPI_WriteData(0x03);SPI_WriteData(0x18);SPI_WriteData

(0x89);SPI_WriteData(0x03);SPI_WriteData(0x18);SPI_WriteData(0x88);SPI_WriteData(0x03);SPI_WriteData(0x18);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x90);             //panel VEND setting
	GP_COMMAD_PA(15);SPI_WriteData(0xce);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);


	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xa0);             //panel CLKA1/2 setting
	GP_COMMAD_PA(15);SPI_WriteData(0xce);SPI_WriteData(0x38);SPI_WriteData(0x07);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x18);SPI_WriteData

(0x00);SPI_WriteData(0x38);SPI_WriteData(0x06);SPI_WriteData(0x05);SPI_WriteData(0x01);SPI_WriteData(0x00);SPI_WriteData(0x18);SPI_WriteData(0x00);
   

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb0);             //panel CLKA3/4 setting
	GP_COMMAD_PA(15);SPI_WriteData(0xce);SPI_WriteData(0x38);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x02);SPI_WriteData(0x00);SPI_WriteData(0x18);SPI_WriteData

(0x00);SPI_WriteData(0x38);SPI_WriteData(0x04);SPI_WriteData(0x05);SPI_WriteData(0x03);SPI_WriteData(0x00);SPI_WriteData(0x18);SPI_WriteData(0x00);
   

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xc0);             //panel CLKb1/2 setting
	GP_COMMAD_PA(15);SPI_WriteData(0xce);SPI_WriteData(0x38);SPI_WriteData(0x03);SPI_WriteData(0x05);SPI_WriteData(0x04);SPI_WriteData(0x00);SPI_WriteData(0x18);SPI_WriteData

(0x00);SPI_WriteData(0x38);SPI_WriteData(0x02);SPI_WriteData(0x05);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x18);SPI_WriteData(0x00);
   

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xd0);             //panel CLKb3/4 setting
	GP_COMMAD_PA(15);SPI_WriteData(0xce);SPI_WriteData(0x38);SPI_WriteData(0x01);SPI_WriteData(0x05);SPI_WriteData(0x06);SPI_WriteData(0x00);SPI_WriteData(0x18);SPI_WriteData

(0x00);SPI_WriteData(0x38);SPI_WriteData(0x00);SPI_WriteData(0x05);SPI_WriteData(0x07);SPI_WriteData(0x00);SPI_WriteData(0x18);SPI_WriteData(0x00);
   


	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x80);             //panel CLKc1/2 setting
	GP_COMMAD_PA(15);SPI_WriteData(0xcf);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x90);             //panel CLKc3/4 setting
	GP_COMMAD_PA(15);SPI_WriteData(0xcf);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xa0);             //panel CLKd1/2 setting
	GP_COMMAD_PA(15);SPI_WriteData(0xcf);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb0);             //panel CLKd3/4 setting
	GP_COMMAD_PA(15);SPI_WriteData(0xcf);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xc0);             //panel ECLK setting
	GP_COMMAD_PA(12);SPI_WriteData(0xcf);SPI_WriteData(0x3D);SPI_WriteData(0x02);SPI_WriteData(0x15);SPI_WriteData(0x20);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData

(0x01);SPI_WriteData(0x81);SPI_WriteData(0x00);SPI_WriteData(0x03);SPI_WriteData(0x08); //gate pre. ena.


     
                                                                                                                           
                                                                                                                           
//-------------------- for Power IC --------------------//                                                                 
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x90);             //Mode-3                                                                
	GP_COMMAD_PA(5);SPI_WriteData(0xf5);SPI_WriteData(0x02);SPI_WriteData(0x11);SPI_WriteData(0x02);SPI_WriteData(0x11);                                                                      
                                                                                                                                                                                   
                                                                                                                           
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x90);             //2xVPNL                                                                
	GP_COMMAD_PA(2);SPI_WriteData(0xc5);SPI_WriteData(0x50);                                                                                     
                                                                                                                           
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x94);             //Freq.                                                                 
	GP_COMMAD_PA(2);SPI_WriteData(0xc5);SPI_WriteData(0x66);                                                                                     
                                                                                                                           
                                                                                                                           
                                                                                                                           
                                                                                                                           
//------------------VGLO1/O2 disable----------------                                                                       
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb2);             //VGLO1                                                                 
	GP_COMMAD_PA(3);SPI_WriteData(0xf5);SPI_WriteData(0x00);SPI_WriteData(0x00);                                                                                
                                                                                                                           
	//GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb4);             //VGLO1_S                                                               
	//GP_COMMAD_PA(3);SPI_WriteData(0xf5);SPI_WriteData(0x00);SPI_WriteData(0x00);                                                                                
                                                                                                                           
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb6);             //VGLO2                                                                 
	GP_COMMAD_PA(3);SPI_WriteData(0xf5);SPI_WriteData(0x00);SPI_WriteData(0x00);                                                                                
                                                                                                                           
	//GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb8);             //VGLO2_S                                                               
	//GP_COMMAD_PA(3);SPI_WriteData(0xf5);SPI_WriteData(0x00);SPI_WriteData(0x00);                                                                                
                                                                                                                           
	//GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x94);  		//VCL on  	                                                                  
	//GP_COMMAD_PA(2);SPI_WriteData(0xF5);SPI_WriteData(0x02);
	                                                                                     
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x94);  		//VCL off  	                                                                  
	GP_COMMAD_PA(3);SPI_WriteData(0xF5);SPI_WriteData(0x00);SPI_WriteData(0x00);    
	                                                                                 
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xd2);             //VCL reg. en
	GP_COMMAD_PA(3);SPI_WriteData(0xf5);SPI_WriteData(0x06);SPI_WriteData(0x15);
                                                                                                                           
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xBA);  		//VSP on   	                                                                  
	GP_COMMAD_PA(2);SPI_WriteData(0xF5);SPI_WriteData(0x03);                                                                                     
                                                                                                                           
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0xb4);       //VGLO1/2 Pull low setting                                              
   GP_COMMAD_PA(2);SPI_WriteData(0xc5);SPI_WriteData(0xc0);		   //d[7] vglo1 d[6] vglo2 => 0: pull vss);SPI_WriteData( 1: pull vgl                              
                  
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x93); //CD err sel. 
	GP_COMMAD_PA(2);SPI_WriteData(0xB0);SPI_WriteData(0x8C);
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x90); 
	GP_COMMAD_PA(2);SPI_WriteData(0xB6);SPI_WriteData(0xB6); //sleep out re-load
	GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x92); 
	GP_COMMAD_PA(2);SPI_WriteData(0xB3);SPI_WriteData(0x02); //HS auto Disable CMD1

   GP_COMMAD_PA(2);SPI_WriteData(0x00);SPI_WriteData(0x00);             //Orise mode disable
   GP_COMMAD_PA(4);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);SPI_WriteData(0xff);



 
	  	   
//ccmoff
//ccmrun

GP_COMMAD_PA(1);   SPI_WriteData(0x11);
Delay_ms(100);
GP_COMMAD_PA(1);   SPI_WriteData(0x29);
Delay_ms(200); 
}