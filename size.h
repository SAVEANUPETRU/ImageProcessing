/**
* @class Size
 * @brief Reprezintă dimensiunile unui obiect bidimensional (înălțime și lățime).
 */
class Size {
private:
    int height; /**< Înălțimea obiectului. */
    int width;  /**< Lățimea obiectului. */

public:
    /**
     * @brief Constructor implicit. Inițializează dimensiunile la 0.
     */
    Size();

    /**
     * @brief Constructor cu parametri.
     * @param height Înălțimea obiectului.
     * @param width Lățimea obiectului.
     */
    Size(int height, int width);

    /**
     * @brief Obține înălțimea obiectului.
     * @return Valoarea înălțimii.
     */
    int getheight();

    /**
     * @brief Obține lățimea obiectului.
     * @return Valoarea lățimii.
     */
    int getwidth();

    /**
     * @brief Obține aria (dimensiunea totală) obiectului.
     * @return Produsul dintre înălțime și lățime.
     */
    int getsize();
};