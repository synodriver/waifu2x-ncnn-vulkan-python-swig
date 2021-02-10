%module waifu2x_ncnn_vulkan_wrapper

%include "carrays.i"
%include "std_string.i"
%include "stdint.i"
%include "pybuffer.i"

%pybuffer_mutable_string(unsigned char *d);

%{
    #include "waifu2x.h"
    #include "waifu2x_wrapped.h"
%}

%include "waifu2x.h"
%include "waifu2x_wrapped.h"