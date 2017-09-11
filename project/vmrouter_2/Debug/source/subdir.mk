################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/mnt/scratch/djc448/firmware-hls/TrackletAlgorithm/VMRouter.cpp \
/mnt/scratch/djc448/firmware-hls/TrackletAlgorithm/VMRouterDispatcher.cpp 

OBJS += \
./source/VMRouter.o \
./source/VMRouterDispatcher.o 

CPP_DEPS += \
./source/VMRouter.d \
./source/VMRouterDispatcher.d 


# Each subdirectory must supply rules for building sources it contributes
source/VMRouter.o: /mnt/scratch/djc448/firmware-hls/TrackletAlgorithm/VMRouter.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/include/ap_sysc -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/lnx64/tools/auto_cc/include -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/include/etc -I/mnt/scratch/djc448/firmware-hls/project -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/include -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/lnx64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/VMRouterDispatcher.o: /mnt/scratch/djc448/firmware-hls/TrackletAlgorithm/VMRouterDispatcher.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/include/ap_sysc -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/lnx64/tools/auto_cc/include -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/include/etc -I/mnt/scratch/djc448/firmware-hls/project -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/include -I/nfs/opt/Xilinx/Vivado_HLS/2017.2/lnx64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


