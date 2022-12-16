/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.00
*/

/*
 * File:   main.c
 * Author: Joshua
 *
 * Created on November 8, 2022, 3:28 PM
 */

#define SSD1306_HARD_SPI1
#define SSD1306_RST RB7_bit
#define SSD1306_DC RB6_bit
#define SSD1306_CS RB5_bit
#define SSD1306_RST_DIR TRISB7_bit
#define SSD1306_DC_DIR TRISB6_bit
#define SSD1306_CS_DIR TRISB5_bit

#include "mcc_generated_files/mcc.h"
#include "SSD1306.c"
#include "GFX_Library.c"

#include <xc.h>

void main(void) 
{
    // Initialize the device
    SYSTEM_Initialize();
    SSD1306_begin(SSD1306_SWITCHCAPVCC);
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

     display();
     __delay_ms(2000);
    display_clear();
    
    while (1)
    {
       display_setTextSize(1);
        display_setTextColor(WHITE, BLACK);
        display_setCursor(0, 0);
        display_printf("Hello, world!\r\n");
        display_setTextColor(BLACK, WHITE); // 'inverted' text
        display_printf("%4.2f\r\n", 3.141592);
        display_setTextSize(2);
        display_setTextColor(WHITE, BLACK);
        display_printf("0x%LX\r\n", 0xDEADBEEF);
        display();
    }
}
/**
 End of File
*/
