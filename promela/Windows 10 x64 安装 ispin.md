# 准备工作
- 下载[Cygwin](https://www.cygwin.com/install.html)  
- 下载[Spin](https://github.com/nimble-code/Spin)  
- 下载[ActiceTcl](https://www.activestate.com/products/tcl/#is-this-tcl-download-free)
# 安装步骤
安装gcc与cpp
1. 打开setup-x86_64.exe
2. 从互联网安装
3. 使用系统代理设置，如“无法下载镜像站点列表”，则访问[官网](https://www.cygwin.com/mirrors.html)，从China选择任意镜像，如mirrors.tencent.com，
复制链接地址，如<https://mirrors.tencent.com/cygwin/>，粘贴至原程序用户网址，点击添加，点击下一步
4. 搜索gcc
5. 点击ALL,点击Devel，下载mingw64-i686-gcc-core，mingw64-i686-gcc-fortran，mingw64-i686-gcc-g++，mingw64-i686-gcc-objc，版本不限
6. 搜索cpp，同理下载mingw64-i686-cppunit，版本不限，点击下一步，点击完成
7. 根据Cygwin安装路径，添加环境变量，如C:\cygwin64\bin

安装ActiceTcl

测试Spin
1. 解压Spin-master.zip
2. 解压Spin-master\Bin目录下的任意Spin版本，如spin651_windows64.exe.gz，重命名为spin.exe
3. 根据Cygwin安装路径，剪切spin.exe，粘贴至bin目录下
4. 复制bin目录下的i686-w64-mingw32-gcc.exe，粘贴至bin目录下，并重命名为gcc.exe
5. 打开Spin-master\optional_gui目录下的ispin.tcl
6. 点击Open，选择Spin-master\Examples目录下的hello.pml
7. 点击Syntax Check，控制台显示spin: nothing to report
8. 点击Simulate/Replay，点击(Re)Run，控制台显示passed first test!
9. 点击Verification，点击Run，控制台显示State-vector 12 byte, depth reached 2, errors: 0
10. Spin安装测试通过
