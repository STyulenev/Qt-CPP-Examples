#include <openssl/x509.h>
#include <openssl/pem.h>
#include <iostream>

#include "Certificate.h"

void print_cert_info(X509* cert)
{
    // 1. Subject (владелец сертификата)
    X509_NAME* subject = X509_get_subject_name(cert);
    //std::cout << "Subject: " << X509_NAME_oneline(subject, nullptr, 0) << std::endl;
    std::string sbjStr = X509_NAME_oneline(subject, nullptr, 0);
    Subject sbj(sbjStr);
    //std::cout << sbj;

    // 2. Issuer (кто подписал)

    X509_NAME* issuer = X509_get_issuer_name(cert);
    //std::cout << "Issuer: " << X509_NAME_oneline(issuer, nullptr, 0) << std::endl;
    std::string issStr = X509_NAME_oneline(issuer, nullptr, 0);
    Issuer iss(issStr);
    //std::cout << iss;


    // 3. Срок действия
    std::string validFrom = std::string(reinterpret_cast<const char*>(
        ASN1_STRING_get0_data(X509_get0_notBefore(cert))
        ));
    std::string validUntil = std::string(reinterpret_cast<const char*>(
        ASN1_STRING_get0_data(X509_get0_notAfter(cert))
        ));


    // 4. Серийный номер
    BIGNUM* serial = ASN1_INTEGER_to_BN(X509_get_serialNumber(cert), nullptr);
    char* serial_hex = BN_bn2hex(serial);
    std::cout << "Serial: " << serial_hex << std::endl;
    OPENSSL_free(serial_hex);
    BN_free(serial);

    Certificate certificate = {
        .issuer = iss,
        .subject = sbj,
        .validFrom = validFrom,
        .validUntil = validUntil
    };

    std::cout << certificate;
}

void load_certificate(const char* cert_path)
{
    FILE* file = fopen(cert_path, "rb");
    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    // Чтение PEM-сертификата
    X509* cert = PEM_read_X509(file, nullptr, nullptr, nullptr);
    fclose(file);

    if (!cert) {
        std::cerr << "Ошибка чтения сертификата!" << std::endl;
        return;
    }

    print_cert_info(cert);
    X509_free(cert);
}

int main()
{
    // Инициализация OpenSSL
    OpenSSL_add_all_algorithms();

    // Создание сертификата
    // create_self_signed_cert("cert.pem", "key.pem");

    // Чтение существующего сертификата
    load_certificate("C:/Work/cert.crt");

    return 0;
}

