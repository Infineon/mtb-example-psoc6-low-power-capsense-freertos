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
* Copyright 2020-2021, Cypress Semiconductor Corporation (an Infineon company) or
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
* Function Definitions
*******************************************************************************/

/*******************************************************************************
* Function Name: retain_sram_selectively
********************************************************************************
* Summary: This function retains only the minimum amount of SRAM required by the
* application.
*
*******************************************************************************/
void retain_sram_selectively(void)
{
    /* Do not disable block 0 of SRAM 0, and entire SRAM2 for this target. Block
     * 0 in SRAM0 contains SRAM section for CM0+ CPU and the last 2KB in SRAM2
     * is reserved for system call, which if disabled will result in unexpected
     * behavior. 256 KB of SRAM2 is retained because the SRAM2 controller does
     * not support granular retention.
     */
    for (uint32_t i = 1; i < 16; i++)
    {
        CPUSS->RAM0_PWR_MACRO_CTL[i] = 0x05FA0000;
    }

    CPUSS->RAM1_PWR_CTL = 0x05FA0000;
}


/* [] END OF FILE */
