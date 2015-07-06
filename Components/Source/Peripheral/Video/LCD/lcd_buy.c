/*
直接和液晶测试盒一起买过来的LCD
*/
#include "System.h"
#include "Nand.h"
#include "Display.h"

void init_buy_lcd()
{
printf("buy lcd\n");
GP_COMMAD_PA(5);SPI_WriteData(0xFF);SPI_WriteData(0xAA);SPI_WriteData(0x55);SPI_WriteData(0xA5);SPI_WriteData(0x80);

//GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x07);
//GP_COMMAD_PA(2);SPI_WriteData(0xF7);SPI_WriteData(0x60);

GP_COMMAD_PA(3);SPI_WriteData(0x6F);SPI_WriteData(0x11);SPI_WriteData(0x00);
GP_COMMAD_PA(3);SPI_WriteData(0xF7);SPI_WriteData(0x20);SPI_WriteData(0x00);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x1E);
GP_COMMAD_PA(2);SPI_WriteData(0xFA);SPI_WriteData(0x20);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x1E);
GP_COMMAD_PA(2);SPI_WriteData(0xFA);SPI_WriteData(0x00);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x1F);
GP_COMMAD_PA(2);SPI_WriteData(0xFA);SPI_WriteData(0x00);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x11);
GP_COMMAD_PA(2);SPI_WriteData(0xF3);SPI_WriteData(0x01);





GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x00);
GP_COMMAD_PA(6);SPI_WriteData(0xBD);SPI_WriteData(0x01);SPI_WriteData(0xA0);SPI_WriteData(0x0C);SPI_WriteData(0x08);SPI_WriteData(0x01);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x02);
GP_COMMAD_PA(2);SPI_WriteData(0xB8);SPI_WriteData(0x0C);

GP_COMMAD_PA(3);SPI_WriteData(0xBB);SPI_WriteData(0x11);SPI_WriteData(0x11);

GP_COMMAD_PA(3);SPI_WriteData(0xBC);SPI_WriteData(0x00);SPI_WriteData(0x00);

GP_COMMAD_PA(2);SPI_WriteData(0xB6);SPI_WriteData(0x01);

GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x01);

GP_COMMAD_PA(3);SPI_WriteData(0xB0);SPI_WriteData(0x09);SPI_WriteData(0x09);
GP_COMMAD_PA(3);SPI_WriteData(0xB1);SPI_WriteData(0x09);SPI_WriteData(0x09);
GP_COMMAD_PA(3);SPI_WriteData(0xBC);SPI_WriteData(0x68);SPI_WriteData(0x01);
GP_COMMAD_PA(3);SPI_WriteData(0xBD);SPI_WriteData(0x68);SPI_WriteData(0x01);

GP_COMMAD_PA(2);SPI_WriteData(0xCA);SPI_WriteData(0x00);
GP_COMMAD_PA(2);SPI_WriteData(0xC0);SPI_WriteData(0x04);

GP_COMMAD_PA(3);SPI_WriteData(0xB5);SPI_WriteData(0x03);SPI_WriteData(0x03);
GP_COMMAD_PA(2);SPI_WriteData(0xBE);SPI_WriteData(0x5A);
GP_COMMAD_PA(3);SPI_WriteData(0xB3);SPI_WriteData(0x1B);SPI_WriteData(0x1B);
GP_COMMAD_PA(3);SPI_WriteData(0xB4);SPI_WriteData(0x0F);SPI_WriteData(0x0F);
GP_COMMAD_PA(3);SPI_WriteData(0xB9);SPI_WriteData(0x26);SPI_WriteData(0x26);

//modified by Frank 20130528
GP_COMMAD_PA(3);SPI_WriteData(0xBA);SPI_WriteData(0x14);SPI_WriteData(0x14);

GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x02);

GP_COMMAD_PA(2);SPI_WriteData(0xEE);SPI_WriteData(0x03);
//R(+) MCR cmd
GP_COMMAD_PA(17);SPI_WriteData(0xB0);SPI_WriteData(0x00);SPI_WriteData(0x09);SPI_WriteData(0x00);SPI_WriteData(0x0C);SPI_WriteData(0x00);SPI_WriteData(0xA4);SPI_WriteData(0x00);
SPI_WriteData(0xBE);SPI_WriteData(0x00);SPI_WriteData(0xD7);SPI_WriteData(0x00);SPI_WriteData(0xFC);SPI_WriteData(0x01);SPI_WriteData(0x19);SPI_WriteData(0x01);SPI_WriteData(0x49);

GP_COMMAD_PA(17);SPI_WriteData(0xB1);SPI_WriteData(0x01);SPI_WriteData(0x70);SPI_WriteData(0x01);SPI_WriteData(0xAB);SPI_WriteData(0x01);SPI_WriteData(0xDD);SPI_WriteData(0x02);
SPI_WriteData(0x2A);SPI_WriteData(0x02);SPI_WriteData(0x6A);SPI_WriteData(0x02);SPI_WriteData(0x6B);SPI_WriteData(0x02);SPI_WriteData(0xA4);SPI_WriteData(0x02);SPI_WriteData(0xE1);

GP_COMMAD_PA(17);SPI_WriteData(0xB2);SPI_WriteData(0x03);SPI_WriteData(0x07);SPI_WriteData(0x03);SPI_WriteData(0x37);SPI_WriteData(0x03);SPI_WriteData(0x56);SPI_WriteData(0x03);
SPI_WriteData(0x7F);SPI_WriteData(0x03);SPI_WriteData(0x9A);SPI_WriteData(0x03);SPI_WriteData(0x9B);SPI_WriteData(0x03);SPI_WriteData(0xA5);SPI_WriteData(0x03);SPI_WriteData(0xC9);

GP_COMMAD_PA(5);SPI_WriteData(0xB3);SPI_WriteData(0x03);SPI_WriteData(0xE8);SPI_WriteData(0x03);SPI_WriteData(0xF8);
//G(+) MCR cmd
GP_COMMAD_PA(17);SPI_WriteData(0xB4);SPI_WriteData(0x00);SPI_WriteData(0x03);SPI_WriteData(0x00);SPI_WriteData(0x06);SPI_WriteData(0x00);SPI_WriteData(0x2B);SPI_WriteData(0x00);
SPI_WriteData(0x6D);SPI_WriteData(0x00);SPI_WriteData(0x92);SPI_WriteData(0x00);SPI_WriteData(0xC6);SPI_WriteData(0x00);SPI_WriteData(0xEF);SPI_WriteData(0x01);SPI_WriteData(0x29);

GP_COMMAD_PA(17);SPI_WriteData(0xB5);SPI_WriteData(0x01);SPI_WriteData(0x56);SPI_WriteData(0x01);SPI_WriteData(0x9B);SPI_WriteData(0x01);SPI_WriteData(0xD0);SPI_WriteData(0x02);
SPI_WriteData(0x23);SPI_WriteData(0x02);SPI_WriteData(0x63);SPI_WriteData(0x02);SPI_WriteData(0x65);SPI_WriteData(0x02);SPI_WriteData(0x9F);SPI_WriteData(0x02);SPI_WriteData(0xDD);

GP_COMMAD_PA(17);SPI_WriteData(0xB6);SPI_WriteData(0x03);SPI_WriteData(0x03);SPI_WriteData(0x03);SPI_WriteData(0x33);SPI_WriteData(0x03);SPI_WriteData(0x53);SPI_WriteData(0x03);
SPI_WriteData(0x7B);SPI_WriteData(0x03);SPI_WriteData(0x94);SPI_WriteData(0x03);SPI_WriteData(0xC9);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);

GP_COMMAD_PA(5);SPI_WriteData(0xB7);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);
//B(+) MCR cmd
GP_COMMAD_PA(17);SPI_WriteData(0xB8);SPI_WriteData(0x00);SPI_WriteData(0xFD);SPI_WriteData(0x00);SPI_WriteData(0xFE);SPI_WriteData(0x01);SPI_WriteData(0x21);SPI_WriteData(0x01);
SPI_WriteData(0x2B);SPI_WriteData(0x01);SPI_WriteData(0x36);SPI_WriteData(0x01);SPI_WriteData(0x49);SPI_WriteData(0x01);SPI_WriteData(0x5C);SPI_WriteData(0x01);SPI_WriteData(0x7D);

GP_COMMAD_PA(17);SPI_WriteData(0xB9);SPI_WriteData(0x01);SPI_WriteData(0x9A);SPI_WriteData(0x01);SPI_WriteData(0xCA);SPI_WriteData(0x01);SPI_WriteData(0xF6);SPI_WriteData(0x02);
SPI_WriteData(0x3A);SPI_WriteData(0x02);SPI_WriteData(0x76);SPI_WriteData(0x02);SPI_WriteData(0x77);SPI_WriteData(0x02);SPI_WriteData(0xAE);SPI_WriteData(0x02);SPI_WriteData(0xEC);

GP_COMMAD_PA(17);SPI_WriteData(0xBA);SPI_WriteData(0x03);SPI_WriteData(0x14);SPI_WriteData(0x03);SPI_WriteData(0x4B);SPI_WriteData(0x03);SPI_WriteData(0x75);SPI_WriteData(0x03);
SPI_WriteData(0xC2);SPI_WriteData(0x03);SPI_WriteData(0xFD);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);

GP_COMMAD_PA(5);SPI_WriteData(0xBB);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);
//R(-) MCR cmd
GP_COMMAD_PA(17);SPI_WriteData(0xBC);SPI_WriteData(0x00);SPI_WriteData(0x09);SPI_WriteData(0x00);SPI_WriteData(0x0C);SPI_WriteData(0x00);SPI_WriteData(0xA4);SPI_WriteData(0x00);
SPI_WriteData(0xBE);SPI_WriteData(0x00);SPI_WriteData(0xD7);SPI_WriteData(0x00);SPI_WriteData(0xFC);SPI_WriteData(0x01);SPI_WriteData(0x19);SPI_WriteData(0x01);SPI_WriteData(0x49);

GP_COMMAD_PA(17);SPI_WriteData(0xBD);SPI_WriteData(0x01);SPI_WriteData(0x70);SPI_WriteData(0x01);SPI_WriteData(0xAB);SPI_WriteData(0x01);SPI_WriteData(0xDD);SPI_WriteData(0x02);
SPI_WriteData(0x2A);SPI_WriteData(0x02);SPI_WriteData(0x6A);SPI_WriteData(0x02);SPI_WriteData(0x6B);SPI_WriteData(0x02);SPI_WriteData(0xA4);SPI_WriteData(0x02);SPI_WriteData(0xE1);

GP_COMMAD_PA(17);SPI_WriteData(0xBE);SPI_WriteData(0x03);SPI_WriteData(0x07);SPI_WriteData(0x03);SPI_WriteData(0x37);SPI_WriteData(0x03);SPI_WriteData(0x56);SPI_WriteData(0x03);
SPI_WriteData(0x7F);SPI_WriteData(0x03);SPI_WriteData(0x9A);SPI_WriteData(0x03);SPI_WriteData(0x9B);SPI_WriteData(0x03);SPI_WriteData(0xA5);SPI_WriteData(0x03);SPI_WriteData(0xC9);

GP_COMMAD_PA(5);SPI_WriteData(0xBF);SPI_WriteData(0x03);SPI_WriteData(0xE8);SPI_WriteData(0x03);SPI_WriteData(0xF8);
//G(-) MCR cmd
GP_COMMAD_PA(17);SPI_WriteData(0xC0);SPI_WriteData(0x00);SPI_WriteData(0x03);SPI_WriteData(0x00);SPI_WriteData(0x06);SPI_WriteData(0x00);SPI_WriteData(0x2B);SPI_WriteData(0x00);
SPI_WriteData(0x6D);SPI_WriteData(0x00);SPI_WriteData(0x92);SPI_WriteData(0x00);SPI_WriteData(0xC6);SPI_WriteData(0x00);SPI_WriteData(0xEF);SPI_WriteData(0x01);SPI_WriteData(0x29);

GP_COMMAD_PA(17);SPI_WriteData(0xC1);SPI_WriteData(0x01);SPI_WriteData(0x56);SPI_WriteData(0x01);SPI_WriteData(0x9B);SPI_WriteData(0x01);SPI_WriteData(0xD0);SPI_WriteData(0x02);
SPI_WriteData(0x23);SPI_WriteData(0x02);SPI_WriteData(0x63);SPI_WriteData(0x02);SPI_WriteData(0x65);SPI_WriteData(0x02);SPI_WriteData(0x9F);SPI_WriteData(0x02);SPI_WriteData(0xDD);

GP_COMMAD_PA(17);SPI_WriteData(0xC2);SPI_WriteData(0x03);SPI_WriteData(0x03);SPI_WriteData(0x03);SPI_WriteData(0x33);SPI_WriteData(0x03);SPI_WriteData(0x53);SPI_WriteData(0x03);
SPI_WriteData(0x7B);SPI_WriteData(0x03);SPI_WriteData(0x94);SPI_WriteData(0x03);SPI_WriteData(0xC9);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);

GP_COMMAD_PA(5);SPI_WriteData(0xC3);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);
//B(-) MCR cmd
GP_COMMAD_PA(17);SPI_WriteData(0xC4);SPI_WriteData(0x00);SPI_WriteData(0xFD);SPI_WriteData(0x00);SPI_WriteData(0xFE);SPI_WriteData(0x01);SPI_WriteData(0x21);SPI_WriteData(0x01);
SPI_WriteData(0x2B);SPI_WriteData(0x01);SPI_WriteData(0x36);SPI_WriteData(0x01);SPI_WriteData(0x49);SPI_WriteData(0x01);SPI_WriteData(0x5C);SPI_WriteData(0x01);SPI_WriteData(0x7D);

GP_COMMAD_PA(17);SPI_WriteData(0xC5);SPI_WriteData(0x01);SPI_WriteData(0x9A);SPI_WriteData(0x01);SPI_WriteData(0xCA);SPI_WriteData(0x01);SPI_WriteData(0xF6);SPI_WriteData(0x02);
SPI_WriteData(0x3A);SPI_WriteData(0x02);SPI_WriteData(0x76);SPI_WriteData(0x02);SPI_WriteData(0x77);SPI_WriteData(0x02);SPI_WriteData(0xAE);SPI_WriteData(0x02);SPI_WriteData(0xEC);

GP_COMMAD_PA(17);SPI_WriteData(0xC6);SPI_WriteData(0x03);SPI_WriteData(0x14);SPI_WriteData(0x03);SPI_WriteData(0x4B);SPI_WriteData(0x03);SPI_WriteData(0x75);SPI_WriteData(0x03);
SPI_WriteData(0xC2);SPI_WriteData(0x03);SPI_WriteData(0xFD);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);

GP_COMMAD_PA(5);SPI_WriteData(0xC7);SPI_WriteData(0x03);SPI_WriteData(0xFE);SPI_WriteData(0x03);SPI_WriteData(0xFE);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x02);
GP_COMMAD_PA(2);SPI_WriteData(0xF7);SPI_WriteData(0x47);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x0A);
GP_COMMAD_PA(2);SPI_WriteData(0xF7);SPI_WriteData(0x02);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x17);
GP_COMMAD_PA(2);SPI_WriteData(0xF4);SPI_WriteData(0x70);

GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x11);
GP_COMMAD_PA(2);SPI_WriteData(0xF3);SPI_WriteData(0x01);




GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x06);

GP_COMMAD_PA(3);SPI_WriteData(0xB0);SPI_WriteData(0x12);SPI_WriteData(0x10);
GP_COMMAD_PA(3);SPI_WriteData(0xB1);SPI_WriteData(0x18);SPI_WriteData(0x16);
GP_COMMAD_PA(3);SPI_WriteData(0xB2);SPI_WriteData(0x00);SPI_WriteData(0x02);
GP_COMMAD_PA(3);SPI_WriteData(0xB3);SPI_WriteData(0x31);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xB4);SPI_WriteData(0x31);SPI_WriteData(0x34);
GP_COMMAD_PA(3);SPI_WriteData(0xB5);SPI_WriteData(0x34);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xB6);SPI_WriteData(0x31);SPI_WriteData(0x33);
GP_COMMAD_PA(3);SPI_WriteData(0xB7);SPI_WriteData(0x33);SPI_WriteData(0x33);
GP_COMMAD_PA(3);SPI_WriteData(0xB8);SPI_WriteData(0x31);SPI_WriteData(0x08);
GP_COMMAD_PA(3);SPI_WriteData(0xB9);SPI_WriteData(0x2E);SPI_WriteData(0x2D);
GP_COMMAD_PA(3);SPI_WriteData(0xBA);SPI_WriteData(0x2D);SPI_WriteData(0x2E);
GP_COMMAD_PA(3);SPI_WriteData(0xBB);SPI_WriteData(0x09);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xBC);SPI_WriteData(0x33);SPI_WriteData(0x33);
GP_COMMAD_PA(3);SPI_WriteData(0xBD);SPI_WriteData(0x33);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xBE);SPI_WriteData(0x31);SPI_WriteData(0x34);
GP_COMMAD_PA(3);SPI_WriteData(0xBF);SPI_WriteData(0x34);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xC0);SPI_WriteData(0x31);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xC1);SPI_WriteData(0x03);SPI_WriteData(0x01);
GP_COMMAD_PA(3);SPI_WriteData(0xC2);SPI_WriteData(0x17);SPI_WriteData(0x19);
GP_COMMAD_PA(3);SPI_WriteData(0xC3);SPI_WriteData(0x11);SPI_WriteData(0x13);
GP_COMMAD_PA(3);SPI_WriteData(0xE5);SPI_WriteData(0x31);SPI_WriteData(0x31);


GP_COMMAD_PA(3);SPI_WriteData(0xC4);SPI_WriteData(0x17);SPI_WriteData(0x19);
GP_COMMAD_PA(3);SPI_WriteData(0xC5);SPI_WriteData(0x11);SPI_WriteData(0x13);
GP_COMMAD_PA(3);SPI_WriteData(0xC6);SPI_WriteData(0x03);SPI_WriteData(0x01);
GP_COMMAD_PA(3);SPI_WriteData(0xC7);SPI_WriteData(0x31);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xC8);SPI_WriteData(0x31);SPI_WriteData(0x34);
GP_COMMAD_PA(3);SPI_WriteData(0xC9);SPI_WriteData(0x34);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xCA);SPI_WriteData(0x31);SPI_WriteData(0x33);
GP_COMMAD_PA(3);SPI_WriteData(0xCB);SPI_WriteData(0x33);SPI_WriteData(0x33);
GP_COMMAD_PA(3);SPI_WriteData(0xCC);SPI_WriteData(0x31);SPI_WriteData(0x09);
GP_COMMAD_PA(3);SPI_WriteData(0xCD);SPI_WriteData(0x2D);SPI_WriteData(0x2E);
GP_COMMAD_PA(3);SPI_WriteData(0xCE);SPI_WriteData(0x2E);SPI_WriteData(0x2D);
GP_COMMAD_PA(3);SPI_WriteData(0xCF);SPI_WriteData(0x08);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xD0);SPI_WriteData(0x33);SPI_WriteData(0x33);
GP_COMMAD_PA(3);SPI_WriteData(0xD1);SPI_WriteData(0x33);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xD2);SPI_WriteData(0x31);SPI_WriteData(0x34);
GP_COMMAD_PA(3);SPI_WriteData(0xD3);SPI_WriteData(0x34);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xD4);SPI_WriteData(0x31);SPI_WriteData(0x31);
GP_COMMAD_PA(3);SPI_WriteData(0xD5);SPI_WriteData(0x00);SPI_WriteData(0x02);
GP_COMMAD_PA(3);SPI_WriteData(0xD6);SPI_WriteData(0x12);SPI_WriteData(0x10);
GP_COMMAD_PA(3);SPI_WriteData(0xD7);SPI_WriteData(0x18);SPI_WriteData(0x16);


GP_COMMAD_PA(6);SPI_WriteData(0xD8);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(6);SPI_WriteData(0xD9);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(2);SPI_WriteData(0xE7);SPI_WriteData(0x00);




GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x05);
GP_COMMAD_PA(2);SPI_WriteData(0xED);SPI_WriteData(0x30);


GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x03);
GP_COMMAD_PA(3);SPI_WriteData(0xB1);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(3);SPI_WriteData(0xB0);SPI_WriteData(0x00);SPI_WriteData(0x00);



GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x05);
GP_COMMAD_PA(2);SPI_WriteData(0xE5);SPI_WriteData(0x00);




GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x05);

GP_COMMAD_PA(3);SPI_WriteData(0xB0);SPI_WriteData(0x17);SPI_WriteData(0x06);

GP_COMMAD_PA(2);SPI_WriteData(0xB8);SPI_WriteData(0x00);

GP_COMMAD_PA(6);SPI_WriteData(0xBD);SPI_WriteData(0x03);SPI_WriteData(0x03);SPI_WriteData(0x01);SPI_WriteData(0x00);SPI_WriteData(0x03);

GP_COMMAD_PA(3);SPI_WriteData(0xB1);SPI_WriteData(0x17);SPI_WriteData(0x06);
GP_COMMAD_PA(3);SPI_WriteData(0xB9);SPI_WriteData(0x00);SPI_WriteData(0x03);
GP_COMMAD_PA(3);SPI_WriteData(0xB2);SPI_WriteData(0x17);SPI_WriteData(0x06);
GP_COMMAD_PA(3);SPI_WriteData(0xBA);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(3);SPI_WriteData(0xB3);SPI_WriteData(0x17);SPI_WriteData(0x06);
GP_COMMAD_PA(3);SPI_WriteData(0xBB);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(3);SPI_WriteData(0xB4);SPI_WriteData(0x17);SPI_WriteData(0x06);
GP_COMMAD_PA(3);SPI_WriteData(0xB5);SPI_WriteData(0x17);SPI_WriteData(0x06);
GP_COMMAD_PA(3);SPI_WriteData(0xB6);SPI_WriteData(0x17);SPI_WriteData(0x06);
GP_COMMAD_PA(3);SPI_WriteData(0xB7);SPI_WriteData(0x17);SPI_WriteData(0x06);
GP_COMMAD_PA(3);SPI_WriteData(0xBC);SPI_WriteData(0x00);SPI_WriteData(0x03);

GP_COMMAD_PA(2);SPI_WriteData(0xE5);SPI_WriteData(0x06);
GP_COMMAD_PA(2);SPI_WriteData(0xE6);SPI_WriteData(0x06);
GP_COMMAD_PA(2);SPI_WriteData(0xE7);SPI_WriteData(0x06);
GP_COMMAD_PA(2);SPI_WriteData(0xE8);SPI_WriteData(0x06);
GP_COMMAD_PA(2);SPI_WriteData(0xE9);SPI_WriteData(0x06);
GP_COMMAD_PA(2);SPI_WriteData(0xEA);SPI_WriteData(0x06);
GP_COMMAD_PA(2);SPI_WriteData(0xEB);SPI_WriteData(0x06);
GP_COMMAD_PA(2);SPI_WriteData(0xEC);SPI_WriteData(0x06);


GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x05);
GP_COMMAD_PA(2);SPI_WriteData(0xC0);SPI_WriteData(0x0B);
GP_COMMAD_PA(2);SPI_WriteData(0xC1);SPI_WriteData(0x09);
GP_COMMAD_PA(2);SPI_WriteData(0xC2);SPI_WriteData(0x0B);
GP_COMMAD_PA(2);SPI_WriteData(0xC3);SPI_WriteData(0x09);

//modified by Frank 20130528
GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x03);
GP_COMMAD_PA(6);SPI_WriteData(0xB2);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x54);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(6);SPI_WriteData(0xB3);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x54);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(6);SPI_WriteData(0xB4);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x54);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(6);SPI_WriteData(0xB5);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x54);SPI_WriteData(0x00);SPI_WriteData(0x00);



GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x05);
GP_COMMAD_PA(2);SPI_WriteData(0xC4);SPI_WriteData(0x10);
GP_COMMAD_PA(2);SPI_WriteData(0xC5);SPI_WriteData(0x10);
GP_COMMAD_PA(2);SPI_WriteData(0xC6);SPI_WriteData(0x10);
GP_COMMAD_PA(2);SPI_WriteData(0xC7);SPI_WriteData(0x10);

//modified by Frank 20130528
GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x03);
GP_COMMAD_PA(6);SPI_WriteData(0xB6);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x54);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(6);SPI_WriteData(0xB7);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x54);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(6);SPI_WriteData(0xB8);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x54);SPI_WriteData(0x00);SPI_WriteData(0x00);
GP_COMMAD_PA(6);SPI_WriteData(0xB9);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x54);SPI_WriteData(0x00);SPI_WriteData(0x00);


GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x05);
GP_COMMAD_PA(3);SPI_WriteData(0xC8);SPI_WriteData(0x07);SPI_WriteData(0x20);
GP_COMMAD_PA(3);SPI_WriteData(0xC9);SPI_WriteData(0x03);SPI_WriteData(0x20);
GP_COMMAD_PA(3);SPI_WriteData(0xCA);SPI_WriteData(0x07);SPI_WriteData(0x00);
GP_COMMAD_PA(3);SPI_WriteData(0xCB);SPI_WriteData(0x03);SPI_WriteData(0x00);

//modified by Frank 20130528
GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x03);
GP_COMMAD_PA(6);SPI_WriteData(0xBA);SPI_WriteData(0x44);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x70);
GP_COMMAD_PA(6);SPI_WriteData(0xBB);SPI_WriteData(0x44);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x70);
GP_COMMAD_PA(6);SPI_WriteData(0xBC);SPI_WriteData(0x44);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x70);
GP_COMMAD_PA(6);SPI_WriteData(0xBD);SPI_WriteData(0x44);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x70);



GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x05);
GP_COMMAD_PA(6);SPI_WriteData(0xD1);SPI_WriteData(0x00);SPI_WriteData(0x05);SPI_WriteData(0x00);SPI_WriteData(0x07);SPI_WriteData(0x10);
GP_COMMAD_PA(6);SPI_WriteData(0xD2);SPI_WriteData(0x00);SPI_WriteData(0x05);SPI_WriteData(0x04);SPI_WriteData(0x07);SPI_WriteData(0x10);
GP_COMMAD_PA(6);SPI_WriteData(0xD3);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x0A);SPI_WriteData(0x07);SPI_WriteData(0x10);
GP_COMMAD_PA(6);SPI_WriteData(0xD4);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x0A);SPI_WriteData(0x07);SPI_WriteData(0x10);



GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x05);

GP_COMMAD_PA(8);SPI_WriteData(0xD0);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

GP_COMMAD_PA(12);SPI_WriteData(0xD5);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);
SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

GP_COMMAD_PA(12);SPI_WriteData(0xD6);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);
SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

GP_COMMAD_PA(12);SPI_WriteData(0xD7);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);
SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);

GP_COMMAD_PA(6);SPI_WriteData(0xD8);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);SPI_WriteData(0x00);


GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x03);

GP_COMMAD_PA(2);SPI_WriteData(0xC4);SPI_WriteData(0x60);
GP_COMMAD_PA(2);SPI_WriteData(0xC5);SPI_WriteData(0x40);
GP_COMMAD_PA(2);SPI_WriteData(0xC6);SPI_WriteData(0x60);
GP_COMMAD_PA(2);SPI_WriteData(0xC7);SPI_WriteData(0x40);


GP_COMMAD_PA(2);SPI_WriteData(0x6F);SPI_WriteData(0x01);
GP_COMMAD_PA(2);SPI_WriteData(0xF9);SPI_WriteData(0x46);

//GP_COMMAD_PA(6);SPI_WriteData(0xF0);SPI_WriteData(0x55);SPI_WriteData(0xAA);SPI_WriteData(0x52);SPI_WriteData(0x08);SPI_WriteData(0x00);
GP_COMMAD_PA(5);SPI_WriteData(0xee);SPI_WriteData(0x87);SPI_WriteData(0x78);SPI_WriteData(0x02);SPI_WriteData(0x40);  
GP_COMMAD_PA(2);SPI_WriteData(0xef);SPI_WriteData(0x07);SPI_WriteData(0xFF);  

//GP_COMMAD_PA(2);SPI_WriteData(0x35);SPI_WriteData(0x00);
//GP_COMMAD_PA(1);SPI_WriteData(0x11);

GP_COMMAD_PA(1);SPI_WriteData(0x29);
 GP_COMMAD_PA(1);SPI_WriteData(0x11);
Delay(300);


}