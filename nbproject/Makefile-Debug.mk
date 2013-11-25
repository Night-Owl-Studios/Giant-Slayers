#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_tdm-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/abilityCard.o \
	${OBJECTDIR}/aresaDeck.o \
	${OBJECTDIR}/attackCard.o \
	${OBJECTDIR}/boundingBox.o \
	${OBJECTDIR}/card.o \
	${OBJECTDIR}/deck.o \
	${OBJECTDIR}/display.o \
	${OBJECTDIR}/gameState.o \
	${OBJECTDIR}/giant.o \
	${OBJECTDIR}/hand.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/minralDeck.o \
	${OBJECTDIR}/player.o \
	${OBJECTDIR}/singlePlayer.o \
	${OBJECTDIR}/system.o \
	${OBJECTDIR}/testState.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m32 -O2 -W -Wall -Wextra -Werror -pedantic
CXXFLAGS=-m32 -O2 -W -Wall -Wextra -Werror -pedantic

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lSDL2 -lSDL2_image ../hamlibs/HamLibs_NetBeans/../bin/WIN32/libhamlibs-debug.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk bin/GSlayers_d.exe

bin/GSlayers_d.exe: ../hamlibs/HamLibs_NetBeans/../bin/WIN32/libhamlibs-debug.a

bin/GSlayers_d.exe: ${OBJECTFILES}
	${MKDIR} -p bin
	${LINK.cc} -o bin/GSlayers_d ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/abilityCard.o: abilityCard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/abilityCard.o abilityCard.cpp

${OBJECTDIR}/aresaDeck.o: aresaDeck.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/aresaDeck.o aresaDeck.cpp

${OBJECTDIR}/attackCard.o: attackCard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/attackCard.o attackCard.cpp

${OBJECTDIR}/boundingBox.o: boundingBox.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/boundingBox.o boundingBox.cpp

${OBJECTDIR}/card.o: card.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/card.o card.cpp

${OBJECTDIR}/deck.o: deck.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/deck.o deck.cpp

${OBJECTDIR}/display.o: display.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/display.o display.cpp

${OBJECTDIR}/gameState.o: gameState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/gameState.o gameState.cpp

${OBJECTDIR}/giant.o: giant.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/giant.o giant.cpp

${OBJECTDIR}/hand.o: hand.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/hand.o hand.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/minralDeck.o: minralDeck.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/minralDeck.o minralDeck.cpp

${OBJECTDIR}/player.o: player.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/player.o player.cpp

${OBJECTDIR}/singlePlayer.o: singlePlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/singlePlayer.o singlePlayer.cpp

${OBJECTDIR}/system.o: system.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/system.o system.cpp

${OBJECTDIR}/testState.o: testState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -DSDL_MAIN_HANDLED -D_DEBUG -I../hamlibs/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/testState.o testState.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} bin/GSlayers_d.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
