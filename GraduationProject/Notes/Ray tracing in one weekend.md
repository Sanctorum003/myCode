# Chapter 1:Output an image
* PPM file
```python
P3
3 2
255
# The part above is the header
# "P3" means this is a RGB color image in ASCII
# "3 2" is the width and height of the image in pixels
# "255" is the maximum value for each color
# The part below is image data: RGB triplets
255   0   0     0 255   0     0   0 255
255 255   0   255 255 255     0   0   0
```

# Chapter 2:The vec3 class
* inline:内联函数不会引入任何函数调用，效率高
* cosnt:
* 引用：
* this和*this:

# Chapter 3:Rays,a simple camera,and background
* 射线方程：P(t) = A+t*B
> A 起始坐标  
> B 方向向量  
> P(t): 已知t时，可以获得光线上该点的坐标（向量）

* 光线追踪基本步骤
* 