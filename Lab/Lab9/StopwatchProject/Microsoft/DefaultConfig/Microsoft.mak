
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug= /Zi /Od /D "_DEBUG" /MDd  /Fd"$(TARGET_NAME)" 
CPPCompileRelease= /Ox /D"NDEBUG" /MD /Fd"$(TARGET_NAME)" 
LinkDebug=
LinkRelease=
BuildSet=Debug

ConfigurationCPPCompileSwitches=  /I . /I . /I $(OMROOT)\LangC  /I $(OMROOT)\LangC\oxf /nologo /W3 $(ENABLE_EH) $(CRT_FLAGS) $(CPPCompileDebug) /D "_AFXDLL" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_WINDOWS" $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) /c 

################### Compilation flags ######################
############################################################
INCLUDE_QUALIFIER=/I
LIB_PREFIX=Ms

CRT_FLAGS=
ENABLE_EH=/GX

WINMM_LIB=winmm.lib

################### Distributed Events Marcos & Flags #######
#############################################################
DISTRIBUTION=False
DISTRIBUTION_PREFIX=
DOX_LIBS=
DOX_FLAGS=

################### Commands definition #########################
#################################################################
RMDIR = rmdir
LIB_CMD=link.exe -lib
LINK_CMD=link.exe
LIB_FLAGS=$(LinkDebug) /NOLOGO   
LINK_FLAGS=$(LinkDebug) /NOLOGO    /SUBSYSTEM:console /MACHINE:I386 

############### Generated macros #################
##################################################

FLAGSFILE=
RULESFILE=
OMROOT="C:\Users\HaYeon\IBM\Rational\Rhapsody\7.5.3\Share"

CPP_EXT=.c
H_EXT=.h
OBJ_EXT=.obj
EXE_EXT=.exe
LIB_EXT=.lib

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=Microsoft

all : $(TARGET_NAME)$(EXE_EXT) Microsoft.mak

TARGET_MAIN=MainMicrosoft

LIBS=

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangC/osconfig/WIN32

ADDITIONAL_OBJS=

OBJS= \
  Button.obj \
  Timer.obj \
  Display.obj \
  StopwatchPkg.obj




OBJ_DIR=

!IF "$(OBJ_DIR)"!=""
CREATE_OBJ_DIR=if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
CLEAN_OBJ_DIR= if exist $(OBJ_DIR) $(RMDIR) $(OBJ_DIR)
!ELSE
CREATE_OBJ_DIR=
CLEAN_OBJ_DIR=
!ENDIF

######################## Predefined macros ############################
#######################################################################
$(OBJS) : $(FLAGSFILE) $(RULESFILE) $(INST_LIBS) $(OXF_LIBS)

LIB_POSTFIX=
!IF "$(BuildSet)"=="Release"
LIB_POSTFIX=R
!ENDIF

!IF "$(DISTRIBUTION)" == "True"
DISTRIBUTION_PREFIX=distrib_
DOX_LIBS=$(OMROOT)\LangC\lib\$(LIB_PREFIX)dox$(LIB_POSTFIX)$(LIB_EXT) kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib 
DOX_FLAGS=/D "RIC_DISTRIBUTED_SYSTEM"
!ELSE
DISTRIBUTION_PREFIX=
DOX_LIBS=
!ENDIF

!IF "$(TARGET_TYPE)" == "Executable"
LinkDebug=$(LinkDebug) /DEBUG
LinkRelease=$(LinkRelease) /OPT:NOREF
!ELSEIF "$(TARGET_TYPE)" == "Library"
LinkDebug=$(LinkDebug) /DEBUGTYPE:CV
!ENDIF

!IF "$(INSTRUMENTATION)" == "Animation"
INST_FLAGS=/D "OMANIMATOR"
INST_INCLUDES=/I $(OMROOT)\LangC\aom
INST_LIBS= $(OMROOT)\LangC\lib\$(LIB_PREFIX)$(DISTRIBUTION_PREFIX)aomanim$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS=$(OMROOT)\LangC\lib\$(LIB_PREFIX)$(DISTRIBUTION_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangC\lib\$(LIB_PREFIX)omcomappl$(LIB_POSTFIX)$(LIB_EXT)
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "Tracing"
INST_FLAGS=/D "OMTRACER"
INST_INCLUDES=/I $(OMROOT)\LangC\aom /I $(OMROOT)\LangCpp\tom
INST_LIBS= $(OMROOT)\LangC\lib\$(LIB_PREFIX)$(DISTRIBUTION_PREFIX)aomtrace$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS= $(OMROOT)\LangC\lib\$(LIB_PREFIX)$(DISTRIBUTION_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangC\lib\$(LIB_PREFIX)omcomappl$(LIB_POSTFIX)$(LIB_EXT)
## C++ Libraries to support link to C++ TOM ##
INST_LIBS= $(INST_LIBS) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)tomtraceRiC$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS= $(OXF_LIBS) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxf$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)omcomappl$(LIB_POSTFIX)$(LIB_EXT)
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "None" 
INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
OXF_LIBS=$(OMROOT)\LangC\lib\$(LIB_PREFIX)$(DISTRIBUTION_PREFIX)oxf$(LIB_POSTFIX)$(LIB_EXT)
SOCK_LIB=

!ELSE
!ERROR An invalid Instrumentation $(INSTRUMENTATION) is specified.
!ENDIF

ConfigurationCPPCompileSwitches=$(ConfigurationCPPCompileSwitches) $(DOX_FLAGS)

################## Generated dependencies ########################
##################################################################






Button.obj : Button.c Button.h    StopwatchPkg.h Timer.h 
	$(CREATE_OBJ_DIR)
	$(CC) $(ConfigurationCPPCompileSwitches)  /Fo"Button.obj" "Button.c" 



Timer.obj : Timer.c Timer.h    StopwatchPkg.h Display.h 
	$(CREATE_OBJ_DIR)
	$(CC) $(ConfigurationCPPCompileSwitches)  /Fo"Timer.obj" "Timer.c" 



Display.obj : Display.c Display.h    StopwatchPkg.h 
	$(CREATE_OBJ_DIR)
	$(CC) $(ConfigurationCPPCompileSwitches)  /Fo"Display.obj" "Display.c" 



StopwatchPkg.obj : StopwatchPkg.c StopwatchPkg.h    Button.h Timer.h Display.h 
	$(CREATE_OBJ_DIR)
	$(CC) $(ConfigurationCPPCompileSwitches)  /Fo"StopwatchPkg.obj" "StopwatchPkg.c" 






$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) $(FLAGSFILE) $(RULESFILE)
	$(CC) $(ConfigurationCPPCompileSwitches) /Fo"$(TARGET_MAIN)$(OBJ_EXT)" $(TARGET_MAIN)$(CPP_EXT)

########################## Linking instructions ###############################
###############################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) Microsoft.mak 
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(DOX_LIBS) \
	$(SOCK_LIB) \
	$(WINMM_LIB) \
	$(LINK_FLAGS) /out:$(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) Microsoft.mak
	@echo Building library $@
	$(LIB_CMD) $(LIB_FLAGS) /out:$(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS) $(LIBS)

clean:
	@echo Cleanup
	if exist Button.obj erase Button.obj
	if exist Timer.obj erase Timer.obj
	if exist Display.obj erase Display.obj
	if exist StopwatchPkg.obj erase StopwatchPkg.obj
	if exist $(TARGET_MAIN)$(OBJ_EXT) erase $(TARGET_MAIN)$(OBJ_EXT)
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
