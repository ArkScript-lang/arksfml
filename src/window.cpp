#include <SFML/Graphics.hpp>
#include <sf_module.hpp>

bool& get_has_window() { static bool w = false; return w; }

Ark::Value sf_window_init(std::vector<Ark::Value>& n, Ark::VM* vm)
{
    if (n.size() != 3)
        throw std::runtime_error("sf:window:init needs 3 arguments: width, height and title");
    if (n[0].valueType() != Ark::ValueType::Number)
        throw Ark::TypeError("sf:window:init: width must be a Number");
    if (n[1].valueType() != Ark::ValueType::Number)
        throw Ark::TypeError("sf:window:init: height must be a Number");
    if (n[2].valueType() != Ark::ValueType::String)
        throw Ark::TypeError("sf:window:init: title must be a String");
    
    if (!get_has_window())
    {
        get_window().create(sf::VideoMode(static_cast<long>(n[0].number()), static_cast<long>(n[1].number())), n[2].string().toString());
        get_has_window() = true;
    }
    else
        throw std::runtime_error("sf:window:init: can't call the function twice");

    return Ark::Nil;
}

Ark::Value sf_window_isopen(std::vector<Ark::Value>& n, Ark::VM* vm)
{
    return get_window().isOpen() ? Ark::True : Ark::False;
}

Ark::Value sf_window_clear(std::vector<Ark::Value>& n, Ark::VM* vm)
{
    if (n.size() != 3)
        throw std::runtime_error("sf:window:clear needs 3 arguments: r, g and b");
    if (n[0].valueType() != Ark::ValueType::Number)
        throw Ark::TypeError("sf:window:clear: r must be a Number");
    if (n[1].valueType() != Ark::ValueType::Number)
        throw Ark::TypeError("sf:window:clear: g must be a Number");
    if (n[2].valueType() != Ark::ValueType::Number)
        throw Ark::TypeError("sf:window:clear: b must be a Number");
    get_window().clear(sf::Color(static_cast<long>(n[0].number()), static_cast<long>(n[1].number()), static_cast<long>(n[2].number())));
    return Ark::Nil;
}

Ark::Value sf_window_display(std::vector<Ark::Value>& n, Ark::VM* vm)
{
    get_window().display();
    return Ark::Nil;
}

Ark::Value sf_window_set_fps(std::vector<Ark::Value>& n, Ark::VM* vm)
{
    if (n[0].valueType() != Ark::ValueType::Number)
        throw Ark::TypeError("sf:window:setFPS: fps must be a Number");
    get_window().setFramerateLimit(static_cast<long>(n[0].number()));
    return Ark::Nil;
}

Ark::Value sf_window_close(std::vector<Ark::Value>& n, Ark::VM* vm)
{
    get_window().close();
    return Ark::Nil;
}

Ark::Value sf_draw(std::vector<Ark::Value>& n, Ark::VM* vm)
{
    for (Ark::Value::Iterator it=n.begin(); it != n.end(); ++it)
    {
        if (it->valueType() != Ark::ValueType::User)
            throw Ark::TypeError("sf:draw: invalid argument");

        if (it->usertypeRef().is<sf::Text>())
            get_window().draw(it->usertypeRef().as<sf::Text>());
        else if (it->usertypeRef().is<sf::Sprite>())
            get_window().draw(it->usertypeRef().as<sf::Sprite>());
        else
            throw Ark::TypeError("Object can not be drawn");
    }
    return Ark::Nil;
}