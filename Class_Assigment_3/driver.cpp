#include "ComplexArray.h"
#include "Complex.h"

using namespace std;

int main() {
    Complex c1(7), c2(2, 3), c3(3, -4), c4(-3, -5);
    cout << "<< Complex >>>" << endl;
    cout << "c1: " << c1.toString() << endl;
    cout << "c2: " << c2.toString() << endl;
    cout << "c3: " << c3.toString() << endl;
    cout << "c4: " << c4.toString() << endl;
    cout << "\n<<< Complex + operators >>>" << endl;
    cout << "c1: " << c1 << ", c2: " << c2;
    cout << ", [++c1 + c2]: " << ++c1 + c2 << endl;
    cout << "c3: " << c3;
    cout << ", [(c3 += 7)++]: " << (c3 += 7)++ << ", c3: " << c3 << endl;
    cout << "c4: " << c4 << ", c1: " << c1;
    cout << ", [!(c4 += c1)]: " << !(c4 += c1) << endl;
    cout << "c1: " << c1 << ", c2: " << c2 << ", c3: " << c3 << ", ";
    c1 = c2 + c3;
    cout << "[c1 = c2 + c3]: " << c1 << endl;
    cout << "Enter data of complex number [real:imag] -2.8:3.4 - ";
    cin >> c1;
    cout << "c1: " << c1 << endl;
    double x = c1;
    cout << "real+imag: " << x << "," << (double)c1 << endl;
    cout << "\n<<< Complex Array >>>" << endl;
    ComplexArray carr1, carr2(4);
    cout << "carr1/carr2 : " << carr1 << "/" << carr2 << endl;
    cin >> carr2;
    cout << "carr2: " << carr2 << endl;
    Complex arr[] = {Complex(1,-1),Complex(2,-2),Complex(3,-3),
                     Complex(4,-4) };
    ComplexArray carr3(arr, 4), carr4(carr2);
    cout << "carr3: " << carr3 << endl;
    cout << "carr4: " << carr4.toString() << endl;
    cout << "carr2 == carr3: " <<((carr2 == carr3)?"yes":"no")<< endl;
    cout << "carr2 == carr4: " << ((carr2 == carr4)?"yes":"no") << endl;
    cout << "carr2 != carr3: " << ((carr2 != carr3)?"yes":"no") << endl;
    carr1 += Complex(-1, -1);
    cout << "carr1: " << carr1 << endl;
    carr1 += carr3 += Complex(10, 20);
    cout << "carr1/carr3: " << carr1 << " / " << carr3 << endl;
    carr1 = carr2 + carr3;
    cout << "carr1: " << carr1 << endl;
    cout << "carr1: " << !carr1 << endl;
    cout << "carr2: " << carr2 << "{";
    cout << "carr2[0]:" << carr2[0] << ", carr2[1]:" << carr2[1] << ", carr2[-1]:" << carr2[-1] << "}" << endl;
    carr2[0] = carr2[1] + carr2[-1];
    cout << "carr2 after {carr2[0] = carr2[1] + carr2[-1]}: " << carr2 << endl;
    carr1 = carr2 + carr3;
    cout << "carr1: " << carr1 << endl;

    cout << "!carr1: " << !carr1 << endl;

    cout << "carr2: " << carr2 << "{";
    cout << "carr2[0]:" << carr2[0] << ", carr2[1]:" << carr2[1] << ", carr2[-1]:" << carr2[-1] << "}" << endl;

    carr2[0] = carr2[1] + carr2[-1];
    cout << "carr2 after {carr2[0] = carr2[1] + carr2[-1]}: " << carr2 << endl;
    return 0;
}
