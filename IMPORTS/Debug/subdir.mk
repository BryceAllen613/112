################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application.cpp \
../ListTester(1).cpp \
../Vec(1).cpp \
../main.cpp 

OBJS += \
./Application.o \
./ListTester(1).o \
./Vec(1).o \
./main.o 

CPP_DEPS += \
./Application.d \
./ListTester(1).d \
./Vec(1).d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ListTester(1).o: ../ListTester(1).cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"ListTester(1).d" -MT"ListTester(1).d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Vec(1).o: ../Vec(1).cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Vec(1).d" -MT"Vec(1).d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


