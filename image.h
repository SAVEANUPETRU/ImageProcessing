#include <string.h>
#include <iostream>
#include "size.h"
#include "rectangle.h"
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;
/**
 * @class Image
 * @brief Reprezintă o imagine grayscale cu pixeli stocați ca matrice de valori `unsigned char`.
 */
/**
 * @class Image
 * @brief Reprezintă o imagine grayscale cu pixeli stocați ca matrice de valori `unsigned char`.
 */
class Image
{
public:
    /**
     * @brief Constructor implicit. Creează o imagine goală.
     */
    Image();

    /**
     * @brief Constructor cu dimensiuni.
     * @param w Lățimea imaginii.
     * @param h Înălțimea imaginii.
     */
    Image(unsigned int w, unsigned int h);

    /**
     * @brief Constructor de copiere.
     * @param other Imaginea de copiat.
     */
    Image(const Image &other);

    /**
     * @brief Destructor. Eliberează memoria.
     */
    ~Image();

    /**
     * @brief Încarcă o imagine dintr-un fișier binar.
     * @param imagePath Calea către fișier.
     * @return true dacă încărcarea a reușit.
     */
    bool load(std::string imagePath);

    /**
     * @brief Salvează imaginea în fișier binar.
     * @param imagePath Calea către fișier.
     * @return true dacă salvarea a reușit.
     */
    bool save(std::string imagePath);

    /**
     * @brief Operator de atribuire.
     * @param other Imaginea sursă.
     * @return Referință la imaginea curentă.
     */
    Image& operator=(const Image &other);

    /**
     * @brief Supraincarcă operatorul + pentru două imagini (adunare pixel cu pixel).
     * @param i Imaginea cu care se va face adunarea.
     * @return O nouă imagine rezultată din adunarea celor două imagini.
     */
    Image operator+(const Image &i) const;

    /**
     * @brief Supraincarcă operatorul - pentru două imagini (scădere pixel cu pixel).
     * @param i Imaginea cu care se va face scăderea.
     * @return O nouă imagine rezultată din scăderea celor două imagini.
     */
    Image operator-(const Image &i) const;

    /**
     * @brief Adaugă o valoare constantă fiecărui pixel.
     * @param i Valoarea care se adaugă fiecărui pixel.
     * @return O nouă imagine cu valorile pixelelor modificate.
     */
    Image operator+(int i) const;

    /**
     * @brief Scade o valoare constantă din fiecare pixel.
     * @param i Valoarea care se scade fiecărui pixel.
     * @return O nouă imagine cu valorile pixelelor modificate.
     */
    Image operator-(int i) const;

    /**
     * @brief Înmulțește fiecare pixel cu o constantă.
     * @param i Factorul cu care se înmulțesc valorile pixelilor.
     * @return O nouă imagine cu pixeli modificați.
     */
    Image operator*(int i) const;

    /**
     * @brief Obține o regiune de interes (ROI) din imagine.
     * @param roiImg Imaginea în care se salvează ROI-ul.
     * @param x Coordonata x a colțului stânga sus.
     * @param y Coordonata y a colțului stânga sus.
     * @param width Lățimea ROI-ului.
     * @param height Înălțimea ROI-ului.
     * @return true dacă ROI-ul este valid și a fost extras cu succes.
     */
    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

    /**
     * @brief Verifică dacă imaginea este goală (null).
     * @return true dacă imaginea este goală, altfel false.
     */
    bool isEmpty() const;

    /**
     * @brief Returnează dimensiunea imaginii.
     * @return Obiect `Size` cu lățime și înălțime.
     */
    Size size() const;

    /**
     * @brief Returnează lățimea imaginii.
     * @return Lățimea imaginii.
     */
    unsigned int width() const;

    /**
     * @brief Returnează înălțimea imaginii.
     * @return Înălțimea imaginii.
     */
    unsigned int height() const;

    /**
     * @brief Returnează referință la pixelul de pe poziția (x, y).
     * @param x Coordonata pe axa X.
     * @param y Coordonata pe axa Y.
     * @return Referință la pixelul de pe poziția (x, y).
     */
    unsigned char& at(unsigned int x, unsigned int y) const;

    /**
     * @brief Returnează referință la pixelul de pe poziția dată de un `Point`.
     * @param pt Punctul care conține coordonatele x și y.
     * @return Referință la pixelul corespunzător punctului.
     */
    unsigned char& at(Point pt);

    /**
     * @brief Returnează un pointer la începutul liniei y.
     * @param y Coordonata pe axa Y.
     * @return Pointer la începutul liniei respective.
     */
    unsigned char* row(int y);

    /**
     * @brief Eliberează memoria imaginii.
     */
    void release();

    /**
     * @brief Afișează informații despre imagine.
     * @param os Fluxul de ieșire.
     * @param dt Imaginea de afișat.
     * @return Referință la fluxul de ieșire.
     */
    friend std::ostream& operator<<(std::ostream& os, const Image& dt);

    /**
     * @brief Creează o imagine cu toți pixelii 0.
     * @param width Lățimea imaginii.
     * @param height Înălțimea imaginii.
     * @return O imagine cu toți pixelii 0.
     */
    static Image zeros(unsigned int width, unsigned int height);

    /**
     * @brief Creează o imagine cu toți pixelii 1.
     * @param width Lățimea imaginii.
     * @param height Înălțimea imaginii.
     * @return O imagine cu toți pixelii 1.
     */
    static Image ones(unsigned int width, unsigned int height);

    /**
     * @brief Schimbă valoarea unui pixel.
     * @param x Coordonata pe axa X a pixelului.
     * @param y Coordonata pe axa Y a pixelului.
     * @param r Valoarea nouă a pixelului.
     */
    void adjust(int x, int y, unsigned char r);

private:
    unsigned char** m_data;    /**< Matricea de pixeli. */
    unsigned int m_width;      /**< Lățimea imaginii. */
    unsigned int m_height;     /**< Înălțimea imaginii. */
};
