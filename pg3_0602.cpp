#include <iostream>
#include <string>
#include <chrono>
#include <utility>  

int main() {
    // 100,000���֤� 'a' �ǳ��ڻ����줿�����Ф�����
    std::string a(100000, 'a');

    // ���ԩ`�ˤ�����r�g��Ӌ�y
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;  // ���ԩ`
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // ��`�֤ˤ�����r�g��Ӌ�y
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a);  // ��`��
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // �Y�����ʾ
    std::cout << "100,000���֤��ƄӤȥ��ԩ`�Ǳ��^" << std::endl;
    std::cout << "���ԩ`: " << copy_duration << " ��s" << std::endl;
    std::cout << "�Ƅ�  : " << move_duration << " ��s" << std::endl;

    // �K�˴��C
    std::cout << "�A�Ф���ˤϺΤ����`��Ѻ���Ƥ���������";
    std::cin.get();

    return 0;
}
