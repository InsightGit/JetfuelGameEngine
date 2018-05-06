################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/bobby/JetfuelGameEnginePublicGit/PythonAPI/src/stringconversions.cpp 

OBJS += \
./src/stringconversions.o 

CPP_DEPS += \
./src/stringconversions.d 


# Each subdirectory must supply rules for building sources it contributes
src/stringconversions.o: /home/bobby/JetfuelGameEnginePublicGit/PythonAPI/src/stringconversions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


