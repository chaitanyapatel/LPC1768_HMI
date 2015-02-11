/**********************************************************************
* $Id$		main.c
*//**
* @file		main.c
* @brief	Write a Program to glow Alternate LEDs on and off
* @version	1.0
* @date		24. July. 2013
* @author	Dwijay.Edutech Learning Solutions
***********************************************************************
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
* NXP Semiconductors assumes no responsibility or liability for the
* use of the software, conveys no license or title under any patent,
* copyright, or mask work right to the product. NXP Semiconductors
* reserves the right to make changes in the software without
* notification. NXP Semiconductors also make no representation or
* warranty that such application will be suitable for the specified
* use without further testing or modification.
**********************************************************************/
#include "lpc_system_init.h"

/* Example group ----------------------------------------------------------- */
/** @defgroup LED LED
 * @ingroup LED_Examples
 * @{
 */


/*-------------------------PRIVATE FUNCTIONS------------------------------*/


/*-------------------------MAIN Page------------------------------*/
/** @mainpage LED Blinking: GPIO Test Example
*   @par Description:
*   - Blink Alternate LEDs
*
*   @par Activity - more information:
*   - Connect ASK25 to LPC1768 board
*   - Observe Alternate Leds Blinking on ASK25
*/
/*-------------------------MAIN FUNCTION------------------------------*/
/*********************************************************************//**
 * @brief	Main GPIO testing example sub-routine
 **********************************************************************/

/* With ARM and GHS toolsets, the entry point is main() - this will
   allow the linker to generate wrapper code to setup stacks, allocate
   heap area, and initialize and copy code and data segments. For GNU
   toolsets, the entry point is through __start() in the crt0_gnu.asm
   file, and that startup code will setup stacks and data */
int main(void)
{
	uchar flag;

	System_Init();

	while(1)
	{
		if(flag)
		{
			GPIO_SetValue(1,_SBF(18,0xAA));
			GPIO_ClearValue(1,_SBF(18,0x55));
			delay_ms(1000);
			flag = 0;
		}
		else
		{
			GPIO_SetValue(1,_SBF(18,0x55));
			GPIO_ClearValue(1,_SBF(18,0xAA));
			delay_ms(1000);
			flag = 1;
		}
	}

    return 1;
}



#ifdef  DEBUG
/*******************************************************************************
* @brief		Reports the name of the source file and the source line number
* 				where the CHECK_PARAM error has occurred.
* @param[in]	file Pointer to the source file name
* @param[in]    line assert_param error line source number
* @return		None
*******************************************************************************/
void check_failed(uint8_t *file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while(1);
}
#endif

/*
 * @}
 */
