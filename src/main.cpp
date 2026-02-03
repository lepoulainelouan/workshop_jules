#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};


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