#include <iostream>
#include <fstream>
int main() {
    uint8_t byte, c = 0, header[8] = { 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a };
    std::ifstream capa("imagem.png", std::ios::binary);
    if (capa.is_open()) {
        for (uint8_t i = 0; i < 8; i++) {
            capa.read((char*)&byte, sizeof(uint8_t));
            byte == header[i] ? c++ : 0;
        }
        std::cout << (c == 8 ? "A capa e um PNG valido. Pode postar!" : "A capa nao e um PNG");
    } else { std::cout << "Cade o arquivo?"; }
}
