APP=obliczanie_wskazu

__start__: ${APP}
	./${APP}

${APP}: obj/main.o obj/LZespolona.o obj/WyrazenieZesp.o obj/Wskaz.o
	g++ -o ./${APP} obj/main.o obj/LZespolona.o  obj/WyrazenieZesp.o obj/Wskaz.o

obj:
	mkdir obj


obj/main.o: src/main.cpp inc/LZespolona.hh inc/WyrazenieZesp.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/LZespolona.o src/LZespolona.cpp

obj/WyrazenieZesp.o: src/WyrazenieZesp.cpp inc/WyrazenieZesp.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/WyrazenieZesp.o src/WyrazenieZesp.cpp
obj/Wskaz.o: src/Wskaz.cpp inc/Wskaz.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/Wskaz.o src/Wskaz.cpp


clean:
	rm -f ./${APP} obj/* 



help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
