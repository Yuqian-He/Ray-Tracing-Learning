#include "color.h"
#include "vec3.h"

#include <iostream>
#include <fstream> 

int main() {

    // Image
    int image_width = 256;
    int image_height = 256;

    // Open file for writing
    std::ofstream outfile("image.ppm");

    // Render
    outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            // Write the pixel color to the output file
            write_color(outfile, pixel_color);
        }
    }

    // Close the file
    outfile.close();

    std::clog << "\rDone.                 \n";
}