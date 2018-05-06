################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/bobby/JetfuelGameEnginePublicGit/src/jetfuelcore/messagebus.cpp 

OBJS += \
./src/jetfuelcore/messagebus.o 

CPP_DEPS += \
./src/jetfuelcore/messagebus.d 


# Each subdirectory must supply rules for building sources it contributes
src/jetfuelcore/messagebus.o: /home/bobby/JetfuelGameEnginePublicGit/src/jetfuelcore/messagebus.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


