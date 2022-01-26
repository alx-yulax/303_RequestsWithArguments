#include <iostream>
#include <cpr/cpr.h>
#include <vector>

int main() {

    cpr::Parameters parameters = cpr::Parameters();
    std::vector<cpr::Pair> payload;

    std::string argument, value;
    while (true) {
        std::cout << "Input argument and value: ";
        std::cin >> argument;
        if (argument == "post" || argument == "get")
            break;
        std::cin >> value;
        payload.push_back({argument, value});
        parameters.Add({argument, value});
    }

    if (argument == "post") {
        cpr::Response r = cpr::Post(cpr::Url{"http://www.httpbin.org/post"},
                                    cpr::Payload{payload.begin(), payload.end()});
        std::cout << r.text << std::endl;
    } else {
        cpr::Response r = cpr::Get(cpr::Url{"http://www.httpbin.org/get"},
                                   parameters);

        std::cout << r.text << std::endl;
    }
    
    return 0;
}
