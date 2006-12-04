# Makefile for lithp2
#
#	Scott Lawrence
#	yorgle@gmail.com
#	http://www.umlautllama.com
#
#   Use this for whatever you like.  No copyrights held.
#   If it's useful for you, run with it.  :]
#
#   This entire project is covered under a LGPL license;
#   please read the "README.TXT" and "LICENSE.TXT" files.
#
############################################################

NAME     := lithp2
REVISION := 1

TARGET := $(NAME)

SRCS := frontend.c \
	internals.c \
	lithp.c

OBJS := $(SRCS:%.c=%.o)

LIBS := 

CFLAGS  := -DREVISION=\"$(REVISION)\" -Wall -pedantic

############################################################

all: prog 

prog:	$(TARGET) $(DATA)

clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: clean
############################################################

$(TARGET):	$(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)


############################################################

test:	prog
	./$(TARGET)

.PHONY: test
############################################################

BAK_NAME := $(NAME)_$(VERSION)

backup: clean
	touch ../$(BAK_NAME).tar.gz
	mv ../$(BAK_NAME).tar.gz ../$(BAK_NAME)_old.tar.gz
	cd .. ; tar -cvf $(BAK_NAME).tar $(NAME)/* ; gzip $(BAK_NAME).tar

.PHONY: backup
############################################################

.SECONDARY: $(OBJS)

############################################################
