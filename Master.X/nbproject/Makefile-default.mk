#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c appliction.c HAL/DCMotor/DcMotor_program.c HAL/KeyPad/KEYPAD_program.c HAL/LCD/LCD_program.c HAL/LED/LED_program.c MCAL/ADC/ADC.c MCAL/CCP/CCP.c MCAL/EEPROM/EEPROM.c MCAL/GPIO/GPIO_Program.c MCAL/I2C/I2C.c MCAL/Interrupt/Interrupt_interface.c MCAL/Interrupt/Interrupt_manger.c MCAL/SPI/SPI.c MCAL/TIMER0/TIMER0.c MCAL/TIMER1/TIMER1.c MCAL/TIMER2/TIMER2.c MCAL/TIMER3/TIMER3..c MCAL/USART/USART.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.p1 ${OBJECTDIR}/appliction.p1 ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1 ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1 ${OBJECTDIR}/HAL/LCD/LCD_program.p1 ${OBJECTDIR}/HAL/LED/LED_program.p1 ${OBJECTDIR}/MCAL/ADC/ADC.p1 ${OBJECTDIR}/MCAL/CCP/CCP.p1 ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1 ${OBJECTDIR}/MCAL/I2C/I2C.p1 ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1 ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1 ${OBJECTDIR}/MCAL/SPI/SPI.p1 ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1 ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1 ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1 ${OBJECTDIR}/MCAL/USART/USART.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/main.p1.d ${OBJECTDIR}/appliction.p1.d ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1.d ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1.d ${OBJECTDIR}/HAL/LCD/LCD_program.p1.d ${OBJECTDIR}/HAL/LED/LED_program.p1.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d ${OBJECTDIR}/MCAL/CCP/CCP.p1.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1.d ${OBJECTDIR}/MCAL/I2C/I2C.p1.d ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1.d ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1.d ${OBJECTDIR}/MCAL/SPI/SPI.p1.d ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1.d ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1.d ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1.d ${OBJECTDIR}/MCAL/USART/USART.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.p1 ${OBJECTDIR}/appliction.p1 ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1 ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1 ${OBJECTDIR}/HAL/LCD/LCD_program.p1 ${OBJECTDIR}/HAL/LED/LED_program.p1 ${OBJECTDIR}/MCAL/ADC/ADC.p1 ${OBJECTDIR}/MCAL/CCP/CCP.p1 ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1 ${OBJECTDIR}/MCAL/I2C/I2C.p1 ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1 ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1 ${OBJECTDIR}/MCAL/SPI/SPI.p1 ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1 ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1 ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1 ${OBJECTDIR}/MCAL/USART/USART.p1

# Source Files
SOURCEFILES=main.c appliction.c HAL/DCMotor/DcMotor_program.c HAL/KeyPad/KEYPAD_program.c HAL/LCD/LCD_program.c HAL/LED/LED_program.c MCAL/ADC/ADC.c MCAL/CCP/CCP.c MCAL/EEPROM/EEPROM.c MCAL/GPIO/GPIO_Program.c MCAL/I2C/I2C.c MCAL/Interrupt/Interrupt_interface.c MCAL/Interrupt/Interrupt_manger.c MCAL/SPI/SPI.c MCAL/TIMER0/TIMER0.c MCAL/TIMER1/TIMER1.c MCAL/TIMER2/TIMER2.c MCAL/TIMER3/TIMER3..c MCAL/USART/USART.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/appliction.p1: appliction.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/appliction.p1.d 
	@${RM} ${OBJECTDIR}/appliction.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/appliction.p1 appliction.c 
	@-${MV} ${OBJECTDIR}/appliction.d ${OBJECTDIR}/appliction.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/appliction.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1: HAL/DCMotor/DcMotor_program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/DCMotor" 
	@${RM} ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1.d 
	@${RM} ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1 HAL/DCMotor/DcMotor_program.c 
	@-${MV} ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.d ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1: HAL/KeyPad/KEYPAD_program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/KeyPad" 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1.d 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1 HAL/KeyPad/KEYPAD_program.c 
	@-${MV} ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.d ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/LCD/LCD_program.p1: HAL/LCD/LCD_program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/LCD" 
	@${RM} ${OBJECTDIR}/HAL/LCD/LCD_program.p1.d 
	@${RM} ${OBJECTDIR}/HAL/LCD/LCD_program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/LCD/LCD_program.p1 HAL/LCD/LCD_program.c 
	@-${MV} ${OBJECTDIR}/HAL/LCD/LCD_program.d ${OBJECTDIR}/HAL/LCD/LCD_program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/LCD/LCD_program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/LED/LED_program.p1: HAL/LED/LED_program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/LED" 
	@${RM} ${OBJECTDIR}/HAL/LED/LED_program.p1.d 
	@${RM} ${OBJECTDIR}/HAL/LED/LED_program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/LED/LED_program.p1 HAL/LED/LED_program.c 
	@-${MV} ${OBJECTDIR}/HAL/LED/LED_program.d ${OBJECTDIR}/HAL/LED/LED_program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/LED/LED_program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/ADC.p1: MCAL/ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/ADC.p1 MCAL/ADC/ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/ADC.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/CCP/CCP.p1: MCAL/CCP/CCP.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/CCP" 
	@${RM} ${OBJECTDIR}/MCAL/CCP/CCP.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/CCP/CCP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/CCP/CCP.p1 MCAL/CCP/CCP.c 
	@-${MV} ${OBJECTDIR}/MCAL/CCP/CCP.d ${OBJECTDIR}/MCAL/CCP/CCP.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/CCP/CCP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1: MCAL/EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 MCAL/EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1: MCAL/GPIO/GPIO_Program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1 MCAL/GPIO/GPIO_Program.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.d ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/I2C/I2C.p1: MCAL/I2C/I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/I2C" 
	@${RM} ${OBJECTDIR}/MCAL/I2C/I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/I2C/I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/I2C/I2C.p1 MCAL/I2C/I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL/I2C/I2C.d ${OBJECTDIR}/MCAL/I2C/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/I2C/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1: MCAL/Interrupt/Interrupt_interface.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1 MCAL/Interrupt/Interrupt_interface.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.d ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1: MCAL/Interrupt/Interrupt_manger.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1 MCAL/Interrupt/Interrupt_manger.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.d ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/SPI/SPI.p1: MCAL/SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/SPI" 
	@${RM} ${OBJECTDIR}/MCAL/SPI/SPI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/SPI/SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/SPI/SPI.p1 MCAL/SPI/SPI.c 
	@-${MV} ${OBJECTDIR}/MCAL/SPI/SPI.d ${OBJECTDIR}/MCAL/SPI/SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/SPI/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1: MCAL/TIMER0/TIMER0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1 MCAL/TIMER0/TIMER0.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER0/TIMER0.d ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1: MCAL/TIMER1/TIMER1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 MCAL/TIMER1/TIMER1.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.d ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1: MCAL/TIMER2/TIMER2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1 MCAL/TIMER2/TIMER2.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER2/TIMER2.d ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1: MCAL/TIMER3/TIMER3..c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1 MCAL/TIMER3/TIMER3..c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER3/TIMER3..d ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/USART/USART.p1: MCAL/USART/USART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/USART" 
	@${RM} ${OBJECTDIR}/MCAL/USART/USART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/USART/USART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/USART/USART.p1 MCAL/USART/USART.c 
	@-${MV} ${OBJECTDIR}/MCAL/USART/USART.d ${OBJECTDIR}/MCAL/USART/USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/USART/USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/appliction.p1: appliction.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/appliction.p1.d 
	@${RM} ${OBJECTDIR}/appliction.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/appliction.p1 appliction.c 
	@-${MV} ${OBJECTDIR}/appliction.d ${OBJECTDIR}/appliction.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/appliction.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1: HAL/DCMotor/DcMotor_program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/DCMotor" 
	@${RM} ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1.d 
	@${RM} ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1 HAL/DCMotor/DcMotor_program.c 
	@-${MV} ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.d ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/DCMotor/DcMotor_program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1: HAL/KeyPad/KEYPAD_program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/KeyPad" 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1.d 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1 HAL/KeyPad/KEYPAD_program.c 
	@-${MV} ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.d ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/KeyPad/KEYPAD_program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/LCD/LCD_program.p1: HAL/LCD/LCD_program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/LCD" 
	@${RM} ${OBJECTDIR}/HAL/LCD/LCD_program.p1.d 
	@${RM} ${OBJECTDIR}/HAL/LCD/LCD_program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/LCD/LCD_program.p1 HAL/LCD/LCD_program.c 
	@-${MV} ${OBJECTDIR}/HAL/LCD/LCD_program.d ${OBJECTDIR}/HAL/LCD/LCD_program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/LCD/LCD_program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/LED/LED_program.p1: HAL/LED/LED_program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/LED" 
	@${RM} ${OBJECTDIR}/HAL/LED/LED_program.p1.d 
	@${RM} ${OBJECTDIR}/HAL/LED/LED_program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/LED/LED_program.p1 HAL/LED/LED_program.c 
	@-${MV} ${OBJECTDIR}/HAL/LED/LED_program.d ${OBJECTDIR}/HAL/LED/LED_program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/LED/LED_program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/ADC.p1: MCAL/ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/ADC.p1 MCAL/ADC/ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/ADC.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/CCP/CCP.p1: MCAL/CCP/CCP.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/CCP" 
	@${RM} ${OBJECTDIR}/MCAL/CCP/CCP.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/CCP/CCP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/CCP/CCP.p1 MCAL/CCP/CCP.c 
	@-${MV} ${OBJECTDIR}/MCAL/CCP/CCP.d ${OBJECTDIR}/MCAL/CCP/CCP.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/CCP/CCP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1: MCAL/EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 MCAL/EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1: MCAL/GPIO/GPIO_Program.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1 MCAL/GPIO/GPIO_Program.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.d ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/GPIO_Program.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/I2C/I2C.p1: MCAL/I2C/I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/I2C" 
	@${RM} ${OBJECTDIR}/MCAL/I2C/I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/I2C/I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/I2C/I2C.p1 MCAL/I2C/I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL/I2C/I2C.d ${OBJECTDIR}/MCAL/I2C/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/I2C/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1: MCAL/Interrupt/Interrupt_interface.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1 MCAL/Interrupt/Interrupt_interface.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.d ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_interface.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1: MCAL/Interrupt/Interrupt_manger.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1 MCAL/Interrupt/Interrupt_manger.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.d ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/Interrupt_manger.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/SPI/SPI.p1: MCAL/SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/SPI" 
	@${RM} ${OBJECTDIR}/MCAL/SPI/SPI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/SPI/SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/SPI/SPI.p1 MCAL/SPI/SPI.c 
	@-${MV} ${OBJECTDIR}/MCAL/SPI/SPI.d ${OBJECTDIR}/MCAL/SPI/SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/SPI/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1: MCAL/TIMER0/TIMER0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1 MCAL/TIMER0/TIMER0.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER0/TIMER0.d ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER0/TIMER0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1: MCAL/TIMER1/TIMER1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 MCAL/TIMER1/TIMER1.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.d ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1: MCAL/TIMER2/TIMER2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1 MCAL/TIMER2/TIMER2.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER2/TIMER2.d ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER2/TIMER2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1: MCAL/TIMER3/TIMER3..c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1 MCAL/TIMER3/TIMER3..c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER3/TIMER3..d ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER3/TIMER3..p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/USART/USART.p1: MCAL/USART/USART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/USART" 
	@${RM} ${OBJECTDIR}/MCAL/USART/USART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/USART/USART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/USART/USART.p1 MCAL/USART/USART.c 
	@-${MV} ${OBJECTDIR}/MCAL/USART/USART.d ${OBJECTDIR}/MCAL/USART/USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/USART/USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Master.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Master.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Master.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
