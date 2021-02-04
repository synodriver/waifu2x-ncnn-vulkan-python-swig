#ifndef WAIFU2X_NCNN_VULKAN_WAIFU2X_WRAPPED_H
#define WAIFU2X_NCNN_VULKAN_WAIFU2X_WRAPPED_H
#include "waifu2x.h"

//Todo: implement faster C-array to Python bytes methods like buffer interface from https://stackoverflow.com/questions/5424324/fast-conversion-of-c-c-vector-to-numpy-array

typedef struct Image{
    unsigned char *data;
    int w;
    int h;
    int elempack;
    Image(unsigned char *d, int w, int h, int channels) {
        this->data = d;
        this->w = w;
        this->h = h;
        this->elempack = channels;
    }

//    Image(unsigned int* d, int w, int h, int channels) {
//        this->data = (unsigned char*) d;
//        this->w = w;
//        this->h = h;
//        this->elempack = channels;
//    }
} Image;

class Waifu2xWrapped : public Waifu2x {
public:
    Waifu2xWrapped(int gpuid, bool tta_mode = false, int num_threads = 1);
    int process(const Image& inimage, Image& outimage) const;
    int process_cpu(const Image& inimage, Image& outimage) const;
    uint32_t get_heap_budget();
};
#endif //WAIFU2X_NCNN_VULKAN_WAIFU2X_WRAPPED_H