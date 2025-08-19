#pragma once

#include "Issuer.h"
#include "Subject.h"

#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/evp.h>

#include <iostream>

struct Certificate
{
    Issuer issuer;
    Subject subject;

    std::string validFrom;
    std::string validUntil;

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

inline void handleErrors()
{
    ERR_print_errors_fp(stderr);
    abort();
}

inline X509* generate_x509_certificate(EVP_PKEY* pkey, const Certificate& certificate)
{
    X509* x509 = X509_new();
    if (!x509) handleErrors();

    // Устанавливаем версию сертификата (v3)
    X509_set_version(x509, 2); // 2 означает X509v3

    // Устанавливаем серийный номер
    ASN1_INTEGER_set(X509_get_serialNumber(x509), 1);

    // Устанавливаем срок действия
    X509_gmtime_adj(X509_get_notBefore(x509), 0); // Действителен с текущего момента (certificate.validFrom)
    X509_gmtime_adj(X509_get_notAfter(x509), 31536000L); // Действителен 1 год (в секундах) (certificate.validUntil)

    // Устанавливаем открытый ключ
    X509_set_pubkey(x509, pkey);

    // Создаем и заполняем поле Subject
    X509_NAME* subject = X509_get_subject_name(x509);
    X509_NAME_add_entry_by_txt(subject, "C", MBSTRING_ASC, (unsigned char*)certificate.subject.C.c_str(), -1, -1, 0); // Страна
    X509_NAME_add_entry_by_txt(subject, "ST", MBSTRING_ASC, (unsigned char*)certificate.subject.ST.c_str(), -1, -1, 0); // Область/край
    X509_NAME_add_entry_by_txt(subject, "L", MBSTRING_ASC, (unsigned char*)certificate.subject.L.c_str(), -1, -1, 0); // Город
    X509_NAME_add_entry_by_txt(subject, "O", MBSTRING_ASC, (unsigned char*)certificate.subject.O.c_str(), -1, -1, 0); // Организация
    X509_NAME_add_entry_by_txt(subject, "OU", MBSTRING_ASC, (unsigned char*)certificate.subject.OU.c_str(), -1, -1, 0); // Подразделение
    X509_NAME_add_entry_by_txt(subject, "CN", MBSTRING_ASC, (unsigned char*)certificate.subject.CN.c_str(), -1, -1, 0); // Общее имя
    X509_NAME_add_entry_by_txt(subject, "emailAddress", MBSTRING_ASC, (unsigned char*)certificate.subject.emailAddress.c_str(), -1, -1, 0); // Email
    X509_set_issuer_name(x509, subject);

    // Создаем и заполняем поле Issuer
    X509_NAME* issuer = X509_get_issuer_name(x509);
    X509_NAME_add_entry_by_txt(issuer, "C", MBSTRING_ASC, (unsigned char*)certificate.issuer.C.c_str(), -1, -1, 0); // Страна
    X509_NAME_add_entry_by_txt(issuer, "ST", MBSTRING_ASC, (unsigned char*)certificate.issuer.ST.c_str(), -1, -1, 0); // Область/край
    X509_NAME_add_entry_by_txt(issuer, "L", MBSTRING_ASC, (unsigned char*)certificate.issuer.L.c_str(), -1, -1, 0); // Город
    X509_NAME_add_entry_by_txt(issuer, "O", MBSTRING_ASC, (unsigned char*)certificate.issuer.O.c_str(), -1, -1, 0); // Организация
    X509_NAME_add_entry_by_txt(issuer, "OU", MBSTRING_ASC, (unsigned char*)certificate.issuer.OU.c_str(), -1, -1, 0); // Подразделение
    X509_NAME_add_entry_by_txt(issuer, "CN", MBSTRING_ASC, (unsigned char*)certificate.issuer.CN.c_str(), -1, -1, 0); // Общее имя
    X509_NAME_add_entry_by_txt(issuer, "emailAddress", MBSTRING_ASC, (unsigned char*)certificate.issuer.emailAddress.c_str(), -1, -1, 0); // Email
    X509_set_issuer_name(x509, issuer);

    // Добавляем расширения
    X509V3_CTX ctx;
    X509V3_set_ctx_nodb(&ctx);
    X509V3_set_ctx(&ctx, x509, x509, NULL, NULL, 0);

    // Добавляем basicConstraints
    X509_EXTENSION* ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_basic_constraints, "critical,CA:TRUE");
    if (ex) {
        X509_add_ext(x509, ex, -1);
        X509_EXTENSION_free(ex);
    }

    // Добавляем keyUsage
    ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_key_usage, "critical,digitalSignature,keyEncipherment,keyCertSign");
    if (ex) {
        X509_add_ext(x509, ex, -1);
        X509_EXTENSION_free(ex);
    }

    // Добавляем extendedKeyUsage
    ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_ext_key_usage, "serverAuth,clientAuth");
    if (ex) {
        X509_add_ext(x509, ex, -1);
        X509_EXTENSION_free(ex);
    }

    // Добавляем subjectKeyIdentifier
    ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_subject_key_identifier, "hash");
    if (ex) {
        X509_add_ext(x509, ex, -1);
        X509_EXTENSION_free(ex);
    }

    // Добавляем authorityKeyIdentifier
    ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_authority_key_identifier, "keyid:always");
    if (ex) {
        X509_add_ext(x509, ex, -1);
        X509_EXTENSION_free(ex);
    }

    // Добавляем subjectAltName (если нужно)
    ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_subject_alt_name, "DNS:example.com,DNS:www.example.com");
    if (ex) {
        X509_add_ext(x509, ex, -1);
        X509_EXTENSION_free(ex);
    }

    // Добавляем политики (Certificate Policies)
    ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_certificate_policies, "dlkfjghlerigjdlkjgndlskjgbdlkjgbdlfkjgldbkfnj");
    if (ex) {
        X509_add_ext(x509, ex, -1);
        X509_EXTENSION_free(ex);
    }

    // Подписываем сертификат
    if (!X509_sign(x509, pkey, EVP_sha256())) {
        handleErrors();
    }

    return x509;
}

inline bool doCertificate(const Certificate& certificate)
{
    // Генерируем ключ
    EVP_PKEY* pkey = EVP_PKEY_new();
    if (!pkey) handleErrors();

    RSA* rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    if (!EVP_PKEY_assign_RSA(pkey, rsa)) {
        handleErrors();
    }

    // Генерируем сертификат
    X509* x509 = generate_x509_certificate(pkey, certificate);

    // Сохраняем сертификат в файл
    FILE* cert_file = fopen("certificate.crt", "wb");
    if (!cert_file) {
        perror("Failed to open certificate file");
        abort();
    }
    PEM_write_X509(cert_file, x509);
    fclose(cert_file);

    // Сохраняем приватный ключ в файл
    FILE* key_file = fopen("private_key.pem", "wb");
    if (!key_file) {
        perror("Failed to open private key file");
        abort();
    }
    PEM_write_PrivateKey(key_file, pkey, NULL, NULL, 0, NULL, NULL);
    fclose(key_file);

    // Освобождаем ресурсы
    X509_free(x509);
    EVP_PKEY_free(pkey);


    return true;
}

inline Certificate writeCertificate(X509* cert)
{
    // 1. Subject (владелец сертификата)
    X509_NAME* subject = X509_get_subject_name(cert);
    std::string sbjStr = X509_NAME_oneline(subject, nullptr, 0);
    Subject sbj(sbjStr);

    // 2. Issuer (кто подписал)
    X509_NAME* issuer = X509_get_issuer_name(cert);
    std::string issStr = X509_NAME_oneline(issuer, nullptr, 0);
    Issuer iss(issStr);

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

    STACK_OF(POLICYINFO) *policies = NULL;

    // Получить список политик из сертификата
    policies = (STACK_OF(POLICYINFO)*)X509_get_ext_d2i(cert, NID_certificate_policies, NULL, NULL);
    if (!policies)
    {
        fprintf(stderr, "Нет расширения certificate policies\n");
    }
    else
    {
        for(int i = 0; i < sk_POLICYINFO_num(policies); ++i) {
            POLICYINFO *policyInfo = sk_POLICYINFO_value(policies, i);

            ASN1_OBJECT *oidPolicy = policyInfo->policyid;
            const char *policyOIDStr = OBJ_nid2ln(OBJ_obj2nid(oidPolicy));

            std::cout << "Policy: " << policyOIDStr << std::endl;
            //printf("Policy %d: OID=%s\n", i+1, policyOIDStr ? policyOIDStr : "<unknown>");
        }

        //sk_POLICYINFO_free(policies);
        sk_POLICYINFO_pop_free(policies, POLICYINFO_free);
    }

    Certificate certificate = {
        .issuer = iss,
        .subject = sbj,
        .validFrom = validFrom,
        .validUntil = validUntil
    };

    return certificate;
}

inline Certificate load_certificate(const char* cert_path)
{
    FILE* file = fopen(cert_path, "rb");
    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        //return false;
    }

    // Чтение PEM-сертификата
    X509* cert = PEM_read_X509(file, nullptr, nullptr, nullptr);
    fclose(file);

    if (!cert) {
        std::cerr << "Ошибка чтения сертификата!" << std::endl;
        // false;
    }

    Certificate certificate = writeCertificate(cert);
    X509_free(cert);

    return certificate;
}
