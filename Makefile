CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = scalculator
OBJECTS = scalculator.o istring.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
