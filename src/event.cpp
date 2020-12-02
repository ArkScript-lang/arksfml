#include <sf_module.hpp>
#include <SFML/Window/Event.hpp>

Value sf_poll_event(std::vector<Value>& n, Ark::VM* vm)
{
    if (get_window().pollEvent(get_event()))
    {
        std::string out = "event-";

        if (get_event().type == sf::Event::Closed)
            out += "quit";
        else if (get_event().type == sf::Event::KeyReleased)
            out += "keyup";
        else if (get_event().type == sf::Event::KeyPressed)
            out += "keydown";
        else
            out += "unknown";

        if (get_event().type == sf::Event::KeyReleased || get_event().type == sf::Event::KeyPressed)
        {
            switch (get_event().key.code)
            {
            case sf::Keyboard::A: out += "a"; break;
            case sf::Keyboard::B: out += "b"; break;
            case sf::Keyboard::C: out += "c"; break;
            case sf::Keyboard::D: out += "d"; break;
            case sf::Keyboard::E: out += "e"; break;
            case sf::Keyboard::F: out += "f"; break;
            case sf::Keyboard::G: out += "g"; break;
            case sf::Keyboard::H: out += "h"; break;
            case sf::Keyboard::I: out += "i"; break;
            case sf::Keyboard::J: out += "j"; break;
            case sf::Keyboard::K: out += "k"; break;
            case sf::Keyboard::L: out += "l"; break;
            case sf::Keyboard::M: out += "m"; break;
            case sf::Keyboard::N: out += "n"; break;
            case sf::Keyboard::O: out += "o"; break;
            case sf::Keyboard::P: out += "p"; break;
            case sf::Keyboard::Q: out += "q"; break;
            case sf::Keyboard::R: out += "r"; break;
            case sf::Keyboard::S: out += "s"; break;
            case sf::Keyboard::T: out += "t"; break;
            case sf::Keyboard::U: out += "u"; break;
            case sf::Keyboard::V: out += "v"; break;
            case sf::Keyboard::W: out += "w"; break;
            case sf::Keyboard::X: out += "x"; break;
            case sf::Keyboard::Y: out += "y"; break;
            case sf::Keyboard::Z: out += "z"; break;
            case sf::Keyboard::Num0: out += "0"; break;
            case sf::Keyboard::Num1: out += "1"; break;
            case sf::Keyboard::Num2: out += "2"; break;
            case sf::Keyboard::Num3: out += "3"; break;
            case sf::Keyboard::Num4: out += "4"; break;
            case sf::Keyboard::Num5: out += "5"; break;
            case sf::Keyboard::Num6: out += "6"; break;
            case sf::Keyboard::Num7: out += "7"; break;
            case sf::Keyboard::Num8: out += "8"; break;
            case sf::Keyboard::Num9: out += "9"; break;
            case sf::Keyboard::Escape:   out += "escape"; break;
            case sf::Keyboard::LBracket: out += "["; break;
            case sf::Keyboard::RBracket: out += "]"; break;
            case sf::Keyboard::Semicolon: out += ";"; break;
            case sf::Keyboard::Comma:    out += ","; break;
            case sf::Keyboard::Period:   out += "."; break;
            case sf::Keyboard::Quote:    out += "'"; break;
            case sf::Keyboard::Slash:    out += "/"; break;
            case sf::Keyboard::Backslash: out += "\\"; break;
            case sf::Keyboard::Tilde:    out += "~"; break;
            case sf::Keyboard::Equal:    out += "="; break;
            case sf::Keyboard::Hyphen:   out += "-"; break;
            case sf::Keyboard::Space:    out += "space"; break;
            case sf::Keyboard::Enter:    out += "enter"; break;
            case sf::Keyboard::Tab:      out += "tab"; break;
            case sf::Keyboard::Add:      out += "+"; break;
            case sf::Keyboard::Subtract: out += "-"; break;
            case sf::Keyboard::Multiply: out += "*"; break;
            case sf::Keyboard::Divide:   out += "/"; break;
            case sf::Keyboard::Left:     out += "left"; break;
            case sf::Keyboard::Right:    out += "right"; break;
            case sf::Keyboard::Up:       out += "up"; break;
            case sf::Keyboard::Down:     out += "down"; break;
            default: out += "unknown"; break;
            }
        }

        return Value(out);
    }
    return Value("event-empty");
}

Value sf_event(std::vector<Value>& n, Ark::VM* vm)
{
    std::string out = "event-";

    if (n.size() == 0)
        throw std::runtime_error("sf:event need at least 1 argument");

    for (Value::Iterator it=n.begin(); it != n.end(); ++it)
    {
        if (it->valueType() != ValueType::String)
            throw Ark::TypeError("sf:event: invalid argument");
        out += it->string().toString();
    }

    return Value(out);
}
