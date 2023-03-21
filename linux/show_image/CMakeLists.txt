cmake_minimum_required(VERSION 3.13.4)
#声明一个project
project(MAIN)


set(ENV{PKG_CONFIG_PATH} /usr/local/lib/pkgconfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_OPENCV REQUIRED opencv4)

#PKG_OPENCV相关头文件/库的输出
MESSAGE(STATUS "PKG_OPENCV_FOUND:          ${PKG_OPENCV_FOUND}")			#有没有找到		    eg: -- PKG_OPENCV_FOUND:        1
MESSAGE(STATUS "PKG_CONFIG_EXECUTABLE:     ${PKG_CONFIG_EXECUTABLE}")		#pkg-config脚本路径	 eg:  /usr/bin/pkg-config
MESSAGE(STATUS "PKG_CONFIG_VERSION_STRING: ${PKG_CONFIG_VERSION_STRING}")	#pkg-config版本号	  相当于执行: pkg-config --version

MESSAGE(STATUS "PKG_OPENCV_VERSION:        ${PKG_OPENCV_VERSION}")			#opencv的版本		  相当于执行: pkg-config opencv --modversion
MESSAGE(STATUS "PKG_OPENCV_PREFIX:         ${PKG_OPENCV_PREFIX}")			#opencv的安装路径PREFIX

MESSAGE(STATUS "PKG_OPENCV_INCLUDE_DIRS:   ${PKG_OPENCV_INCLUDE_DIRS}")		#头文件路径		    include路径，多个，分开
MESSAGE(STATUS "PKG_OPENCV_LIBRARY_DIRS:   ${PKG_OPENCV_LIBRARY_DIRS}")		#动态库路径		    lib路径，多个，分开
MESSAGE(STATUS "PKG_OPENCV_LIBRARIES:      ${PKG_OPENCV_LIBRARIES}")		#有那些动态库?        相当于执行: pkg-config opencv --libs-only-l，只列出库名字
MESSAGE(STATUS "PKG_OPENCV_LDFLAGS:        ${PKG_OPENCV_LDFLAGS}")			#所有需要链接的标志	  相当于执行: pkg-config opencv --libs，不仅有库名字，还有其路径
MESSAGE(STATUS "PKG_OPENCV_LDFLAGS_OTHER:  ${PKG_OPENCV_LDFLAGS_OTHER}")	#其他需要链接的标志	  相当于执行: pkg-config opencv --libs-only-other
MESSAGE(STATUS "PKG_OPENCV_CFLAGS:         ${PKG_OPENCV_CFLAGS}")			#cflag可以指头文件    相当于执行: pkg-config opencv --cflags，多个，分开
MESSAGE(STATUS "PKG_OPENCV_CFLAGS_OTHER:   ${PKG_OPENCV_CFLAGS_OTHER}")		#其他cflag标志		 相当于执行: pkg-config opencv --libs-only-other




# 查找当前目录下的所有源文件并将名称保存到DIR_SRCS变量
#AUX_SOURCE_DIRECTORY(. DIR_SRCS)
# 添加头文件detect.hpp路径
#INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/DetectorClass")
# 添加三方opencv的头文件路径-- -I/home/topeet/programfile/opencv2/include/opencv -I/home/topeet/programfile/opencv2/include
INCLUDE_DIRECTORIES(${PKG_OPENCV_INCLUDE_DIRS})

# 触发寻找下一级CMakeLists.txt，即指向DetectorClass子目录下的CMakeLists.txt，这时会把libdetect.so编译出来
#ADD_SUBDIRECTORY(DetectorClass)											#注意下面的语句不能和上面的INCLUDE_DIRECTORIES交换，否则头文件找不到，是个顺序过程
# 指定生成目标
ADD_EXECUTABLE(main main.cpp)
# 为指定的bin文件添加三方链接库
#TARGET_LINK_LIBRARIES(test detect ${PKG_OPENCV_LDFLAGS})
target_link_libraries(main ${PKG_OPENCV_LDFLAGS} )

#添加一个可执行文件
#add_executable(test test.cpp)
