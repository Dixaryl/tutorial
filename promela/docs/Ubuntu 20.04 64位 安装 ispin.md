# 准备工作
- 下载[Spin](https://github.com/nimble-code/Spin) 
# 安装步骤
1. sudo apt-get update，更新源
2. sudo apt-get install spin，安装Spin，输入spin并回车，显示如Spin Version 6.4.9 -- 17 December 2018，则安装成功
3. sudo apt-get install wish，安装Tk
4. sudo apt-get install gcc，安装gcc
5. 解压准备工作中下载的Spin，并进入optional_gui目录，如~/Desktop/Spin-master/optional_gui
6. wish ispin.tcl
7. 点击Open，选择Spin-master\Examples目录下的hello.pml
8. 点击Syntax Check，控制台显示spin: nothing to report
9. 点击Simulate/Replay，点击(Re)Run，控制台显示passed first test!
10. 点击Verification，点击Run，控制台显示State-vector 12 byte, depth reached 2, errors: 0
11. Spin安装测试通过
