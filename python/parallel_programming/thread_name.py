import threading
import time


def first_function():
    print(threading.currentThread().getName() + \
          str(' is Starting \n'))
    time.sleep(2)
    print(threading.currentThread().getName() + \
          str(' is Exiting \n'))
    return


def second_function():
    print(threading.currentThread().getName() + \
          str(' is Starting \n'))
    time.sleep(2)
    print(threading.currentThread().getName() + \
          str(' is Exiting \n'))
    return


def third_function():
    print(threading.currentThread().getName() + \
          str(' is Starting \n'))
    time.sleep(2)
    print(threading.currentThread().getName() + \
          str(' is Exiting \n'))
    return


if __name__ == '__main__':
    # 可以在线程创建时增加命名
    t1 = threading.Thread \
        (name='frist_function', target=first_function)
    t2 = threading.Thread \
        (name='second_function', target=second_function)
    t3 = threading.Thread \
        (name='third_function', target=third_function)
    t1.start()
    t2.start()
    t3.start()
    # 加入以下的join()方法后，可以确保三个子线程执行完前，主线程不会结束
    t1.join()
    t2.join()
    t3.join()
