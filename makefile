# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

#final: Song.o UtPod.o UtPodDriver.o  
#	g++ -otest  Song.o UtPod.o  UtPodDriver.o
#Song.o: Song.cpp Song.h
#	g++ Song.cpp 
#UtPod.o: UtPod.cpp UtPod.h Song.h
#	g++ UtPod.cpp
#UtPodDriver.o: UtPodDriver.cpp UtPod.h Song.h
#	g++ UtPodDriver.cpp


final: UtPodDriver.o UtPod.o song.o
	g++ -otest  UtPodDriver.o UtPod.o song.o
driver: UtPodDriver.cpp UtPod.h song.h
	g++ -c UtPod_Driver.cpp
UtPod.o: UtPod.cpp UtPod.h song.h
	g++ -c UtPod.cpp
song.o: song.cpp song.h
	g++ -c song.cpp