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

    // ����ֵΪ30��Ԫ��
    auto it = std::find(vec.begin(), vec.end(), 30);

    if (it != vec.end()) {
        std::cout << "�ҵ���Ԫ�أ�ֵΪ: " << *it << std::endl;
    }
    else {
        std::cout << "û���ҵ�Ԫ��" << std::endl;
    }

    return 0;
}
