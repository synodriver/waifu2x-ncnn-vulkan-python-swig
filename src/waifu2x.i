%module waifu2x_ncnn_vulkan_wrapper

%include "carrays.i"
%include "std_string.i"
%include "stdint.i"

%array_class(unsigned char, PixelBuffer);

%{
    #include "waifu2x.h"
    #include "waifu2x_wrapped.h"
%}

%include "waifu2x.h"
%include "waifu2x_wrapped.h"