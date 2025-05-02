#include "point.h"
/**
 * @class Rectangle
 * @brief Reprezintă un dreptunghi într-un plan bidimensional, definit prin colțul stânga-sus și dimensiuni.
 */
class Rectangle {
private:
    int width;  /**< Lățimea dreptunghiului. */
    int height; /**< Înălțimea dreptunghiului. */
    int x;      /**< Coordonata x a colțului stânga-sus. */
    int y;      /**< Coordonata y a colțului stânga-sus. */

public:
    /**
     * @brief Constructor implicit. Creează un dreptunghi nul.
     */
    Rectangle();

    /**
     * @brief Constructor care primește două puncte și calculează dimensiunile.
     * @param p Punctul din colțul stânga-sus.
     * @param q Punctul din colțul dreapta-jos.
     */
    Rectangle(Point &p, Point &q);

    /**
     * @brief Constructor cu coordonate explicite și dimensiuni.
     * @param x Coordonata x a colțului stânga-sus.
     * @param y Coordonata y a colțului stânga-sus.
     * @param width Lățimea dreptunghiului.
     * @param height Înălțimea dreptunghiului.
     */
    Rectangle(int x, int y, int width, int height);

    /**
     * @brief Supraincarcă operatorul << pentru afișarea unui dreptunghi.
     * @param os Streamul de ieșire.
     * @param r Dreptunghiul de afișat.
     * @return Referință la streamul de ieșire.
     */
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);

    /**
     * @brief Supraincarcă operatorul >> pentru citirea unui dreptunghi.
     * @param is Streamul de intrare.
     * @param r Dreptunghiul în care se vor citi valorile.
     * @return Referință la streamul de intrare.
     */
    friend std::istream& operator>>(std::istream& is, Rectangle& r);

    /**
     * @brief Translează dreptunghiul într-o poziție nouă prin adunarea unui punct.
     * @param p Punctul după care se translatează.
     * @return Dreptunghiul translatat.
     */
    Rectangle operator+(Point& p);

    /**
     * @brief Translează dreptunghiul înapoi prin scăderea unui punct.
     * @param p Punctul după care se translatează înapoi.
     * @return Dreptunghiul rezultat.
     */
    Rectangle operator-(Point& p);

    /**
     * @brief Calculează intersecția a două dreptunghiuri.
     * @param other Dreptunghiul cu care se face intersecția.
     * @return Dreptunghiul rezultat al intersecției (poate fi nul).
     */
    Rectangle operator&(const Rectangle& other) const;

    /**
     * @brief Calculează reuniunea a două dreptunghiuri (bounding box).
     * @param other Dreptunghiul de unit.
     * @return Dreptunghiul care acoperă ambele dreptunghiuri.
     */
    Rectangle operator|(const Rectangle& other) const;
    /**
     *@brief Returneaza top left point
     */
    Point get_corner() const;
    /**
     *@brief Returneaza height
     */
    int get_height() const;

    /**
     * @brief Returneaza width
     */
    int get_width() const;
};