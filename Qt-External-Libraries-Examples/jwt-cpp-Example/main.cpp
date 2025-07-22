#include <QCoreApplication>

#include <iostream>

#include <jwt-cpp/traits/nlohmann-json/defaults.h>
#include <jwt-cpp/jwt.h>

namespace {
    const char* secret_key = "secret_key";
}

void test1()
{
    std::string encoded_string;

    // Кодирование
    {
        auto token = jwt::create<jwt::traits::nlohmann_json>()
                         .set_issuer("auth.server.com")
                         .set_subject("user@example.com")
                         .set_type("JWS")
                         .set_payload_claim("role", jwt::claim(std::string("user")))
                         .set_payload_claim("sample", jwt::claim(std::string("test")))
                         .sign(jwt::algorithm::hs256{::secret_key});

        encoded_string = token.c_str();
    }

    // Вывод сгенерированного токена
    std::cout << "Generated JWT: Bearer " << encoded_string << std::endl;

    // Декодирование
    {
        auto decoded_token = jwt::decode<jwt::traits::nlohmann_json>(encoded_string);

        auto verifier = jwt::verify()
                            .with_issuer("auth.server.com")
                            .with_claim("sample", jwt::claim(std::string("test")))
                            .allow_algorithm(jwt::algorithm::hs256{::secret_key});

        verifier.verify(decoded_token);

        std::cout << "jwt payload: claim \"role\" = "   << decoded_token.get_payload_json().find("role")->second   << std::endl;
        std::cout << "jwt payload: claim \"sample\" = " << decoded_token.get_payload_json().find("sample")->second << std::endl;
    }
}

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);

    test1();

    return 0;//app.exec();
}
