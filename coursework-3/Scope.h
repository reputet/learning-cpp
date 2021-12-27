#pragma once
enum Scope {IT, MEDIA, MEDICINE, LAW, EDUCATION, GOVERNMENT};

inline const char* ToString(Scope v)
{
    switch (v)
    {
        case IT: return "IT";
        case MEDIA: return "Media";
        case MEDICINE: return "Medicine";
        case LAW: return "Law";
        case EDUCATION: return "Education";
        case GOVERNMENT: return "Government";
        default: return "[Unknown job scope]";
    }
}