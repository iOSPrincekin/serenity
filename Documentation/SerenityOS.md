# 1.编译的优化和调试信息
## 1.添加 -O2 编译优化
add_compile_options(-O2)
## 2.添加 -g1 会使 qemu-system-i386 调试 .cpp 文件失败
add_compile_options(-g1)