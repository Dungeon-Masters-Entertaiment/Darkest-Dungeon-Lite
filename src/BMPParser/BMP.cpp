//
// Created by Ivan Novikov on 09.03.2024.
//
#include <cstdio>
#include "BMP.h"
#include <ncurses.h>

struct {
    int R, G, B;
} xtermColors[16] = {{0, 0, 0},
                      {128, 0, 0},
                      {0, 128, 0},
                      {128, 128, 0},
                      {0, 0, 128},
                      {128, 0, 128},
                      {0, 128, 128},
                      {192, 192, 192},
                      {128, 128, 128},
                      {255, 0, 0},
                      {0, 255, 0},
                      {255, 255, 0},
                      {0, 0, 255},
                      {255, 0, 255},
                      {0, 255, 255},
                      {255, 255, 255},
};

class Bmp_Reader {
public:
    static std::vector<std::vector<int>> get_character(std::string file_name) {
        bitmap_image image("res/HeroBMP/" + file_name + ".bmp");
        int height = image.height(), width = image.width();
        std::vector<std::vector<int>> ret_character(height, std::vector<int>(width));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {

                unsigned char r, g, b;
                image.get_pixel(j, i, r, g, b);

                //short r_search, g_search, b_search;
                ret_character[i][j] = 0;
                int deviation = 100000000;

                for (int color = 0; color < 16; color++) {
                    //color_content((short) color, &r_search, &g_search, &b_search);
                    int cur_dev = (r - xtermColors[color].R) * (r - xtermColors[color].R) + (g - xtermColors[color].G) * (g - xtermColors[color].G) +
                                  (b - xtermColors[color].B) * (b - xtermColors[color].B);
                    if (cur_dev < deviation) {
                        deviation = cur_dev;
                        ret_character[i][j] = color;
                        //ret_character[i][j] = xtermColors[color];
                        //ret_character[i][j] = COLOR_RED;
                    }
                }
                //ret_character[i][j] = ((r + g + b) / 3) / 16;
                //ret_character[i][j] = COLOR_RED;
            }
        }
        return ret_character;
    }
};

