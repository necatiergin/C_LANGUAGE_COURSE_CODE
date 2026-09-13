#include <assert.h>

enum Color {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE
};

const char *color_name(enum Color color)
{
    switch (color) {
    case COLOR_RED:
        return "red";
    case COLOR_GREEN:
        return "green";
    case COLOR_BLUE:
        return "blue";
    }

    assert(!"invalid Color value");
    return "";
}
