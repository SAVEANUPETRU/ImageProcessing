#include <cassert>
#include "imageprocessing.h"
#include <math.h>
void test_size(){
    Size s1;
    assert(s1.getheight() == 0);
    assert(s1.getwidth() == 0);
    assert(s1.getsize() == 0);


    Size s2(3, 4);
    assert(s2.getheight() == 3);
    assert(s2.getwidth() == 4);
    assert(s2.getsize() == 12);


    Size s3(100, 200);
    assert(s3.getheight() == 100);
    assert(s3.getwidth() == 200);
    assert(s3.getsize() == 20000);


    Size s4(0, 10);
    assert(s4.getheight() == 0);
    assert(s4.getwidth() == 10);
    assert(s4.getsize() == 0);

    Size s5(-2, 5);
    assert(s5.getheight() == -2);
    assert(s5.getwidth() == 5);
    assert(s5.getsize() == -10);

}
void test_point() {
    Point p1;
    assert(p1.get_x() == 0);
    assert(p1.get_y() == 0);


    Point p2(3, 7);
    assert(p2.get_x() == 3);
    assert(p2.get_y() == 7);


    std::istringstream input("5 9");
    input >> p1;
    assert(p1.get_x() == 5);
    assert(p1.get_y() == 9);


    std::ostringstream output;
    output << p1;
    assert(output.str() == "(5,9)\n");
}
void test_rectangle() {
    Rectangle r1;
    std::ostringstream out1;
    out1 << r1;
    assert(out1.str() == "Left corner: 0 0 0 0\n");


    Rectangle r2(2, 4, 10, 5);
    std::ostringstream out2;
    out2 << r2;
    assert(out2.str() == "Left corner: 2 4 10 5\n");


    Point p1(1, 6), p2(5, 2);
    Rectangle r3(p1, p2);
    assert(out2.str() != ""); // test indirect


    std::istringstream input("3 3 5 5");
    Rectangle r4;
    input >> r4;
    std::ostringstream out4;
    out4 << r4;
    assert(out4.str() == "Left corner: 3 3 5 5\n");


    Point delta(1, -1);
    Rectangle r5 = r2 + delta;
    std::ostringstream out5;
    out5 << r5;
    assert(out5.str() == "Left corner: 3 3 10 5\n");


    Rectangle r6 = r2 - delta;
    std::ostringstream out6;
    out6 << r6;
    assert(out6.str() == "Left corner: 1 5 10 5\n");


    Rectangle ra(0, 10, 10, 10);
    Rectangle rb(5, 15, 10, 10);
    Rectangle rint = ra & rb;
    std::ostringstream outint;
    outint << rint;
    assert(outint.str() == "Left corner: 5 10 5 5\n");


    Rectangle runi = ra | rb;
    std::ostringstream outr;
    outr << runi;
    assert(outr.str() == "Left corner: 0 15 15 15\n");

}
void test_image() {

    Image img(5, 5);
    assert(img.height() == 5);
    assert(img.width() == 5);
    assert(!img.isEmpty());

    img.at(0, 0) = 115;
    img.at(1, 1) = 200;
    img.at(2, 2) = 50;
    img.at(3, 3) = 255;

    assert(img.at(0, 0) == 115);
    assert(img.at(1, 1) == 200);
    assert(img.at(2, 2) == 50);
    assert(img.at(3, 3) == 255);


    Image img2(5, 5);
    img2.at(0, 0) = 100;
    img2.at(1, 1) = 50;
    img2.at(2, 2) = 200;
    img2.at(3, 3) = 0;

    Image resultAdd = img + img2;
    assert(resultAdd.at(0, 0) == 215);
    assert(resultAdd.at(1, 1) == 250);
    assert(resultAdd.at(2, 2) == 250);
    assert(resultAdd.at(3, 3) == 255);

    Image resultSub = img - img2;
    assert(resultSub.at(0, 0) == 15);
    assert(resultSub.at(1, 1) == 150);
    assert(resultSub.at(2, 2) == 0);
    assert(resultSub.at(3, 3) == 255);

    Image resultMul = img * 2;
    assert(resultMul.at(0, 0) == 230);
    assert(resultMul.at(1, 1) == 255);
    assert(resultMul.at(2, 2) == 100);
    assert(resultMul.at(3, 3) == 255);


    Image roiImg;
    img.getROI(roiImg, 1, 1, 3, 3);

    assert(roiImg.height() == 3);
    assert(roiImg.width() == 3);

    assert(roiImg.at(0, 0) == 200);
    assert(roiImg.at(1, 1) == 50);

    Size imgSize = img.size();
    assert(imgSize.getheight() == 5);
    assert(imgSize.getwidth() == 5);

    Image zeroImg = Image::zeros(3, 3);
    assert(zeroImg.at(0, 0) == 0);
    assert(zeroImg.at(1, 1) == 0);
    assert(zeroImg.at(2, 2) == 0);

    Image onesImg = Image::ones(3, 3);
    assert(onesImg.at(0, 0) == 255);
    assert(onesImg.at(1, 1) == 255);
    assert(onesImg.at(2, 2) == 255);

    Image final;
    if (!final.load("C:\\Users\\petru\\CLionProjects\\Image\\imagine.txt")) {
        std::cerr << "Nu s-a putut încărca imaginea!\n";
    }

    Image resultFinal = final + 50;

    if (!resultFinal.save("C:\\Users\\petru\\CLionProjects\\Image\\imaginefinal.txt")) {
        std::cerr << "Nu s-a putut salva imaginea!\n";
    }

}
void test_draw_circle() {
    ///circle
    int width = 10, height = 10;
    Image img(width, height);
    img.adjust(0,0,'j');
    img.adjust(9,9,'j');
    Point center(5, 5);
    unsigned char color = 'i';
    Image result = drawCircle(img, center, 3, color);
    assert(result.at(5, 5) == color);
    assert(result.at(3, 5) == color);
    assert(result.at(7, 5) == color);
    assert(result.at(5, 3) == color);
    assert(result.at(5, 7) == color);
    assert(result.at(0, 0) != color);
    assert(result.at(9, 9) != color);
}
void test_draw_line() {
    int width = 10, height = 10;
    Image img(width, height);
    img.adjust(0,0,'j');
    img.adjust(9,9,'j');
    Point p1(2, 2), p2(8, 8);
    unsigned char color = 'i';
    Image result = drawLine(img, p1, p2, color);
    assert(result.at(2, 2) == color);
    assert(result.at(8, 8) == color);
    assert(result.at(5, 5) == color);
    assert(result.at(7, 7) == color);
    assert(result.at(0, 0) != color);
    assert(result.at(9, 9) != color);
}
void test_draw_rectangle() {
    int width = 10, height = 5, x = 2, y = 9, color = 'i';
    Rectangle r(x, y, width, height);
    Image img(15, 15);
    img.adjust(1,10,'j');
    Image result = drawRectangle(img, r, color);

    for (int i = y; i > y - height; --i)
        for (int j = x; j < x + width; ++j) {
            assert(result.at(j, i) == color);
        }

    assert(result.at(10, 1) != color);
}
void test_draw_rectangle1() {
    int width = 10, height = 10;
    Image img(width, height);
    img.adjust(0,0,'j');
    img.adjust(9,9,'j');
    Point tl(2, 4), br(7, 2);
    unsigned char color = 'i';
    Image result = drawRectangle(img, tl, br, color);
    for (int i = 2; i <= 7; ++i) {
        for (int j = 2; j <= 4; ++j) {
            assert(result.at(i, j) == color);
        }
    }
    assert(result.at(0, 0) != color);
    assert(result.at(9, 9) != color);
}
void test_brightness() {
    Image input(2, 2);
    input.adjust(0, 0, 10);
    input.adjust(0, 1, 150);
    input.adjust(1, 0, 200);
    input.adjust(1, 1, 250);

    Image output;
    Brightness brightnessFilter(1, 10);
    brightnessFilter.process(input, output);

    assert(output.at(0, 0) == 20);
    assert(output.at(1, 0) == 160);
    assert(output.at(0, 1) == 210);
    assert(output.at(1, 1) == 255);
}
void test_gamma() {
    Image input(1, 1);
    input.adjust(0, 0, 64);

    GammaCorrection gamma(0.5);
    Image output;
    gamma.process(input, output);

    float expected =sqrt(64);
    expected = min(expected, 255.0f);
    assert(abs(float(output.at(0, 0)) - expected) < 1);
}
void test_convolutional() {
    Image img(3, 3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            img.adjust(i, j, 255);

    float kernel[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    auto scale = [](float x) -> unsigned char {
        return static_cast<unsigned char>(std::clamp(x / 9.0f, 0.0f, 255.0f));
    };

    Convolution conv(kernel, scale);
    Image result;
    conv.process(img, result);

    assert(result.at(1,1)==255);
}
void test_all(){
    test_size();
    test_point();
    test_rectangle();
    test_image();
    test_draw_circle();
    test_draw_line();
    test_draw_rectangle();
    test_draw_rectangle1();
    test_brightness();
    test_gamma();
    test_convolutional();
    cout << "All tests passed" << endl;
 }
