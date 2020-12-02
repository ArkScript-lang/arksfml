#include <Ark/Module.hpp>

#include <event.hpp>
#include <graphics.hpp>
#include <window.hpp>

// module functions mapping
ARK_API_EXPORT mapping* getFunctionsMapping()
{
    mapping* map = mapping_create(17);
    std::size_t i = 0;

    // window
    mapping_add(map[i++], "sf:window:init",      sf_window_init);
    mapping_add(map[i++], "sf:window:open?",     sf_window_isopen);
    mapping_add(map[i++], "sf:window:close",     sf_window_close);
    mapping_add(map[i++], "sf:window:clear",     sf_window_clear);
    mapping_add(map[i++], "sf:window:display",   sf_window_display);
    mapping_add(map[i++], "sf:window:setFPS",    sf_window_set_fps);
    mapping_add(map[i++], "sf:draw",             sf_draw);

    // events
    mapping_add(map[i++], "sf:pollEvent",        sf_poll_event);
    mapping_add(map[i++], "sf:event",            sf_event);

    // graphics
    mapping_add(map[i++], "sf:load:texture",     sf_load_texture);
    mapping_add(map[i++], "sf:load:sprite",      sf_load_sprite);
    mapping_add(map[i++], "sf:load:font",        sf_load_font);
    mapping_add(map[i++], "sf:text:make",        sf_make_text);
    mapping_add(map[i++], "sf:text:set",         sf_set_text);
    mapping_add(map[i++], "sf:set:pos",          sf_setpos);
    mapping_add(map[i++], "sf:width",            sf_width);
    mapping_add(map[i++], "sf:height",           sf_height);

    return map;
}