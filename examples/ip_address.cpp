#include <parsepples/parser.hpp>

class IPv4 : public Parsepples::Parser
{
    ROOT(ipv4);
    RULE(ipv4, { return
        ((dec_octet() >> chr('.'))->repeat(3) >> dec_octet())->as("ipv4");
    });

    RULE(dec_octet, { return
        str("25") >> match["0-5"] |
        chr('2') >> match["0-4"] >> digit |
        chr('1') >> digit >> digit |
        match["1-9"] >> digit |
        digit;
    });

    RULE(digit, { return
        match["0-9"];
    });
}

int
main (int argc, char** argv)
{
    Parslet::Result* result = IPv4().parse(argv[1]);

    return 1;
}
