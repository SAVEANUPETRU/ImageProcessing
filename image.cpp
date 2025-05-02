#include "image.h"

using namespace std;
Image::Image() {
    this->m_height = 0;
    this->m_width = 0;
    this->m_data = nullptr;
}
Image::Image(unsigned int w, unsigned int h) {
    this->m_height = h;
    this->m_width = w;
    this->m_data = new unsigned char*[h];
    for (int i = 0; i < h; i++) {
        this->m_data[i] = new unsigned char[w];
    }
}
Image::~Image() {
    this->release();
}
Image::Image(const Image &other) {
    m_height = other.m_height;
    m_width = other.m_width;
    m_data = new unsigned char*[m_height];
    for (int i = 0; i < m_height; i++) {
        m_data[i] = new unsigned char[m_width];
    }
    for (unsigned int i = 0; i < m_height; i++) {
        for (unsigned int j = 0; j < m_width; j++) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
}
Image &Image::operator=(const Image &other) {
    if (this != &other) {
        release();
        m_height = other.m_height;
        m_width = other.m_width;
        m_data = new unsigned char*[m_height];
        for (int i = 0; i < m_height; i++) {
            m_data[i] = new unsigned char[m_width];
        }
        for (unsigned int i = 0; i < m_height; i++) {
            for (unsigned int j = 0; j < m_width; j++) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }
    return *this;
}
unsigned int Image::height()const {
    return m_height;
}
unsigned int Image::width()const {
    return m_width;
}
Size Image::size()const {
    return Size{int(m_height),int( m_width)};
}
bool Image::isEmpty()const {
   return m_data == nullptr;
}
bool Image::save(string imagePath) {
    std::ofstream file(imagePath);
    if (!file) return false;

    file << "P2\n";
    file << m_width << " " << m_height << "\n";
    file << "255\n";

    for (unsigned int i = 0; i < m_height; ++i) {
        for (unsigned int j = 0; j < m_width; ++j) {
            file << static_cast<int>(m_data[i][j]) << " ";
        }
        file << "\n";
    }

    return true;
}
bool Image::load(string imagePath) {
    std::ifstream file(imagePath);
    if (!file) return false;

    std::string line;
    getline(file, line);
    if (line != "P2") return false;

    do {
        getline(file, line);
    } while (line[0] == '#');

    std::stringstream ss(line);
    ss >> m_width >> m_height;

    int maxVal;
    file >> maxVal;

    m_data = new unsigned char*[m_height];
    for (unsigned int i = 0; i < m_height; ++i)
        m_data[i] = new unsigned char[m_width];

    for (unsigned int i = 0; i < m_height; ++i) {
        for (unsigned int j = 0; j < m_width; ++j) {
            int val;
            file >> val;
            m_data[i][j] = static_cast<unsigned char>(val);
        }
    }

    return true;
}
Image Image::operator+(const Image &other) const {
    if (m_height != other.m_height || m_width != other.m_width) {
        throw std::invalid_argument("Image::operator+()");
    }

    Image result(m_width, m_height);

    for (unsigned int i = 0; i < m_height; ++i) {
        for (unsigned int j = 0; j < m_width; ++j) {
            result.m_data[i][j] = min(255, m_data[i][j] + other.m_data[i][j]);
        }
    }

    return result;
}

Image Image::operator-(const Image &other) const {
    if (m_height != other.m_height || m_width != other.m_width) {
        throw std::invalid_argument("Image::operator-()");
    }

    Image result(m_width, m_height);

    for (unsigned int i = 0; i < m_height; ++i) {
        for (unsigned int j = 0; j < m_width; ++j) {
            result.m_data[i][j] = max(0, m_data[i][j] - other.m_data[i][j]);
        }
    }

    return result;
}
Image Image::operator*(int i) const{
    Image result(m_width, m_height);
    for (unsigned int x = 0; x < m_height; ++x) {
        for (unsigned int y = 0; y < m_width; ++y) {
            int newValue = m_data[x][y] * i;
            result.m_data[x][y] = (unsigned char)min(255, max(0, newValue));
        }
    }
    return result;
}

Image Image::operator+(int i) const{
    Image result(m_width, m_height);
    for (unsigned int x = 0; x < m_height; ++x) {
        for (unsigned int y = 0; y < m_width; ++y) {
            int newValue = m_data[x][y] + i;
            result.m_data[x][y] = (unsigned char)min(255, max(0, newValue));
        }
    }
    return result;
}

Image Image::operator-(int i) const{
    Image result(m_width, m_height);
    for (unsigned int x = 0; x < m_height; ++x) {
        for (unsigned int y = 0; y < m_width; ++y) {
            int newValue = m_data[x][y] - i;
            result.m_data[x][y] = (unsigned char)min(255, max(0, newValue));
        }
    }
    return result;
}
void Image::release() {
    for (unsigned int i = 0; i < m_height; ++i) {
        delete[] m_data[i];
    }
    delete[] m_data;
    m_data = nullptr;
}
unsigned char &Image::at(unsigned int x, unsigned int y) const{
    if (x> m_height || y> m_width) {
        throw std::invalid_argument("Image::at()");
    }
    return m_data[x][y];
}
unsigned char &Image::at(Point pt) {
    if (pt.get_x() > m_width || pt.get_y() > m_height) {
        throw std::invalid_argument("Image::at()");
    }
    return m_data[pt.get_x()][pt.get_y()];
}
unsigned char *Image::row(int y) {
    if (y > m_height) {
        throw std::invalid_argument("Image::row()");
    }
    return m_data[y];
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if (x + width > m_width || y + height > m_height) {
        throw std::invalid_argument("ROI out of bounds");
    }
    roiImg = Image(width, height);

    for (unsigned int i = 0; i < height; ++i) {
        unsigned char* sourceRow = m_data[y + i];
        unsigned char* destRow = roiImg.m_data[i];

        for (unsigned int j = 0; j < width; ++j) {
            *(destRow + j) = *(sourceRow + (x + j));
        }
    }

    return true;
}
Image Image::zeros(unsigned int width, unsigned int height) {
    Image result(width, height);
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            result.m_data[y][x] = 0;
        }
    }
    return result;
}
Image Image::ones(unsigned int width, unsigned int height) {
    Image result(width, height);
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            result.m_data[y][x] = 255;
        }
    }
    return result;
}
ostream& operator<<(ostream& os, const Image& dt){
    for (unsigned int i = 0; i < dt.m_height; ++i) {
        for (unsigned int j = 0; j < dt.m_width; ++j) {
            os << setw(3) << (int)dt.m_data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

void Image::adjust(int x, int y,unsigned char r) {
    m_data[y][x] = r;
}





