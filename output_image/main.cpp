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
            outfile << (i * 255 / (image_width - 1)) << ' ' 
                    << (j * 255 / (image_height - 1)) << " 0\n";
        }
    }

    // Close the file
    outfile.close();

    std::clog << "\rDone.                 \n";
}

// The pixels are written out in rows.

// Every row of pixels is written out left to right.

// These rows are written out from top to bottom.

//By convention, each of the red/green/blue components are represented internally by real-valued variables that range 
//from 0.0 to 1.0. These must be scaled to integer values between 0 and 255 before we print them out.

//Red goes from fully off (black) to fully on (bright red) from left to right, and green goes from fully off at the top (black) 
//to fully on at the bottom (bright green). Adding red and green light together make yellow so we should expect the bottom right 
//corner to be yellow.