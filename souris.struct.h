#ifndef SOURIS_STRUCT_H
#define SOURIS_STRUCT_H

#include <vector>

struct sourisTooltip{
    int x, y;
    int xTool, yTool;
    unsigned int page;
    bool isHover;
    bool isHoverPageN, isHoverPageP;
    bool isHoverPersInAsc;
    bool onTooltip;
    size_t ascenseursHover;
    size_t personneHover, personneSelected;
    std::vector<size_t> personnesHover;
};

#endif // SOURIS_STRUCT_H
