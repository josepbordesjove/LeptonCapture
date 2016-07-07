##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=LeptonCapture
ConfigurationName      :=Debug
WorkspacePath          := "/home/pi/Desktop/LeptonCapture.5"
ProjectPath            := "/home/pi/Desktop/LeptonCapture.5/LeptonCapture"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=07/07/16
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
OutputFile             :=../bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="LeptonCapture.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)../Lepton_SDK/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Lepton_SDK 
ArLibs                 :=  "Lepton_SDK" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/src_functions.c$(ObjectSuffix) $(IntermediateDirectory)/src_images.c$(ObjectSuffix) $(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) $(IntermediateDirectory)/src_menu.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture.5/LeptonCapture/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM "src/main.c"

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) "src/main.c"

$(IntermediateDirectory)/src_functions.c$(ObjectSuffix): src/functions.c $(IntermediateDirectory)/src_functions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture.5/LeptonCapture/src/functions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_functions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_functions.c$(DependSuffix): src/functions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_functions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_functions.c$(DependSuffix) -MM "src/functions.c"

$(IntermediateDirectory)/src_functions.c$(PreprocessSuffix): src/functions.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_functions.c$(PreprocessSuffix) "src/functions.c"

$(IntermediateDirectory)/src_images.c$(ObjectSuffix): src/images.c $(IntermediateDirectory)/src_images.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture.5/LeptonCapture/src/images.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_images.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_images.c$(DependSuffix): src/images.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_images.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_images.c$(DependSuffix) -MM "src/images.c"

$(IntermediateDirectory)/src_images.c$(PreprocessSuffix): src/images.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_images.c$(PreprocessSuffix) "src/images.c"

$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix): src/helpers.c $(IntermediateDirectory)/src_helpers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture.5/LeptonCapture/src/helpers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_helpers.c$(DependSuffix): src/helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_helpers.c$(DependSuffix) -MM "src/helpers.c"

$(IntermediateDirectory)/src_helpers.c$(PreprocessSuffix): src/helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_helpers.c$(PreprocessSuffix) "src/helpers.c"

$(IntermediateDirectory)/src_menu.c$(ObjectSuffix): src/menu.c $(IntermediateDirectory)/src_menu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/Desktop/LeptonCapture.5/LeptonCapture/src/menu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_menu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_menu.c$(DependSuffix): src/menu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_menu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_menu.c$(DependSuffix) -MM "src/menu.c"

$(IntermediateDirectory)/src_menu.c$(PreprocessSuffix): src/menu.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_menu.c$(PreprocessSuffix) "src/menu.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/LeptonCapture"


