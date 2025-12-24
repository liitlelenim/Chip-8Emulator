#include <iostream>
#include <filesystem>

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Proper usage:\n" << argv[0] << " [rom-path]";
        return EXIT_FAILURE;
    }

    std::filesystem::path romPath = argv[1];
    if (!std::filesystem::exists(romPath)) {
        std::cerr << "File not found: " << romPath;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
