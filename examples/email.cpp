#include <parsepples.hpp>
#include <cctype>

namespace Email {
    class Parser : public Parsepples::Parser
    {
        HELPER(stri) (std::string text) {
            HELPER_RESULT result = match[std::string(tolower(text[0])) + toupper(text[0])];

            for (size_t i = 1; i < text.size(); i++) {
                result = result >> match[std::string(tolower(text[i])) + toupper(text[i])];
            }

            return result;
        };

        RULE(space) { return
            match["\s"];
        };

        RULE(dash), { return
            match["-_"];
        };

        RULE(at) { return
            chr('@') | (dash()->maybe() >> stri("at") >> dash()->maybe();
        };

        RULE(dot) { return
            chr('.') | (dash()->maybe() >> stri("dot") >> dash()->maybe());
        };

        RULE(word) { return
            match["a-z0-9"]->repeat(1)->as("word") >> space()->maybe();
        };

        RULE(separator) { return
            dot()->as("dot") >> space()->maybe() | space();
        };

        RULE(words) { return
            word() >> (separator() >> word())->repeat();
        };

        RULE(email) { return
            (words()->as("username") >> space()->maybe() >> at() >> space()->maybe() >> words())->as("email");
        };

        ROOT(email);
    };

    class Transform : public Parsepples::Transform
    {
        TRANSFORM {
            SIMPLE(dot_word, "dot", "word");
        };

        T_RULE(dot_word) {
    };
}

int
main (int argc, char** argv)
{
    Parsepples::Result* result = Email::Transform().apply(Email::Parser().parse(argv[1]));
    
    delete result;

    return 1;
}
