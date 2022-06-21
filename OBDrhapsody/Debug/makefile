################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_HOST/Target/subdir.mk
-include USB_HOST/App/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/Rhapsody/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
OBDrhapsody.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
OBDrhapsody.list \

OBJCOPY_BIN += \
OBDrhapsody.bin \


# All Target
all: OBDrhapsody.elf secondary-outputs

# Tool invocations
OBDrhapsody.elf: $(OBJS) $(USER_OBJS) C:\Users\HaYeon\STM32CubeIDE\workspace_1.4.0\OBDrhapsody\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "OBDrhapsody.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\HaYeon\STM32CubeIDE\workspace_1.4.0\OBDrhapsody\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="OBDrhapsody.map" -Wl,--gc-sections -static -L"C:\Rhapsody\V60_RiC_InterruptDrivenFramework\idf\Arm_Cortex\oxf" -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

OBDrhapsody.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "OBDrhapsody.list"
	@echo 'Finished building: $@'
	@echo ' '

OBDrhapsody.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "OBDrhapsody.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
