# PSoC&trade; 6 MCU: low-power CAPSENSE&trade; design (FreeRTOS)

This code example demonstrates how to create a low-power CAPSENSE&trade; design using PSoC&trade; 6 MCU. This example features a 5-segment CAPSENSE&trade; slider and a ganged sensor, and displays the detected touch position over the serial terminal. This example uses the [CAPSENSE&trade; middleware library](https://github.com/infineon/capsense).

[View this README on GitHub.](https://github.com/Infineon/mtb-example-psoc6-low-power-capsense-freertos)

[Provide feedback on this code example.](https://cypress.co1.qualtrics.com/jfe/form/SV_1NTns53sK2yiljn?Q_EED=eyJVbmlxdWUgRG9jIElkIjoiQ0UyMzA5NjgiLCJTcGVjIE51bWJlciI6IjAwMi0zMDk2OCIsIkRvYyBUaXRsZSI6IlBTb0MmdHJhZGU7IDYgTUNVOiBsb3ctcG93ZXIgQ0FQU0VOU0UmdHJhZGU7IGRlc2lnbiAoRnJlZVJUT1MpIiwicmlkIjoic2JrciIsIkRvYyB2ZXJzaW9uIjoiMS4yLjAiLCJEb2MgTGFuZ3VhZ2UiOiJFbmdsaXNoIiwiRG9jIERpdmlzaW9uIjoiTUNEIiwiRG9jIEJVIjoiSUNXIiwiRG9jIEZhbWlseSI6IlBTT0MifQ==)


## Requirements

- [ModusToolbox&trade; software](https://www.cypress.com/products/modustoolbox-software-environment) v2.2 or later (tested with v2.3)
- Board support package (BSP) minimum required version: 2.0.0
- Programming language: C
- Associated parts: All [PSoC&trade; 6 MCU](https://www.cypress.com/PSoC6) parts, [AIROC™ CYW20735 Bluetooth® & Bluetooth® LE system-on-chip](https://www.cypress.com/products/cyw20735), [AIROC™ CYW20819 Bluetooth® & Bluetooth® LE system-on-chip](https://www.cypress.com/products/cyw20819), [AIROC™ CYW43012 Wi-Fi & Bluetooth® combo chip](https://www.cypress.com/products/cyw43012), [AIROC™ CYW4332W Wi-Fi & Bluetooth® combo chip](https://www.cypress.com/products/cyw4343w)


## Supported toolchains (make variable 'TOOLCHAIN')

- GNU Arm&reg; embedded compiler v9.3.1 (`GCC_ARM`) - Default value of `TOOLCHAIN`
- Arm&reg; compiler v6.13 (`ARM`)
- IAR C/C++ compiler v8.42.2 (`IAR`)


## Supported kits (make variable 'TARGET')

- [PSoC&trade; 6 Wi-Fi Bluetooth® prototyping kit](https://www.cypress.com/CY8CPROTO-062-4343W) (`CY8CPROTO-062-4343W`) - Default value of `TARGET`
- [PSoC&trade; 6 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CY8CKIT-062-WiFi-BT) (`CY8CKIT-062-WiFi-BT`)
- [PSoC&trade; 6 Bluetooth&reg; LE pioneer kit](https://www.cypress.com/CY8CKIT-062-BLE) (`CY8CKIT-062-BLE`)
- [PSoC&trade; 6 Bluetooth&reg; LE prototyping kit](https://www.cypress.com/CY8CPROTO-063-BLE) (`CY8CPROTO-063-BLE`)
- [PSoC&trade; 62S2 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CY8CKIT-062S2-43012) (`CY8CKIT-062S2-43012`)
- [PSoC&trade; 62S1 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CYW9P62S1-43438EVB-01) (`CYW9P62S1-43438EVB-01`)
- [PSoC&trade; 62S1 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CYW9P62S1-43012EVB-01) (`CYW9P62S1-43012EVB-01`)
- [PSoC&trade; 62S3 Wi-Fi Bluetooth&reg; prototyping kit](https://www.cypress.com/CY8CPROTO-062S3-4343W) (`CY8CPROTO-062S3-4343W`)
- [PSoC&trade; 64 "Secure Boot" Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CY8CKIT-064B0S2-4343W) (`CY8CKIT-064B0S2-4343W`)
- [PSoC&trade; 62S4 pioneer kit](https://www.cypress.com/CY8CKIT-062S4) (`CY8CKIT-062S4`)
- [PSoC&trade; 62S2 evaluation kit](https://www.cypress.com/CY8CEVAL-062S2) (`CY8CEVAL-062S2`, `CY8CEVAL-062S2-LAI-4373M2`)


## Hardware setup

This example uses the board's default configuration. See the kit user guide to ensure that the board is configured correctly.

**Note:** The PSoC&trade; 6 Bluetooth&reg; LE pioneer kit (CY8CKIT-062-BLE) and the PSoC&trade; 6 Wi-Fi Bluetooth&reg; pioneer kit (CY8CKIT-062-WIFI-BT) ship with KitProg2 installed. The ModusToolbox&trade; software requires KitProg3. Before using this code example, make sure that the board is upgraded to KitProg3. The tool and instructions are available in the [Firmware loader](https://github.com/Infineon/Firmware-loader) GitHub repository. If you do not upgrade, you will see an error like "unable to find CMSIS-DAP device" or "KitProg firmware is out of date".


## Software setup

Install a terminal emulator if you don't have one. Instructions in this document use [Tera Term](https://ttssh2.osdn.jp/index.html.en).

This example requires no additional software or tools.


## Using the code example

Create the project and open it using one of the following:

<details><summary><b>In Eclipse IDE for ModusToolbox&trade; software</b></summary>

1. Click the **New Application** link in the **Quick Panel** (or, use **File** > **New** > **ModusToolbox Application**). This launches the [Project Creator](https://www.cypress.com/ModusToolboxProjectCreator) tool.

2. Pick a kit supported by the code example from the list shown in the **Project Creator - Choose Board Support Package (BSP)** dialog.

   When you select a supported kit, the example is reconfigured automatically to work with the kit. To work with a different supported kit later, use the [Library Manager](https://www.cypress.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can use the Library Manager to select or update the BSP and firmware libraries used in this application. To access the Library Manager, click the link from the **Quick Panel**.

   You can also just start the application creation process again and select a different kit.

   If you want to use the application for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work.

3. In the **Project Creator - Select Application** dialog, choose the example by enabling the checkbox.

4. (Optional) Change the suggested **New Application Name**.

5. The **Application(s) Root Path** defaults to the Eclipse workspace which is usually the desired location for the application. If you want to store the application in a different location, you can change the *Application(s) Root Path* value. Applications that share libraries should be in the same root path.

6. Click **Create** to complete the application creation process.

For more details, see the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.cypress.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/ide_{version}/docs/mt_ide_user_guide.pdf*).

</details>

<details><summary><b>In command-line interface (CLI)</b></summary>

ModusToolbox&trade; software provides the Project Creator as both a GUI tool and the command line tool, "project-creator-cli". The CLI tool can be used to create applications from a CLI terminal or from within batch files or shell scripts. This tool is available in the *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/* directory.

Use a CLI terminal to invoke the "project-creator-cli" tool. On Windows, use the command line "modus-shell" program provided in the ModusToolbox&trade; software installation instead of a standard Windows command-line application. This shell provides access to all ModusToolbox&trade; software tools. You can access it by typing `modus-shell` in the search box in the Windows menu. In Linux and macOS, you can use any terminal application.

This tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--board-id` | Defined in the `<id>` field of the [BSP](https://github.com/Infineon?q=bsp-manifest&type=&language=&sort=) manifest | Required
`--app-id`   | Defined in the `<id>` field of the [CE](https://github.com/Infineon?q=ce-manifest&type=&language=&sort=) manifest | Required
`--target-dir`| Specify the directory in which the application is to be created if you prefer not to use the default current working directory | Optional
`--user-app-name`| Specify the name of the application if you prefer to have a name other than the example's default name | Optional

<br>

The following example will clone the "[Hello World](https://github.com/Infineon/mtb-example-psoc6-hello-world)" application with the desired name "MyHelloWorld" configured for the *CY8CKIT-062-WiFi-BT* BSP into the specified working directory, *C:/mtb_projects*:

   ```
   project-creator-cli --board-id CY8CKIT-062-WIFI-BT --app-id mtb-example-psoc6-hello-world --user-app-name MyHelloWorld --target-dir "C:/mtb_projects"
   ```

**Note:** The project-creator-cli tool uses the `git clone` and `make getlibs` commands to fetch the repository and import the required libraries. For details, see the "Project creator tools" section of the [ModusToolbox&trade; software user guide](https://www.cypress.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>

<details><summary><b>In third-party IDEs</b></summary>

Use one of the following options:

- **Use the standalone [Project Creator](https://www.cypress.com/ModusToolboxProjectCreator) tool:**

   1. Launch Project Creator from the Windows Start menu or from *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/project-creator.exe*.

   2. In the initial **Choose Board Support Package** screen, select the BSP, and click **Next**.

   3. In the **Select Application** screen, select the appropriate IDE from the **Target IDE** drop-down menu.

   4. Click **Create** and follow the instructions printed in the bottom pane to import or open the exported project in the respective IDE.

<br>

- **Use command-line interface (CLI):**

   1. Follow the instructions from the **In command-line interface (CLI)** section to create the application, and then import the libraries using the `make getlibs` command.

   2. Export the application to a supported IDE using the `make <ide>` command.

   3. Follow the instructions displayed in the terminal to create or import the application as an IDE project.

For a list of supported IDEs and more details, see the "Exporting to IDEs" section of the [ModusToolbox&trade; software user guide](https://www.cypress.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>


## Operation

If using a PSoC&trade; 64 "Secure" MCU kit (like CY8CKIT-064B0S2-4343W), the PSoC&trade; 64 device must be provisioned with keys and policies before being programmed. Follow the instructions in the ["Secure Boot" SDK user guide](https://www.cypress.com/documentation/software-and-drivers/psoc-64-secure-mcu-secure-boot-sdk-user-guide) to provision the device. If the kit is already provisioned, copy-paste the keys and policy folder to the application folder.

1. Connect the board to your PC using the provided USB cable through the KitProg3 USB connector.

2. Open a terminal program and select the KitProg3 COM port. Set the serial port parameters to 8N1 and 115200 baud.

3. Program the board using one of the following:

   <details><summary><b>Using Eclipse IDE for ModusToolbox&trade; software</b></summary>

      1. Select the application project in the Project Explorer.

      2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (KitProg3_MiniProg4)**.
   </details>

   <details><summary><b>Using CLI</b></summary>

     From the terminal, execute the `make program` command to build and program the application using the default toolchain to the default target. The default toolchain and target are specified in the application's Makefile but you can override those values manually:
      ```
      make program TARGET=<BSP> TOOLCHAIN=<toolchain>
      ```

      Example:
      ```
      make program TARGET=CY8CPROTO-062-4343W TOOLCHAIN=GCC_ARM
      ```
   </details>

4. After programming, the application starts automatically. Confirm that "\<CE Title>" is displayed on the UART terminal.

    **Figure 1. Terminal output on program startup**

    ![Figure 1](images/figure1.png)

5. Slide your finger along the slider to view the touch position detected on the serial terminal as shown below:

    **Figure 2. Terminal output on touching the slider**

    ![Figure 2](images/figure2.png)

6. The example switches to slow scan if touch is not detected for `MAX_CAPSENSE_FAST_SCAN_COUNT` fast scans. The example indicates the transition to slow scan on the serial terminal as shown below:

    **Figure 3. Terminal output when shifting to slow scan**

    ![Figure 3](images/figure3.png)

7. Touch the slider again to shift to fast scan. The example indicates the transition to fast scan on the serial terminal as shown below:

    **Figure 4. Terminal output when shifting to fast scan**

    ![Figure 4](images/figure4.png)

8. Measure the current as instructed in the [Making current measurements for PSoC&trade; 6 MCU device](#making-current-measurements-for-psoc&trade;-6-mcu-device) section.


## Debugging

You can debug the example to step through the code. In the IDE, use the **\<Application Name> Debug (KitProg3_MiniProg4)** configuration in the **Quick Panel**. For details, see the "Program and debug" section in the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.cypress.com/MTBEclipseIDEUserGuide).

**Note:** **(Only while debugging)** On the CM4 CPU, some code in `main()` may execute before the debugger halts at the beginning of `main()`. This means that some code executes twice – once before the debugger stops execution, and again after the debugger resets the program counter to the beginning of `main()`. See [KBA231071](https://community.cypress.com/docs/DOC-21143) to learn about this and for the workaround.


## Design and implementation

The example performs CAPSENSE&trade; scans at two different rates. It scans at `CAPSENSE_FAST_SCAN_INTERVAL_MS` intervals (fast scan) when there is a touch detected on the slider, and at `CAPSENSE_SLOW_SCAN_INTERVAL_MS` interval (slow scan) when there is no touch detected for `MAX_CAPSENSE_FAST_SCAN_COUNT` fast scans. `CAPSENSE_FAST_SCAN_INTERVAL_MS`, `CAPSENSE_SLOW_SCAN_INTERVAL_MS`, and `MAX_CAPSENSE_FAST_SCAN_COUNT` can be configured in *source/capsense.c*.

The example uses two CAPSENSE&trade; widgets; a linear slider, which is set up and scanned during the fast scan, and a GangedSensor (button widget), which is set up and scanned during the slow scan. The linear slider widget has five sensors, whereas the GangedSensor widget has only one sensor which corresponds to a ganged connection of the five sensors used in the linear slider widget.

The main function initializes the UART and creates `capsense_task` before starting the FreeRTOS scheduler. The example disables support for CAPSENSE&trade; tuner by default. You can enable the tuner by defining the `CAPSENSE_TUNER_ENABLE` variable in the *Makefile*.

The `capsense_task` is responsible for initializing the CAPSENSE&trade; hardware block, tuner communication if enabled, and scanning and processing the touch information. It also creates and starts a FreeRTOS timer instance which is used to signal the start of a new scan at the end of every timer period. The task implements an FSM to scan, process touch, and schedule sleep/deep sleep.

   **Figure 5. FSM state diagram**

   ![Figure 5](images/figure5.png)

The FSM comprises the following states:

1. `INITIATE_SCAN`: In this state, the example checks if the CAPSENSE&trade; HW block is busy. If not, the example initiates a CAPSENSE&trade; scan and changes the state to `WAIT_IN_SLEEP`. If tuner is enabled, `Cy_CapSense_ScanAllWidgets` is called to scan the widgets. It is not called if tuner communication is disabled because it sets up and scans both the widgets used in this example which results in longer scan times. Instead, `Cy_CapSense_Scan` is called to scan the widget. The widget that is scanned is the one that was last set up using `Cy_CapSense_SetupWidget`.

2. `WAIT_IN_SLEEP`: In this state, the example locks the deep sleep state and waits for task notification from `capsense_callback`, which signals that the CAPSENSE&trade; scan has completed. The task notification updates the state variable to `PROCESS_TOUCH`.

3. `PROCESS_TOUCH`: In this state, the device processes the scan data. The widget that is processed depends on the type of scan performed i.e., fast scan or slow scan.

   In fast scan, if a new touch is detected, the value of `capsense_fast_scan_count` is reset to `RESET_CAPSENSE_FAST_SCAN_COUNT`, and the slider position is displayed on the serial terminal. If not, `capsense_fast_scan_count` is incremented until `MAX_CAPSENSE_FAST_SCAN_COUNT` after which the timer period is changed to `CAPSENSE_SLOW_SCAN_INTERVAL_MS` and the GangedSensor widget is set up for the next scan.

   In slow scan, if a touch is detected for the GangedSensor widget, the example switches to fast scan mode by setting up the linear slider widget, resetting the value of `capsense_fast_scan_count` to `RESET_CAPSENSE_FAST_SCAN_COUNT`, and changing the timer period to `CAPSENSE_FAST_SCAN_INTERVAL_MS`.

   After processing the touch data, the state variable is changed to `WAIT_IN_DEEP_SLEEP`.

4. `WAIT_IN_DEEP_SLEEP`: In this state, the example unlocks the deep sleep state and waits for task notification from `scan_timer_callback` which signals that the timer period has elapsed and a new scan must be issued. The task notification updates the state variable to `INITIATE_SCAN`.


### Low-power design considerations

The common techniques used for the low-power operation of PSoC&trade; 6 MCU are:

1. Reducing the operating frequency of the CPU

2. Selecting System ULP mode over System LP

3. Selecting a buck regulator over LDO

4. Retaining as less RAM as possible by disabling SRAM controllers and unused pages within a SRAM Controller. Note that disabling portion of SRAM requires update to linker script capturing the used length of SRAM. 

In addition to these, the following firmware changes are required to achieve a low-power CAPSENSE&trade; design:

1. Select manual tuning against SmartSense auto-tuning - start from a lower resolution and higher modulator clock for the fastest scan possible until you achieve the desired performance. See [AN85951 - PSoC&trade; 4 and PSoC&trade; 6 MCU CAPSENSE&trade; design guide](https://www.cypress.com/documentation/application-notes/an85951-psoc-4-and-psoc-6-mcu-capsense-design-guide) for details on manual tuning.

2. Reduce the scan resolution to reduce the scan time.

3. Perform scans at a lower frequency when no touch has been detected. This enables the MCU to stay in deep sleep longer when no touch is detected. Increase the frequency when touch is detected to improve performance but at the cost of increase in current consumption.

4. Use a widget in slow scan where the sensors of the widget used in fast scan are ganged together to constitute a single sensor for shorter scan times. Note that doing so increases the parasitic capacitance of the sensor.

Some of these configurations can be made using the device configurator and CAPSENSE&trade; configurator which are packaged with ModusToolbox&trade; software. See the [Creating a custom device configuration for low-power operation](#creating-a-custom-device-configuration-for-low-power-operation) section.


### Resources and settings

**Table 1. Application resources**

| Resource  |  Alias/object     |    Purpose     |
| :------- | :------------    | :------------ |
| UART (HAL)|cy_retarget_io_uart_obj| UART HAL object used by Retarget-IO for debug UART port  |
| I2C (HAL)|sEzI2C| Slave EZI2C used for CAPSENSE&trade; tuner communication. This object is not enabled by default. |
| CAPSENSE&trade; (Middleware)| CSD0 | CAPSENSE&trade; hardware used for scanning the position of touch on the linear slider.|

<br>

### Creating a custom device configuration for low-power operation

The code example overrides the default device configuration provided in *<application_folder>/../mtb_shared/TARGET_\<kit>/latest_vX.Y/COMPONENT_BSP_DESIGN_MODUS* with the one provided in *<application_folder>/COMPONENT_CUSTOM_DESIGN_MODUS/TARGET_\<kit>* for the supported kits.

The custom configuration disables the phase-locked loop (PLL), selects System ULP power mode, selects Minimum Current Buck as the regulator, and provides a CAPSENSE&trade; configuration with a linear slider and a GangedSensor widget.

The device configurator is bundled with the ModusToolbox&trade; software installation and can be found at *\<ModusToolbox_installed_location>/tools_\*.\*/device-configurator*.

The example ships with the device configuration in which the CM4 CPU is clocked by FLL at 48 MHz, CLK_PERI at 24 MHz, CAPSENSE&trade; Mod clock at 24 MHz, and PSoC&trade; 6 MCU in ULP power mode.

Do the following to create a custom configuration for a new kit. The screenshots provided with the instructions use CY8CKIT-062-WIFI-BT as an example.

1. Create a new directory inside *COMPONENT_CUSTOM_DESIGN_MODUS* with the same name as the target you are building the example for, such as *<application_folder>/COMPONENT_CUSTOM_DESIGN_MODUS/TARGET_\<kit>*.

2. Copy the contents of the *COMPONENT_BSP_DESIGN_MODUS* folder at *<application_folder>/..//mtb_shared/TARGET_\<kit>/latest_vX.Y/COMPONENT_BSP_DESIGN_MODUS* into the folder created in the previous step except the *GeneratedSource* folder.

   **Note:** The files *design.cycapsense* and *design.qspi* are copied so that you don't have to configure these peripherals again. You only need to enable these peripherals in the *design.modus* file to use them.

3. Open the copied *design.modus* file using device configurator. If prompted, provide a path to the device support library as shown below:

   **Figure 6. Prompt for device support library path**

   ![](images/figure6.png)

4. Click **OK** and provide the path to the device support library in *<application_folder>/../mtb_shared/mtb-pdl-cat1/latest-vX.Y/devicesupport.xml* as shown below:

    **Figure 7. Select devicesupport.xml**

    ![](images/figure7.png)

5. Under the **Power** resource, change the **Power mode** to **ULP**, and change the **Core Regulator** under **General** to **Minimum Current Buck** as shown below:

    **Figure 8. Change power mode settings**

    ![](images/figure8.png)

6. Switch to the **System** tab and expand the **System Clocks** resource. Disable all instances of the PLL by unchecking the box in the **FLL+PLL** section as shown below:

    **Figure 9. Disable PLL**

    ![](images/figure9.png)

   PLL is disabled because it consumes higher current even though the noise performance is better than FLL.

   **If you are using the FLL to source the clock to CPU:**

   1. Enable the FLL in the **FLL+PLL** section if disabled. The  maximum operating frequency is 50 MHz in ULP mode; the FLL supports a range of 24-100 MHz. Therefore, provide the value of frequency within 24-50 MHz. This example uses a frequency of 48 MHz as shown below:

       **Figure 10. Enable FLL**

       ![](images/figure10.png)

   2. The CM4 CPU is clocked by **CLK_FAST**, which is derived from **CLK_HF0**. Ensure that **CLK_HF0** is allotted **CLK_PATH0** to connect **CLK_HF0** to FLL as shown below:

       **Figure 11. Change clock path**

       ![](images/figure11.png)

   3. **CLK_PERI** in ULP mode cannot exceed 25 MHz; therefore, ensure that **CLK_PERI** is not greater than 25 MHz by changing the divider appropriately as shown below. Optionally, if the FLL frequency is 24 MHz, you can change the divider for **CLK_PERI** to 1.

       **Figure 12. Change divider for CLK_PERI**

       ![](images/figure12.png)

   **If you are using the IMO to source the clock to CPU:**

   1. You can also use the IMO to clock the CPU. Disable the FLL in the **FLL+PLL** section if enabled as shown below:

       **Figure 13. Disable FLL**

       ![](images/figure13.png)

   2. In the **High Frequency** section under **System Clocks**, select **CLK_PERI** and decrease the divider to 1 as shown below:

       **Figure 14. Change divider for CLK_PERI**

       ![](images/figure14.png)

      Because the source clock is IMO, which is at 8 MHZ, CLK_PERI can also be configured to run at 8 MHZ. This helps in a better performance of the peripherals than when the divider is set as 2.

7. Save the file, switch to the **Peripherals** tab, and select **CSD(CAPSENSE&trade;, etc.)** under **System**. Select **Launch CAPSENSE&trade; configurator** in the panel on the right as shown below:

    **Figure 15. Launch CAPSENSE&trade; configurator**

    ![](images/figure15.png)

8. In the **Basic** tab of CAPSENSE&trade; configurator, create a new self-capacitance button widget called "GangedSensor", delete the Button0 and Button1 widgets, and select **Manual Tuning** as shown below:

    **Figure 16. Configure widgets**

    ![](images/figure16.png)

9. Open the **Advanced** tab.

   **If you are using FLL to source the clock to CPU:**

   1. Open the **CSD settings** tab and set the modulator clock divider such that the modulator clock frequency is lower than 50 MHz. This example uses the modulator clock of 24 MHz for a FLL frequency of 48 MHz as shown below:

       **Figure 17. Configure modulator clock**

       ![](images/figure17.png)

   2. Open the **Widget Details** tab, select **LinearSlider0**, and change the **Widget hardware parameters** and **Widget threshold parameters** as shown below:

       **Figure 18. Configure linear slider widget parameters**

       ![](images/figure18.png)

   3. Select **GangedSensor** and change the **Widget hardware parameters** and **Widget threshold parameters** as shown below:

       **Figure 19. Configure GangedSensor widget parameters**

       ![](images/figure19.png)

    **If you are using IMO to source the clock to CPU:**

    1.  Open the **CSD settings** tab and set the modulator clock divider to 1 as shown below. Increasing the modulator clock divider will result in reduction in performance.

        **Figure 20. Configure modulator clock**

        ![](images/figure20.png)

    2. Open the **Widget Details** tab, select **LinearSlider0**, and change the **Widget hardware parameters** and **Widget threshold parameters** as shown below:

        **Figure 21. Configure linear slider widget parameters**

        ![](images/figure21.png)

    3. Select **GangedSensor** and change the **Widget hardware parameters** and **Widget threshold parameters** as shown below:

        **Figure 22. Configure GangedSensor widget parameters**

        ![](images/figure22.png)

10. Select **GangedSensor_Sns0** under **Widget Details** of the **Advanced** tab and do the following:

    1. In the **Sensor connections** option on the panel on the right, unselect **dedicated pin**.

    2. Select the remaining ones as shown below to to create a ganged connection of the sensors of the linear slider:

       **Figure 23. Configure GangedSensor widget parameters**

       ![](images/figure23.png)

11. Save and close CAPSENSE&trade; configurator. Return to device configurator and save the file to generate the source files.

12. Disable the default configuration and enable the custom configuration by making the following changes in *Makefile*:

    ```
    DISABLE_COMPONENTS += BSP_DESIGN_MODUS
    COMPONENTS += CUSTOM_DESIGN_MODUS
    ```


### Considerations for widget parameters in CAPSENSE&trade; configurator

1. The example reduces the scan resolution to 9 bits as shown in Figure 18-19 and Figure 21-22. Reducing the scan resolution reduces the scan time at the cost of accuracy.

2. Because the accuracy of capacitance measurements at the sensors is reduced, the widget threshold parameters such as finger threshold and noise threshold need to be updated according to the observed values of raw counts.

   Enable tuner communication by defining the `CAPSENSE_TUNER_ENABLE` variable in the *Makefile* and program the example.

   **Using CAPSENSE&trade; tuner to monitor data:**

   1. Open CAPSENSE&trade; tuner from the IDE Quick Panel.

       You can also run the CAPSENSE&trade; tuner application standalone from *{ModusToolbox&trade; software install directory}/ModusToolbox/tools_{version}/capsense-configurator/capsense-tuner*. In this case, after opening the application, select **File** > **Open** and open the *design.cycapsense* file for the respective kit, which is present in the *TARGET_\<BSP-NAME>/{version}/COMPONENT_BSP_DESIGN_MODUS* or *COMPONENT_CUSTOM_DESIGN_MODUS* folder.

    2. Ensure that the kit is in KitProg3 mode. See [Firmware-loader](https://github.com/infineon/Firmware-loader) to learn on how to update the firmware and switch to KitProg3 mode.

    3. In the tuner application, click **Tuner Communication Setup** or select **Tools** > **Tuner Communication Setup**. In the window that appears, select the I2C checkbox under KitProg3 and configure as follows:

       - I2C Address: 8
       - Sub-address: 2-Bytes
       - Speed (kHz): 400

    4. Click **Connect** or select **Communication** > **Connect**.

    5. Click **Start** or select **Communication** > **Start**.

    Under the **Widget View** tab, you can see the corresponding widgets highlighted in blue color when you touch the button or slider. You can also view the sensor data in the **Graph View** tab. For example, to view the sensor data for Button 0, select **Button0_Rx0** under **Button0**.

    Figure 24 shows the CAPSENSE&trade; tuner displaying the status of CAPSENSE&trade; touch on LinearSlider 0 and GangedSensor.

    **Figure 24. CAPSENSE&trade; tuner showing touch data**

    ![](images/figure24.png)

    The CAPSENSE&trade; tuner can also be used for CAPSENSE&trade; parameter tuning, and measuring signal-to-noise ratio (SNR). See the [ModusToolbox&trade; CAPSENSE&trade; tuner guide](https://www.cypress.com/ModusToolboxCapSenseTuner) (**Help** > **View Help**) and [AN85951 – PSoC&trade; 4 and PSoC&trade; 6 MCU CAPSENSE&trade; design guide](https://www.cypress.com/an85951) for more details on selecting the tuning parameters.

3. In the widget threshold parameters, the ON debounce is set as 1, which can result in false positives for touch detection. Increase the value to 3 to reduce false positives; however, this will mean a poor reaction time in slow scan mode.

4. The sensor clock divider for GangedSensor is increased to 8 when CAPSENSE&trade; modulator clock frequency of 24 MHz. This is because its sensor, which comprises a ganged connection of 5 sensors, has a high parasitic capacitance that requires more time for making measurements. Reducing the sensor clock divider can result in failure to initialize CAPSENSE&trade; due to a calibration error for the sensor.

5. The sensor clock source for the GangedSensor is chosen as direct instead of PRS* or SS* clock. This is because SS* and PRS* modulate the clock, which results in varying pulse widths. This can cause errors when making measurements of the GangedSensor sensor due to its high parasitic capacitance.


### Operation at a custom power supply voltage

The application is configured to work with the default operating voltage of the kit.

**Table 1. Operating voltages supported by the kits**

| Kit                   | Supported operating voltages | Default operating voltage |
| :-------------------- | ---------------------------- | ------------------------- |
| CY8CPROTO-062-4343W   | 3.3 V / 1.8 V                | 3.3 V                     |
| CY8CKIT-062-BLE       | 3.3 V / 1.8 V                | 3.3 V                     |
| CY8CKIT-062-WiFi-BT   | 3.3 V / 1.8 V                | 3.3 V                     |
| CY8CKIT-062S2-43012   | 3.3 V / 1.8 V                | 3.3 V                     |
| CYW9P62S1-43438EVB-01 | 3.3 V Only                   | 3.3 V                     |
| CYW9P62S1-43012EVB-01 | 1.8 V Only                   | 1.8 V                     |
| CY8CPROTO-062S3-4343W | 3.3 V / 1.8 V                | 3.3 V                     |

<br>

For kits that support multiple operating voltages, follow the instructions to use the example at a custom power supply, such as 1.8 V:

1. Launch the [Device configurator](https://www.cypress.com/ModusToolboxDeviceConfig) tool using the Quick Panel link in the IDE. This opens the *design.modus* file from the *COMPONENT_CUSTOM_DESIGN_MODUS/TARGET_\<kit>* folder.

2. Update the **Operating Conditions** parameters in Power settings with the desired voltage and select **File** > **Save**.

   **Figure 25. Power settings to work with 1.8 V**

   ![](images/figure25.png)

3. Change the jumper/switch setting as follows:

   **Table 2. Jumper/switch position for 1.8-V operation**

   | Kit                   | Jumper/switch position |
   | :-------------------- | ---------------------- |
   | CY8CPROTO-062-4343W   | J3 (1-2)               |
   | CY8CKIT-062-BLE       | SW5 (1-2)              |
   | CY8CKIT-062-WIFI-BT   | SW5 (1-2)              |
   | CY8CKIT-062S2-43012   | J14 (1-2)              |
   | CY8CPROTO-062S3-4343W | J3 (1-2)               |
   | CY8CKIT-064B0S2-4343W | J14 (1-2)              |

<br>

4. Rebuild and program the application to evaluate the application at the new power setting.


### Making current measurements for PSoC&trade; 6 MCU device

- **CY8CKIT_062S2_43012, CYW9P62S1_43438EVB_01, and CYW9P62S1_43012EVB_01**

   Measure the current at J15 across VTARG and P6_VDD. Ensure that J25 is removed to eliminate leakage currents across potentiometer R1.


- **CY8CPROTO_062_4343W**

   Measure the current by removing R65 on the right of the board close to the USB connector of the PSoC&trade; 6 MCU USB (device) and connecting an ammeter between VTARG (J2.32) and P6_VDD (J2.24).

   The PSoC&trade; 6 MCU deep sleep current is approximately 350 uA because of the pull-up resistor (R24) attached to the WL_HOST_WAKE pin P0_4, which leaks around 330 uA. This is because P0_4 is driven LOW when there is no network activity. Therefore, remove R24 (at the back of the board, below J1.9).

- **CY8CPROTO_062S3_4343W**

   Measure the current by removing R59 on the back of the board, towards the right and above J2.31, and connecting an ammeter between VTARG (J2.32) and P6_VDD (J2.31).

- **CY8CKIT_062_WIFI_BT**

   Measure the current by connecting an ammeter to the PWR MON jumper J8.

- **CY8CKIT_062_BLE**

   Measure the current by connecting an ammeter to the PWR MON jumper J8.


### Current measurements

Table 3 provides the typical current measurement values where PSoC&trade; 6 MCU is operated with the Arm® Cortex®-M4 CPU (CM4) running at 48 MHz in ultra-low-power (ULP) mode with **Minimum Current Buck** selected as the regulator. The amount of SRAM retained is provided in the table below. **CLK_PERI** and CAPSENSE&trade; modulator clock run at 48 MHz.

**Table 3. Typical current values when CPU clock is sourced by FLL**

<table>
<tr><th>Target</th><th>Amount of SRAM retained</th><th>Slow scan (Scan GangedSensor at 5 Hz. The widget has only one sensor which is a ganged connection of five sensors fom the linear slider widget.)</th><th>Fast scan (Scan LinearSlider widget at 50 Hz. The widget has five sensors.)</th></tr>
        <tr>
            <td>CY8CKIT-062-BLE</td>
            <td>64 KB (Block 0 and Block 9 of SRAM0 are retained</td>
            <td>26 uA</td>
            <td>255 uA</td>
        </tr>
        <tr>
            <td>CY8CKIT-062-WIFI-BT</td>
            <td>64 KB (Block 0 and Block 9 of SRAM0 are retained</td>
            <td>26 uA</td>
            <td>300 uA</td>
        </tr>
        <tr>
            <td>CY8CKIT-062S2-43012</td>
            <td>288 KB (Block 0 of SRAM0 and 256 KB of SRAM2 are retained)</td>
            <td>26 uA</td>
            <td>315 uA</td>
        </tr>
        <tr>
            <td>CY8CPROTO-062-4343W</td>
            <td>288 KB (Block 0 of SRAM0 and 256 KB of SRAM2 are retained)</td>
            <td>26.6 uA</td>
            <td>350 uA</td>
        </tr>
        <tr>
            <td>CY8CPROTO-062S3-4343W</td>
            <td>64 KB (Block 0 and Block 8 of SRAM0 are retained</td>
            <td>20.7 uA</td>
            <td>230 uA</td>
        </tr>
        <tr>
            <td>CYW9P62S1-43012EVB-01</td>
            <td>64 KB (Block 0 and Block 9 of SRAM0 are retained</td>
            <td>25.2 uA</td>
            <td>360 uA</td>
        </tr>
        <tr>
            <td>CYW9P62S1-43438EVB-01</td>
            <td>64 KB (Block 0 and Block 9 of SRAM0 are retained</td>
            <td>23 uA</td>
            <td>260 uA</td>
        </tr>
        <tr>
            <td>CY8CKIT-064B0S2-4343W</td>
            <td>288 KB (Block 0 of SRAM0 and 256 KB of SRAM2 are retained)</td>
            <td>30.6 uA</td>
            <td>365 uA</td>
        </tr>
 </table>

<br>

 Table 4 provides the typical current measurement values where PSoC&trade; 6 MCU is operated with CM4 running at 8 MHz in ULP mode with **Minimum Current Buck** selected as the regulator. The amount of SRAM retained is provided in the table below. **CLK_PERI** and CAPSENSE&trade; modulator clock run at 8 MHz.


**Table 4. Typical current values when CPU clock is sourced by IMO**

<table>
<tr><th>Target</th><th>Amount of SRAM retained</th><th>Slow scan (Scan GangedSensor at 5 Hz. The widget has only one sensor which is a ganged connection of five sensors fom the linear slider widget.)</th><th>Fast scan (Scan LinearSlider widget at 50 Hz. The widget has five sensors.)</th></tr>
        <tr>
            <td>CY8CKIT-062-BLE</td>
            <td>64 KB (Block 0 and Block 9 of SRAM0 are retained</td>
            <td>23 uA</td>
            <td>165 uA</td>
        </tr>
        <tr>
            <td>CY8CKIT-062-WIFI-BT</td>
            <td>64 KB (Block 0 and Block 9 of SRAM0 are retained</td>
            <td>23 uA</td>
            <td>170 uA</td>
        </tr>
        <tr>
            <td>CY8CKIT-062S2-43012</td>
            <td>288 KB (Block 0 of SRAM0 and 256 KB of SRAM2 are retained)</td>
            <td>23 uA</td>
            <td>165 uA</td>
        </tr>
        <tr>
            <td>CY8CPROTO-062-4343W</td>
            <td>288 KB (Block 0 of SRAM0 and 256 KB of SRAM2 are retained)</td>
            <td>22.3 uA</td>
            <td>190 uA</td>
        </tr>
        <tr>
            <td>CY8CPROTO-062S3-4343W</td>
            <td>64 KB (Block 0 and Block 8 of SRAM0 are retained</td>
            <td>18.6 uA</td>
            <td>146.6 uA</td>
        </tr>
        <tr>
            <td>CYW9P62S1-43012EVB-01</td>
            <td>64 KB (Block 0 and Block 9 of SRAM0 are retained</td>
            <td>19.0 uA</td>
            <td>185 uA</td>
        </tr>
        <tr>
            <td>CYW9P62S1-43438EVB-01</td>
            <td>64 KB (Block 0 and Block 9 of SRAM0 are retained</td>
            <td>20 uA</td>
            <td>170 uA</td>
        </tr>
        <tr>
            <td>CY8CKIT-064B0S2-4343W</td>
            <td>288 KB (Block 0 of SRAM0 and 256 KB of SRAM2 are retained)</td>
            <td>27.6 uA</td>
            <td>210.5 uA</td>
        </tr>
 </table>

<br>


## Related resources

Resources  | Links
-----------|----------------------------------
Application notes  | [AN228571](https://www.cypress.com/AN228571) – Getting started with PSoC&trade; 6 MCU on ModusToolbox&trade; software <br>  [AN215656](https://www.cypress.com/AN215656) – PSoC&trade; 6 MCU: Dual-CPU system design
Code examples  | [Using ModusToolbox&trade; software](https://github.com/Infineon/Code-Examples-for-ModusToolbox-Software) on GitHub <br>  [mtb-example-psoc6-*](https://github.com/Infineon?q=mtb-example-psoc6%20NOT%20Deprecated) on GitHub
Device documentation | [PSoC&trade; 6 MCU datasheets](https://www.cypress.com/search/all?f[0]=meta_type%3Atechnical_documents&f[1]=resource_meta_type%3A575&f[2]=field_related_products%3A114026) <br> [PSoC&trade; 6 technical reference manuals](https://www.cypress.com/search/all/PSoC%206%20Technical%20Reference%20Manual?f[0]=meta_type%3Atechnical_documents&f[1]=resource_meta_type%3A583)
Development kits | Visit www.cypress.com/microcontrollers-mcus-kits and use the options in the **Select your kit** section to filter kits by *Product family* or *Features*.
Libraries on GitHub  | [mtb-pdl-cat1](https://github.com/infineon/mtb-pdl-cat1) – PSoC&trade; 6 peripheral driver library (PDL)  <br> [mtb-hal-cat1](https://github.com/infineon/mtb-hal-cat1) – Hardware abstraction layer (HAL) library <br> [retarget-io](https://github.com/infineon/retarget-io) – Utility library to retarget STDIO messages to a UART port
Middleware on GitHub  | [capsense](https://github.com/infineon/capsense) – CAPSENSE&trade; library and documents <br> [psoc6-middleware](https://github.com/Infineon/modustoolbox-software#psoc-6-middleware-libraries) – Links to all PSoC&trade; 6 MCU middleware
Tools  | [Eclipse IDE for ModusToolbox&trade; software](https://www.cypress.com/modustoolbox) – ModusToolbox&trade; software is a collection of easy-to-use software and tools enabling rapid development with Infineon MCUs, covering applications from embedded sense and control to wireless and cloud-connected systems using AIROC&trade; Wi-Fi and Bluetooth® connectivity devices.

## Other resources

Cypress provides a wealth of data at www.cypress.com to help you select the right device, and quickly and effectively integrate it into your design.

For PSoC&trade; 6 MCU devices, see [How to design with PSoC&trade; 6 MCU - KBA223067](https://community.cypress.com/docs/DOC-14644) in the Cypress community.


## Document history

Document title: *CE230968* - *PSoC&trade; 6 MCU: low-power CAPSENSE&trade; design (FreeRTOS)*

| Version | Description of change |
| ------- | --------------------- |
| 1.0.0   | New code example      |
| 1.1.0   | Updated to support ModusToolbox software v2.3.<br /> Added support for CY8CKIT-062S4. |
| 1.2.0   | Added support for CY8CEVAL-062S2 and CY8CEVAL-062S2-LAI-4373M2. |
------


© Cypress Semiconductor Corporation, 2020-2021. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress").  This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide.  Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights.  If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress’s patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products.  Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.
<br>
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  No computing device can be absolutely secure.  Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach").  Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach.  In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes.  It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product.  "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage.  Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices.  "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness.  Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress’s published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.
<br>
Cypress, the Cypress logo, and combinations thereof, WICED, ModusToolbox, PSoC, CapSense, EZ-USB, F-RAM, and Traveo are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit cypress.com. Other names and brands may be claimed as property of their respective owners.
