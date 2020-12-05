#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>

#include <Ark/Module.hpp>

#include <list>

sf::RenderWindow& get_window();
sf::Event& get_event();
std::list<sf::Texture>& get_textures();
std::list<sf::Sprite>& get_sprites();
std::list<sf::Font>& get_fonts();
std::list<sf::Text>& get_texts();
