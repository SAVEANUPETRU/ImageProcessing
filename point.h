#include <iostream>
using namespace std;
/**
 * @class Point
 * @brief Reprezintă un punct într-un plan bidimensional (x, y).
 */
class Point {
private:
    int x; /**< Coordonata x a punctului. */
    int y; /**< Coordonata y a punctului. */

public:
    /**
     * @brief Constructor implicit. Inițializează punctul la (0, 0).
     */
    Point();

    /**
     * @brief Constructor cu parametri.
     * @param x Coordonata x.
     * @param y Coordonata y.
     */
    Point(int x, int y);

    /**
     * @brief Supraincarcă operatorul << pentru a afișa un punct.
     * @param os Streamul de ieșire.
     * @param dt Punctul de afișat.
     * @return Referință la streamul de ieșire.
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& dt);

    /**
     * @brief Supraincarcă operatorul >> pentru a citi un punct.
     * @param is Streamul de intrare.
     * @param dt Punctul în care se vor citi valorile.
     * @return Referință la streamul de intrare.
     */
    friend std::istream& operator>>(std::istream& is, Point& dt);

    /**
     * @brief Obține coordonata x.
     * @return Valoarea lui x.
     */
    int get_x();

    /**
     * @brief Obține coordonata y.
     * @return Valoarea lui y.
     */
    int get_y();
};