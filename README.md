# Embedded-Indicators-Control-Over-Mobile-Phones


High-Level Architecture and Software Requirement Specification-
   
The system is an embedded software module implemented on the PSoC platform that:
- Reads two physical button inputs (left and right)
- Executes decision logic defined in a Simulink Stateflow model
- Outputs LED control signals via PWM modules
- Sends log messages over UART based on the current state
System Components:
- Inputs: Left and Right Buttons (active-low)
- Outputs: Two PWM-controlled LEDs, UART logs
- Logic Core: Simulink-generated C code from Stateflow
  
The goal of this project was to implement a real-time indicator control system using a combination of:

-	Embedded C code written and compiled in PSoC Creator 4.4
-	Simulink Stateflow logic auto generated into C code
-	Input from real buttons
-	Output to LEDs via PWM
-	Status logs sent over UART
  
This type of embedded control logic is commonly used in automotive systems for indicators or hazard warnings, making it a great real-world use case.
________________________________________
Planning and Design Strategy
We began with a clear architectural separation of concerns:
- Component- Simulink	          ->          Responsibility- Models state machine logic using Stateflow, 
- Component-PSoC Creator	      ->         Responsibility- Controls GPIO, Timer, PWM, UART, and handles main execution, 
- Component-Generated Code	      ->        Responsibility- Serves as logic glue between input and output

The approach was to let Simulink handle decision-making logic and let PSoC Creator handle all peripheral interactions and timing.
________________________________________
Simulink Design and Code Generation
Tools Used:
-	MATLAB Simulink
-	Stateflow
-	Embedded Coder
  
Process:

1.	Create a Simulink model named indicator_control_model.slx.
2.	Inside, add a Stateflow Chart with:
-	Inputs: left_btn, right_btn (boolean)
-	Outputs: left_led_pwm, right_led_pwm (boolean), and uart_status (uint8)
3.	The chart defined states like:
-	OFF, LEFT, RIGHT, and HAZARD
4.	Transition logic defined how the buttons trigger state changes.
5.	Used Configuration Parameters to:
-	Set solver to fixed-step
-	Use target ert.tlc
-	Define sample time 0.1 (100 ms)
6.	Generated C code using Embedded Coder:
-	indicator_control_model.c
-	indicator_control_model.h
-	indicator_control_model_types.h
-	rtwtypes.h
  
The logic from the Simulink model was now ready to be used as a C library in PSoC Creator.

________________________________________

PSoC Creator 4.4 Implementation


- Tools Used:
-	PSoC Creator 4.4
-	GCC ARM compiler
-	UART Terminal (planned)
-	PWM and GPIO pin components
  
Implementation Steps:

1. Project Setup
   
-	Created a new PSoC 5LP project.
-	Added PWM, UART, Timer, and Button components.
-	Configured:
-	UART: 9600 baud
-	Timer: 100 ms periodic mode
-	PWM: Used to control LED brightness or blinking
2. Peripheral Initialization
 	
-	Created driver files:
-	gpio_driver.c/.h
-	uart_driver.c/.h
-	pwm_driver.c/.h
-	timer_driver.c/.h
-	Wrote abstraction for reading button inputs and writing to LEDs.
  
3. Integrating Simulink-Generated Code
   
-	Added indicator_control_model.c, .h, .types.h, and rtwtypes.h to the project.
-	Declared I/O variables:
- c
- CopyEdit
- boolean_T left_btn;
- boolean_T right_btn;
- boolean_T left_led_pwm;
- boolean_T right_led_pwm;
- uint8_T uart_status;
-	Called indicator_control_model_initialize() once at startup.
-	Called indicator_control_model_step() every 100 ms in the main loop.
  
4. Real-Time Scheduling
   
-	Used a hardware timer interrupt (Timer_1) to set a tick_100ms_flag.
-	In the main loop:
-	Read button states
-	Assigned inputs to Simulink variables
-	Called step()
-	Set PWM or LED output according to Simulink outputs
-	Logged UART messages
________________________________________

Testing and Debugging

-	Verified that all components initialized correctly.
-	Successfully built and linked the code.
