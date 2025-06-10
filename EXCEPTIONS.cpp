#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include<sstream>

using namespace std;


// کلاس‌های استثناء
class negative_zero_R_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: value of R can not be negative or zero";
    }
};

class syntax_error_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Syntax error";
    }
};

class element_R_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Element not found in library\nMake sure the element type starts with a capital letter (e.g. 'R')";
    }
};

class invalid_delete_syntax_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Incorrect format";
    }
};

class invalid_delete_element_type_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid element type to delete.";
    }
};

class resistor_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Resistor not found.";
    }
};

class duplicate_resistor_name_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Resistor with the same name already exists in the circuit.";
    }
};

class element_C_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Element not found in library\nMake sure the element type starts with a capital letter (e.g. 'C')";
    }
};

class duplicate_capasitor_name_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Capasitor with the same name already exists in the circuit.";
    }
};

class negative_zero_C_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: value of C can not be negative or zero";
    }
};

class element_L_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Element not found in library\nMake sure the element type starts with a capital letter (e.g. 'L')";
    }
};

class duplicate_inductor_name_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Inductor with the same name already exists in the circuit.";
    }
};

class negative_zero_L_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: value of L can not be negative or zero";
    }
};

class duplicate_diode_exp : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Diode with same name already exists.";
    }
};

class element_D_not_found_diode_exp : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Diode not found.";
    }
};

class invalid_diode_element_model_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid diode model to add.";
    }
};

class element_D_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Element not found in library\nMake sure the element type starts with a capital letter (e.g. 'D')";
    }
};

class syntax_error_gnd_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid GND syntax. Use: add GND <node>";
    }
};

class duplicate_ground_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Ground node already exists.";
    }
};

class ground_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Ground node not found.";
    }
};


class element_VS_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Voltage Source element not found in library\nMake sure the element type starts with a capital letter (e.g. 'V')";
    }
};

class duplicate_voltage_source_name_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Voltage Source with the same name already exists in the circuit.";
    }
};

class negative_zero_VS_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: value of Current Source can not be negative or zero";
    }
};

class element_IS_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Current Source element not found in library\nMake sure the element type starts with a capital letter (e.g. 'I')";
    }
};

class duplicate_current_source_name_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Current Source with the same name already exists in the circuit.";
    }
};

class negative_zero_IS_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: value of Current Source can not be negative or zero";
    }
};

class element_sinV_not_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Sin Voltage Source element not found in library\nMake sure the element type starts with a capital letter (e.g. 'S')";
    }
};

class duplicate_sin_voltage_source_name_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Sin Voltage Source with the same name already exists in the circuit.";
    }
};

class negative_zero_sinV_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: values of Sin Voltage Source can not be negative or zero";
    }
};

// کلاس مقاومت
class Resistor {
public:
    string name;
    string node1;
    string node2;
    double value;

    Resistor(string n, string n1, string n2, double v)
        : name(n), node1(n1), node2(n2), value(v) {}
};
//کلاس خازن
class Capacitor {
public:
    string name;
    string node1;
    string node2;
    double value; // Farads

    Capacitor(string n, string n1, string n2, double v)
        : name(n), node1(n1), node2(n2), value(v) {}
};

// کلاس سلف
class Inductor {
public:
    string name;
    string node1;
    string node2;
    double value; // Henries

    Inductor(string n, string n1, string n2, double v)
        : name(n), node1(n1), node2(n2), value(v) {}
};

// کلاس دیود
class Diode {
public:
    string name;
    string node1;
    string node2;
    string model;

    Diode(string n, string n1, string n2, string m)
        : name(n), node1(n1), node2(n2), model(m) {}
};
//کلاس زمین
class Ground {
public:
    string node;
    Ground(string n) : node(n) {}
};

// کلاس منبع ولتاژ مستقل
class VoltageSource {
public:
    string name;
    string nodePositive; // گره مثبت
    string nodeNegative; // گره منفی (مثلا زمین)
    double value;        // مقدار ولتاژ بر حسب ولت

    VoltageSource(string n, string np, string nn, double v)
        : name(n), nodePositive(np), nodeNegative(nn), value(v) {}
};

// کلاس منبع جریان مستقل
class CurrentSource {
public:
    string name;
    string node1 ;
    string node2 ;
    double value;        

    CurrentSource(string n, string n1, string n2, double i)
        : name(n), node1(n1), node2(n2), value(i) {}
};

// تعریف کلاس منبع ولتاژ سینوسی
class SineVoltageSource {
public:
    string name;
    string nodePositive;
    string nodeNegative;
    double amplitude;  // مقداردامنهج ولتاژ )
    double offset; //مقدار DC
    double frequency;  // فرکانس (هرتز)
    //double phase;      // فاز (در درجه یا رادیان)

    SineVoltageSource(string n, string np, string nn, double amp, double dc, double freq)
        : name(n), nodePositive(np), nodeNegative(nn), amplitude(amp), frequency(freq), offset(dc) {}
};

// لیست مقاومت‌ها
vector<Resistor> resistors;
//بیست خازن ها
vector<Capacitor> capacitors;
//لیست سلف ها
vector<Inductor> inductors;
// لیست دیودها
vector<Diode> diodes;
//لیست زمین ها
vector<Ground> grounds;
// لیست منابع ولتاژ مستقل
vector<VoltageSource> voltageSources;
// لیست منابع جریان مستقل
vector<CurrentSource> currentSource;
// لیست منابع ولتاژ سینوسی
vector<SineVoltageSource> sineVoltageSources;

///// باید در بخش های دیگر موقع تحلیل مورد استفاده قرار بگیرد//////////////////////////////////////////////////
bool hasGround() {
    return !grounds.empty();
}

class no_ground_found_exp : public exception {
public:
    const char* what() const noexcept override {
        return "Error: No ground (GND) node found in the circuit. At least one ground is required.";
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// توابع کلی
// تابع جداکننده کلمات از رشته‌ی ورودی
void devide(string line, vector<string>& words) {
    istringstream iss(line);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
}

// تابع تبدیل مقدار با واحد
double parseValueWithUnit(const string& str) {
    if (str.empty()) throw syntax_error_exp();

    char lastChar = str.back();
    double multiplier = 1.0;
    string numberPart = str;

    if (lastChar == 'k' || lastChar == 'K') {
        multiplier = 1e3;
        numberPart = str.substr(0, str.size() - 1);
    } else if (lastChar == 'M') {
        multiplier = 1e6;
        numberPart = str.substr(0, str.size() - 1);
    } else if (lastChar == 'm'){
        multiplier = 1e-3 ;
        numberPart = str.substr(0, str.size() - 1);
    } else if (lastChar == 'u') {
        multiplier = 1e-6; 
        numberPart = str.substr(0, str.size() - 1);
    } else if (lastChar == 'n') { 
        multiplier = 1e-9; 
        numberPart = str.substr(0, str.size() - 1);
    }else if (lastChar == 'f') {
        multiplier = 1.0; 
        numberPart = str.substr(0, str.size() - 1); 
    }

    double value = 0;
    try {
        value = stod(numberPart);  // تبدیل رشته به عدد اعشاری
    } catch (const invalid_argument& e) {
        throw syntax_error_exp();
    } catch (const out_of_range& e) {
        throw syntax_error_exp();
    }

    value *= multiplier;
    return value;
}


// تابع پردازش ورودی کاربر
void inputHandler(string line) {
    vector<string> words;
    devide(line, words);

    if (words.size() == 0) return;

    if (words[0] == "add") {
        if(words.size() < 5){
            throw syntax_error_exp() ;
        }
        

        string name = words[1];
        string node1 = words[2];
        string node2 = words[3];
//اضافه کردن مقاومت
        if(name[0] == 'R'){
            // بررسی اینکه حرف اول نام المان باید بزرگ باشد
            if (!isupper(words[1][0])) {
                throw element_R_not_found_exp();
            }
             // بررسی وجود مقاومت با همین نام
            auto it = find_if(resistors.begin(), resistors.end(), [&](const Resistor& r) {
                return r.name == name;
            });

            if (it != resistors.end()) {
                throw duplicate_resistor_name_exp();
            }

            double value = 0;
            try {
                value = parseValueWithUnit(words[4]);  // تلاش برای تبدیل مقدار به عدد
            } catch (const invalid_argument& e) {
                throw syntax_error_exp();
            } catch (const out_of_range& e) {
                throw syntax_error_exp();
            }

            if (value <= 0) {
                throw negative_zero_R_exp();
            }

            

            resistors.emplace_back(name, node1, node2, value);
            cout << "Resistor added: " << name << " between " << node1 << " and " << node2 << " with value " << value << " ohms.\n";
        }
//اضافه کردن خازن
        else if (name[0] == 'C') {
            // بررسی اینکه حرف اول نام المان باید بزرگ باشد
            if (!isupper(words[1][0])) {
                throw element_C_not_found_exp();
            }
            // خازن
            auto it = find_if(capacitors.begin(), capacitors.end(), [&](const Capacitor& c) {
                return c.name == name;
            });

            if (it != capacitors.end()) {
                throw duplicate_capasitor_name_exp(); 
            }

            double value = parseValueWithUnit(words[4]);
            if (value <= 0) {
                throw negative_zero_C_exp(); 
            }

            capacitors.emplace_back(name, node1, node2, value);
            cout << "Capacitor added: " << name << " between " << node1 << " and " << node2
                << " with value " << value << " F.\n";
        }
//اضافه کردن سلف
        else if (name[0] == 'L') {
            if (!isupper(name[0])) {
                throw element_L_not_found_exp();
            }

            auto it = find_if(inductors.begin(), inductors.end(), [&](const Inductor& l) {
                return l.name == name;
            });

            if (it != inductors.end()) {
                throw duplicate_inductor_name_exp();
            }

            double value = 0;
            try {
                value = parseValueWithUnit(words[4]);  // تلاش برای تبدیل مقدار به عدد
            } catch (const invalid_argument& e) {
                throw syntax_error_exp();
            } catch (const out_of_range& e) {
                throw syntax_error_exp();
            }

            if (value <= 0) {
                throw negative_zero_L_exp();
            }

            inductors.emplace_back(name, node1, node2, value);
            cout << "Inductor added: " << name << " between " << node1 << " and " << node2
                << " with value " << value << " H.\n";
        }
// اضافه کردن دیود
        else if (name[0] == 'D') {
            if (words.size() < 5) throw syntax_error_exp();
            // بررسی اینکه حرف اول نام المان باید بزرگ باشد
            if (!isupper(words[1][0])) {
                throw element_D_not_found_exp();
            }

            string model = words[4];
            cout << model << endl ;
            if(model != "D" &&  model != "Z" ){
                throw invalid_diode_element_model_exp() ;
            }
            auto it = find_if(diodes.begin(), diodes.end(), [&](const Diode& d) {
                return d.name == name;
            });

            if (it != diodes.end()) {
                throw duplicate_diode_exp();
            }

            diodes.emplace_back(name, node1, node2, model);
            cout << "Diode added: " << name << " between " << node1 << " and " << node2
                 << " with model " << model << ".\n";
        } 
//اضافه کردن زمین
        else if (words[1] == "GND") {
            if (words.size() != 3) {
                throw syntax_error_gnd_exp();
            }

            string node = words[2];
            auto it = find_if(grounds.begin(), grounds.end(), [&](const Ground& g) {
                return g.node == node;
            });

            if (it != grounds.end()) {
                throw duplicate_ground_exp();
            }

            grounds.emplace_back(node);
            cout << "Ground node added at: " << node << endl;
        }
// اضافه کردن VoltageSource
        else if (name[0] == 'V') {
            if (!isupper(name[0])) {
                throw element_VS_not_found_exp();
            }

            auto it = find_if(voltageSources.begin(), voltageSources.end(), [&](const VoltageSource& vs) {
                return vs.name == name;
            });

            if (it != voltageSources.end()) {
                throw duplicate_voltage_source_name_exp();
            }

            double value = 0;
            try {
                value = parseValueWithUnit(words[4]);
            } catch (const invalid_argument& e) {
                throw syntax_error_exp();
            } catch (const out_of_range& e) {
                throw syntax_error_exp();
            }

            if (value <= 0) {
                throw negative_zero_VS_exp();
            }

            voltageSources.emplace_back(name, node1, node2, value);
            cout << "Voltage Source added: " << name << " between " << node1 << " and " << node2
                 << " with value " << value << " V.\n";
        }

// اضافه کردن CurrentSource
        else if (name[0] == 'I') {
            if (!isupper(name[0])) {
                throw element_IS_not_found_exp();
            }

            auto it = find_if(currentSource.begin(), currentSource.end(), [&](const CurrentSource& cs) {
                return cs.name == name;
            });

            if (it != currentSource.end()) {
                throw duplicate_current_source_name_exp();
            }

            double value = 0;
            try {
                value = parseValueWithUnit(words[4]);
            } catch (const invalid_argument& e) {
                throw syntax_error_exp();
            } catch (const out_of_range& e) {
                throw syntax_error_exp();
            }

            if (value <= 0) {
                throw negative_zero_IS_exp();
            }

            currentSource.emplace_back(name, node1, node2, value);
            cout << "Current Source added: " << name << " between " << node1 << " and " << node2
                 << " with value " << value << " A.\n";
        }
// اضافه کردن منبع ولتاژ سینوسی
        else if (name[0] == 'S') {
            if (words.size() != 7) {
                throw syntax_error_exp();
            }

            if (!isupper(name[0])) {
                throw element_sinV_not_found_exp();
            }

            // چک کردن وجود منبع با همین نام
            auto it = find_if(sineVoltageSources.begin(), sineVoltageSources.end(), [&](const SineVoltageSource& svs) {
                return svs.name == name;
            });

            if (it != sineVoltageSources.end()) {
                throw duplicate_sin_voltage_source_name_exp();
            }

            double amplitude = 0;
            double frequency = 0;
            double offset = 0 ;
           // double phase = parseValueWithUnit(words[6]);
            
            try {
                amplitude = parseValueWithUnit(words[4]);
                frequency = parseValueWithUnit(words[5]);
                offset = parseValueWithUnit(words[6]);
            } catch (const invalid_argument& e) {
                throw syntax_error_exp();
            } catch (const out_of_range& e) {
                throw syntax_error_exp();
            }
            


            if (amplitude <= 0 || frequency < 0) {
                throw negative_zero_sinV_exp();
            }

            sineVoltageSources.emplace_back(name, node1, node2, amplitude, frequency , offset);
            cout << "Sine Voltage Source added: " << name << " between " << node1 << " and " << node2
                << " with amplitude " << amplitude << " V, frequency " << frequency << " Hz offset " << offset << "V.\n";
        }
    }
    else if (words[0] == "delete") {
        if (words.size() != 2) {
            throw invalid_delete_syntax_exp();
        }

        string name = words[1];

//پاک کردن مقاومت
        if(name[0] == 'R'){
            auto it = find_if(resistors.begin(), resistors.end(), [&](const Resistor& r) {
                return r.name == name;
            });

            if (it != resistors.end()) {
                resistors.erase(it);
                cout << "Resistor " << name << " deleted successfully.\n";
            } else {
                throw resistor_not_found_exp();
            }
        }
//پاک کردن خازن
        else if (name[0] == 'C') {
            auto it = find_if(capacitors.begin(), capacitors.end(), [&](const Capacitor& c) {
                return c.name == name;
            });

            if (it != capacitors.end()) {
                capacitors.erase(it);
                cout << "Capacitor " << name << " deleted successfully.\n";
            } else {
                throw element_C_not_found_exp(); // استفاده مجدد از استثناء موجود
            }
        }
//پاک کردن سلف
        else if (name[0] == 'L') {
            auto it = find_if(inductors.begin(), inductors.end(), [&](const Inductor& l) {
                return l.name == name;
            });

            if (it != inductors.end()) {
                inductors.erase(it);
                cout << "Inductor " << name << " deleted successfully.\n";
            } else {
                throw element_L_not_found_exp(); // استفاده مجدد از استثناء موجود
            }
        }
//پاک کردن دیود
        else if (name[0] == 'D') {
            auto it = find_if(diodes.begin(), diodes.end(), [&](const Diode& d) {
                return d.name == name;
            });

            if (it != diodes.end()) {
                diodes.erase(it);
                cout << "Diode " << name << " deleted successfully.\n";
            } else {
                throw element_D_not_found_diode_exp(); // کلاس استثناء مخصوص دیود
            }
        }
//پاک کردن زمین
        else if (words[1] == "GND") {
            if (words.size() != 3) {
                throw invalid_delete_syntax_exp();
            }

            string node = words[2];
            auto it = find_if(grounds.begin(), grounds.end(), [&](const Ground& g) {
                return g.node == node;
            });

            if (it != grounds.end()) {
                grounds.erase(it);
                cout << "Ground node " << node << " deleted successfully.\n";
            } else {
                throw ground_not_found_exp();
            }
        }
//پاک کردن voltageSoruce
        else if(name[0] =='V') {
            auto it = find_if(voltageSources.begin(), voltageSources.end(), [&](const VoltageSource& vs) {
                return vs.name == name;
            });

            if (it != voltageSources.end()) {
                voltageSources.erase(it);
                cout << "Voltage Source " << name << " deleted successfully.\n";
            } else {
                throw element_VS_not_found_exp();
            }
        }
//پاک کردن CurrentSoruce
        else if(name[0] =='I') {
            auto it = find_if(currentSource.begin(), currentSource.end(), [&](const CurrentSource& is) {
                return is.name == name;
            });

            if (it != currentSource.end()) {
                currentSource.erase(it);
                cout << "Current Source " << name << " deleted successfully.\n";
            } else {
                throw element_IS_not_found_exp();
            }
        }
// حذف منبع ولتاژ سینوسی
        else if (name[0] == 'S') {
            // پیدا کردن منبع سینوسی با نام name در وکتور
            auto it = std::find_if(sineVoltageSources.begin(), sineVoltageSources.end(), [&](const SineVoltageSource& svs) {
                return svs.name == name;
            });

            if (it != sineVoltageSources.end()) {
                sineVoltageSources.erase(it);
                cout << "Sine Voltage Source " << name << " deleted successfully.\n";
            } else {
                throw element_VS_not_found_exp();  // یا هر استثنای مناسب که برای منبع پیدا نشدن تعریف کردید
            }
        }
        else {
            throw invalid_delete_element_type_exp();
        }
    }
}

// تابع main
int main() {
    string line;
    cout << "Start:\n";

    while (getline(cin, line)) {
        if(line == "exit"){
            break ;
        }
        try {
            inputHandler(line);
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}


/*add R1 n1 n2 10k
add C1 n2 n3 4.7u
add L1 n3 n4 3.2m
add D1 n4 n5 D
add V1 n3 n5 3.5
add I1 N4 N5 5.6
add S1 n5 n6 5(amplitude) 6k(frequency)
show
exit*/