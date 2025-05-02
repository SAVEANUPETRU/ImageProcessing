#include "image.h"
/**
 * @brief Desenează un cerc într-o imagine.
 *
 * @param image Imaginea în care se desenează cercul.
 * @param center Centrul cercului.
 * @param radius Raza cercului.
 * @param color Culoarea folosită pentru desen.
 */
Image drawCircle(Image& image, Point center, int radius, unsigned char color);

/**
 * @brief Desenează o linie între două puncte.
 *
 * @param img Imaginea în care se desenează linia.
 * @param p1 Punctul de start al liniei.
 * @param p2 Punctul de sfârșit al liniei.
 * @param color Culoarea liniei.
 */
Image drawLine(Image& img, Point p1, Point p2, unsigned char color);

/**
 * @brief Desenează un dreptunghi într-o imagine.
 *
 * @param img Imaginea în care se desenează dreptunghiul.
 * @param r Dreptunghiul de desenat (ca structură).
 * @param color Culoarea dreptunghiului.
 */
Image drawRectangle(Image& img, Rectangle r, unsigned char color);

/**
 * @brief Desenează un dreptunghi folosind punctele colțurilor.
 *
 * @param img Imaginea în care se desenează dreptunghiul.
 * @param tl Colțul din stânga sus.
 * @param br Colțul din dreapta jos.
 * @param color Culoarea dreptunghiului.
 */
Image drawRectangle(Image& img, Point tl, Point br, unsigned char color);