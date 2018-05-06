################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/bobby/JetfuelGameEnginePublicGit/src/jetfuelinspire/pythonclassloader.cpp \
/home/bobby/JetfuelGameEnginePublicGit/src/jetfuelinspire/pythonmoduleloader.cpp 

OBJS += \
./src/jetfuelinspire/pythonclassloader.o \
./src/jetfuelinspire/pythonmoduleloader.o 

CPP_DEPS += \
./src/jetfuelinspire/pythonclassloader.d \
./src/jetfuelinspire/pythonmoduleloader.d 


# Each subdirectory must supply rules for building sources it contributes
src/jetfuelinspire/pythonclassloader.o: /home/bobby/JetfuelGameEnginePublicGit/src/jetfuelinspire/pythonclassloader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/jetfuelinspire/pythonmoduleloader.o: /home/bobby/JetfuelGameEnginePublicGit/src/jetfuelinspire/pythonmoduleloader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I../../../include -I../../../windowsdependencies/rapidjson-master/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


