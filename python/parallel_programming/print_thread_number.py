import threading


def function(i):
    print("function called by thread %i\n" % i)
    return


threads = []

for i in range(5):
    # Thread()方法用于在不同的线程中运行进程与函数
    # target:这是一个在启动一个线程活动时将会执行的函数
    # args:这是传给目标的一个参数元组
    t = threading.Thread(target=function, args=(i,))
    threads.append(t)
    # 直到调用start()方法时线程才会开始运行，join()方法会导致调用线程等待，直到它执行完毕
    t.start()
    t.join()
