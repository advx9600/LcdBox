
#include "System.h"
#include "NAND.h"
#include "Display.h"
//#include "Console.h"

U32 InputID;

void Update_Dowith(void);
void UpdateSTEPLDR(void);
void UpdateTestProgram(void);
void UpdateBmp1(void);
void UpdateBmp2(void);
void UpdateBmp3(void);
void UpdateBmp4(void);
void Delay_MS(U32 ms);

void *function[][2]=
{ 
	(void *) UpdateTestProgram, (char *)"Update Test Program  ",
	(void *) UpdateBmp1,	    (char *)"Update No.1 Picture  ",
	(void *) UpdateBmp2,	    (char *)"Update No.2 Picture  ",
	(void *) UpdateBmp3,        (char *)"Update No.3 Picture  ",
	(void *) UpdateBmp4,        (char *)"Update No.4 Picture  ",
	(void *) UpdateSTEPLDR,     (char *)"Update STEPLDR.nb0   ",
	0,0
};


U32 stopIndex;
void Key_Init(void)
{
	rGPJCON &= 0xFFFFFF00;	// GPJ0~3Ϊ����
	rGPJUDP &= 0xFFFFFF00;	// GPJ0~3Ϊ��������
	rGPJDAT |= 0x000F;
	
	stopIndex = 0;	
}

#define BmpMAX 8

int main( void)
{

	int autoID,dispID,dispIndex;
	int timerval;
	U16 btnStat,oldStat;
	

	rGPACDH = rdGPACDH & ~(1<<5) | (0<<5); // RDATA_OEN : enable

	rGPHCON=rGPHCON&~(0xf<<26)|(0xa<<26);
	rMISCCR=rMISCCR&~((0x7<<8)|(0x7<<4))|(0x3<<8)|(0x2<<4);

	// test code start setting in option.h
	SetCLKDIV( Startup_ARMCLKdiv, Startup_PREdiv, Startup_HCLKdiv, Startup_PCLKdiv);
	SetMPLL( Startup_MDIV, Startup_PDIV, Startup_SDIV);
	SystemCLK(0);	

	Isr_Init();
	MMU_Init();
	SPI_Init();

	Console();
		
	printf("\n\n***********TST-500_OTM1283+AUO5.7_720*1280 Test Program Ver 0.0***********\n");
	//printf("MPLL=%.2fMHz, ARMCLK=%.2fMHz (%d:%d:%d), HCLK=%.2fMHz, PCLK=%.2fMHz\n\n",
	//   		(float)MPLL/1000000,(float)ARMCLK/1000000,ARMCLKdiv+1,(ARMCLKdiv+1)*(HCLKdiv+1),(ARMCLKdiv+1)*(HCLKdiv+1)*(PCLKdiv+1),(float)HCLK/1000000,(float)PCLK/1000000);

	
	Init_SSD2805_SPI();	//2805 spi��ʼ����λ��/Peripheral/Video/LCD/Display.c�ļ�
	SetLcdPort(); 		//2443 RGB�˿ڼ���ؼĴ������ã�����RGB����λ��Display.h�ļ�
	
	SPI_READ_ID(0xb0);	
	

	Key_Init();				//������ʼ��
	
	dispID    = 0;
	dispIndex = 1;
	autoID    = 0;
	timerval  = 0;
	
	btnStat=0;
	oldStat=0;
	
	while(1)	//
	{
	
		if(dispIndex)
		{
			dispIndex = 0;
			
			switch(dispID)
			{
				
				case 0: disp_color(0xF800,0,0,XSIZE,YSIZE);	   break;	//��ʾR��ɫ
				case 1: disp_color(0x07E0,0,0,XSIZE,YSIZE);	   break;	//��ʾG��ɫ
				case 2: disp_color(0x001F,0,0,XSIZE,YSIZE);	   break;	//��ʾB��ɫ
			    case 3: disp_9WB();                        break;	
				case 4: disp_color_table();                    break;
				case 5: disp_gray();                           break;
				case 6: disp_color(0xffff,0,0,XSIZE,YSIZE);	   break;	//��ʾ��ɫ
				case 7: disp_color(0x0000,0,0,XSIZE,YSIZE);       K9S1208_RdBmp(TFT_RAM1,TFT_SMC_BLK1,TFT_BmpSize); break;//��ͼƬ���ݿ������ڴ棬TFT_RAM1,TFT_SMC_BLK1������Display.h�ļ�	break;//Delay(10);    	//��ʾ��ɫ   
    	        case 8: disp_bmp((U16 *)TFT_RAM1,0,0,XSIZE,YSIZE);K9S1208_RdBmp(TFT_RAM2,TFT_SMC_BLK2,TFT_BmpSize); break; 	//��ʾ�ڴ��ͼƬ������     
			    case 9: disp_bmp((U16 *)TFT_RAM2,0,0,XSIZE,YSIZE);K9S1208_RdBmp(TFT_RAM3,TFT_SMC_BLK3,TFT_BmpSize); break;	//��ʾ�ڴ��ͼƬ������
			    case 10: disp_bmp((U16 *)TFT_RAM3,0,0,XSIZE,YSIZE);K9S1208_RdBmp(TFT_RAM4,TFT_SMC_BLK4,TFT_BmpSize); break;	//��ʾ�ڴ��ͼƬ������
			    case 11: disp_bmp((U16 *)TFT_RAM4,0,0,XSIZE,YSIZE);  break;
			}
			
		//	printf("\display id = %d\n",dispID);
			Delay_MS(400);
		}

		if(autoID)
		{
			timerval++;
			if(timerval>30)
			{
				timerval = 0;
				dispID++;
				if(dispID>BmpMAX) dispID=0;
				dispIndex = 1;
				//Init_SSD2805_SPI();
			}
		}
		
		btnStat = rGPJDAT;
		btnStat = (~btnStat)&0x0007;
		//printf("\ndisplay btn = 0x%x\n",btnStat);
		
		if(btnStat)
		{
			if(((btnStat&0x01)==0x01) && ((oldStat&0x01)==0x00))	//GPJ0�Զ��ֶ��л�
			{
				if(autoID) autoID = 0;
				else       autoID = 1;	
			}
			
			if(((btnStat&0x02)==0x02) && ((oldStat&0x02)==0x00))	//GPJ1������ǰ��
			{
				dispID++;
				if(dispID>BmpMAX) dispID=0;
				dispIndex = 1;
				//Init_SSD2828();	
			}
			
			if(((btnStat&0x04)==0x04) && ((oldStat&0x04)==0x00))	//GPJ2�������
			{
			//	dispID++;
				if(dispID>0) dispID--;
				else         dispID = BmpMAX;
				dispIndex = 1;	
			}
		//	Delay_MS(100);
		}
	
		Delay_MS(50);						//��ʱ�����Ҽ��Ӵ���
				
		oldStat = btnStat;

	}
//--------------------------------------------------------------------------------------------


}

void Delay_MS(U32 ms)
{
	U16 btnStat,oldStat;
	
	oldStat = 1;

	while(1) 
	{/*
		btnStat = rGPJDAT&0x0001;
		
		if((btnStat==0)&&(oldStat==1))
		{
			if(stopIndex==0) stopIndex=1;
			else             
			{
				stopIndex=0;
				break;
			}	
		}*/
		
	
		if(stopIndex==0)
		{
			ms--;
			if(ms==0) break;	
		}
		
		oldStat = btnStat;
	
		if(rUTRSTAT1  & 0x1) Update_Dowith();		//���Ӵ�������
		Delay(20000);	
	}	
}

void Update_Dowith(void)
{
	int i;
	
	while(1)
	{
 		i = 0;
		while(1)
		{	//display menu
	    		printf("%2d:%s",i,function[i][1]);
	    		i++;
	    		if((int)(function[i][0])==0)
	    		{
				printf("\n");
 				break;
	    		}
	    		if((i%4)==0) printf("\n");
		}

		printf("\nSelect the function to test : ");
		i = GetIntNum();
		if(i>8)  
		{
			printf("\n\nGo to display test picture!\n\n");
			break;	
		}
		printf("\n");

		if( i>=0 && (i<sizeof(function)/8-1) ) 
			( (void (*)(void)) (function[i][0]) )();
	}		
}

void UpdateSTEPLDR(void)
{
	if(DownloadData())
	{
		printf("\nStart to update STEPLDR.nb0!!!\n");
		WrFileToNF(BOOTLOADER);	
	}		
}

void UpdateTestProgram(void)
{
	if(DownloadData())
	{
		printf("\nStart to update test program!!!\n");
		WrFileToNF(TEST_PRG_BLK);	
	}		
}
void UpdateBmp1(void)
{
	if(DownloadData())
	{
		printf("\nStart to update test program!!!\n");
		WrFileToNF(TFT_SMC_BLK1);	
	}	
}
void UpdateBmp2(void)
{
	if(DownloadData())
	{
		printf("\nStart to update test program!!!\n");
		WrFileToNF(TFT_SMC_BLK2);	
	}	
}
void UpdateBmp3(void)
{
	if(DownloadData())
	{
		printf("\nStart to update test program!!!\n");
		WrFileToNF(TFT_SMC_BLK3);	
	}	
}
void UpdateBmp4(void)
{
	if(DownloadData())
	{
		printf("\nStart to update test program!!!\n");
		WrFileToNF(TFT_SMC_BLK4);	
	}	
}


