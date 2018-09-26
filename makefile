CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =	Ant.o Board.o Doodlebug.o Organism.o PA4_zrfitzgibbon.o

LIBS =

TARGET =	PA4_zrfitzgibbon

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

# Give command "make docs" to create documentation.	
docs:
	doxygen
