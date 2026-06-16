# マクロ（定数）の定義
CC = gcc
CFLAGS = -Wall #-g
.PHONY: all clean	# ダミーターゲットを明示的に指定

# makeの引数なしで生成するものの一覧
all: printAddr1 pointerAccess funcParam1 funcParam2 # printAddr2 printAddr3 printAddr4 pointerScanf shoppingPtr # constFunc


# コンパイルによってできるものを削除する
clean:
	rm -f *.o printAddr1 pointerAccess funcParam1 funcParam2 printAddr2 printAddr3 printAddr4 pointerScanf shoppingPtr
	rm -rf *.dSYM
