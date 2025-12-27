# Chip-8 Emulator

Small emulator written in C++20 using SFML 3. Created as a learning project, focused on gaining practical
experience with modern C++ and emulator programming.

## Technology Stack

* Language: C++20
* Build System: CMake 3.16
* Graphics & Input: SFML 3.0.2 (bundled as a submodule in vendor/)

## Usage

### Build

```
git clone https://github.com/liitlelenim/Chip-8Emulator
cd CHIP-8Emulator

mkdir build
cd build

cmake ..
cmake --build .
```

### Run

After building the project, run the emulator by providing a
path to a CHIP-8 ROM file:

#### Linux

```
./CHIP-8Emulator path/to/rom.ch8
```

#### Windows

```
.\CHIP-8Emulator.exe path\to\rom.ch8
```

### Usage notes

* The ROM file path is required as a command-line argument.
* Supported ROMs must be compatible with the CHIP-8 specification.
* The emulator window will open automatically after loading the ROM.

### References

#### Documentation

The emulator was primarily implemented based the following documentation:
[Cowgod's Chip-8 Technical Reference v1.0](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)

#### Roms

The emulator was tested using ROMs from the  
[chip8-roms](https://github.com/kripod/chip8-roms/tree/master) GitHub repository.

It’s a great place to find ROMs if you want to test the emulator on your own.
