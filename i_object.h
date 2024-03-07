#pragma once


namespace mxPiglets {


struct IObject
{

    // IObject() = default;
    //  
    // IObject(const IObject&) = default;
    // IObject& operator=(const IObject&) = default;
    //  
    // IObject(IObject&&) = default;
    // IObject& operator=(IObject&&) = default;

    virtual bool isValid() const = 0;

    virtual ~IObject() {}

}; // struct IObject


} // namespace mxPiglets

