################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ArrayQueueTester.cpp \
../PalindromeDetector.cpp \
../PalindromeDetectorTester.cpp \
../main.cpp 

OBJS += \
./ArrayQueueTester.o \
./PalindromeDetector.o \
./PalindromeDetectorTester.o \
./main.o 

CPP_DEPS += \
./ArrayQueueTester.d \
./PalindromeDetector.d \
./PalindromeDetectorTester.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


