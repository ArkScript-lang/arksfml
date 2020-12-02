#include <Ark/Module.hpp>

#include <event.hpp>
#include <graphics.hpp>
#include <window.hpp>

// module functions mapping
ARK_API_EXPORT mapping* getFunctionsMapping()
{
    mapping* map = mapping_create(17);

    mapping_add(map[0],  "sf:window:init",      sf_window_init);
    mapping_add(map[1],  "sf:window:open?",     sf_window_isopen);
    mapping_add(map[2],  "sf:window:close",     sf_window_close);
    mapping_add(map[3],  "sf:window:clear",     sf_window_clear);
    mapping_add(map[4],  "sf:window:display",   sf_window_display);
    mapping_add(map[5],  "sf:window:setFPS",    sf_window_set_fps);
    mapping_add(map[6],  "sf:pollEvent",        sf_poll_event);
    mapping_add(map[7],  "sf:draw",             sf_draw);
    mapping_add(map[8],  "sf:load:texture",     sf_load_texture);
    mapping_add(map[9],  "sf:load:sprite",      sf_load_sprite);
    mapping_add(map[10], "sf:load:font",        sf_load_font);
    mapping_add(map[11], "sf:make:text",        sf_make_text);
    mapping_add(map[12], "sf:set:text",         sf_set_text);
    mapping_add(map[13], "sf:set:pos",          sf_setpos);
    mapping_add(map[14], "sf:width",            sf_width);
    mapping_add(map[15], "sf:height",           sf_height);
    mapping_add(map[16], "sf:event",            sf_event);

    return map;
}