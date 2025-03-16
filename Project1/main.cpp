#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
int main() {
    int arr[5];
    int top = -1;
    using namespace std;
    map<int, int> p;
    p.key_comp();
    std::vector<int> vec = { 10, 20, 30, 40, 50 };

    // 查找值为30的元素
    auto it = std::find(vec.begin(), vec.end(), 30);

    if (it != vec.end()) {
        std::cout << "找到了元素，值为: " << *it << std::endl;
    }
    else {
        std::cout << "没有找到元素" << std::endl;
    }

    return 0;
}
