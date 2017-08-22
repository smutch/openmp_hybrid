all: build/Makefile
	@make -C build --no-print-directory

build/Makefile: CMakeLists.txt
	@mkdir -p build
	@cd build && cmake .. $(CMAKE_OPTS)

clean:
	@rm -r build

CMakeLists.txt: ;

% :: build/Makefile
	@make -C build --no-print-directory $@ $(MFLAGS)
