#include <SFML/Graphics.hpp>
#include <sf_module.hpp>

Value sf_load_texture(std::vector<Value>& n, Ark::VM* vm)
{
    if (n.size() != 1)
        throw std::runtime_error("sf:load:texture: need 1 argument: path");
    if (n[0].valueType() != ValueType::String)
        throw Ark::TypeError("sf:load:texture: need a path to the texture");

    sf::Texture& texture = get_textures().emplace_back();
    if (!texture.loadFromFile(n[0].string().toString()))
        throw std::runtime_error("sf:load:texture: Could not load texture: " + n[0].string().toString());

    return Value(UserType(&texture));
}

Value sf_load_sprite(std::vector<Value>& n, Ark::VM* vm)
{
    if (n.size() != 1)
        throw std::runtime_error("sf:load:sprite: need 1 argument: texture");
    if (n[0].valueType() != ValueType::User || !n[0].usertype_ref().is<sf::Texture>())
        throw Ark::TypeError("sf:load:sprite: need a SFML texture");

    sf::Sprite& object = get_sprites().emplace_back();
    object.setTexture(n[0].usertype_ref().as<sf::Texture>());

    return Value(UserType(&object));
}

Value sf_load_font(std::vector<Value>& n, Ark::VM* vm)
{
    if (n.size() != 1)
        throw std::runtime_error("sf:load:font: need 1 argument: path to font");
    if (n[0].valueType() != ValueType::String)
        throw Ark::TypeError("sf:load:font: need a String");

    sf::Font& font = get_fonts().emplace_back();
    if (!font.loadFromFile(n[0].string().toString()))
        throw std::runtime_error("sf:load:font: Could not load font: " + n[0].string().toString());

    return Value(UserType(&font));
}

Value sf_make_text(std::vector<Value>& n, Ark::VM* vm)
{
    if (n.size() != 4)
        throw std::runtime_error("sf:text:make: need 4 arguments: font, text, size, color");
    if (n[0].valueType() != ValueType::User || !n[0].usertype_ref().is<sf::Font>())
        throw Ark::TypeError("sf:text:make: invalid argument (font)");
    if (n[1].valueType() != ValueType::String)
        throw Ark::TypeError("sf:text:make: invalid argument (text)");
    if (n[2].valueType() != ValueType::Number)
        throw Ark::TypeError("sf:text:make: invalid argument (size)");
    if (n[3].valueType() != ValueType::List)
        throw Ark::TypeError("sf:text:make: invalid argument (color)");

    sf::Text& object = get_texts().emplace_back();
    object.setFont(n[0].usertype_ref().as<sf::Font>());
    object.setString(n[1].string().toString());
    object.setCharacterSize(static_cast<long>(n[2].number()));
    object.setFillColor(sf::Color(
        static_cast<long>(n[3].const_list()[0].number()),
        static_cast<long>(n[3].const_list()[1].number()),
        static_cast<long>(n[3].const_list()[2].number())
    ));

    return Value(UserType(&object));
}

Value sf_set_text(std::vector<Value>& n, Ark::VM* vm)
{
    if (n.size() != 2)
        throw std::runtime_error("sf:text:set: need 2 arguments: text object, new value");
    if (n[0].valueType() != ValueType::User || !n[0].usertype_ref().is<sf::Text>())
        throw Ark::TypeError("sf:text:set: invalid argument (text object)");
    if (n[1].valueType() != ValueType::String)
        throw Ark::TypeError("sf:text:set: invalid argument (new value)");

    n[0].usertype_ref().as<sf::Text>().setString(n[1].string().toString());
    return Nil;
}

Value sf_setpos(std::vector<Value>& n, Ark::VM* vm)
{
    if (n.size() != 3)
        throw std::runtime_error("sf:set:pos: need 3 arguments: object, x, y");
    if (n[0].valueType() != ValueType::User)
        throw Ark::TypeError("sf:set:pos: invalid argument (object)");
    if (n[1].valueType() != ValueType::Number)
        throw Ark::TypeError("sf:set:pos: invalid argument (x)");
    if (n[2].valueType() != ValueType::Number)
        throw Ark::TypeError("sf:set:pos: invalid argument (y)");

    if (n[0].usertype_ref().is<sf::Text>())
        n[0].usertype_ref().as<sf::Text>().setPosition(static_cast<long>(n[1].number()), static_cast<long>(n[2].number()));
    else if (n[0].usertype_ref().is<sf::Sprite>())
        n[0].usertype_ref().as<sf::Sprite>().setPosition(static_cast<long>(n[1].number()), static_cast<long>(n[2].number()));
    else
        throw Ark::TypeError("Object isn't a SFML object");

    return Nil;
}

Value sf_width(std::vector<Value>& n, Ark::VM* vm)
{
    if (n.size() != 1)
        throw std::runtime_error("sf:width: need 1 argument: object");
    if (n[0].valueType() != ValueType::User)
        throw Ark::TypeError("sf:width: invalid argument");

    if (n[0].usertype_ref().is<sf::Text>())
        return Value(static_cast<int>(n[0].usertype_ref().as<sf::Text>().getGlobalBounds().width));
    else if (n[0].usertype_ref().is<sf::Sprite>())
        return Value(static_cast<int>(n[0].usertype_ref().as<sf::Sprite>().getGlobalBounds().width));
    throw Ark::TypeError("Object isn't a SFML object");
}

Value sf_height(std::vector<Value>& n, Ark::VM* vm)
{
    if (n.size() != 1)
        throw std::runtime_error("sf:height: need 1 argument: object");
    if (n[0].valueType() != ValueType::User)
        throw Ark::TypeError("sf:height: invalid argument");

    if (n[0].usertype_ref().is<sf::Text>())
        return Value(static_cast<int>(n[0].usertype_ref().as<sf::Text>().getGlobalBounds().height));
    else if (n[0].usertype_ref().is<sf::Sprite>())
        return Value(static_cast<int>(n[0].usertype_ref().as<sf::Sprite>().getGlobalBounds().height));
    throw Ark::TypeError("Object isn't a SFML object");
}