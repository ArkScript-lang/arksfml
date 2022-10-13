#include <Ark/Module.hpp>

#include <event.hpp>
#include <graphics.hpp>
#include <window.hpp>

// module functions mapping
ARK_API Ark::mapping* getFunctionsMapping()
{
    Ark::mapping* map = Ark::mapping_create(18);
    std::size_t i = 0;

    // window
    Ark::mapping_add(map[i++], "sf:window:init", sf_window_init);
    Ark::mapping_add(map[i++], "sf:window:open?", sf_window_isopen);
    Ark::mapping_add(map[i++], "sf:window:close", sf_window_close);
    Ark::mapping_add(map[i++], "sf:window:clear", sf_window_clear);
    Ark::mapping_add(map[i++], "sf:window:display", sf_window_display);
    Ark::mapping_add(map[i++], "sf:window:setFPS", sf_window_set_fps);
    Ark::mapping_add(map[i++], "sf:draw", sf_draw);

    // events
    Ark::mapping_add(map[i++], "sf:pollEvent", sf_poll_event);
    Ark::mapping_add(map[i++], "sf:event", sf_event);

    // graphics
    Ark::mapping_add(map[i++], "sf:load:texture", sf_load_texture);
    Ark::mapping_add(map[i++], "sf:load:sprite", sf_load_sprite);
    Ark::mapping_add(map[i++], "sf:load:font", sf_load_font);
    Ark::mapping_add(map[i++], "sf:text:make", sf_make_text);
    Ark::mapping_add(map[i++], "sf:text:set", sf_set_text);
    Ark::mapping_add(map[i++], "sf:text:setColor", sf_set_text_color);
    Ark::mapping_add(map[i++], "sf:set:pos", sf_setpos);
    Ark::mapping_add(map[i++], "sf:width", sf_width);
    Ark::mapping_add(map[i++], "sf:height", sf_height);

    return map;
}