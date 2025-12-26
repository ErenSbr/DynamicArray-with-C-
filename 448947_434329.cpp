#include <iostream>

using namespace std;




class DynamicArray {
    private:
    //degiskenler
    int* data;
    int size;
    int capacity;
    //Yardımcı foksiyon çok fazla kod fazlalığına yol açıyodu
    void kapasiteKontrol();
public:
    DynamicArray();
    DynamicArray(int capacity);
    DynamicArray(const DynamicArray& op);
    virtual ~DynamicArray(); // Virtual destructor

    //islemler
    void clear();
    void print() const;
  //override için virtual
    virtual void push(int deger);
    void pop();
    int get(int indeks) const;
    int getSize() const;
    int getCapacity() const;
    void set(int indeks, int deger);
    bool isEmpty() const;



    // Operatörler
    int& operator[](int indeks);
    const int& operator[](int index) const;
    DynamicArray operator+(const DynamicArray& op);
    DynamicArray& operator=(const DynamicArray& op);
    bool operator==(const DynamicArray& op) const;
    bool operator!=(const DynamicArray& op) const;
    friend ostream& operator<<(ostream& os, const DynamicArray& arr);
};

// Unique array
class UniqueArray : public DynamicArray {
public:
    UniqueArray();
    UniqueArray(int capacity);
    // Override edildi
    void push(int value) override;
    bool contains(int value) const;
};

//Sorted Array sınıfı
class SortedArray : public DynamicArray {
public:
    SortedArray();
    SortedArray(int capacity);
    // Override
    void push(int value) override;
    int binarySearch(int value);
};
//********************
//Main
//********************
int main() {
    // 1. Dynamic Array Testi
    cout << "--- Dynamic Array Testi ---" << endl;
    DynamicArray arr1;
    arr1.push(25);
    arr1.push(50);
    arr1.push(75);
    arr1.print();
    // İndeksleme operatörü
    arr1[1] = 55;
    cout << "arr1[1] = " << arr1[1] << endl;
    // Birleştirme operatoru
    DynamicArray arr2;
    arr2.push(40);
    arr2.push(50);
    DynamicArray arr3 = arr1 + arr2;
    cout << "Birlestirilmis dizi: ";
    arr3.print();
    // Sorted Array İşlemleri
    cout << "\n--- Sorted Array Testi ---" << endl;
    SortedArray sorted;
    sorted.push(8);
    sorted.push(27);
    sorted.push(35);
    sorted.push(20);
    sorted.print();
    int index = sorted.binarySearch(35);
    cout << "35 bulundu indeks: " << index << endl;
    // Unique Array Testi
    cout << "\n--- Unique Array Testi ---" << endl;
    UniqueArray unique;
    unique.push(37);
    unique.push(20);
    unique.push(37); // Aynısı var, eklemez
    unique.push(30);
    unique.print();
    cout << "20 var mi? " << (unique.contains(20) ? "Evet" : "Hayir") << endl;
    return 0;
}
//_--------------------_
//Dynamic Array işlemleri
//_-------------------_
DynamicArray::DynamicArray() {
    capacity = 2;
    size = 0;
    data = new int[capacity];
}
DynamicArray::DynamicArray(int kapasite) {
    if (kapasite < 2) kapasite = 2;
    capacity = kapasite;
    size = 0;
    data = new int[capacity];
}
DynamicArray::DynamicArray(const DynamicArray& dizi) { // Copy Constructor
    capacity = dizi.capacity;
    size = dizi.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = dizi.data[i];
    }
}
DynamicArray::~DynamicArray() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
}
void DynamicArray::kapasiteKontrol() {
    if (size == capacity) {
        int yeniKapasite = capacity * 2;
        int* tempdizi = new int[yeniKapasite];
        for (int k = 0; k < size; k++) {
            tempdizi[k] = data[k];
        }
        delete[] data;
        data = tempdizi;
        capacity = yeniKapasite;
    }
}

void DynamicArray::push(int deger) {
    kapasiteKontrol();
    data[size] = deger;
    size++;
}

void DynamicArray::pop() {
    if (size <= 0) {
        cout << "Bos listeden eleman silemezsin" << endl;
        return;
    }
    data[size - 1] = 0;
    size--;
    if (size > 0 && size == capacity / 2 && capacity > 2) {
        int yeniKapasite = (size < 2) ? 2 : size;
        int* tempdizi = new int[yeniKapasite];
        for (int k = 0; k < size; k++) {
            tempdizi[k] = data[k];
        }
        delete[] data;
        data = tempdizi;
        capacity = yeniKapasite;
    }
}
int DynamicArray::get(int index) const {
    if (index >= 0 && index < size) return data[index];
    //-1 döndürüyorruz
    return -1;
}

void DynamicArray::set(int index, int value) {
    if (index >= 0 && index < size) data[index] = value;
}
int DynamicArray::getSize() const { return size; }
int DynamicArray::getCapacity() const { return capacity; }
bool DynamicArray::isEmpty() const { return size == 0; }
void DynamicArray::clear() { size = 0; }

void DynamicArray::print() const {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}
//_--------------------_
//Dynamic Array
//_--------------------_
int& DynamicArray::operator[](int index) { return data[index]; }
const int& DynamicArray::operator[](int index) const { return data[index]; }
DynamicArray DynamicArray::operator+(const DynamicArray& op) {
    DynamicArray yeniList(size + op.size);
    for (int i = 0; i < size; i++) yeniList.push(data[i]);
    for (int i = 0; i < op.size; i++) yeniList.push(op.data[i]);
    return yeniList;
}
DynamicArray& DynamicArray::operator=(const DynamicArray& op) {
    if (this == &op) return *this;
    delete[] data;
    capacity = op.capacity;
    size = op.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++) data[i] = op.data[i];
    return *this;
}

bool DynamicArray::operator==(const DynamicArray& op) const {
    if (size != op.size) return false;
    for (int i = 0; i < size; i++) {
        if (data[i] != op.data[i]) return false;
    }
    return true;
}

bool DynamicArray::operator!=(const DynamicArray& op) const { return !(*this == op); }
ostream& operator<<(ostream& os, const DynamicArray& op) {
    if (op.size == 0) {
        os << "[]";
    }
    else {
        os << "[ ";
        for (int i = 0; i < op.size; i++) {
            os << op.data[i];
            if (i < op.size - 1) os << ", ";
        }
        os << " ]";
    }
    return os;
}
//---------------
// Unique Array İmp.
//_----------------
UniqueArray::UniqueArray() : DynamicArray() {}
UniqueArray::UniqueArray(int capacity) : DynamicArray(capacity) {}
bool UniqueArray::contains(int value) const {
    for (int i = 0; i < getSize(); i++) {
        if (get(i) == value) return true;
    }
    return false;
}
void UniqueArray::push(int value) {
    if (!contains(value)) {
        DynamicArray::push(value);
    }
}
// sorted array implemantasyonu
SortedArray::SortedArray() : DynamicArray() {}
SortedArray::SortedArray(int capacity) : DynamicArray(capacity) {}
void SortedArray::push(int deger) {
    DynamicArray::push(deger);
    int i = getSize() - 1;
    while (i > 0 && get(i) < get(i-1)) {
        // değiştirme
        int temp = get(i);
        set(i, get(i-1));
        set(i-1, temp);
        i--;
    }
}
int SortedArray::binarySearch(int aranan){
    int sol = 0;
    int sag = getSize() - 1;
    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;
        int ortaDeger = get(orta);
        if (ortaDeger == aranan)
            return orta;
        if (ortaDeger < aranan)//sağ tarafa
            sol = orta + 1;
        else//sola
            sag = orta - 1;
    }
    return -1;
}