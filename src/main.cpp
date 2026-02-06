#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>
#include <complex>

sil::Image box_blur(sil::Image const& image, int kernel_size)   
{
    sil::Image result{image.width(), image.height()};
    int half = kernel_size / 2;
    
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            glm::vec3 sum{0.f};
            int count = 0;
            for (int dy = -half; dy <= half; dy++) {
                for (int dx = -half; dx <= half; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < image.width() && ny >= 0 && ny < image.height()) {
                        sum += image.pixel(nx, ny);
                        count++;
                    }
                }
            }
            result.pixel(x, y) = sum / static_cast<float>(count);
        }
    }
    
    return result;
}


int main()
{
    sil::Image image{"images/logo.png"};
    // sil::Image image{"images/photo.jpg"};
    // sil::Image image{"images/photo_faible_contraste.png"};


////////////////////////////////////////////////////////

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
//     sil::Image new_image{image.height(), image.width()};

//     for (int x = 0; x < image.width(); x++)
//     {
//         for (int y = 0; y < image.height(); y++)
//         {
//             new_image.pixel(image.height() - 1 - y, x) = image.pixel(x, y);
//         }
//     }
//     new_image.save("output/rotation_90.png");
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
//     sil::Image mosaique{image.width() * 5, image.height() * 5};
//     for (int y = 0; y < mosaique.height(); y++) {
//         for (int x = 0; x < mosaique.width(); x++) {
//             mosaique.pixel(x, y) = image.pixel(x%image.width(), y%image.height());
//         }
//     }
//     mosaique.save("output/mosaique.png");
// }

//mosaique miroir
//     sil::Image mosaique_m{image.width() * 5, image.height() * 5};
//     for (int y = 0; y < mosaique_m.height(); y++) {
//         for (int x = 0; x < mosaique_m.width(); x++) {

//             int case_x = x / image.width();
//             int case_y = y / image.height();
//             int local_x = x % image.width();
//             int local_y = y % image.height();
            
//             if (case_x % 2 == 1) {
//                 local_x = image.width() - 1 - local_x;
//             }

//             if (case_y%2==1){
//                 local_y=image.height()-1-local_y;
//             }
//             mosaique_m.pixel(x, y) = image.pixel(local_x, local_y);
//         }
//     }
//     mosaique_m.save("output/mosaique_m.png");
// }


//glitch
    // int nb_glitches = 100; 
    
//     for (int i = 0; i < nb_glitches; i++) {
//         int rect_width = random_int(4, 20);
//         int rect_height = random_int(4, 20);
        
//         int x1 = random_int(0, image.width() - rect_width);
//         int y1 = random_int(0, image.height() - rect_height);
        
//         int x2 = random_int(0, image.width() - rect_width);
//         int y2 = random_int(0, image.height() - rect_height);
        

//         for (int dy = 0; dy < rect_height; dy++) {
//             for (int dx = 0; dx < rect_width; dx++) {
//                 std::swap(
//                     image.pixel(x1 + dx, y1 + dy),
//                     image.pixel(x2 + dx, y2 + dy)
//                 );
//             }
//         }
//     }
    
//     image.save("output/glitch.png");
// }

//Fractale de Mandelbrot
//     sil::Image image{500, 500};
//     int max_iterations = 100;

//     for (int x = 0; x < image.width(); x++)
//     {
//         for (int y = 0; y < image.height(); y++)
//         {
//             float real = (x / static_cast<float>(image.width())) * 3.5f - 2.5f;
//             float imag = (y / static_cast<float>(image.height())) * 2.0f - 1.0f;

//             std::complex<float> c{real, imag};
            
//             std::complex<float> z{0.f, 0.f};
//             int iterations = 0;
            
//             while (std::abs(z) <= 2.0f && iterations < max_iterations)
//             {
//                 z = z * z + c;
//                 iterations++;
//             }
//             float color;
//             if (iterations == max_iterations)
//             {

//                 color = 1.0f;
//             }
//             else
//             {

//                 color = iterations / static_cast<float>(max_iterations);
//             }
//             image.pixel(x, y).r=color;
//             image.pixel(x, y).g=color;
//             image.pixel(x, y).b=color;
//         }
//     }
//     image.save("output/mandelbrot.png");
// }


//J'ai voulu faire un truc mais ça a donné un autre effet et en vrai j'aime un peu donc je veux pas supprimer 
//     sil::Image blur_small = box_blur(image, 0);
//     sil::Image blur_large = box_blur(image, 50);
//     sil::Image result{image.width(), image.height()};

//     for (int y = 0; y < image.height(); y++) {
//         for (int x = 0; x < image.width(); x++) {
//             glm::vec3 diff = blur_small.pixel(x, y) - blur_large.pixel(x, y);
//             result.pixel(x, y) = diff + glm::vec3{0.5f};
//         }
//     }
//     result.save("output/difference_gaussienne.png");
// }