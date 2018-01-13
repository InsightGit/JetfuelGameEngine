################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/media/bobby/PVSERVER01/CentralProjectStorage/eclipseworkspace/Jetfuel\ Game\ Engine\ Public\ Git/src/jetfuelmedia/music.cpp \
/media/bobby/PVSERVER01/CentralProjectStorage/eclipseworkspace/Jetfuel\ Game\ Engine\ Public\ Git/src/jetfuelmedia/soundeffect.cpp 

OBJS += \
./src/jetfuelmedia/music.o \
./src/jetfuelmedia/soundeffect.o 

CPP_DEPS += \
./src/jetfuelmedia/music.d \
./src/jetfuelmedia/soundeffect.d 


# Each subdirectory must supply rules for building sources it contributes
src/jetfuelmedia/music.o: /media/bobby/PVSERVER01/CentralProjectStorage/eclipseworkspace/Jetfuel\ Game\ Engine\ Public\ Git/src/jetfuelmedia/music.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/media/bobby/PVSERVER01/CentralProjectStorage/eclipseworkspace/Jetfuel Game Engine Public Git/src" -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/jetfuelmedia/soundeffect.o: /media/bobby/PVSERVER01/CentralProjectStorage/eclipseworkspace/Jetfuel\ Game\ Engine\ Public\ Git/src/jetfuelmedia/soundeffect.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/media/bobby/PVSERVER01/CentralProjectStorage/eclipseworkspace/Jetfuel Game Engine Public Git/src" -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


