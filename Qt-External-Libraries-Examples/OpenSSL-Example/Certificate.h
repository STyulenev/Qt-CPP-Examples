#pragma once

#include "Issuer.h"
#include "Subject.h"

struct Certificate
{
    Issuer issuer;
    Subject subject;

    std::string validFrom;
    std::string validUntil;

    /*Certificate() {}
    Certificate(Issuer issuer = Issuer(), Subject subject = Subject(), std::string validFrom = std::string(), std::string validUntil= std::string()) :
        issuer(issuer),
        subject(subject),
        validFrom(validFrom),
        validUntil(validUntil)
    {

    }

    Certificate(const Issuer& issuer, const Subject& subject, const std::string& validFrom, const std::string& validUntil) :
        issuer(issuer),
        subject(subject),
        validFrom(validFrom),
        validUntil(validUntil)
    {

    }

    ~Certificate() {}*/

    friend std::ostream& operator<<(std::ostream& os, const Certificate& cert)
    {
        return os << "Certificate:\n"
                  << "[\n"
                  << cert.issuer << "\n"
                  << cert.subject << "\n"
                  << "validFrom: " << cert.validFrom << "\n"
                  << "validUntil: " << cert.validUntil << "\n"
                  << "]\n";
    }
};
