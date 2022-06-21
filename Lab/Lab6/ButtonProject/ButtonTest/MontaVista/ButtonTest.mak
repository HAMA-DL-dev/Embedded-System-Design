
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
OMROOT="/home/control/Rhapsody753/Share"

CPP_EXT=.cpp
H_EXT=.h
OBJ_EXT=.o
EXE_EXT=
LIB_EXT=.a

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=ButtonTest

all : $(TARGET_NAME)$(EXE_EXT) ButtonTest.mak

TARGET_MAIN=MainButtonTest

LIBS=

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/Linux

ADDITIONAL_OBJS=

OBJS= \
  Button.o \
  Led.o \
  PushSwitch.o \
  ButtonPkg.o \
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






Button.o : Button.cpp Button.h    ButtonPkg.h Led.h 
	@echo Compiling Button.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o Button.o Button.cpp




Led.o : Led.cpp Led.h    ButtonPkg.h 
	@echo Compiling Led.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o Led.o Led.cpp




PushSwitch.o : PushSwitch.cpp PushSwitch.h    ButtonPkg.h Button.h 
	@echo Compiling PushSwitch.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o PushSwitch.o PushSwitch.cpp




ButtonPkg.o : ButtonPkg.cpp ButtonPkg.h    Button.h Led.h PushSwitch.h 
	@echo Compiling ButtonPkg.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o ButtonPkg.o ButtonPkg.cpp




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
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) ButtonTest.mak 
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	@$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(INST_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) -o $(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) ButtonTest.mak
	@echo Building library $@
	@$(LIB_CMD) $(LIB_FLAGS) $(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS) $(LIBS)



clean:
	@echo Cleanup
	$(RM) Button.o
	$(RM) Led.o
	$(RM) PushSwitch.o
	$(RM) ButtonPkg.o
	$(RM) Interface.o
	$(RM) $(TARGET_MAIN)$(OBJ_EXT) $(ADDITIONAL_OBJS)
	$(RM) $(TARGET_NAME)$(LIB_EXT)
	$(RM) $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
