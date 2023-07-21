from threading import Thread
from time import sleep


class CookBook(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.massage = "Hello Parallel Python CookBook!!\n"

    def print_massage(self):
        print(self.massage)

    def run(self):
        print("Thread Starting\n")
        x = 0
        while x < 10:
            self.print_massage()
            sleep(2)
            x += 1
        print("Thread Ended\n")


print("Process Started")
hello_Python = CookBook()
hello_Python.start()
print("Process Ended")
# 虽然主程序已经执行完毕，但线程还会每隔两秒继续打印消息
