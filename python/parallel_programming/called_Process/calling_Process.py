import os

program = "python"
print("Process Calling")
# 放入列表后，可以使字符串以一个完整元素的形式加入元组
arguments = ["called_Process.py"]
# execvp函数启动了一个新进程，并替换了当前的进程
os.execvp(program, (program,) + tuple(arguments))
print("Good Bye!!")
