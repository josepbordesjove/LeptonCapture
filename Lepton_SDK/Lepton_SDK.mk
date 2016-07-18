##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lepton_SDK
ConfigurationName      :=Debug
WorkspacePath          := "/home/pi/Desktop/LeptonCapture"
ProjectPath            := "/home/pi/Desktop/LeptonCapture/Lepton_SDK"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=07/09/16
CodeLitePath           :="/home/pi/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../lib/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Lepton_SDK.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_LEPTON_AGC.c$(ObjectSuffix) $(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(ObjectSuffix) $(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(ObjectSuffix) $(IntermediateDirectory)/src_LEPTON_SDK.c$(ObjectSuffix) $(IntermediateDirectory)/src_LEPTON_SYS.c$(ObjectSuffix) $(IntermediateDirectory)/src_LEPTON_VID.c$(ObjectSuffix) $(IntermediateDirectory)/src_crc16fast.c$(ObjectSuffix) $(IntermediateDirectory)/src_raspi_I2C.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/pi/Desktop/LeptonCapture/.build-debug"
	@echo rebuilt > "/home/pi/Desktop/LeptonCapture/.build-debug/Lepton_SDK"

./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_LEPTON_AGC.c$(ObjectSuffix): src/LEPTON_AGC.c $(IntermediateDirectory)/src_LEPTON_AGC.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture/Lepton_SDK/src/LEPTON_AGC.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LEPTON_AGC.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LEPTON_AGC.c$(DependSuffix): src/LEPTON_AGC.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LEPTON_AGC.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LEPTON_AGC.c$(DependSuffix) -MM "src/LEPTON_AGC.c"

$(IntermediateDirectory)/src_LEPTON_AGC.c$(PreprocessSuffix): src/LEPTON_AGC.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LEPTON_AGC.c$(PreprocessSuffix) "src/LEPTON_AGC.c"

$(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(ObjectSuffix): src/LEPTON_I2C_Protocol.c $(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture/Lepton_SDK/src/LEPTON_I2C_Protocol.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(DependSuffix): src/LEPTON_I2C_Protocol.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(DependSuffix) -MM "src/LEPTON_I2C_Protocol.c"

$(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(PreprocessSuffix): src/LEPTON_I2C_Protocol.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LEPTON_I2C_Protocol.c$(PreprocessSuffix) "src/LEPTON_I2C_Protocol.c"

$(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(ObjectSuffix): src/LEPTON_I2C_Service.c $(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture/Lepton_SDK/src/LEPTON_I2C_Service.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(DependSuffix): src/LEPTON_I2C_Service.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(DependSuffix) -MM "src/LEPTON_I2C_Service.c"

$(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(PreprocessSuffix): src/LEPTON_I2C_Service.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LEPTON_I2C_Service.c$(PreprocessSuffix) "src/LEPTON_I2C_Service.c"

$(IntermediateDirectory)/src_LEPTON_SDK.c$(ObjectSuffix): src/LEPTON_SDK.c $(IntermediateDirectory)/src_LEPTON_SDK.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture/Lepton_SDK/src/LEPTON_SDK.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LEPTON_SDK.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LEPTON_SDK.c$(DependSuffix): src/LEPTON_SDK.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LEPTON_SDK.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LEPTON_SDK.c$(DependSuffix) -MM "src/LEPTON_SDK.c"

$(IntermediateDirectory)/src_LEPTON_SDK.c$(PreprocessSuffix): src/LEPTON_SDK.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LEPTON_SDK.c$(PreprocessSuffix) "src/LEPTON_SDK.c"

$(IntermediateDirectory)/src_LEPTON_SYS.c$(ObjectSuffix): src/LEPTON_SYS.c $(IntermediateDirectory)/src_LEPTON_SYS.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture/Lepton_SDK/src/LEPTON_SYS.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LEPTON_SYS.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LEPTON_SYS.c$(DependSuffix): src/LEPTON_SYS.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LEPTON_SYS.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LEPTON_SYS.c$(DependSuffix) -MM "src/LEPTON_SYS.c"

$(IntermediateDirectory)/src_LEPTON_SYS.c$(PreprocessSuffix): src/LEPTON_SYS.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LEPTON_SYS.c$(PreprocessSuffix) "src/LEPTON_SYS.c"

$(IntermediateDirectory)/src_LEPTON_VID.c$(ObjectSuffix): src/LEPTON_VID.c $(IntermediateDirectory)/src_LEPTON_VID.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture/Lepton_SDK/src/LEPTON_VID.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LEPTON_VID.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LEPTON_VID.c$(DependSuffix): src/LEPTON_VID.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LEPTON_VID.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LEPTON_VID.c$(DependSuffix) -MM "src/LEPTON_VID.c"

$(IntermediateDirectory)/src_LEPTON_VID.c$(PreprocessSuffix): src/LEPTON_VID.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LEPTON_VID.c$(PreprocessSuffix) "src/LEPTON_VID.c"

$(IntermediateDirectory)/src_crc16fast.c$(ObjectSuffix): src/crc16fast.c $(IntermediateDirectory)/src_crc16fast.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture/Lepton_SDK/src/crc16fast.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_crc16fast.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_crc16fast.c$(DependSuffix): src/crc16fast.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_crc16fast.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_crc16fast.c$(DependSuffix) -MM "src/crc16fast.c"

$(IntermediateDirectory)/src_crc16fast.c$(PreprocessSuffix): src/crc16fast.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_crc16fast.c$(PreprocessSuffix) "src/crc16fast.c"

$(IntermediateDirectory)/src_raspi_I2C.c$(ObjectSuffix): src/raspi_I2C.c $(IntermediateDirectory)/src_raspi_I2C.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture/Lepton_SDK/src/raspi_I2C.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_raspi_I2C.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_raspi_I2C.c$(DependSuffix): src/raspi_I2C.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_raspi_I2C.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_raspi_I2C.c$(DependSuffix) -MM "src/raspi_I2C.c"

$(IntermediateDirectory)/src_raspi_I2C.c$(PreprocessSuffix): src/raspi_I2C.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_raspi_I2C.c$(PreprocessSuffix) "src/raspi_I2C.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/Lepton_SDK"


