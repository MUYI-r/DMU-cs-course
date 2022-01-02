###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = 80C51
COMPILER = "ASEM-51 (Proteus)"
TARGET = Debug
SHELL = C:\Windows\system32\cmd.exe

## Tools general options

## Processing Tools
ASM=asem.exe
DDX=ASEMDDX.EXE
#  C:/Users/MrLeea/Desktop/新建文件夹/80C51/Debug/Debug.HEX: TOOL=ASM
#  Post: $(DDX) $(DDXFLAGS) Debug.lst
#     C:/Users/MrLeea/Desktop/新建文件夹/80C51/JMP1_2.asm

# Build tree:
all:	Debug

Debug:	Debug.HEX

Debug.HEX:	../JMP1_2.asm 
	$(ASM) "..\JMP1_2.asm" "Debug.HEX" Debug.lst $(ASMFLAGS)  /INCLUDES:"..\..\..\..\..\..\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\Tools\ASEM51"
	$(DDX) $(DDXFLAGS) Debug.lst

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Debug.lst

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.HEX
	rm -rf Debug.SDI
