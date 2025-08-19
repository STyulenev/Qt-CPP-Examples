#include "Certificate.h"

int main()
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Write
    {
        Issuer issuer;
        issuer.C = "Country Name";
        issuer.ST = "State or Province";
        issuer.L = "Locality";
        issuer.O = "Organization";
        issuer.OU = "Organizational Unit";
        issuer.CN = "Common Name";
        issuer.emailAddress = "Email Address";
        issuer.serialNumber = "Serial Number";
        issuer.UID = "nique Identifier";
        issuer.DC = "Domain Component";

        Subject subject;
        subject.C = "Country Name";
        subject.ST = "State or Province";
        subject.L = "Locality";
        subject.O = "Organization";
        subject.OU = "Organizational Unit";
        subject.CN = "Common Name";
        subject.emailAddress = "Email Address";
        subject.serialNumber = "Serial Number";
        subject.UID = "nique Identifier";
        subject.DC = "Domain Component";

        Certificate certificate {
            .issuer = issuer,
            .subject = subject,
            .validFrom = "",
            .validUntil = ""
        };

        if (doCertificate(certificate)) {
            std::cout << "Certificate and private key generated successfully!" << std::endl;
        } else {
            std::cout << "Error" << std::endl;
            return -1;
        }

    }

    // Read
    {
        // Чтение существующего сертификата
        Certificate certificate = load_certificate("certificate.crt");
        std::cout << certificate << std::endl;
    }

    return 0;
}
