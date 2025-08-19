#pragma once

#include "Utils.h"

struct Issuer
{
    std::string C;            // Country Name
    std::string ST;           // State or Province
    std::string L;            // Locality
    std::string O;            // Organization
    std::string OU;           // Organizational Unit
    std::string CN;           // Common Name
    std::string emailAddress; // Email Address
    std::string serialNumber; // Serial Number
    std::string UID;          // nique Identifier
    std::string DC;           // Domain Component

    // ...

    Issuer() {}
    Issuer(const std::string& data)
    {
        std::map<std::string, std::string> hh = Utils::doubleSplitter(data, '/');

        C = hh.contains("C") ? hh.find("C")->second : "";
        ST = hh.contains("ST") ? hh.find("ST")->second : "";
        L = hh.contains("L") ? hh.find("L")->second : "";
        O = hh.contains("O") ? hh.find("O")->second : "";
        OU= hh.contains("OU") ? hh.find("OU")->second : "";
        CN = hh.contains("CN") ? hh.find("CN")->second : "";
        emailAddress = hh.contains("emailAddress") ? hh.find("emailAddress")->second : "";
        serialNumber = hh.contains("serialNumber") ? hh.find("serialNumber")->second : "";
        UID = hh.contains("UID") ? hh.find("UID")->second : "";
        DC = hh.contains("DC") ? hh.find("DC")->second : "";
    }

    friend std::ostream& operator<<(std::ostream& os, const Issuer& iss)
    {
        return os << "Issuer:\n"
                  << "\tC: " << iss.C << "\n"
                  << "\tST: " << iss.ST << "\n"
                  << "\tL: " << iss.L << "\n"
                  << "\tO: " << iss.O << "\n"
                  << "\tOU: " << iss.OU << "\n"
                  << "\tCN: " << iss.CN << "\n"
                  << "\temailAddress: " << iss.emailAddress << "\n"
                  << "\tserialNumber: " << iss.serialNumber << "\n"
                  << "\tUID: " << iss.UID << "\n"
                  << "\tDC: " << iss.DC << "\n";
    }
};
