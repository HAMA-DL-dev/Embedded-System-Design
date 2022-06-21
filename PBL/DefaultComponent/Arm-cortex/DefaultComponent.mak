
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug=-g
CPPCompileRelease=-O2
LinkDebug=
LinkRelease=
BuildSet=Debug

ConfigurationCPPCompileSwitches=  -I . -I$(CIDF_ROOT)/arm_cortex  -I$(CIDF_ROOT)/arm_cortex/oxf -DUSE_C_LIBRARY=0 -D__TARGET_FPU_NONE -DSEMIHOSTED=1 -DEVALUATOR7T=1 -DADS_BUILD=1 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb $(CPPCompileDebug) -DARM_IDF $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) 

################### Compilation flags ######################
############################################################
INCLUDE_QUALIFIER=-I

################### Commands definition #########################
#################################################################
LIB_CMD=arm-none-eabi-ar
LINK_CMD=arm-none-eabi-ld
LIB_FLAGS=
LINK_FLAGS=$(LinkDebug)   

############### Generated macros #################
##################################################

FLAGSFILE=
RULESFILE=
OMROOT="C:/Users/HaYeon/IBM/Rational/Rhapsody/7.5.3/Share"

CPP_EXT=.c
H_EXT=.h
OBJ_EXT=.o
EXE_EXT=.axf
LIB_EXT=.a

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=DefaultComponent

all : $(TARGET_NAME)$(EXE_EXT) DefaultComponent.mak

TARGET_MAIN=MainDefaultComponent

LIBS=

INCLUDE_PATH=

ADDITIONAL_OBJS=

OBJS= \
  CANtranscevier.o \
  Monitor.o \
  Ubidots.o \
  PBLPkg.o




######################## Predefined macros ############################
#######################################################################
$(OBJS) : $(FLAGSFILE) $(RULESFILE) $(INST_LIBS) $(OXF_LIBS)


INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
OXF_LIBS=$(CIDF_ROOT)\arm_cortex\oxf\idf$(LIB_EXT)
SOCK_LIB=


################## Generated dependencies ########################
##################################################################






CANtranscevier.o : CANtranscevier.c CANtranscevier.h    PBLPkg.h Monitor.h Ubidots.h 
	@echo Compiling CANtranscevier.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oCANtranscevier.o CANtranscevier.c



Monitor.o : Monitor.c Monitor.h    PBLPkg.h Ubidots.h 
	@echo Compiling Monitor.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oMonitor.o Monitor.c



Ubidots.o : Ubidots.c Ubidots.h    PBLPkg.h 
	@echo Compiling Ubidots.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oUbidots.o Ubidots.c



PBLPkg.o : PBLPkg.c PBLPkg.h    CANtranscevier.h Monitor.h Ubidots.h 
	@echo Compiling PBLPkg.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oPBLPkg.o PBLPkg.c






$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) $(FLAGSFILE) $(RULESFILE)
    #@echo Compiling $(TARGET_MAIN)$(CPP_EXT)
	arm-none-eabi-gcc -c $(ConfigurationCPPCompileSwitches) -o $(TARGET_MAIN)$(OBJ_EXT) $(TARGET_MAIN)$(CPP_EXT)

########################## Linking instructions ###############################
###############################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) DefaultComponent.mak
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) -o $(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) DefaultComponent.mak
	@echo Building library $@
	$(LIB_CMD) -rc $(LIB_FLAGS) $(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS)
clean:
	@echo Cleanup
	if exist CANtranscevier.o erase CANtranscevier.o
	if exist Monitor.o erase Monitor.o
	if exist Ubidots.o erase Ubidots.o
	if exist PBLPkg.o erase PBLPkg.o
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
