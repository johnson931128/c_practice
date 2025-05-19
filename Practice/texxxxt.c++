#include <SFML/Graphics.hpp>

int main()
{
    // 創建一個 800x600 的視窗
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    // 進入遊戲主循環
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close(); // 關閉視窗
        }

        // 清除視窗並填充背景顏色
        window.clear(sf::Color::Black);

        // 顯示畫面
        window.display();
    }

    return 0;
}
