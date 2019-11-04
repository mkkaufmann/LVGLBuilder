#
# Makefile
#
CC = g++
LVGL_DIR ?= ${shell pwd}
CFLAGS ?= -Wall -Wshadow -Wundef -Wmaybe-uninitialized -O3 -g0 -I$(LVGL_DIR)/
LDFLAGS ?= -lSDL2 -lm lvgl.a
BIN = demo


#Collect the files to compile
MAINSRC = ./main.c

#include $(LVGL_DIR)/lvgl/lvgl.mk
#include $(LVGL_DIR)/lv_drivers/lv_drivers.mk
#include $(LVGL_DIR)/lv_examples/lv_examples.mk

#CSRCS +=$(LVGL_DIR)/mouse_cursor_icon.c
WRAPPERSRCS = ./wrapper/src/object.cpp

OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))
WRAPPEROBJS = $(WRAPPERSRCS:.cpp=$(OBJEXT))

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(MAINSRC) $(WRAPPERSRCS)
OBJS = $(AOBJS) $(COBJS) $(WRAPPEROBJS)

## MAINOBJ -> OBJFILES

all: default

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"
    
default: $(AOBJS) $(COBJS) $(MAINOBJ) $(WRAPPEROBJS)
	$(CC) -o $(BIN) $(MAINOBJ) $(AOBJS) $(COBJS) $(WRAPPEROBJS) $(LDFLAGS)

clean: 
	rm -f $(BIN) $(AOBJS) $(COBJS) $(WRAPPEROBJS) $(MAINOBJ)

