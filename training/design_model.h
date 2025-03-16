#pragma once
#include<mutex>
//工厂模式  包括静态类的工厂模式 和一个map的键值对 类名和构造函数   通告查找调用函数；
//


//单例模式
//使用static来访问对象  内部有一个自己的指针  null或者对象  多线程
//懒汉式加载不安全  用lock_gard<std::mutex>进行加锁 //缓存

