#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>

int main()
// {
//     sil::Image image{"images/logo.png"};


    //Tout en vert
//     for (glm::vec3& color : image.pixels())
// {
//     color.r = 0.f;
//     color.b=0.f;
// }
//     image.save("output/vert.png");
// }


//inversement couleur
//     for (glm::vec3& color : image.pixels()){
//     std::swap(color.r, color.b);
// }
//     image.save("output/canaux.png");
// }


//noir et blanc
//     for (glm::vec3& color : image.pixels()) {
//         float gray = 0.333f * color.r + 0.333f * color.g + 0.333f * color.b;
//         color = glm::vec3{gray};
//     }
//     image.save("output/logo_nb.png");
// }


//negatif
//     for (glm::vec3& color : image.pixels()){
//         color.r = 1.0f-color.r;
//         color.g = 1.0f-color.g;
//         color.b = 1.0f-color.b;
//     }
//     image.save("output/logo_negatif.png");
// }

//degradé
    // for (int x{0}; x < image.width(); x++)
    // {
    //     for (int y{0}; y < image.height(); y++)
    //     {
    //         image.pixel(x, y).r = 0.f;
    //     }
    // }


//Miroir
//     for (int y = 0; y < image.height(); y++) {
//         for (int x = 0; x < image.width() / 2; x++) {
//             std::swap(
//                 image.pixel(x, y), 
//                 image.pixel(image.width() - 1 - x, y)
//             );
//         }
//         }
//     image.save("output/miroir.png");
// }


//Image bruitée
//     for (glm::vec3& color : image.pixels()) {
//         color.r += random_float(-0.3f, 0.3f);
//         color.g += random_float(-0.3f, 0.3f);
//         color.b += random_float(-0.3f, 0.3f);
//     }
//     image.save("output/logo_noize.png");
// }


//rotation 90
    // sil::Image new_image{image.width(), image.height()};
    // int total_pixels = image.width() * image.height();
    // for (int i = 0; i < total_pixels / 2; i++) {
    //     std::swap(image.pixels()[i], image.pixels()[total_pixels - 1 - i]);
    // }
    // new_image.save("output/rotation_90.png");
    // }


//RGB SPLIT
//     sil::Image new_image{image.width(), image.height()};
    
//     int split =20;
//     for (int y = 0; y < image.height(); y++) {
//         for (int x = 0; x < image.width(); x++) {
//             //Rouge
//             int x_droite = std::min(x + split, image.width() - 1);
//             new_image.pixel(x, y).r = image.pixel(x_droite, y).r;
//             //Vert
//             new_image.pixel(x, y).g = image.pixel(x, y).g;
//             //Bleu
//             int x_gauche = std::max(x - split, 0);
//             new_image.pixel(x, y).b = image.pixel(x_gauche, y).b;
//             }
//     }
//     new_image.save("output/logo_rgb_split.png");
// }


//disque 
    // {
    // sil::Image image{500/*width*/, 500/*height*/};
    // int centre_x = 250;
    // int centre_y = 250;
    // int rayon = 100;
    
    // for (int y = 0; y < image.height(); y++) {
    //     for (int x = 0; x < image.width(); x++) {
    //         float distance = std::sqrt(
    //             std::pow(x - centre_x, 2) + std::pow(y - centre_y, 2)
    //         );
    //         if (distance <= rayon) {
    //             image.pixel(x, y) = glm::vec3{1.0f}; 
    //         }
    //         }
    // } 
    // image.save("output/disque.png");
    // }


//cercle
    // {
    // sil::Image image{500/*width*/, 500/*height*/};
    // int centre_x = 250;
    // int centre_y = 250;
    // int rayon = 100;
    // int thickness = 10;

    // for (int y = 0; y < image.height(); y++) {
    //     for (int x = 0; x < image.width(); x++) {
    //         float distance = std::sqrt(
    //             std::pow(x - centre_x, 2) + std::pow(y - centre_y, 2)
    //         );
    //         if (distance >= rayon - thickness && distance <= rayon) {
    //             image.pixel(x, y) = glm::vec3{1.0f};
    //         }
    //         }
    // }
    // image.save("output/cercle.png");
    // }


//rosace
    // {
    // sil::Image image{500/*width*/, 500/*height*/};
    // int centre_x = 250;
    // int centre_y = 250;
    // int rayon = 100;
    // int thickness = 2;
    
    // for (int y = 0; y < image.height(); y++) {
    //     for (int x = 0; x < image.width(); x++) {
    //         bool dans_cercle = false;
    //         float distance_centre = std::sqrt(
    //             std::pow(x - centre_x, 2) + std::pow(y-centre_y, 2)
    //         );
    //         if (distance_centre >= rayon - thickness && distance_centre <= rayon) {
    //             dans_cercle = true;
    //         }

    //         for (int i = 0; i < 6; i++) {//repetion du cercle 
    //             float angle = i * 2.0f * M_PI / 6.0f;
    //             int cx = centre_x + rayon * std::cos(angle);
    //             int cy = centre_y + rayon * std::sin(angle);
    //             float distance = std::sqrt(
    //                 std::pow(x - cx, 2) + std::pow(y - cy, 2)
    //             );
                
    //             if (distance >= rayon - thickness && distance <= rayon) {
    //                 dans_cercle = true;
    //             }
    //         }
            
    //         if (dans_cercle) {
    //             image.pixel(x, y) = glm::vec3{1.0f};
    //         }
    //     }
    // }
    // image.save("output/rosace.png");
    // }

//Mosaique
    