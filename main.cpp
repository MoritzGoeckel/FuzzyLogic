#include <algorithm>
#include <iostream>
#include <string>

class FBool{
    private:
        float state;
    
    public:
        FBool(const float& value);
        FBool(const bool& value);
        FBool(const FBool& value);

        FBool& operator=(const bool& value);
        FBool& operator=(const FBool& value);
        FBool& operator=(const float& value);

        FBool operator&&(const FBool& value) const;
        FBool operator||(const FBool& value) const;
        FBool operator!() const;
        bool getBool() const;
        float getFloat() const;
};

FBool::FBool(const float& value){
    this->state = value;
}

FBool::FBool(const bool& value){
    this->state = value ? 1 : 0;
}

FBool::FBool(const FBool& value){
    this->state = value.state;
}

FBool& FBool::operator=(const bool& value){
    this->state = value ? 1 : 0;
    return *this;
}

FBool& FBool::operator=(const FBool& value){
    this->state = value.state;
    return *this;
}

FBool& FBool::operator=(const float& value){
    this->state = value;
    return *this;
}

FBool FBool::operator&&(const FBool& value) const{
    return FBool(std::min(this->state, value.state));
}

FBool FBool::operator||(const FBool& value) const{
    return FBool(std::max(this->state, value.state));
}

FBool FBool::operator!() const{
    return FBool(1 - this->state);
}

bool FBool::getBool() const{
    return this->state > 0.5;
}

float FBool::getFloat() const{
    return this->state;
}

std::ostream& operator<<(std::ostream &os, const FBool& value) { 
    if(value.getBool())
        os << "T(";
    else
        os << "F(";
    os << value.getFloat();
    os << ")";
    
    return os;
}

int main(){
    FBool t = true;
    FBool f = 0.3f;

    FBool x = t && f;
    FBool y = t || f;
    FBool z = t && !f;

    std::cout << "Yo!" << std::endl;
    std::cout << x.getBool() << " " << y.getBool() << " " << z.getBool() << std::endl;
    std::cout << t << " " << f << std::endl;
}