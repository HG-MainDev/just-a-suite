CC = gcc
OBJ = main.o
BIN= bin
OUT= out

just-a-suite: out/$(OBJ) $(BIN)
	$(CC) -o $(BIN)/just-a-suite $(OUT)/$(OBJ)

out/main.o: source/main.c $(OUT)
	$(CC) -c source/main.c -o $(OUT)/main.o
clean:
	rm -rf bin/
	rm -rf out/
dev: out/dev-$(OBJ) $(BIN)
	$(CC) -o $(BIN)/dev-just-a-suite $(OUT)/dev-$(OBJ)
out/dev-main.o: source/dev-main.c $(OUT)
	$(CC) -c source/dev-main.c -o $(OUT)/dev-main.o
all:
	make just-a-suite
	make dev
$(BIN):
	if [ ! -d "./$(BIN)" ];then     \
		mkdir $(BIN);           \
	fi
$(OUT):
	if [ ! -d "./$(OUT)" ];then     \
		mkdir $(OUT);           \
	fi