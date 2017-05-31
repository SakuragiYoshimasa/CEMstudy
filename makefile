COMPILER  = g++
CFLAGS    = -Wall -std=c++11 -O2
ifeq "$(shell getconf LONG_BIT)" "64"
  LDFLAGS =
else
  LDFLAGS =
endif
LIBS      =
INCLUDE   = -I./include
TARGET    = ./bin/main.out
SRCDIR    = ./source
ifeq "$(strip $(SRCDIR))" ""
  SRCDIR  = .
endif
SOURCES   = $(wildcard $(SRCDIR)/*.cpp)
OBJDIR    = ./obj
ifeq "$(strip $(OBJDIR))" ""
  OBJDIR  = .
endif
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPENDS   = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<


EasyEnv_test: $(OBJDIR)/EasyEnv_test.o $(OBJDIR)/EasyEnv.o
	$(COMPILER) $(CFLAGS) -o ./bin/EasyEnv_test $(OBJDIR)/EasyEnv_test.o $(OBJDIR)/EasyEnv.o

$(OBJDIR)/EasyEnv_test.o: ./tests/EasyEnv_test.cpp $(OBJECTS)
	$(COMPILER) $(CFLAGS) -c ./tests/EasyEnv_test.cpp -o $(OBJDIR)/EasyEnv_test.o

all: clean $(TARGET)

clean:
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGET)

-include $(DEPENDS)
