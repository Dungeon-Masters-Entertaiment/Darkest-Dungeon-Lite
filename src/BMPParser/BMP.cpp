//
// Created by Ivan Novikov on 09.03.2024.
//

/*
#include <cstdio>
#include "BMP.h"
#include <ncurses.h>


class Bmp_Reader {
    std::vector <std::vector <int>> get_character(std::string file_name) {
        bitmap_image image("bmp_files/" + file_name);
        int height = image.height(), width = image.width();
        std::vector <std::vector <int>> ret_character (height, std::vector <int> (width));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                unsigned char r, g, b;
                image.get_pixel(j, i, r, g, b);
                short r_search, g_search, b_search;

                ret_character[i][j] = 0;
                int deviation = 1000000;

                for (int color = 0; color < 16; color++) {
                    color_content((short)color, &r_search, &g_search, &b_search);
                    int cur_dev = (r - r_search) * (r - r_search) + (g - g_search) * (g - g_search) + (b - b_search) * (b - b_search);
                    if (cur_dev < deviation) {
                        deviation = cur_dev;
                        ret_character[i][j] = color;
                    }
                }
            }
        }
        return ret_character;
    }
};
*/
