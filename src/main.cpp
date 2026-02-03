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


//inversement couleur
    for (glm::vec3& color : image.pixels())
    std::swap(color.r, color.b);


    image.save("output/pouet.png");
}