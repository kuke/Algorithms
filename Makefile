all: ChineseGeneral LCS GetOneFileFromSubDir

ChineseGeneral: ChineseGeneral.cpp 
	g++ ChineseGeneral.cpp -o ChineseGeneral.bin 

LCS: LCS.cpp
	g++ LCS.cpp -o LCS.bin

GetOneFileFromSubDir: GetOneFileFromSubDir.cpp
	g++ GetOneFileFromSubDir.cpp -o GetOneFileFromSubDir

clean: 
	rm *.bin


