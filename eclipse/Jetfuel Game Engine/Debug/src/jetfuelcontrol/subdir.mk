################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/bobby/JetfuelGameEnginePublicGit/src/jetfuelcontrol/UISinterpreter.cpp \
/home/bobby/JetfuelGameEnginePublicGit/src/jetfuelcontrol/UISmanager.cpp 

OBJS += \
./src/jetfuelcontrol/UISinterpreter.o \
./src/jetfuelcontrol/UISmanager.o 

CPP_DEPS += \
./src/jetfuelcontrol/UISinterpreter.d \
./src/jetfuelcontrol/UISmanager.d 


# Each subdirectory must supply rules for building sources it contributes
src/jetfuelcontrol/UISinterpreter.o: /home/bobby/JetfuelGameEnginePublicGit/src/jetfuelcontrol/UISinterpreter.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/jetfuelcontrol/UISmanager.o: /home/bobby/JetfuelGameEnginePublicGit/src/jetfuelcontrol/UISmanager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


