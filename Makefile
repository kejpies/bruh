CC ?= cc
CFLAGS +=
LDFLAGS +=

TARGET = bruh
SRC = bruh.c
OBJ = $(SRC:.c=.o)

DESTDIR ?=
PREFIX ?= /usr/local
BINDIR ?= ${DESTDIR}/${PREFIX}/bin
LIBDIR ?= ${DESTDIR}/${PREFIX}/share
DATADIR ?= ${LIBDIR}/bruh/
MANDIR ?= ${LIBDIR}/man/

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	install -D $(TARGET) -t ${BINDIR}
	install -Dm 644 $(TARGET).wav -t ${DATADIR}
	install -Dm 644 $(TARGET).1 -t ${MANDIR}/man1
	@echo bruh

uninstall:
	$(RM) ${BINDIR}/${TARGET}
	$(RM) ${DATADIR}/${TARGET}.wav
	$(RM) ${MANDIR}/man1/${TARGET}.1
	@echo bruh

clean:
	$(RM) *.o $(TARGET)
	@echo All clean
