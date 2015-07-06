/*********************************************************************
;* Project Name : s3c2443x
;*
;* Copyright 2006 by Samsung Electronics, Inc.
;* All rights reserved.
;*
;* Project Description :
;* This software is only for verifying functions of the s3c2443x
;* Anybody can use this code without our permission.
;**********************************************************************/


#include "System.h"
#include "Nand.h"
#include "Display.h"

//#define SDO GPE11
//#define SDI GPE12
//#define SCL GPE13
//#define CSX GPE14
//#define RST GPE15


void Delay_us(U32 us)
{
	while(us--) Delay(56);	
}

void Delay_ms(U32 ms)
{
	while(ms--) Delay(59360);	
}






uint16 * pFrameBuf = NULL;

void Set_RST(U32 index)
{
	if(index) rGPFDAT |= 0x0001;
	else      rGPFDAT &= ~0x0001;	
}

void Set_2805_CS(U32 index)
{
	if(index) rGPEDAT |= 0x8000;
	else      rGPEDAT &= ~0x8000;	
}

void Set_CSX(U32 index)
{
	if(index) rGPEDAT |= 0x4000;
	else      rGPEDAT &= ~0x4000;	
}

void Set_SCL(U32 index)
{
	if(index) rGPEDAT |= 0x2000;
	else      rGPEDAT &= ~0x2000;	
}

void Set_SDI(U32 index)
{
	if(index) rGPEDAT |= 0x1000;
	else      rGPEDAT &= ~0x1000;	
}


void SPI_Init(void)
{
	rGPECON &= 0x003FFFFF;	//Set GPE15~12 output,GPE11 input
	rGPECON |= 0x55000000;
	
	rGPEUDP &= 0x07FF;	//Set GPE15~11 pull-up
	
	
	Set_RST(1);
	Set_2805_CS(1);
	Set_CSX(1);
	Set_SCL(0);	
	Set_SDI(0);
	
	rGPFCON &= 0xFFFFFFFC;	//Set GPE15~12 output,GPE11 input
	rGPFCON |= 0x00000001;
	
	//rGPFUDP &= 0xFFFE;	//Set GPE0 pull-up
	
}

void SPI_3W_SET_Cmd(U8 cmd)
{
	U32 kk;
	
	Set_SDI(0);			//Set DC=0, for writing to Command register
	Set_SCL(0);
	Set_SCL(1);
	

	Set_SCL(0);
	for(kk=0;kk<8;kk++)
	{
		if((cmd&0x80)==0x80) Set_SDI(1);
		else         Set_SDI(0);
		Set_SCL(1);
		Set_SCL(0);
		cmd = cmd<<1;	
	}
}

void SPI_3W_SET_PAs(U8 value)
{
	U32 kk;

	Set_SDI(1);			//Set DC=1, for writing to Data register
	Set_SCL(0);
	Set_SCL(1);
//	Delay_us(1);	
	Set_SCL(0);
	for(kk=0;kk<8;kk++)
	{
		if((value&0x80)==0x80) Set_SDI(1);
		else         Set_SDI(0);
		Set_SCL(1);
		Set_SCL(0);
		value = value<<1;	
	}	
}
//-----------------------------------------------------
void Write_com(U16 vv)
{
	Set_2805_CS(0);
	SPI_3W_SET_Cmd(vv&0xff);	
}

void Write_register(U16 vv)
{
	SPI_3W_SET_PAs(vv&0xff);
	SPI_3W_SET_PAs((vv>>8)&0xff);	
}
//-----------------------------------------------------

void writec(U8 cmd)
{
		U32 kk;
	
	Set_2805_CS(0);
	
	Set_SDI(0);			//Set DC=0, for writing to Command register
	Set_SCL(0);
	Set_SCL(1);
	

	Set_SCL(0);
	for(kk=0;kk<8;kk++)
	{
		if((cmd&0x80)==0x80) Set_SDI(1);
		else         Set_SDI(0);
		Set_SCL(1);
		Set_SCL(0);
		cmd = cmd<<1;	
	}
	
	Set_2805_CS(1);		
}

void writed(U8 cmd)
{
		U32 kk;
	
	Set_2805_CS(0);
	
	Set_SDI(1);			//Set DC=0, for writing to Command register
	Set_SCL(0);
	Set_SCL(1);
	

	Set_SCL(0);
	for(kk=0;kk<8;kk++)
	{
		if((cmd&0x80)==0x80) Set_SDI(1);
		else         Set_SDI(0);
		Set_SCL(1);
		Set_SCL(0);
		cmd = cmd<<1;	
	}
	
	Set_2805_CS(1);		
}

void SPI_2825_WrCmd(U8 cmd)
{
	U32 kk;
	
	Set_2805_CS(0);
	
	Set_SDI(0);			//Set DC=0, for writing to Command register
	Set_SCL(0);
	Set_SCL(1);
	

	Set_SCL(0);
	for(kk=0;kk<8;kk++)
	{
		if((cmd&0x80)==0x80) Set_SDI(1);
		else         Set_SDI(0);
		Set_SCL(1);
		Set_SCL(0);
		cmd = cmd<<1;	
	}
	
	Set_2805_CS(1);	
}

//void SPI_2825_WrCmd(U8)
void SPI_2825_WrReg(U8 c,U16 value)
{
	Set_2805_CS(0);
	SPI_3W_SET_Cmd(c);
	SPI_3W_SET_PAs(value&0xff);
	SPI_3W_SET_PAs((value>>8)&0xff);	
	Set_2805_CS(1);	
}



U8 Read_PAs(void)
{
	U32 kk;
	U8  rdValue;

//	Set_SCL(0);
	rdValue = 0;
	for(kk=0;kk<8;kk++)
	{
		rdValue = rdValue<<1;
		
		Set_SCL(1);
		if(rGPEDAT&0x0800)  rdValue |= 0x01;
		Set_SCL(0);
	}
//	Set_CSX(0);

	return rdValue;	
}

U16   SPI_READ(U8 cmd)
{
	U8  rdT;
	U16 reValue;
	U32 kk;
	
	Set_2805_CS(0);

	Set_SDI(0);			//Set DC=0, for writing to Command register
	Set_SCL(0);
	Set_SCL(1);
	

//	cmd = 0xB0;
	Set_SCL(0);
	for(kk=0;kk<8;kk++)
	{
		if((cmd&0x80)==0x80) Set_SDI(1);
		else         Set_SDI(0);
		Set_SCL(1);
		Set_SCL(0);
		cmd = cmd<<1;	
	}
	
	Set_SDI(0);			//Set DC=0, for writing to Command register
	Set_SCL(0);
	Set_SCL(1);
	

	cmd = 0xFA;
	Set_SCL(0);
	for(kk=0;kk<8;kk++)
	{
		if((cmd&0x80)==0x80) Set_SDI(1);
		else         Set_SDI(0);
		Set_SCL(1);
		Set_SCL(0);
		cmd = cmd<<1;	
	}	
	
	rdT=0;
	for(kk=0;kk<8;kk++)
	{
		rdT = rdT<<1;
		Set_SCL(1);
		if(rGPEDAT&0x0800) rdT |= 0x01;
		Set_SCL(0);				
	}
	
	reValue = rdT;
	//reValue = (reValue<<8)&0xFF00;
	
	rdT=0;
	for(kk=0;kk<8;kk++)
	{
		rdT = rdT<<1;
		Set_SCL(1);
		if(rGPEDAT&0x0800) rdT |= 0x01;
		Set_SCL(0);				
	}
	
	reValue += (rdT<<8);
	
	Set_2805_CS(1);
	
	return reValue;			
}

U16   SPI_READ_ID(U8 cmd)
{
	SPI_2825_WrReg(0xd4, 0x00FA);
	if (cmd == 0xb0)
		printf("2828 ID: 0x%x\n",SPI_READ(cmd));
	return SPI_READ(cmd);
}


void SPI_WriteData(U8 value)
{
//	printf("-%2x",value);
	Set_2805_CS(0);
	SPI_3W_SET_PAs(value);
	Set_2805_CS(1);	
}


void GP_COMMAD_PA(U16 num)
{

 

         	SPI_2825_WrReg(0xbc, num);
	    	Write_com(0x00bd);
			SPI_2825_WrReg(0xbe, num);
        	Write_com(0x00bf);
        	Set_2805_CS(1);	
}
static void GP_COMMAD_PA_READ()
{
	U16 i,count;
	SPI_2825_WrReg(0xB7,0x382);
    SPI_2825_WrReg(0xBC,0x01);
    SPI_2825_WrReg(0xBF,0x0a);
	Delay_ms(10);
	printf("C6:0x%X\n",SPI_READ_ID(0xC6));
 	count = SPI_READ_ID(0xC2);
 	printf("readnum:0x%X ",count);
    if (count >100) count =100;
    for (i=0;i<count;i++)
    {
        printf("data[%d]:0x%X ",i,SPI_READ_ID(0xFF));
    } printf("\n");
}




void Init_SSD2805_SPI(void)
{
	U16 count;
	U16 i;
	Set_RST(0);// ( rGPFDAT &= (~(1<<3))) ;
	Delay_ms(100);
	Set_RST(1);//  ( rGPFDAT |= (1<<3) ) ;
	Delay_ms(100);
	
	//void SPI_2825_WrCmd(U8)
	//void SPI_2825_WrReg(U8 c,U16 value)
	//Initial code 1: SSD2825 initialization
	//RGB interface configuration 
    SPI_2825_WrCmd(0xb7);
			        SPI_WriteData(0x50);//50=TX_CLK 70=PCLK
			        SPI_WriteData(0x00);   //Configuration Register

			        SPI_2825_WrCmd(0xb8);
			        SPI_WriteData(0x00);
			        SPI_WriteData(0x00);   //VC(Virtual ChannelID) Control Register

			        SPI_2825_WrCmd(0xb9);
			        SPI_WriteData(0x00);//1=PLL disable
			        SPI_WriteData(0x00);
                               //TX_CLK/MS should be between 5Mhz to100Mhz
			        SPI_2825_WrCmd(0xBA);//PLL=(TX_CLK/MS)*NS 8228=480M 4428=240M  061E=120M 4214=240M 821E=360M 8219=300M
			        SPI_WriteData(0x14);//D7-0=NS(0x01 : NS=1)
			        SPI_WriteData(0x42);//D15-14=PLL范围 00=62.5-125 01=126-250 10=251-500 11=501-1000  DB12-8=MS(01:MS=1)

			        SPI_2825_WrCmd(0xBB);//LP Clock Divider LP clock = 400MHz / LPD / 8 = 240 / 8 / 4 = 7.5MHz
			        SPI_WriteData(0x03);//D5-0=LPD=0x1 – Divide by 2
			        SPI_WriteData(0x00);

			        SPI_2825_WrCmd(0xb9);
			       	SPI_WriteData(0x01);//1=PLL disable
			       	SPI_WriteData(0x00);
			        //MIPI lane configuration
			            	SPI_2825_WrCmd(0xDE);//通道数
			            	SPI_WriteData(0x00);//11=4LANE 10=3LANE 01=2LANE 00=1LANE   00	  
			            	SPI_WriteData(0x00);

			        SPI_2825_WrCmd(0xc9);
			        SPI_WriteData(0x02);
			        SPI_WriteData(0x23);   //p1: HS-Data-zero  p2: HS-Data- prepare  --> 8031 issue
			        Delay_ms(100);

//LCD driver initialization
						GP_COMMAD_PA_READ();
                  SPI_2825_WrCmd(0xB7);
                  SPI_WriteData(0x10);
                  SPI_WriteData(0x02);
                  SPI_2825_WrCmd(0xBD);
                  SPI_WriteData(0x00);
                  SPI_WriteData(0x00);
	
	/*************************************************/
//	init_buy_lcd();	
//	init_ot1287_lcd();
//	init_xinli_lcd();
	init_bp070wx1_lcd();
	/**************************************************/
//	GP_COMMAD_PA_READ();
	//SSD2825_Initial
//SSD2825_Initial
SPI_2825_WrCmd(0xb7);
SPI_WriteData(0x50);
SPI_WriteData(0x00);   //Configuration Register

SPI_2825_WrCmd(0xb8);
SPI_WriteData(0x00);
SPI_WriteData(0x00);   //VC(Virtual ChannelID) Control Register

SPI_2825_WrCmd(0xb9);
SPI_WriteData(0x00);//1=PLL disable
SPI_WriteData(0x00);

SPI_2825_WrCmd(0xBA);//PLL=(TX_CLK/MS)*NS 8228=480M 4428=240M  061E=120M 4214=240M 821E=360M 8219=300M 8225=444M 8224=432
SPI_WriteData(0x2b);//D7-0=NS(0x01 : NS=1)   //0X28
SPI_WriteData(0x82);//D15-14=PLL范围 00=62.5-125 01=126-250 10=251-500 11=501-1000  DB12-8=MS(01:MS=1) //0X82

SPI_2825_WrCmd(0xBB);//LP Clock Divider LP clock = 400MHz / LPD / 8 = 480 / 8/ 8 = 7.5MHz
SPI_WriteData(0x07);//D5-0=LPD=0x1 – Divide by 2
SPI_WriteData(0x00);

SPI_2825_WrCmd(0xb9);
SPI_WriteData(0x01);//1=PLL disable
SPI_WriteData(0x00);

SPI_2825_WrCmd(0xc9);
SPI_WriteData(0x02);
SPI_WriteData(0x23);   //p1: HS-Data-zero  p2: HS-Data- prepare  --> 8031 issue
Delay_ms(5);

SPI_2825_WrCmd(0xCA);
SPI_WriteData(0x01);//CLK Prepare
SPI_WriteData(0x23);//Clk Zero

SPI_2825_WrCmd(0xCB); //local_write_reg(addr=0xCB,data=0x0510)
SPI_WriteData(0x10); //Clk Post
SPI_WriteData(0x05); //Clk Per

SPI_2825_WrCmd(0xCC); //local_write_reg(addr=0xCC,data=0x100A)
SPI_WriteData(0x05); //HS Trail
SPI_WriteData(0x10); //Clk Trail
Delay_ms(5);

SPI_2825_WrCmd(0xD0); //local_write_reg(addr=0xCC,data=0x100A)
SPI_WriteData(0x00); //HS Trail
SPI_WriteData(0x00); //Clk Trail
Delay_ms(5);


//RGB interface configuration
/*SPI_2825_WrReg(0xb1,(5<<8)|2);      //Vertical sync and horizontal sync active period 
        SPI_2825_WrReg(0xb2,(8<<8)|24); //Vertical and horizontal back porch period  
        SPI_2825_WrReg(0xb3,(25<<8)|1); //Vertical and horizontal front porch period 
        SPI_2825_WrReg(0xb4, 720);              //Horizontal active period 
        SPI_2825_WrReg(0xb5, 1280) ;*/
        
        SPI_2825_WrReg(0xb1,(LCD_VSPW<<8)|LCD_HSPW);      //Vertical sync and horizontal sync active period 
        SPI_2825_WrReg(0xb2,(LCD_VBPD<<8)|LCD_HBPD); //Vertical and horizontal back porch period  
        SPI_2825_WrReg(0xb3,(LCD_VFPD<<8)|LCD_HFPD); //Vertical and horizontal front porch period 
        SPI_2825_WrReg(0xb4, LCD_XSIZE_TFT);              //Horizontal active period 
        SPI_2825_WrReg(0xb5, LCD_YSIZE_TFT) ;

	
SPI_2825_WrCmd(0xB6);//通道数
SPI_WriteData(0x03);//11=4LANE 10=3LANE 01=2LANE 00=1LANE		 03
SPI_WriteData(0x00);
//MIPI lane configuration
SPI_2825_WrCmd(0xDE);//通道数
SPI_WriteData(0x03);//11=4LANE 10=3LANE 01=2LANE 00=1LANE	  03
SPI_WriteData(0x00);

SPI_2825_WrCmd(0xD6);//  05=BGR  04=RGB
SPI_WriteData(0x04);//D0=0=RGB 1:BGR D1=1=Most significant byte sent first
SPI_WriteData(0x00);

SPI_2825_WrCmd(0xB7);
SPI_WriteData(0x4B); //0X4B
SPI_WriteData(0x02);Delay_ms(100);

SPI_2825_WrCmd(0x2C);
//Delay_ms(3000);
}



void SetLcdPort(void)		//2443 RGB端口初始化
{
 //uint8  pagewidth_in_byte=0,offsize_in_byte=0;
	uint8  clkval=0;
	uint16 hcync_cnt,vclk_cnt;
	uint16 lcd_horizon_value,lcd_line_value;
	uint8  lcd_vbpd,lcd_vfpd,lcd_vspw,lcd_hbpd,lcd_hfpd,lcd_hspw;
	uint8  lcd_frame_rate;	
	
	//uint16 tmp, k;
	uint32 i,j;	


	// Set up the LCD controller registers to display a power-on bitmap image.
	rMISCCR |= (1<<28);  // select LCD controller for TFT lcd controller
	
	// set gpio for lcd
	//rGPCCON = 0xaaaaaaaa;	// CTRL,  VD[7:0]
	//rGPDCON = 0xaaaaaaaa;	// VD[23:8]
	
	rGPCCON = 0xaa95aaaa;	// CTRL,  VD[7:0]
	rGPDCON = 0xaa95aaa5;	// VD[23:8]
	
	rGPCDAT &= 0xF8FF;
	rGPDDAT &= 0xF8FC;

	rGPBCON &= 0xFFFFFF3F;
	rGPBCON |= 0x00000040;	//Set GPB3 output
	
	rGPBDAT &= ~0x00000008;	//Set GPB3=1, ON BackLight
	
	
	lcd_horizon_value = LCD_HOZVAL;
	lcd_line_value    = LCD_LINEVAL;
	lcd_vbpd          = LCD_VBPD+ 1;
	lcd_vfpd          = LCD_VFPD+ 1;
	lcd_vspw          = LCD_VSPW+ 1;
	lcd_hbpd          = LCD_HBPD+ 1;
	lcd_hfpd          = LCD_HFPD+ 1;
	lcd_hspw          = LCD_HSPW+ 1;
	lcd_frame_rate    = LCD_FRAME_RATE;       	
/*
	pagewidth_in_byte = lcd_horizon_value/8*16;	
	if((pagewidth_in_byte%16)!=0)
	{
		pagewidth_in_byte += 16 - (pagewidth_in_byte%16);
	}
	offsize_in_byte = 0;*/
	
	//LcdWindowOnOff(LCD_WIN_ALL,LCD_OFF);	
	rWINCON0 &= ~0x01;
	rWINCON1 &= ~0x01;
	
	//LcdEnvidOnOff(LCD_OFF);
	rVIDCON0 &= (~3); //ENVID Off using Per Frame method

	//Basic_Display_Setting(window,WINCONx_16BPP_565,lcd_horizon_value,0);	
	rVIDCON0 = VIDCON0_S_RGB_IF|VIDCON0_S_RGB_PAR|VIDCON0_S_VCLK_GATING_OFF|VIDCON0_S_CLKDIR_DIVIDED|VIDCON0_S_CLKSEL_HCLK;
	
	hcync_cnt = (lcd_vbpd+lcd_vfpd+lcd_vspw+lcd_line_value);
	vclk_cnt = (lcd_hbpd+lcd_hfpd+lcd_hspw+lcd_horizon_value);
	                                              //525*286*60
	clkval = (uint8)(((float)S3C2443_HCLK/(float)(hcync_cnt*vclk_cnt*lcd_frame_rate))+0.5)-1;	
	
	rVIDCON0 |= (clkval <<VIDCON0_CLKVAL_F_SHIFT);
	//rVIDCON0 |= (0 <<VIDCON0_CLKVAL_F_SHIFT);

	//check point	

//#elif (LCD_MODULE_TYPE == TFT480_272_SHARP)
//	rVIDCON1 = VIDCON1_S_HSYNC_INVERTED|VIDCON1_S_VSYNC_INVERTED|VIDCON1_S_VCLK_FALL_EDGE_FETCH;
	
//#elif (LCD_MODULE_TYPE == TFT800_480_QIMEI)
//	rVIDCON1 = VIDCON1_S_HSYNC_INVERTED|VIDCON1_S_VSYNC_INVERTED;
//#elif (LCD_MODULE_TYPE == TFT800_600_QIMEI)
	rVIDCON1 = VIDCON1_S_HSYNC_INVERTED|VIDCON1_S_VSYNC_INVERTED|VIDCON1_S_VCLK_RISE_EDGE_FETCH;

	
	rVIDTCON0=((lcd_vbpd-1)<<VIDTCON0_BPD_S)|((lcd_vfpd-1)<<VIDTCON0_FPD_S)|(lcd_vspw-1);
	rVIDTCON1=((lcd_hbpd-1)<<VIDTCON0_BPD_S)|((lcd_hfpd-1)<<VIDTCON0_FPD_S)|(lcd_hspw-1);
	rVIDTCON2 = ((lcd_line_value-1)<<VIDTCON2_LINEVAL_S)|(lcd_horizon_value-1);
	
	//s2443LCD->WINCON0 = (0<<WINCON_BUFSEL)|(0<<WINCON_BUFAUTOEN)|(0<<WINCON_SWAP_S)|(WINCONx_4WORD_BURST<<WINCON_BURSTLEN_S)|(WINCONx_16BPP_565<<WINCON_BPP_S); // 4word burst, 16bpp, 
	rWINCON0 = (0<<WINCON_BUFSEL)|(0<<WINCON_BUFAUTOEN)|(0<<WINCON_SWAP_S)|(WINCONx_4WORD_BURST<<WINCON_BURSTLEN_S)|(WINCONx_16BPP_565<<WINCON_BPP_S); // 4word burst, 24bpp, WINCONx_24BPP_888
	rVIDOSD0A = (0<<VIDOSDxAB_HORIZON_X_S)|(0);
	rVIDOSD0B = ((lcd_horizon_value-1)<<VIDOSDxAB_HORIZON_X_S)|(lcd_line_value-1);	

	// buffer start address
	rVIDW00ADD0B0 = (uint32) IMAGE_FRAMEBUFFER_DMA_BASE;		
	// buffer end address
	//s2443LCD->VIDW00ADD1B0 = (UINT32)IMAGE_FRAMEBUFFER_DMA_BASE + (LCD_XSIZE_TFT*LCD_YSIZE_TFT*2);
	rVIDW00ADD1B0 = (uint32) IMAGE_FRAMEBUFFER_DMA_BASE + (LCD_XSIZE_TFT*LCD_YSIZE_TFT*2);
	// buffer size 
	//s2443LCD->VIDW00ADD2B0 = (offsize_in_byte<<VIDWxADD2_OFFSET_SIZE_S)|(LCD_XSIZE_TFT*2);
	rVIDW00ADD2B0 = (0<<VIDWxADD2_OFFSET_SIZE_S)|(LCD_XSIZE_TFT*2);	
	
	rWIN0MAP = 0;
	//s2443LCD->WINCON0 |= (1<<WINCON_SWAP_S);
		
	  


     ////////////////////////////////////////////////////////////////////////////////////////////
     //清空显示内存
     pFrameBuf = (uint16 *)IMAGE_FRAMEBUFFER_UA_BASE;
     for(j=0;j<LCD_YSIZE_TFT;j++)
     {
     		for(i=0;i<LCD_XSIZE_TFT;i++) *(pFrameBuf++) = 0x0000;	
	
     }

	//	rGPBDAT |= 0x00000008;	//Set GPB3=0, TURN OFF BackLight on mainboard
	
	rWINCON0 |= 0x1;
	rVIDCON0 |= 0x3;
	
}


void Display_Bmp(void )
{
	disp_bmp((U16 *)TFT_RAM2,0,0,XSIZE,YSIZE);	
}
//---------------------------------------------------------------------------------------
void disp_bmp(U16 *bmpbuf,int x0,int y0,int x1,int y1)
{
      int ii,jj;
      int bmpW,bmpH;
      U16 *p;
      
      p=(uint16 *)IMAGE_FRAMEBUFFER_UA_BASE;
      bmpW=x1;
      bmpH=y1;

      for(ii=0;ii<bmpH;ii++)
      {
      	//wrp=p+(ii+y0)*XSIZE+x0;      	     
            for(jj=0;jj<bmpW;jj++)
            {           
                  //*(p++)=bmpbuf[ii*bmpW+jj*2+1];
                  *(p++)=bmpbuf[ii*bmpW+jj];
            }
      }
}
//--------------------------------------------------------------------
void disp_color(U16 color,int x0,int y0,int x1,int y1)
{
      int ii,jj;
      U16 *p,*wrp;
      
      p=(uint16 *)IMAGE_FRAMEBUFFER_UA_BASE;    
      for(ii=0;ii<y1;ii++)
      {
      	wrp=p+(ii+y0)*XSIZE+x0;      	     
            for(jj=0;jj<x1;jj++)
            {        
                  
                  *(wrp++)=color;
            }
      }
}
//--------------------------------------------------------------------
U16 cb[8]=
{
0xF800, 0x07E0, 0x001f,0xFFE0,0xF81F,0x07FF, 0xFFFF,0x0000	
};

void disp_color_table(void)
{
      int ii,jj,kk;
      U16 *p;
      U32 xsNum,xeNum,xxNum;

      
      xxNum = XSIZE/8;
      xeNum = XSIZE - xxNum*7; 		//中间占用63灰阶
      
      
      p=(uint16 *)IMAGE_FRAMEBUFFER_UA_BASE;   
       
      for(ii=0;ii<YSIZE;ii++)		//R
      {
   	     
            
            for(jj=0;jj<7;jj++)
            {
            	for(kk=0;kk<xxNum;kk++) *(p++)= cb[jj];	
            }
            
            
            for(kk=0;kk<xeNum;kk++) *(p++)= cb[7];
      }

}

void disp_gray(void)
{
      int ii,jj,kk;
      U16 *p;
      U16 xsNum,xeNum,xxNum;
	U16 cc;
      
      xxNum = XSIZE/32;
      xsNum = (XSIZE - xxNum*30)/2; 		//中间占用63灰阶
      xeNum = XSIZE - xxNum*30 - xsNum;
      
      
      p=(uint16 *)IMAGE_FRAMEBUFFER_UA_BASE;   
       
      for(ii=0;ii<YSIZE;ii++)		//R
      {
   	     cc = 0x0000;
   	     for(kk=0;kk<xsNum;kk++) *(p++)= cc;
            
            for(jj=1;jj<31;jj++)
            {
            	cc =(jj<<11)+(jj<<6) +jj;
            	for(kk=0;kk<xxNum;kk++) *(p++)= cc;	
            }
            
            cc = 0xFFFF;
            for(kk=0;kk<xeNum;kk++) *(p++)= cc;

      }

}



void disp_frame(void)
{
	int ii,jj;
      U16 *p;
      
      p=(U16 *)IMAGE_FRAMEBUFFER_UA_BASE;   
       
      for(ii=0;ii<YSIZE;ii++)
      {
   	     	if(ii==0) 
   	     	{
   	     		for(jj=0;jj<XSIZE;jj++)	 *(p++)=0x00ffffff;
   	     	}
   	     	else if(ii== (YSIZE-1))
   	     	{
   	     		for(jj=0;jj<XSIZE;jj++)	 *(p++)=0x00ffffff;	
   	     	}
    	      else
    	      {
    	      	for(jj=0;jj<XSIZE;jj++)	 
    	      	{
    	      		if(jj==0 )       		*(p++)=0x00ffffff;
    	      		else if(jj==(XSIZE-1))  *(p++)=0x00ffffff;    	      		
    	      		else             		*(p++)=0x00000000;	
    	      	}	
    	      }
      }
}

U16 wbColor[2] = 
{
0x0000,0xFFFF	
};
/*===========================================================================
** 函数名称: disp_9WB() 
** 功能描述: 实现黑白格子
============================================================================*/


void disp_9WB(void)//九宫格的函数
{
      int ii,jj,kk,mm;
      U16 *p;
      U16 xsNum,xeNum,xxNum;
      U16 ysNum,yeNum,yyNum;
	U16 cc[2];
      
      xxNum = XSIZE/8;
      xeNum = XSIZE - xxNum*7;
      yyNum = YSIZE/8;
      yeNum = YSIZE - yyNum*7;
      
      
      p=(uint16 *)IMAGE_FRAMEBUFFER_UA_BASE;   
       
      for(ii=0;ii<7;ii++)		//R
      {
           cc[0] = wbColor[ii%2];
           cc[1] = wbColor[(ii+1)%2];
		
		for(mm=0;mm<yyNum;mm++)
		{
			for(jj=0;jj<7;jj++)
   	     		{
   	     			for(kk=0;kk<xxNum;kk++) *(p++)= cc[jj%2];	
   	     		}
   	     
   	     		for(kk=0;kk<xeNum;kk++) *(p++)= cc[1];	
		}  
      }
      
      ii=7;
      
      cc[0] = wbColor[ii%2];
      cc[1] = wbColor[(ii+1)%2];
		
	for(mm=0;mm<yeNum;mm++)
	{
		for(jj=0;jj<7;jj++)
   	     	{
   	     		for(kk=0;kk<xxNum;kk++) *(p++)= cc[jj%2];	
   	     	}
   	     
   	     	for(kk=0;kk<xeNum;kk++) *(p++)= cc[1];	
	}  

}






