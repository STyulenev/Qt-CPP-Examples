#include <botan/x509_ca.h>
#include <botan/x509_crl.h>
#include <botan/x509_dn.h>
#include <botan/x509_ext.h>
#include <botan/x509_key.h>
#include <botan/x509_obj.h>
#include <botan/x509cert.h>
#include <botan/x509self.h>

#include <botan/pem.h>
#include <botan/pkcs8.h>
#include <botan/pkcs10.h>
#include <botan/pubkey.h>
#include <botan/rsa.h>
#include <botan/auto_rng.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


// Функция для преобразования серийного номера (вектора байтов) в строку
std::string serial_number_to_string(const std::vector<uint8_t>& serial)
{
    std::ostringstream oss;
    oss << "0x";
    for (const auto& byte : serial) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }
    return oss.str();
}

int main()
{
    try {
        // Инициализация генератора случайных чисел
        Botan::AutoSeeded_RNG rng;

        // Генерация RSA ключа (2048 бит)
        Botan::RSA_PrivateKey private_key(rng, 2048);

        // Создание информации о субъекте (владельце сертификата)
        Botan::X509_Cert_Options opts;
        opts.common_name = "example.com";
        opts.country = "RU";
        opts.organization = "Example Company";
        opts.org_unit = "IT Department";
        opts.email = "admin@example.com";

        // Создание самоподписанного сертификата
        Botan::X509_Certificate cert = Botan::X509::create_self_signed_cert(opts, private_key, "SHA-256", rng);

        // Вывод информации о сертификате
        std::cout << "Сертификат успешно создан:\n";
        std::cout << "Subject: " << cert.subject_dn().to_string() << "\n";
        std::cout << "Issuer: " << cert.issuer_dn().to_string() << "\n";
        std::cout << "Серийный номер: " << serial_number_to_string(cert.serial_number()) << "\n";
        std::cout << "Действует с: " << cert.not_before().to_string() << "\n";
        std::cout << "Действует до: " << cert.not_after().to_string() << "\n";

        // Сохранение сертификата в файл PEM формата
        std::ofstream cert_file("certificate.pem", std::ios::out | std::ios::binary);
        if (cert_file.is_open()) {
            cert_file << cert.PEM_encode();
            cert_file.close();
            std::cout << "\nСертификат сохранен в: certificate.pem\n";
        } else {
            std::cerr << "Ошибка открытия файла для записи сертификата\n";
        }

        // Сохранение приватного ключа в файл
        std::ofstream key_file("private_key.pem", std::ios::out | std::ios::binary);
        if (key_file.is_open()) {
            key_file << Botan::PKCS8::PEM_encode(private_key);
            key_file.close();
            std::cout << "Приватный ключ сохранен в: private_key.pem\n";
        } else {
            std::cerr << "Ошибка открытия файла для записи ключа\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
