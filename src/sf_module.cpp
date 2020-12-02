#include <SFML/Graphics.hpp>
#include <list>
#include <Ark/Module.hpp>

sf::RenderWindow& get_window() { static sf::RenderWindow w; return w; }
sf::Event& get_event() { static sf::Event e; return e; }
std::list<sf::Texture>& get_textures() { static std::list<sf::Texture> t; return t; }
std::list<sf::Sprite>& get_sprites() { static std::list<sf::Sprite> s; return s; }
std::list<sf::Font>& get_fonts() { static std::list<sf::Font> f; return f; }
std::list<sf::Text>& get_texts() { static std::list<sf::Text> t; return t; }
