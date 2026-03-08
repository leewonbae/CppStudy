#include "Potion.h"

Potion::Potion()
{
    std::cout << "Potion 기본 생성자" << std::endl;
}

Potion::Potion(std::string name, int32_t recoveryValue) : Item(name, E_ITEM_TYPE::POTION)
{
    _recoveryValue = recoveryValue;

    std::cout << "Potion 오버라이딩 생성자" << std::endl;
}

Potion::~Potion()
{
    std::cout << "Potion 메모리 삭제 " << std::endl;
}

std::string Potion::GetDetailInfo() const
{
    return " 상세 정보 -> 회복 지수 : [" + std::to_string(_recoveryValue) + "]";
}
