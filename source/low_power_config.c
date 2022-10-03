/******************************************************************************
* File Name:   low_power_config.c
*
* Description: This file contains function definitions for low-power
* configuration of the device.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2020-2022, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
 * Include header files
 ******************************************************************************/
#include "cybsp.h"
#include "cyhal.h"
#include "cy_pdl.h"

#include "low_power_config.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/

#if defined(CY_DEVICE_PSOC6A2M) 
    /* Do not disable block 0 of SRAM 0, and entire SRAM2 for these targets. 
    * Block 0 in SRAM0 contains SRAM section for CM0+ CPU and the last 2KB in 
    * SRAM2 is reserved for system call, which if disabled will result in unexpected
    * behavior. 256 KB of SRAM2 is retained because the SRAM2 controller does
    * not support granular retention.
    */
    #define MAX_RAM0_MACRO   (16)

#elif defined(CY_DEVICE_PSOC6ABLE2)
    /* Do not disable block 0 and block 9 for these targets. Block 0 contains SRAM
    * section for CM0+ CPU and the last 2KB in block 9 is reserved for system
    * call, which if disabled will result in unexpected behavior.
    */
    #define MAX_RAM0_MACRO   (8)

#elif defined(CY_DEVICE_PSOC6A512K)
    /* Do not disable block 0 and block 8 for these targets. Block 0 contains SRAM
    * section for CM0+ CPU and the last 2KB in block 8 is reserved for system
    * call, which if disabled will result in unexpected behavior.
    */
    #define MAX_RAM0_MACRO   (7)

#elif defined(CY_DEVICE_PSOC6A256K)
    /* Do not disable block 0 and block 3 for these targets. Block 0 contains SRAM
    * section for CM0+ CPU and the last 2KB in block 3 is reserved for system
    * call, which if disabled will result in unexpected behavior.
    */
    #define MAX_RAM0_MACRO   (3)

#endif /* #if defined(CY_DEVICE_PSOC6A2M) */

#define RAM_PWR_CTRL_TURN_OFF  (0x05FA0000)  


/*******************************************************************************
* Function Definitions
*******************************************************************************/

/*******************************************************************************
* Function Name: retain_sram_selectively
********************************************************************************
* Summary: This function retains only the minimum amount of SRAM required by the
* application. The function definition varies depending on the flash sizes and
* the SRAM sizes for different targets. The macro defines from the peripheral
* device library (PDL) have been used to differentiate between kits with different
* flash and SRAM sizes. 
* Please see the kit documentations and kit user guides for detailed information on  
* individual flash and SRAM sizes for the targets. 
*
*******************************************************************************/

void retain_sram_selectively(void)
{
    for (uint32_t i = 1; i < MAX_RAM0_MACRO; i++)
    {
        CPUSS->RAM0_PWR_MACRO_CTL[i] = RAM_PWR_CTRL_TURN_OFF;
    }

#if defined(CY_DEVICE_PSOC6A2M)
    CPUSS->RAM1_PWR_CTL = RAM_PWR_CTRL_TURN_OFF;
#endif /* #if defined(CY_DEVICE_PSOC6A2M) */

}


/* [] END OF FILE */
