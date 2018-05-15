################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/bobby/JetfuelGameEnginePublicGit/examples/Jetfuel\ Graphical\ Example/src/Jetfuel\ Graphical\ Example.cpp 

OBJS += \
./src/Jetfuel\ Graphical\ Example.o 

CPP_DEPS += \
./src/Jetfuel\ Graphical\ Example.d 


# Each subdirectory must supply rules for building sources it contributes
src/Jetfuel\ Graphical\ Example.o: /home/bobby/JetfuelGameEnginePublicGit/examples/Jetfuel\ Graphical\ Example/src/Jetfuel\ Graphical\ Example.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -MMD -MP -MF"src/Jetfuel Graphical Example.d" -MT"src/Jetfuel\ Graphical\ Example.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


