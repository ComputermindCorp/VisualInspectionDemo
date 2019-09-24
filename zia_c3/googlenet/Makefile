include env.mk

#INC = -I../../dv-user-driver/include -I../common/include `freetype-config --cflags`
INC = -I./include -I/usr/include/agg2 `freetype-config --cflags`
LIB = -L./lib -ldmpdv -ldv700_util -lagg -lfreetype 

CFLAGS = -pthread -std=c++11 $(OPT) -Wall -Werror -c  $(INC)
LFLAGS = -pthread -std=c++11 $(OPT) -fopenmp

DEPS = InspectionDemoGoogLeNet_gen.h
OBJS = InspectionDemoGoogLeNet_gen.o main.o
TGT  = ./bin/visuaInspectionDemo

%.o: %.cpp $(DEPS)
	$(GPP) $(CFLAGS) -o $@ $<

all : $(OBJS)
	$(GPP) $(LFLAGS) $(OBJS) -o $(TGT) $(LIB)

clean:
	rm -f *.o $(TGT)


