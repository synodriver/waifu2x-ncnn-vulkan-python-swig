# waifu2x ncnn Vulkan Python

Python wrapper of the ncnn implementation of waifu2x converter. Runs fast on Intel / AMD / Nvidia with Vulkan API.

waifu2x-ncnn-vulkan-python wraps [waifu2x-ncnn-vulkan project](https://github.com/nihui/waifu2x-ncnn-vulkan) by SWIG to make it easier to integrate waifu2x-ncnn-vulkan with your existing python projects.

This project only wrapped the original Waifu2x class. As a result, functions other than the core upscaling and denoising such as multi-thread loading and saving are not available. Of course, the auto tilesize and prepadding settings are implements, so don't worry about them.

## Download

Not yet available as release. However you can build it yourself.


## Build
```shell
git clone https://github.com/ArchieMeng/waifu2x-ncnn-vulkan-python.git
cd waifu2x-ncnn-vulkan-python
git submodule update --init --recursive
cd src
cmake -B build .
cd build
make
```

## Usages

### Example program

```python
from PIL import Image
from waifu2x_ncnn_vulkan import Waifu2x

im = Image.open("0.jpg")
w2x_obj = Waifu2x(gpuid=0)
out_im = w2x_obj.process(im)
out_im.save("1.png")
```

## Known issues
- The current performance of python binded Waifu2x implementation is about 20% slower than the original binary excutable.
It is caused by inefficient pixel data copying between C and python. Will be improved in the future.

## Original waifu2x Project

- https://github.com/nagadomi/waifu2x
- https://github.com/lltcggie/waifu2x-caffe
- https://github.com/nihui/waifu2x-ncnn-vulkan

## Other Open-Source Code Used

- https://github.com/Tencent/ncnn for fast neural network inference on ALL PLATFORMS
- https://github.com/webmproject/libwebp for encoding and decoding Webp images on ALL PLATFORMS
- https://github.com/nothings/stb for decoding and encoding image on Linux / MacOS
- https://github.com/tronkko/dirent for listing files in directory on Windows
