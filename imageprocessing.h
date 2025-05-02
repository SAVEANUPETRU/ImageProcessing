#include "draw.h"
/**
 * @class ImageProcessing
 * @brief Clasă de bază pentru procesarea imaginilor.
 *
 * Această clasă este abstractă și definește un interfață generală pentru procesarea imaginilor.
 */
class ImageProcessing {
  public:
    /**
     * @brief Procesarea imaginii.
     *
     * Această metodă trebuie implementată în clasele derivate pentru a procesa o imagine
     * conform algoritmului specificat.
     * @param src Imaginea de intrare.
     * @param dst Imaginea de ieșire.
     */
    virtual void process(const Image& src, Image& dst) = 0;

    /**
     * @brief Destructorul clasei de bază.
     *
     * Destructorul virtual pentru a permite polimorfismul.
     */
    virtual ~ImageProcessing();
};

/**
 * @class Brightness
 * @brief Clasă care aplică ajustări de luminozitate unei imagini.
 *
 * Această clasă modifică luminozitatea unei imagini folosind un factor de scalare
 * și o valoare de offset.
 */
class Brightness : public ImageProcessing {
  private:
    int alpha; ///< Factorul de scalare pentru luminozitate.
    int beta;  ///< Valoarea de offset pentru ajustarea luminozității.

  public:
    /**
     * @brief Constructor implicit pentru Brightness.
     *
     * Inițializează alpha la 1 și beta la 0.
     */
    Brightness();

    /**
     * @brief Constructor pentru Brightness cu parametrii specifici.
     *
     * Permite setarea valorilor pentru alpha și beta.
     * @param _alfa Factorul de scalare pentru luminozitate.
     * @param _beta Valoarea de offset pentru ajustarea luminozității.
     */
    Brightness(int _alfa, int _beta);

    /**
     * @brief Aplică ajustarea de luminozitate asupra imaginii.
     *
     * Modifică valorile pixelilor imaginii folosind factorul alpha și offset-ul beta.
     * @param src Imaginea de intrare.
     * @param dst Imaginea de ieșire cu luminozitatea ajustată.
     */
    void process(const Image& src, Image& dst) override;
};

/**
 * @class GammaCorrection
 * @brief Clasă care aplică corecție gamma unei imagini.
 *
 * Corecția gamma ajustează luminozitatea imaginii pe baza unui factor gamma.
 */
class GammaCorrection : public ImageProcessing {
  private:
    float gamma; ///< Factorul gamma pentru corectarea luminozității.

  public:
    /**
     * @brief Constructor implicit pentru GammaCorrection.
     *
     * Inițializează gamma la 1.
     */
    GammaCorrection();

    /**
     * @brief Constructor pentru GammaCorrection cu un parametru gamma.
     *
     * Permite setarea valorii gamma pentru corectarea imaginii.
     * @param _gamma Factorul gamma de aplicat imaginii.
     */
    GammaCorrection(float _gamma);

    /**
     * @brief Aplică corecția gamma asupra imaginii.
     *
     * Modifică valorile pixelilor imaginii conform factorului gamma.
     * @param src Imaginea de intrare.
     * @param dst Imaginea de ieșire cu corecția gamma aplicată.
     */
    void process(const Image& src, Image& dst) override;
};

/**
 * @class Convolution
 * @brief Clasă care aplică un kernel de convoluție asupra imaginii.
 *
 * Această clasă aplică un kernel 3x3 asupra imaginii folosind o funcție de scalare.
 */
class Convolution : public ImageProcessing {
  private:
    float kernel[3][3]; ///< Kernel-ul 3x3 aplicat imaginii.
    unsigned char (*scale)(float); ///< Funcția de scalare a valorii pixelilor.

  public:
    /**
     * @brief Constructor pentru Convolution cu un kernel și o funcție de scalare.
     *
     * Permite setarea kernel-ului 3x3 și a funcției de scalare.
     * @param _kernel Kernel-ul 3x3 aplicat imaginii.
     * @param _scale Funcția de scalare a valorilor pixelilor.
     */
    Convolution(float _kernel[3][3], unsigned char (*_scale)(float));

    /**
     * @brief Aplică convoluția asupra imaginii folosind kernel-ul specificat.
     *
     * Modifică valorile pixelilor imaginii aplicând kernel-ul și scalarea corespunzătoare.
     * @param src Imaginea de intrare.
     * @param dst Imaginea de ieșire cu convoluția aplicată.
     */
    void process(const Image& src, Image& dst) override;
};
