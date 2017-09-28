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
$(BIN):
	if [ ! -d "./$(BIN)" ];then     \
		mkdir $(BIN);           \
	fi
$(OUT):
	if [ ! -d "./$(OUT)" ];then     \
		mkdir $(OUT);           \
	fi