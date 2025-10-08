#ifndef BMP_HPP
#define BMP_HPP

#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdint>
#include <cstring>

#pragma pack(push, 1)
struct BMPHeader {
    uint16_t file_type{0x4D42}; // 'BM' in little endian
    uint32_t file_size{0};      // File size in bytes
    uint16_t reserved1{0};      // Reserved field
    uint16_t reserved2{0};      // Reserved field
    uint32_t data_offset{54};   // Offset where image data begins

    uint32_t header_size{40};   // Size of the DIB header (40 bytes)
    int32_t width{0};           // Image width
    int32_t height{0};          // Image height
    uint16_t color_planes{1};   // Number of color planes
    uint16_t bits_per_pixel{24}; // Bits per pixel (24 for RGB)
    uint32_t compression{0};    // Compression method (0 = none)
    uint32_t image_size{0};     // Image size (can be 0 for uncompressed)
    int32_t x_pixels_per_meter{2835};
    int32_t y_pixels_per_meter{2835};
    uint32_t colors_used{0};
    uint32_t colors_important{0};
};
#pragma pack(pop)
class BMP {
public:
    BMP(int width, int height) : width(width), height(height) {
        row_size = width * 3;  // 3 bytes per pixel
        padded_row_size = (row_size + 3) & ~3; // Align to 4-byte boundary
        data.resize(padded_row_size * height, 255); // Initialize with white
    }

    BMP(const std::string& file_name) {
        read(file_name);
    }

    void set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            int index = ((height - 1 - y) * padded_row_size) + (x * 3);
            data[index] = b;
            data[index + 1] = g;
            data[index + 2] = r;
        }
    }

    void get_pixel(int x, int y, uint8_t& r, uint8_t& g, uint8_t& b) const {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            int index = ((height - 1 - y) * padded_row_size) + (x * 3);
            b = data[index];
            g = data[index + 1];
            r = data[index + 2];
        }
    }

    void write(const std::string& file_name) const {
        std::ofstream out(file_name, std::ios::binary);
        if (!out) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        BMPHeader bmp_header;
       

        bmp_header.file_size = sizeof(BMPHeader)  + data.size();
        

        bmp_header.width = width;
        bmp_header.height = height;
        bmp_header.image_size = data.size();

        out.write(reinterpret_cast<const char*>(&bmp_header), sizeof(bmp_header));
       
        out.write(reinterpret_cast<const char*>(data.data()), data.size());
    }

    void read(const std::string& file_name) {
        std::ifstream in(file_name, std::ios::binary);
        if (!in) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        BMPHeader bmp_header;
        

        in.read(reinterpret_cast<char*>(&bmp_header), sizeof(bmp_header));
        //in.read(reinterpret_cast<char*>(&dib_header), sizeof(dib_header));

        if (bmp_header.file_type != 0x4D42) {
            throw std::runtime_error("Not a valid BMP file.");
        }

        if (bmp_header.bits_per_pixel != 24) {
            throw std::runtime_error("Only 24-bit BMP files are supported.");
        }

        width = bmp_header.width;
        height = bmp_header.height;

        row_size = width * 3;
        padded_row_size = (row_size + 3) & ~3;

        data.resize(padded_row_size * height);

        in.seekg(bmp_header.data_offset, std::ios::beg);
        in.read(reinterpret_cast<char*>(data.data()), data.size());
    }

    int get_width() const {
        return width;
    }

    int get_height() const {
        return height;
    }

private:
    int width{0};
    int height{0};
    int row_size{0};
    int padded_row_size{0};
    std::vector<uint8_t> data;
};

struct color{
int r;
int g;
int b;
color(int r_, int g_, int b_):r{r_},g{g_},b{b_}{}
color():r{0},g{0},b{0}{}
};

#endif // BMP_HPP
