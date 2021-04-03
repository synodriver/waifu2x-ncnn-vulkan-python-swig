# waifu2x ncnn Vulkan Python

## Introduction

[waifu2x-ncnn-vulkan](https://github.com/nihui/waifu2x-ncnn-vulkan) is nihui's ncnn implementation of waifu2x converter. Runs fast on Intel / AMD / Nvidia with Vulkan API.

This project is a Python wrapper of nihui's project.

waifu2x-ncnn-vulkan-python wraps [waifu2x-ncnn-vulkan project](https://github.com/nihui/waifu2x-ncnn-vulkan) by SWIG to make it easier to integrate waifu2x-ncnn-vulkan with existing python projects.

This project only wrapped the original Waifu2x class. As a result, functions other than the core upscaling and denoising such as multi-thread loading and saving are not available. Of course, the auto tilesize and prepadding settings are implements, so don't worry about them.

## Download

linux x64 and Windows x64 releases are available now. The build on Mac OS hasn't been tested yet. For other platforms, you may compile it on
your own.


## Build

First, you have to install python, python development package (Python native development libs in Visual Studio), vulkan SDK and SWIG on your platform. And then:

### Linux
```shell
git clone https://github.com/ArchieMeng/waifu2x-ncnn-vulkan-python.git
cd waifu2x-ncnn-vulkan-python
git submodule update --init --recursive
cd src
cmake -B build .
cd build
make
```

### Windows
I used Visual Studio 2019 and msvc v142 to build this project for Windows.

Install visual studio and open the project directory, and build. Job done.

The only problem on Windows is that, you cannot use [CMake for Windows](https://cmake.org/download/) to generate the Visual Studio solution file and build it. This will make the lib crash on loading.

The only way is [use Visual Studio to open the project as directory](https://www.microfocus.com/documentation/visual-cobol/vc50/VS2019/GUID-BE1C48AA-DB22-4F38-9644-E9B48658EF36.html), and build it from Visual Studio.

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

## Docs

### Methods
class **Waifu2x**(gpuid=0,
model="models-cunet",
tta_mode=False,
num_threads=1,
scale=2,
noise=0,
tilesize=0)

> waifu2x-ncnn-vulkan class which can do image super resolution.
> 
> ### **Parameters**
>
> **gpuid**: int
> >the id of the gpu device to use. -1 for cpu mode.
>
> **model**: str
> > the name or the path to the model
>
> **tta_mode**: bool
> > whether to enable tta mode or not
> 
> **num_threads**: int
> > the number of threads in upscaling
> >
> > default 1
> 
> **scale**: int
> > scale level, 1 = no scaling, 2 = upscale 2x
> >
> > value: float. default: 2
> 
> **noise**: int
> > noise level, large value means strong denoise effect, -1 = no effect
> >
> > value: -1/0/1/2/3. default: -1
> 
> **tilesize**: int
> > tile size, use smaller value to reduce GPU memory usage, default selects automatically
> >
> > 0 for automatically setting the size. default: 0

Waifu2x.**set_params**(self, scale=2, noise=-1, tilesize=0)
>
> set parameters for waifu2x object. 
> 
> This function will be called during the object initialization, so usually no need to call it except for parameters changes after initialization.
> 
> ### **Parameters**
> 
> **scale**: int
> > scale ratio. 
> >
> > value: 1/2. default: 2
>
>**noise**: int
> > denoise level.
> >
> > value: -1/0/1/2/3. default: -1
>
> **tilesize**: int
> > tile size.
> >
> > 0 for automatically setting the size. default: 0
> 
> ### **Returns**: None

Waifu2x.**load**(parampath: str = "", modelpath: str = "")
> Load models from given paths. Use Waifu2x.model if one or all of the parameters are not given.
> 
> This function will be called during the object initialization, so usually no need to call it except for setting a different **Waifu2x.model** after initialization.
>
> ### **Parameters**
>
> **parampath**: str
> > the path to model params. usually ended with ".param".
>
> **modelpath**: str
> > the path to model bin. usually ended with ".bin"
> >
> > value: -1/0/1/2/3. default: -1
>
>
> ### **Returns**: None

Waifu2x.**process**(self, im: PIL.Image)
> Process the incoming PIL.Image
>
> ### **Parameters**
>
> **im**: PIL.Image
> > the image object to process
>
> ### **Returns**: PIL.Image
> > The result PIL.Image object.

### Properties

Waifu2x.**gpuid**
> The id of gpu this Waifu2x Object is using.
> 
Waifu2x.**model**
> The model name or path this object is going to use. Waifu2x.load() should be called manually after updating this property.
>
Waifu2x.**scale**
> The result scale ratio. It is different to the self._raw_w2xobj.scale. Waifu2x.scale controls the result scale size while
> self._raw_w2xobj.scale controls the scale ratio at each raw image process method call. 
> 
> ( Waifu2x.**_process**(im) is the raw image process call. A upscaling task is done by repeatedly calling 2 times super-resolution)
>
Waifu2x.**_raw_w2xobj**
> The raw binding object of the original Waifu2x class. All the processing parameters are actually passed to this object eventually.
> 
> It is not recommend to operate on this object directly since there are many important parameter settings like tilesize setting have already been included in Python Waifu2x class.

## Known issues
- [Module finalization will crash for nvidia dedicated graphics card(s) on Linux. (The image processing still works.)](https://github.com/Tencent/ncnn/issues/2666)
- Not yet tested for Mac OS. I guess it should work.

## Original waifu2x Project

- https://github.com/nagadomi/waifu2x
- https://github.com/lltcggie/waifu2x-caffe
- https://github.com/nihui/waifu2x-ncnn-vulkan

## Other Open-Source Code Used

- https://github.com/Tencent/ncnn for fast neural network inference on ALL PLATFORMS
- https://github.com/webmproject/libwebp for encoding and decoding Webp images on ALL PLATFORMS
- https://github.com/nothings/stb for decoding and encoding image on Linux / MacOS
- https://github.com/tronkko/dirent for listing files in directory on Windows
