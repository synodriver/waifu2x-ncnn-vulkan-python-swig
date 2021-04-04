# Docs

## Methods
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
> > denoise level, large value means strong denoise effect, -1 = no effect
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