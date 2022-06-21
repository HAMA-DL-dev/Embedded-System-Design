
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug=-g
CPPCompileRelease=-O
LinkDebug=-g
LinkRelease=-O

ConfigurationCPPCompileSwitches=   -I. -I. -I$(OMROOT) -I$(OMROOT)/LangCpp -I$(OMROOT)/LangCpp/oxf $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) -DUSE_IOSTREAM $(CPPCompileDebug) -c 

#########################################
###### Predefined macros ################
CPU=arm-linux-gnueabihf
CC=arm-linux-gnueabihf-gcc
LIB_CMD=arm-linux-gnueabihf-ar
LIB_PREFIX=mvl
RM=rm -rf
MD=mkdir -p

INCLUDE_QUALIFIER=-I

LINK_CMD=$(CC)
LIB_FLAGS=rvu

LINK_FLAGS=-lpthread -lstdc++ $(LinkDebug)  

#########################################
####### Context macros ##################

FLAGSFILE=
RULESFILE=
OMROOT="/home/hayeon/Rhapsody753/Share"

CPP_EXT=.cpp
H_EXT=.h
OBJ_EXT=.o
EXE_EXT=
LIB_EXT=.a

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=StopwatchTest

all : $(TARGET_NAME)$(EXE_EXT) StopwatchTest.mak

TARGET_MAIN=MainStopwatchTest

LIBS=

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/Linux

ADDITIONAL_OBJS=

OBJS= \
  Button.o \
  Timer.o \
  Display.o \
  PushSwitch.o \
  StopwatchPkg.o \
  Interface.o




#########################################
####### Predefined macros ###############
$(OBJS) :  $(INST_LIBS) $(OXF_LIBS)

OBJ_DIR=

ifeq ($(OBJ_DIR),)
CREATE_OBJ_DIR=
CLEAN_OBJ_DIR=
else
CREATE_OBJ_DIR= $(MD) $(OBJ_DIR)
CLEAN_OBJ_DIR=  $(RM) $(OBJ_DIR)
endif


ifeq ($(INSTRUMENTATION),Animation)

INST_FLAGS=-DOMANIMATOR
INST_INCLUDES=-I$(OMROOT)/LangCpp/aom -I$(OMROOT)/LangCpp/tom
INST_LIBS= $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)aomanimarm-linux-gnueabihf$(LIB_EXT)
OXF_LIBS=$(OMROOT)/LangCpp/lib/$(LIB_PREFIX)oxfinstarm-linux-gnueabihf$(LIB_EXT) $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)omcomapplarm-linux-gnueabihf$(LIB_EXT)
SOCK_LIB=

else
ifeq ($(INSTRUMENTATION),Tracing)

INST_FLAGS=-DOMTRACER
INST_INCLUDES=-I$(OMROOT)/LangCpp/aom -I$(OMROOT)/LangCpp/tom
INST_LIBS=$(OMROOT)/LangCpp/lib/$(LIB_PREFIX)tomtracearm-linux-gnueabihf$(LIB_EXT) $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)aomtracearm-linux-gnueabihf$(LIB_EXT)
OXF_LIBS= $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)oxfinstarm-linux-gnueabihf$(LIB_EXT) $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)omcomapplarm-linux-gnueabihf$(LIB_EXT)
SOCK_LIB=

else
ifeq ($(INSTRUMENTATION),None)

INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
OXF_LIBS=$(OMROOT)/LangCpp/lib/$(LIB_PREFIX)oxfarm-linux-gnueabihf$(LIB_EXT)
SOCK_LIB=

else
	@echo An invalid Instrumentation $(INSTRUMENTATION) is specified.
	exit
endif
endif
endif

.SUFFIXES: $(CPP_EXT)



#####################################################################
##################### Context dependencies and commands #############






Button.o : Button.cpp Button.h    StopwatchPkg.h Timer.h 
	@echo Compiling Button.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o Button.o Button.cpp




Timer.o : Timer.cpp Timer.h    StopwatchPkg.h Display.h 
	@echo Compiling Timer.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o Timer.o Timer.cpp




Display.o : Display.cpp Display.h    StopwatchPkg.h 
	@echo Compiling Display.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o Display.o Display.cpp




PushSwitch.o : PushSwitch.cpp PushSwitch.h    StopwatchPkg.h Button.h 
	@echo Compiling PushSwitch.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o PushSwitch.o PushSwitch.cpp




StopwatchPkg.o : StopwatchPkg.cpp StopwatchPkg.h    Button.h Timer.h Display.h PushSwitch.h 
	@echo Compiling StopwatchPkg.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o StopwatchPkg.o StopwatchPkg.cpp




Interface.o : Interface.cpp     
	@echo Compiling Interface.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o Interface.o Interface.cpp







$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) 
		@$(CC) $(ConfigurationCPPCompileSwitches) -o  $(TARGET_MAIN)$(OBJ_EXT) $(TARGET_MAIN)$(CPP_EXT)

####################################################################################
#                    Predefined linking instructions                               #
# INST_LIBS is included twice to solve bi-directional dependency between libraries #
####################################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) StopwatchTest.mak 
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	@$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(INST_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) -o $(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) StopwatchTest.mak
	@echo Building library $@
	@$(LIB_CMD) $(LIB_FLAGS) $(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS) $(LIBS)



clean:
	@echo Cleanup
	$(RM) Button.o
	$(RM) Timer.o
	$(RM) Display.o
	$(RM) PushSwitch.o
	$(RM) StopwatchPkg.o
	$(RM) Interface.o
	$(RM) $(TARGET_MAIN)$(OBJ_EXT) $(ADDITIONAL_OBJS)
	$(RM) $(TARGET_NAME)$(LIB_EXT)
	$(RM) $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
