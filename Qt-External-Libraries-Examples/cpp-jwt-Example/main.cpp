#include <QCoreApplication>

#include <iostream>

#include <jwt/jwt.hpp>

namespace {
    const char* secret_key = "secret_key";
}

void test1()
{
    std::string encoded_string;

    // Кодирование
    {
        jwt::jwt_object obj {
            jwt::params::algorithm("HS256"),
            jwt::params::payload({
                { "some", "payload" }
            }),
            jwt::params::secret(::secret_key)
        };

        encoded_string = obj.signature();
    }

    encoded_string = "Bearer " + encoded_string;
    std::cout << encoded_string << std::endl;

    encoded_string.erase(0, 7);
    std::cout << encoded_string << std::endl;

    // Декодирование
    {
        jwt::jwt_object dec_obj = jwt::decode(encoded_string,
                                              jwt::params::algorithms({"HS256"}),
                                              jwt::params::secret(::secret_key)
                                              );

        std::cout << dec_obj.header() << std::endl;
        std::cout << dec_obj.payload() << std::endl;
    }
}

void test2()
{
    std::string encoded_string;

    // Кодирование
    {
        jwt::jwt_object obj{
            jwt::params::algorithm("HS256"),
            jwt::params::secret(::secret_key),
            jwt::params::payload({{"user", "admin"}})
        };

        obj.add_claim("iss", "some.server")
            .add_claim("sub", "test")
            .add_claim("id", "001")
            .add_claim("iat", 1513862371)
            .add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{10})
            ;

        encoded_string = obj.signature();
    }

    // Декодирование
    {
        jwt::jwt_object dec_obj = jwt::decode(encoded_string,
                                              jwt::params::algorithms({"HS256"}),
                                              jwt::params::secret(::secret_key)
                                              );


        if (dec_obj.has_claim("exp")) {
            std::cout << "exp = " << dec_obj.payload().get_claim_value<int64_t>("exp") << std::endl;
            std::cout << "exp = " << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << std::endl;
        } else {
            assert(true);
        }

        assert (dec_obj.payload().has_claim_with_value("iat", 1513862371));
    }
}

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);

    test1();
    test2();

    return app.exec();
}
