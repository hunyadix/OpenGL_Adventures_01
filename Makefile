SrcSuf   = cxx
ObjSuf   = o
ExeSuf   = 
OutPutOpt = -o # +whitespace

CXX      = c++
CXXFLAGS = -std=c++17 -Wall -Wshadow
LD       = c++
LDFLAGS  = 

SDL_INCLUDE = -I/usr/local/include
SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image -Wl,-rpath=/usr/local/lib
GLEW_LIB = 

LIBS     = -lGL -lGLU -lglut $(SDL_LIB) -lGLEW -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

SHOOTER_S = ./src/programs/shooter_start.$(SrcSuf)
SHOOTER_O = ./obj/shooter_start.$(ObjSuf)
SHOOTER_A = ./bin/shooter_start$(ExeSuf)
OBJS     += $(SHOOTER_O)
PROGRAMS += $(SHOOTER_A)

# OBJS

SHOOTER_GAME_S = ./src/Shooter_game.$(SrcSuf)
SHOOTER_GAME_O = ./obj/Shooter_game.$(ObjSuf)
OBJS     += $(SHOOTER_O)

TEXTURE_LOADER_S = ./src/Texture_loader.$(SrcSuf)
TEXTURE_LOADER_O = ./obj/Texture_loader.$(ObjSuf)
OBJS     += $(TEXTURE_LOADER_O)

DRAWABLE_SPRITE_S = ./src/Drawable_sprite.$(SrcSuf)
DRAWABLE_SPRITE_O = ./obj/Drawable_sprite.$(ObjSuf)
OBJS     += $(DRAWABLE_SPRITE_O)

PLAYER_S = ./src/Player.$(SrcSuf)
PLAYER_O = ./obj/Player.$(ObjSuf)
OBJS     += $(PLAYER_O)

all: $(PROGRAMS)

# Executables

$(SHOOTER_A): $(SHOOTER_O) $(SHOOTER_GAME_O) $(TEXTURE_LOADER_O) $(DRAWABLE_SPRITE_O) $(PLAYER_O)
	@printf "Compiling done, linking \""$@"\"...\n"
	@$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	$(MT_EXE)
	@echo "Succesful make..."
	@echo "...$@ is ready to use."

# Program obj files

$(SHOOTER_O): $(SHOOTER_S)
	@printf "Compiling program: \""$<"\"...\n"
	@$(CXX) $(CXXFLAGS) $(LIBS) -c $< $(OutPutOpt)$@
	@printf "Done.\n"

$(TEXTURE_LOADER_O): $(TEXTURE_LOADER_S)
	@printf "Compiling program: \""$<"\"...\n"
	@$(CXX) $(CXXFLAGS) $(LIBS) -c $< $(OutPutOpt)$@
	@printf "Done.\n"

$(DRAWABLE_SPRITE_O): $(DRAWABLE_SPRITE_S)
	@printf "Compiling program: \""$<"\"...\n"
	@$(CXX) $(CXXFLAGS) $(LIBS) -c $< $(OutPutOpt)$@
	@printf "Done.\n"

$(PLAYER_O): $(PLAYER_S)
	@printf "Compiling program: \""$<"\"...\n"
	@$(CXX) $(CXXFLAGS) $(LIBS) -c $< $(OutPutOpt)$@
	@printf "Done.\n"

# Object obj files

$(SHOOTER_GAME_O): $(SHOOTER_GAME_S)
	@printf "Compiling program: \""$<"\"...\n"
	@$(CXX) $(CXXFLAGS) $(LIBS) -c $< $(OutPutOpt)$@
	@printf "Done.\n"

print_compiler_info:
	@printf "Compiler: $(CXX)\n"
	@printf "Compiler flags: $(CXXFLAGS)\n"
	@printf "Linked libs: $(LIBS)\n"
	@printf "Linker: $(LD)\n"
	@printf "Linker flags: $(LDFLAGS)\n"

clean:
	@rm -f $(OBJS) $(PROGRAMS) core

distclean: clean
	@rm -f $(PROGRAMS) *Dict.* *.def *.exp \
	*.root *.ps *.so *.lib *.dll *.d *.log .def so_locations
	@rm -rf cxx_repository

.SUFFIXES: .$(SrcSuf)