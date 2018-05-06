################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/bobby/JetfuelGameEnginePublicGit/src/jetfuelmedia/music.cpp \
/home/bobby/JetfuelGameEnginePublicGit/src/jetfuelmedia/soundeffect.cpp 

OBJS += \
./src/jetfuelmedia/music.o \
./src/jetfuelmedia/soundeffect.o 

CPP_DEPS += \
./src/jetfuelmedia/music.d \
./src/jetfuelmedia/soundeffect.d 


# Each subdirectory must supply rules for building sources it contributes
src/jetfuelmedia/music.o: /home/bobby/JetfuelGameEnginePublicGit/src/jetfuelmedia/music.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/jetfuelmedia/soundeffect.o: /home/bobby/JetfuelGameEnginePublicGit/src/jetfuelmedia/soundeffect.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


