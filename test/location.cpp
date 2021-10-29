#include <iostream>
#include <string_view>
#include <source_location>

constexpr const char *get_location()
{
    return std::source_location::current().file_name();
}

void log(std::string_view message,
         const char *location)
{
    std::cout << "info:"
              << location << " "
              << message << '\n';
}

int main()
{
    log("Hello world!", get_location());
}
