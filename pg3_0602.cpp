#include <iostream>
#include <string>
#include <chrono>
#include <utility>  

int main() {
    // 100,000文字の 'a' で初期化された文字列を作成
    std::string a(100000, 'a');

    // コピーにかかる時間を計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;  // コピー
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // ムーブにかかる時間を計測
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a);  // ムーブ
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // 結果を表示
    std::cout << "100,000文字を移動とコピーで比較" << std::endl;
    std::cout << "コピー: " << copy_duration << " μs" << std::endl;
    std::cout << "移動  : " << move_duration << " μs" << std::endl;

    // 終了待機
    std::cout << "続行するには何かキーを押してください…";
    std::cin.get();

    return 0;
}
