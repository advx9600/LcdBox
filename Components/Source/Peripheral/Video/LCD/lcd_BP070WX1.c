/*
BP070WX1-300 Initial code setting(S6D7AA0X01-B0E5)(MP Status) lcd
*/
#include "System.h"
#include "Nand.h"
#include "Display.h"

void init_bp070wx1_lcd(void)
{
	printf("bp070wx1 lcd\n");
Delay_ms(20);


GP_COMMAD_PA(3);SPI_WriteData(0xF0);SPI_WriteData(0x5A);SPI_WriteData(0x5A);
GP_COMMAD_PA(3);SPI_WriteData(0xF1);SPI_WriteData(0x5A);SPI_WriteData(0x5A);
GP_COMMAD_PA(3);SPI_WriteData(0xFC);SPI_WriteData(0xA5);SPI_WriteData(0xA5);
GP_COMMAD_PA(2);SPI_WriteData(0xB1);SPI_WriteData(0x10);
GP_COMMAD_PA(5);SPI_WriteData(0xB2);SPI_WriteData(0x14);SPI_WriteData(0x22);SPI_WriteData(0x2F);SPI_WriteData(0x04);
GP_COMMAD_PA(3);SPI_WriteData(0xD0);SPI_WriteData(0x00);SPI_WriteData(0x10);
GP_COMMAD_PA(6);SPI_WriteData(0xF2);SPI_WriteData(0x02);SPI_WriteData(0x08);SPI_WriteData(0x08);SPI_WriteData(0x40);SPI_WriteData(0x10);
GP_COMMAD_PA(2);SPI_WriteData(0xB0);SPI_WriteData(0x03);
GP_COMMAD_PA(3);SPI_WriteData(0xFD);SPI_WriteData(0x23);SPI_WriteData(0x09);
GP_COMMAD_PA(11);SPI_WriteData(0xF3);SPI_WriteData(0x01);SPI_WriteData(0xD7);SPI_WriteData(0xE2);SPI_WriteData(0x62);SPI_WriteData(0xF4);SPI_WriteData(0xF7);SPI_WriteData(0x77);SPI_WriteData(0x3C);SPI_WriteData(0x26);SPI_WriteData(0x00);
GP_COMMAD_PA(46);SPI_WriteData(0xF4);SPI_WriteData(0x00);SPI_WriteData(0x02);SPI_WriteData(0x03);SPI_WriteData(0x26);SPI_WriteData(0x03);SPI_WriteData(0x02);SPI_WriteData(0x09);SPI_WriteData(0x00);SPI_WriteData(0x07);SPI_WriteData(0x16);SPI_WriteData(0x16);SPI_WriteData(0x03);SPI_WriteData(0x00);SPI_WriteData(0x08);SPI_WriteData(0x08);SPI_WriteData(0x03);SPI_WriteData(0x0E);SPI_WriteData(0x0F);SPI_WriteData(0x12);SPI_WriteData(0x1C);SPI_WriteData(0x1D);SPI_WriteData(0x1E);SPI_WriteData(0x0C);SPI_WriteData(0x09);SPI_WriteData(0x01);SPI_WriteData(0x04);SPI_WriteData(0x02);SPI_WriteData(0x61);SPI_WriteData(0x74);SPI_WriteData(0x75);SPI_WriteData(0x72);SPI_WriteData(0x83);SPI_WriteData(0x80);SPI_WriteData(0x80);SPI_WriteData(0xB0);SPI_WriteData(0x00);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x28);SPI_WriteData(0x04);SPI_WriteData(0x03);SPI_WriteData(0x28);SPI_WriteData(0x01);SPI_WriteData(0xD1);SPI_WriteData(0x32);
GP_COMMAD_PA(27);SPI_WriteData(0xF5);SPI_WriteData(0x8C);SPI_WriteData(0x2F);SPI_WriteData(0x2F);SPI_WriteData(0x3A);SPI_WriteData(0xAB);SPI_WriteData(0x98);SPI_WriteData(0x52);SPI_WriteData(0x0F);SPI_WriteData(0x33);SPI_WriteData(0x43);SPI_WriteData(0x04);SPI_WriteData(0x59);SPI_WriteData(0x54);SPI_WriteData(0x52);SPI_WriteData(0x05);SPI_WriteData(0x40);SPI_WriteData(0x60);SPI_WriteData(0x4E);SPI_WriteData(0x60);SPI_WriteData(0x40);SPI_WriteData(0x27);SPI_WriteData(0x26);SPI_WriteData(0x52);SPI_WriteData(0x25);SPI_WriteData(0x6D);SPI_WriteData(0x18);
GP_COMMAD_PA(9);SPI_WriteData(0xEE);SPI_WriteData(0x22);SPI_WriteData(0x00);SPI_WriteData(0x22);SPI_WriteData(0x00);SPI_WriteData(0x22);SPI_WriteData(0x00);SPI_WriteData(0x22);SPI_WriteData(0x00);
GP_COMMAD_PA(9);SPI_WriteData(0xEF);SPI_WriteData(0x12);SPI_WriteData(0x12);SPI_WriteData(0x43);SPI_WriteData(0x43);SPI_WriteData(0xA0);SPI_WriteData(0x04);SPI_WriteData(0x24);SPI_WriteData(0x81);
GP_COMMAD_PA(33);SPI_WriteData(0xF7);SPI_WriteData(0x0A);SPI_WriteData(0x0A);SPI_WriteData(0x08);SPI_WriteData(0x08);SPI_WriteData(0x0B);SPI_WriteData(0x0B);SPI_WriteData(0x09);SPI_WriteData(0x09);SPI_WriteData(0x04);SPI_WriteData(0x05);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x0A);SPI_WriteData(0x0A);SPI_WriteData(0x08);SPI_WriteData(0x08);SPI_WriteData(0x0B);SPI_WriteData(0x0B);SPI_WriteData(0x09);SPI_WriteData(0x09);SPI_WriteData(0x04);SPI_WriteData(0x05);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x01);SPI_WriteData(0x01);
GP_COMMAD_PA(4);SPI_WriteData(0xBC);SPI_WriteData(0x01);SPI_WriteData(0x4E);SPI_WriteData(0x0A);
GP_COMMAD_PA(6);SPI_WriteData(0xE1);SPI_WriteData(0x03);SPI_WriteData(0x10);SPI_WriteData(0x1C);SPI_WriteData(0xA0);SPI_WriteData(0x10);
GP_COMMAD_PA(7);SPI_WriteData(0xF6);SPI_WriteData(0x60);SPI_WriteData(0x25);SPI_WriteData(0xA6);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(7);SPI_WriteData(0xFE);SPI_WriteData(0x00);SPI_WriteData(0x0D);SPI_WriteData(0x03);SPI_WriteData(0x21);SPI_WriteData(0x00);SPI_WriteData(0x78);
GP_COMMAD_PA(18);SPI_WriteData(0xFA);SPI_WriteData(0x00);SPI_WriteData(0x35);SPI_WriteData(0x0A);SPI_WriteData(0x12);SPI_WriteData(0x0B);SPI_WriteData(0x11);SPI_WriteData(0x17);SPI_WriteData(0x16);SPI_WriteData(0x19);SPI_WriteData(0x21);SPI_WriteData(0x24);SPI_WriteData(0x24);SPI_WriteData(0x25);SPI_WriteData(0x25);SPI_WriteData(0x24);SPI_WriteData(0x23);SPI_WriteData(0x2B);
GP_COMMAD_PA(18);SPI_WriteData(0xFB);SPI_WriteData(0x00);SPI_WriteData(0x35);SPI_WriteData(0x0A);SPI_WriteData(0x12);SPI_WriteData(0x0A);SPI_WriteData(0x11);SPI_WriteData(0x16);SPI_WriteData(0x16);SPI_WriteData(0x19);SPI_WriteData(0x21);SPI_WriteData(0x24);SPI_WriteData(0x24);SPI_WriteData(0x25);SPI_WriteData(0x25);SPI_WriteData(0x24);SPI_WriteData(0x23);SPI_WriteData(0x2B);
Delay_ms(10);
GP_COMMAD_PA(4);SPI_WriteData(0xC3);SPI_WriteData(0x40);SPI_WriteData(0x00);SPI_WriteData(0x28);
Delay_ms(120);
GP_COMMAD_PA(2);SPI_WriteData(0x35);SPI_WriteData(0x00);
GP_COMMAD_PA(1);SPI_WriteData(0x11);
Delay_ms(200);
GP_COMMAD_PA(1);SPI_WriteData(0x29);
}