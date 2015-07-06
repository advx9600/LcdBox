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

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

//#define LCD_MODULE_TYPE            	(TFT480_272_QIMEI)
//#define LCD_MODULE_TYPE            	(TFT800_480_QIMEI)




#define RAM_LENGTH    0x200000
#define TFT_RAM1      0x30800000
#define TFT_RAM2      (TFT_RAM1+RAM_LENGTH)
#define TFT_RAM3      (TFT_RAM1+RAM_LENGTH*2)
#define TFT_RAM4      (TFT_RAM1+RAM_LENGTH*3)
#define TFT_RAM5      (TFT_RAM1+RAM_LENGTH*4)

#define BOOTLOADER        0
#define TEST_PRG_BLK      2
#define TFT_SMC_BLK1      200
#define TFT_SMC_BLK2      400
#define TFT_SMC_BLK3      600
#define TFT_SMC_BLK4      800
#define TFT_SMC_BLK5      1000

/*
#if (LCD_MODULE_TYPE == TFT480_272_QIMEI)
#define TFT_BmpSize     0x5FA00
#define LCD_XSIZE_TFT   (480)   
#define LCD_YSIZE_TFT   (272)
#define LCD_VBPD		(1)
#define LCD_VFPD		(1)
#define LCD_VSPW		(9)
#define LCD_HBPD		(1)
#define LCD_HFPD		(1)
#define LCD_HSPW		(40)

#elif (LCD_MODULE_TYPE == TFT800_480_QIMEI)
*/

#define LCD_XSIZE_TFT    (800) 
#define LCD_YSIZE_TFT    (1281)
/*
#define LCD_VBPD		 (28)
#define LCD_VFPD	 	 (26)
#define LCD_VSPW		 (6)
#define LCD_HBPD		 (20)
#define LCD_HFPD		 (18)
#define LCD_HSPW	       (3)*/
#define LCD_VBPD		 (4)
#define LCD_VFPD	 	 (8)
#define LCD_VSPW		 (4)
#define LCD_HBPD		 (48)//25
#define LCD_HFPD		 (16)//30
#define LCD_HSPW	     (4)//2

#define LCD_DSI_CLCK	(0x8440)

#define TFT_BmpSize      (LCD_XSIZE_TFT*LCD_YSIZE_TFT*2)//0x119400

//#endif

#define XSIZE            LCD_XSIZE_TFT  
#define YSIZE            LCD_YSIZE_TFT 
#define LCD_HOZVAL	 LCD_XSIZE_TFT
#define LCD_LINEVAL	 LCD_YSIZE_TFT 
#define LCD_FRAME_RATE	 (53)

#define IMAGE_FRAMEBUFFER_UA_BASE  0x33800000
#define IMAGE_FRAMEBUFFER_DMA_BASE 0x33800000

#define S3C2443_HCLK  133000000//ARMCLK

/*
#define LCD_FRAME_BUFFER		_NONCACHE_STARTADDRESS

#define LCD_WIN0_FRAME_BUFFER0		(LCD_FRAME_BUFFER)
#define LCD_WIN0_FRAME_BUFFER1		(LCD_FRAME_BUFFER+0x100000)
#define LCD_WIN1_FRAME_BUFFER		(LCD_FRAME_BUFFER+0x200000)

#define LCD_DELAY_300NS	54		//on the basis of 540MHz
#define LCD_DELAY_50US	9000	//on the basis of 540MHz
#define LCD_DELAY_1MS	18000	//180000	//on the basis of 540MHz
*/
/*
#define LCD_MODULE_LTS222	1
#define LCD_MODULE_LTV350	2
#define LCD_MODULE_LTS222_SERIAL	3

#define LCD_MODULE_LTS222_CPUIF	1

// SPECIFIC FOR LTS222 MODULE FOR PARALLEL RGB INTERFACE
#define LTS222_VBPD		(9)		
#define LTS222_VFPD		(10)
#define LTS222_VSPW		(3)
#define LTS222_HBPD		(1)		
#define LTS222_HFPD		(6)
#define LTS222_HSPW		(3)
#define LTS222_HOZVAL	(240)
#define LTS222_LINEVAL	(320)

// SPECIFIC FOR LTS222 MODULE FOR SERIAL RGB INTERFACE
#define LTS222_VBPD_SERIAL		(7)		
#define LTS222_VFPD_SERIAL		(10)
#define LTS222_VSPW_SERIAL		(3)
#define LTS222_HBPD_SERIAL		(6)		
#define LTS222_HFPD_SERIAL		(6)
#define LTS222_HSPW_SERIAL		(3)
#define LTS222_HOZVAL_SERIAL	(240)
#define LTS222_LINEVAL_SERIAL	(320)

// SPECIFIC FOR LTS222 MODULE FOR CPU INTERFACE
#define LTS222_CS_SETUP	(1)		
#define LTS222_WR_SETUP	(1)
#define LTS222_WR_ACT		(5)
#define LTS222_WR_HOLD		(1)		
#define LTS222_FRAME_RATE	65

// SPECIFIC FOR LTV350 MODULE
#define LTV350_VBPD		(5)
#define LTV350_VFPD		(3)
#define LTV350_VSPW		(4)
#define LTV350_HBPD		(5)
#define LTV350_HFPD		(3)
#define LTV350_HSPW		(10)
#define LTV350_HOZVAL	(320)
#define LTV350_LINEVAL	(240)

#define LTV350_FRAME_RATE	65
*/

//* VIDCON0	
#define VIDCON0_S_RGB_IF					(0<<22)
#define VIDCON0_S_CPU_IF_MAIN					(2<<22)
#define VIDCON0_S_CPU_IF_SUB					(3<<22)

#define VIDCON0_CPU_16BIT					(0<<19)
#define VIDCON0_CPU_16plus2					(1<<19)
#define VIDCON0_CPU_9plus9					(2<<19)
#define VIDCON0_CPU_16plus8					(3<<19)
#define VIDCON0_CPU_18BIT					(4<<19)

#define VIDCON0_S_RGB_PAR					(0<<13)
#define VIDCON0_S_BGR_PAR					(1<<13)
#define VIDCON0_S_RGB_SER					(2<<13)
#define VIDCON0_S_BGR_SER					(3<<13)
#define VIDCON0_S_CLKVAL_F_AlWAYS_UPDATE	(0<<12)
#define VIDCON0_S_CLKVAL_F_SOF_UPDATE		(1<<12)
#define VIDCON0_S_VCLK_GATING_ON			(0<<5)
#define VIDCON0_S_VCLK_GATING_OFF			(1<<5)
#define VIDCON0_S_CLKDIR_DIRECT				(0<<4)
#define VIDCON0_S_CLKDIR_DIVIDED			(1<<4)
#define VIDCON0_S_CLKSEL_HCLK				(0<<2)
#define VIDCON0_S_CLKSEL_UPLL				(1<<2)
#define VIDCON0_S_ENVID_OFF					(0<<1)
#define VIDCON0_S_EVVID_ON					(1<<1)
#define VIDCON0_S_ENVID_F_OFF				(0<<0)
#define VIDCON0_S_ENVID_F_ON				(1<<0)
//bit shift
#define VIDCON0_CLKVAL_F_SHIFT				(6)

//* VIDCON1
#define VIDCON1_S_VCLK_FALL_EDGE_FETCH		(0<<7)
#define VIDCON1_S_VCLK_RISE_EDGE_FETCH		(1<<7)
#define VIDCON1_S_HSYNC_INVERTED			(1<<6)
#define VIDCON1_S_VSYNC_INVERTED			(1<<5)
#define VIDCON1_S_VDEN_INVERTED				(1<<4)

//* VIDTCON0,1
//bit shift
#define VIDTCON0_BPD_S				(16)
#define VIDTCON0_FPD_S				(8)
#define VIDTCON0_SPW_S				(0)

//* VIDTCON2
//bit shift
#define VIDTCON2_LINEVAL_S			(11)
#define VIDTCON2_HOZVAL_S			(0)


//* WINCON1to4
#define WINCONx_BIT_SWAP_ON			(1<<2)	//shift on basis of half-word swap
#define WINCONx_BYTE_SWAP_ON		(1<<1)	//shift on basis of half-word swap
#define WINCONx_HALFW_SWAP_ON		(1<<0)	//shift on basis of half-word swap
#define WINCONx_4WORD_BURST			(2)
#define WINCONx_8WORD_BURST			(1)
#define WINCONx_16WORD_BURST		(0)
#define WINCONx_PLANE_BLENDING		(0)
#define WINCONx_PIXEL_BLENDING		(1)
#define WINCONx_1BPP_PALLET			(0)
#define WINCONx_2BPP_PALLET			(1)
#define WINCONx_4BPP_PALLET			(2)
#define WINCONx_8BPP_PALLET			(3)
#define WINCONx_8BPP_NO_PALLET		(4)
#define WINCONx_16BPP_565			(5)
#define WINCONx_16BPP_A555			(6)
#define WINCONx_16BPP_1555			(7)
#define WINCONx_18BPP_666			(8)
#define WINCONx_18BPP_A665			(9)
#define WINCONx_19BPP_A666			(10)
#define WINCONx_24BPP_888			(11)
#define WINCONx_24BPP_A887			(12)
#define WINCONx_25BPP_A888			(13)
#define WINCONx_ALPHA_MODE_0		(0)
#define WINCONx_ALPHA_MODE_1		(1)

//bit shift
#define WINCON_BUFSEL				(23)
#define WINCON_BUFAUTOEN			(22)
#define WINCON_SWAP_S				(16)
#define WINCON_BURSTLEN_S			(9)
#define WINCON_BLENDING_S			(6)
#define WINCON_BPP_S				(2)
#define WINCON_ALPHA_S				(1)

//* VIDWxADD2
//bit shift
#define VIDWxADD2_OFFSET_SIZE_S		(13)
#define VIDWxADD2_PAGE_WIDTH_S		(0)


//* VIDOSDxA,B,C
//bit shift
#define VIDOSDxAB_HORIZON_X_S		(11)
#define VIDOSDxAB_VERTICAL_Y_S		(0)
#define VIDOSDxC_ALPHA0_S			(12)


#define LCD_WIN_0					0
#define LCD_WIN_1					1
#define LCD_WIN_ALL					2

#define LCD_BUF_0					0
#define LCD_BUF_1					1


#define LCD_OFF						0
#define LCD_ON						1

	// set spi for lcd 
	// 1. set jumper like as 1-2 in J15 at SMDK board
	// 2. you can use the SPI1 to control LCD sfr register
	// nSS1 		---> SPI_LCDnSS  	---> GPL 14
	// SPIMOSI1	---> SPI_LCDMOSI      ---> GPL 11
	// SPICLK1    ---> SPI_LCDCLK        ---> GPL 10

#define LCD_DEN		(1<<14)
#define LCD_DSERI	(1<<11)
#define LCD_DCLK	(1<<10)

#define LCD_DEN_BIT		14
#define LCD_DSERI_BIT	11
#define LCD_DCLK_BIT	10

#define LCD_nRESET		1
#define LCD_RESET     (0)


#define MVAL		(13)
#define MVAL_USED 	(0)
#define M5D(n) ((n) & 0x1fffff)	// To get lower 21bits

#define CLKVAL_STN_MONO		(20) 	
    // 30hz @100Mhz(HCLK),WLH=16hclk,WDLY=16hclk,LINEBLANK=1*8hclk,VD=4 
#define CLKVAL_STN_GRAY		(10) 	
    // 60hz @100Mhz,WLH=16hclk,WDLY=16hclk,LINEBLANK=13*8hclk,VD=4 
#define CLKVAL_CSTN					(9)   
//#define CLKVAL_CSTN					(35)   

//STN
#define WLH_STN	    		(0)
#define WDLY_STN		(0)
#define LINEBLANK_MONO		(1 &0xff) // MONO timing parameter for CPT CLS-040S-C3M(CHUNGHWA)
#define LINEBLANK_GRAY		(13 &0xff)// GRAY timing parameter for CPT CLS-040S-C3M(CHUNGHWA)
//CSTN timing parameter for LCBHBT161M(NANYA)
#define WLH_CSTN	        (0)
#define WDLY_CSTN		(0)
#define LINEBLANK_CSTN		(16 &0xff)

//STN
#define HOZVAL_STN		(LCD_XSIZE_STN/4-1)	// Valid VD data line number is 4.
#define LINEVAL_STN		(LCD_YSIZE_STN-1)
//Color STN
#define HOZVAL_CSTN		(LCD_XSIZE_CSTN*3/8-1)	// Valid VD data line number is 8.
#define LINEVAL_CSTN		(LCD_YSIZE_CSTN-1)

//STN
#define LCD_XSIZE_STN 	(320)
#define LCD_YSIZE_STN 	(240)
//Color STN
#define LCD_XSIZE_CSTN 	(320)
#define LCD_YSIZE_CSTN 	(240)
//TFT 240320
#define LCD_XSIZE_TFT_240320 	(240)	
#define LCD_YSIZE_TFT_240320 	(320)
//TFT 640480
#define LCD_XSIZE_TFT_640480 	(640)	
#define LCD_YSIZE_TFT_640480 	(480)
//TFT 800600
#define LCD_XSIZE_TFT_800600 	(800)	
#define LCD_YSIZE_TFT_800600 	(600)

//STN
#define SCR_XSIZE_STN 	(LCD_XSIZE_STN*2)   //for virtual screen  
#define SCR_YSIZE_STN 	(LCD_YSIZE_STN*2)
//Color STN
/*
#define SCR_XSIZE_CSTN 	(LCD_XSIZE_CSTN*2)   //for virtual screen  
#define SCR_YSIZE_CSTN 	(LCD_YSIZE_CSTN*2)
*/
#define SCR_XSIZE_CSTN 	(LCD_XSIZE_CSTN)   //No virtual screen  
#define SCR_YSIZE_CSTN 	(LCD_YSIZE_CSTN)

//TFT 240320
#define SCR_XSIZE_TFT_240320 	(LCD_XSIZE_TFT_240320*2)
#define SCR_YSIZE_TFT_240320 	(LCD_YSIZE_TFT_240320*2)
//TFT 640480
#define SCR_XSIZE_TFT_640480 	(LCD_XSIZE_TFT_640480*2)
#define SCR_YSIZE_TFT_640480 	(LCD_YSIZE_TFT_640480*2)
//TFT 800600
#define SCR_XSIZE_TFT_800600 	(LCD_XSIZE_TFT_800600*2)
#define SCR_YSIZE_TFT_800600 	(LCD_YSIZE_TFT_800600*2)

//Selecting LCD type
//STN LCD Panel(320*240)
#define MODE_STN_1BIT 	(0x1001)
#define MODE_STN_2BIT  	(0x1002)
#define MODE_STN_4BIT  	(0x1004)
//Color STN LCD Panel(320*240)
#define MODE_CSTN_8BIT   (0x2001)
#define MODE_CSTN_12BIT (0x2002)
#define MODE_CSTN_12BIT_UP (0x2004)
#define MODE_CSTN_16BIT (0x2008) // for 2442A
//TFT LCD Panel(240*320)
#define MODE_TFT_1BIT_240320     (0x4101)
#define MODE_TFT_8BIT_240320 	 (0x4102)
#define MODE_TFT_16BIT_240320    (0x4104)
#define MODE_TFT_24BIT_240320    (0x4108)
//TFT LCD Panel(640*480)
#define MODE_TFT_1BIT_640480     (0x4201)
#define MODE_TFT_8BIT_640480     (0x4202)
#define MODE_TFT_16BIT_640480    (0x4204)
#define MODE_TFT_24BIT_640480    (0x4208)
//TFT LCD Panel(800*600)
#define MODE_TFT_1BIT_800600     (0x4401)
#define MODE_TFT_8BIT_800600     (0x4402)
#define MODE_TFT_16BIT_800600    (0x4404)


void SPI_Init(void);
void Init_HX8369_SPI(void);
void Init_SSD2805_SPI(void);
void SSD2828RGBINT(void);
U16 SPI_READ_ID(U8 cmd);
void SetLcdPort(void);
void disp_bmp(U16 *bmpbuf,int x0,int y0,int x1,int y1);
void Display_Bmp(void );
void disp_color(U16 color,int x0,int y0,int x1,int y1);
void disp_color_table(void);
void disp_gray(void);
void disp_frame(void);
void disp_9WB(void);

void GP_COMMAD_PA(U16 num);
void SPI_WriteData(U8 value);

#ifdef __cplusplus
}
#endif
#endif //#ifndef __DISPLAY_H__
