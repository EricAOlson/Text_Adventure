#############EXECUTABLE#############
go: final.o car.o pass.o security.o dining.o caboose.o friend.o bag.o support.o
	g++ final.o car.o pass.o security.o dining.o caboose.o friend.o bag.o support.o -o go


############OBJECT FILES############
final.o: final.cpp
	g++ final.cpp -c

car.o: car.cpp
	g++ car.cpp -c

pass.o: pass.cpp
	g++ pass.cpp -c

security.o: security.cpp
	g++ security.cpp -c

dining.o: dining.cpp
	g++ dining.cpp -c

caboose.o: caboose.cpp
	g++ caboose.cpp -c
	
friend.o: friend.cpp
	g++ friend.cpp -c

bag.o: bag.cpp
	g++ bag.cpp -c

support.o: support.cpp
	g++ support.cpp -c
