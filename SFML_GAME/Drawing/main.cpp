// library
#include <SFML/Graphics.hpp>

// main program
int main()
{
    // parameters
    unsigned int pixels_w = 24;
    unsigned int pixels_h = 24;
    
    // current color
    uint8_t cr = 255;
    uint8_t cg = 255;
    uint8_t cb = 255;

    // number of data in pixels
    unsigned int pixels_n = pixels_w * pixels_h * 4;

    // create array of pixels
    uint8_t pixels[pixels_n];

    // create window
    sf::RenderWindow window(sf::VideoMode({600, 600}), "Title");

    // create texture & sprite
    sf::Texture texture({pixels_w, pixels_h});
    sf::Sprite  sprite(texture);
    float scale = window.getSize().x / pixels_w;
    sprite.setScale({scale, scale});

    // lambda function - set pixel based on mouse position
    auto SetPixel = [&] (uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
    {
        // mouse position
        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

        // pixel position
        unsigned int x = mouse_position.x / scale;
        unsigned int y = mouse_position.y / scale;

        // index of RGBA channel
        unsigned int ir = (pixels_w*y + x) * 4;
        unsigned int ig = ir + 1;
        unsigned int ib = ig + 1;
        unsigned int ia = ib + 1;

        // set pixel
        if (ia < pixels_n and
            (pixels[ir] != r or pixels[ig] != g or pixels[ib] != b or pixels[ia] != a))
        {
            pixels[ir] = r;
            pixels[ig] = g;
            pixels[ib] = b;
            pixels[ia] = a;
    
            // update texture
            texture.update(pixels);
        }
    };

    // lambda function - clear pixels
    auto ClearPixels = [&] ()
    {
        // clear pixels
        for (unsigned int i = 0;  i < pixels_n;  i++)
            pixels[i] = 0;
    
        // update texture
        texture.update(pixels);
    };

    // clear pixels
    ClearPixels();

    // window loop
    while (window.isOpen())
    {
        // handle events
        while (auto event = window.pollEvent())
        {
            // on close button release
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }

            // when window is resized
            else if (auto resized = event->getIf<sf::Event::Resized>())
            {
                // update view
                window.setView(sf::View(sf::FloatRect({0.f, 0.f}, sf::Vector2f(resized->size))));
            }
        
            // on keyboard release
            else if (auto key = event->getIf<sf::Event::KeyReleased>())
            {
                // select color
                if      (key->scancode == sf::Keyboard::Scan::Num1) {cr = 255; cg = 255; cb = 255;}
                else if (key->scancode == sf::Keyboard::Scan::Num2) {cr =   0; cg =   0; cb =   0;}
                else if (key->scancode == sf::Keyboard::Scan::Num3) {cr =   0; cg = 170; cb = 255;}
                else if (key->scancode == sf::Keyboard::Scan::Num4) {cr =   0; cg = 255; cb = 255;}
                else if (key->scancode == sf::Keyboard::Scan::Num5) {cr = 255; cg = 223; cb = 191;}
            
                // clear pixels
                else if (key->scancode == sf::Keyboard::Scan::Escape)
                    ClearPixels();

                // save to file
                else if (key->scancode == sf::Keyboard::Scan::S and key->control)
                    bool success = texture.copyToImage().saveToFile("Draw.png");
            }
        }

        // when left mouse button is pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            // set pixel with current color
            SetPixel(cr, cg, cb);
        }

        // when right mouse button is pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
            // clear pixel
            SetPixel(0, 0, 0, 0);
        }

        // fill background color
        window.clear(sf::Color(64, 64, 64));

        // draw sprite
        window.draw(sprite);

        // display
        window.display();
    }

    // program end successfully
    return 0;
}