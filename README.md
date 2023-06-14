# OpenGL


练习OpenGL的项目, 最终会将其抽象成专门的类


## cmake 包含第三方库
1. 第三方库有CMakeLists.txt文件，可以考虑直接用`add_subdirectories`直接包含
2. 第三方库没有CMakeLists.txt等文件，可以自己写一个，然后按第一步做
3. 第三方库提供了xxxconfig.cmake 或者 Findxxx.cmake文件，可以用`find_package`找到包


