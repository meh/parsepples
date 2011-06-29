#include <parsepples.hpp>

namespace IPv4 {
  class Parser : public Parsepples::Parser
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
  };

  class Transform : public Parsepples::Transform
  {
  };
}

int
main (int argc, char** argv)
{
    Parsepples::Result* result = IPv4::Transform().apply(IPv4::Parser().parse(argv[1]));
    
    delete result;

    return 1;
}
